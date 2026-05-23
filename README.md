# RVCore — Single-Cycle RV32I Core in SystemVerilog

**RVCore** is a fully implemented and verified **RV32I single-cycle CPU** written in **SystemVerilog**.  
Developed as a hands-on learning project in computer architecture and CPU design.

This project is **heavily inspired by and partially based on [HOLY-CORE](https://github.com/0BAB1/HOLY_CORE_COURSE)** by [Hugo Babin-Riby (0BAB1)](https://github.com/0BAB1/). The clean, modular design of HOLY-CORE was the primary reference and several modules were adapted from it directly. Hugo has been generous with his time and knowledge — this project would not be what it is without his work.

---

## Overview

RVCore implements the complete **RV32I base integer instruction set** (excluding CSR, ECALL, EBREAK, and FENCE) as a single-cycle datapath. Every instruction is verified end-to-end through a cocotb + Verilator testbench suite.

---

## Implemented & Verified Instructions

### Arithmetic & Logic
| Instruction | Type | Description |
|---|---|---|
| `ADD`, `ADDI` | R / I | Addition |
| `SUB` | R | Subtraction |
| `AND`, `ANDI` | R / I | Bitwise AND |
| `OR`, `ORI` | R / I | Bitwise OR |
| `XOR`, `XORI` | R / I | Bitwise XOR |
| `SLT`, `SLTI` | R / I | Set less than (signed) |
| `SLTU`, `SLTIU` | R / I | Set less than (unsigned) |
| `SLL`, `SLLI` | R / I | Logical left shift |
| `SRL`, `SRLI` | R / I | Logical right shift |
| `SRA`, `SRAI` | R / I | Arithmetic right shift |

### Upper Immediate
| Instruction | Description |
|---|---|
| `LUI` | Load upper immediate |
| `AUIPC` | Add upper immediate to PC |

### Load & Store (with full sub-word support)
| Instruction | Description |
|---|---|
| `LW` | Load word |
| `LH` / `LHU` | Load halfword (signed / unsigned) |
| `LB` / `LBU` | Load byte (signed / unsigned) |
| `SW` | Store word |
| `SH` | Store halfword |
| `SB` | Store byte |

Misaligned accesses are silently suppressed (no register or memory write occurs).

### Control Flow
| Instruction | Description |
|---|---|
| `BEQ` | Branch if equal |
| `BNE` | Branch if not equal |
| `BLT` / `BLTU` | Branch if less than (signed / unsigned) |
| `BGE` / `BGEU` | Branch if greater or equal (signed / unsigned) |
| `JAL` | Jump and link |
| `JALR` | Jump and link register |

---

## Project Structure

```
RVCore/
├── packages/
│   └── holy_core_pkg.sv       # Shared enums: opcodes, ALU ops, funct3/funct7
├── src/
│   ├── alu.sv                 # 10-operation ALU with zero and last_bit flags
│   ├── control.sv             # Main decoder + ALU decoder + branch condition logic
│   ├── signext.sv             # Immediate sign-extender (I/S/B/J/U formats)
│   ├── regfile.sv             # 32×32 register file, x0 hardwired to zero
│   ├── memory.sv              # Word-addressed RAM with byte-enable write masking
│   ├── load_store_decoder.sv  # Byte-lane alignment for SB/SH/SW
│   ├── reader.sv              # Load data extraction and sign extension (LB/LH/LBU/LHU/LW)
│   └── cpu.sv                 # Top-level datapath integrating all modules
└── tb/
    ├── alu/                   # ALU unit tests (1000 randomised cases per operation)
    ├── control/               # Control unit tests (all opcodes + branch conditions)
    ├── signext/               # Sign-extender tests (all immediate formats)
    ├── memory/                # Memory tests (reset, word R/W, byte-enable)
    ├── regfile/               # Register file tests
    └── cpu/                   # Full CPU integration test (all instructions end-to-end)
```

---

## Testbench Results

All tests pass using **cocotb v2.0.1** and **Verilator ≥ 5.036**.

| Testbench | Tests | Status |
|---|---|---|
| ALU | 13 | ✅ PASS |
| Control | 12 | ✅ PASS |
| Sign-extender | 7 | ✅ PASS |
| Memory | 4 | ✅ PASS |
| CPU (integration) | 1 (30+ instruction groups) | ✅ PASS |

The CPU integration test exercises every implemented instruction end-to-end, including taken and not-taken branches, forward and backward jumps, sub-word loads with sign extension, misaligned access suppression, and invalid shift encodings.

---

## Toolchain Setup (WSL2 / Ubuntu 24.04)

### 1. Install system dependencies
```bash
sudo apt update && sudo apt install -y \
    git make python3 python3-pip python3-venv \
    autoconf flex bison help2man libfl-dev \
    libgoogle-perftools-dev numactl perl
```

### 2. Build Verilator from source (≥ 5.036 required)
```bash
git clone https://github.com/verilator/verilator
cd verilator
git checkout stable
autoconf
./configure
make -j$(nproc)
sudo make install
verilator --version   # should show 5.036 or later
```

### 3. Set up Python environment
```bash
python3 -m venv ~/cocotb-env
source ~/cocotb-env/bin/activate
pip install cocotb
```

Add to `~/.bashrc` for persistence:
```bash
echo 'source ~/cocotb-env/bin/activate' >> ~/.bashrc
```

---

## Running the Tests

Each testbench has its own `Makefile`. Run from the relevant directory with the venv active.

```bash
# Unit tests
cd tb/alu     && make
cd tb/control && make
cd tb/signext && make
cd tb/memory  && make

# Full CPU integration test
cd tb/cpu && make
```

---

## Known Limitations

- Single-cycle only — no pipeline, no hazard detection
- No CSR registers, no privilege levels, no interrupts
- No ECALL / EBREAK / FENCE
- Memory is a flat simulation array — no cache, no external bus

---

## Acknowledgements

**[HOLY-CORE](https://github.com/0BAB1/HOLY_CORE_COURSE)**  
Author: [Hugo Babin-Riby (0BAB1)](https://github.com/0BAB1/)

HOLY-CORE provided the architectural reference, module structure, and the comprehensive CPU testbench program used here. RVCore would not be what it is without Hugo's clear and well-documented work. Highly recommended as a learning resource for anyone interested in RISC-V CPU design.

---

## Disclaimer

RVCore is a learning-focused project. It is not production-ready.  
Bug reports, suggestions, and constructive feedback are welcome.
