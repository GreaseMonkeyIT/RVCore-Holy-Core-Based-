`timescale 1ns/1ps

/*
 * load_store_decoder.sv
 *
 * Sits between the ALU and data memory on the write path.
 * Given the effective byte address (from ALU) and the source register,
 * it produces:
 *   byte_enable — which bytes of the word to write
 *   data        — write_data aligned to the correct byte lanes
 *
 * The reader module mirrors this on the read path.
 */

module load_store_decoder (
    input  logic [31:0] alu_result_address,  // byte address from ALU
    input  logic [2:0]  f3,                  // funct3 (SB/SH/SW)
    input  logic [31:0] reg_read,            // rs2 — data to store
    output logic [3:0]  byte_enable,
    output logic [31:0] data                 // lane-aligned write data
);

import holy_core_pkg::*;

logic [1:0] offset;
assign offset = alu_result_address[1:0]; // byte offset within the word

always_comb begin
    case (f3)

        // SB / LB / LBU — single byte
        F3_BYTE, F3_BYTE_U : begin
            case (offset)
                2'b00 : begin byte_enable = 4'b0001; data = (reg_read & 32'h0000_00FF);       end
                2'b01 : begin byte_enable = 4'b0010; data = (reg_read & 32'h0000_00FF) << 8;  end
                2'b10 : begin byte_enable = 4'b0100; data = (reg_read & 32'h0000_00FF) << 16; end
                2'b11 : begin byte_enable = 4'b1000; data = (reg_read & 32'h0000_00FF) << 24; end
                default: begin byte_enable = 4'b0000; data = 32'b0; end
            endcase
        end

        // SH / LH / LHU — halfword (must be 2-byte aligned)
        F3_HALFWORD, F3_HALFWORD_U : begin
            case (offset)
                2'b00 : begin byte_enable = 4'b0011; data = (reg_read & 32'h0000_FFFF);       end
                2'b10 : begin byte_enable = 4'b1100; data = (reg_read & 32'h0000_FFFF) << 16; end
                default: begin byte_enable = 4'b0000; data = 32'b0; end // misaligned — silently suppress
            endcase
        end

        // SW — full word (must be 4-byte aligned)
        F3_WORD : begin
            byte_enable = (offset == 2'b00) ? 4'b1111 : 4'b0000;
            data        = reg_read;
        end

        default : begin
            byte_enable = 4'b0000;
            data        = 32'b0;
        end
    endcase
end

endmodule
