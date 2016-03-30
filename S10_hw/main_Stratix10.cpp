#include "schematics/top.h"
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// -------------------------------------------------------------------
#define VERSIONSTR0 "==================================="
#define VERSIONSTR1 "Stratix10 Software Virtual Platform"
#define VERSIONSTR2 "Version 1.0.1"
#define VERSIONSTR3 "(c)2016 Altera Corporation"
// -------------------------------------------------------------------
// -------------------------------------------------------------------
extern "C" void Papoulis_SetTclVariable(const char* name, const char* value);
void showVersion();
void showInternalNotes();
// -------------------------------------------------------------------

void my_handler(int s){
    cout << endl << "*** Caught signal " << s << endl;
    cout << "*** Stopping Simulation " << endl;
    sc_stop();
    exit(0); 
}

// -------------------------------------------------------------------
int sc_main(int argc, char *argv[]) {

  Papoulis_SetTclVariable("::env(VISTA_PLATFORM_NAME)", "Stratix10");

 struct sigaction sigIntHandler;
 sigIntHandler.sa_handler = my_handler;
 sigemptyset(&sigIntHandler.sa_mask);
 sigIntHandler.sa_flags = 0;
 sigaction(SIGINT, &sigIntHandler, NULL);

  char* image_name = 0;
  int gdb_port = 0;
  int version  = 0;
  int intNotes = 0;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {

           if(argv[i][1] == 'p') gdb_port = atoi(&argv[i][2]);
      else if(argv[i][1] == 'r') intNotes = 1;
      else if(argv[i][1] == 'v') version = 1;
      else if(argv[i][1] == '-') break;
      else fprintf(stderr, "%s: unknown flag. Ignored\n", argv[i]);

    } else {

      if (!image_name) image_name = argv[i];
      else fprintf(stderr, "%s: redundant parameter. Ignored\n", argv[i]);

    }
  }

  if (version) {
    showVersion();
    return 1;
  }
  
  if (intNotes) {
    showInternalNotes();
    return 1;
  }
  
  if (image_name) {
    mb::sysc::set_parameter("elf_image_file", (const char*)image_name);
  }
  
  if (gdb_port) {
    mb::sysc::set_parameter("gdbstub_port", gdb_port);
  }

  top *inst_top = new top("top");

  sc_start();

  delete inst_top;
  
  return 0;
}
// -------------------------------------------------------------------
// -------------------------------------------------------------------
void showVersion()
{
  std::cout<<std::endl<<std::endl;
  std::cout<<VERSIONSTR0<<std::endl;
  std::cout<<VERSIONSTR1<<std::endl;
  std::cout<<VERSIONSTR2<<std::endl;
  std::cout<<VERSIONSTR3<<std::endl;
  std::cout<<VERSIONSTR0<<std::endl<<std::endl;
}
// -------------------------------------------------------------------
#define ST(M);   std::cout<<M<<std::endl;
// -------------------------------------------------------------------
void showInternalNotes()
{
  ST(std::endl);
  ST(VERSIONSTR0);
  ST("Internal notes");
  ST("");
  ST("  1 ");
  ST("    - cpuinfo shows one proc");
  ST("    - cpu0/1/2/3 run ok independently");
  ST("  0 ");
  ST("  - add tracking/version to main");
  ST("  - parameter clean up");
  ST(VERSIONSTR0);
  ST("");
}
#undef ST
#undef VERSIONSTR0
#undef VERSIONSTR1
#undef VERSIONSTR2
#undef VERSIONSTR3
