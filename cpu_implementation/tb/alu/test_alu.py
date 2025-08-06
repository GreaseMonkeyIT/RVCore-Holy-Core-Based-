import cocotb
from cocotb.triggers import Timer
import random

def binary_to_hex(bin_val):
    return hex(int(str(bin_val), 2))[2:].zfill(8).upper()


@cocotb.test()
async def add_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = 0b000

    for _ in range(1000):
        src1 = random.randint(0,0xFFFFFFFF)
        src2 = random.randint(0,0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2

        # We mask expected to not take account of overflows
        expected = (src1 + src2) & 0xFFFFFFFF

        # Await 1 ns for the infos to propagate
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def sub_test(dut):
    await Timer(1,units="ns")
    dut.alu_control.value = 0b001
    for _ in range(1000):
        src1 = random.randint(0,0xFFFFFFFF)
        src2 = random.randint(0,0xFFFFFFFF)
        #src1 =random.randint(0,0xFF)
        #src2 =random.randint(0,0xFF)
        #print(bin(src1)[2:].zfill(8))
        #print(bin(src2)[2:].zfill(8))
        #print(bin(src1-src2)[2:].zfill(8))
        dut.src1.value = src1
        dut.src2.value = src2
        expected = (src1-src2) & 0xFFFFFFFF
        await Timer(1,units="ns")
        assert str(dut.alu_result.value) == bin(expected)[2:].zfill(32)
        assert binary_to_hex(dut.alu_result.value) == hex(expected)[2:].zfill(8).upper()
        assert int(str(dut.alu_result.value), 2) == expected

@cocotb.test()
async def default_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = 0b111
    src1 = random.randint(0,0xFFFFFFFF)
    src2 = random.randint(0,0xFFFFFFFF)
    dut.src1.value = src1
    dut.src2.value = src2
    expected = 0

    # Await 1 ns for the infos to propagate
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == expected

@cocotb.test()
async def zero_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = 0b000
    dut.src1.value = 123
    dut.src2.value = -123
    await Timer(1, units="ns")
    print(int(dut.alu_result.value))
    assert int(dut.zero.value) == 1
    assert int(dut.alu_result.value) == 0

@cocotb.test()
async def and_test(dut):
    await Timer(1,units="ns")
    dut.alu_control.value = 0b010
    for _ in range(1000):
        src1 = random.randint(0,0xFFFFFFFF)
        src2 = random.randint(0,0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected= src1 & src2
        #Await1nsfortheinfostopropagate
        await Timer(1,units="ns")
        assert int(dut.alu_result.value) ==expected

@cocotb.test()
async def or_test(dut):
    await Timer(1,units="ns")
    dut.alu_control.value = 0b011
    for _ in range(1000):
        src1 = random.randint(0,0xFFFFFFFF)
        src2 = random.randint(0,0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected= src1 | src2
        #Await1nsfortheinfostopropagate
        await Timer(1,units="ns")
        assert int(dut.alu_result.value) == expected