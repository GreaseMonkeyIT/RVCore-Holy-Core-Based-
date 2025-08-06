// regfile.sv
module regfile(
    // Basic Signals
    input  logic        clk,
    input  logic        rst_n,

    // Read Ports
    input  logic [4:0]  address1,
    input  logic [4:0]  address2,
    output logic [31:0] read_data1,
    output logic [31:0] read_data2,

    // Write Port
    input  logic        write_enable,
    input  logic [31:0] write_data,
    input  logic [4:0]  address3
);

    // 32 general-purpose 32-bit registers
    logic [31:0] registers [0:31];

    // Synchronous write with active-low reset
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 32; i++) begin
                registers[i] <= 32'b0;
            end
        end else if (write_enable && address3 != 0) begin
            registers[address3] <= write_data;
        end
    end

    // Asynchronous reads
    always_comb begin
        read_data1 = registers[address1];
        read_data2 = registers[address2];
    end

endmodule
