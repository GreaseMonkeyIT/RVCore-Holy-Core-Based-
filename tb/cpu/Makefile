# Makefile

# defaults
SIM ?= verilator
TOPLEVEL_LANG ?= verilog
EXTRA_ARGS += --trace --trace-structs
WAVES = 1

# List all the source files needed for the simulation
# Package must be first — all modules import it
VERILOG_SOURCES += $(PWD)/../../packages/holy_core_pkg.sv
VERILOG_SOURCES += $(PWD)/../../src/alu.sv
VERILOG_SOURCES += $(PWD)/../../src/regfile.sv
VERILOG_SOURCES += $(PWD)/../../src/signext.sv
VERILOG_SOURCES += $(PWD)/../../src/memory.sv
VERILOG_SOURCES += $(PWD)/../../src/load_store_decoder.sv
VERILOG_SOURCES += $(PWD)/../../src/reader.sv
VERILOG_SOURCES += $(PWD)/../../src/control.sv
VERILOG_SOURCES += $(PWD)/../../src/cpu.sv

COMPILE_ARGS += --public-flat-rw

# Top-level module
TOPLEVEL = cpu

# Python testbench module name (without .py)
MODULE = test_cpu

# Include cocotb's simulation make rules
include $(shell cocotb-config --makefiles)/Makefile.sim
