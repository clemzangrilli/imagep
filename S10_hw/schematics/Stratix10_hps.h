#include "mgc_vista_schematics.h"
$includes_begin;
#include "../../../../platforms/stratix10/src/Arria_models/Dummy2_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/split_bus_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SDRAM_Adapter_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_FPGAMGR_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_OCRAM_FireWall_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_DWC_OTG_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_EMAC_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Dummy3_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_PER_FireWall_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_RSTMGR_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_TIMER_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_I2C_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_DDRL3_FireWall_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_LWHPS2FPGA_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_GPIO_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/L4_SYS_Bus_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_HPS2FPGA_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_UART_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_DDR_FireWall_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/L3_Interconnect_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SYSMGR_CORE_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SYSMGRROM_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/signal_source_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SPI_model.h"
#include "models_catalogue.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SDRAM_Scheduler_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/ocram_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_IOMGR_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SDHC_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_CLKMGR_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_SYS_FireWall_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Dummy1_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_HMC_MMR_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_L4WD_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/dma_irq_splitter_model.h"
#include "../../../../platforms/stratix10/src/Arria_models/L4_PER_Bus_model.h"
#include "../../../../platforms/stratix10/src/Arria_schematics/ARMv8_CoreTile.h"
#include "../../../../platforms/stratix10/src/Arria_models/Arria_FPGA2HPS_model.h"
$includes_end;

