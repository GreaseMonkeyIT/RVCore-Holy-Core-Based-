// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__clk__0 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__clk__0 
        = vlSelfRef.cpu__DOT__regfile__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__rst_n__0 
        = vlSelfRef.cpu__DOT__regfile__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__data_memory__DOT__clk__0 
        = vlSelfRef.cpu__DOT__data_memory__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__instruction_memory__DOT__write_data = 0U;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__write_enable = 0U;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__byte_enable = 0U;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__rst_n = 1U;
    VL_READMEM_N(true, 32, 128, 0, "./test_imemory.hex"s
                 ,  &(vlSelfRef.cpu__DOT__instruction_memory__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.cpu__DOT__data_memory__DOT__rst_n = 1U;
    VL_READMEM_N(true, 32, 128, 0, "./test_dmemory.hex"s
                 ,  &(vlSelfRef.cpu__DOT__data_memory__DOT__mem)
                 , 0, ~0ULL);
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
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/cpu/../../src/cpu.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hba1b7ba9_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    // Body
    vlSelfRef.cpu__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.cpu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.cpu__DOT__pc_plus_four = ((IData)(4U) 
                                        + vlSelfRef.cpu__DOT__pc);
    vlSelfRef.cpu__DOT__instruction_memory__DOT__address 
        = vlSelfRef.cpu__DOT__pc;
    vlSelfRef.cpu__DOT__regfile__DOT__rst_n = vlSelfRef.cpu__DOT__rst_n;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__regfile__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__data_memory__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__read_data 
        = vlSelfRef.cpu__DOT__instruction_memory__DOT__mem
        [(0x0000007fU & (vlSelfRef.cpu__DOT__instruction_memory__DOT__address 
                         >> 2U))];
    vlSelfRef.cpu__DOT__instruction = vlSelfRef.cpu__DOT__instruction_memory__DOT__read_data;
    vlSelfRef.cpu__DOT__dest_reg = (0x0000001fU & (vlSelfRef.cpu__DOT__instruction 
                                                   >> 7U));
    vlSelfRef.cpu__DOT__source_reg1 = (0x0000001fU 
                                       & (vlSelfRef.cpu__DOT__instruction 
                                          >> 0x0000000fU));
    vlSelfRef.cpu__DOT__source_reg2 = (0x0000001fU 
                                       & (vlSelfRef.cpu__DOT__instruction 
                                          >> 0x00000014U));
    vlSelfRef.cpu__DOT__raw_imm = (vlSelfRef.cpu__DOT__instruction 
                                   >> 7U);
    vlSelfRef.cpu__DOT__op = (0x0000007fU & vlSelfRef.cpu__DOT__instruction);
    vlSelfRef.cpu__DOT__f7 = (vlSelfRef.cpu__DOT__instruction 
                              >> 0x00000019U);
    vlSelfRef.cpu__DOT__f3 = (7U & (vlSelfRef.cpu__DOT__instruction 
                                    >> 0x0000000cU));
    vlSelfRef.cpu__DOT__regfile__DOT__address3 = vlSelfRef.cpu__DOT__dest_reg;
    vlSelfRef.cpu__DOT__regfile__DOT__address1 = vlSelfRef.cpu__DOT__source_reg1;
    vlSelfRef.cpu__DOT__regfile__DOT__address2 = vlSelfRef.cpu__DOT__source_reg2;
    vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
        = vlSelfRef.cpu__DOT__raw_imm;
    vlSelfRef.cpu__DOT__control_unit__DOT__op = vlSelfRef.cpu__DOT__op;
    vlSelfRef.cpu__DOT__control_unit__DOT__func7 = vlSelfRef.cpu__DOT__f7;
    vlSelfRef.cpu__DOT__reader_inst__DOT__f3 = vlSelfRef.cpu__DOT__f3;
    vlSelfRef.cpu__DOT__ls_decode__DOT__f3 = vlSelfRef.cpu__DOT__f3;
    vlSelfRef.cpu__DOT__control_unit__DOT__func3 = vlSelfRef.cpu__DOT__f3;
    vlSelfRef.cpu__DOT__regfile__DOT__read_data1 = vlSelfRef.cpu__DOT__regfile__DOT__registers
        [vlSelfRef.cpu__DOT__regfile__DOT__address1];
    vlSelfRef.cpu__DOT__regfile__DOT__read_data2 = vlSelfRef.cpu__DOT__regfile__DOT__registers
        [vlSelfRef.cpu__DOT__regfile__DOT__address2];
    vlSelfRef.cpu__DOT__reader_inst__DOT__sign_extend 
        = (1U & (~ ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3) 
                    >> 2U)));
    vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__mem_write = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__branch = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__jump = 0U;
    vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
        if (VL_LIKELY(((0x00000020U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            if (VL_UNLIKELY(((0x00000010U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            } else if ((8U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
                if (VL_LIKELY(((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                        if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                            vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 3U;
                            vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 2U;
                            vlSelfRef.cpu__DOT__control_unit__DOT__jump = 1U;
                            vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 0U;
                        } else {
                            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                        }
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else if ((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
                if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                        vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 0U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 1U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 2U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__jump = 1U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 2U;
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 2U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 0U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 1U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__branch = 1U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
        if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
            if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            } else if ((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
                if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                        vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 4U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 3U;
                        vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 1U;
                    } else {
                        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                    }
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 0U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 2U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            }
        } else if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        } else if (VL_UNLIKELY(((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 1U;
                vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 1U;
                vlSelfRef.cpu__DOT__control_unit__DOT__mem_write = 1U;
                vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 0U;
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
        if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        } else if ((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))) {
            if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                    vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 4U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 3U;
                    vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source = 0U;
                } else {
                    VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                                 , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
                }
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            }
        } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
                vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 0U;
                vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 1U;
                vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 2U;
                vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 0U;
                vlSelfRef.cpu__DOT__control_unit__DOT__reg_write 
                    = ((1U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                        ? (0U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func7))
                        : ((5U != (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3)) 
                           || ((0U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func7)) 
                               | (0x20U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func7)))));
            } else {
                VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                             , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
            }
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        }
    } else if (VL_UNLIKELY(((8U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
    } else if (VL_UNLIKELY(((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
    } else if (VL_LIKELY(((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
        if (VL_LIKELY(((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op))))) {
            vlSelfRef.cpu__DOT__control_unit__DOT__reg_write = 1U;
            vlSelfRef.cpu__DOT__control_unit__DOT__imm_source = 0U;
            vlSelfRef.cpu__DOT__control_unit__DOT__alu_source = 1U;
            vlSelfRef.cpu__DOT__control_unit__DOT__alu_op = 0U;
            vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source = 1U;
        } else {
            VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                         , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
        }
    } else {
        VL_WRITEF_NX("[CONTROL] Unknown opcode: %b\n",1
                     , '#',7,vlSelfRef.cpu__DOT__control_unit__DOT__op);
    }
    vlSelfRef.cpu__DOT__read_reg1 = vlSelfRef.cpu__DOT__regfile__DOT__read_data1;
    vlSelfRef.cpu__DOT__read_reg2 = vlSelfRef.cpu__DOT__regfile__DOT__read_data2;
    vlSelfRef.cpu__DOT__mem_write = vlSelfRef.cpu__DOT__control_unit__DOT__mem_write;
    vlSelfRef.cpu__DOT__reg_write = vlSelfRef.cpu__DOT__control_unit__DOT__reg_write;
    vlSelfRef.cpu__DOT__write_back_source = vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source;
    vlSelfRef.cpu__DOT__second_add_source = vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source;
    vlSelfRef.cpu__DOT__control_unit__DOT__alu_control 
        = (((2U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_op))
             ? ((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                 ? ((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                     ? ((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                         ? 2U : 3U) : ((1U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                                        ? ((0x20U == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func7))
                                            ? 9U : 6U)
                                        : 8U)) : ((2U 
                                                   & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                                                    ? 7U
                                                    : 5U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                                                    ? 4U
                                                    : 
                                                   (1U 
                                                    & (- (IData)(
                                                                 ((0x20U 
                                                                   == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func7)) 
                                                                  & (0x33U 
                                                                     == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__op)))))))))
             : (((4U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                  ? ((2U & (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))
                      ? 7U : 5U) : 1U) & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_op)))))) 
           & (- (IData)((0U != (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_op)))));
    vlSelfRef.cpu__DOT__alu_source = vlSelfRef.cpu__DOT__control_unit__DOT__alu_source;
    vlSelfRef.cpu__DOT__imm_source = vlSelfRef.cpu__DOT__control_unit__DOT__imm_source;
    vlSelfRef.cpu__DOT__alu_inst__DOT__src1 = vlSelfRef.cpu__DOT__read_reg1;
    vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read = vlSelfRef.cpu__DOT__read_reg2;
    vlSelfRef.cpu__DOT__data_memory__DOT__write_enable 
        = vlSelfRef.cpu__DOT__mem_write;
    vlSelfRef.cpu__DOT__alu_control = vlSelfRef.cpu__DOT__control_unit__DOT__alu_control;
    vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source 
        = vlSelfRef.cpu__DOT__imm_source;
    vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control 
        = vlSelfRef.cpu__DOT__alu_control;
    vlSelfRef.cpu__DOT__sign_extender__DOT__immediate 
        = ((4U & (IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source))
            ? (0xfffff000U & ((- (IData)((1U & (~ (IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source))))) 
                              & ((vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                  << 7U) & (- (IData)(
                                                      (1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source) 
                                                           >> 1U))))))))
            : ((2U & (IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source))
                ? ((1U & (IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source))
                    ? (((- (IData)((1U & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                          >> 0x00000018U)))) 
                        << 0x00000014U) | ((((0x000001feU 
                                              & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                                 >> 4U)) 
                                             | (1U 
                                                & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                                   >> 0x0000000dU))) 
                                            << 0x0000000bU) 
                                           | (0x000007feU 
                                              & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                                 >> 0x0000000dU))))
                    : (((- (IData)((1U & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                          >> 0x00000018U)))) 
                        << 0x0000000cU) | ((0x00000800U 
                                            & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                               << 0x0000000bU)) 
                                           | ((0x000007e0U 
                                               & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                                  >> 0x0000000dU)) 
                                              | (0x0000001eU 
                                                 & vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src)))))
                : (((- (IData)((1U & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                      >> 0x00000018U)))) 
                    << 0x0000000cU) | (0x00000fffU 
                                       & ((1U & (IData)(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source))
                                           ? ((0x00000fe0U 
                                               & (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                                  >> 0x0000000dU)) 
                                              | (0x0000001fU 
                                                 & vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src))
                                           : (vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src 
                                              >> 0x0000000dU))))));
    vlSelfRef.cpu__DOT__immediate = vlSelfRef.cpu__DOT__sign_extender__DOT__immediate;
    vlSelfRef.cpu__DOT__pc_plus_second_add = ((0U == (IData)(vlSelfRef.cpu__DOT__second_add_source))
                                               ? (vlSelfRef.cpu__DOT__pc 
                                                  + vlSelfRef.cpu__DOT__immediate)
                                               : ((1U 
                                                   == (IData)(vlSelfRef.cpu__DOT__second_add_source))
                                                   ? vlSelfRef.cpu__DOT__immediate
                                                   : 
                                                  ((- (IData)(
                                                              (2U 
                                                               == (IData)(vlSelfRef.cpu__DOT__second_add_source)))) 
                                                   & (vlSelfRef.cpu__DOT__immediate 
                                                      + vlSelfRef.cpu__DOT__read_reg1))));
    vlSelfRef.cpu__DOT__alu_src2 = ((IData)(vlSelfRef.cpu__DOT__alu_source)
                                     ? vlSelfRef.cpu__DOT__immediate
                                     : vlSelfRef.cpu__DOT__read_reg2);
    vlSelfRef.cpu__DOT__alu_inst__DOT__src2 = vlSelfRef.cpu__DOT__alu_src2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__shamt = (0x0000001fU 
                                                & vlSelfRef.cpu__DOT__alu_inst__DOT__src2);
    vlSelfRef.cpu__DOT__alu_inst__DOT__alu_result = 
        ((8U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
          ? ((- (IData)((1U & (~ ((IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control) 
                                  >> 1U))))) & (((1U 
                                                  & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,5, vlSelfRef.cpu__DOT__alu_inst__DOT__src1, (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shamt))
                                                  : 
                                                 (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                                                  ^ vlSelfRef.cpu__DOT__alu_inst__DOT__src2)) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ 
                                                                 ((IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control) 
                                                                  >> 2U)))))))
          : ((4U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
              ? ((2U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                  ? ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                      ? (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         < vlSelfRef.cpu__DOT__alu_inst__DOT__src2)
                      : (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         >> (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shamt)))
                  : ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                      ? VL_LTS_III(32, vlSelfRef.cpu__DOT__alu_inst__DOT__src1, vlSelfRef.cpu__DOT__alu_inst__DOT__src2)
                      : (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         << (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shamt))))
              : ((2U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                  ? ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                      ? (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         | vlSelfRef.cpu__DOT__alu_inst__DOT__src2)
                      : (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         & vlSelfRef.cpu__DOT__alu_inst__DOT__src2))
                  : ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control))
                      ? ((IData)(1U) + (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                                        + (~ vlSelfRef.cpu__DOT__alu_inst__DOT__src2)))
                      : (vlSelfRef.cpu__DOT__alu_inst__DOT__src1 
                         + vlSelfRef.cpu__DOT__alu_inst__DOT__src2)))));
    vlSelfRef.cpu__DOT__alu_inst__DOT__zero = (0U == vlSelfRef.cpu__DOT__alu_inst__DOT__alu_result);
    vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit = (1U 
                                                   & vlSelfRef.cpu__DOT__alu_inst__DOT__alu_result);
    vlSelfRef.cpu__DOT__alu_result = vlSelfRef.cpu__DOT__alu_inst__DOT__alu_result;
    vlSelfRef.cpu__DOT__alu_zero = vlSelfRef.cpu__DOT__alu_inst__DOT__zero;
    vlSelfRef.cpu__DOT__alu_last_bit = vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit;
    vlSelfRef.cpu__DOT__data_memory__DOT__address = 
        (0xfffffffcU & vlSelfRef.cpu__DOT__alu_result);
    vlSelfRef.cpu__DOT__ls_decode__DOT__alu_result_address 
        = vlSelfRef.cpu__DOT__alu_result;
    vlSelfRef.cpu__DOT__control_unit__DOT__alu_zero 
        = vlSelfRef.cpu__DOT__alu_zero;
    vlSelfRef.cpu__DOT__control_unit__DOT__alu_last_bit 
        = vlSelfRef.cpu__DOT__alu_last_bit;
    vlSelfRef.cpu__DOT__data_memory__DOT__read_data 
        = vlSelfRef.cpu__DOT__data_memory__DOT__mem
        [(0x0000007fU & (vlSelfRef.cpu__DOT__data_memory__DOT__address 
                         >> 2U))];
    vlSelfRef.cpu__DOT__ls_decode__DOT__offset = (3U 
                                                  & vlSelfRef.cpu__DOT__ls_decode__DOT__alu_result_address);
    __Vtableidx1 = (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_zero) 
                     << 5U) | (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__branch) 
                                << 4U) | (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_last_bit) 
                                           << 3U) | (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))));
    vlSelfRef.cpu__DOT__control_unit__DOT__assert_branch 
        = Vtop__ConstPool__TABLE_hba1b7ba9_0[__Vtableidx1];
    vlSelfRef.cpu__DOT__mem_read = vlSelfRef.cpu__DOT__data_memory__DOT__read_data;
    if ((4U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
        if ((2U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data = 0U;
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0U;
        } else if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
            if ((0U == (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
                vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                    = (0x0000ffffU & vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read);
                vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 3U;
            } else if ((2U == (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
                vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                    = (0xffff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000010U));
                vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0x0cU;
            } else {
                vlSelfRef.cpu__DOT__ls_decode__DOT__data = 0U;
                vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
            if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
                vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                    = (0xff000000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000018U));
                vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 8U;
            } else {
                vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                    = (0x00ff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000010U));
                vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 4U;
            }
        } else if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0x0000ff00U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 8U));
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 2U;
        } else {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0x000000ffU & vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read);
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
        if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data = 0U;
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0U;
        } else {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read;
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable 
                = ((0U == (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))
                    ? 0x0fU : 0U);
        }
    } else if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__f3))) {
        if ((0U == (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0x0000ffffU & vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read);
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 3U;
        } else if ((2U == (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0xffff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000010U));
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0x0cU;
        } else {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data = 0U;
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 0U;
        }
    } else if ((2U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
        if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0xff000000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000018U));
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 8U;
        } else {
            vlSelfRef.cpu__DOT__ls_decode__DOT__data 
                = (0x00ff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 0x00000010U));
            vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 4U;
        }
    } else if ((1U & (IData)(vlSelfRef.cpu__DOT__ls_decode__DOT__offset))) {
        vlSelfRef.cpu__DOT__ls_decode__DOT__data = 
            (0x0000ff00U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read, 8U));
        vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 2U;
    } else {
        vlSelfRef.cpu__DOT__ls_decode__DOT__data = 
            (0x000000ffU & vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read);
        vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable = 1U;
    }
    vlSelfRef.cpu__DOT__control_unit__DOT__pc_source 
        = ((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__jump) 
           | (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__assert_branch));
    vlSelfRef.cpu__DOT__reader_inst__DOT__mem_data 
        = vlSelfRef.cpu__DOT__mem_read;
    vlSelfRef.cpu__DOT__mem_write_data = vlSelfRef.cpu__DOT__ls_decode__DOT__data;
    vlSelfRef.cpu__DOT__mem_byte_enable = vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable;
    vlSelfRef.cpu__DOT__pc_source = vlSelfRef.cpu__DOT__control_unit__DOT__pc_source;
    vlSelfRef.cpu__DOT__data_memory__DOT__write_data 
        = vlSelfRef.cpu__DOT__mem_write_data;
    vlSelfRef.cpu__DOT__data_memory__DOT__byte_enable 
        = vlSelfRef.cpu__DOT__mem_byte_enable;
    vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask = vlSelfRef.cpu__DOT__mem_byte_enable;
    vlSelfRef.cpu__DOT__pc_next = ((IData)(vlSelfRef.cpu__DOT__pc_source)
                                    ? vlSelfRef.cpu__DOT__pc_plus_second_add
                                    : vlSelfRef.cpu__DOT__pc_plus_four);
    vlSelfRef.cpu__DOT__reader_inst__DOT__valid = (0U 
                                                   != (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask));
    vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 4U, vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data 
            = (((~ ((IData)(0x000000ffU) << (0x0000001fU 
                                             & VL_MULS_III(32, (IData)(8U), vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i)))) 
                & vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data) 
               | (0x00000000ffffffffULL & (((1U & ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask) 
                                                   >> 
                                                   (3U 
                                                    & vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i)))
                                             ? (0x000000ffU 
                                                & (vlSelfRef.cpu__DOT__reader_inst__DOT__mem_data 
                                                   >> 
                                                   (0x0000001fU 
                                                    & VL_MULS_III(32, (IData)(8U), vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i))))
                                             : 0U) 
                                           << (0x0000001fU 
                                               & VL_MULS_III(32, (IData)(8U), vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i)))));
        vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.cpu__DOT__mem_read_write_back_valid = vlSelfRef.cpu__DOT__reader_inst__DOT__valid;
    vlSelfRef.cpu__DOT__wb_valid = ((1U & ((IData)(vlSelfRef.cpu__DOT__write_back_source) 
                                           >> 1U)) 
                                    || ((1U & (~ (IData)(vlSelfRef.cpu__DOT__write_back_source))) 
                                        || (IData)(vlSelfRef.cpu__DOT__mem_read_write_back_valid)));
    __VdfgRegularize_h6e95ff9d_0_3 = ((1U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
                                       ? ((3U == (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))
                                           ? vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data
                                           : (VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data, 0x00000010U) 
                                              & (- (IData)(
                                                           (0x0cU 
                                                            == (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))))))
                                       : ((8U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))
                                           ? ((- (IData)(
                                                         (1U 
                                                          & (~ 
                                                             ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask) 
                                                              >> 1U))))) 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))))) 
                                                 & (VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data, 0x00000018U) 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask) 
                                                                      >> 2U))))))))
                                           : ((4U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))
                                               ? ((- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))))) 
                                                  & (VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data, 0x00000010U) 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (~ 
                                                                      ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask) 
                                                                       >> 1U)))))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))
                                                   ? 
                                                  (VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data, 8U) 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask))))))
                                                   : 
                                                  (vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask)))))))));
    vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data 
        = ((4U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
            ? (__VdfgRegularize_h6e95ff9d_0_3 & (- (IData)(
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3) 
                                                                >> 1U))))))
            : ((2U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
                ? (vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data 
                   & (- (IData)((1U & (~ (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))))))
                : __VdfgRegularize_h6e95ff9d_0_3));
    __VdfgRegularize_h6e95ff9d_0_4 = ((1U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
                                       ? ((((- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data 
                                                           >> 0x0000000fU)))) 
                                            & (- (IData)((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__sign_extend)))) 
                                           << 0x00000010U) 
                                          | (0x0000ffffU 
                                             & vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data))
                                       : ((((- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data 
                                                           >> 7U)))) 
                                            & (- (IData)((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__sign_extend)))) 
                                           << 8U) | 
                                          (0x000000ffU 
                                           & vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data)));
    vlSelfRef.cpu__DOT__reader_inst__DOT__wb_data = 
        ((4U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
          ? (__VdfgRegularize_h6e95ff9d_0_4 & (- (IData)(
                                                         (1U 
                                                          & (~ 
                                                             ((IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3) 
                                                              >> 1U))))))
          : ((2U & (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))
              ? (vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data 
                 & (- (IData)((1U & (~ (IData)(vlSelfRef.cpu__DOT__reader_inst__DOT__f3))))))
              : __VdfgRegularize_h6e95ff9d_0_4));
    vlSelfRef.cpu__DOT__regfile__DOT__write_enable 
        = ((IData)(vlSelfRef.cpu__DOT__wb_valid) & (IData)(vlSelfRef.cpu__DOT__reg_write));
    vlSelfRef.cpu__DOT__mem_read_write_back_data = vlSelfRef.cpu__DOT__reader_inst__DOT__wb_data;
    vlSelfRef.cpu__DOT__write_back_data = ((2U & (IData)(vlSelfRef.cpu__DOT__write_back_source))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__write_back_source))
                                                ? vlSelfRef.cpu__DOT__pc_plus_second_add
                                                : vlSelfRef.cpu__DOT__pc_plus_four)
                                            : ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__write_back_source))
                                                ? vlSelfRef.cpu__DOT__mem_read_write_back_data
                                                : vlSelfRef.cpu__DOT__alu_result));
    vlSelfRef.cpu__DOT__regfile__DOT__write_data = vlSelfRef.cpu__DOT__write_back_data;
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
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

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge cpu.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge cpu.regfile.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge cpu.regfile.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge cpu.data_memory.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->cpu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5456728620559131056ull);
    vlSelf->cpu__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12949139165289987104ull);
    vlSelf->cpu__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12979896101630030509ull);
    vlSelf->cpu__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11401018961025754907ull);
    vlSelf->cpu__DOT__pc_plus_four = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16966422207647766465ull);
    vlSelf->cpu__DOT__pc_plus_second_add = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13709064303390329826ull);
    vlSelf->cpu__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3676520396987702001ull);
    vlSelf->cpu__DOT__op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 12508572871176283413ull);
    vlSelf->cpu__DOT__f3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 596015922531462669ull);
    vlSelf->cpu__DOT__f7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 453699903925344475ull);
    vlSelf->cpu__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17161198845646111129ull);
    vlSelf->cpu__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 400036621919628728ull);
    vlSelf->cpu__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2478348765490579174ull);
    vlSelf->cpu__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4586295343091075808ull);
    vlSelf->cpu__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4199765347900879115ull);
    vlSelf->cpu__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15999734060210743814ull);
    vlSelf->cpu__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6534914121567284302ull);
    vlSelf->cpu__DOT__write_back_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11069135130404140919ull);
    vlSelf->cpu__DOT__pc_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16370498713040622867ull);
    vlSelf->cpu__DOT__second_add_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5189930819573064260ull);
    vlSelf->cpu__DOT__raw_imm = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 17663876785484434241ull);
    vlSelf->cpu__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7657775539254847072ull);
    vlSelf->cpu__DOT__source_reg1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14035701915223311449ull);
    vlSelf->cpu__DOT__source_reg2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4380140507199591624ull);
    vlSelf->cpu__DOT__dest_reg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17360345143593915006ull);
    vlSelf->cpu__DOT__read_reg1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1524000216712112607ull);
    vlSelf->cpu__DOT__read_reg2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12531379444480071751ull);
    vlSelf->cpu__DOT__write_back_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7679111009518496669ull);
    vlSelf->cpu__DOT__wb_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2342307097518024898ull);
    vlSelf->cpu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12522730548817195188ull);
    vlSelf->cpu__DOT__alu_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8284561064640361552ull);
    vlSelf->cpu__DOT__mem_byte_enable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7700989728588882453ull);
    vlSelf->cpu__DOT__mem_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13377718031851555467ull);
    vlSelf->cpu__DOT__mem_read = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7262268092522396926ull);
    vlSelf->cpu__DOT__mem_read_write_back_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13861952446377723548ull);
    vlSelf->cpu__DOT__mem_read_write_back_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8948937580639569682ull);
    vlSelf->cpu__DOT__instruction_memory__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14625368131609872853ull);
    vlSelf->cpu__DOT__instruction_memory__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13860628555311754532ull);
    vlSelf->cpu__DOT__instruction_memory__DOT__write_data = 0U;
    ;
    vlSelf->cpu__DOT__instruction_memory__DOT__byte_enable = 0U;
    ;
    vlSelf->cpu__DOT__instruction_memory__DOT__write_enable = 0U;
    ;
    vlSelf->cpu__DOT__instruction_memory__DOT__rst_n = 1U;
    ;
    vlSelf->cpu__DOT__instruction_memory__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5435733009246666832ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->cpu__DOT__instruction_memory__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7404162715100081064ull);
    }
    vlSelf->cpu__DOT__instruction_memory__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->cpu__DOT__instruction_memory__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu__DOT__control_unit__DOT__op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3611403323189279122ull);
    vlSelf->cpu__DOT__control_unit__DOT__func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3110094534871067700ull);
    vlSelf->cpu__DOT__control_unit__DOT__func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 17253829472483387209ull);
    vlSelf->cpu__DOT__control_unit__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1791935297008950456ull);
    vlSelf->cpu__DOT__control_unit__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13269146157175486782ull);
    vlSelf->cpu__DOT__control_unit__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17425714914367488737ull);
    vlSelf->cpu__DOT__control_unit__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6485016073868578189ull);
    vlSelf->cpu__DOT__control_unit__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8294752314298161282ull);
    vlSelf->cpu__DOT__control_unit__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13869306721224570585ull);
    vlSelf->cpu__DOT__control_unit__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13788007134988577272ull);
    vlSelf->cpu__DOT__control_unit__DOT__write_back_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 490859545281816256ull);
    vlSelf->cpu__DOT__control_unit__DOT__pc_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2512942167037623742ull);
    vlSelf->cpu__DOT__control_unit__DOT__second_add_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6678713981853037848ull);
    vlSelf->cpu__DOT__control_unit__DOT__alu_op = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8179692090656847853ull);
    vlSelf->cpu__DOT__control_unit__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2709023761027822046ull);
    vlSelf->cpu__DOT__control_unit__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11309178397259977647ull);
    vlSelf->cpu__DOT__control_unit__DOT__assert_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5253589969340897323ull);
    vlSelf->cpu__DOT__sign_extender__DOT__raw_src = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 3508015887788509646ull);
    vlSelf->cpu__DOT__sign_extender__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3458098460170252871ull);
    vlSelf->cpu__DOT__sign_extender__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8774878167709989639ull);
    vlSelf->cpu__DOT__regfile__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6418748850776135729ull);
    vlSelf->cpu__DOT__regfile__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15713003529679336938ull);
    vlSelf->cpu__DOT__regfile__DOT__address1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14750483544627185196ull);
    vlSelf->cpu__DOT__regfile__DOT__address2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8597712201974368323ull);
    vlSelf->cpu__DOT__regfile__DOT__read_data1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10013646264735073798ull);
    vlSelf->cpu__DOT__regfile__DOT__read_data2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4968804507512006539ull);
    vlSelf->cpu__DOT__regfile__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9988947362695560081ull);
    vlSelf->cpu__DOT__regfile__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 544213930637243827ull);
    vlSelf->cpu__DOT__regfile__DOT__address3 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 954105450285310959ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->cpu__DOT__regfile__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15800446414295255430ull);
    }
    vlSelf->cpu__DOT__regfile__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu__DOT__alu_inst__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11209935511910668533ull);
    vlSelf->cpu__DOT__alu_inst__DOT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1464569046335488162ull);
    vlSelf->cpu__DOT__alu_inst__DOT__src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9682957663792374465ull);
    vlSelf->cpu__DOT__alu_inst__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3987035607850862406ull);
    vlSelf->cpu__DOT__alu_inst__DOT__zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14474213535884226629ull);
    vlSelf->cpu__DOT__alu_inst__DOT__last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15397634673879318311ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shamt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10928791468607102851ull);
    vlSelf->cpu__DOT__ls_decode__DOT__alu_result_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16178732286973489047ull);
    vlSelf->cpu__DOT__ls_decode__DOT__f3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4712554890967665217ull);
    vlSelf->cpu__DOT__ls_decode__DOT__reg_read = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14638220028635046621ull);
    vlSelf->cpu__DOT__ls_decode__DOT__byte_enable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11304666189925894772ull);
    vlSelf->cpu__DOT__ls_decode__DOT__data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15073718270080290381ull);
    vlSelf->cpu__DOT__ls_decode__DOT__offset = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16574626924315778573ull);
    vlSelf->cpu__DOT__data_memory__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11098813462957875079ull);
    vlSelf->cpu__DOT__data_memory__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2410208994358422173ull);
    vlSelf->cpu__DOT__data_memory__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2701052512181033886ull);
    vlSelf->cpu__DOT__data_memory__DOT__byte_enable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6968471113932893181ull);
    vlSelf->cpu__DOT__data_memory__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1215334658594043730ull);
    vlSelf->cpu__DOT__data_memory__DOT__rst_n = 1U;
    ;
    vlSelf->cpu__DOT__data_memory__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13538062894372254119ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->cpu__DOT__data_memory__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16394125434072290796ull);
    }
    vlSelf->cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->cpu__DOT__data_memory__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu__DOT__reader_inst__DOT__mem_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13043582410846504223ull);
    vlSelf->cpu__DOT__reader_inst__DOT__be_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12779663429312853140ull);
    vlSelf->cpu__DOT__reader_inst__DOT__f3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3405399924661784971ull);
    vlSelf->cpu__DOT__reader_inst__DOT__wb_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13719103381469885477ull);
    vlSelf->cpu__DOT__reader_inst__DOT__valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5683063334973354771ull);
    vlSelf->cpu__DOT__reader_inst__DOT__sign_extend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8388596068475032640ull);
    vlSelf->cpu__DOT__reader_inst__DOT__masked_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1939041957767647495ull);
    vlSelf->cpu__DOT__reader_inst__DOT__raw_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18300403238918821615ull);
    vlSelf->cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__data_memory__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
