// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(128);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_control = new VerilatedScope{this, "control", "control", "control", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_control);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("alu_control", &(TOP.alu_control), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("alu_last_bit", &(TOP.alu_last_bit), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("alu_source", &(TOP.alu_source), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("alu_zero", &(TOP.alu_zero), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("func3", &(TOP.func3), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("func7", &(TOP.func7), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_TOP->varInsert("imm_source", &(TOP.imm_source), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("mem_write", &(TOP.mem_write), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("op", &(TOP.op), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_TOP->varInsert("pc_source", &(TOP.pc_source), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("reg_write", &(TOP.reg_write), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("second_add_source", &(TOP.second_add_source), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("write_back_source", &(TOP.write_back_source), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_control->varInsert("alu_control", &(TOP.control__DOT__alu_control), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_control->varInsert("alu_last_bit", &(TOP.control__DOT__alu_last_bit), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("alu_op", &(TOP.control__DOT__alu_op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_control->varInsert("alu_source", &(TOP.control__DOT__alu_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("alu_zero", &(TOP.control__DOT__alu_zero), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("assert_branch", &(TOP.control__DOT__assert_branch), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("branch", &(TOP.control__DOT__branch), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("func3", &(TOP.control__DOT__func3), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_control->varInsert("func7", &(TOP.control__DOT__func7), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_control->varInsert("imm_source", &(TOP.control__DOT__imm_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_control->varInsert("jump", &(TOP.control__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("mem_write", &(TOP.control__DOT__mem_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("op", &(TOP.control__DOT__op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_control->varInsert("pc_source", &(TOP.control__DOT__pc_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_control->varInsert("reg_write", &(TOP.control__DOT__reg_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_control->varInsert("second_add_source", &(TOP.control__DOT__second_add_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_control->varInsert("write_back_source", &(TOP.control__DOT__write_back_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_control);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_control, __Vscopep_control = nullptr);
    // Tear down sub module instances
}
