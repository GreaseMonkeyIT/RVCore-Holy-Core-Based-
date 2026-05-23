// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.signext__DOT__raw_src = vlSelfRef.raw_src;
    vlSelfRef.signext__DOT__imm_source = vlSelfRef.imm_source;
    vlSelfRef.signext__DOT__immediate = ((4U & (IData)(vlSelfRef.signext__DOT__imm_source))
                                          ? (0xfffff000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (~ (IData)(vlSelfRef.signext__DOT__imm_source))))) 
                                                & ((vlSelfRef.signext__DOT__raw_src 
                                                    << 7U) 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.signext__DOT__imm_source) 
                                                                     >> 1U))))))))
                                          : ((2U & (IData)(vlSelfRef.signext__DOT__imm_source))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.signext__DOT__imm_source))
                                                  ? 
                                                 (((- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.signext__DOT__raw_src 
                                                                  >> 0x00000018U)))) 
                                                   << 0x00000014U) 
                                                  | ((((0x000001feU 
                                                        & (vlSelfRef.signext__DOT__raw_src 
                                                           >> 4U)) 
                                                       | (1U 
                                                          & (vlSelfRef.signext__DOT__raw_src 
                                                             >> 0x0000000dU))) 
                                                      << 0x0000000bU) 
                                                     | (0x000007feU 
                                                        & (vlSelfRef.signext__DOT__raw_src 
                                                           >> 0x0000000dU))))
                                                  : 
                                                 (((- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.signext__DOT__raw_src 
                                                                  >> 0x00000018U)))) 
                                                   << 0x0000000cU) 
                                                  | ((0x00000800U 
                                                      & (vlSelfRef.signext__DOT__raw_src 
                                                         << 0x0000000bU)) 
                                                     | ((0x000007e0U 
                                                         & (vlSelfRef.signext__DOT__raw_src 
                                                            >> 0x0000000dU)) 
                                                        | (0x0000001eU 
                                                           & vlSelfRef.signext__DOT__raw_src)))))
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.signext__DOT__raw_src 
                                                                 >> 0x00000018U)))) 
                                                  << 0x0000000cU) 
                                                 | (0x00000fffU 
                                                    & ((1U 
                                                        & (IData)(vlSelfRef.signext__DOT__imm_source))
                                                        ? 
                                                       ((0x00000fe0U 
                                                         & (vlSelfRef.signext__DOT__raw_src 
                                                            >> 0x0000000dU)) 
                                                        | (0x0000001fU 
                                                           & vlSelfRef.signext__DOT__raw_src))
                                                        : 
                                                       (vlSelfRef.signext__DOT__raw_src 
                                                        >> 0x0000000dU))))));
    vlSelfRef.immediate = vlSelfRef.signext__DOT__immediate;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/signext/../../src/signext.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.raw_src & 0xfe000000U)))) {
        Verilated::overWidthError("raw_src");
    }
    if (VL_UNLIKELY(((vlSelfRef.imm_source & 0xf8U)))) {
        Verilated::overWidthError("imm_source");
    }
}
#endif  // VL_DEBUG
