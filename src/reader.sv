`timescale 1ns/1ps

/*
 * reader.sv
 *
 * Sits on the read path between data memory and the write-back mux.
 * Given the raw 32-bit word from memory, the byte_enable mask that was
 * used on the store side (re-used here to know which lanes are active),
 * and funct3, it produces:
 *   wb_data — the correctly extracted and sign-extended value
 *   valid   — asserted when at least one byte_enable lane was active
 *             (used to gate the register file write)
 */

module reader (
    input  logic [31:0] mem_data,
    input  logic [3:0]  be_mask,   // same mask produced by load_store_decoder
    input  logic [2:0]  f3,
    output logic [31:0] wb_data,
    output logic        valid
);

import holy_core_pkg::*;

logic sign_extend;
assign sign_extend = ~f3[2]; // funct3[2]=0 → signed (LB/LH/LW), =1 → unsigned (LBU/LHU)

// Step 1: zero-out non-enabled byte lanes
logic [31:0] masked_data;
always_comb begin : mask_apply
    for (int i = 0; i < 4; i++) begin
        masked_data[(i*8)+:8] = be_mask[i] ? mem_data[(i*8)+:8] : 8'h00;
    end
end

// Step 2: shift the active bytes down to [7:0] or [15:0]
logic [31:0] raw_data;
always_comb begin : shift_data
    case (f3)
        F3_WORD : raw_data = masked_data;

        F3_BYTE, F3_BYTE_U : begin
            case (be_mask)
                4'b0001 : raw_data = masked_data;
                4'b0010 : raw_data = masked_data >> 8;
                4'b0100 : raw_data = masked_data >> 16;
                4'b1000 : raw_data = masked_data >> 24;
                default  : raw_data = 32'b0;
            endcase
        end

        F3_HALFWORD, F3_HALFWORD_U : begin
            case (be_mask)
                4'b0011 : raw_data = masked_data;
                4'b1100 : raw_data = masked_data >> 16;
                default  : raw_data = 32'b0;
            endcase
        end

        default : raw_data = 32'b0;
    endcase
end

// Step 3: sign-extend (or zero-extend for *U variants)
always_comb begin : sign_extend_logic
    case (f3)
        F3_WORD :
            wb_data = raw_data;
        F3_BYTE, F3_BYTE_U :
            wb_data = sign_extend ? {{24{raw_data[7]}},  raw_data[7:0]}  : {24'b0, raw_data[7:0]};
        F3_HALFWORD, F3_HALFWORD_U :
            wb_data = sign_extend ? {{16{raw_data[15]}}, raw_data[15:0]} : {16'b0, raw_data[15:0]};
        default :
            wb_data = 32'b0;
    endcase

    valid = |be_mask; // valid if any byte lane was active
end

endmodule
