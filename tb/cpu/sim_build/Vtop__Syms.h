// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_cpu;
    VerilatedScope* __Vscopep_cpu__alu_inst;
    VerilatedScope* __Vscopep_cpu__control_unit;
    VerilatedScope* __Vscopep_cpu__data_memory;
    VerilatedScope* __Vscopep_cpu__data_memory__unnamedblk1;
    VerilatedScope* __Vscopep_cpu__data_memory__unnamedblk2;
    VerilatedScope* __Vscopep_cpu__instruction_memory;
    VerilatedScope* __Vscopep_cpu__instruction_memory__unnamedblk1;
    VerilatedScope* __Vscopep_cpu__instruction_memory__unnamedblk2;
    VerilatedScope* __Vscopep_cpu__ls_decode;
    VerilatedScope* __Vscopep_cpu__reader_inst;
    VerilatedScope* __Vscopep_cpu__reader_inst__mask_apply;
    VerilatedScope* __Vscopep_cpu__reader_inst__mask_apply__unnamedblk1;
    VerilatedScope* __Vscopep_cpu__regfile;
    VerilatedScope* __Vscopep_cpu__regfile__unnamedblk1;
    VerilatedScope* __Vscopep_cpu__sign_extender;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
