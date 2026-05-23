`timescale 1ns/1ps

module control (
    // IN
    input  logic [6:0] op,
    input  logic [2:0] func3,
    input  logic [6:0] func7,
    input  logic       alu_zero,
    input  logic       alu_last_bit,  // alu_result[0] for BLT/BGE family

    // OUT
    output logic [3:0] alu_control,
    output logic [2:0] imm_source,       // 3-bit: I/S/B/J/U formats
    output logic       mem_write,
    output logic       reg_write,
    output logic       alu_source,       // 0=reg2, 1=immediate
    output logic [1:0] write_back_source,// 00=alu, 01=mem, 10=pc+4, 11=pc+imm
    output logic       pc_source,        // 1 = take branch/jump
    output logic [1:0] second_add_source // 00=pc+imm, 01=imm only(LUI), 10=rs1+imm(JALR)
);

import holy_core_pkg::*;

// ── MAIN DECODER ────────────────────────────────────────────────────────────
logic [1:0] alu_op;
logic       branch;
logic       jump;

always_comb begin
    // Safe defaults — prevent latches and avoid unintended state changes
    reg_write         = 1'b0;
    imm_source        = 3'b000;
    mem_write         = 1'b0;
    alu_op            = 2'b00;
    alu_source        = 1'b0;
    write_back_source = 2'b00;
    branch            = 1'b0;
    jump              = 1'b0;
    second_add_source = 2'b00;

    case (op)

        // LW — I-type load
        OPCODE_I_TYPE_LOAD : begin
            reg_write         = 1'b1;
            imm_source        = 3'b000;
            alu_source        = 1'b1;   // use immediate as ALU src2
            alu_op            = ALU_OP_LOAD_STORE;
            write_back_source = 2'b01;  // data memory read
        end

        // ADDI / ANDI / ORI / XORI / SLTI / SLTIU / SLLI / SRLI / SRAI — I-type ALU
        OPCODE_I_TYPE_ALU : begin
            imm_source        = 3'b000;
            alu_source        = 1'b1;   // immediate
            alu_op            = ALU_OP_MATH;
            write_back_source = 2'b00;  // alu result
            // Shift instructions encode f7 in the upper 7 bits of the immediate.
            // Only valid f7 values are accepted; invalid encodings suppress the write.
            if (func3 == F3_SLL) begin
                reg_write = (func7 == F7_NORMAL) ? 1'b1 : 1'b0;
            end else if (func3 == F3_SRL_SRA) begin
                reg_write = (func7 == F7_NORMAL || func7 == F7_ALT) ? 1'b1 : 1'b0;
            end else begin
                reg_write = 1'b1;
            end
        end

        // SW — S-type
        OPCODE_S_TYPE : begin
            imm_source = 3'b001;
            alu_source = 1'b1;
            mem_write  = 1'b1;
            alu_op     = ALU_OP_LOAD_STORE;
        end

        // ADD / SUB / AND / OR / XOR / SLT / SLTU / SLL / SRL / SRA — R-type
        OPCODE_R_TYPE : begin
            reg_write         = 1'b1;
            alu_source        = 1'b0;   // reg2
            alu_op            = ALU_OP_MATH;
            write_back_source = 2'b00;
        end

        // BEQ / BNE / BLT / BGE / BLTU / BGEU — B-type
        OPCODE_B_TYPE : begin
            imm_source        = 3'b010;
            alu_source        = 1'b0;
            alu_op            = ALU_OP_BRANCHES;
            branch            = 1'b1;
            second_add_source = 2'b00;  // pc + imm
        end

        // JAL — J-type
        OPCODE_J_TYPE : begin
            reg_write         = 1'b1;
            imm_source        = 3'b011;
            write_back_source = 2'b10;  // pc + 4 (return address)
            jump              = 1'b1;
            second_add_source = 2'b00;  // pc + imm
        end

        // JALR — I-type variant
        OPCODE_J_TYPE_JALR : begin
            reg_write         = 1'b1;
            imm_source        = 3'b000;
            alu_source        = 1'b1;
            write_back_source = 2'b10;  // pc + 4 (return address)
            jump              = 1'b1;
            second_add_source = 2'b10;  // rs1 + imm
        end

        // LUI — U-type
        OPCODE_U_TYPE_LUI : begin
            reg_write         = 1'b1;
            imm_source        = 3'b100;
            write_back_source = 2'b11;  // pc_plus_second_add (imm directly)
            second_add_source = 2'b01;  // immediate only (not added to pc)
        end

        // AUIPC — U-type
        OPCODE_U_TYPE_AUIPC : begin
            reg_write         = 1'b1;
            imm_source        = 3'b100;
            write_back_source = 2'b11;  // pc + imm
            second_add_source = 2'b00;  // pc + imm
        end

        default : begin
            // Unknown opcode — do not touch CPU or memory state
            $display("[CONTROL] Unknown opcode: %b", op);
        end
    endcase
end


// ── ALU DECODER ─────────────────────────────────────────────────────────────
always_comb begin
    case (alu_op)

        // LW / SW — always ADD for address calculation
        ALU_OP_LOAD_STORE : alu_control = ALU_ADD;

        // R-type and I-type ALU
        ALU_OP_MATH : begin
            case (func3)
                F3_ADD_SUB : begin
                    // R-type: check f7 for SUB vs ADD
                    // I-type (ADDI): always ADD (f7 field is part of immediate, not op)
                    if (op == OPCODE_R_TYPE)
                        alu_control = (func7 == F7_ALT) ? ALU_SUB : ALU_ADD;
                    else
                        alu_control = ALU_ADD;
                end
                F3_AND     : alu_control = ALU_AND;
                F3_OR      : alu_control = ALU_OR;
                F3_XOR     : alu_control = ALU_XOR;
                F3_SLT     : alu_control = ALU_SLT;
                F3_SLTU    : alu_control = ALU_SLTU;
                F3_SLL     : alu_control = ALU_SLL;
                F3_SRL_SRA : alu_control = (func7 == F7_ALT) ? ALU_SRA : ALU_SRL;
                default    : alu_control = ALU_ADD;
            endcase
        end

        // Branches — ALU performs the comparison; branch_logic_decode handles the condition
        ALU_OP_BRANCHES : begin
            case (func3)
                F3_BEQ, F3_BNE   : alu_control = ALU_SUB;  // zero flag used
                F3_BLT, F3_BGE   : alu_control = ALU_SLT;  // signed compare, last_bit used
                F3_BLTU, F3_BGEU : alu_control = ALU_SLTU; // unsigned compare, last_bit used
                default           : alu_control = ALU_SUB;
            endcase
        end

        default : alu_control = ALU_ADD;
    endcase
end


// ── PC_SOURCE — branch condition decode ─────────────────────────────────────
logic assert_branch;

always_comb begin : branch_logic_decode
    case (func3)
        F3_BEQ        : assert_branch = alu_zero    & branch;  //  rs1 == rs2
        F3_BNE        : assert_branch = ~alu_zero   & branch;  //  rs1 != rs2
        F3_BLT, F3_BLTU : assert_branch = alu_last_bit & branch; // rs1 < rs2
        F3_BGE, F3_BGEU : assert_branch = ~alu_last_bit & branch; // rs1 >= rs2
        default        : assert_branch = 1'b0;
    endcase
end

assign pc_source = assert_branch | jump;

endmodule
