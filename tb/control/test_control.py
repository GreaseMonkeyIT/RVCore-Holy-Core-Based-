import cocotb
from cocotb.triggers import Timer

# ── Helper ───────────────────────────────────────────────────────────────────

async def init_inputs(dut):
    """Drive all control inputs to safe known values before each test."""
    await Timer(1, units="ns")
    dut.op.value       = 0
    dut.func3.value    = 0
    dut.func7.value    = 0
    dut.alu_zero.value = 0
    dut.alu_last_bit.value = 0
    await Timer(1, units="ns")

# ── LW ───────────────────────────────────────────────────────────────────────

@cocotb.test()
async def lw_control_test(dut):
    await init_inputs(dut)
    dut.op.value = 0b0000011   # I-type LOAD
    await Timer(1, units="ns")
    assert dut.alu_control.value       == "0000"   # ALU_ADD
    assert dut.imm_source.value        == "000"    # I-type immediate
    assert dut.mem_write.value         == "0"
    assert dut.reg_write.value         == "1"
    assert dut.alu_source.value        == "1"      # immediate
    assert dut.write_back_source.value == "01"     # memory read
    assert dut.pc_source.value         == "0"

# ── SW ───────────────────────────────────────────────────────────────────────

@cocotb.test()
async def sw_control_test(dut):
    await init_inputs(dut)
    dut.op.value = 0b0100011   # S-type STORE
    await Timer(1, units="ns")
    assert dut.alu_control.value == "0000"   # ALU_ADD
    assert dut.imm_source.value  == "001"    # S-type immediate
    assert dut.mem_write.value   == "1"
    assert dut.reg_write.value   == "0"
    assert dut.alu_source.value  == "1"
    assert dut.pc_source.value   == "0"

# ── R-type: ADD ──────────────────────────────────────────────────────────────

@cocotb.test()
async def add_control_test(dut):
    await init_inputs(dut)
    dut.op.value    = 0b0110011   # R-type
    dut.func3.value = 0b000       # ADD/SUB
    dut.func7.value = 0b0000000   # ADD (not SUB)
    await Timer(1, units="ns")
    assert dut.alu_control.value       == "0000"   # ALU_ADD
    assert dut.mem_write.value         == "0"
    assert dut.reg_write.value         == "1"
    assert dut.alu_source.value        == "0"      # reg2
    assert dut.write_back_source.value == "00"     # alu result
    assert dut.pc_source.value         == "0"

# ── R-type: SUB ──────────────────────────────────────────────────────────────

@cocotb.test()
async def sub_control_test(dut):
    await init_inputs(dut)
    dut.op.value    = 0b0110011
    dut.func3.value = 0b000
    dut.func7.value = 0b0100000   # SUB
    await Timer(1, units="ns")
    assert dut.alu_control.value == "0001"   # ALU_SUB

# ── R-type: AND ──────────────────────────────────────────────────────────────

@cocotb.test()
async def and_control_test(dut):
    await init_inputs(dut)
    dut.op.value    = 0b0110011
    dut.func3.value = 0b111       # AND
    await Timer(1, units="ns")
    assert dut.alu_control.value       == "0010"   # ALU_AND
    assert dut.mem_write.value         == "0"
    assert dut.reg_write.value         == "1"
    assert dut.alu_source.value        == "0"
    assert dut.write_back_source.value == "00"
    assert dut.pc_source.value         == "0"

# ── R-type: OR ───────────────────────────────────────────────────────────────

@cocotb.test()
async def or_control_test(dut):
    await init_inputs(dut)
    dut.op.value    = 0b0110011
    dut.func3.value = 0b110       # OR
    await Timer(1, units="ns")
    assert dut.alu_control.value       == "0011"   # ALU_OR
    assert dut.mem_write.value         == "0"
    assert dut.reg_write.value         == "1"
    assert dut.alu_source.value        == "0"
    assert dut.write_back_source.value == "00"
    assert dut.pc_source.value         == "0"

# ── I-type ALU: ADDI ─────────────────────────────────────────────────────────

@cocotb.test()
async def addi_control_test(dut):
    await init_inputs(dut)
    dut.op.value    = 0b0010011   # I-type ALU
    dut.func3.value = 0b000       # ADDI
    await Timer(1, units="ns")
    assert dut.alu_control.value       == "0000"   # ALU_ADD
    assert dut.reg_write.value         == "1"
    assert dut.alu_source.value        == "1"      # immediate
    assert dut.mem_write.value         == "0"
    assert dut.write_back_source.value == "00"
    assert dut.pc_source.value         == "0"

# ── BEQ ──────────────────────────────────────────────────────────────────────

@cocotb.test()
async def beq_control_test(dut):
    await init_inputs(dut)
    dut.op.value       = 0b1100011   # B-type
    dut.func3.value    = 0b000       # BEQ
    dut.alu_zero.value = 0
    await Timer(1, units="ns")
    assert dut.imm_source.value    == "010"    # B-type immediate
    assert dut.alu_control.value   == "0001"   # ALU_SUB (for zero comparison)
    assert dut.mem_write.value     == "0"
    assert dut.reg_write.value     == "0"
    assert dut.alu_source.value    == "0"
    assert dut.pc_source.value     == "0"      # not taken yet

    # Assert branch taken when zero flag goes high
    dut.alu_zero.value = 1
    await Timer(1, units="ns")
    assert dut.pc_source.value == "1"

# ── BNE ──────────────────────────────────────────────────────────────────────

@cocotb.test()
async def bne_control_test(dut):
    await init_inputs(dut)
    dut.op.value       = 0b1100011
    dut.func3.value    = 0b001       # BNE
    dut.alu_zero.value = 1           # equal → BNE NOT taken
    await Timer(1, units="ns")
    assert dut.pc_source.value == "0"

    dut.alu_zero.value = 0           # not equal → BNE taken
    await Timer(1, units="ns")
    assert dut.pc_source.value == "1"

# ── BLT ──────────────────────────────────────────────────────────────────────

@cocotb.test()
async def blt_control_test(dut):
    await init_inputs(dut)
    dut.op.value           = 0b1100011
    dut.func3.value        = 0b100       # BLT
    dut.alu_last_bit.value = 0           # not less-than → not taken
    await Timer(1, units="ns")
    assert dut.alu_control.value == "0101"   # ALU_SLT
    assert dut.pc_source.value   == "0"

    dut.alu_last_bit.value = 1           # less-than → taken
    await Timer(1, units="ns")
    assert dut.pc_source.value == "1"

# ── JAL ──────────────────────────────────────────────────────────────────────

@cocotb.test()
async def jal_control_test(dut):
    await init_inputs(dut)
    dut.op.value = 0b1101111   # JAL
    await Timer(1, units="ns")
    assert dut.reg_write.value         == "1"
    assert dut.imm_source.value        == "011"   # J-type immediate
    assert dut.write_back_source.value == "10"    # pc + 4 (return address)
    assert dut.pc_source.value         == "1"     # always jump
    assert dut.mem_write.value         == "0"

# ── LUI ──────────────────────────────────────────────────────────────────────

@cocotb.test()
async def lui_control_test(dut):
    await init_inputs(dut)
    dut.op.value = 0b0110111   # LUI
    await Timer(1, units="ns")
    assert dut.reg_write.value         == "1"
    assert dut.imm_source.value        == "100"   # U-type immediate
    assert dut.write_back_source.value == "11"    # pc_plus_second_add (imm directly)
    assert dut.second_add_source.value == "01"    # immediate only
    assert dut.mem_write.value         == "0"
    assert dut.pc_source.value         == "0"
