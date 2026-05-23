import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

def binary_to_hex(bin_str):
    hex_str = hex(int(str(bin_str), 2))[2:]
    hex_str = hex_str.zfill(8)
    return hex_str.upper()

def hex_to_bin(hex_str):
    bin_str = bin(int(str(hex_str), 16))[2:]
    bin_str = bin_str.zfill(32)
    return bin_str.upper()

async def cpu_reset(dut):
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

@cocotb.test()
async def cpu_insrt_test(dut):
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await RisingEdge(dut.clk)
    await cpu_reset(dut)

    ##################
    # LOAD WORD TEST
    # lw x18 0x8(x0)
    ##################
    print("\n\nTESTING LW\n\n")
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[18].value) == "DEADBEEF", \
        f"expected DEADBEEF but got {binary_to_hex(dut.regfile.registers[18].value)} @ pc {binary_to_hex(dut.pc.value)}"

    ##################
    # STORE WORD TEST
    # sw x18 0xC(x0)
    ##################
    print("\n\nTESTING SW\n\n")
    test_address = int(0xC / 4)
    assert binary_to_hex(dut.data_memory.mem[test_address].value) == "F2F2F2F2", \
        f"expected F2F2F2F2 but got {binary_to_hex(dut.data_memory.mem[test_address].value)} @ pc {binary_to_hex(dut.pc.value)}"
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.data_memory.mem[test_address].value) == "DEADBEEF", \
        f"expected DEADBEEF but got {binary_to_hex(dut.data_memory.mem[test_address].value)} @ pc {binary_to_hex(dut.pc.value)}"

    ##################
    # ADD TEST
    # lw x19 0x10(x0)
    # add x20 x18 x19
    ##################
    print("\n\nTESTING ADD\n\n")
    expected_result = (0xDEADBEEF + 0x00000AAA) & 0xFFFFFFFF
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[19].value) == "00000AAA"
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[20].value) == hex(expected_result)[2:].upper(), \
        f"expected {hex(expected_result)[2:]} but got {binary_to_hex(dut.regfile.registers[20].value)} @ pc {binary_to_hex(dut.pc.value)}"

    ##################
    # AND TEST
    # and x21 x18 x20
    ##################
    print("\n\nTESTING AND\n\n")
    expected_result = expected_result & 0xDEADBEEF
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[21].value) == "DEAD8889"

    ##################
    # OR TEST
    # lw x5 0x14(x0) | x5 <= 125F552D
    # lw x6 0x18(x0) | x6 <= 7F4FD46A
    # or x7 x5 x6    | x7 <= 7F5FD56F
    ##################
    print("\n\nTESTING OR\n\n")
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[5].value) == "125F552D"
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[6].value) == "7F4FD46A"
    await RisingEdge(dut.clk)
    assert binary_to_hex(dut.regfile.registers[7].value) == "7F5FD56F"

    ##################
    # BEQ TEST
    # beq x6 x7 0xC       | #1 SHOULD NOT BRANCH
    # lw x22 0x8(x0)      | x22 <= DEADBEEF
    # beq x18 x22 0x10    | #2 SHOULD BRANCH (positive offset)
    # nop                 | NEVER EXECUTED
    # nop                 | NEVER EXECUTED
    # beq x0 x0 0xC       | #4 SHOULD BRANCH (avoid loop)
    # lw x22 0x0(x0)      | x22 <= AEAEAEAE  (#2 destination)
    # beq x22 x22 -0x8    | #3 SHOULD BRANCH (negative offset)
    # nop                 | FINAL NOP
    ##################
    print("\n\nTESTING BEQ\n\n")
    assert binary_to_hex(dut.instruction.value) == "00730663"

    await RisingEdge(dut.clk)  # beq x6 x7 0xC  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "00802B03"

    await RisingEdge(dut.clk)  # lw x22 0x8(x0)
    assert binary_to_hex(dut.regfile.registers[22].value) == "DEADBEEF"

    await RisingEdge(dut.clk)  # beq x18 x22 0x10  TAKEN
    assert binary_to_hex(dut.instruction.value) == "00002B03"

    await RisingEdge(dut.clk)  # lw x22 0x0(x0)
    assert binary_to_hex(dut.regfile.registers[22].value) == "AEAEAEAE"

    await RisingEdge(dut.clk)  # beq x22 x22 -0x8  TAKEN
    assert binary_to_hex(dut.instruction.value) == "00000663"

    await RisingEdge(dut.clk)  # beq x0 x0 0xC  TAKEN
    assert binary_to_hex(dut.instruction.value) == "00000013"
    await RisingEdge(dut.clk)  # NOP

    ##################
    # JAL TEST
    # jal x1 0xC      | #1 jump @PC+0xC   PC 0x44
    # nop             | NEVER EXECUTED    PC 0x48
    # jal x1 0xC      | #2 jump @PC+0xC   PC 0x4C
    # jal x1 -4       | #3 jump @PC-0x4   PC 0x50
    # nop             | NEVER EXECUTED    PC 0x54
    # lw x7 0xC(x0)   | x7 <= DEADBEEF   PC 0x58
    ##################
    print("\n\nTESTING JAL\n\n")
    assert binary_to_hex(dut.instruction.value) == "00C000EF"
    assert binary_to_hex(dut.pc.value) == "00000044"

    await RisingEdge(dut.clk)  # jal x1 0xC
    assert binary_to_hex(dut.instruction.value) == "FFDFF0EF"
    assert binary_to_hex(dut.pc.value) == "00000050"
    assert binary_to_hex(dut.regfile.registers[1].value) == "00000048"

    await RisingEdge(dut.clk)  # jal x1 -4
    assert binary_to_hex(dut.instruction.value) == "00C000EF"
    assert binary_to_hex(dut.pc.value) == "0000004C"
    assert binary_to_hex(dut.regfile.registers[1].value) == "00000054"

    await RisingEdge(dut.clk)  # jal x1 0xC
    assert binary_to_hex(dut.instruction.value) == "00C02383"
    assert binary_to_hex(dut.pc.value) == "00000058"
    assert binary_to_hex(dut.regfile.registers[1].value) == "00000050"

    await RisingEdge(dut.clk)  # lw x7 0xC(x0)
    assert binary_to_hex(dut.regfile.registers[7].value) == "DEADBEEF"

    ##################
    # ADDI TEST
    # addi x26 x7 0x1AB  | x26 <= DEADC09A
    # addi x25 x6 0xF21  | x25 <= 7F4FD38B
    ##################
    print("\n\nTESTING ADDI\n\n")
    assert binary_to_hex(dut.instruction.value) == "1AB38D13"
    assert not binary_to_hex(dut.regfile.registers[26].value) == "DEADC09A"

    await RisingEdge(dut.clk)  # addi x26 x7 0x1AB
    assert binary_to_hex(dut.instruction.value) == "F2130C93"
    assert binary_to_hex(dut.regfile.registers[26].value) == "DEADC09A"

    await RisingEdge(dut.clk)  # addi x25 x6 0xF21
    assert binary_to_hex(dut.regfile.registers[25].value) == "7F4FD38B"

    ##################
    # AUIPC TEST  (PC before is 0x64)
    # auipc x5 0x1F1FA  | x5 <= 1F1FA064
    ##################
    print("\n\nTESTING AUIPC\n\n")
    assert binary_to_hex(dut.instruction.value) == "1F1FA297"

    await RisingEdge(dut.clk)  # auipc x5 0x1F1FA
    assert binary_to_hex(dut.regfile.registers[5].value) == "1F1FA064"

    ##################
    # LUI TEST
    # lui x5 0x2F2FA  | x5 <= 2F2FA000
    ##################
    print("\n\nTESTING LUI\n\n")
    assert binary_to_hex(dut.instruction.value) == "2F2FA2B7"

    await RisingEdge(dut.clk)  # lui x5 0x2F2FA
    assert binary_to_hex(dut.regfile.registers[5].value) == "2F2FA000"

    ##################
    # SLTI TEST
    # slti x23 x19 0xFFF  | x23 <= 00000000
    # slti x23 x23 0x001  | x23 <= 00000001
    ##################
    print("\n\nTESTING SLTI\n\n")
    assert binary_to_hex(dut.regfile.registers[19].value) == "00000AAA"
    assert binary_to_hex(dut.instruction.value) == "FFF9AB93"

    await RisingEdge(dut.clk)  # slti x23 x19 0xFFF
    assert binary_to_hex(dut.regfile.registers[23].value) == "00000000"

    await RisingEdge(dut.clk)  # slti x23 x23 0x001
    assert binary_to_hex(dut.regfile.registers[23].value) == "00000001"

    ##################
    # SLTIU TEST
    # sltiu x22 x19 0xFFF  | x22 <= 00000001
    # sltiu x22 x19 0x001  | x22 <= 00000000
    ##################
    print("\n\nTESTING SLTIU\n\n")
    assert binary_to_hex(dut.instruction.value) == "FFF9BB13"

    await RisingEdge(dut.clk)  # sltiu x22 x19 0xFFF
    assert binary_to_hex(dut.regfile.registers[22].value) == "00000001"

    await RisingEdge(dut.clk)  # sltiu x22 x19 0x001
    assert binary_to_hex(dut.regfile.registers[22].value) == "00000000"

    ##################
    # XORI TEST
    # xori x18 x19 0xAAA  | x18 <= 21524445  (sign-extended 0xAAA = -1366)
    # xori x19 x18 0x000  | x19 <= 21524445
    ##################
    print("\n\nTESTING XORI\n\n")
    assert binary_to_hex(dut.instruction.value) == "AAA94913"

    await RisingEdge(dut.clk)  # xori x18 x19 0xAAA
    assert binary_to_hex(dut.regfile.registers[18].value) == "21524445"

    await RisingEdge(dut.clk)  # xori x19 x18 0x000
    assert binary_to_hex(dut.regfile.registers[19].value) == binary_to_hex(dut.regfile.registers[18].value)

    ##################
    # ORI TEST
    # ori x20 x19 0xAAA  | x20 <= FFFFFEEF
    # ori x21 x20 0x000  | x21 <= FFFFFEEF
    ##################
    print("\n\nTESTING ORI\n\n")
    assert binary_to_hex(dut.instruction.value) == "AAA9EA13"

    await RisingEdge(dut.clk)  # ori x20 x19 0xAAA
    assert binary_to_hex(dut.regfile.registers[20].value) == "FFFFFEEF"

    await RisingEdge(dut.clk)  # ori x21 x20 0x000
    assert binary_to_hex(dut.regfile.registers[21].value) == binary_to_hex(dut.regfile.registers[20].value)

    ##################
    # ANDI TEST
    # andi x18 x20 0x7FF  | x18 <= 000006EF
    # andi x19 x21 0xFFF  | x19 <= FFFFFEEF
    # andi x20 x21 0x000  | x20 <= 00000000
    ##################
    print("\n\nTESTING ANDI\n\n")
    assert binary_to_hex(dut.instruction.value) == "7FFA7913"

    await RisingEdge(dut.clk)  # andi x18 x20 0x7FF
    assert binary_to_hex(dut.regfile.registers[18].value) == "000006EF"

    await RisingEdge(dut.clk)  # andi x19 x21 0xFFF
    assert binary_to_hex(dut.regfile.registers[19].value) == binary_to_hex(dut.regfile.registers[21].value)
    assert binary_to_hex(dut.regfile.registers[19].value) == "FFFFFEEF"

    await RisingEdge(dut.clk)  # andi x20 x21 0x000
    assert binary_to_hex(dut.regfile.registers[20].value) == "00000000"

    ##################
    # SLLI TEST
    # slli x19 x19 0x4   | x19 <= FFFFEEF0
    # invalid op test    | NO CHANGE (wrong f7)
    ##################
    print("\n\nTESTING SLLI\n\n")
    assert binary_to_hex(dut.instruction.value) == "00499993"

    await RisingEdge(dut.clk)  # slli x19 x19 0x4
    assert binary_to_hex(dut.regfile.registers[19].value) == "FFFFEEF0"

    assert dut.reg_write.value == "0"
    await RisingEdge(dut.clk)  # invalid op — reg_write suppressed
    assert binary_to_hex(dut.regfile.registers[19].value) == "FFFFEEF0"

    ##################
    # SRLI TEST
    # srli x20 x19 0x4   | x20 <= 0FFFFEEF
    # invalid op test    | NO CHANGE (wrong f7)
    ##################
    print("\n\nTESTING SRLI\n\n")
    assert binary_to_hex(dut.instruction.value) == "0049DA13"

    await RisingEdge(dut.clk)  # srli x20 x19 0x4
    assert binary_to_hex(dut.regfile.registers[20].value) == "0FFFFEEF"

    assert dut.reg_write.value == "0"
    await RisingEdge(dut.clk)  # invalid op — reg_write suppressed
    assert binary_to_hex(dut.regfile.registers[20].value) == "0FFFFEEF"

    ##################
    # SRAI TEST
    # srai x21 x21 0x4   | x21 <= FFFFFFEE
    # invalid op test    | NO CHANGE (wrong f7)
    ##################
    print("\n\nTESTING SRAI\n\n")
    assert binary_to_hex(dut.instruction.value) == "404ADA93"

    await RisingEdge(dut.clk)  # srai x21 x21 0x4
    assert binary_to_hex(dut.regfile.registers[21].value) == "FFFFFFEE"

    assert dut.reg_write.value == "0"
    await RisingEdge(dut.clk)  # invalid op — reg_write suppressed
    assert binary_to_hex(dut.regfile.registers[21].value) == "FFFFFFEE"

    ##################
    # SUB TEST
    # sub x18 x21 x18  | x18 <= FFFFF8FF
    ##################
    print("\n\nTESTING SUB\n\n")
    assert binary_to_hex(dut.instruction.value) == "412A8933"

    await RisingEdge(dut.clk)  # sub x18 x21 x18
    assert binary_to_hex(dut.regfile.registers[18].value) == "FFFFF8FF"

    ##################
    # SLL TEST
    # addi x7 x0 0x8     | x7 <= 00000008
    # sll x18 x18 x7     | x18 <= FFF8FF00
    ##################
    print("\n\nTESTING SLL\n\n")
    assert binary_to_hex(dut.instruction.value) == "00800393"

    await RisingEdge(dut.clk)  # addi x7 x0 0x8
    assert binary_to_hex(dut.regfile.registers[7].value) == "00000008"

    await RisingEdge(dut.clk)  # sll x18 x18 x7
    assert binary_to_hex(dut.regfile.registers[18].value) == "FFF8FF00"

    ##################
    # SLT TEST
    # slt x17 x22 x23  | x17 <= 00000001
    ##################
    print("\n\nTESTING SLT\n\n")
    assert binary_to_hex(dut.instruction.value) == "013928B3"

    await RisingEdge(dut.clk)  # slt x17 x22 x23
    assert binary_to_hex(dut.regfile.registers[17].value) == "00000001"

    ##################
    # SLTU TEST
    # sltu x17 x22 x23  | x17 <= 00000001
    ##################
    print("\n\nTESTING SLTU\n\n")
    assert binary_to_hex(dut.instruction.value) == "013938B3"

    await RisingEdge(dut.clk)  # sltu x17 x22 x23
    assert binary_to_hex(dut.regfile.registers[17].value) == "00000001"

    ##################
    # XOR TEST
    # xor x17 x18 x19  | x17 <= 000711F0
    ##################
    print("\n\nTESTING XOR\n\n")
    assert binary_to_hex(dut.instruction.value) == "013948B3"

    await RisingEdge(dut.clk)  # xor x17 x18 x19
    assert binary_to_hex(dut.regfile.registers[17].value) == "000711F0"

    ##################
    # SRL TEST
    # srl x8 x19 x7  | x8 <= 00FFFFEE
    ##################
    print("\n\nTESTING SRL\n\n")
    assert binary_to_hex(dut.instruction.value) == "0079D433"

    await RisingEdge(dut.clk)  # srl x8 x19 x7
    assert binary_to_hex(dut.regfile.registers[8].value) == "00FFFFEE"

    ##################
    # SRA TEST
    # sra x8 x19 x7  | x8 <= FFFFFFEE
    ##################
    print("\n\nTESTING SRA\n\n")
    assert binary_to_hex(dut.instruction.value) == "4079D433"

    await RisingEdge(dut.clk)  # sra x8 x19 x7
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # BLT TEST
    # blt x17 x8 0x8  | not taken  (x17=pos, x8=neg)
    # blt x8 x17 0x8  | taken      (x8=neg < x17=pos)
    # addi x8 x0 0xC  | NEVER EXECUTED
    ##################
    print("\n\nTESTING BLT\n\n")
    assert binary_to_hex(dut.instruction.value) == "0088C463"
    assert binary_to_hex(dut.regfile.registers[17].value) == "000711F0"
    assert binary_to_hex(dut.regfile.registers[8].value)  == "FFFFFFEE"

    await RisingEdge(dut.clk)  # blt x17 x8 0x8  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "01144463"

    await RisingEdge(dut.clk)  # blt x8 x17 0x8  TAKEN
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # BNE TEST
    # bne x8 x8 0x8   | not taken
    # bne x8 x17 0x8  | taken
    # addi x8 x0 0xC  | NEVER EXECUTED
    ##################
    print("\n\nTESTING BNE\n\n")
    assert binary_to_hex(dut.instruction.value) == "00841463"

    await RisingEdge(dut.clk)  # bne x8 x8 0x8  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "01141463"

    await RisingEdge(dut.clk)  # bne x8 x17 0x8  TAKEN
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # BGE TEST
    # bge x8 x17 0x8  | not taken  (x8=neg < x17=pos)
    # bge x8 x8 0x8   | taken      (equal)
    # addi x8 x0 0xC  | NEVER EXECUTED
    ##################
    print("\n\nTESTING BGE\n\n")
    assert binary_to_hex(dut.instruction.value) == "01145463"

    await RisingEdge(dut.clk)  # bge x8 x17 0x8  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "00845463"

    await RisingEdge(dut.clk)  # bge x8 x8 0x8  TAKEN
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # BLTU TEST
    # bltu x8 x17 0x8  | not taken  (x8=0xFFFF... > x17=0x0007... unsigned)
    # bltu x17 x8 0x8  | taken      (x17 < x8 unsigned)
    # addi x8 x0 0xC   | NEVER EXECUTED
    ##################
    print("\n\nTESTING BLTU\n\n")
    assert binary_to_hex(dut.instruction.value) == "01146463"

    await RisingEdge(dut.clk)  # bltu x8 x17 0x8  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "0088E463"

    await RisingEdge(dut.clk)  # bltu x17 x8 0x8  TAKEN
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # BGEU TEST
    # bgeu x17 x8 0x8  | not taken  (x17 < x8 unsigned)
    # bgeu x8 x17 0x8  | taken      (x8 >= x17 unsigned)
    # addi x8 x0 0xC   | NEVER EXECUTED
    ##################
    print("\n\nTESTING BGEU\n\n")
    assert binary_to_hex(dut.instruction.value) == "0088F463"

    await RisingEdge(dut.clk)  # bgeu x17 x8 0x8  NOT TAKEN
    assert binary_to_hex(dut.instruction.value) == "01147463"

    await RisingEdge(dut.clk)  # bgeu x8 x17 0x8  TAKEN
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"

    ##################
    # JALR TEST
    # auipc x7 0x0      | x7 <= 0000010C + 0 = 0000010C   PC = 0x10C
    # addi x7 x7 0x10   | x7 <= 0000011C... wait           PC = 0x110
    # jalr x1 -4(x7)    | x1 <= 00000118, jump to 0x11C   PC = 0x114
    # addi x8 x0 0xC    | NEVER EXECUTED                  PC = 0x118
    ##################
    print("\n\nTESTING JALR\n\n")
    assert binary_to_hex(dut.instruction.value) == "00000397"
    assert binary_to_hex(dut.pc.value) == "0000010C"

    await RisingEdge(dut.clk)  # auipc x7 0x0
    await RisingEdge(dut.clk)  # addi x7 x7 0x10
    assert binary_to_hex(dut.regfile.registers[7].value) == "00000120"

    await RisingEdge(dut.clk)  # jalr x1 -4(x7)
    assert binary_to_hex(dut.regfile.registers[1].value) == "00000118"
    assert not binary_to_hex(dut.instruction.value) == "00C00413"
    assert binary_to_hex(dut.regfile.registers[8].value) == "FFFFFFEE"
    assert binary_to_hex(dut.pc.value) == "0000011C"

    ##################
    # SB TEST
    # sw x8 0x1(x0)  | NO WRITE — misaligned SW
    # sb x8 0x6(x0)  | mem[1] <= 00EE0000
    ##################
    print("\n\nTESTING SB\n\n")
    assert binary_to_hex(dut.instruction.value) == "008020A3"

    await RisingEdge(dut.clk)  # sw x8 0x1(x0)  misaligned — suppressed
    assert binary_to_hex(dut.data_memory.mem[1].value) == "00000000"

    await RisingEdge(dut.clk)  # sb x8 0x6(x0)
    assert binary_to_hex(dut.data_memory.mem[1].value) == "00EE0000"

    ##################
    # SH TEST
    # sh x8 1(x0)  | NO WRITE — misaligned
    # sh x8 3(x0)  | NO WRITE — misaligned
    # sh x8 6(x0)  | mem[1] <= FFEE0000
    ##################
    print("\n\nTESTING SH\n\n")
    assert binary_to_hex(dut.instruction.value) == "008010A3"

    await RisingEdge(dut.clk)  # sh x8 1(x0)  misaligned — suppressed
    assert binary_to_hex(dut.data_memory.mem[1].value) == "00EE0000"

    await RisingEdge(dut.clk)  # sh x8 3(x0)  misaligned — suppressed
    assert binary_to_hex(dut.data_memory.mem[1].value) == "00EE0000"

    await RisingEdge(dut.clk)  # sh x8 6(x0)
    assert binary_to_hex(dut.data_memory.mem[1].value) == "FFEE0000"

    ##################
    # PARTIAL LOAD TESTS
    # addi x7 x0 0x10     | x7 <= 00000010  (base)
    # lw x18 -1(x7)       | NO WRITE — misaligned LW
    # lb x18 -1(x7)       | x18 <= FFFFFFDE
    # lbu x19 -3(x7)      | x19 <= 000000BE
    # lh x20 -3(x7)       | NO WRITE — misaligned LH
    # lh x20 -6(x7)       | x20 <= FFFFDEAD
    # lhu x21 -3(x7)      | NO WRITE — misaligned LHU
    # lhu x21 -6(x7)      | x21 <= 0000DEAD
    ##################
    print("\n\nTESTING LB / LBU / LH / LHU\n\n")
    assert binary_to_hex(dut.instruction.value) == "01000393"

    await RisingEdge(dut.clk)  # addi x7 x0 0x10
    assert binary_to_hex(dut.regfile.registers[7].value) == "00000010"

    assert binary_to_hex(dut.regfile.registers[18].value) == "FFF8FF00"
    await RisingEdge(dut.clk)  # lw x18 -1(x7)  misaligned — suppressed
    assert binary_to_hex(dut.regfile.registers[18].value) == "FFF8FF00"

    await RisingEdge(dut.clk)  # lb x18 -1(x7)
    assert binary_to_hex(dut.regfile.registers[18].value) == "FFFFFFDE"

    await RisingEdge(dut.clk)  # lbu x19 -3(x7)
    assert binary_to_hex(dut.regfile.registers[19].value) == "000000BE"

    await RisingEdge(dut.clk)  # lh x20 -3(x7)  misaligned — suppressed
    assert binary_to_hex(dut.regfile.registers[20].value) == "0FFFFEEF"

    await RisingEdge(dut.clk)  # lh x20 -6(x7)
    assert binary_to_hex(dut.regfile.registers[20].value) == "FFFFDEAD"

    await RisingEdge(dut.clk)  # lhu x21 -3(x7)  misaligned — suppressed
    assert binary_to_hex(dut.regfile.registers[21].value) == "FFFFFFEE"

    await RisingEdge(dut.clk)  # lhu x21 -6(x7)
    assert binary_to_hex(dut.regfile.registers[21].value) == "0000DEAD"
