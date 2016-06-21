
select_cluster "Arria10_top.Arria10_soc_inst.CORTEX_A9MP.PV"

trace_linux ../A10_sw/kernel/linux-socfpga/vmlinux

trace_linux_process [list id2 libc-2*] {
  add_symbol_file ../../imagep/fpga_sw/imagedisplay/id2
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff

  trace_memory_leaks -report_file id2_leaks.txt
  trace_memory_usage -kind csv
  trace_memory_functions_activity -kind eff

  insert_tracepoint tp1 -at-function-entry main -do-raw {
    printf("Setting timing to DYNAMIC\n");
    set_parameter("Arria10_top.fpga_inst.fpga_axi_bus.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.ic.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.fb.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.fpgamem.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.ip.lt_policy_modeling", "DYNAMIC");
  }

  insert_tracepoint tp2 -at-function-exit my_handler -do-raw {
    printf("Setting timing to STATIC\n");
    set_parameter("Arria10_top.fpga_inst.fpga_axi_bus.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.ic.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.fb.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.fpgamem.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.ip.lt_policy_modeling", "STATIC");
  }
}


trace_attribute Arria10_top.Arria10_soc_inst.CORTEX_A9MP.PV.cpu0.core.core_state
trace_attribute Arria10_top.Arria10_soc_inst.CORTEX_A9MP.PV.cpu1.core.core_state

trace_socket Arria10_top.fpga_inst.fpga_axi_bus.FPGAmaster
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.FPGAslave
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.ICregisters
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.ICdma
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.JPEGregisters
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.JPEGdma
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.FrameBuffer
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.FPGAmem
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.IPregisters
trace_socket Arria10_top.fpga_inst.fpga_axi_bus.IPdma

trace_socket Arria10_top.fpga_inst.ic.irq
trace_socket Arria10_top.fpga_inst.ip.irq
