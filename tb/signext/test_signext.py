import cocotb
from cocotb.triggers import Timer
import random

# imm_source encoding (matches holy_core_pkg.sv / signext.sv)
IMM_I = 0b000
IMM_S = 0b001
IMM_B = 0b010
IMM_J = 0b011
IMM_U = 0b100

def sign_ext(val, bits):
    """Sign-extend a 'bits'-wide value to a Python int."""
    if val & (1 << (bits - 1)):
        val -= (1 << bits)
    return val

def mask32(val):
    return val & 0xFFFFFFFF

# ── I-type ───────────────────────────────────────────────────────────────────

@cocotb.test()
async def i_type_positive_test(dut):
    """I-type: positive immediate = 123."""
    imm = 0b000001111011   # 123, 12-bit
    raw_data = (imm << 13) | 0b0000000000000_1010101010101
    await Timer(1, units="ns")
    dut.raw_src.value   = raw_data
    dut.imm_source.value = IMM_I
    await Timer(1, units="ns")
    assert int(dut.immediate.value) == 123

@cocotb.test()
async def i_type_negative_test(dut):
    """I-type: negative immediate = -42."""
    imm = 0b111111010110   # -42 in 12-bit twos complement
    raw_data = (imm << 13) | 0b0000000000000_1010101010101
    await Timer(1, units="ns")
    dut.raw_src.value    = raw_data
    dut.imm_source.value = IMM_I
    await Timer(1, units="ns")
    result = int(dut.immediate.value) - (1 << 32)
    assert result == -42, f"Expected -42, got {result}"

@cocotb.test()
async def i_type_random_test(dut):
    """I-type: 200 randomised sign-extension checks."""
    for _ in range(200):
        imm12 = random.randint(0, 0xFFF)
        raw_data = (imm12 << 13) | random.randint(0, 0x1FFF)
        await Timer(1, units="ns")
        dut.raw_src.value    = raw_data
        dut.imm_source.value = IMM_I
        await Timer(1, units="ns")
        expected = mask32(sign_ext(imm12, 12))
        assert int(dut.immediate.value) == expected, \
            f"I-type: imm12={imm12:#05x}, expected={expected:#010x}, got={int(dut.immediate.value):#010x}"

# ── S-type ───────────────────────────────────────────────────────────────────

@cocotb.test()
async def s_type_random_test(dut):
    """S-type: imm[11:5] from raw_src[24:18], imm[4:0] from raw_src[4:0]."""
    for _ in range(200):
        imm12    = random.randint(0, 0xFFF)
        imm_11_5 = (imm12 >> 5) & 0x7F
        imm_4_0  = imm12 & 0x1F
        raw_data = (imm_11_5 << 18) | (imm_4_0)
        await Timer(1, units="ns")
        dut.raw_src.value    = raw_data
        dut.imm_source.value = IMM_S
        await Timer(1, units="ns")
        expected = mask32(sign_ext(imm12, 12))
        assert int(dut.immediate.value) == expected, \
            f"S-type: imm12={imm12:#05x}, expected={expected:#010x}, got={int(dut.immediate.value):#010x}"

# ── B-type ───────────────────────────────────────────────────────────────────

@cocotb.test()
async def b_type_test(dut):
    """
    B-type immediate layout (instruction bits):
      imm[12]   = inst[31]  = raw_src[24]
      imm[10:5] = inst[30:25] = raw_src[23:18]
      imm[4:1]  = inst[11:8]  = raw_src[4:1]
      imm[11]   = inst[7]     = raw_src[0]
      imm[0]    = 0 (always)
    """
    test_cases = [
        # (imm value, description)  — must be even (bit 0 always 0)
        (8,     "positive small offset +8"),
        (-8,    "negative small offset -8"),
        (4094,  "max positive B-type"),
        (-4096, "max negative B-type"),
    ]
    for imm_val, desc in test_cases:
        # Reconstruct raw_src from the known imm value
        imm_u = imm_val & 0x1FFF   # 13-bit unsigned representation
        bit12    = (imm_u >> 12) & 1
        bit11    = (imm_u >> 11) & 1
        bits10_5 = (imm_u >> 5)  & 0x3F
        bits4_1  = (imm_u >> 1)  & 0xF

        # Pack into raw_src[24:0]:
        #   raw_src[24]=bit12, raw_src[23:18]=bits10_5, raw_src[0]=bit11, raw_src[4:1]=bits4_1
        raw_src = (bit12 << 24) | (bits10_5 << 18) | (bits4_1 << 1) | (bit11 << 0)

        await Timer(1, units="ns")
        dut.raw_src.value    = raw_src
        dut.imm_source.value = IMM_B
        await Timer(1, units="ns")

        expected = mask32(imm_val)
        assert int(dut.immediate.value) == expected, \
            f"B-type '{desc}': expected {expected:#010x}, got {int(dut.immediate.value):#010x}"

# ── J-type ───────────────────────────────────────────────────────────────────

@cocotb.test()
async def j_type_test(dut):
    """
    J-type immediate layout (instruction bits):
      imm[20]    = inst[31]   = raw_src[24]
      imm[10:1]  = inst[30:21]= raw_src[23:14]
      imm[11]    = inst[20]   = raw_src[13]
      imm[19:12] = inst[19:12]= raw_src[12:5]
      imm[0]     = 0
    """
    test_cases = [
        (4,       "small forward jump"),
        (-4,      "small backward jump"),
        (1048574, "large positive JAL"),
        (-1048576,"max negative JAL"),
    ]
    for imm_val, desc in test_cases:
        imm_u = imm_val & 0x1FFFFF   # 21-bit unsigned
        bit20    = (imm_u >> 20) & 1
        bits19_12= (imm_u >> 12) & 0xFF
        bit11    = (imm_u >> 11) & 1
        bits10_1 = (imm_u >> 1)  & 0x3FF

        # Pack: raw_src[24]=bit20, raw_src[23:14]=bits10_1,
        #        raw_src[13]=bit11, raw_src[12:5]=bits19_12
        raw_src = ((bit20)     << 24) | \
                  ((bits10_1)  << 14) | \
                  ((bit11)     << 13) | \
                  ((bits19_12) <<  5)

        await Timer(1, units="ns")
        dut.raw_src.value    = raw_src
        dut.imm_source.value = IMM_J
        await Timer(1, units="ns")

        expected = mask32(imm_val)
        assert int(dut.immediate.value) == expected, \
            f"J-type '{desc}': expected {expected:#010x}, got {int(dut.immediate.value):#010x}"

# ── U-type ───────────────────────────────────────────────────────────────────

@cocotb.test()
async def u_type_test(dut):
    """U-type: upper 20 bits placed in imm[31:12], imm[11:0]=0."""
    test_cases = [
        0x12345,   # arbitrary upper 20 bits
        0xABCDE,
        0x00001,
        0xFFFFF,
    ]
    for upper20 in test_cases:
        # raw_src[24:5] = upper 20 bits of immediate
        raw_src = upper20 << 5
        await Timer(1, units="ns")
        dut.raw_src.value    = raw_src
        dut.imm_source.value = IMM_U
        await Timer(1, units="ns")
        expected = (upper20 << 12) & 0xFFFFFFFF
        assert int(dut.immediate.value) == expected, \
            f"U-type: upper20={upper20:#07x}, expected={expected:#010x}, got={int(dut.immediate.value):#010x}"
