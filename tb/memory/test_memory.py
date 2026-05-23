import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

BYTE_ENABLE_WORD = 0b1111   # full word write
BYTE_ENABLE_NONE = 0b0000   # no write (read-only cycles)

async def mem_reset(dut):
    dut.rst_n.value        = 0
    dut.write_enable.value = 0
    dut.byte_enable.value  = BYTE_ENABLE_NONE
    dut.address.value      = 0
    dut.write_data.value   = 0
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

@cocotb.test()
async def reset_clears_memory_test(dut):
    """After reset, all words should read as 0."""
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await mem_reset(dut)

    for word_idx in range(int(dut.WORDS.value)):
        dut.address.value      = word_idx * 4   # byte address
        dut.byte_enable.value  = BYTE_ENABLE_NONE
        dut.write_enable.value = 0
        await Timer(1, units="ns")
        assert dut.read_data.value == 0, \
            f"Word {word_idx} not zero after reset: {dut.read_data.value}"

@cocotb.test()
async def word_write_read_test(dut):
    """Write full words, read them back."""
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await mem_reset(dut)

    test_data = [
        (0x00, 0xDEADBEEF),
        (0x04, 0xCAFEBABE),
        (0x08, 0x12345678),
        (0x0C, 0xA5A5A5A5),
    ]

    for address, data in test_data:
        dut.address.value      = address
        dut.write_data.value   = data
        dut.write_enable.value = 1
        dut.byte_enable.value  = BYTE_ENABLE_WORD
        await RisingEdge(dut.clk)

        dut.write_enable.value = 0
        dut.byte_enable.value  = BYTE_ENABLE_NONE
        await RisingEdge(dut.clk)

        dut.address.value = address
        await Timer(1, units="ns")
        assert int(dut.read_data.value) == data, \
            f"Address 0x{address:02X}: expected 0x{data:08X}, got 0x{int(dut.read_data.value):08X}"

@cocotb.test()
async def byte_enable_test(dut):
    """Write individual bytes into a word using byte_enable masks."""
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await mem_reset(dut)

    # First write a known full word
    dut.address.value      = 0x10
    dut.write_data.value   = 0xAABBCCDD
    dut.write_enable.value = 1
    dut.byte_enable.value  = BYTE_ENABLE_WORD
    await RisingEdge(dut.clk)

    # Now overwrite only byte 0 (bits [7:0]) with 0xFF
    dut.address.value      = 0x10
    dut.write_data.value   = 0x000000FF
    dut.write_enable.value = 1
    dut.byte_enable.value  = 0b0001       # byte 0 only
    await RisingEdge(dut.clk)

    dut.write_enable.value = 0
    dut.byte_enable.value  = BYTE_ENABLE_NONE
    await RisingEdge(dut.clk)

    dut.address.value = 0x10
    await Timer(1, units="ns")
    # Byte 0 changed to FF, bytes 1-3 unchanged (AABBCC)
    assert int(dut.read_data.value) == 0xAABBCCFF, \
        f"Byte-enable write failed: got 0x{int(dut.read_data.value):08X}"

@cocotb.test()
async def sequential_word_write_test(dut):
    """Write a range of words and read them all back."""
    cocotb.start_soon(Clock(dut.clk, 1, units="ns").start())
    await mem_reset(dut)

    # Write words at addresses 0, 4, 8, ... (step 4 = one word each)
    num_words = 16
    for i in range(num_words):
        dut.address.value      = i * 4
        dut.write_data.value   = i + 0x100
        dut.write_enable.value = 1
        dut.byte_enable.value  = BYTE_ENABLE_WORD
        await RisingEdge(dut.clk)

    dut.write_enable.value = 0
    dut.byte_enable.value  = BYTE_ENABLE_NONE

    for i in range(num_words):
        dut.address.value = i * 4
        await RisingEdge(dut.clk)
        assert int(dut.read_data.value) == i + 0x100, \
            f"Word {i}: expected {i + 0x100}, got {int(dut.read_data.value)}"