//$module_begin("Arria10_top");
//SC_MODULE(Arria10_top) {
//public:
//  typedef Arria10_top SC_CURRENT_USER_MODULE;
//  Arria10_top(::sc_core::sc_module_name name):
//    ::sc_core::sc_module(name)
//    $initialization_begin
//$init("FWOCRAM"),
//FWOCRAM(0)
//$end
//$init("QSPI_port"),
//QSPI_port(0)
//$end
//$init("HMCREGS"),
//HMCREGS(0)
//$end
//$init("c6"),
//c6(0)
//$end
//$init("dma_split_bus"),
//dma_split_bus(0)
//$end
//$init("SYSMGR_CORE"),
//SYSMGR_CORE(0)
//$end
//$init("l4_sys_bus"),
//l4_sys_bus(0)
//$end
//$init("FWDDRL3"),
//FWDDRL3(0)
//$end
//$init("EMAC0"),
//EMAC0(0)
//$end
//$init("UART0"),
//UART0(0)
//$end
//$init("OCRAM"),
//OCRAM(0)
//$end
//$init("DMA_SPLIT"),
//DMA_SPLIT(0)
//$end
//$init("EMAC2"),
//EMAC2(0)
//$end
//$init("L4WD1"),
//L4WD1(0)
//$end
//$init("c8"),
//c8(0)
//$end
//$init("SPIS0"),
//SPIS0(0)
//$end
//$init("SPIM1"),
//SPIM1(0)
//$end
//$init("FWL4SYS"),
//FWL4SYS(0)
//$end
//$init("HMCAREGS"),
//HMCAREGS(0)
//$end
//$init("SDMMC"),
//SDMMC(0)
//$end
//$init("QSPI"),
//QSPI(0)
//$end
//$init("RSTMGR"),
//RSTMGR(0)
//$end
//$init("c5"),
//c5(0)
//$end
//$init("I2C0"),
//I2C0(0)
//$end
//$init("FPGAMGR"),
//FPGAMGR(0)
//$end
//$init("CORTEX_A9MP"),
//CORTEX_A9MP(0)
//$end
//$init("GPIO1"),
//GPIO1(0)
//$end
//$init("LWHPS2FPGA"),
//LWHPS2FPGA(0)
//$end
//$init("I2C1"),
//I2C1(0)
//$end
//$init("DMAC"),
//DMAC(0)
//$end
//$init("SPTIMER0"),
//SPTIMER0(0)
//$end
//$init("FWL4PER"),
//FWL4PER(0)
//$end
//$init("Console0"),
//Console0(0)
//$end
//$init("usb1"),
//usb1(0)
//$end
//$init("I2C2"),
//I2C2(0)
//$end
//$init("EMAC1"),
//EMAC1(0)
//$end
//$init("UART1"),
//UART1(0)
//$end
//$init("mpu_split_bus"),
//mpu_split_bus(0)
//$end
//$init("IOMGR"),
//IOMGR(0)
//$end
//$init("fpga_split_bus"),
//fpga_split_bus(0)
//$end
//$init("usb2"),
//usb2(0)
//$end
//$init("I2C3"),
//I2C3(0)
//$end
//$init("l4_per_bus"),
//l4_per_bus(0)
//$end
//$init("SPTIMER1"),
//SPTIMER1(0)
//$end
//$init("L4WD0"),
//L4WD0(0)
//$end
//$init("Console1"),
//Console1(0)
//$end
//$init("SPIM0"),
//SPIM0(0)
//$end
//$init("I2C4"),
//I2C4(0)
//$end
//$init("ext_inst"),
//ext_inst(0)
//$end
//$init("HPS2FPGA"),
//HPS2FPGA(0)
//$end
//$init("BROM"),
//BROM(0)
//$end
//$init("SPIS1"),
//SPIS1(0)
//$end
//$init("CLKMGR"),
//CLKMGR(0)
//$end
//$init("FWFPGA2SDRAM"),
//FWFPGA2SDRAM(0)
//$end
//$init("OSC1TIMER0"),
//OSC1TIMER0(0)
//$end
//$init("OSC1TIMER1"),
//OSC1TIMER1(0)
//$end
//$init("GPIO0"),
//GPIO0(0)
//$end
//$init("l3_interconnect"),
//l3_interconnect(0)
//$end
//$init("FPGA2HPS"),
//FPGA2HPS(0)
//$end
//$init("SYSMGRROM"),
//SYSMGRROM(0)
//$end
//$init("SCHREGS"),
//SCHREGS(0)
//$end
//$init("GPIO2"),
//GPIO2(0)
//$end
//    $initialization_end
//{
//    $elaboration_begin;
////////$create_component("FWOCRAM");
//FWOCRAM = new Arria_OCRAM_FireWall_pvt("FWOCRAM");
//$end;
//$create_component("QSPI_port");
//QSPI_port = new APB2AHB_pvt("QSPI_port");
//$end;
//$create_component("HMCREGS");
//HMCREGS = new Arria_HMC_MMR_pvt("HMCREGS");
//$end;
//$create_component("c6");
//c6 = new Dummy2_pvt("c6");
//$end;
//$create_component("dma_split_bus");
//dma_split_bus = new split_bus_pvt("dma_split_bus");
//$end;
//$create_component("SYSMGR_CORE");
//SYSMGR_CORE = new Arria_SYSMGR_CORE_pvt("SYSMGR_CORE");
//$end;
//$create_component("l4_sys_bus");
//l4_sys_bus = new L4_SYS_Bus_pvt("l4_sys_bus");
//$end;
//$create_component("FWDDRL3");
//FWDDRL3 = new Arria_DDRL3_FireWall_pvt("FWDDRL3");
//$end;
//$create_component("EMAC0");
//EMAC0 = new Arria_EMAC_pvt("EMAC0");
//$end;
//$create_component("UART0");
//UART0 = new Arria_UART_pvt("UART0");
//$end;
//$create_component("OCRAM");
//OCRAM = new ocram_pvt("OCRAM");
//$end;
//$create_component("DMA_SPLIT");
//DMA_SPLIT = new dma_irq_splitter_pvt("DMA_SPLIT");
//$end;
//$create_component("EMAC2");
//EMAC2 = new Arria_EMAC_pvt("EMAC2");
//$end;
//$create_component("L4WD1");
//L4WD1 = new Arria_L4WD_pvt("L4WD1");
//$end;
//$create_component("c8");
//c8 = new Dummy3_pvt("c8");
//$end;
//$create_component("SPIS0");
//SPIS0 = new Arria_SPI_pvt("SPIS0");
//$end;
//$create_component("SPIM1");
//SPIM1 = new Arria_SPI_pvt("SPIM1");
//$end;
//$create_component("FWL4SYS");
//FWL4SYS = new Arria_SYS_FireWall_pvt("FWL4SYS");
//$end;
//$create_component("HMCAREGS");
//HMCAREGS = new Arria_SDRAM_Adapter_pvt("HMCAREGS");
//$end;
//$create_component("SDMMC");
//SDMMC = new Arria_SDHC_pvt("SDMMC");
//$end;
//$create_component("QSPI");
//QSPI = new Arria_QSPI_pvt("QSPI");
//$end;
//$create_component("RSTMGR");
//RSTMGR = new Arria_RSTMGR_pvt("RSTMGR");
//$end;
//$create_component("c5");
//c5 = new Dummy1_pvt("c5");
//$end;
//$create_component("I2C0");
//I2C0 = new Arria_I2C_pvt("I2C0");
//$end;
//$create_component("FPGAMGR");
//FPGAMGR = new Arria_FPGAMGR_pvt("FPGAMGR");
//$end;
//$create_component("CORTEX_A9MP");
//CORTEX_A9MP = new Cortex_A9MP_pvt("CORTEX_A9MP");
//$end;
//$create_component("GPIO1");
//GPIO1 = new Arria_GPIO_pvt("GPIO1");
//$end;
//$create_component("LWHPS2FPGA");
//LWHPS2FPGA = new Arria_LWHPS2FPGA_pvt("LWHPS2FPGA");
//$end;
//$create_component("I2C1");
//I2C1 = new Arria_I2C_pvt("I2C1");
//$end;
//$create_component("DMAC");
//DMAC = new DMA330_pvt("DMAC");
//$end;
//$create_component("SPTIMER0");
//SPTIMER0 = new Arria_TIMER_pvt("SPTIMER0");
//$end;
//$create_component("FWL4PER");
//FWL4PER = new Arria_PER_FireWall_pvt("FWL4PER");
//$end;
//$create_component("Console0");
//Console0 = new CONSOLE_pvt("Console0");
//$end;
//$create_component("usb1");
//usb1 = new Arria_DWC_OTG_pvt("usb1");
//$end;
//$create_component("I2C2");
//I2C2 = new Arria_I2C_pvt("I2C2");
//$end;
//$create_component("EMAC1");
//EMAC1 = new Arria_EMAC_pvt("EMAC1");
//$end;
//$create_component("UART1");
//UART1 = new Arria_UART_pvt("UART1");
//$end;
//$create_component("mpu_split_bus");
//mpu_split_bus = new split_bus_pvt("mpu_split_bus");
//$end;
//$create_component("IOMGR");
//IOMGR = new Arria_IOMGR_pvt("IOMGR");
//$end;
//$create_component("fpga_split_bus");
//fpga_split_bus = new split_bus_pvt("fpga_split_bus");
//$end;
//$create_component("usb2");
//usb2 = new Arria_DWC_OTG_pvt("usb2");
//$end;
//$create_component("I2C3");
//I2C3 = new Arria_I2C_pvt("I2C3");
//$end;
//$create_component("l4_per_bus");
//l4_per_bus = new L4_PER_Bus_pvt("l4_per_bus");
//$end;
//$create_component("SPTIMER1");
//SPTIMER1 = new Arria_TIMER_pvt("SPTIMER1");
//$end;
//$create_component("L4WD0");
//L4WD0 = new Arria_L4WD_pvt("L4WD0");
//$end;
//$create_component("Console1");
//Console1 = new CONSOLE_pvt("Console1");
//$end;
//$create_component("SPIM0");
//SPIM0 = new Arria_SPI_pvt("SPIM0");
//$end;
//$create_component("I2C4");
//I2C4 = new Arria_I2C_pvt("I2C4");
//$end;
//$create_component("ext_inst");
//ext_inst = new external_function_pvt("ext_inst");
//$end;
//$create_component("HPS2FPGA");
//HPS2FPGA = new Arria_HPS2FPGA_pvt("HPS2FPGA");
//$end;
//$create_component("BROM");
//BROM = new brom_pvt("BROM");
//$end;
//$create_component("SPIS1");
//SPIS1 = new Arria_SPI_pvt("SPIS1");
//$end;
//$create_component("CLKMGR");
//CLKMGR = new Arria_CLKMGR_pvt("CLKMGR");
//$end;
//$create_component("FWFPGA2SDRAM");
//FWFPGA2SDRAM = new Arria_DDR_FireWall_pvt("FWFPGA2SDRAM");
//$end;
//$create_component("OSC1TIMER0");
//OSC1TIMER0 = new Arria_TIMER_pvt("OSC1TIMER0");
//$end;
//$create_component("OSC1TIMER1");
//OSC1TIMER1 = new Arria_TIMER_pvt("OSC1TIMER1");
//$end;
//$create_component("GPIO0");
//GPIO0 = new Arria_GPIO_pvt("GPIO0");
//$end;
//$create_component("l3_interconnect");
//l3_interconnect = new L3_Interconnect_pvt("l3_interconnect");
//$end;
//$create_component("FPGA2HPS");
//FPGA2HPS = new Arria_FPGA2HPS_pvt("FPGA2HPS");
//$end;
//$create_component("SYSMGRROM");
//SYSMGRROM = new Arria_SYSMGRROM_pvt("SYSMGRROM");
//$end;
//$create_component("SCHREGS");
//SCHREGS = new Arria_SDRAM_Scheduler_pvt("SCHREGS");
//$end;
//$create_component("GPIO2");
//GPIO2 = new Arria_GPIO_pvt("GPIO2");
//$end;
//$bind("ext_inst->irq17","CORTEX_A9MP->irq_36");
//vista_bind(ext_inst->irq17, CORTEX_A9MP->irq_36);
//$end;
//$bind("RSTMGR->n_qspi_flash_rst","QSPI->Resetn");
//vista_bind(RSTMGR->n_qspi_flash_rst, QSPI->Resetn);
//$end;
//$bind("ext_inst->irq31","CORTEX_A9MP->irq_50");
//vista_bind(ext_inst->irq31, CORTEX_A9MP->irq_50);
//$end;
//$bind("l4_sys_bus->bus_master_hmcaregs","HMCAREGS->Slave0");
//vista_bind(l4_sys_bus->bus_master_hmcaregs, HMCAREGS->Slave0);
//$end;
//$bind("RSTMGR->n_mpu_scu_rst","CORTEX_A9MP->n_scu_reset");
//vista_bind(RSTMGR->n_mpu_scu_rst, CORTEX_A9MP->n_scu_reset);
//$end;
//$bind("ext_inst->irq43","CORTEX_A9MP->irq_62");
//vista_bind(ext_inst->irq43, CORTEX_A9MP->irq_62);
//$end;
//$bind("ext_inst->irq55","CORTEX_A9MP->irq_74");
//vista_bind(ext_inst->irq55, CORTEX_A9MP->irq_74);
//$end;
//$bind("QSPI_port->master","QSPI->AHB");
//vista_bind(QSPI_port->master, QSPI->AHB);
//$end;
//$bind("l4_per_bus->bus_master_sdmmc","SDMMC->APB");
//vista_bind(l4_per_bus->bus_master_sdmmc, SDMMC->APB);
//$end;
//$bind("FWFPGA2SDRAM->master_port_f2s0","SCHREGS->AXI2_Slave");
//vista_bind(FWFPGA2SDRAM->master_port_f2s0, SCHREGS->AXI2_Slave);
//$end;
//$bind("I2C3->IRQ","CORTEX_A9MP->irq_108");
//vista_bind(I2C3->IRQ, CORTEX_A9MP->irq_108);
//$end;
//$bind("UART0->TX","Console0->RX");
//vista_bind(UART0->TX, Console0->RX);
//$end;
//$bind("SPIS1->IRQ","CORTEX_A9MP->irq_104");
//vista_bind(SPIS1->IRQ, CORTEX_A9MP->irq_104);
//$end;
//$bind("usb1->master","l3_interconnect->axi_slave_7");
//vista_bind(usb1->master, l3_interconnect->axi_slave_7);
//$end;
//$bind("l4_per_bus->bus_master_i2c4","I2C4->APB_Slave");
//vista_bind(l4_per_bus->bus_master_i2c4, I2C4->APB_Slave);
//$end;
//$bind("c8->ahb_master1","l3_interconnect->ahb_slave1");
//vista_bind(c8->ahb_master1, l3_interconnect->ahb_slave1);
//$end;
//$bind("I2C3->DMA_RX","DMAC->periph_req_15");
//vista_bind(I2C3->DMA_RX, DMAC->periph_req_15);
//$end;
//$bind("FWOCRAM->master_port","OCRAM->slave");
//vista_bind(FWOCRAM->master_port, OCRAM->slave);
//$end;
//$bind("l4_per_bus->bus_master_dmanonsecure","DMAC->APB_NonSecure_slave");
//vista_bind(l4_per_bus->bus_master_dmanonsecure, DMAC->APB_NonSecure_slave);
//$end;
//$bind("EMAC2->irq","CORTEX_A9MP->irq_94");
//vista_bind(EMAC2->irq, CORTEX_A9MP->irq_94);
//$end;
//$bind("l4_sys_bus->bus_master_clkmgr","CLKMGR->APB");
//vista_bind(l4_sys_bus->bus_master_clkmgr, CLKMGR->APB);
//$end;
//$bind("FPGA2HPS->AXI_master","fpga_split_bus->axi_slave0");
//vista_bind(FPGA2HPS->AXI_master, fpga_split_bus->axi_slave0);
//$end;
//$bind("SPIS1->RXDMA","DMAC->periph_req_23");
//vista_bind(SPIS1->RXDMA, DMAC->periph_req_23);
//$end;
//$bind("DMAC->irq","DMA_SPLIT->input");
//vista_bind(DMAC->irq, DMA_SPLIT->input);
//$end;
//$bind("RSTMGR->n_spim_rst_0","SPIM0->Resetn");
//vista_bind(RSTMGR->n_spim_rst_0, SPIM0->Resetn);
//$end;
//$bind("ext_inst->irq30","CORTEX_A9MP->irq_49");
//vista_bind(ext_inst->irq30, CORTEX_A9MP->irq_49);
//$end;
//$bind("l3_interconnect->axi_master3","c5->axi_slave1");
//vista_bind(l3_interconnect->axi_master3, c5->axi_slave1);
//$end;
//$bind("c8->axi_master5","l3_interconnect->axi_slave6");
//vista_bind(c8->axi_master5, l3_interconnect->axi_slave6);
//$end;
//$bind("l3_interconnect->ahb_master1","c6->ahb_slave1");
//vista_bind(l3_interconnect->ahb_master1, c6->ahb_slave1);
//$end;
//$bind("I2C4->IRQ","CORTEX_A9MP->irq_109");
//vista_bind(I2C4->IRQ, CORTEX_A9MP->irq_109);
//$end;
//$bind("ext_inst->irq15","CORTEX_A9MP->irq_34");
//vista_bind(ext_inst->irq15, CORTEX_A9MP->irq_34);
//$end;
//$bind("DMA_SPLIT->output4","CORTEX_A9MP->irq_87");
//vista_bind(DMA_SPLIT->output4, CORTEX_A9MP->irq_87);
//$end;
//$bind("ext_inst->irq27","CORTEX_A9MP->irq_46");
//vista_bind(ext_inst->irq27, CORTEX_A9MP->irq_46);
//$end;
//$bind("ext_inst->irq39","CORTEX_A9MP->irq_58");
//vista_bind(ext_inst->irq39, CORTEX_A9MP->irq_58);
//$end;
//$bind("ext_inst->irq41","CORTEX_A9MP->irq_60");
//vista_bind(ext_inst->irq41, CORTEX_A9MP->irq_60);
//$end;
//$bind("RSTMGR->n_dma_rst","DMAC->aresetn");
//vista_bind(RSTMGR->n_dma_rst, DMAC->aresetn);
//$end;
//$bind("RSTMGR->n_spim_rst_1","SPIM1->Resetn");
//vista_bind(RSTMGR->n_spim_rst_1, SPIM1->Resetn);
//$end;
//$bind("ext_inst->irq53","CORTEX_A9MP->irq_72");
//vista_bind(ext_inst->irq53, CORTEX_A9MP->irq_72);
//$end;
//$bind("ext_inst->irq7","CORTEX_A9MP->irq_26");
//vista_bind(ext_inst->irq7, CORTEX_A9MP->irq_26);
//$end;
//$bind("UART1->TX","Console1->RX");
//vista_bind(UART1->TX, Console1->RX);
//$end;
//$bind("RSTMGR->n_osc1_timer_rst_1","OSC1TIMER1->reset");
//vista_bind(RSTMGR->n_osc1_timer_rst_1, OSC1TIMER1->reset);
//$end;
//$bind("I2C1->DMA_TX","DMAC->periph_req_10");
//vista_bind(I2C1->DMA_TX, DMAC->periph_req_10);
//$end;
//$bind("dma_split_bus->apb_master_sys","l4_sys_bus->bus_slave_dmac");
//vista_bind(dma_split_bus->apb_master_sys, l4_sys_bus->bus_slave_dmac);
//$end;
//$bind("l4_per_bus->bus_master_qspireg","QSPI->APB");
//vista_bind(l4_per_bus->bus_master_qspireg, QSPI->APB);
//$end;
//$bind("ext_inst->irq42","CORTEX_A9MP->irq_61");
//vista_bind(ext_inst->irq42, CORTEX_A9MP->irq_61);
//$end;
//$bind("HMCAREGS->Master1","HMCREGS->Slave2");
//vista_bind(HMCAREGS->Master1, HMCREGS->Slave2);
//$end;
//$bind("RSTMGR->n_i2c_rst_3","I2C3->Resetn");
//vista_bind(RSTMGR->n_i2c_rst_3, I2C3->Resetn);
//$end;
//$bind("l3_interconnect->apb_master5","c6->apb_slave3");
//vista_bind(l3_interconnect->apb_master5, c6->apb_slave3);
//$end;
//$bind("FPGAMGR->IRQ","CORTEX_A9MP->irq_123");
//vista_bind(FPGAMGR->IRQ, CORTEX_A9MP->irq_123);
//$end;
//$bind("QSPI->DMA_WR","DMAC->periph_req_24");
//vista_bind(QSPI->DMA_WR, DMAC->periph_req_24);
//$end;
//$bind("l3_interconnect->axi_master11","usb1->slave");
//vista_bind(l3_interconnect->axi_master11, usb1->slave);
//$end;
//$bind("Console1->TX","UART1->RX");
//vista_bind(Console1->TX, UART1->RX);
//$end;
//$bind("l3_interconnect->axi_master1","HPS2FPGA->AXI_Slave");
//vista_bind(l3_interconnect->axi_master1, HPS2FPGA->AXI_Slave);
//$end;
//$bind("FWFPGA2SDRAM->master_port_mpu","SCHREGS->AXI1_Slave");
//vista_bind(FWFPGA2SDRAM->master_port_mpu, SCHREGS->AXI1_Slave);
//$end;
//$bind("OSC1TIMER1->irq","CORTEX_A9MP->irq_118");
//vista_bind(OSC1TIMER1->irq, CORTEX_A9MP->irq_118);
//$end;
//$bind("fpga_split_bus->apb_master_per","l4_per_bus->bus_slave_fpgabridg");
//vista_bind(fpga_split_bus->apb_master_per, l4_per_bus->bus_slave_fpgabridg);
//$end;
//$bind("LWHPS2FPGA->AHB_Master_FPGA2HPS","FPGA2HPS->AHB_slave");
//vista_bind(LWHPS2FPGA->AHB_Master_FPGA2HPS, FPGA2HPS->AHB_slave);
//$end;
//$bind("l3_interconnect->axi_master2","FWDDRL3->slave_port");
//vista_bind(l3_interconnect->axi_master2, FWDDRL3->slave_port);
//$end;
//$bind("HMCAREGS->Master0","HMCREGS->Slave1");
//vista_bind(HMCAREGS->Master0, HMCREGS->Slave1);
//$end;
//$bind("ext_inst->irq40","CORTEX_A9MP->irq_59");
//vista_bind(ext_inst->irq40, CORTEX_A9MP->irq_59);
//$end;
//$bind("SYSMGR_CORE->irq_ns","DMAC->boot_irq_ns");
//vista_bind(SYSMGR_CORE->irq_ns, DMAC->boot_irq_ns);
//$end;
//$bind("SDMMC->IRQ","CORTEX_A9MP->irq_98");
//vista_bind(SDMMC->IRQ, CORTEX_A9MP->irq_98);
//$end;
//$bind("QSPI->DMA_RD","DMAC->periph_req_25");
//vista_bind(QSPI->DMA_RD, DMAC->periph_req_25);
//$end;
//$bind("DMA_SPLIT->output2","CORTEX_A9MP->irq_85");
//vista_bind(DMA_SPLIT->output2, CORTEX_A9MP->irq_85);
//$end;
//$bind("I2C2->DMA_TX","DMAC->periph_req_12");
//vista_bind(I2C2->DMA_TX, DMAC->periph_req_12);
//$end;
//$bind("ext_inst->irq37","CORTEX_A9MP->irq_56");
//vista_bind(ext_inst->irq37, CORTEX_A9MP->irq_56);
//$end;
//$bind("l4_sys_bus->bus_master_hmcregs","HMCREGS->Slave0");
//vista_bind(l4_sys_bus->bus_master_hmcregs, HMCREGS->Slave0);
//$end;
//$bind("ext_inst->irq49","CORTEX_A9MP->irq_68");
//vista_bind(ext_inst->irq49, CORTEX_A9MP->irq_68);
//$end;
//$bind("usb1->irq","CORTEX_A9MP->irq_95");
//vista_bind(usb1->irq, CORTEX_A9MP->irq_95);
//$end;
//$bind("FWFPGA2SDRAM->master_port_f2s1","SCHREGS->AXI3_Slave");
//vista_bind(FWFPGA2SDRAM->master_port_f2s1, SCHREGS->AXI3_Slave);
//$end;
//$bind("ext_inst->irq5","CORTEX_A9MP->irq_24");
//vista_bind(ext_inst->irq5, CORTEX_A9MP->irq_24);
//$end;
//$bind("DMAC->irq_abort","CORTEX_A9MP->irq_91");
//vista_bind(DMAC->irq_abort, CORTEX_A9MP->irq_91);
//$end;
//$bind("l4_sys_bus->bus_master_fwddrl3","FWDDRL3->slave_reg");
//vista_bind(l4_sys_bus->bus_master_fwddrl3, FWDDRL3->slave_reg);
//$end;
//$bind("ext_inst->irq14","CORTEX_A9MP->irq_33");
//vista_bind(ext_inst->irq14, CORTEX_A9MP->irq_33);
//$end;
//$bind("FWL4SYS->out0","l4_sys_bus->security");
//vista_bind(FWL4SYS->out0, l4_sys_bus->security);
//$end;
//$bind("DMA_SPLIT->output3","CORTEX_A9MP->irq_86");
//vista_bind(DMA_SPLIT->output3, CORTEX_A9MP->irq_86);
//$end;
//$bind("ext_inst->irq26","CORTEX_A9MP->irq_45");
//vista_bind(ext_inst->irq26, CORTEX_A9MP->irq_45);
//$end;
//$bind("ext_inst->irq38","CORTEX_A9MP->irq_57");
//vista_bind(ext_inst->irq38, CORTEX_A9MP->irq_57);
//$end;
//$bind("l4_per_bus->bus_master_sptimer1","SPTIMER1->apb");
//vista_bind(l4_per_bus->bus_master_sptimer1, SPTIMER1->apb);
//$end;
//$bind("ext_inst->irq52","CORTEX_A9MP->irq_71");
//vista_bind(ext_inst->irq52, CORTEX_A9MP->irq_71);
//$end;
//$bind("EMAC0->AXI","l3_interconnect->axi_slave3");
//vista_bind(EMAC0->AXI, l3_interconnect->axi_slave3);
//$end;
//$bind("ext_inst->irq6","CORTEX_A9MP->irq_25");
//vista_bind(ext_inst->irq6, CORTEX_A9MP->irq_25);
//$end;
//$bind("dma_split_bus->apb_master_per","l4_per_bus->bus_slave_dmac");
//vista_bind(dma_split_bus->apb_master_per, l4_per_bus->bus_slave_dmac);
//$end;
//$bind("l4_sys_bus->bus_master_osc1timer0","OSC1TIMER0->apb");
//vista_bind(l4_sys_bus->bus_master_osc1timer0, OSC1TIMER0->apb);
//$end;
//$bind("l3_interconnect->apb_master2","c6->apb_slave1");
//vista_bind(l3_interconnect->apb_master2, c6->apb_slave1);
//$end;
//$bind("RSTMGR->n_mpu_periph_rst","CORTEX_A9MP->n_periph_reset");
//vista_bind(RSTMGR->n_mpu_periph_rst, CORTEX_A9MP->n_periph_reset);
//$end;
//$bind("l4_per_bus->bus_master_emac2","EMAC2->apb");
//vista_bind(l4_per_bus->bus_master_emac2, EMAC2->apb);
//$end;
//$bind("UART0->DMA_RX","DMAC->periph_req_29");
//vista_bind(UART0->DMA_RX, DMAC->periph_req_29);
//$end;
//$bind("SPIM0->TXDMA","DMAC->periph_req_16");
//vista_bind(SPIM0->TXDMA, DMAC->periph_req_16);
//$end;
//$bind("I2C3->DMA_TX","DMAC->periph_req_14");
//vista_bind(I2C3->DMA_TX, DMAC->periph_req_14);
//$end;
//$bind("l3_interconnect->axi_master7","c5->axi_slave5");
//vista_bind(l3_interconnect->axi_master7, c5->axi_slave5);
//$end;
//$bind("usb2->irq","CORTEX_A9MP->irq_96");
//vista_bind(usb2->irq, CORTEX_A9MP->irq_96);
//$end;
//$bind("CORTEX_A9MP->wd_reset_req_0","RSTMGR->mpu_wd_rst_req_0");
//vista_bind(CORTEX_A9MP->wd_reset_req_0, RSTMGR->mpu_wd_rst_req_0);
//$end;
//$bind("EMAC2->AXI","l3_interconnect->axi_slave5");
//vista_bind(EMAC2->AXI, l3_interconnect->axi_slave5);
//$end;
//$bind("l4_per_bus->bus_master_gpio2","GPIO2->slave");
//vista_bind(l4_per_bus->bus_master_gpio2, GPIO2->slave);
//$end;
//$bind("dma_split_bus->axi_master_l3","l3_interconnect->axi_slave2");
//vista_bind(dma_split_bus->axi_master_l3, l3_interconnect->axi_slave2);
//$end;
//$bind("mpu_split_bus->apb_master_sys","l4_sys_bus->bus_slave_mpu");
//vista_bind(mpu_split_bus->apb_master_sys, l4_sys_bus->bus_slave_mpu);
//$end;
//$bind("UART0->DMA_TX","DMAC->periph_req_28");
//vista_bind(UART0->DMA_TX, DMAC->periph_req_28);
//$end;
//$bind("UART0->IRQ","CORTEX_A9MP->irq_110");
//vista_bind(UART0->IRQ, CORTEX_A9MP->irq_110);
//$end;
//$bind("DMA_SPLIT->output1","CORTEX_A9MP->irq_84");
//vista_bind(DMA_SPLIT->output1, CORTEX_A9MP->irq_84);
//$end;
//$bind("ext_inst->irq24","CORTEX_A9MP->irq_43");
//vista_bind(ext_inst->irq24, CORTEX_A9MP->irq_43);
//$end;
//$bind("l4_per_bus->bus_master_gpio1","GPIO1->slave");
//vista_bind(l4_per_bus->bus_master_gpio1, GPIO1->slave);
//$end;
//$bind("ext_inst->irq36","CORTEX_A9MP->irq_55");
//vista_bind(ext_inst->irq36, CORTEX_A9MP->irq_55);
//$end;
//$bind("ext_inst->irq48","CORTEX_A9MP->irq_67");
//vista_bind(ext_inst->irq48, CORTEX_A9MP->irq_67);
//$end;
//$bind("RSTMGR->n_i2c_rst_4","I2C4->Resetn");
//vista_bind(RSTMGR->n_i2c_rst_4, I2C4->Resetn);
//$end;
//$bind("I2C0->DMA_TX","DMAC->periph_req_8");
//vista_bind(I2C0->DMA_TX, DMAC->periph_req_8);
//$end;
//$bind("ext_inst->irq62","CORTEX_A9MP->irq_81");
//vista_bind(ext_inst->irq62, CORTEX_A9MP->irq_81);
//$end;
//$bind("ext_inst->irq4","CORTEX_A9MP->irq_23");
//vista_bind(ext_inst->irq4, CORTEX_A9MP->irq_23);
//$end;
//$bind("l3_interconnect->axi_master12","usb2->slave");
//vista_bind(l3_interconnect->axi_master12, usb2->slave);
//$end;
//$bind("l4_per_bus->bus_master_gpio0","GPIO0->slave");
//vista_bind(l4_per_bus->bus_master_gpio0, GPIO0->slave);
//$end;
//$bind("ext_inst->irq13","CORTEX_A9MP->irq_32");
//vista_bind(ext_inst->irq13, CORTEX_A9MP->irq_32);
//$end;
//$bind("ext_inst->irq25","CORTEX_A9MP->irq_44");
//vista_bind(ext_inst->irq25, CORTEX_A9MP->irq_44);
//$end;
//$bind("l4_per_bus->bus_master_emac1","EMAC1->apb");
//vista_bind(l4_per_bus->bus_master_emac1, EMAC1->apb);
//$end;
//$bind("Console0->TX","UART0->RX");
//vista_bind(Console0->TX, UART0->RX);
//$end;
//$bind("SPIS1->TXDMA","DMAC->periph_req_22");
//vista_bind(SPIS1->TXDMA, DMAC->periph_req_22);
//$end;
//$bind("ext_inst->irq51","CORTEX_A9MP->irq_70");
//vista_bind(ext_inst->irq51, CORTEX_A9MP->irq_70);
//$end;
//$bind("ext_inst->irq63","CORTEX_A9MP->irq_82");
//vista_bind(ext_inst->irq63, CORTEX_A9MP->irq_82);
//$end;
//$bind("GPIO1->irq","CORTEX_A9MP->irq_113");
//vista_bind(GPIO1->irq, CORTEX_A9MP->irq_113);
//$end;
//$bind("RSTMGR->n_i2c_rst_0","I2C0->Resetn");
//vista_bind(RSTMGR->n_i2c_rst_0, I2C0->Resetn);
//$end;
//$bind("SPIS0->RXDMA","DMAC->periph_req_19");
//vista_bind(SPIS0->RXDMA, DMAC->periph_req_19);
//$end;
//$bind("FWL4PER->out0","l4_per_bus->security");
//vista_bind(FWL4PER->out0, l4_per_bus->security);
//$end;
//$bind("l3_interconnect->axi_master4","c5->axi_slave7");
//vista_bind(l3_interconnect->axi_master4, c5->axi_slave7);
//$end;
//$bind("ext_inst->master","FPGA2HPS->AXI_slave");
//vista_bind(ext_inst->master, FPGA2HPS->AXI_slave);
//$end;
//$bind("RSTMGR->n_gpio_rst_0","GPIO0->Resetn");
//vista_bind(RSTMGR->n_gpio_rst_0, GPIO0->Resetn);
//$end;
//$bind("mpu_split_bus->apb_master_per","l4_per_bus->bus_slave_mpu");
//vista_bind(mpu_split_bus->apb_master_per, l4_per_bus->bus_slave_mpu);
//$end;
//$bind("l3_interconnect->apb_master1","l4_per_bus->bus_slave_l3");
//vista_bind(l3_interconnect->apb_master1, l4_per_bus->bus_slave_l3);
//$end;
//$bind("l3_interconnect->axi_master9","BROM->slave");
//vista_bind(l3_interconnect->axi_master9, BROM->slave);
//$end;
//$bind("l4_sys_bus->bus_master_fwl4sys","FWL4SYS->slave_reg");
//vista_bind(l4_sys_bus->bus_master_fwl4sys, FWL4SYS->slave_reg);
//$end;
//$bind("SYSMGR_CORE->mgr_ns","DMAC->boot_manager_ns");
//vista_bind(SYSMGR_CORE->mgr_ns, DMAC->boot_manager_ns);
//$end;
//$bind("SPIS0->IRQ","CORTEX_A9MP->irq_103");
//vista_bind(SPIS0->IRQ, CORTEX_A9MP->irq_103);
//$end;
//$bind("l4_per_bus->bus_master_spi1","SPIS1->APB");
//vista_bind(l4_per_bus->bus_master_spi1, SPIS1->APB);
//$end;
//$bind("SPIM1->IRQ","CORTEX_A9MP->irq_102");
//vista_bind(SPIM1->IRQ, CORTEX_A9MP->irq_102);
//$end;
//$bind("l4_per_bus->bus_master_uart1","UART1->APB_Port");
//vista_bind(l4_per_bus->bus_master_uart1, UART1->APB_Port);
//$end;
//$bind("EMAC1->irq","CORTEX_A9MP->irq_93");
//vista_bind(EMAC1->irq, CORTEX_A9MP->irq_93);
//$end;
//$bind("ext_inst->irq58","CORTEX_A9MP->irq_77");
//vista_bind(ext_inst->irq58, CORTEX_A9MP->irq_77);
//$end;
//$bind("SPIM1->RXDMA","DMAC->periph_req_21");
//vista_bind(SPIM1->RXDMA, DMAC->periph_req_21);
//$end;
//$bind("I2C0->DMA_RX","DMAC->periph_req_9");
//vista_bind(I2C0->DMA_RX, DMAC->periph_req_9);
//$end;
//$bind("ext_inst->irq50","CORTEX_A9MP->irq_69");
//vista_bind(ext_inst->irq50, CORTEX_A9MP->irq_69);
//$end;
//$bind("ext_inst->irq11","CORTEX_A9MP->irq_30");
//vista_bind(ext_inst->irq11, CORTEX_A9MP->irq_30);
//$end;
//$bind("DMA_SPLIT->output0","CORTEX_A9MP->irq_83");
//vista_bind(DMA_SPLIT->output0, CORTEX_A9MP->irq_83);
//$end;
//$bind("ext_inst->irq23","CORTEX_A9MP->irq_42");
//vista_bind(ext_inst->irq23, CORTEX_A9MP->irq_42);
//$end;
//$bind("ext_inst->irq35","CORTEX_A9MP->irq_54");
//vista_bind(ext_inst->irq35, CORTEX_A9MP->irq_54);
//$end;
//$bind("ext_inst->irq47","CORTEX_A9MP->irq_66");
//vista_bind(ext_inst->irq47, CORTEX_A9MP->irq_66);
//$end;
//$bind("ext_inst->irq59","CORTEX_A9MP->irq_78");
//vista_bind(ext_inst->irq59, CORTEX_A9MP->irq_78);
//$end;
//$bind("ext_inst->irq61","CORTEX_A9MP->irq_80");
//vista_bind(ext_inst->irq61, CORTEX_A9MP->irq_80);
//$end;
//$bind("ext_inst->irq3","CORTEX_A9MP->irq_22");
//vista_bind(ext_inst->irq3, CORTEX_A9MP->irq_22);
//$end;
//$bind("l4_per_bus->bus_master_emac0","EMAC0->apb");
//vista_bind(l4_per_bus->bus_master_emac0, EMAC0->apb);
//$end;
//$bind("l4_sys_bus->bus_master_fpgamgrregs","FPGAMGR->APB");
//vista_bind(l4_sys_bus->bus_master_fpgamgrregs, FPGAMGR->APB);
//$end;
//$bind("ext_inst->irq12","CORTEX_A9MP->irq_31");
//vista_bind(ext_inst->irq12, CORTEX_A9MP->irq_31);
//$end;
//$bind("l4_sys_bus->bus_master_osc1timer1","OSC1TIMER1->apb");
//vista_bind(l4_sys_bus->bus_master_osc1timer1, OSC1TIMER1->apb);
//$end;
//$bind("l3_interconnect->axi_master0","FWOCRAM->slave_port");
//vista_bind(l3_interconnect->axi_master0, FWOCRAM->slave_port);
//$end;
//$bind("l4_sys_bus->bus_master_rstmgr","RSTMGR->APB_A10");
//vista_bind(l4_sys_bus->bus_master_rstmgr, RSTMGR->APB_A10);
//$end;
//$bind("RSTMGR->n_sdmmc_rst","SDMMC->Resetn");
//vista_bind(RSTMGR->n_sdmmc_rst, SDMMC->Resetn);
//$end;
//$bind("l4_sys_bus->bus_master_sysmgrrom","SYSMGRROM->slave");
//vista_bind(l4_sys_bus->bus_master_sysmgrrom, SYSMGRROM->slave);
//$end;
//$bind("RSTMGR->n_spis_rst_0","SPIS0->Resetn");
//vista_bind(RSTMGR->n_spis_rst_0, SPIS0->Resetn);
//$end;
//$bind("RSTMGR->n_sp_timer_rst_1","SPTIMER1->reset");
//vista_bind(RSTMGR->n_sp_timer_rst_1, SPTIMER1->reset);
//$end;
//$bind("RSTMGR->n_osc1_timer_rst_0","OSC1TIMER0->reset");
//vista_bind(RSTMGR->n_osc1_timer_rst_0, OSC1TIMER0->reset);
//$end;
//$bind("l4_per_bus->bus_master_spi0","SPIS0->APB");
//vista_bind(l4_per_bus->bus_master_spi0, SPIS0->APB);
//$end;
//$bind("l4_per_bus->bus_master_i2c0","I2C0->APB_Slave");
//vista_bind(l4_per_bus->bus_master_i2c0, I2C0->APB_Slave);
//$end;
//$bind("l3_interconnect->apb_master3","c6->apb_slave2");
//vista_bind(l3_interconnect->apb_master3, c6->apb_slave2);
//$end;
//$bind("ext_inst->irq10","CORTEX_A9MP->irq_29");
//vista_bind(ext_inst->irq10, CORTEX_A9MP->irq_29);
//$end;
//$bind("l4_sys_bus->bus_master_l4wd1","L4WD1->APB");
//vista_bind(l4_sys_bus->bus_master_l4wd1, L4WD1->APB);
//$end;
//$bind("HPS2FPGA->AXI_Master","ext_inst->host");
//vista_bind(HPS2FPGA->AXI_Master, ext_inst->host);
//$end;
//$bind("l4_per_bus->bus_master_uart0","UART0->APB_Port");
//vista_bind(l4_per_bus->bus_master_uart0, UART0->APB_Port);
//$end;
//$bind("QSPI->IRQ","CORTEX_A9MP->irq_100");
//vista_bind(QSPI->IRQ, CORTEX_A9MP->irq_100);
//$end;
//$bind("OSC1TIMER0->irq","CORTEX_A9MP->irq_117");
//vista_bind(OSC1TIMER0->irq, CORTEX_A9MP->irq_117);
//$end;
//$bind("ext_inst->irq60","CORTEX_A9MP->irq_79");
//vista_bind(ext_inst->irq60, CORTEX_A9MP->irq_79);
//$end;
//$bind("ext_inst->irq19","CORTEX_A9MP->irq_38");
//vista_bind(ext_inst->irq19, CORTEX_A9MP->irq_38);
//$end;
//$bind("FWFPGA2SDRAM->master_port_f2s2","SCHREGS->AXI4_Slave");
//vista_bind(FWFPGA2SDRAM->master_port_f2s2, SCHREGS->AXI4_Slave);
//$end;
//$bind("ext_inst->irq45","CORTEX_A9MP->irq_64");
//vista_bind(ext_inst->irq45, CORTEX_A9MP->irq_64);
//$end;
//$bind("ext_inst->irq57","CORTEX_A9MP->irq_76");
//vista_bind(ext_inst->irq57, CORTEX_A9MP->irq_76);
//$end;
//$bind("RSTMGR->n_i2c_rst_1","I2C1->Resetn");
//vista_bind(RSTMGR->n_i2c_rst_1, I2C1->Resetn);
//$end;
//$bind("ext_inst->irq1","CORTEX_A9MP->irq_20");
//vista_bind(ext_inst->irq1, CORTEX_A9MP->irq_20);
//$end;
//$bind("l4_per_bus->bus_master_i2c1","I2C1->APB_Slave");
//vista_bind(l4_per_bus->bus_master_i2c1, I2C1->APB_Slave);
//$end;
//$bind("l3_interconnect->axi_master8","c5->axi_slave6");
//vista_bind(l3_interconnect->axi_master8, c5->axi_slave6);
//$end;
//$bind("usb2->master","l3_interconnect->axi_slave8");
//vista_bind(usb2->master, l3_interconnect->axi_slave8);
//$end;
//$bind("RSTMGR->n_gpio_rst_1","GPIO1->Resetn");
//vista_bind(RSTMGR->n_gpio_rst_1, GPIO1->Resetn);
//$end;
//$bind("l3_interconnect->axi_master10","c5->axi_slave3");
//vista_bind(l3_interconnect->axi_master10, c5->axi_slave3);
//$end;
//$bind("LWHPS2FPGA->AXI_Master","ext_inst->host1");
//vista_bind(LWHPS2FPGA->AXI_Master, ext_inst->host1);
//$end;
//$bind("ext_inst->irq22","CORTEX_A9MP->irq_41");
//vista_bind(ext_inst->irq22, CORTEX_A9MP->irq_41);
//$end;
//$bind("ext_inst->irq34","CORTEX_A9MP->irq_53");
//vista_bind(ext_inst->irq34, CORTEX_A9MP->irq_53);
//$end;
//$bind("l3_interconnect->axi_master5","LWHPS2FPGA->AXI_Slave");
//vista_bind(l3_interconnect->axi_master5, LWHPS2FPGA->AXI_Slave);
//$end;
//$bind("ext_inst->irq46","CORTEX_A9MP->irq_65");
//vista_bind(ext_inst->irq46, CORTEX_A9MP->irq_65);
//$end;
//$bind("ext_inst->irq2","CORTEX_A9MP->irq_21");
//vista_bind(ext_inst->irq2, CORTEX_A9MP->irq_21);
//$end;
//$bind("l4_per_bus->bus_master_qspidata","QSPI_port->slave");
//vista_bind(l4_per_bus->bus_master_qspidata, QSPI_port->slave);
//$end;
//$bind("FPGAMGR->DMA_WR","DMAC->periph_req_27");
//vista_bind(FPGAMGR->DMA_WR, DMAC->periph_req_27);
//$end;
//$bind("RSTMGR->n_gpio_rst_2","GPIO2->Resetn");
//vista_bind(RSTMGR->n_gpio_rst_2, GPIO2->Resetn);
//$end;
//$bind("RSTMGR->n_fpga_manager_rst","FPGAMGR->Resetn");
//vista_bind(RSTMGR->n_fpga_manager_rst, FPGAMGR->Resetn);
//$end;
//$bind("l4_per_bus->bus_master_spi3","SPIM1->APB");
//vista_bind(l4_per_bus->bus_master_spi3, SPIM1->APB);
//$end;
//$bind("l4_per_bus->bus_master_i2c2","I2C2->APB_Slave");
//vista_bind(l4_per_bus->bus_master_i2c2, I2C2->APB_Slave);
//$end;
//$bind("I2C0->IRQ","CORTEX_A9MP->irq_105");
//vista_bind(I2C0->IRQ, CORTEX_A9MP->irq_105);
//$end;
//$bind("l4_sys_bus->bus_master_fwl4per","FWL4PER->slave_reg");
//vista_bind(l4_sys_bus->bus_master_fwl4per, FWL4PER->slave_reg);
//$end;
//$bind("SYSMGR_CORE->per_ns","DMAC->boot_periph_ns");
//vista_bind(SYSMGR_CORE->per_ns, DMAC->boot_periph_ns);
//$end;
//$bind("I2C4->DMA_TX","DMAC->periph_req_6");
//vista_bind(I2C4->DMA_TX, DMAC->periph_req_6);
//$end;
//$bind("SPTIMER0->irq","CORTEX_A9MP->irq_115");
//vista_bind(SPTIMER0->irq, CORTEX_A9MP->irq_115);
//$end;
//$bind("SCHREGS->APB_Master","HMCAREGS->Slave1");
//vista_bind(SCHREGS->APB_Master, HMCAREGS->Slave1);
//$end;
//$bind("SDMMC->AHB","l3_interconnect->ahb_slave0");
//vista_bind(SDMMC->AHB, l3_interconnect->ahb_slave0);
//$end;
//$bind("l4_per_bus->bus_master_dmasecure","DMAC->APB_slave");
//vista_bind(l4_per_bus->bus_master_dmasecure, DMAC->APB_slave);
//$end;
//$bind("l3_interconnect->apb_master0","c6->apb_slave0");
//vista_bind(l3_interconnect->apb_master0, c6->apb_slave0);
//$end;
//$bind("ext_inst->irq20","CORTEX_A9MP->irq_39");
//vista_bind(ext_inst->irq20, CORTEX_A9MP->irq_39);
//$end;
//$bind("DMAC->AXI_master","dma_split_bus->axi_slave0");
//vista_bind(DMAC->AXI_master, dma_split_bus->axi_slave0);
//$end;
//$bind("l4_sys_bus->bus_master_l4wd0","L4WD0->APB");
//vista_bind(l4_sys_bus->bus_master_l4wd0, L4WD0->APB);
//$end;
//$bind("l4_sys_bus->bus_master_iomgr","IOMGR->Prog_IF");
//vista_bind(l4_sys_bus->bus_master_iomgr, IOMGR->Prog_IF);
//$end;
//$bind("ext_inst->irq0","CORTEX_A9MP->irq_19");
//vista_bind(ext_inst->irq0, CORTEX_A9MP->irq_19);
//$end;
//$bind("l4_per_bus->bus_master_i2c3","I2C3->APB_Slave");
//vista_bind(l4_per_bus->bus_master_i2c3, I2C3->APB_Slave);
//$end;
//$bind("DMA_SPLIT->output6","CORTEX_A9MP->irq_89");
//vista_bind(DMA_SPLIT->output6, CORTEX_A9MP->irq_89);
//$end;
//$bind("ext_inst->irq29","CORTEX_A9MP->irq_48");
//vista_bind(ext_inst->irq29, CORTEX_A9MP->irq_48);
//$end;
//$bind("RSTMGR->n_mpu_wd_rst_0","CORTEX_A9MP->n_wd_reset_0");
//vista_bind(RSTMGR->n_mpu_wd_rst_0, CORTEX_A9MP->n_wd_reset_0);
//$end;
//$bind("RSTMGR->n_sp_timer_rst_0","SPTIMER0->reset");
//vista_bind(RSTMGR->n_sp_timer_rst_0, SPTIMER0->reset);
//$end;
//$bind("ext_inst->irq9","CORTEX_A9MP->irq_28");
//vista_bind(ext_inst->irq9, CORTEX_A9MP->irq_28);
//$end;
//$bind("EMAC1->AXI","l3_interconnect->axi_slave4");
//vista_bind(EMAC1->AXI, l3_interconnect->axi_slave4);
//$end;
//$bind("l4_sys_bus->bus_master_fwfpga2sdram","FWFPGA2SDRAM->slave_reg");
//vista_bind(l4_sys_bus->bus_master_fwfpga2sdram, FWFPGA2SDRAM->slave_reg);
//$end;
//$bind("ext_inst->irq18","CORTEX_A9MP->irq_37");
//vista_bind(ext_inst->irq18, CORTEX_A9MP->irq_37);
//$end;
//$bind("l3_interconnect->apb_master4","l4_sys_bus->bus_slave_l3");
//vista_bind(l3_interconnect->apb_master4, l4_sys_bus->bus_slave_l3);
//$end;
//$bind("l4_per_bus->bus_master_sptimer0","SPTIMER0->apb");
//vista_bind(l4_per_bus->bus_master_sptimer0, SPTIMER0->apb);
//$end;
//$bind("l4_sys_bus->bus_master_sysmgr","SYSMGR_CORE->slave_reg");
//vista_bind(l4_sys_bus->bus_master_sysmgr, SYSMGR_CORE->slave_reg);
//$end;
//$bind("RSTMGR->n_spis_rst_1","SPIS1->Resetn");
//vista_bind(RSTMGR->n_spis_rst_1, SPIS1->Resetn);
//$end;
//$bind("ext_inst->irq32","CORTEX_A9MP->irq_51");
//vista_bind(ext_inst->irq32, CORTEX_A9MP->irq_51);
//$end;
//$bind("SPIS0->TXDMA","DMAC->periph_req_18");
//vista_bind(SPIS0->TXDMA, DMAC->periph_req_18);
//$end;
//$bind("I2C1->IRQ","CORTEX_A9MP->irq_106");
//vista_bind(I2C1->IRQ, CORTEX_A9MP->irq_106);
//$end;
//$bind("ext_inst->irq44","CORTEX_A9MP->irq_63");
//vista_bind(ext_inst->irq44, CORTEX_A9MP->irq_63);
//$end;
//$bind("ext_inst->irq56","CORTEX_A9MP->irq_75");
//vista_bind(ext_inst->irq56, CORTEX_A9MP->irq_75);
//$end;
//$bind("RSTMGR->IRQ","CORTEX_A9MP->irq_122");
//vista_bind(RSTMGR->IRQ, CORTEX_A9MP->irq_122);
//$end;
//$bind("I2C1->DMA_RX","DMAC->periph_req_11");
//vista_bind(I2C1->DMA_RX, DMAC->periph_req_11);
//$end;
//$bind("l4_sys_bus->bus_master_fpgamgrdata","FPGAMGR->DATA_A10");
//vista_bind(l4_sys_bus->bus_master_fpgamgrdata, FPGAMGR->DATA_A10);
//$end;
//$bind("ext_inst->irq21","CORTEX_A9MP->irq_40");
//vista_bind(ext_inst->irq21, CORTEX_A9MP->irq_40);
//$end;
//$bind("ext_inst->irq33","CORTEX_A9MP->irq_52");
//vista_bind(ext_inst->irq33, CORTEX_A9MP->irq_52);
//$end;
//$bind("l4_per_bus->bus_master_spi2","SPIM0->APB");
//vista_bind(l4_per_bus->bus_master_spi2, SPIM0->APB);
//$end;
//$bind("I2C4->DMA_RX","DMAC->periph_req_7");
//vista_bind(I2C4->DMA_RX, DMAC->periph_req_7);
//$end;
//$bind("DMA_SPLIT->output7","CORTEX_A9MP->irq_90");
//vista_bind(DMA_SPLIT->output7, CORTEX_A9MP->irq_90);
//$end;
//$bind("UART1->DMA_RX","DMAC->periph_req_31");
//vista_bind(UART1->DMA_RX, DMAC->periph_req_31);
//$end;
//$bind("SPIM1->TXDMA","DMAC->periph_req_20");
//vista_bind(SPIM1->TXDMA, DMAC->periph_req_20);
//$end;
//$bind("FWDDRL3->master_port","SCHREGS->AXI0_Slave");
//vista_bind(FWDDRL3->master_port, SCHREGS->AXI0_Slave);
//$end;
//$bind("GPIO0->irq","CORTEX_A9MP->irq_112");
//vista_bind(GPIO0->irq, CORTEX_A9MP->irq_112);
//$end;
//$bind("RSTMGR->n_mpu_cpu_rst_1","CORTEX_A9MP->n_reset_1");
//vista_bind(RSTMGR->n_mpu_cpu_rst_1, CORTEX_A9MP->n_reset_1);
//$end;
//$bind("l4_sys_bus->bus_master_schregs","SCHREGS->APB_Slave");
//vista_bind(l4_sys_bus->bus_master_schregs, SCHREGS->APB_Slave);
//$end;
//$bind("fpga_split_bus->apb_master_sys","l4_sys_bus->bus_slave_fpgabridg");
//vista_bind(fpga_split_bus->apb_master_sys, l4_sys_bus->bus_slave_fpgabridg);
//$end;
//$bind("RSTMGR->n_i2c_rst_2","I2C2->Resetn");
//vista_bind(RSTMGR->n_i2c_rst_2, I2C2->Resetn);
//$end;
//$bind("UART1->IRQ","CORTEX_A9MP->irq_111");
//vista_bind(UART1->IRQ, CORTEX_A9MP->irq_111);
//$end;
//$bind("I2C2->IRQ","CORTEX_A9MP->irq_107");
//vista_bind(I2C2->IRQ, CORTEX_A9MP->irq_107);
//$end;
//$bind("fpga_split_bus->axi_master_l3","l3_interconnect->axi_slave0");
//vista_bind(fpga_split_bus->axi_master_l3, l3_interconnect->axi_slave0);
//$end;
//$bind("c8->ahb_master2","l3_interconnect->ahb_slave2");
//vista_bind(c8->ahb_master2, l3_interconnect->ahb_slave2);
//$end;
//$bind("SPIM0->RXDMA","DMAC->periph_req_17");
//vista_bind(SPIM0->RXDMA, DMAC->periph_req_17);
//$end;
//$bind("l3_interconnect->ahb_master0","c6->ahb_slave0");
//vista_bind(l3_interconnect->ahb_master0, c6->ahb_slave0);
//$end;
//$bind("l4_sys_bus->bus_master_fwocram","FWOCRAM->slave_reg");
//vista_bind(l4_sys_bus->bus_master_fwocram, FWOCRAM->slave_reg);
//$end;
//$bind("ext_inst->irq16","CORTEX_A9MP->irq_35");
//vista_bind(ext_inst->irq16, CORTEX_A9MP->irq_35);
//$end;
//$bind("DMA_SPLIT->output5","CORTEX_A9MP->irq_88");
//vista_bind(DMA_SPLIT->output5, CORTEX_A9MP->irq_88);
//$end;
//$bind("I2C2->DMA_RX","DMAC->periph_req_13");
//vista_bind(I2C2->DMA_RX, DMAC->periph_req_13);
//$end;
//$bind("ext_inst->irq28","CORTEX_A9MP->irq_47");
//vista_bind(ext_inst->irq28, CORTEX_A9MP->irq_47);
//$end;
//$bind("SPTIMER1->irq","CORTEX_A9MP->irq_116");
//vista_bind(SPTIMER1->irq, CORTEX_A9MP->irq_116);
//$end;
//$bind("ext_inst->irq54","CORTEX_A9MP->irq_73");
//vista_bind(ext_inst->irq54, CORTEX_A9MP->irq_73);
//$end;
//$bind("SPIM0->IRQ","CORTEX_A9MP->irq_101");
//vista_bind(SPIM0->IRQ, CORTEX_A9MP->irq_101);
//$end;
//$bind("ext_inst->irq8","CORTEX_A9MP->irq_27");
//vista_bind(ext_inst->irq8, CORTEX_A9MP->irq_27);
//$end;
//$bind("mpu_split_bus->axi_master_l3","l3_interconnect->axi_slave1");
//vista_bind(mpu_split_bus->axi_master_l3, l3_interconnect->axi_slave1);
//$end;
//$bind("l3_interconnect->axi_master6","c5->axi_slave4");
//vista_bind(l3_interconnect->axi_master6, c5->axi_slave4);
//$end;
//$bind("EMAC0->irq","CORTEX_A9MP->irq_92");
//vista_bind(EMAC0->irq, CORTEX_A9MP->irq_92);
//$end;
//$bind("GPIO2->irq","CORTEX_A9MP->irq_114");
//vista_bind(GPIO2->irq, CORTEX_A9MP->irq_114);
//$end;
//$bind("LWHPS2FPGA->AHB_Master_HPS2FPGA","HPS2FPGA->AHB_Slave");
//vista_bind(LWHPS2FPGA->AHB_Master_HPS2FPGA, HPS2FPGA->AHB_Slave);
//$end;
//$bind("RSTMGR->n_mpu_cpu_rst_0","CORTEX_A9MP->n_reset_0");
//vista_bind(RSTMGR->n_mpu_cpu_rst_0, CORTEX_A9MP->n_reset_0);
//$end;
//$bind("UART1->DMA_TX","DMAC->periph_req_30");
//vista_bind(UART1->DMA_TX, DMAC->periph_req_30);
//$end;
//    $elaboration_end;
//  $vlnv_assign_begin;
//m_library = "Arria_schematics";
//m_vendor = "";
//m_version = "";
//  $vlnv_assign_end;
//  }
//  ~Arria10_top() {
//    $destructor_begin;
//$destruct_component("FWOCRAM");
//delete FWOCRAM; FWOCRAM = 0;
//$end;
//$destruct_component("QSPI_port");
//delete QSPI_port; QSPI_port = 0;
//$end;
//$destruct_component("HMCREGS");
//delete HMCREGS; HMCREGS = 0;
//$end;
//$destruct_component("c6");
//delete c6; c6 = 0;
//$end;
//$destruct_component("dma_split_bus");
//delete dma_split_bus; dma_split_bus = 0;
//$end;
//$destruct_component("SYSMGR_CORE");
//delete SYSMGR_CORE; SYSMGR_CORE = 0;
//$end;
//$destruct_component("l4_sys_bus");
//delete l4_sys_bus; l4_sys_bus = 0;
//$end;
//$destruct_component("FWDDRL3");
//delete FWDDRL3; FWDDRL3 = 0;
//$end;
//$destruct_component("EMAC0");
//delete EMAC0; EMAC0 = 0;
//$end;
//$destruct_component("UART0");
//delete UART0; UART0 = 0;
//$end;
//$destruct_component("OCRAM");
//delete OCRAM; OCRAM = 0;
//$end;
//$destruct_component("DMA_SPLIT");
//delete DMA_SPLIT; DMA_SPLIT = 0;
//$end;
//$destruct_component("EMAC2");
//delete EMAC2; EMAC2 = 0;
//$end;
//$destruct_component("L4WD1");
//delete L4WD1; L4WD1 = 0;
//$end;
//$destruct_component("c8");
//delete c8; c8 = 0;
//$end;
//$destruct_component("SPIS0");
//delete SPIS0; SPIS0 = 0;
//$end;
//$destruct_component("SPIM1");
//delete SPIM1; SPIM1 = 0;
//$end;
//$destruct_component("FWL4SYS");
//delete FWL4SYS; FWL4SYS = 0;
//$end;
//$destruct_component("HMCAREGS");
//delete HMCAREGS; HMCAREGS = 0;
//$end;
//$destruct_component("SDMMC");
//delete SDMMC; SDMMC = 0;
//$end;
//$destruct_component("QSPI");
//delete QSPI; QSPI = 0;
//$end;
//$destruct_component("RSTMGR");
//delete RSTMGR; RSTMGR = 0;
//$end;
//$destruct_component("c5");
//delete c5; c5 = 0;
//$end;
//$destruct_component("I2C0");
//delete I2C0; I2C0 = 0;
//$end;
//$destruct_component("FPGAMGR");
//delete FPGAMGR; FPGAMGR = 0;
//$end;
//$destruct_component("CORTEX_A9MP");
//delete CORTEX_A9MP; CORTEX_A9MP = 0;
//$end;
//$destruct_component("GPIO1");
//delete GPIO1; GPIO1 = 0;
//$end;
//$destruct_component("LWHPS2FPGA");
//delete LWHPS2FPGA; LWHPS2FPGA = 0;
//$end;
//$destruct_component("I2C1");
//delete I2C1; I2C1 = 0;
//$end;
//$destruct_component("DMAC");
//delete DMAC; DMAC = 0;
//$end;
//$destruct_component("SPTIMER0");
//delete SPTIMER0; SPTIMER0 = 0;
//$end;
//$destruct_component("FWL4PER");
//delete FWL4PER; FWL4PER = 0;
//$end;
//$destruct_component("Console0");
//delete Console0; Console0 = 0;
//$end;
//$destruct_component("usb1");
//delete usb1; usb1 = 0;
//$end;
//$destruct_component("I2C2");
//delete I2C2; I2C2 = 0;
//$end;
//$destruct_component("EMAC1");
//delete EMAC1; EMAC1 = 0;
//$end;
//$destruct_component("UART1");
//delete UART1; UART1 = 0;
//$end;
//$destruct_component("mpu_split_bus");
//delete mpu_split_bus; mpu_split_bus = 0;
//$end;
//$destruct_component("IOMGR");
//delete IOMGR; IOMGR = 0;
//$end;
//$destruct_component("fpga_split_bus");
//delete fpga_split_bus; fpga_split_bus = 0;
//$end;
//$destruct_component("usb2");
//delete usb2; usb2 = 0;
//$end;
//$destruct_component("I2C3");
//delete I2C3; I2C3 = 0;
//$end;
//$destruct_component("l4_per_bus");
//delete l4_per_bus; l4_per_bus = 0;
//$end;
//$destruct_component("SPTIMER1");
//delete SPTIMER1; SPTIMER1 = 0;
//$end;
//$destruct_component("L4WD0");
//delete L4WD0; L4WD0 = 0;
//$end;
//$destruct_component("Console1");
//delete Console1; Console1 = 0;
//$end;
//$destruct_component("SPIM0");
//delete SPIM0; SPIM0 = 0;
//$end;
//$destruct_component("I2C4");
//delete I2C4; I2C4 = 0;
//$end;
//$destruct_component("ext_inst");
//delete ext_inst; ext_inst = 0;
//$end;
//$destruct_component("HPS2FPGA");
//delete HPS2FPGA; HPS2FPGA = 0;
//$end;
//$destruct_component("BROM");
//delete BROM; BROM = 0;
//$end;
//$destruct_component("SPIS1");
//delete SPIS1; SPIS1 = 0;
//$end;
//$destruct_component("CLKMGR");
//delete CLKMGR; CLKMGR = 0;
//$end;
//$destruct_component("FWFPGA2SDRAM");
//delete FWFPGA2SDRAM; FWFPGA2SDRAM = 0;
//$end;
//$destruct_component("OSC1TIMER0");
//delete OSC1TIMER0; OSC1TIMER0 = 0;
//$end;
//$destruct_component("OSC1TIMER1");
//delete OSC1TIMER1; OSC1TIMER1 = 0;
//$end;
//$destruct_component("GPIO0");
//delete GPIO0; GPIO0 = 0;
//$end;
//$destruct_component("l3_interconnect");
//delete l3_interconnect; l3_interconnect = 0;
//$end;
//$destruct_component("FPGA2HPS");
//delete FPGA2HPS; FPGA2HPS = 0;
//$end;
//$destruct_component("SYSMGRROM");
//delete SYSMGRROM; SYSMGRROM = 0;
//$end;
//$destruct_component("SCHREGS");
//delete SCHREGS; SCHREGS = 0;
//$end;
//$destruct_component("GPIO2");
//delete GPIO2; GPIO2 = 0;
//$end;
//    $destructor_end;
//  }
//public:
//  $fields_begin;
//$component("FWOCRAM");
//Arria_OCRAM_FireWall_pvt *FWOCRAM;
//$end;
//$component("QSPI_port");
//APB2AHB_pvt *QSPI_port;
//$end;
//$component("HMCREGS");
//Arria_HMC_MMR_pvt *HMCREGS;
//$end;
//$component("c6");
//Dummy2_pvt *c6;
//$end;
//$component("dma_split_bus");
//split_bus_pvt *dma_split_bus;
//$end;
//$component("SYSMGR_CORE");
//Arria_SYSMGR_CORE_pvt *SYSMGR_CORE;
//$end;
//$component("l4_sys_bus");
//L4_SYS_Bus_pvt *l4_sys_bus;
//$end;
//$component("FWDDRL3");
//Arria_DDRL3_FireWall_pvt *FWDDRL3;
//$end;
//$component("EMAC0");
//Arria_EMAC_pvt *EMAC0;
//$end;
//$component("UART0");
//Arria_UART_pvt *UART0;
//$end;
//$component("OCRAM");
//ocram_pvt *OCRAM;
//$end;
//$component("DMA_SPLIT");
//dma_irq_splitter_pvt *DMA_SPLIT;
//$end;
//$component("EMAC2");
//Arria_EMAC_pvt *EMAC2;
//$end;
//$component("L4WD1");
//Arria_L4WD_pvt *L4WD1;
//$end;
//$component("c8");
//Dummy3_pvt *c8;
//$end;
//$component("SPIS0");
//Arria_SPI_pvt *SPIS0;
//$end;
//$component("SPIM1");
//Arria_SPI_pvt *SPIM1;
//$end;
//$component("FWL4SYS");
//Arria_SYS_FireWall_pvt *FWL4SYS;
//$end;
//$component("HMCAREGS");
//Arria_SDRAM_Adapter_pvt *HMCAREGS;
//$end;
//$component("SDMMC");
//Arria_SDHC_pvt *SDMMC;
//$end;
//$component("QSPI");
//Arria_QSPI_pvt *QSPI;
//$end;
//$component("RSTMGR");
//Arria_RSTMGR_pvt *RSTMGR;
//$end;
//$component("c5");
//Dummy1_pvt *c5;
//$end;
//$component("I2C0");
//Arria_I2C_pvt *I2C0;
//$end;
//$component("FPGAMGR");
//Arria_FPGAMGR_pvt *FPGAMGR;
//$end;
//$component("CORTEX_A9MP");
//Cortex_A9MP_pvt *CORTEX_A9MP;
//$end;
//$component("GPIO1");
//Arria_GPIO_pvt *GPIO1;
//$end;
//$component("LWHPS2FPGA");
//Arria_LWHPS2FPGA_pvt *LWHPS2FPGA;
//$end;
//$component("I2C1");
//Arria_I2C_pvt *I2C1;
//$end;
//$component("DMAC");
//DMA330_pvt *DMAC;
//$end;
//$component("SPTIMER0");
//Arria_TIMER_pvt *SPTIMER0;
//$end;
//$component("FWL4PER");
//Arria_PER_FireWall_pvt *FWL4PER;
//$end;
//$component("Console0");
//CONSOLE_pvt *Console0;
//$end;
//$component("usb1");
//Arria_DWC_OTG_pvt *usb1;
//$end;
//$component("I2C2");
//Arria_I2C_pvt *I2C2;
//$end;
//$component("EMAC1");
//Arria_EMAC_pvt *EMAC1;
//$end;
//$component("UART1");
//Arria_UART_pvt *UART1;
//$end;
//$component("mpu_split_bus");
//split_bus_pvt *mpu_split_bus;
//$end;
//$component("IOMGR");
//Arria_IOMGR_pvt *IOMGR;
//$end;
//$component("fpga_split_bus");
//split_bus_pvt *fpga_split_bus;
//$end;
//$component("usb2");
//Arria_DWC_OTG_pvt *usb2;
//$end;
//$component("I2C3");
//Arria_I2C_pvt *I2C3;
//$end;
//$component("l4_per_bus");
//L4_PER_Bus_pvt *l4_per_bus;
//$end;
//$component("SPTIMER1");
//Arria_TIMER_pvt *SPTIMER1;
//$end;
//$component("L4WD0");
//Arria_L4WD_pvt *L4WD0;
//$end;
//$component("Console1");
//CONSOLE_pvt *Console1;
//$end;
//$component("SPIM0");
//Arria_SPI_pvt *SPIM0;
//$end;
//$component("I2C4");
//Arria_I2C_pvt *I2C4;
//$end;
//$component("ext_inst");
//external_function_pvt *ext_inst;
//$end;
//$component("HPS2FPGA");
//Arria_HPS2FPGA_pvt *HPS2FPGA;
//$end;
//$component("BROM");
//brom_pvt *BROM;
//$end;
//$component("SPIS1");
//Arria_SPI_pvt *SPIS1;
//$end;
//$component("CLKMGR");
//Arria_CLKMGR_pvt *CLKMGR;
//$end;
//$component("FWFPGA2SDRAM");
//Arria_DDR_FireWall_pvt *FWFPGA2SDRAM;
//$end;
//$component("OSC1TIMER0");
//Arria_TIMER_pvt *OSC1TIMER0;
//$end;
//$component("OSC1TIMER1");
//Arria_TIMER_pvt *OSC1TIMER1;
//$end;
//$component("GPIO0");
//Arria_GPIO_pvt *GPIO0;
//$end;
//$component("l3_interconnect");
//L3_Interconnect_pvt *l3_interconnect;
//$end;
//$component("FPGA2HPS");
//Arria_FPGA2HPS_pvt *FPGA2HPS;
//$end;
//$component("SYSMGRROM");
//Arria_SYSMGRROM_pvt *SYSMGRROM;
//$end;
//$component("SCHREGS");
//Arria_SDRAM_Scheduler_pvt *SCHREGS;
//$end;
//$component("GPIO2");
//Arria_GPIO_pvt *GPIO2;
//$end;
//  $fields_end;
//  $vlnv_decl_begin;
//public:
//const char* m_library;
//const char* m_vendor;
//const char* m_version;
//  $vlnv_decl_end;
//};
//$module_end;
$module_begin("Stratix10_hps");
SC_MODULE(Stratix10_hps) {
public:
  typedef Stratix10_hps SC_CURRENT_USER_MODULE;
  Stratix10_hps(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("irq_23"),
irq_23("irq_23")
$end
$init("irq_21"),
irq_21("irq_21")
$end
$init("irq_19"),
irq_19("irq_19")
$end
$init("FPGA2HPS_AXI"),
FPGA2HPS_AXI("FPGA2HPS_AXI")
$end
$init("irq_24"),
irq_24("irq_24")
$end
$init("irq_22"),
irq_22("irq_22")
$end
$init("irq_20"),
irq_20("irq_20")
$end
$init("irq_25"),
irq_25("irq_25")
$end
$init("HPS2FPGA_AXI"),
HPS2FPGA_AXI("HPS2FPGA_AXI")
$end
$init("LWHPS2FPGA_AXI"),
LWHPS2FPGA_AXI("LWHPS2FPGA_AXI")
$end
$init("FWOCRAM"),
FWOCRAM(0)
$end
$init("HMCREGS"),
HMCREGS(0)
$end
$init("c6"),
c6(0)
$end
$init("dma_split_bus"),
dma_split_bus(0)
$end
$init("SYSMGR_CORE"),
SYSMGR_CORE(0)
$end
$init("l4_sys_bus"),
l4_sys_bus(0)
$end
$init("FWDDRL3"),
FWDDRL3(0)
$end
$init("EMAC0"),
EMAC0(0)
$end
$init("UART0"),
UART0(0)
$end
$init("OCRAM"),
OCRAM(0)
$end
$init("DMA_SPLIT"),
DMA_SPLIT(0)
$end
$init("EMAC2"),
EMAC2(0)
$end
$init("CPU"),
CPU(0)
$end
$init("L4WD1"),
L4WD1(0)
$end
$init("c8"),
c8(0)
$end
$init("SPIS0"),
SPIS0(0)
$end
$init("SPIM1"),
SPIM1(0)
$end
$init("L4WD3"),
L4WD3(0)
$end
$init("FWL4SYS"),
FWL4SYS(0)
$end
$init("HMCAREGS"),
HMCAREGS(0)
$end
$init("SDMMC"),
SDMMC(0)
$end
$init("RSTMGR"),
RSTMGR(0)
$end
$init("c5"),
c5(0)
$end
$init("I2C0"),
I2C0(0)
$end
$init("FPGAMGR"),
FPGAMGR(0)
$end
$init("GPIO1"),
GPIO1(0)
$end
$init("LWHPS2FPGA"),
LWHPS2FPGA(0)
$end
$init("I2C1"),
I2C1(0)
$end
$init("DMAC"),
DMAC(0)
$end
$init("SPTIMER0"),
SPTIMER0(0)
$end
$init("FWL4PER"),
FWL4PER(0)
$end
$init("Console0"),
Console0(0)
$end
$init("usb1"),
usb1(0)
$end
$init("I2C2"),
I2C2(0)
$end
$init("EMAC1"),
EMAC1(0)
$end
$init("UART1"),
UART1(0)
$end
$init("mpu_split_bus"),
mpu_split_bus(0)
$end
$init("IOMGR"),
IOMGR(0)
$end
$init("fpga_split_bus"),
fpga_split_bus(0)
$end
$init("usb2"),
usb2(0)
$end
$init("I2C3"),
I2C3(0)
$end
$init("l4_per_bus"),
l4_per_bus(0)
$end
$init("SPTIMER1"),
SPTIMER1(0)
$end
$init("L4WD0"),
L4WD0(0)
$end
$init("Console1"),
Console1(0)
$end
$init("SPIM0"),
SPIM0(0)
$end
$init("I2C4"),
I2C4(0)
$end
$init("L4WD2"),
L4WD2(0)
$end
$init("HPS2FPGA"),
HPS2FPGA(0)
$end
$init("SPIS1"),
SPIS1(0)
$end
$init("CLKMGR"),
CLKMGR(0)
$end
$init("FWFPGA2SDRAM"),
FWFPGA2SDRAM(0)
$end
$init("ss_n_reset_1"),
ss_n_reset_1(0)
$end
$init("ss_n_reset_2"),
ss_n_reset_2(0)
$end
$init("ss_n_reset_3"),
ss_n_reset_3(0)
$end
$init("OSC1TIMER0"),
OSC1TIMER0(0)
$end
$init("OSC1TIMER1"),
OSC1TIMER1(0)
$end
$init("GPIO0"),
GPIO0(0)
$end
$init("l3_interconnect"),
l3_interconnect(0)
$end
$init("FPGA2HPS"),
FPGA2HPS(0)
$end
$init("SYSMGRROM"),
SYSMGRROM(0)
$end
$init("SCHREGS"),
SCHREGS(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("FWOCRAM");
FWOCRAM = new Arria_OCRAM_FireWall_pvt("FWOCRAM");
$end;
$create_component("HMCREGS");
HMCREGS = new Arria_HMC_MMR_pvt("HMCREGS");
$end;
$create_component("c6");
c6 = new Dummy2_pvt("c6");
$end;
$create_component("dma_split_bus");
dma_split_bus = new split_bus_pvt("dma_split_bus");
$end;
$create_component("SYSMGR_CORE");
SYSMGR_CORE = new Arria_SYSMGR_CORE_pvt("SYSMGR_CORE");
$end;
$create_component("l4_sys_bus");
l4_sys_bus = new L4_SYS_Bus_pvt("l4_sys_bus");
$end;
$create_component("FWDDRL3");
FWDDRL3 = new Arria_DDRL3_FireWall_pvt("FWDDRL3");
$end;
$create_component("EMAC0");
EMAC0 = new Arria_EMAC_pvt("EMAC0");
$end;
$create_component("UART0");
UART0 = new Arria_UART_pvt("UART0");
$end;
$create_component("OCRAM");
OCRAM = new ocram_pvt("OCRAM");
$end;
$create_component("DMA_SPLIT");
DMA_SPLIT = new dma_irq_splitter_pvt("DMA_SPLIT");
$end;
$create_component("EMAC2");
EMAC2 = new Arria_EMAC_pvt("EMAC2");
$end;
$create_component("CPU");
CPU = new ARMv8_CoreTile("CPU");
$end;
$create_component("L4WD1");
L4WD1 = new Arria_L4WD_pvt("L4WD1");
$end;
$create_component("c8");
c8 = new Dummy3_pvt("c8");
$end;
$create_component("SPIS0");
SPIS0 = new Arria_SPI_pvt("SPIS0");
$end;
$create_component("SPIM1");
SPIM1 = new Arria_SPI_pvt("SPIM1");
$end;
$create_component("L4WD3");
L4WD3 = new Arria_L4WD_pvt("L4WD3");
$end;
$create_component("FWL4SYS");
FWL4SYS = new Arria_SYS_FireWall_pvt("FWL4SYS");
$end;
$create_component("HMCAREGS");
HMCAREGS = new Arria_SDRAM_Adapter_pvt("HMCAREGS");
$end;
$create_component("SDMMC");
SDMMC = new Arria_SDHC_pvt("SDMMC");
$end;
$create_component("RSTMGR");
RSTMGR = new Arria_RSTMGR_pvt("RSTMGR");
$end;
$create_component("c5");
c5 = new Dummy1_pvt("c5");
$end;
$create_component("I2C0");
I2C0 = new Arria_I2C_pvt("I2C0");
$end;
$create_component("FPGAMGR");
FPGAMGR = new Arria_FPGAMGR_pvt("FPGAMGR");
$end;
$create_component("GPIO1");
GPIO1 = new Arria_GPIO_pvt("GPIO1");
$end;
$create_component("LWHPS2FPGA");
LWHPS2FPGA = new Arria_LWHPS2FPGA_pvt("LWHPS2FPGA");
$end;
$create_component("I2C1");
I2C1 = new Arria_I2C_pvt("I2C1");
$end;
$create_component("DMAC");
DMAC = new DMA330_pvt("DMAC");
$end;
$create_component("SPTIMER0");
SPTIMER0 = new Arria_TIMER_pvt("SPTIMER0");
$end;
$create_component("FWL4PER");
FWL4PER = new Arria_PER_FireWall_pvt("FWL4PER");
$end;
$create_component("Console0");
Console0 = new CONSOLE_pvt("Console0");
$end;
$create_component("usb1");
usb1 = new Arria_DWC_OTG_pvt("usb1");
$end;
$create_component("I2C2");
I2C2 = new Arria_I2C_pvt("I2C2");
$end;
$create_component("EMAC1");
EMAC1 = new Arria_EMAC_pvt("EMAC1");
$end;
$create_component("UART1");
UART1 = new Arria_UART_pvt("UART1");
$end;
$create_component("mpu_split_bus");
mpu_split_bus = new split_bus_pvt("mpu_split_bus");
$end;
$create_component("IOMGR");
IOMGR = new Arria_IOMGR_pvt("IOMGR");
$end;
$create_component("fpga_split_bus");
fpga_split_bus = new split_bus_pvt("fpga_split_bus");
$end;
$create_component("usb2");
usb2 = new Arria_DWC_OTG_pvt("usb2");
$end;
$create_component("I2C3");
I2C3 = new Arria_I2C_pvt("I2C3");
$end;
$create_component("l4_per_bus");
l4_per_bus = new L4_PER_Bus_pvt("l4_per_bus");
$end;
$create_component("SPTIMER1");
SPTIMER1 = new Arria_TIMER_pvt("SPTIMER1");
$end;
$create_component("L4WD0");
L4WD0 = new Arria_L4WD_pvt("L4WD0");
$end;
$create_component("Console1");
Console1 = new CONSOLE_pvt("Console1");
$end;
$create_component("SPIM0");
SPIM0 = new Arria_SPI_pvt("SPIM0");
$end;
$create_component("I2C4");
I2C4 = new Arria_I2C_pvt("I2C4");
$end;
$create_component("L4WD2");
L4WD2 = new Arria_L4WD_pvt("L4WD2");
$end;
$create_component("HPS2FPGA");
HPS2FPGA = new Arria_HPS2FPGA_pvt("HPS2FPGA");
$end;
$create_component("SPIS1");
SPIS1 = new Arria_SPI_pvt("SPIS1");
$end;
$create_component("CLKMGR");
CLKMGR = new Arria_CLKMGR_pvt("CLKMGR");
$end;
$create_component("FWFPGA2SDRAM");
FWFPGA2SDRAM = new Arria_DDR_FireWall_pvt("FWFPGA2SDRAM");
$end;
$create_component("ss_n_reset_1");
ss_n_reset_1 = new signal_source_pvt("ss_n_reset_1");
$end;
$create_component("ss_n_reset_2");
ss_n_reset_2 = new signal_source_pvt("ss_n_reset_2");
$end;
$create_component("ss_n_reset_3");
ss_n_reset_3 = new signal_source_pvt("ss_n_reset_3");
$end;
$create_component("OSC1TIMER0");
OSC1TIMER0 = new Arria_TIMER_pvt("OSC1TIMER0");
$end;
$create_component("OSC1TIMER1");
OSC1TIMER1 = new Arria_TIMER_pvt("OSC1TIMER1");
$end;
$create_component("GPIO0");
GPIO0 = new Arria_GPIO_pvt("GPIO0");
$end;
$create_component("l3_interconnect");
l3_interconnect = new L3_Interconnect_pvt("l3_interconnect");
$end;
$create_component("FPGA2HPS");
FPGA2HPS = new Arria_FPGA2HPS_pvt("FPGA2HPS");
$end;
$create_component("SYSMGRROM");
SYSMGRROM = new Arria_SYSMGRROM_pvt("SYSMGRROM");
$end;
$create_component("SCHREGS");
SCHREGS = new Arria_SDRAM_Scheduler_pvt("SCHREGS");
$end;
$bind("l4_sys_bus->bus_master_hmcaregs","HMCAREGS->Slave0");
vista_bind(l4_sys_bus->bus_master_hmcaregs, HMCAREGS->Slave0);
$end;
$bind("irq_21","CPU->irq_21");
vista_bind(irq_21, CPU->irq_21);
$end;
$bind("I2C4->IRQ","CPU->irq_18");
vista_bind(I2C4->IRQ, CPU->irq_18);
$end;
$bind("irq_19","CPU->irq_19");
vista_bind(irq_19, CPU->irq_19);
$end;
$bind("l4_per_bus->bus_master_sdmmc","SDMMC->APB");
vista_bind(l4_per_bus->bus_master_sdmmc, SDMMC->APB);
$end;
$bind("FWFPGA2SDRAM->master_port_f2s0","SCHREGS->AXI2_Slave");
vista_bind(FWFPGA2SDRAM->master_port_f2s0, SCHREGS->AXI2_Slave);
$end;
$bind("RSTMGR->n_mpu_cpu_rst_0","CPU->n_reset_0");
vista_bind(RSTMGR->n_mpu_cpu_rst_0, CPU->n_reset_0);
$end;
$bind("I2C2->IRQ","CPU->irq_105");
vista_bind(I2C2->IRQ, CPU->irq_105);
$end;
$bind("UART0->TX","Console0->RX");
vista_bind(UART0->TX, Console0->RX);
$end;
$bind("usb1->master","l3_interconnect->axi_slave_7");
vista_bind(usb1->master, l3_interconnect->axi_slave_7);
$end;
$bind("DMA_SPLIT->output5","CPU->irq_86");
vista_bind(DMA_SPLIT->output5, CPU->irq_86);
$end;
$bind("l4_per_bus->bus_master_i2c4","I2C4->APB_Slave");
vista_bind(l4_per_bus->bus_master_i2c4, I2C4->APB_Slave);
$end;
$bind("c8->ahb_master1","l3_interconnect->ahb_slave1");
vista_bind(c8->ahb_master1, l3_interconnect->ahb_slave1);
$end;
$bind("I2C3->DMA_RX","DMAC->periph_req_15");
vista_bind(I2C3->DMA_RX, DMAC->periph_req_15);
$end;
$bind("FWOCRAM->master_port","OCRAM->slave");
vista_bind(FWOCRAM->master_port, OCRAM->slave);
$end;
$bind("l4_per_bus->bus_master_dmanonsecure","DMAC->APB_NonSecure_slave");
vista_bind(l4_per_bus->bus_master_dmanonsecure, DMAC->APB_NonSecure_slave);
$end;
$bind("l4_sys_bus->bus_master_clkmgr","CLKMGR->APB");
vista_bind(l4_sys_bus->bus_master_clkmgr, CLKMGR->APB);
$end;
$bind("FPGA2HPS->AXI_master","fpga_split_bus->axi_slave0");
vista_bind(FPGA2HPS->AXI_master, fpga_split_bus->axi_slave0);
$end;
$bind("SPTIMER1->irq","CPU->irq_114");
vista_bind(SPTIMER1->irq, CPU->irq_114);
$end;
$bind("SPIS1->RXDMA","DMAC->periph_req_23");
vista_bind(SPIS1->RXDMA, DMAC->periph_req_23);
$end;
$bind("DMAC->irq","DMA_SPLIT->input");
vista_bind(DMAC->irq, DMA_SPLIT->input);
$end;
$bind("RSTMGR->n_spim_rst_0","SPIM0->Resetn");
vista_bind(RSTMGR->n_spim_rst_0, SPIM0->Resetn);
$end;
$bind("l3_interconnect->axi_master3","c5->axi_slave1");
vista_bind(l3_interconnect->axi_master3, c5->axi_slave1);
$end;
$bind("c8->axi_master5","l3_interconnect->axi_slave6");
vista_bind(c8->axi_master5, l3_interconnect->axi_slave6);
$end;
$bind("l3_interconnect->ahb_master1","c6->ahb_slave1");
vista_bind(l3_interconnect->ahb_master1, c6->ahb_slave1);
$end;
$bind("I2C3->IRQ","CPU->irq_106");
vista_bind(I2C3->IRQ, CPU->irq_106);
$end;
$bind("RSTMGR->n_dma_rst","DMAC->aresetn");
vista_bind(RSTMGR->n_dma_rst, DMAC->aresetn);
$end;
$bind("RSTMGR->n_spim_rst_1","SPIM1->Resetn");
vista_bind(RSTMGR->n_spim_rst_1, SPIM1->Resetn);
$end;
$bind("UART1->TX","Console1->RX");
vista_bind(UART1->TX, Console1->RX);
$end;
$bind("RSTMGR->n_osc1_timer_rst_1","OSC1TIMER1->reset");
vista_bind(RSTMGR->n_osc1_timer_rst_1, OSC1TIMER1->reset);
$end;
$bind("I2C1->DMA_TX","DMAC->periph_req_10");
vista_bind(I2C1->DMA_TX, DMAC->periph_req_10);
$end;
$bind("dma_split_bus->apb_master_sys","l4_sys_bus->bus_slave_dmac");
vista_bind(dma_split_bus->apb_master_sys, l4_sys_bus->bus_slave_dmac);
$end;
$bind("HMCAREGS->Master1","HMCREGS->Slave2");
vista_bind(HMCAREGS->Master1, HMCREGS->Slave2);
$end;
$bind("l3_interconnect->apb_master5","c6->apb_slave3");
vista_bind(l3_interconnect->apb_master5, c6->apb_slave3);
$end;
$bind("RSTMGR->n_i2c_rst_3","I2C3->Resetn");
vista_bind(RSTMGR->n_i2c_rst_3, I2C3->Resetn);
$end;
$bind("ss_n_reset_3->out","CPU->n_reset_3");
vista_bind(ss_n_reset_3->out, CPU->n_reset_3);
$end;
$bind("DMA_SPLIT->output7","CPU->irq_88");
vista_bind(DMA_SPLIT->output7, CPU->irq_88);
$end;
$bind("Console1->TX","UART1->RX");
vista_bind(Console1->TX, UART1->RX);
$end;
$bind("l3_interconnect->axi_master11","usb1->slave");
vista_bind(l3_interconnect->axi_master11, usb1->slave);
$end;
$bind("l3_interconnect->axi_master1","HPS2FPGA->AXI_Slave");
vista_bind(l3_interconnect->axi_master1, HPS2FPGA->AXI_Slave);
$end;
$bind("DMA_SPLIT->output0","CPU->irq_81");
vista_bind(DMA_SPLIT->output0, CPU->irq_81);
$end;
$bind("FWFPGA2SDRAM->master_port_mpu","SCHREGS->AXI1_Slave");
vista_bind(FWFPGA2SDRAM->master_port_mpu, SCHREGS->AXI1_Slave);
$end;
$bind("EMAC1->irq","CPU->irq_91");
vista_bind(EMAC1->irq, CPU->irq_91);
$end;
$bind("fpga_split_bus->apb_master_per","l4_per_bus->bus_slave_fpgabridg");
vista_bind(fpga_split_bus->apb_master_per, l4_per_bus->bus_slave_fpgabridg);
$end;
$bind("DMA_SPLIT->output6","CPU->irq_87");
vista_bind(DMA_SPLIT->output6, CPU->irq_87);
$end;
$bind("LWHPS2FPGA->AHB_Master_FPGA2HPS","FPGA2HPS->AHB_slave");
vista_bind(LWHPS2FPGA->AHB_Master_FPGA2HPS, FPGA2HPS->AHB_slave);
$end;
$bind("L4WD0->irq","CPU->irq_117");
vista_bind(L4WD0->irq, CPU->irq_117);
$end;
$bind("l3_interconnect->axi_master2","FWDDRL3->slave_port");
vista_bind(l3_interconnect->axi_master2, FWDDRL3->slave_port);
$end;
$bind("HMCAREGS->Master0","HMCREGS->Slave1");
vista_bind(HMCAREGS->Master0, HMCREGS->Slave1);
$end;
$bind("SYSMGR_CORE->irq_ns","DMAC->boot_irq_ns");
vista_bind(SYSMGR_CORE->irq_ns, DMAC->boot_irq_ns);
$end;
$bind("I2C2->DMA_TX","DMAC->periph_req_12");
vista_bind(I2C2->DMA_TX, DMAC->periph_req_12);
$end;
$bind("l4_sys_bus->bus_master_hmcregs","HMCREGS->Slave0");
vista_bind(l4_sys_bus->bus_master_hmcregs, HMCREGS->Slave0);
$end;
$bind("UART0->IRQ","CPU->irq_108");
vista_bind(UART0->IRQ, CPU->irq_108);
$end;
$bind("FWFPGA2SDRAM->master_port_f2s1","SCHREGS->AXI3_Slave");
vista_bind(FWFPGA2SDRAM->master_port_f2s1, SCHREGS->AXI3_Slave);
$end;
$bind("l4_sys_bus->bus_master_fwddrl3","FWDDRL3->slave_reg");
vista_bind(l4_sys_bus->bus_master_fwddrl3, FWDDRL3->slave_reg);
$end;
$bind("FWL4SYS->out0","l4_sys_bus->security");
vista_bind(FWL4SYS->out0, l4_sys_bus->security);
$end;
$bind("l4_per_bus->bus_master_sptimer1","SPTIMER1->apb");
vista_bind(l4_per_bus->bus_master_sptimer1, SPTIMER1->apb);
$end;
$bind("EMAC0->AXI","l3_interconnect->axi_slave3");
vista_bind(EMAC0->AXI, l3_interconnect->axi_slave3);
$end;
$bind("l4_sys_bus->bus_master_osc1timer0","OSC1TIMER0->apb");
vista_bind(l4_sys_bus->bus_master_osc1timer0, OSC1TIMER0->apb);
$end;
$bind("dma_split_bus->apb_master_per","l4_per_bus->bus_slave_dmac");
vista_bind(dma_split_bus->apb_master_per, l4_per_bus->bus_slave_dmac);
$end;
$bind("l3_interconnect->apb_master2","c6->apb_slave1");
vista_bind(l3_interconnect->apb_master2, c6->apb_slave1);
$end;
$bind("l4_per_bus->bus_master_emac2","EMAC2->apb");
vista_bind(l4_per_bus->bus_master_emac2, EMAC2->apb);
$end;
$bind("UART0->DMA_RX","DMAC->periph_req_29");
vista_bind(UART0->DMA_RX, DMAC->periph_req_29);
$end;
$bind("SPIM0->TXDMA","DMAC->periph_req_16");
vista_bind(SPIM0->TXDMA, DMAC->periph_req_16);
$end;
$bind("OSC1TIMER0->irq","CPU->irq_115");
vista_bind(OSC1TIMER0->irq, CPU->irq_115);
$end;
$bind("I2C3->DMA_TX","DMAC->periph_req_14");
vista_bind(I2C3->DMA_TX, DMAC->periph_req_14);
$end;
$bind("LWHPS2FPGA->AXI_Master","LWHPS2FPGA_AXI");
vista_bind(LWHPS2FPGA->AXI_Master, LWHPS2FPGA_AXI);
$end;
$bind("ss_n_reset_2->out","CPU->n_reset_2");
vista_bind(ss_n_reset_2->out, CPU->n_reset_2);
$end;
$bind("l3_interconnect->axi_master7","c5->axi_slave5");
vista_bind(l3_interconnect->axi_master7, c5->axi_slave5);
$end;
$bind("SPIS0->IRQ","CPU->irq_99");
vista_bind(SPIS0->IRQ, CPU->irq_99);
$end;
$bind("DMA_SPLIT->output8","CPU->irq_89");
vista_bind(DMA_SPLIT->output8, CPU->irq_89);
$end;
$bind("L4WD2->irq","CPU->irq_125");
vista_bind(L4WD2->irq, CPU->irq_125);
$end;
$bind("EMAC2->AXI","l3_interconnect->axi_slave5");
vista_bind(EMAC2->AXI, l3_interconnect->axi_slave5);
$end;
$bind("irq_24","CPU->irq_24");
vista_bind(irq_24, CPU->irq_24);
$end;
$bind("SDMMC->IRQ","CPU->irq_96");
vista_bind(SDMMC->IRQ, CPU->irq_96);
$end;
$bind("DMA_SPLIT->output1","CPU->irq_82");
vista_bind(DMA_SPLIT->output1, CPU->irq_82);
$end;
$bind("dma_split_bus->axi_master_l3","l3_interconnect->axi_slave2");
vista_bind(dma_split_bus->axi_master_l3, l3_interconnect->axi_slave2);
$end;
$bind("l4_sys_bus->bus_master_l4wd3","L4WD3->APB");
vista_bind(l4_sys_bus->bus_master_l4wd3, L4WD3->APB);
$end;
$bind("mpu_split_bus->apb_master_sys","l4_sys_bus->bus_slave_mpu");
vista_bind(mpu_split_bus->apb_master_sys, l4_sys_bus->bus_slave_mpu);
$end;
$bind("UART0->DMA_TX","DMAC->periph_req_28");
vista_bind(UART0->DMA_TX, DMAC->periph_req_28);
$end;
$bind("GPIO0->irq","CPU->irq_110");
vista_bind(GPIO0->irq, CPU->irq_110);
$end;
$bind("l4_per_bus->bus_master_gpio1","GPIO1->slave");
vista_bind(l4_per_bus->bus_master_gpio1, GPIO1->slave);
$end;
$bind("RSTMGR->n_i2c_rst_4","I2C4->Resetn");
vista_bind(RSTMGR->n_i2c_rst_4, I2C4->Resetn);
$end;
$bind("I2C0->DMA_TX","DMAC->periph_req_8");
vista_bind(I2C0->DMA_TX, DMAC->periph_req_8);
$end;
$bind("SPIM1->IRQ","CPU->irq_102");
vista_bind(SPIM1->IRQ, CPU->irq_102);
$end;
$bind("l3_interconnect->axi_master12","usb2->slave");
vista_bind(l3_interconnect->axi_master12, usb2->slave);
$end;
$bind("l4_per_bus->bus_master_gpio0","GPIO0->slave");
vista_bind(l4_per_bus->bus_master_gpio0, GPIO0->slave);
$end;
$bind("Console0->TX","UART0->RX");
vista_bind(Console0->TX, UART0->RX);
$end;
$bind("l4_per_bus->bus_master_emac1","EMAC1->apb");
vista_bind(l4_per_bus->bus_master_emac1, EMAC1->apb);
$end;
$bind("SPIS1->TXDMA","DMAC->periph_req_22");
vista_bind(SPIS1->TXDMA, DMAC->periph_req_22);
$end;
$bind("RSTMGR->n_i2c_rst_0","I2C0->Resetn");
vista_bind(RSTMGR->n_i2c_rst_0, I2C0->Resetn);
$end;
$bind("irq_22","CPU->irq_22");
vista_bind(irq_22, CPU->irq_22);
$end;
$bind("SPIS0->RXDMA","DMAC->periph_req_19");
vista_bind(SPIS0->RXDMA, DMAC->periph_req_19);
$end;
$bind("l3_interconnect->axi_master4","c5->axi_slave7");
vista_bind(l3_interconnect->axi_master4, c5->axi_slave7);
$end;
$bind("FWL4PER->out0","l4_per_bus->security");
vista_bind(FWL4PER->out0, l4_per_bus->security);
$end;
$bind("RSTMGR->n_gpio_rst_0","GPIO0->Resetn");
vista_bind(RSTMGR->n_gpio_rst_0, GPIO0->Resetn);
$end;
$bind("mpu_split_bus->apb_master_per","l4_per_bus->bus_slave_mpu");
vista_bind(mpu_split_bus->apb_master_per, l4_per_bus->bus_slave_mpu);
$end;
$bind("l3_interconnect->apb_master1","l4_per_bus->bus_slave_l3");
vista_bind(l3_interconnect->apb_master1, l4_per_bus->bus_slave_l3);
$end;
$bind("l4_sys_bus->bus_master_fwl4sys","FWL4SYS->slave_reg");
vista_bind(l4_sys_bus->bus_master_fwl4sys, FWL4SYS->slave_reg);
$end;
$bind("ss_n_reset_1->out","CPU->n_reset_1");
vista_bind(ss_n_reset_1->out, CPU->n_reset_1);
$end;
$bind("SYSMGR_CORE->mgr_ns","DMAC->boot_manager_ns");
vista_bind(SYSMGR_CORE->mgr_ns, DMAC->boot_manager_ns);
$end;
$bind("l4_per_bus->bus_master_spi1","SPIS1->APB");
vista_bind(l4_per_bus->bus_master_spi1, SPIS1->APB);
$end;
$bind("l4_per_bus->bus_master_uart1","UART1->APB_Port");
vista_bind(l4_per_bus->bus_master_uart1, UART1->APB_Port);
$end;
$bind("FPGA2HPS_AXI","FPGA2HPS->AXI_slave");
vista_bind(FPGA2HPS_AXI, FPGA2HPS->AXI_slave);
$end;
$bind("l4_sys_bus->bus_master_l4wd2","L4WD2->APB");
vista_bind(l4_sys_bus->bus_master_l4wd2, L4WD2->APB);
$end;
$bind("SPIM1->RXDMA","DMAC->periph_req_21");
vista_bind(SPIM1->RXDMA, DMAC->periph_req_21);
$end;
$bind("DMA_SPLIT->output2","CPU->irq_83");
vista_bind(DMA_SPLIT->output2, CPU->irq_83);
$end;
$bind("I2C0->DMA_RX","DMAC->periph_req_9");
vista_bind(I2C0->DMA_RX, DMAC->periph_req_9);
$end;
$bind("irq_20","CPU->irq_20");
vista_bind(irq_20, CPU->irq_20);
$end;
$bind("l4_per_bus->bus_master_emac0","EMAC0->apb");
vista_bind(l4_per_bus->bus_master_emac0, EMAC0->apb);
$end;
$bind("l4_sys_bus->bus_master_fpgamgrregs","FPGAMGR->APB");
vista_bind(l4_sys_bus->bus_master_fpgamgrregs, FPGAMGR->APB);
$end;
$bind("RSTMGR->IRQ","CPU->irq_120");
vista_bind(RSTMGR->IRQ, CPU->irq_120);
$end;
$bind("l4_sys_bus->bus_master_osc1timer1","OSC1TIMER1->apb");
vista_bind(l4_sys_bus->bus_master_osc1timer1, OSC1TIMER1->apb);
$end;
$bind("l3_interconnect->axi_master0","FWOCRAM->slave_port");
vista_bind(l3_interconnect->axi_master0, FWOCRAM->slave_port);
$end;
$bind("usb1->irq","CPU->irq_93");
vista_bind(usb1->irq, CPU->irq_93);
$end;
$bind("l4_sys_bus->bus_master_rstmgr","RSTMGR->APB_A10");
vista_bind(l4_sys_bus->bus_master_rstmgr, RSTMGR->APB_A10);
$end;
$bind("RSTMGR->n_sdmmc_rst","SDMMC->Resetn");
vista_bind(RSTMGR->n_sdmmc_rst, SDMMC->Resetn);
$end;
$bind("l4_sys_bus->bus_master_sysmgrrom","SYSMGRROM->slave");
vista_bind(l4_sys_bus->bus_master_sysmgrrom, SYSMGRROM->slave);
$end;
$bind("RSTMGR->n_spis_rst_0","SPIS0->Resetn");
vista_bind(RSTMGR->n_spis_rst_0, SPIS0->Resetn);
$end;
$bind("RSTMGR->n_mpu_periph_rst","CPU->n_periph_reset");
vista_bind(RSTMGR->n_mpu_periph_rst, CPU->n_periph_reset);
$end;
$bind("RSTMGR->n_sp_timer_rst_1","SPTIMER1->reset");
vista_bind(RSTMGR->n_sp_timer_rst_1, SPTIMER1->reset);
$end;
$bind("RSTMGR->n_osc1_timer_rst_0","OSC1TIMER0->reset");
vista_bind(RSTMGR->n_osc1_timer_rst_0, OSC1TIMER0->reset);
$end;
$bind("l4_per_bus->bus_master_spi0","SPIS0->APB");
vista_bind(l4_per_bus->bus_master_spi0, SPIS0->APB);
$end;
$bind("l4_per_bus->bus_master_i2c0","I2C0->APB_Slave");
vista_bind(l4_per_bus->bus_master_i2c0, I2C0->APB_Slave);
$end;
$bind("l3_interconnect->apb_master3","c6->apb_slave2");
vista_bind(l3_interconnect->apb_master3, c6->apb_slave2);
$end;
$bind("l4_sys_bus->bus_master_l4wd1","L4WD1->APB");
vista_bind(l4_sys_bus->bus_master_l4wd1, L4WD1->APB);
$end;
$bind("l4_per_bus->bus_master_uart0","UART0->APB_Port");
vista_bind(l4_per_bus->bus_master_uart0, UART0->APB_Port);
$end;
$bind("EMAC0->irq","CPU->irq_90");
vista_bind(EMAC0->irq, CPU->irq_90);
$end;
$bind("FWFPGA2SDRAM->master_port_f2s2","SCHREGS->AXI4_Slave");
vista_bind(FWFPGA2SDRAM->master_port_f2s2, SCHREGS->AXI4_Slave);
$end;
$bind("usb2->irq","CPU->irq_94");
vista_bind(usb2->irq, CPU->irq_94);
$end;
$bind("RSTMGR->n_i2c_rst_1","I2C1->Resetn");
vista_bind(RSTMGR->n_i2c_rst_1, I2C1->Resetn);
$end;
$bind("l3_interconnect->axi_master8","c5->axi_slave6");
vista_bind(l3_interconnect->axi_master8, c5->axi_slave6);
$end;
$bind("l4_per_bus->bus_master_i2c1","I2C1->APB_Slave");
vista_bind(l4_per_bus->bus_master_i2c1, I2C1->APB_Slave);
$end;
$bind("usb2->master","l3_interconnect->axi_slave8");
vista_bind(usb2->master, l3_interconnect->axi_slave8);
$end;
$bind("l3_interconnect->axi_master10","c5->axi_slave3");
vista_bind(l3_interconnect->axi_master10, c5->axi_slave3);
$end;
$bind("RSTMGR->n_gpio_rst_1","GPIO1->Resetn");
vista_bind(RSTMGR->n_gpio_rst_1, GPIO1->Resetn);
$end;
$bind("DMA_SPLIT->output3","CPU->irq_84");
vista_bind(DMA_SPLIT->output3, CPU->irq_84);
$end;
$bind("l3_interconnect->axi_master5","LWHPS2FPGA->AXI_Slave");
vista_bind(l3_interconnect->axi_master5, LWHPS2FPGA->AXI_Slave);
$end;
$bind("FPGAMGR->DMA_WR","DMAC->periph_req_27");
vista_bind(FPGAMGR->DMA_WR, DMAC->periph_req_27);
$end;
$bind("RSTMGR->n_fpga_manager_rst","FPGAMGR->Resetn");
vista_bind(RSTMGR->n_fpga_manager_rst, FPGAMGR->Resetn);
$end;
$bind("l4_per_bus->bus_master_i2c2","I2C2->APB_Slave");
vista_bind(l4_per_bus->bus_master_i2c2, I2C2->APB_Slave);
$end;
$bind("EMAC2->irq","CPU->irq_92");
vista_bind(EMAC2->irq, CPU->irq_92);
$end;
$bind("l4_per_bus->bus_master_spi3","SPIM1->APB");
vista_bind(l4_per_bus->bus_master_spi3, SPIM1->APB);
$end;
$bind("l4_sys_bus->bus_master_fwl4per","FWL4PER->slave_reg");
vista_bind(l4_sys_bus->bus_master_fwl4per, FWL4PER->slave_reg);
$end;
$bind("SYSMGR_CORE->per_ns","DMAC->boot_periph_ns");
vista_bind(SYSMGR_CORE->per_ns, DMAC->boot_periph_ns);
$end;
$bind("L4WD1->irq","CPU->irq_118");
vista_bind(L4WD1->irq, CPU->irq_118);
$end;
$bind("I2C4->DMA_TX","DMAC->periph_req_6");
vista_bind(I2C4->DMA_TX, DMAC->periph_req_6);
$end;
$bind("OSC1TIMER1->irq","CPU->irq_116");
vista_bind(OSC1TIMER1->irq, CPU->irq_116);
$end;
$bind("SDMMC->AHB","l3_interconnect->ahb_slave0");
vista_bind(SDMMC->AHB, l3_interconnect->ahb_slave0);
$end;
$bind("SCHREGS->APB_Master","HMCAREGS->Slave1");
vista_bind(SCHREGS->APB_Master, HMCAREGS->Slave1);
$end;
$bind("l4_per_bus->bus_master_dmasecure","DMAC->APB_slave");
vista_bind(l4_per_bus->bus_master_dmasecure, DMAC->APB_slave);
$end;
$bind("l3_interconnect->apb_master0","c6->apb_slave0");
vista_bind(l3_interconnect->apb_master0, c6->apb_slave0);
$end;
$bind("DMAC->AXI_master","dma_split_bus->axi_slave0");
vista_bind(DMAC->AXI_master, dma_split_bus->axi_slave0);
$end;
$bind("UART1->IRQ","CPU->irq_109");
vista_bind(UART1->IRQ, CPU->irq_109);
$end;
$bind("l4_sys_bus->bus_master_l4wd0","L4WD0->APB");
vista_bind(l4_sys_bus->bus_master_l4wd0, L4WD0->APB);
$end;
$bind("CPU->master0","mpu_split_bus->axi_slave0");
vista_bind(CPU->master0, mpu_split_bus->axi_slave0);
$end;
$bind("l4_sys_bus->bus_master_iomgr","IOMGR->Prog_IF");
vista_bind(l4_sys_bus->bus_master_iomgr, IOMGR->Prog_IF);
$end;
$bind("l4_per_bus->bus_master_i2c3","I2C3->APB_Slave");
vista_bind(l4_per_bus->bus_master_i2c3, I2C3->APB_Slave);
$end;
$bind("RSTMGR->n_sp_timer_rst_0","SPTIMER0->reset");
vista_bind(RSTMGR->n_sp_timer_rst_0, SPTIMER0->reset);
$end;
$bind("irq_25","CPU->irq_25");
vista_bind(irq_25, CPU->irq_25);
$end;
$bind("l4_sys_bus->bus_master_fwfpga2sdram","FWFPGA2SDRAM->slave_reg");
vista_bind(l4_sys_bus->bus_master_fwfpga2sdram, FWFPGA2SDRAM->slave_reg);
$end;
$bind("EMAC1->AXI","l3_interconnect->axi_slave4");
vista_bind(EMAC1->AXI, l3_interconnect->axi_slave4);
$end;
$bind("l3_interconnect->apb_master4","l4_sys_bus->bus_slave_l3");
vista_bind(l3_interconnect->apb_master4, l4_sys_bus->bus_slave_l3);
$end;
$bind("l4_per_bus->bus_master_sptimer0","SPTIMER0->apb");
vista_bind(l4_per_bus->bus_master_sptimer0, SPTIMER0->apb);
$end;
$bind("l4_sys_bus->bus_master_sysmgr","SYSMGR_CORE->slave_reg");
vista_bind(l4_sys_bus->bus_master_sysmgr, SYSMGR_CORE->slave_reg);
$end;
$bind("RSTMGR->n_spis_rst_1","SPIS1->Resetn");
vista_bind(RSTMGR->n_spis_rst_1, SPIS1->Resetn);
$end;
$bind("SPIS0->TXDMA","DMAC->periph_req_18");
vista_bind(SPIS0->TXDMA, DMAC->periph_req_18);
$end;
$bind("CLKMGR->irq","CPU->irq_119");
vista_bind(CLKMGR->irq, CPU->irq_119);
$end;
$bind("I2C0->IRQ","CPU->irq_103");
vista_bind(I2C0->IRQ, CPU->irq_103);
$end;
$bind("I2C1->DMA_RX","DMAC->periph_req_11");
vista_bind(I2C1->DMA_RX, DMAC->periph_req_11);
$end;
$bind("l4_sys_bus->bus_master_fpgamgrdata","FPGAMGR->DATA_A10");
vista_bind(l4_sys_bus->bus_master_fpgamgrdata, FPGAMGR->DATA_A10);
$end;
$bind("DMA_SPLIT->output4","CPU->irq_85");
vista_bind(DMA_SPLIT->output4, CPU->irq_85);
$end;
$bind("SPTIMER0->irq","CPU->irq_113");
vista_bind(SPTIMER0->irq, CPU->irq_113);
$end;
$bind("l4_per_bus->bus_master_spi2","SPIM0->APB");
vista_bind(l4_per_bus->bus_master_spi2, SPIM0->APB);
$end;
$bind("I2C4->DMA_RX","DMAC->periph_req_7");
vista_bind(I2C4->DMA_RX, DMAC->periph_req_7);
$end;
$bind("SPIM0->IRQ","CPU->irq_101");
vista_bind(SPIM0->IRQ, CPU->irq_101);
$end;
$bind("L4WD3->irq","CPU->irq_126");
vista_bind(L4WD3->irq, CPU->irq_126);
$end;
$bind("UART1->DMA_RX","DMAC->periph_req_31");
vista_bind(UART1->DMA_RX, DMAC->periph_req_31);
$end;
$bind("SPIM1->TXDMA","DMAC->periph_req_20");
vista_bind(SPIM1->TXDMA, DMAC->periph_req_20);
$end;
$bind("irq_23","CPU->irq_23");
vista_bind(irq_23, CPU->irq_23);
$end;
$bind("FWDDRL3->master_port","SCHREGS->AXI0_Slave");
vista_bind(FWDDRL3->master_port, SCHREGS->AXI0_Slave);
$end;
$bind("l4_sys_bus->bus_master_schregs","SCHREGS->APB_Slave");
vista_bind(l4_sys_bus->bus_master_schregs, SCHREGS->APB_Slave);
$end;
$bind("fpga_split_bus->apb_master_sys","l4_sys_bus->bus_slave_fpgabridg");
vista_bind(fpga_split_bus->apb_master_sys, l4_sys_bus->bus_slave_fpgabridg);
$end;
$bind("RSTMGR->n_i2c_rst_2","I2C2->Resetn");
vista_bind(RSTMGR->n_i2c_rst_2, I2C2->Resetn);
$end;
$bind("GPIO1->irq","CPU->irq_111");
vista_bind(GPIO1->irq, CPU->irq_111);
$end;
$bind("c8->ahb_master2","l3_interconnect->ahb_slave2");
vista_bind(c8->ahb_master2, l3_interconnect->ahb_slave2);
$end;
$bind("SPIM0->RXDMA","DMAC->periph_req_17");
vista_bind(SPIM0->RXDMA, DMAC->periph_req_17);
$end;
$bind("fpga_split_bus->axi_master_l3","l3_interconnect->axi_slave0");
vista_bind(fpga_split_bus->axi_master_l3, l3_interconnect->axi_slave0);
$end;
$bind("I2C1->IRQ","CPU->irq_104");
vista_bind(I2C1->IRQ, CPU->irq_104);
$end;
$bind("SPIS1->IRQ","CPU->irq_100");
vista_bind(SPIS1->IRQ, CPU->irq_100);
$end;
$bind("l3_interconnect->ahb_master0","c6->ahb_slave0");
vista_bind(l3_interconnect->ahb_master0, c6->ahb_slave0);
$end;
$bind("l4_sys_bus->bus_master_fwocram","FWOCRAM->slave_reg");
vista_bind(l4_sys_bus->bus_master_fwocram, FWOCRAM->slave_reg);
$end;
$bind("I2C2->DMA_RX","DMAC->periph_req_13");
vista_bind(I2C2->DMA_RX, DMAC->periph_req_13);
$end;
$bind("HPS2FPGA->AXI_Master","HPS2FPGA_AXI");
vista_bind(HPS2FPGA->AXI_Master, HPS2FPGA_AXI);
$end;
$bind("mpu_split_bus->axi_master_l3","l3_interconnect->axi_slave1");
vista_bind(mpu_split_bus->axi_master_l3, l3_interconnect->axi_slave1);
$end;
$bind("l3_interconnect->axi_master6","c5->axi_slave4");
vista_bind(l3_interconnect->axi_master6, c5->axi_slave4);
$end;
$bind("FPGAMGR->IRQ","CPU->irq_123");
vista_bind(FPGAMGR->IRQ, CPU->irq_123);
$end;
$bind("LWHPS2FPGA->AHB_Master_HPS2FPGA","HPS2FPGA->AHB_Slave");
vista_bind(LWHPS2FPGA->AHB_Master_HPS2FPGA, HPS2FPGA->AHB_Slave);
$end;
$bind("UART1->DMA_TX","DMAC->periph_req_30");
vista_bind(UART1->DMA_TX, DMAC->periph_req_30);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "schematics";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~Stratix10_hps() {
    $destructor_begin;
$destruct_component("FWOCRAM");
delete FWOCRAM; FWOCRAM = 0;
$end;
$destruct_component("HMCREGS");
delete HMCREGS; HMCREGS = 0;
$end;
$destruct_component("c6");
delete c6; c6 = 0;
$end;
$destruct_component("dma_split_bus");
delete dma_split_bus; dma_split_bus = 0;
$end;
$destruct_component("SYSMGR_CORE");
delete SYSMGR_CORE; SYSMGR_CORE = 0;
$end;
$destruct_component("l4_sys_bus");
delete l4_sys_bus; l4_sys_bus = 0;
$end;
$destruct_component("FWDDRL3");
delete FWDDRL3; FWDDRL3 = 0;
$end;
$destruct_component("EMAC0");
delete EMAC0; EMAC0 = 0;
$end;
$destruct_component("UART0");
delete UART0; UART0 = 0;
$end;
$destruct_component("OCRAM");
delete OCRAM; OCRAM = 0;
$end;
$destruct_component("DMA_SPLIT");
delete DMA_SPLIT; DMA_SPLIT = 0;
$end;
$destruct_component("EMAC2");
delete EMAC2; EMAC2 = 0;
$end;
$destruct_component("CPU");
delete CPU; CPU = 0;
$end;
$destruct_component("L4WD1");
delete L4WD1; L4WD1 = 0;
$end;
$destruct_component("c8");
delete c8; c8 = 0;
$end;
$destruct_component("SPIS0");
delete SPIS0; SPIS0 = 0;
$end;
$destruct_component("SPIM1");
delete SPIM1; SPIM1 = 0;
$end;
$destruct_component("L4WD3");
delete L4WD3; L4WD3 = 0;
$end;
$destruct_component("FWL4SYS");
delete FWL4SYS; FWL4SYS = 0;
$end;
$destruct_component("HMCAREGS");
delete HMCAREGS; HMCAREGS = 0;
$end;
$destruct_component("SDMMC");
delete SDMMC; SDMMC = 0;
$end;
$destruct_component("RSTMGR");
delete RSTMGR; RSTMGR = 0;
$end;
$destruct_component("c5");
delete c5; c5 = 0;
$end;
$destruct_component("I2C0");
delete I2C0; I2C0 = 0;
$end;
$destruct_component("FPGAMGR");
delete FPGAMGR; FPGAMGR = 0;
$end;
$destruct_component("GPIO1");
delete GPIO1; GPIO1 = 0;
$end;
$destruct_component("LWHPS2FPGA");
delete LWHPS2FPGA; LWHPS2FPGA = 0;
$end;
$destruct_component("I2C1");
delete I2C1; I2C1 = 0;
$end;
$destruct_component("DMAC");
delete DMAC; DMAC = 0;
$end;
$destruct_component("SPTIMER0");
delete SPTIMER0; SPTIMER0 = 0;
$end;
$destruct_component("FWL4PER");
delete FWL4PER; FWL4PER = 0;
$end;
$destruct_component("Console0");
delete Console0; Console0 = 0;
$end;
$destruct_component("usb1");
delete usb1; usb1 = 0;
$end;
$destruct_component("I2C2");
delete I2C2; I2C2 = 0;
$end;
$destruct_component("EMAC1");
delete EMAC1; EMAC1 = 0;
$end;
$destruct_component("UART1");
delete UART1; UART1 = 0;
$end;
$destruct_component("mpu_split_bus");
delete mpu_split_bus; mpu_split_bus = 0;
$end;
$destruct_component("IOMGR");
delete IOMGR; IOMGR = 0;
$end;
$destruct_component("fpga_split_bus");
delete fpga_split_bus; fpga_split_bus = 0;
$end;
$destruct_component("usb2");
delete usb2; usb2 = 0;
$end;
$destruct_component("I2C3");
delete I2C3; I2C3 = 0;
$end;
$destruct_component("l4_per_bus");
delete l4_per_bus; l4_per_bus = 0;
$end;
$destruct_component("SPTIMER1");
delete SPTIMER1; SPTIMER1 = 0;
$end;
$destruct_component("L4WD0");
delete L4WD0; L4WD0 = 0;
$end;
$destruct_component("Console1");
delete Console1; Console1 = 0;
$end;
$destruct_component("SPIM0");
delete SPIM0; SPIM0 = 0;
$end;
$destruct_component("I2C4");
delete I2C4; I2C4 = 0;
$end;
$destruct_component("L4WD2");
delete L4WD2; L4WD2 = 0;
$end;
$destruct_component("HPS2FPGA");
delete HPS2FPGA; HPS2FPGA = 0;
$end;
$destruct_component("SPIS1");
delete SPIS1; SPIS1 = 0;
$end;
$destruct_component("CLKMGR");
delete CLKMGR; CLKMGR = 0;
$end;
$destruct_component("FWFPGA2SDRAM");
delete FWFPGA2SDRAM; FWFPGA2SDRAM = 0;
$end;
$destruct_component("ss_n_reset_1");
delete ss_n_reset_1; ss_n_reset_1 = 0;
$end;
$destruct_component("ss_n_reset_2");
delete ss_n_reset_2; ss_n_reset_2 = 0;
$end;
$destruct_component("ss_n_reset_3");
delete ss_n_reset_3; ss_n_reset_3 = 0;
$end;
$destruct_component("OSC1TIMER0");
delete OSC1TIMER0; OSC1TIMER0 = 0;
$end;
$destruct_component("OSC1TIMER1");
delete OSC1TIMER1; OSC1TIMER1 = 0;
$end;
$destruct_component("GPIO0");
delete GPIO0; GPIO0 = 0;
$end;
$destruct_component("l3_interconnect");
delete l3_interconnect; l3_interconnect = 0;
$end;
$destruct_component("FPGA2HPS");
delete FPGA2HPS; FPGA2HPS = 0;
$end;
$destruct_component("SYSMGRROM");
delete SYSMGRROM; SYSMGRROM = 0;
$end;
$destruct_component("SCHREGS");
delete SCHREGS; SCHREGS = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$socket("irq_23");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_23;
$end;
$socket("irq_21");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_21;
$end;
$socket("irq_19");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_19;
$end;
$socket("FPGA2HPS_AXI");
tlm::tlm_target_socket< 128U,axi_protocol_types,1,sc_core::SC_ONE_OR_MORE_BOUND > FPGA2HPS_AXI;
$end;
$socket("irq_24");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_24;
$end;
$socket("irq_22");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_22;
$end;
$socket("irq_20");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_20;
$end;
$socket("irq_25");
tlm::tlm_target_socket< 1U,tlm::tlm_base_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > irq_25;
$end;
$socket("HPS2FPGA_AXI");
tlm::tlm_initiator_socket< 128U,axi_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > HPS2FPGA_AXI;
$end;
$socket("LWHPS2FPGA_AXI");
tlm::tlm_initiator_socket< 32U,axi_protocol_types,1,sc_core::SC_ZERO_OR_MORE_BOUND > LWHPS2FPGA_AXI;
$end;
$component("FWOCRAM");
Arria_OCRAM_FireWall_pvt *FWOCRAM;
$end;
$component("HMCREGS");
Arria_HMC_MMR_pvt *HMCREGS;
$end;
$component("c6");
Dummy2_pvt *c6;
$end;
$component("dma_split_bus");
split_bus_pvt *dma_split_bus;
$end;
$component("SYSMGR_CORE");
Arria_SYSMGR_CORE_pvt *SYSMGR_CORE;
$end;
$component("l4_sys_bus");
L4_SYS_Bus_pvt *l4_sys_bus;
$end;
$component("FWDDRL3");
Arria_DDRL3_FireWall_pvt *FWDDRL3;
$end;
$component("EMAC0");
Arria_EMAC_pvt *EMAC0;
$end;
$component("UART0");
Arria_UART_pvt *UART0;
$end;
$component("OCRAM");
ocram_pvt *OCRAM;
$end;
$component("DMA_SPLIT");
dma_irq_splitter_pvt *DMA_SPLIT;
$end;
$component("EMAC2");
Arria_EMAC_pvt *EMAC2;
$end;
$component("CPU");
ARMv8_CoreTile *CPU;
$end;
$component("L4WD1");
Arria_L4WD_pvt *L4WD1;
$end;
$component("c8");
Dummy3_pvt *c8;
$end;
$component("SPIS0");
Arria_SPI_pvt *SPIS0;
$end;
$component("SPIM1");
Arria_SPI_pvt *SPIM1;
$end;
$component("L4WD3");
Arria_L4WD_pvt *L4WD3;
$end;
$component("FWL4SYS");
Arria_SYS_FireWall_pvt *FWL4SYS;
$end;
$component("HMCAREGS");
Arria_SDRAM_Adapter_pvt *HMCAREGS;
$end;
$component("SDMMC");
Arria_SDHC_pvt *SDMMC;
$end;
$component("RSTMGR");
Arria_RSTMGR_pvt *RSTMGR;
$end;
$component("c5");
Dummy1_pvt *c5;
$end;
$component("I2C0");
Arria_I2C_pvt *I2C0;
$end;
$component("FPGAMGR");
Arria_FPGAMGR_pvt *FPGAMGR;
$end;
$component("GPIO1");
Arria_GPIO_pvt *GPIO1;
$end;
$component("LWHPS2FPGA");
Arria_LWHPS2FPGA_pvt *LWHPS2FPGA;
$end;
$component("I2C1");
Arria_I2C_pvt *I2C1;
$end;
$component("DMAC");
DMA330_pvt *DMAC;
$end;
$component("SPTIMER0");
Arria_TIMER_pvt *SPTIMER0;
$end;
$component("FWL4PER");
Arria_PER_FireWall_pvt *FWL4PER;
$end;
$component("Console0");
CONSOLE_pvt *Console0;
$end;
$component("usb1");
Arria_DWC_OTG_pvt *usb1;
$end;
$component("I2C2");
Arria_I2C_pvt *I2C2;
$end;
$component("EMAC1");
Arria_EMAC_pvt *EMAC1;
$end;
$component("UART1");
Arria_UART_pvt *UART1;
$end;
$component("mpu_split_bus");
split_bus_pvt *mpu_split_bus;
$end;
$component("IOMGR");
Arria_IOMGR_pvt *IOMGR;
$end;
$component("fpga_split_bus");
split_bus_pvt *fpga_split_bus;
$end;
$component("usb2");
Arria_DWC_OTG_pvt *usb2;
$end;
$component("I2C3");
Arria_I2C_pvt *I2C3;
$end;
$component("l4_per_bus");
L4_PER_Bus_pvt *l4_per_bus;
$end;
$component("SPTIMER1");
Arria_TIMER_pvt *SPTIMER1;
$end;
$component("L4WD0");
Arria_L4WD_pvt *L4WD0;
$end;
$component("Console1");
CONSOLE_pvt *Console1;
$end;
$component("SPIM0");
Arria_SPI_pvt *SPIM0;
$end;
$component("I2C4");
Arria_I2C_pvt *I2C4;
$end;
$component("L4WD2");
Arria_L4WD_pvt *L4WD2;
$end;
$component("HPS2FPGA");
Arria_HPS2FPGA_pvt *HPS2FPGA;
$end;
$component("SPIS1");
Arria_SPI_pvt *SPIS1;
$end;
$component("CLKMGR");
Arria_CLKMGR_pvt *CLKMGR;
$end;
$component("FWFPGA2SDRAM");
Arria_DDR_FireWall_pvt *FWFPGA2SDRAM;
$end;
$component("ss_n_reset_1");
signal_source_pvt *ss_n_reset_1;
$end;
$component("ss_n_reset_2");
signal_source_pvt *ss_n_reset_2;
$end;
$component("ss_n_reset_3");
signal_source_pvt *ss_n_reset_3;
$end;
$component("OSC1TIMER0");
Arria_TIMER_pvt *OSC1TIMER0;
$end;
$component("OSC1TIMER1");
Arria_TIMER_pvt *OSC1TIMER1;
$end;
$component("GPIO0");
Arria_GPIO_pvt *GPIO0;
$end;
$component("l3_interconnect");
L3_Interconnect_pvt *l3_interconnect;
$end;
$component("FPGA2HPS");
Arria_FPGA2HPS_pvt *FPGA2HPS;
$end;
$component("SYSMGRROM");
Arria_SYSMGRROM_pvt *SYSMGRROM;
$end;
$component("SCHREGS");
Arria_SDRAM_Scheduler_pvt *SCHREGS;
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