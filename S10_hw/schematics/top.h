#pragma once
#include "mgc_vista_schematics.h"
$includes_begin;
#include <systemc.h>
#include "../../fpga_hw/schematics/FPGA_fabric.h"
#include "../../../platforms/stratix10/src/Arria_schematics/Stratix10_top.h"
$includes_end;

$module_begin("top");
SC_MODULE(top) {
public:
  typedef top SC_CURRENT_USER_MODULE;
  top(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("fpga_inst"),
fpga_inst(0)
$end
$init("stratix10_inst"),
stratix10_inst(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("fpga_inst");
fpga_inst = new FPGA_fabric("fpga_inst");
$end;
$create_component("stratix10_inst");
stratix10_inst = new Stratix10_top("stratix10_inst");
$end;
$bind("fpga_inst->jpeg_irq","stratix10_inst->irq_20");
vista_bind(fpga_inst->jpeg_irq, stratix10_inst->irq_20);
$end;
$bind("fpga_inst->ip_irq","stratix10_inst->irq_21");
vista_bind(fpga_inst->ip_irq, stratix10_inst->irq_21);
$end;
$bind("fpga_inst->ic_irq","stratix10_inst->irq_19");
vista_bind(fpga_inst->ic_irq, stratix10_inst->irq_19);
$end;
$bind("stratix10_inst->HPS2FPGA_Master","fpga_inst->FPGAslave");
vista_bind(stratix10_inst->HPS2FPGA_Master, fpga_inst->FPGAslave);
$end;
$bind("fpga_inst->FPGAmaster","stratix10_inst->FPGA2HPS_Slave");
vista_bind(fpga_inst->FPGAmaster, stratix10_inst->FPGA2HPS_Slave);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "schematics";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~top() {
    $destructor_begin;
$destruct_component("fpga_inst");
delete fpga_inst; fpga_inst = 0;
$end;
$destruct_component("stratix10_inst");
delete stratix10_inst; stratix10_inst = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$component("fpga_inst");
FPGA_fabric *fpga_inst;
$end;
$component("stratix10_inst");
Stratix10_top *stratix10_inst;
$end;
  $fields_end;
  $vlnv_decl_begin;
public:
const char* m_library;
const char* m_vendor;
const char* m_version;
  $vlnv_decl_end;
};
$module_end;