#pragma once
#include "mgc_vista_schematics.h"
$includes_begin;
#include <systemc.h>
#include "../models/FPGA_AXI_BUS_model.h"
#include "../models/LinuxFrameBufferDisplay_model.h"
#include "../models/ImageCapture_model.h"
#include "../models/fpga_memory_model.h"
#include "../models/ImageProcessing_model.h"
#include "../../../jpeg/models/JPEG_ENCODER_model.h"
$includes_end;

$module_begin("FPGA_fabric");
SC_MODULE(FPGA_fabric) {
public:
  typedef FPGA_fabric SC_CURRENT_USER_MODULE;
  FPGA_fabric(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("FPGAslave"),
FPGAslave("FPGAslave")
$end
$init("FPGAmaster"),
FPGAmaster("FPGAmaster")
$end
$init("ip_irq"),
ip_irq("ip_irq")
$end
$init("ic_irq"),
ic_irq("ic_irq")
$end
$init("jpeg_irq"),
jpeg_irq("jpeg_irq")
$end
$init("fpga_axi_bus"),
fpga_axi_bus(0)
$end
$init("fb"),
fb(0)
$end
$init("ic"),
ic(0)
$end
$init("jpeg"),
jpeg(0)
$end
$init("fpgamem"),
fpgamem(0)
$end
$init("ip"),
ip(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("fpga_axi_bus");
fpga_axi_bus = new FPGA_AXI_BUS_pvt("fpga_axi_bus");
$end;
$create_component("fb");
fb = new LinuxFrameBufferDisplay_pvt("fb");
$end;
$create_component("ic");
ic = new ImageCapture_pvt("ic");
$end;
$create_component("jpeg");
jpeg = new JPEG_ENCODER_pvt("jpeg");
$end;
$create_component("fpgamem");
fpgamem = new fpga_memory_pvt("fpgamem");
$end;
$create_component("ip");
ip = new ImageProcessing_pvt("ip");
$end;
$bind("fpga_axi_bus->JPEGregisters","jpeg->slave");
vista_bind(fpga_axi_bus->JPEGregisters, jpeg->slave);
$end;
$bind("jpeg->master","fpga_axi_bus->JPEGdma");
vista_bind(jpeg->master, fpga_axi_bus->JPEGdma);
$end;
$bind("ic->master","fpga_axi_bus->ICdma");
vista_bind(ic->master, fpga_axi_bus->ICdma);
$end;
$bind("fpga_axi_bus->ICregisters","ic->slave");
vista_bind(fpga_axi_bus->ICregisters, ic->slave);
$end;
$bind("fpga_axi_bus->FPGAmem","fpgamem->slave");
vista_bind(fpga_axi_bus->FPGAmem, fpgamem->slave);
$end;
$bind("fpga_axi_bus->FrameBuffer","fb->from_bus");
vista_bind(fpga_axi_bus->FrameBuffer, fb->from_bus);
$end;
$bind("fpga_axi_bus->IPregisters","ip->slave");
vista_bind(fpga_axi_bus->IPregisters, ip->slave);
$end;
$bind("ip->master","fpga_axi_bus->IPdma");
vista_bind(ip->master, fpga_axi_bus->IPdma);
$end;
$bind("jpeg->irq","jpeg_irq");
vista_bind(jpeg->irq, jpeg_irq);
$end;
$bind("ip->irq","ip_irq");
vista_bind(ip->irq, ip_irq);
$end;
$bind("fpga_axi_bus->FPGAmaster","FPGAmaster");
vista_bind(fpga_axi_bus->FPGAmaster, FPGAmaster);
$end;
$bind("ic->irq","ic_irq");
vista_bind(ic->irq, ic_irq);
$end;
$bind("FPGAslave","fpga_axi_bus->FPGAslave");
vista_bind(FPGAslave, fpga_axi_bus->FPGAslave);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "fpga_schematics";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~FPGA_fabric() {
    $destructor_begin;
$destruct_component("fpga_axi_bus");
delete fpga_axi_bus; fpga_axi_bus = 0;
$end;
$destruct_component("fb");
delete fb; fb = 0;
$end;
$destruct_component("ic");
delete ic; ic = 0;
$end;
$destruct_component("jpeg");
delete jpeg; jpeg = 0;
$end;
$destruct_component("fpgamem");
delete fpgamem; fpgamem = 0;
$end;
$destruct_component("ip");
delete ip; ip = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$socket("FPGAslave");
tlm::tlm_target_socket< 128U,axi_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > FPGAslave;
$end;
$socket("FPGAmaster");
tlm::tlm_initiator_socket< 128U,axi_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > FPGAmaster;
$end;
$socket("ip_irq");
tlm::tlm_initiator_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > ip_irq;
$end;
$socket("ic_irq");
tlm::tlm_initiator_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > ic_irq;
$end;
$socket("jpeg_irq");
tlm::tlm_initiator_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > jpeg_irq;
$end;
$component("fpga_axi_bus");
FPGA_AXI_BUS_pvt *fpga_axi_bus;
$end;
$component("fb");
LinuxFrameBufferDisplay_pvt *fb;
$end;
$component("ic");
ImageCapture_pvt *ic;
$end;
$component("jpeg");
JPEG_ENCODER_pvt *jpeg;
$end;
$component("fpgamem");
fpga_memory_pvt *fpgamem;
$end;
$component("ip");
ImageProcessing_pvt *ip;
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