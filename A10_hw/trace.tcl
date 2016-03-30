
select_cluster "Arria10_top.Arria10_soc_inst.CORTEX_A9MP.PV"

#trace_linux ../sw/kernel/linux-socfpga/vmlinux -libc ../../local/libc-2.20.so
trace_linux ../A10_sw/kernel/linux-socfpga/vmlinux

trace_linux_process mem_test {
  add_symbol_file ../sw/test/mem_test
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff
}

trace_linux_process { mem_test libc-2* } {
  add_symbol_file ../sw/test/mem_test
  trace_memory_leaks -report_file /tmp/mem_leaks.%exe.%pid
  trace_memory_usage -kind csv
  trace_memory_functions_activity -kind eff
}

trace_linux_process jpegsw {
  add_symbol_file ../sw/jpegcpp/jpegsw
  trace_function_activity main -kind eff
  trace_function_activity jpgencoder -kind eff
  trace_function_activity pixelpipe -kind eff
}

trace_linux_process jpeghw {
  add_symbol_file ../sw/jpegcpp/jpeghw
  add_raw_context {
    static unsigned long long mysimtime = 0;
  }
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff
  trace_function_activity jpgencoder -kind eff
  trace_function_activity main -kind eff
  trace_function_activity waitforirq -kind eff
  insert_tracepoint jpeghw_1 -at-function-entry jpgencoder -do-raw {
    mysimtime = get_time_stamp();
    printf("Setting timing to DYNAMIC\n");
    set_parameter("Arria10_top.fpga_inst.jpeg.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.fpgamem.lt_policy_modeling", "DYNAMIC");
    set_parameter("Arria10_top.fpga_inst.fpga_axi_bus.lt_policy_modeling", "DYNAMIC");
  }
  insert_tracepoint jpeghw_2 -at-function-exit jpgencoder -do-raw {
    printf("Setting timing back to STATIC\n");
    mysimtime = get_time_stamp() - mysimtime;
    printf("jpgencoder function took %d ms\n", mysimtime/1000000);
    set_parameter("Arria10_top.fpga_inst.jpeg.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.fpgamem.lt_policy_modeling", "STATIC");
    set_parameter("Arria10_top.fpga_inst.fpga_axi_bus.lt_policy_modeling", "STATIC");
  }
}

trace_linux_process { jpeghw libc-2* libstdc++* } {
  add_symbol_file ../sw/jpegcpp/jpeghw
  trace_memory_leaks -report_file /tmp/jpeghw.%exe.%pid
  trace_memory_usage -kind csv
  trace_memory_functions_activity -kind eff
}

trace_linux_process id2 {
  add_symbol_file ../../imagep/fpga_sw/imagedisplay/id2
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff

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

trace_socket   Arria10_top.fpga_inst.jpeg.slave
trace_socket   Arria10_top.fpga_inst.jpeg.master
trace_socket   Arria10_top.fpga_inst.jpeg.irq
trace_socket   Arria10_top.fpga_inst.fpgamem.slave

trace_attribute Arria10_top.fpga_inst.jpeg.PV.jpeg_delay

trace_register Arria10_top.fpga_inst.jpeg.PV.inputaddr
trace_register Arria10_top.fpga_inst.jpeg.PV.input_w_h_size
trace_register Arria10_top.fpga_inst.jpeg.PV.outputaddr
trace_register Arria10_top.fpga_inst.jpeg.PV.outputlength
trace_register Arria10_top.fpga_inst.jpeg.PV.status
trace_register Arria10_top.fpga_inst.jpeg.PV.start


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

#enable_coverage -design custom.dgn -test custom.tst
