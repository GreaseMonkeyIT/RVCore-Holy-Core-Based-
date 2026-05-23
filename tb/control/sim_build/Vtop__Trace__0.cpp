// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgCData(oldp+0,(vlSelfRef.op),7);
    bufp->chgCData(oldp+1,(vlSelfRef.func3),3);
    bufp->chgCData(oldp+2,(vlSelfRef.func7),7);
    bufp->chgBit(oldp+3,(vlSelfRef.alu_zero));
    bufp->chgBit(oldp+4,(vlSelfRef.alu_last_bit));
    bufp->chgCData(oldp+5,(vlSelfRef.alu_control),4);
    bufp->chgCData(oldp+6,(vlSelfRef.imm_source),3);
    bufp->chgBit(oldp+7,(vlSelfRef.mem_write));
    bufp->chgBit(oldp+8,(vlSelfRef.reg_write));
    bufp->chgBit(oldp+9,(vlSelfRef.alu_source));
    bufp->chgCData(oldp+10,(vlSelfRef.write_back_source),2);
    bufp->chgBit(oldp+11,(vlSelfRef.pc_source));
    bufp->chgCData(oldp+12,(vlSelfRef.second_add_source),2);
    bufp->chgCData(oldp+13,(vlSelfRef.control__DOT__op),7);
    bufp->chgCData(oldp+14,(vlSelfRef.control__DOT__func3),3);
    bufp->chgCData(oldp+15,(vlSelfRef.control__DOT__func7),7);
    bufp->chgBit(oldp+16,(vlSelfRef.control__DOT__alu_zero));
    bufp->chgBit(oldp+17,(vlSelfRef.control__DOT__alu_last_bit));
    bufp->chgCData(oldp+18,(vlSelfRef.control__DOT__alu_control),4);
    bufp->chgCData(oldp+19,(vlSelfRef.control__DOT__imm_source),3);
    bufp->chgBit(oldp+20,(vlSelfRef.control__DOT__mem_write));
    bufp->chgBit(oldp+21,(vlSelfRef.control__DOT__reg_write));
    bufp->chgBit(oldp+22,(vlSelfRef.control__DOT__alu_source));
    bufp->chgCData(oldp+23,(vlSelfRef.control__DOT__write_back_source),2);
    bufp->chgBit(oldp+24,(vlSelfRef.control__DOT__pc_source));
    bufp->chgCData(oldp+25,(vlSelfRef.control__DOT__second_add_source),2);
    bufp->chgCData(oldp+26,(vlSelfRef.control__DOT__alu_op),2);
    bufp->chgBit(oldp+27,(vlSelfRef.control__DOT__branch));
    bufp->chgBit(oldp+28,(vlSelfRef.control__DOT__jump));
    bufp->chgBit(oldp+29,(vlSelfRef.control__DOT__assert_branch));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
