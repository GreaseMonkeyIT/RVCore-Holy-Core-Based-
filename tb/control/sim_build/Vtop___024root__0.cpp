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

extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hba1b7ba9_0;

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.control__DOT__alu_zero = vlSelfRef.alu_zero;
    vlSelfRef.control__DOT__alu_last_bit = vlSelfRef.alu_last_bit;
    vlSelfRef.control__DOT__op = vlSelfRef.op;
    vlSelfRef.control__DOT__func7 = vlSelfRef.func7;
    vlSelfRef.control__DOT__func3 = vlSelfRef.func3;
    vlSelfRef.control__DOT__reg_write = 0U;
    vlSelfRef.control__DOT__imm_source = 0U;
    vlSelfRef.control__DOT__mem_write = 0U;
    vlSelfRef.control__DOT__alu_op = 0U;
    vlSelfRef.control__DOT__alu_source = 0U;
    vlSelfRef.control__DOT__write_back_source = 0U;
    vlSelfRef.control__DOT__branch = 0U;
    vlSelfRef.control__DOT__jump = 0U;
    vlSelfRef.control__DOT__second_add_source = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.control__DOT__op))) {
        if (VL_LIKELY(((0x00000020U & (IData)(vlSelfRef.control__DOT__op))))) {
            if (VL_UNLIKELY(((0x00000010U & (IData)(vlSelfRef.control__DOT__op))))) {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            } else if ((8U & (IData)(vlSelfRef.control__DOT__op))) {
                if (VL_LIKELY(((4U & (IData)(vlSelfRef.control__DOT__op))))) {
                    if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                        if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                            vlSelfRef.control__DOT__reg_write = 1U;
                            vlSelfRef.control__DOT__imm_source = 3U;
                            vlSelfRef.control__DOT__write_back_source = 2U;
                            vlSelfRef.control__DOT__jump = 1U;
                            vlSelfRef.control__DOT__second_add_source = 0U;
                        } else {
                            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                         , '#',7,vlSelfRef.control__DOT__op);
                        }
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.control__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else if ((4U & (IData)(vlSelfRef.control__DOT__op))) {
                if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                    if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                        vlSelfRef.control__DOT__reg_write = 1U;
                        vlSelfRef.control__DOT__imm_source = 0U;
                        vlSelfRef.control__DOT__alu_source = 1U;
                        vlSelfRef.control__DOT__write_back_source = 2U;
                        vlSelfRef.control__DOT__jump = 1U;
                        vlSelfRef.control__DOT__second_add_source = 2U;
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.control__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                    vlSelfRef.control__DOT__imm_source = 2U;
                    vlSelfRef.control__DOT__alu_source = 0U;
                    vlSelfRef.control__DOT__alu_op = 1U;
                    vlSelfRef.control__DOT__branch = 1U;
                    vlSelfRef.control__DOT__second_add_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.control__DOT__op))) {
        if ((0x00000010U & (IData)(vlSelfRef.control__DOT__op))) {
            if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.control__DOT__op))))) {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            } else if ((4U & (IData)(vlSelfRef.control__DOT__op))) {
                if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                    if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                        vlSelfRef.control__DOT__reg_write = 1U;
                        vlSelfRef.control__DOT__imm_source = 4U;
                        vlSelfRef.control__DOT__write_back_source = 3U;
                        vlSelfRef.control__DOT__second_add_source = 1U;
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.control__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                    vlSelfRef.control__DOT__reg_write = 1U;
                    vlSelfRef.control__DOT__alu_source = 0U;
                    vlSelfRef.control__DOT__alu_op = 2U;
                    vlSelfRef.control__DOT__write_back_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            }
        } else if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.control__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        } else if (VL_UNLIKELY(((4U & (IData)(vlSelfRef.control__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
            if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                vlSelfRef.control__DOT__imm_source = 1U;
                vlSelfRef.control__DOT__alu_source = 1U;
                vlSelfRef.control__DOT__mem_write = 1U;
                vlSelfRef.control__DOT__alu_op = 0U;
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.control__DOT__op))) {
        if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.control__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        } else if ((4U & (IData)(vlSelfRef.control__DOT__op))) {
            if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                    vlSelfRef.control__DOT__reg_write = 1U;
                    vlSelfRef.control__DOT__imm_source = 4U;
                    vlSelfRef.control__DOT__write_back_source = 3U;
                    vlSelfRef.control__DOT__second_add_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.control__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            }
        } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
            if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
                vlSelfRef.control__DOT__imm_source = 0U;
                vlSelfRef.control__DOT__alu_source = 1U;
                vlSelfRef.control__DOT__alu_op = 2U;
                vlSelfRef.control__DOT__write_back_source = 0U;
                vlSelfRef.control__DOT__reg_write = 
                    ((1U == (IData)(vlSelfRef.control__DOT__func3))
                      ? (0U == (IData)(vlSelfRef.control__DOT__func7))
                      : ((5U != (IData)(vlSelfRef.control__DOT__func3)) 
                         || ((0U == (IData)(vlSelfRef.control__DOT__func7)) 
                             | (0x20U == (IData)(vlSelfRef.control__DOT__func7)))));
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.control__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        }
    } else if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.control__DOT__op))))) {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.control__DOT__op);
    } else if (VL_UNLIKELY(((4U & (IData)(vlSelfRef.control__DOT__op))))) {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.control__DOT__op);
    } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.control__DOT__op))))) {
        if (VL_LIKELY(((1U & (IData)(vlSelfRef.control__DOT__op))))) {
            vlSelfRef.control__DOT__reg_write = 1U;
            vlSelfRef.control__DOT__imm_source = 0U;
            vlSelfRef.control__DOT__alu_source = 1U;
            vlSelfRef.control__DOT__alu_op = 0U;
            vlSelfRef.control__DOT__write_back_source = 1U;
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.control__DOT__op);
        }
    } else {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.control__DOT__op);
    }
    vlSelfRef.reg_write = vlSelfRef.control__DOT__reg_write;
    vlSelfRef.imm_source = vlSelfRef.control__DOT__imm_source;
    vlSelfRef.mem_write = vlSelfRef.control__DOT__mem_write;
    vlSelfRef.alu_source = vlSelfRef.control__DOT__alu_source;
    vlSelfRef.write_back_source = vlSelfRef.control__DOT__write_back_source;
    vlSelfRef.second_add_source = vlSelfRef.control__DOT__second_add_source;
    vlSelfRef.control__DOT__alu_control = (((2U == (IData)(vlSelfRef.control__DOT__alu_op))
                                             ? ((4U 
                                                 & (IData)(vlSelfRef.control__DOT__func3))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelfRef.control__DOT__func3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.control__DOT__func3))
                                                   ? 2U
                                                   : 3U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.control__DOT__func3))
                                                   ? 
                                                  ((0x20U 
                                                    == (IData)(vlSelfRef.control__DOT__func7))
                                                    ? 9U
                                                    : 6U)
                                                   : 8U))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelfRef.control__DOT__func3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.control__DOT__func3))
                                                   ? 7U
                                                   : 5U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.control__DOT__func3))
                                                   ? 4U
                                                   : 
                                                  (1U 
                                                   & (- (IData)(
                                                                ((0x20U 
                                                                  == (IData)(vlSelfRef.control__DOT__func7)) 
                                                                 & (0x33U 
                                                                    == (IData)(vlSelfRef.control__DOT__op)))))))))
                                             : (((4U 
                                                  & (IData)(vlSelfRef.control__DOT__func3))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.control__DOT__func3))
                                                   ? 7U
                                                   : 5U)
                                                  : 1U) 
                                                & (- (IData)(
                                                             (1U 
                                                              == (IData)(vlSelfRef.control__DOT__alu_op)))))) 
                                           & (- (IData)(
                                                        (0U 
                                                         != (IData)(vlSelfRef.control__DOT__alu_op)))));
    __Vtableidx1 = (((IData)(vlSelfRef.control__DOT__alu_zero) 
                     << 5U) | (((IData)(vlSelfRef.control__DOT__branch) 
                                << 4U) | (((IData)(vlSelfRef.control__DOT__alu_last_bit) 
                                           << 3U) | (IData)(vlSelfRef.control__DOT__func3))));
    vlSelfRef.control__DOT__assert_branch = Vtop__ConstPool__TABLE_hba1b7ba9_0
        [__Vtableidx1];
    vlSelfRef.alu_control = vlSelfRef.control__DOT__alu_control;
    vlSelfRef.control__DOT__pc_source = ((IData)(vlSelfRef.control__DOT__jump) 
                                         | (IData)(vlSelfRef.control__DOT__assert_branch));
    vlSelfRef.pc_source = vlSelfRef.control__DOT__pc_source;
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
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/control/../../src/control.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.op & 0x80U)))) {
        Verilated::overWidthError("op");
    }
    if (VL_UNLIKELY(((vlSelfRef.func3 & 0xf8U)))) {
        Verilated::overWidthError("func3");
    }
    if (VL_UNLIKELY(((vlSelfRef.func7 & 0x80U)))) {
        Verilated::overWidthError("func7");
    }
    if (VL_UNLIKELY(((vlSelfRef.alu_zero & 0xfeU)))) {
        Verilated::overWidthError("alu_zero");
    }
    if (VL_UNLIKELY(((vlSelfRef.alu_last_bit & 0xfeU)))) {
        Verilated::overWidthError("alu_last_bit");
    }
}
#endif  // VL_DEBUG
