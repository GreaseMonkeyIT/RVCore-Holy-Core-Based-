import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

def binary_to_hex(bin_str):
    # CONVERT BINARY STRING TO HEXADECIMAL
    hex_str = hex(int(str(bin_str), 2))[2:]
    hex_str = hex_str.zfill(8)
    return hex_str.upper()

def hex_to_bin(hex_str):
    # CONVERT HEX STRING TO BINARY
    bin_str = bin(int(str(hex_str), 16))[2:]
    bin_str = bin_str.zfill(32)
    return bin_str.upper()

async def wait_n_cycles(dut, n):
    # WAIT FOR N CLOCK CYCLES
    for _ in range(n):
        await RisingEdge(dut.clk)

@cocotb.coroutine
async def cpu_reset(dut):
    # INITIALIZE AND RESET
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)  # WAIT FOR A CLOCK EDGE AFTER RESET
    dut.rst_n.value = 1        # DE-ASSERT RESET
    await RisingEdge(dut.clk)  # WAIT FOR A CLOCK EDGE AFTER RESET

@cocotb.test()
async def cpu_insrt_test(dut):
    """RUNS A LW DATAPATH TEST"""
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await RisingEdge(dut.clk)
    await cpu_reset(dut)

    ##################
    # LOAD WORD TEST
    # LW X18 0X8(X0)
    ##################

    print("\n\nTESTING LW\n\n")
    # THE FIRST INSTRUCTION FOR THE TEST IN IMEM.HEX LOADS THE DATA FROM
    # DMEM @ ADDRESS 0X00000008 THAT HAPPENS TO BE 0XABCDABCD INTO REGISTER X18
    await RisingEdge(dut.clk)  # WAIT A CLOCK CYCLE FOR THE INSTRUCTION TO EXECUTE
    assert binary_to_hex(dut.regfile.registers[18].value) == "ABCDABCD"

    ##################
    # STORE WORD TEST
    # SW X18 0XC(X0)
    ##################

    print("\n\nTESTING SW\n\n")
    test_address = int(0xC / 4)
    # MEM IS BYTE ADDRESSED BUT IS MADE OUT OF WORDS IN THE EYES OF THE SOFTWARE
    # THE SECOND INSTRUCTION IN IMEM.HEX STORES DATA FROM X18 (ABCDABCD) @ ADDRESS 0X0000000C

    ##################
    # ADD TEST
    # LW X19 0X10(X0) (THIS MEMORY SPOT CONTAINS 0X00000AAA)
    # ADD X20 X18 X19
    ##################

    print("\n\nTESTING ADD\n\n")
    # EXPECTED RESULT OF X18 + X19
    expected_result = (0xABCDABCD + 0x00000AAA) & 0xFFFFFFFF

    # WAITING FOR THE LW X19 INSTRUCTION TO EXECUTE
    await wait_n_cycles(dut, 2)
    assert binary_to_hex(dut.regfile.registers[19].value) == "00000AAA", \
        f"X19 EXPECTED 00000AAA, GOT {binary_to_hex(dut.regfile.registers[19].value)}"

    # WAITING FOR THE ADD X20, X18, X19 INSTRUCTION TO COMPLETE
    await wait_n_cycles(dut, 2)
    assert binary_to_hex(dut.regfile.registers[20].value) == hex(expected_result)[2:].zfill(8).upper(), \
        f"X20 EXPECTED {hex(expected_result)[2:].zfill(8).upper()}, GOT {binary_to_hex(dut.regfile.registers[20].value)}"

    ##################
    # AND TEST
    # AND X21 X18 X20 (RESULT SHALL BE 0XABCDA245)
    ##################

    print("\n\nTESTING AND\n\n")
    # USE LAST EXPECTED RESULT, AS THIS INSTRUCTION USES LAST OP RESULT REGISTER
    expected_result = expected_result & 0xABCDABCD
    await RisingEdge(dut.clk)  # AND X21 X18 X20
    assert binary_to_hex(dut.regfile.registers[21].value) == "ABCDA245"

    ##################
    # OR TEST
    # LOAD NEW VALUES TO TEST OR INSTRUCTION
    # PRE-COMPUTED VALUES:
    # LW X5 0X14(X0) | X5 <= 125F552D
    # LW X6 0X18(X0) | X6 <= 7F4FD46A
    # OR X7 X5 X6    | X7 <= 7F5FD56F
    ##################

    print("\n\nTESTING OR\n\n")
    await RisingEdge(dut.clk)  # LW X5 0X14(X0)
    assert binary_to_hex(dut.regfile.registers[5].value) == "125F552D"
    await RisingEdge(dut.clk)  # LW X6 0X18(X0)
    assert binary_to_hex(dut.regfile.registers[6].value) == "7F4FD46A"
    await RisingEdge(dut.clk)  # OR X7 X5 X6
    assert binary_to_hex(dut.regfile.registers[7].value) == "7F5FD56F"
