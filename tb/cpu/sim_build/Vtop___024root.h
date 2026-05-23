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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        CData/*0:0*/ cpu__DOT__clk;
        CData/*0:0*/ cpu__DOT__rst_n;
        CData/*6:0*/ cpu__DOT__op;
        CData/*2:0*/ cpu__DOT__f3;
        CData/*6:0*/ cpu__DOT__f7;
        CData/*0:0*/ cpu__DOT__alu_zero;
        CData/*0:0*/ cpu__DOT__alu_last_bit;
        CData/*3:0*/ cpu__DOT__alu_control;
        CData/*2:0*/ cpu__DOT__imm_source;
        CData/*0:0*/ cpu__DOT__mem_write;
        CData/*0:0*/ cpu__DOT__reg_write;
        CData/*0:0*/ cpu__DOT__alu_source;
        CData/*1:0*/ cpu__DOT__write_back_source;
        CData/*0:0*/ cpu__DOT__pc_source;
        CData/*1:0*/ cpu__DOT__second_add_source;
        CData/*4:0*/ cpu__DOT__source_reg1;
        CData/*4:0*/ cpu__DOT__source_reg2;
        CData/*4:0*/ cpu__DOT__dest_reg;
        CData/*0:0*/ cpu__DOT__wb_valid;
        CData/*3:0*/ cpu__DOT__mem_byte_enable;
        CData/*0:0*/ cpu__DOT__mem_read_write_back_valid;
        CData/*0:0*/ cpu__DOT__instruction_memory__DOT__clk;
        CData/*3:0*/ cpu__DOT__instruction_memory__DOT__byte_enable;
        CData/*0:0*/ cpu__DOT__instruction_memory__DOT__write_enable;
        CData/*0:0*/ cpu__DOT__instruction_memory__DOT__rst_n;
        CData/*6:0*/ cpu__DOT__control_unit__DOT__op;
        CData/*2:0*/ cpu__DOT__control_unit__DOT__func3;
        CData/*6:0*/ cpu__DOT__control_unit__DOT__func7;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__alu_zero;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__alu_last_bit;
        CData/*3:0*/ cpu__DOT__control_unit__DOT__alu_control;
        CData/*2:0*/ cpu__DOT__control_unit__DOT__imm_source;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__mem_write;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__reg_write;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__alu_source;
        CData/*1:0*/ cpu__DOT__control_unit__DOT__write_back_source;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__pc_source;
        CData/*1:0*/ cpu__DOT__control_unit__DOT__second_add_source;
        CData/*1:0*/ cpu__DOT__control_unit__DOT__alu_op;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__branch;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__jump;
        CData/*0:0*/ cpu__DOT__control_unit__DOT__assert_branch;
        CData/*2:0*/ cpu__DOT__sign_extender__DOT__imm_source;
        CData/*0:0*/ cpu__DOT__regfile__DOT__clk;
        CData/*0:0*/ cpu__DOT__regfile__DOT__rst_n;
        CData/*4:0*/ cpu__DOT__regfile__DOT__address1;
        CData/*4:0*/ cpu__DOT__regfile__DOT__address2;
        CData/*0:0*/ cpu__DOT__regfile__DOT__write_enable;
        CData/*4:0*/ cpu__DOT__regfile__DOT__address3;
        CData/*3:0*/ cpu__DOT__alu_inst__DOT__alu_control;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__zero;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__last_bit;
        CData/*4:0*/ cpu__DOT__alu_inst__DOT__shamt;
        CData/*2:0*/ cpu__DOT__ls_decode__DOT__f3;
        CData/*3:0*/ cpu__DOT__ls_decode__DOT__byte_enable;
        CData/*1:0*/ cpu__DOT__ls_decode__DOT__offset;
        CData/*0:0*/ cpu__DOT__data_memory__DOT__clk;
        CData/*3:0*/ cpu__DOT__data_memory__DOT__byte_enable;
        CData/*0:0*/ cpu__DOT__data_memory__DOT__write_enable;
        CData/*0:0*/ cpu__DOT__data_memory__DOT__rst_n;
        CData/*3:0*/ cpu__DOT__reader_inst__DOT__be_mask;
        CData/*2:0*/ cpu__DOT__reader_inst__DOT__f3;
    };
    struct {
        CData/*0:0*/ cpu__DOT__reader_inst__DOT__valid;
        CData/*0:0*/ cpu__DOT__reader_inst__DOT__sign_extend;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__regfile__DOT__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__data_memory__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        IData/*31:0*/ cpu__DOT__pc;
        IData/*31:0*/ cpu__DOT__pc_next;
        IData/*31:0*/ cpu__DOT__pc_plus_four;
        IData/*31:0*/ cpu__DOT__pc_plus_second_add;
        IData/*31:0*/ cpu__DOT__instruction;
        IData/*24:0*/ cpu__DOT__raw_imm;
        IData/*31:0*/ cpu__DOT__immediate;
        IData/*31:0*/ cpu__DOT__read_reg1;
        IData/*31:0*/ cpu__DOT__read_reg2;
        IData/*31:0*/ cpu__DOT__write_back_data;
        IData/*31:0*/ cpu__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__alu_src2;
        IData/*31:0*/ cpu__DOT__mem_write_data;
        IData/*31:0*/ cpu__DOT__mem_read;
        IData/*31:0*/ cpu__DOT__mem_read_write_back_data;
        IData/*31:0*/ cpu__DOT__instruction_memory__DOT__address;
        IData/*31:0*/ cpu__DOT__instruction_memory__DOT__write_data;
        IData/*31:0*/ cpu__DOT__instruction_memory__DOT__read_data;
        IData/*31:0*/ cpu__DOT__instruction_memory__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ cpu__DOT__instruction_memory__DOT__unnamedblk1__DOT__i;
        IData/*24:0*/ cpu__DOT__sign_extender__DOT__raw_src;
        IData/*31:0*/ cpu__DOT__sign_extender__DOT__immediate;
        IData/*31:0*/ cpu__DOT__regfile__DOT__read_data1;
        IData/*31:0*/ cpu__DOT__regfile__DOT__read_data2;
        IData/*31:0*/ cpu__DOT__regfile__DOT__write_data;
        IData/*31:0*/ cpu__DOT__regfile__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__src1;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__src2;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__ls_decode__DOT__alu_result_address;
        IData/*31:0*/ cpu__DOT__ls_decode__DOT__reg_read;
        IData/*31:0*/ cpu__DOT__ls_decode__DOT__data;
        IData/*31:0*/ cpu__DOT__data_memory__DOT__address;
        IData/*31:0*/ cpu__DOT__data_memory__DOT__write_data;
        IData/*31:0*/ cpu__DOT__data_memory__DOT__read_data;
        IData/*31:0*/ cpu__DOT__data_memory__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ cpu__DOT__data_memory__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ cpu__DOT__reader_inst__DOT__mem_data;
        IData/*31:0*/ cpu__DOT__reader_inst__DOT__wb_data;
        IData/*31:0*/ cpu__DOT__reader_inst__DOT__masked_data;
        IData/*31:0*/ cpu__DOT__reader_inst__DOT__raw_data;
        IData/*31:0*/ cpu__DOT__reader_inst__DOT__mask_apply__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 128> cpu__DOT__instruction_memory__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> cpu__DOT__regfile__DOT__registers;
        VlUnpacked<IData/*31:0*/, 128> cpu__DOT__data_memory__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 32>, false, IData/*31:0*/, 1> __VdlyCommitQueuecpu__DOT__regfile__DOT__registers;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 128>, true, IData/*31:0*/, 1> __VdlyCommitQueuecpu__DOT__data_memory__DOT__mem;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ cpu__DOT__instruction_memory__DOT__WORDS = 0x00000080U;
    static constexpr VlWide<5>/*143:0*/ cpu__DOT__instruction_memory__DOT__mem_init = VlWide<5>{{
            0x2e686578, 0x6d6f7279, 0x5f696d65, 0x74657374,
            0x00002e2f
    }};
    static constexpr IData/*31:0*/ cpu__DOT__data_memory__DOT__WORDS = 0x00000080U;
    static constexpr VlWide<5>/*143:0*/ cpu__DOT__data_memory__DOT__mem_init = VlWide<5>{{
            0x2e686578, 0x6d6f7279, 0x5f646d65, 0x74657374,
            0x00002e2f
    }};

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
