// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/control/../../src/control.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3630531923276091163ull);
    vlSelf->func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17167398980792102871ull);
    vlSelf->func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 9521031397428840109ull);
    vlSelf->alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6877900235479524133ull);
    vlSelf->alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11272622237994397092ull);
    vlSelf->alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1754865974476159228ull);
    vlSelf->imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10065145166371004188ull);
    vlSelf->mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11468839172742666876ull);
    vlSelf->reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12827810274228629793ull);
    vlSelf->alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15377102592057122748ull);
    vlSelf->write_back_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1858231933752668070ull);
    vlSelf->pc_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12463004756257529121ull);
    vlSelf->second_add_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11206358290808556435ull);
    vlSelf->control__DOT__op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 10091991400898876186ull);
    vlSelf->control__DOT__func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2913317379052310580ull);
    vlSelf->control__DOT__func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 18400458879092405231ull);
    vlSelf->control__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4848146584683975244ull);
    vlSelf->control__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17532569709525714214ull);
    vlSelf->control__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1475372961970402298ull);
    vlSelf->control__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4179647577975631839ull);
    vlSelf->control__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15837600266890739578ull);
    vlSelf->control__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4172781194734883387ull);
    vlSelf->control__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10112234427487483849ull);
    vlSelf->control__DOT__write_back_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4065889845780847506ull);
    vlSelf->control__DOT__pc_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5278693478111558391ull);
    vlSelf->control__DOT__second_add_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16729555026165596725ull);
    vlSelf->control__DOT__alu_op = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2167531295479129457ull);
    vlSelf->control__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4843327407585655548ull);
    vlSelf->control__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9309894292066349831ull);
    vlSelf->control__DOT__assert_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10782063087366379952ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
}
