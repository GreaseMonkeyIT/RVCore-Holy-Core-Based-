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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.cpu__DOT__clk));
    bufp->chgBit(oldp+3,(vlSelfRef.cpu__DOT__rst_n));
    bufp->chgIData(oldp+4,(vlSelfRef.cpu__DOT__pc),32);
    bufp->chgIData(oldp+5,(vlSelfRef.cpu__DOT__pc_next),32);
    bufp->chgIData(oldp+6,(vlSelfRef.cpu__DOT__pc_plus_four),32);
    bufp->chgIData(oldp+7,(vlSelfRef.cpu__DOT__pc_plus_second_add),32);
    bufp->chgIData(oldp+8,(vlSelfRef.cpu__DOT__instruction),32);
    bufp->chgCData(oldp+9,(vlSelfRef.cpu__DOT__op),7);
    bufp->chgCData(oldp+10,(vlSelfRef.cpu__DOT__f3),3);
    bufp->chgCData(oldp+11,(vlSelfRef.cpu__DOT__f7),7);
    bufp->chgBit(oldp+12,(vlSelfRef.cpu__DOT__alu_zero));
    bufp->chgBit(oldp+13,(vlSelfRef.cpu__DOT__alu_last_bit));
    bufp->chgCData(oldp+14,(vlSelfRef.cpu__DOT__alu_control),4);
    bufp->chgCData(oldp+15,(vlSelfRef.cpu__DOT__imm_source),3);
    bufp->chgBit(oldp+16,(vlSelfRef.cpu__DOT__mem_write));
    bufp->chgBit(oldp+17,(vlSelfRef.cpu__DOT__reg_write));
    bufp->chgBit(oldp+18,(vlSelfRef.cpu__DOT__alu_source));
    bufp->chgCData(oldp+19,(vlSelfRef.cpu__DOT__write_back_source),2);
    bufp->chgBit(oldp+20,(vlSelfRef.cpu__DOT__pc_source));
    bufp->chgCData(oldp+21,(vlSelfRef.cpu__DOT__second_add_source),2);
    bufp->chgIData(oldp+22,(vlSelfRef.cpu__DOT__raw_imm),25);
    bufp->chgIData(oldp+23,(vlSelfRef.cpu__DOT__immediate),32);
    bufp->chgCData(oldp+24,(vlSelfRef.cpu__DOT__source_reg1),5);
    bufp->chgCData(oldp+25,(vlSelfRef.cpu__DOT__source_reg2),5);
    bufp->chgCData(oldp+26,(vlSelfRef.cpu__DOT__dest_reg),5);
    bufp->chgIData(oldp+27,(vlSelfRef.cpu__DOT__read_reg1),32);
    bufp->chgIData(oldp+28,(vlSelfRef.cpu__DOT__read_reg2),32);
    bufp->chgIData(oldp+29,(vlSelfRef.cpu__DOT__write_back_data),32);
    bufp->chgBit(oldp+30,(vlSelfRef.cpu__DOT__wb_valid));
    bufp->chgIData(oldp+31,(vlSelfRef.cpu__DOT__alu_result),32);
    bufp->chgIData(oldp+32,(vlSelfRef.cpu__DOT__alu_src2),32);
    bufp->chgCData(oldp+33,(vlSelfRef.cpu__DOT__mem_byte_enable),4);
    bufp->chgIData(oldp+34,(vlSelfRef.cpu__DOT__mem_write_data),32);
    bufp->chgIData(oldp+35,(vlSelfRef.cpu__DOT__mem_read),32);
    bufp->chgIData(oldp+36,(vlSelfRef.cpu__DOT__mem_read_write_back_data),32);
    bufp->chgBit(oldp+37,(vlSelfRef.cpu__DOT__mem_read_write_back_valid));
    bufp->chgCData(oldp+38,(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_control),4);
    bufp->chgIData(oldp+39,(vlSelfRef.cpu__DOT__alu_inst__DOT__src1),32);
    bufp->chgIData(oldp+40,(vlSelfRef.cpu__DOT__alu_inst__DOT__src2),32);
    bufp->chgIData(oldp+41,(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_result),32);
    bufp->chgBit(oldp+42,(vlSelfRef.cpu__DOT__alu_inst__DOT__zero));
    bufp->chgBit(oldp+43,(vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit));
    bufp->chgCData(oldp+44,(vlSelfRef.cpu__DOT__alu_inst__DOT__shamt),5);
    bufp->chgCData(oldp+45,(vlSelfRef.cpu__DOT__control_unit__DOT__op),7);
    bufp->chgCData(oldp+46,(vlSelfRef.cpu__DOT__control_unit__DOT__func3),3);
    bufp->chgCData(oldp+47,(vlSelfRef.cpu__DOT__control_unit__DOT__func7),7);
    bufp->chgBit(oldp+48,(vlSelfRef.cpu__DOT__control_unit__DOT__alu_zero));
    bufp->chgBit(oldp+49,(vlSelfRef.cpu__DOT__control_unit__DOT__alu_last_bit));
    bufp->chgCData(oldp+50,(vlSelfRef.cpu__DOT__control_unit__DOT__alu_control),4);
    bufp->chgCData(oldp+51,(vlSelfRef.cpu__DOT__control_unit__DOT__imm_source),3);
    bufp->chgBit(oldp+52,(vlSelfRef.cpu__DOT__control_unit__DOT__mem_write));
    bufp->chgBit(oldp+53,(vlSelfRef.cpu__DOT__control_unit__DOT__reg_write));
    bufp->chgBit(oldp+54,(vlSelfRef.cpu__DOT__control_unit__DOT__alu_source));
    bufp->chgCData(oldp+55,(vlSelfRef.cpu__DOT__control_unit__DOT__write_back_source),2);
    bufp->chgBit(oldp+56,(vlSelfRef.cpu__DOT__control_unit__DOT__pc_source));
    bufp->chgCData(oldp+57,(vlSelfRef.cpu__DOT__control_unit__DOT__second_add_source),2);
    bufp->chgCData(oldp+58,(vlSelfRef.cpu__DOT__control_unit__DOT__alu_op),2);
    bufp->chgBit(oldp+59,(vlSelfRef.cpu__DOT__control_unit__DOT__branch));
    bufp->chgBit(oldp+60,(vlSelfRef.cpu__DOT__control_unit__DOT__jump));
    bufp->chgBit(oldp+61,(vlSelfRef.cpu__DOT__control_unit__DOT__assert_branch));
    bufp->chgBit(oldp+62,(vlSelfRef.cpu__DOT__data_memory__DOT__clk));
    bufp->chgIData(oldp+63,(vlSelfRef.cpu__DOT__data_memory__DOT__address),32);
    bufp->chgIData(oldp+64,(vlSelfRef.cpu__DOT__data_memory__DOT__write_data),32);
    bufp->chgCData(oldp+65,(vlSelfRef.cpu__DOT__data_memory__DOT__byte_enable),4);
    bufp->chgBit(oldp+66,(vlSelfRef.cpu__DOT__data_memory__DOT__write_enable));
    bufp->chgIData(oldp+67,(vlSelfRef.cpu__DOT__data_memory__DOT__read_data),32);
    bufp->chgBit(oldp+68,(vlSelfRef.cpu__DOT__instruction_memory__DOT__clk));
    bufp->chgIData(oldp+69,(vlSelfRef.cpu__DOT__instruction_memory__DOT__address),32);
    bufp->chgIData(oldp+70,(vlSelfRef.cpu__DOT__instruction_memory__DOT__read_data),32);
    bufp->chgIData(oldp+71,(vlSelfRef.cpu__DOT__ls_decode__DOT__alu_result_address),32);
    bufp->chgCData(oldp+72,(vlSelfRef.cpu__DOT__ls_decode__DOT__f3),3);
    bufp->chgIData(oldp+73,(vlSelfRef.cpu__DOT__ls_decode__DOT__reg_read),32);
    bufp->chgCData(oldp+74,(vlSelfRef.cpu__DOT__ls_decode__DOT__byte_enable),4);
    bufp->chgIData(oldp+75,(vlSelfRef.cpu__DOT__ls_decode__DOT__data),32);
    bufp->chgCData(oldp+76,(vlSelfRef.cpu__DOT__ls_decode__DOT__offset),2);
    bufp->chgIData(oldp+77,(vlSelfRef.cpu__DOT__reader_inst__DOT__mem_data),32);
    bufp->chgCData(oldp+78,(vlSelfRef.cpu__DOT__reader_inst__DOT__be_mask),4);
    bufp->chgCData(oldp+79,(vlSelfRef.cpu__DOT__reader_inst__DOT__f3),3);
    bufp->chgIData(oldp+80,(vlSelfRef.cpu__DOT__reader_inst__DOT__wb_data),32);
    bufp->chgBit(oldp+81,(vlSelfRef.cpu__DOT__reader_inst__DOT__valid));
    bufp->chgBit(oldp+82,(vlSelfRef.cpu__DOT__reader_inst__DOT__sign_extend));
    bufp->chgIData(oldp+83,(vlSelfRef.cpu__DOT__reader_inst__DOT__masked_data),32);
    bufp->chgIData(oldp+84,(vlSelfRef.cpu__DOT__reader_inst__DOT__raw_data),32);
    bufp->chgBit(oldp+85,(vlSelfRef.cpu__DOT__regfile__DOT__clk));
    bufp->chgBit(oldp+86,(vlSelfRef.cpu__DOT__regfile__DOT__rst_n));
    bufp->chgCData(oldp+87,(vlSelfRef.cpu__DOT__regfile__DOT__address1),5);
    bufp->chgCData(oldp+88,(vlSelfRef.cpu__DOT__regfile__DOT__address2),5);
    bufp->chgIData(oldp+89,(vlSelfRef.cpu__DOT__regfile__DOT__read_data1),32);
    bufp->chgIData(oldp+90,(vlSelfRef.cpu__DOT__regfile__DOT__read_data2),32);
    bufp->chgBit(oldp+91,(vlSelfRef.cpu__DOT__regfile__DOT__write_enable));
    bufp->chgIData(oldp+92,(vlSelfRef.cpu__DOT__regfile__DOT__write_data),32);
    bufp->chgCData(oldp+93,(vlSelfRef.cpu__DOT__regfile__DOT__address3),5);
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 94, vlSelfRef.cpu__DOT__regfile__DOT__registers);
    bufp->chgIData(oldp+126,(vlSelfRef.cpu__DOT__sign_extender__DOT__raw_src),25);
    bufp->chgCData(oldp+127,(vlSelfRef.cpu__DOT__sign_extender__DOT__imm_source),3);
    bufp->chgIData(oldp+128,(vlSelfRef.cpu__DOT__sign_extender__DOT__immediate),32);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
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
