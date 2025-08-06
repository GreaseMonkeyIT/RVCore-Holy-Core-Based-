# RVCore — A Simple RISC-V Core in SystemVerilog

**RVCore** is a work-in-progress implementation of a RISC-V **RV32I** core written in **SystemVerilog**.  
It is being developed as part of a personal learning journey into computer architecture and CPU design.

This project is **heavily inspired by [HOLY-CORE](https://github.com/HugoBabinRiby/HOLY-CORE)** by [Hugo Babin-Riby](https://github.com/HugoBabinRiby). The clear and modular design of HOLY-CORE has served as the primary reference throughout development.

---

## Overview

RVCore aims to gradually implement the base RV32I instruction set architecture in a readable and testable form. The current focus is on correctness, modularity, and educational clarity.

---

## Implemented Instructions

The following instructions from the RV32I base ISA have been successfully implemented and tested:

- `add` – Register-register addition  
- `or`  – Bitwise OR  
- `and` – Bitwise AND  
- `lw`  – Load word  
- `sw`  – Store word  

---

## Work in Progress

The following instructions and features are currently under active development:

- `beq` – Branch if equal

---

## Project Goals

- Learn CPU architecture and microarchitecture hands-on
- Implement a functional, minimal RV32I CPU in SystemVerilog
- Understand datapath, control logic, memory interface, and instruction decoding
- Build a testbench to validate instruction behavior
- Gradually add support for control flow and pipeline execution

---

## Project Structure

RVCore/
├── src/                 # SystemVerilog modules (ALU, RegFile, Control, etc.)
├── tb/                  # Testbench (Cocotb-based)
├── additional files     # Instruction memory, program loader, etc.

---

## Build and Simulation

Support for simulation (e.g. using Icarus Verilog or Verilator) is being added.  
Instructions for compiling and running simple programs will be documented as the project matures.

---

## Acknowledgements

This project is built on top of the concepts and structure provided by:

**[HOLY-CORE](https://github.com/HugoBabinRiby/HOLY-CORE)**  
Author: [Hugo Babin-Riby](https://github.com/HugoBabinRiby)

HOLY-CORE has been an exceptional reference for understanding how to implement a clean, simple RISC-V core in SystemVerilog. RVCore would not exist in its current form without it.

---

## Disclaimer

RVCore is a learning-focused project. It is not production-ready and is expected to evolve significantly.  
Bug reports, suggestions, and constructive feedback are welcome.
