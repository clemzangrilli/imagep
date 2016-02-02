
select_cluster "Arria10_top.Arria10_soc_inst.CORTEX_A9MP.PV"

#trace_linux ../sw/kernel/linux-socfpga/vmlinux -libc ../../local/libc-2.20.so
trace_linux ../sw/kernel/linux-socfpga/vmlinux

trace_linux_process fact {
  add_symbol_file ../sw/test/fact
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff
}

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
  #trace_function_calls -kind eff
  #trace_current_function -kind eff
  #trace_function_activity * -kind eff
  trace_function_activity jpgencoder -kind eff
}

trace_linux_process { jpegsw libc-2* libstdc++* } {
  add_symbol_file ../sw/jpegcpp/jpegsw
  #trace_memory_leaks -report_file /tmp/jpegsw.%exe.%pid
  #trace_memory_usage -kind csv
  #trace_memory_functions_activity -kind eff
}

trace_linux_process jpeghw {
  add_symbol_file ../sw/jpegcpp/jpeghw
  trace_function_calls -kind eff
  trace_current_function -kind eff
  trace_function_activity * -kind eff
}

trace_linux_process { jpeghw libc-2* libstdc++* } {
  add_symbol_file ../sw/jpegcpp/jpeghw
  trace_memory_leaks -report_file /tmp/jpeghw.%exe.%pid
  trace_memory_usage -kind csv
  trace_memory_functions_activity -kind eff
}

trace_socket   Arria10_top.jpeg.slave
trace_socket   Arria10_top.jpeg.master
trace_socket   Arria10_top.fpgamem.s

#trace_register Arria10_top.jpeg.PV.inputaddr
#trace_register Arria10_top.jpeg.PV.inputlength
#trace_register Arria10_top.jpeg.PV.outputaddr
#trace_register Arria10_top.jpeg.PV.outputlength
#trace_register Arria10_top.jpeg.PV.status
#trace_register Arria10_top.jpeg.PV.start

#enable_coverage -design custom.dgn -test custom.tst
