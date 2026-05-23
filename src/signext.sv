`timescale 1ns/1ps

module signext (
    // IN
    input  logic [24:0] raw_src,     // instruction[31:7]
    input  logic [2:0]  imm_source,  // 3-bit: selects immediate format

    // OUT
    output logic [31:0] immediate
);

/*
 * Immediate formats (RISC-V ISA Vol.I, Section 2.3):
 *
 *  raw_src bit index refers to instruction bits [31:7], so:
 *    raw_src[24] = inst[31]  (sign bit for all formats)
 *    raw_src[23:18] = inst[30:25]
 *    raw_src[17:13] = inst[24:20]
 *    raw_src[12:8]  = inst[19:15]  (rs1 field — not part of imm)
 *    raw_src[7:5]   = inst[14:12]  (funct3 — not part of imm)
 *    raw_src[4:0]   = inst[11:7]   (rd / lower S-imm bits)
 */

always_comb begin
    case (imm_source)

        // I-type: imm[11:0] = inst[31:20]
        3'b000 : immediate = {{20{raw_src[24]}}, raw_src[24:13]};

        // S-type: imm[11:5] = inst[31:25], imm[4:0] = inst[11:7]
        3'b001 : immediate = {{20{raw_src[24]}}, raw_src[24:18], raw_src[4:0]};

        // B-type: imm[12|10:5] = inst[31|30:25], imm[4:1|11] = inst[11:8|7], imm[0]=0
        3'b010 : immediate = {{20{raw_src[24]}}, raw_src[0], raw_src[23:18], raw_src[4:1], 1'b0};

        // J-type: imm[20|10:1|11|19:12] = inst[31|30:21|20|19:12], imm[0]=0
        3'b011 : immediate = {{12{raw_src[24]}}, raw_src[12:5], raw_src[13], raw_src[23:14], 1'b0};

        // U-type: imm[31:12] = inst[31:12], imm[11:0] = 0
        3'b100 : immediate = {raw_src[24:5], 12'b0};

        default: immediate = 32'b0;
    endcase
end

endmodule
