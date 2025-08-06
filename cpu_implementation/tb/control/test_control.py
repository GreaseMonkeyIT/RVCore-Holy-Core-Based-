import cocotb
from cocotb.triggers import Timer
import random
from cocotb.binary import BinaryValue

@cocotb.coroutine
async def set_unknown(dut):
    # Set all input to unknown before each test
    await Timer(1,units="ns")
    dut.op.value = BinaryValue("XXXXXXX")
    #
    # Uncomment the following throughout the course when needed
    #
    # dut.func3.value = BinaryValue("XXX")
    # dut.func7.value=BinaryValue("XXXXXXX")
    # dut.alu_zero.value=BinaryValue("X")
    # dut.alu_last_bit.value=BinaryValue("X")
    await Timer(1,units="ns")
    
@cocotb.test()
async def lw_control_test(dut):
    # TEST CONTROL SIGNALS FOR LW
    await Timer(1,units="ns")
    dut.op.value = 0b0000011 # I-Type
    await Timer(1,units="ns")
    assert dut.alu_control.value == "000"
    assert dut.imm_source.value == "00"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "1"
    # Datapath mux sources
    assert dut.alu_source.value == "1"
    assert dut.write_back_source.value == "1"
    assert dut.pc_source.value == "0"

@cocotb.test()
async def sw_control_test(dut):
    # TEST CONTROL SIGNALS FOR SW
    await Timer(10,units="ns")
    dut.op.value = 0b0100011 # S-Type
    await Timer(1,units="ns")
    assert dut.alu_control.value == "000"
    assert dut.imm_source.value == "01"
    assert dut.mem_write.value == "1"
    assert dut.reg_write.value == "0"
    # Datapath mux sources
    assert dut.alu_source.value == "1"
    assert dut.pc_source.value == "0"


@cocotb.test()
async def add_control_test(dut):
    # TEST CONTROL SIGNALS FOR ADD
    await Timer(10, units="ns")
    dut.op.value = 0b0110011 # R-TYPE
    # F3 is important here and now
    dut.func3.value = 0b000
    await Timer(1, units="ns")
    assert dut.alu_control.value == "000"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "1"
    # Datapath mux sources
    assert dut.alu_source.value == "0"
    assert dut.write_back_source.value == "0"
    assert dut.pc_source.value == "0"

@cocotb.test()
async def and_control_test(dut):
    await set_unknown(dut)
    # TEST CONTROL SIGNALS FOR AND
    await Timer(10,units="ns")
    dut.op.value = 0b0110011 #R-TYPE
    # F3 is important here and now
    dut.func3.value =0b111
    await Timer(1,units="ns")
    assert dut.alu_control.value == "010"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "1"
    # Datapath muxsources
    assert dut.alu_source.value == "0"
    assert dut.write_back_source.value == "0"
    assert dut.pc_source.value == "0"

@cocotb.test()
async def or_control_test(dut):
    await set_unknown(dut)
    await Timer(10,units="ns")
    dut.op.value = 0b0110011
    dut.func3.value = 0b110
    await Timer(1,units="ns")
    # only thing that changes comp to add/and
    assert dut.alu_control.value == "011"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "1"
    assert dut.alu_source.value == "0"
    assert dut.write_back_source.value == "0"
    assert dut.pc_source.value == "0"

@cocotb.test()
async def beq_control_test(dut):
    await set_unknown(dut)
    # TEST CONTROL SIGNALS FOR BEQ
    await Timer(10,units="ns")
    dut.op.value = 0b1100011 # B-TYPE
    dut.func3.value = 0b000 # beq
    dut.alu_zero.value = 0b0
    await Timer(1,units="ns")
    assert dut.imm_source.value == "10"
    assert dut.alu_control.value == "001"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "0"
    assert dut.alu_source.value == "0"
    assert dut.branch.value == "1"
    assert dut.pc_source.value == "0"

    # Test if branching condition is met
    await Timer(3,units="ns")
    dut.alu_zero.value = 0b1
    await Timer(1,units="ns")
    assert dut.pc_source.value == "1"