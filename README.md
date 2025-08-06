RVCore — A Simple RISC-V Core in SystemVerilog (WIP)

This is a work-in-progress RISC-V RV32I core written in SystemVerilog, developed as part of my personal learning journey into processor design and computer architecture.

The implementation is heavily inspired by HOLY-CORE by Hugo Babin-Riby, a clean and minimal RISC-V CPU core that has been immensely helpful as a reference.

Currently Implemented Instructions

The following RV32I instructions are supported and have been tested:

    lw – Load Word

    sw – Store Word

    add – Register-Register Addition

    or – Bitwise OR

    and – Bitwise AND

Work in Progress

    beq – Branch if Equal (currently being added)

Purpose

This project is intended as a learning exercise, helping me understand:

    Instruction decoding

    ALU design

    Memory access handling

    Control signal generation

    Sequential logic design in SystemVerilog

Eventually, this core may be extended with:

    Control flow instructions

    A basic testbench and simulation setup

    Support for pipelining and more instructions from RV32I

Acknowledgements
	
	This project draws directly from the HOLY-CORE project. Huge thanks to Hugo Babin-Riby for making such a clean and readable SystemVerilog implementation available. It has served as both a guide and a source of motivation.

Disclaimer

	This project is for educational purposes. It is not optimized or complete, and things will break as development continues. Contributions, feedback, or ideas are welcome.
