// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(op,6,0);
    VL_IN8(func3,2,0);
    VL_IN8(func7,6,0);
    VL_IN8(alu_zero,0,0);
    VL_IN8(alu_last_bit,0,0);
    VL_OUT8(alu_control,3,0);
    VL_OUT8(imm_source,2,0);
    VL_OUT8(mem_write,0,0);
    VL_OUT8(reg_write,0,0);
    VL_OUT8(alu_source,0,0);
    VL_OUT8(write_back_source,1,0);
    VL_OUT8(pc_source,0,0);
    VL_OUT8(second_add_source,1,0);
    CData/*6:0*/ control__DOT__op;
    CData/*2:0*/ control__DOT__func3;
    CData/*6:0*/ control__DOT__func7;
    CData/*0:0*/ control__DOT__alu_zero;
    CData/*0:0*/ control__DOT__alu_last_bit;
    CData/*3:0*/ control__DOT__alu_control;
    CData/*2:0*/ control__DOT__imm_source;
    CData/*0:0*/ control__DOT__mem_write;
    CData/*0:0*/ control__DOT__reg_write;
    CData/*0:0*/ control__DOT__alu_source;
    CData/*1:0*/ control__DOT__write_back_source;
    CData/*0:0*/ control__DOT__pc_source;
    CData/*1:0*/ control__DOT__second_add_source;
    CData/*1:0*/ control__DOT__alu_op;
    CData/*0:0*/ control__DOT__branch;
    CData/*0:0*/ control__DOT__jump;
    CData/*0:0*/ control__DOT__assert_branch;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
