module control (
    // IN
    input  logic [6:0] op,
    input  logic [2:0] func3,
    input  logic [6:0] func7,
    input  logic       alu_zero,

    // OUT
    output logic [2:0] alu_control,
    output logic [1:0] imm_source,
    output logic       mem_write,
    output logic       reg_write,
    output logic       alu_source,
    output logic       write_back_source,
    output logic       pc_source
);

/**
* MAIN DECODER
*/
logic [1:0] alu_op;
logic       branch;
always_comb begin
    // Default assignments to prevent latches
    reg_write = 1'b0;
    imm_source = 2'b00;
    mem_write = 1'b0;
    alu_op = 2'b00;
    alu_source = 1'b0;
    write_back_source = 1'b0;
    branch = 1'b0;

    case (op)
        7'b0000011 : begin // I-Type
            reg_write = 1'b1;
            imm_source = 2'b00;
            mem_write = 1'b0;
            alu_op = 2'b00;
            alu_source = 1'b1; 
            write_back_source = 1'b1;
            branch = 1'b0;
        end

        7'b0100011: begin // S-Type
            reg_write= 1'b0;
            imm_source= 2'b01;
            mem_write= 1'b1;
            alu_op= 2'b00;
            alu_source = 1'b1;
            branch = 1'b0;
        end

        7'b0110011 : begin // R-Type
            reg_write = 1'b1;
            mem_write = 1'b0;
            alu_op = 2'b10;
            alu_source = 1'b0;
            write_back_source = 1'b0;
            branch = 1'b0;
            // imm_source remains defaulted, no errors should be caused
        end

        7'b1100011 : begin // B-Type
            // B-Type instructions do not write to registers
            reg_write = 1'b0;
            imm_source = 2'b10;
            alu_source = 1'b0;
            mem_write = 1'b0;
            alu_op = 2'b01;
            branch = 1'b1;
        end

        default: begin // UNDEFINED
            // All default values replaced and assigned above
            reg_write = 1'b0;
            mem_write = 1'b0;
        end
    endcase
end


/**
* ALU DECODER
*/
always_comb begin
    case (alu_op)

        // LW, SW
        2'b00 : alu_control = 3'b000;
        // R-Types
        2'b10 : begin
            case (func3)
                // ADD
                3'b000 : alu_control = 3'b000;
                //AND
                3'b111 : alu_control = 3'b010;
                // OR
                3'b110 : alu_control = 3'b011;
                // ALL THE OTHERS
                default: alu_control = 3'b111;
            endcase
        end

        //BEQ
        2'b01: alu_control = 3'b001; // tells the alu to subtract

        // UNDEFINED INSTRUCTIONS
        default: alu_control = 3'b111;
    endcase
end

/**
*PC_Source (NEW!)
*/
assign pc_source=alu_zero&branch;

endmodule