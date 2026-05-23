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
    vlSelfRef.cpu__DOT__regfile__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__data_memory__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__instruction_memory__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
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

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.cpu__DOT__data_memory__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__data_memory__DOT__clk__0))) 
                                                       << 3U) 
                                                      | (((~ (IData)(vlSelfRef.cpu__DOT__regfile__DOT__rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__rst_n__0)) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.cpu__DOT__regfile__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__clk__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.cpu__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__clk__0 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__clk__0 
        = vlSelfRef.cpu__DOT__regfile__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__rst_n__0 
        = vlSelfRef.cpu__DOT__regfile__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__data_memory__DOT__clk__0 
        = vlSelfRef.cpu__DOT__data_memory__DOT__clk;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__cpu__DOT__data_memory__DOT__mem__v0;
    __VdlyVal__cpu__DOT__data_memory__DOT__mem__v0 = 0;
    CData/*4:0*/ __VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0;
    __VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0 = 0;
    CData/*6:0*/ __VdlyDim0__cpu__DOT__data_memory__DOT__mem__v0;
    __VdlyDim0__cpu__DOT__data_memory__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyMask__cpu__DOT__data_memory__DOT__mem__v0;
    __VdlyMask__cpu__DOT__data_memory__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyElem__cpu__DOT__data_memory__DOT__mem__v0;
    __VdlyElem__cpu__DOT__data_memory__DOT__mem__v0 = 0;
    // Body
    if (vlSelfRef.cpu__DOT__data_memory__DOT__write_enable) {
        if (VL_UNLIKELY(((0U != (3U & vlSelfRef.cpu__DOT__data_memory__DOT__address))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: memory.sv:39: Assertion failed in %m: %d\n",4, 'M',vlSymsp->name(),"cpu.data_memory", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.cpu__DOT__data_memory__DOT__address);
            VL_STOP_MT("/home/soumyadip/riscv-cpu/tb/cpu/../../src/memory.sv", 39, "", false);
        } else {
            vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i = 0U;
            while (VL_GTS_III(32, 4U, vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i)) {
                if ((1U & ((IData)(vlSelfRef.cpu__DOT__data_memory__DOT__byte_enable) 
                           >> (3U & vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i)))) {
                    __VdlyVal__cpu__DOT__data_memory__DOT__mem__v0 
                        = (0x000000ffU & (vlSelfRef.cpu__DOT__data_memory__DOT__write_data 
                                          >> (0x0000001fU 
                                              & VL_MULS_III(32, (IData)(8U), vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i))));
                    __VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0 
                        = (0x0000001fU & VL_MULS_III(32, (IData)(8U), vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i));
                    __VdlyDim0__cpu__DOT__data_memory__DOT__mem__v0 
                        = (0x0000007fU & (vlSelfRef.cpu__DOT__data_memory__DOT__address 
                                          >> 2U));
                    __VdlyMask__cpu__DOT__data_memory__DOT__mem__v0 = 0U;
                    __VdlyMask__cpu__DOT__data_memory__DOT__mem__v0 
                        = (__VdlyMask__cpu__DOT__data_memory__DOT__mem__v0 
                           | (0x00000000ffffffffULL 
                              & ((IData)(0xffU) << (IData)(__VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0))));
                    __VdlyElem__cpu__DOT__data_memory__DOT__mem__v0 = 0U;
                    __VdlyElem__cpu__DOT__data_memory__DOT__mem__v0 
                        = (((~ ((IData)(0x000000ffU) 
                                << (IData)(__VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0))) 
                            & __VdlyElem__cpu__DOT__data_memory__DOT__mem__v0) 
                           | (0x00000000ffffffffULL 
                              & ((IData)(__VdlyVal__cpu__DOT__data_memory__DOT__mem__v0) 
                                 << (IData)(__VdlyLsb__cpu__DOT__data_memory__DOT__mem__v0))));
                    vlSelfRef.__VdlyCommitQueuecpu__DOT__data_memory__DOT__mem.enqueue(__VdlyElem__cpu__DOT__data_memory__DOT__mem__v0, __VdlyMask__cpu__DOT__data_memory__DOT__mem__v0, (IData)(__VdlyDim0__cpu__DOT__data_memory__DOT__mem__v0));
                }
                vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i 
                    = ((IData)(1U) + vlSelfRef.cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i);
            }
        }
    }
    vlSelfRef.__VdlyCommitQueuecpu__DOT__data_memory__DOT__mem.commit(vlSelfRef.cpu__DOT__data_memory__DOT__mem);
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__cpu__DOT__regfile__DOT__registers__v0;
    __VdlyVal__cpu__DOT__regfile__DOT__registers__v0 = 0;
    CData/*4:0*/ __VdlyDim0__cpu__DOT__regfile__DOT__registers__v0;
    __VdlyDim0__cpu__DOT__regfile__DOT__registers__v0 = 0;
    CData/*4:0*/ __VdlyDim0__cpu__DOT__regfile__DOT__registers__v1;
    __VdlyDim0__cpu__DOT__regfile__DOT__registers__v1 = 0;
    // Body
    if (vlSelfRef.cpu__DOT__regfile__DOT__rst_n) {
        if (((IData)(vlSelfRef.cpu__DOT__regfile__DOT__write_enable) 
             & (0U != (IData)(vlSelfRef.cpu__DOT__regfile__DOT__address3)))) {
            __VdlyVal__cpu__DOT__regfile__DOT__registers__v0 
                = vlSelfRef.cpu__DOT__regfile__DOT__write_data;
            __VdlyDim0__cpu__DOT__regfile__DOT__registers__v0 
                = vlSelfRef.cpu__DOT__regfile__DOT__address3;
            vlSelfRef.__VdlyCommitQueuecpu__DOT__regfile__DOT__registers.enqueue(__VdlyVal__cpu__DOT__regfile__DOT__registers__v0, (IData)(__VdlyDim0__cpu__DOT__regfile__DOT__registers__v0));
        }
    } else {
        vlSelfRef.cpu__DOT__regfile__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00000020U, vlSelfRef.cpu__DOT__regfile__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__cpu__DOT__regfile__DOT__registers__v1 
                = (0x0000001fU & vlSelfRef.cpu__DOT__regfile__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__regfile__DOT__registers.enqueue(0U, (IData)(__VdlyDim0__cpu__DOT__regfile__DOT__registers__v1));
            vlSelfRef.cpu__DOT__regfile__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.cpu__DOT__regfile__DOT__unnamedblk1__DOT__i);
        }
    }
    vlSelfRef.__VdlyCommitQueuecpu__DOT__regfile__DOT__registers.commit(vlSelfRef.cpu__DOT__regfile__DOT__registers);
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__pc = ((IData)(vlSelfRef.cpu__DOT__rst_n)
                               ? vlSelfRef.cpu__DOT__pc_next
                               : 0U);
    vlSelfRef.cpu__DOT__pc_plus_four = ((IData)(4U) 
                                        + vlSelfRef.cpu__DOT__pc);
    vlSelfRef.cpu__DOT__instruction_memory__DOT__address 
        = vlSelfRef.cpu__DOT__pc;
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
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.cpu__DOT__regfile__DOT__read_data1 = vlSelfRef.cpu__DOT__regfile__DOT__registers
        [vlSelfRef.cpu__DOT__regfile__DOT__address1];
    vlSelfRef.cpu__DOT__regfile__DOT__read_data2 = vlSelfRef.cpu__DOT__regfile__DOT__registers
        [vlSelfRef.cpu__DOT__regfile__DOT__address2];
    vlSelfRef.cpu__DOT__read_reg1 = vlSelfRef.cpu__DOT__regfile__DOT__read_data1;
    vlSelfRef.cpu__DOT__read_reg2 = vlSelfRef.cpu__DOT__regfile__DOT__read_data2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__src1 = vlSelfRef.cpu__DOT__read_reg1;
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
    vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read = vlSelfRef.cpu__DOT__read_reg2;
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
    vlSelfRef.cpu__DOT__ls_decode__DOT__offset = (3U 
                                                  & vlSelfRef.cpu__DOT__ls_decode__DOT__alu_result_address);
    __Vtableidx1 = (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_zero) 
                     << 5U) | (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__branch) 
                                << 4U) | (((IData)(vlSelfRef.cpu__DOT__control_unit__DOT__alu_last_bit) 
                                           << 3U) | (IData)(vlSelfRef.cpu__DOT__control_unit__DOT__func3))));
    vlSelfRef.cpu__DOT__control_unit__DOT__assert_branch 
        = Vtop__ConstPool__TABLE_hba1b7ba9_0[__Vtableidx1];
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
    vlSelfRef.cpu__DOT__mem_read_write_back_valid = vlSelfRef.cpu__DOT__reader_inst__DOT__valid;
    vlSelfRef.cpu__DOT__wb_valid = ((1U & ((IData)(vlSelfRef.cpu__DOT__write_back_source) 
                                           >> 1U)) 
                                    || ((1U & (~ (IData)(vlSelfRef.cpu__DOT__write_back_source))) 
                                        || (IData)(vlSelfRef.cpu__DOT__mem_read_write_back_valid)));
    vlSelfRef.cpu__DOT__regfile__DOT__write_enable 
        = ((IData)(vlSelfRef.cpu__DOT__wb_valid) & (IData)(vlSelfRef.cpu__DOT__reg_write));
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    // Body
    vlSelfRef.cpu__DOT__data_memory__DOT__read_data 
        = vlSelfRef.cpu__DOT__data_memory__DOT__mem
        [(0x0000007fU & (vlSelfRef.cpu__DOT__data_memory__DOT__address 
                         >> 2U))];
    vlSelfRef.cpu__DOT__mem_read = vlSelfRef.cpu__DOT__data_memory__DOT__read_data;
    vlSelfRef.cpu__DOT__reader_inst__DOT__mem_data 
        = vlSelfRef.cpu__DOT__mem_read;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/cpu/../../src/cpu.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/cpu/../../src/cpu.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/soumyadip/riscv-cpu/tb/cpu/../../src/cpu.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
}
#endif  // VL_DEBUG
