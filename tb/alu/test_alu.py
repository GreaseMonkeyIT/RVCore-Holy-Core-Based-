import cocotb
from cocotb.triggers import Timer
import random
import ctypes

# ── Helpers ──────────────────────────────────────────────────────────────────

def to_signed32(val):
    """Interpret a 32-bit unsigned int as a signed int."""
    return ctypes.c_int32(val).value

def mask32(val):
    return val & 0xFFFFFFFF

# ALU control codes — match holy_core_pkg.sv
ALU_ADD  = 0b0000
ALU_SUB  = 0b0001
ALU_AND  = 0b0010
ALU_OR   = 0b0011
ALU_SLL  = 0b0100
ALU_SLT  = 0b0101
ALU_SRL  = 0b0110
ALU_SLTU = 0b0111
ALU_XOR  = 0b1000
ALU_SRA  = 0b1001

# ── Original tests (values unchanged, just made explicit) ─────────────────────

@cocotb.test()
async def add_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_ADD
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected = mask32(src1 + src2)
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def sub_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SUB
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected = mask32(src1 - src2)
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def and_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_AND
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == (src1 & src2)

@cocotb.test()
async def or_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_OR
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == (src1 | src2)

@cocotb.test()
async def zero_test(dut):
    """ADD of equal-magnitude pos/neg values should give zero flag."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_ADD
    dut.src1.value = 123
    dut.src2.value = mask32(-123)   # twos-complement -123 as uint
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == 0
    assert int(dut.zero.value) == 1

@cocotb.test()
async def default_test(dut):
    """Undefined control code should produce zero output."""
    await Timer(1, units="ns")
    dut.alu_control.value = 0b1111   # not in enum → default
    dut.src1.value = random.randint(0, 0xFFFFFFFF)
    dut.src2.value = random.randint(0, 0xFFFFFFFF)
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == 0

# ── New tests ─────────────────────────────────────────────────────────────────

@cocotb.test()
async def xor_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_XOR
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == (src1 ^ src2)

@cocotb.test()
async def slt_test(dut):
    """SLT: signed less-than. Result is 1 if src1 < src2 (signed), else 0."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SLT
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected = 1 if to_signed32(src1) < to_signed32(src2) else 0
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def sltu_test(dut):
    """SLTU: unsigned less-than."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SLTU
    for _ in range(1000):
        src1 = random.randint(0, 0xFFFFFFFF)
        src2 = random.randint(0, 0xFFFFFFFF)
        dut.src1.value = src1
        dut.src2.value = src2
        expected = 1 if src1 < src2 else 0
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def sll_test(dut):
    """SLL: logical left shift by shamt = src2[4:0]."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SLL
    for _ in range(500):
        src1  = random.randint(0, 0xFFFFFFFF)
        shamt = random.randint(0, 31)
        dut.src1.value = src1
        dut.src2.value = shamt
        expected = mask32(src1 << shamt)
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def srl_test(dut):
    """SRL: logical right shift (zero-fill)."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SRL
    for _ in range(500):
        src1  = random.randint(0, 0xFFFFFFFF)
        shamt = random.randint(0, 31)
        dut.src1.value = src1
        dut.src2.value = shamt
        expected = src1 >> shamt   # Python int >> is logical for positive values
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def sra_test(dut):
    """SRA: arithmetic right shift (sign-fill)."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SRA
    for _ in range(500):
        src1  = random.randint(0, 0xFFFFFFFF)
        shamt = random.randint(0, 31)
        dut.src1.value = src1
        dut.src2.value = shamt
        # Arithmetic shift: treat src1 as signed
        expected = mask32(to_signed32(src1) >> shamt)
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

@cocotb.test()
async def last_bit_test(dut):
    """last_bit == alu_result[0] — used by BLT/BGE branch logic."""
    await Timer(1, units="ns")
    dut.alu_control.value = ALU_SLT
    # Case where src1 < src2 (signed) → result=1 → last_bit=1
    dut.src1.value = mask32(-5)   # -5 in twos complement
    dut.src2.value = 10
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == 1
    assert int(dut.last_bit.value)   == 1

    # Case where src1 >= src2 → result=0 → last_bit=0
    dut.src1.value = 10
    dut.src2.value = mask32(-5)
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == 0
    assert int(dut.last_bit.value)   == 0
