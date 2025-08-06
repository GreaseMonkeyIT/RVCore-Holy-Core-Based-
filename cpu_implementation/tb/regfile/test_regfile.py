import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

@cocotb.test()
async def random_write_read_test(dut):
    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    await RisingEdge(dut.clk)

    # Initialize
    dut.rst_n.value = 0
    dut.write_enable.value = 0
    dut.address1.value = 0
    dut.address2.value = 0
    dut.address3.value = 0
    dut.write_data.value = 0

    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    theoretical_regs = [0 for _ in range(32)]

    for _ in range(1000):
        # Generate random addresses and value
        address1 = random.randint(1, 31)
        address2 = random.randint(1, 31)
        address3 = random.randint(1, 31)
        write_value = random.randint(0, 0xFFFFFFFF)

        # Perform the write
        dut.address3.value = address3
        dut.write_data.value = write_value
        dut.write_enable.value = 1
        await RisingEdge(dut.clk)
        dut.write_enable.value = 0
        theoretical_regs[address3] = write_value
        await RisingEdge(dut.clk)  # allow one cycle after write

        # Perform the reads
        dut.address1.value = address1
        dut.address2.value = address2
        await RisingEdge(dut.clk)  # allow read values to settle

        # Assertions
        read1 = int(dut.read_data1.value)
        read2 = int(dut.read_data2.value)
        expected1 = theoretical_regs[address1]
        expected2 = theoretical_regs[address2]

        assert read1 == expected1, f"Read1 mismatch: got {read1}, expected {expected1} at addr {address1}"
        assert read2 == expected2, f"Read2 mismatch: got {read2}, expected {expected2} at addr {address2}"

    # Special test: write to register 0 should be ignored
    dut.address3.value = 0
    dut.write_data.value = 0xAEAEAEAE
    dut.write_enable.value = 1
    await RisingEdge(dut.clk)
    dut.write_enable.value = 0
    theoretical_regs[0] = 0  # Should remain 0

    # Read from register 0
    dut.address1.value = 0
    await RisingEdge(dut.clk)
    read0 = int(dut.read_data1.value)
    assert read0 == 0, f"Register x0 should always return 0, got {read0}"

    cocotb.log.info("Random write/read test completed successfully.")
