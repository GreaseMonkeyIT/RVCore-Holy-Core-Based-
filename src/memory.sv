`timescale 1ns/1ps

// memory.sv
module memory #(
    parameter WORDS    = 128,               // 512 bytes
    parameter mem_init = ""
) (
    input  logic        clk,
    input  logic [31:0] address,
    input  logic [31:0] write_data,
    input  logic [3:0]  byte_enable,        // per-byte write mask (from load_store_decoder)
    input  logic        write_enable,
    input  logic        rst_n,
    output logic [31:0] read_data
);

/*
 * Word-addressed array, byte-enable granularity on writes.
 * Read is always a full 32-bit word; the reader module narrows it.
 * Misaligned word writes are a fatal simulation error.
 */

reg [31:0] mem [0:WORDS-1];

initial begin
    if (mem_init != "") begin
        $readmemh(mem_init, mem);
    end
end

// Write
always @(posedge clk) begin
    if (rst_n == 1'b0) begin
        for (int i = 0; i < WORDS; i++) begin
            mem[i] <= 32'b0;
        end
    end else if (write_enable) begin
        if (address[1:0] != 2'b00) begin
            $fatal("[MEMORY] Misaligned write at address 0x%08h — check your code.", address);
        end else begin
            // Selectively write only the enabled bytes
            for (int i = 0; i < 4; i++) begin
                if (byte_enable[i]) begin
                    /* verilator lint_off WIDTHTRUNC */
                    mem[address[31:2] & (WORDS-1)][(i*8)+:8] <= write_data[(i*8)+:8];
                    /* verilator lint_on WIDTHTRUNC */
                end
            end
        end
    end
end

// Read — combinational, full word; reader module handles narrowing
always_comb begin
    /* verilator lint_off WIDTHTRUNC */
    read_data = mem[address[31:2] & (WORDS-1)];
    /* verilator lint_on WIDTHTRUNC */
end

endmodule
