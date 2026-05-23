`timescale 1ns/1ps

module cpu (
    input logic clk,
    input logic rst_n
);

// ── PROGRAM COUNTER ──────────────────────────────────────────────────────────
reg   [31:0] pc;
logic [31:0] pc_next;
logic [31:0] pc_plus_four;
logic [31:0] pc_plus_second_add;

assign pc_plus_four = pc + 4;

// Select the target of the second adder (branches/jumps/LUI/AUIPC)
always_comb begin : second_add_select
    case (second_add_source)
        2'b00   : pc_plus_second_add = pc + immediate;      // branches, JAL, AUIPC
        2'b01   : pc_plus_second_add = immediate;           // LUI (imm directly)
        2'b10   : pc_plus_second_add = read_reg1 + immediate; // JALR
        default : pc_plus_second_add = 32'b0;
    endcase
end

// Select next PC: sequential or branch/jump target
always_comb begin : pc_select
    case (pc_source)
        1'b0    : pc_next = pc_plus_four;
        1'b1    : pc_next = pc_plus_second_add;
        default : pc_next = pc_plus_four;
    endcase
end

always_ff @(posedge clk) begin
    if (rst_n == 1'b0)
        pc <= 32'b0;
    else
        pc <= pc_next;
end


// ── INSTRUCTION MEMORY (ROM) ─────────────────────────────────────────────────
wire [31:0] instruction;

memory #(
    .mem_init("./test_imemory.hex")
) instruction_memory (
    .clk(clk),
    .address(pc),
    .write_data(32'b0),
    .write_enable(1'b0),
    .byte_enable(4'b0000),
    .rst_n(1'b1),
    .read_data(instruction)
);


// ── INSTRUCTION DECODE — field extraction ────────────────────────────────────
logic [6:0] op;
logic [2:0] f3;
logic [6:0] f7;
assign op = instruction[6:0];
assign f3 = instruction[14:12];
assign f7 = instruction[31:25]; // was hardwired 7'b0 — BUG fixed


// ── CONTROL UNIT ─────────────────────────────────────────────────────────────
wire        alu_zero;
wire        alu_last_bit;
wire [3:0]  alu_control;
wire [2:0]  imm_source;
wire        mem_write;
wire        reg_write;
wire        alu_source;
wire [1:0]  write_back_source;
wire        pc_source;
wire [1:0]  second_add_source;

control control_unit (
    .op(op),
    .func3(f3),
    .func7(f7),
    .alu_zero(alu_zero),
    .alu_last_bit(alu_last_bit),

    .alu_control(alu_control),
    .imm_source(imm_source),
    .mem_write(mem_write),
    .reg_write(reg_write),
    .alu_source(alu_source),
    .write_back_source(write_back_source),
    .pc_source(pc_source),
    .second_add_source(second_add_source)
);


// ── SIGN EXTENDER ────────────────────────────────────────────────────────────
logic [24:0] raw_imm;
assign raw_imm = instruction[31:7];
wire [31:0] immediate;

signext sign_extender (
    .raw_src(raw_imm),
    .imm_source(imm_source),
    .immediate(immediate)
);


// ── REGISTER FILE ────────────────────────────────────────────────────────────
logic [4:0]  source_reg1;
logic [4:0]  source_reg2;
logic [4:0]  dest_reg;
assign source_reg1 = instruction[19:15];
assign source_reg2 = instruction[24:20];
assign dest_reg    = instruction[11:7];

wire [31:0] read_reg1;
wire [31:0] read_reg2;
logic [31:0] write_back_data;
logic        wb_valid;

// Write-back mux — 4 sources
always_comb begin : write_back_source_select
    case (write_back_source)
        2'b00 : begin write_back_data = alu_result;                wb_valid = 1'b1; end // ALU result
        2'b01 : begin write_back_data = mem_read_write_back_data;  wb_valid = mem_read_write_back_valid; end // load
        2'b10 : begin write_back_data = pc_plus_four;             wb_valid = 1'b1; end // JAL/JALR return addr
        2'b11 : begin write_back_data = pc_plus_second_add;       wb_valid = 1'b1; end // LUI/AUIPC
        default: begin write_back_data = alu_result;              wb_valid = 1'b1; end
    endcase
end

regfile regfile (
    .clk(clk),
    .rst_n(rst_n),
    .address1(source_reg1),
    .address2(source_reg2),
    .read_data1(read_reg1),
    .read_data2(read_reg2),
    .write_enable(reg_write & wb_valid), // gate on wb_valid to suppress partial-load writes
    .write_data(write_back_data),
    .address3(dest_reg)
);


// ── ALU ──────────────────────────────────────────────────────────────────────
wire [31:0] alu_result;
logic [31:0] alu_src2;

always_comb begin : alu_source_select
    case (alu_source)
        1'b1    : alu_src2 = immediate;
        default : alu_src2 = read_reg2;
    endcase
end

alu alu_inst (
    .alu_control(alu_control),
    .src1(read_reg1),
    .src2(alu_src2),
    .alu_result(alu_result),
    .zero(alu_zero),
    .last_bit(alu_last_bit)
);


// ── LOAD/STORE DECODER ───────────────────────────────────────────────────────
wire [3:0]  mem_byte_enable;
wire [31:0] mem_write_data;

load_store_decoder ls_decode (
    .alu_result_address(alu_result),
    .f3(f3),
    .reg_read(read_reg2),
    .byte_enable(mem_byte_enable),
    .data(mem_write_data)
);


// ── DATA MEMORY ──────────────────────────────────────────────────────────────
wire [31:0] mem_read;

memory #(
    .mem_init("./test_dmemory.hex")
) data_memory (
    .clk(clk),
    .address({alu_result[31:2], 2'b00}), // word-aligned address
    .write_data(mem_write_data),
    .write_enable(mem_write),
    .byte_enable(mem_byte_enable),
    .rst_n(1'b1),
    .read_data(mem_read)
);


// ── READER — load data formatting + sign extension ───────────────────────────
wire [31:0] mem_read_write_back_data;
wire        mem_read_write_back_valid;

reader reader_inst (
    .mem_data(mem_read),
    .be_mask(mem_byte_enable),
    .f3(f3),
    .wb_data(mem_read_write_back_data),
    .valid(mem_read_write_back_valid)
);

endmodule
