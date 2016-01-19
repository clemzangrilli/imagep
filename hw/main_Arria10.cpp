//v2: comments beginning with v2 are generated and used by V2
//v2: please don't remove or modify these comments

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//v2: begin of includes section
#include "schematics/Arria10_top.h"
//v2: end of includes section


void my_handler(int s){
    cout << endl << "*** Caught signal " << s << endl;
    cout << "*** Stopping Simulation " << endl;
    sc_stop();
    exit(0); 
}

extern "C" void Papoulis_SetTclVariable(const char* name, const char* value);

int sc_main(int argc, char *argv[]) {

  Papoulis_SetTclVariable("::env(VISTA_PLATFORM_NAME)", "Arria10");
 struct sigaction sigIntHandler;
 sigIntHandler.sa_handler = my_handler;
 sigemptyset(&sigIntHandler.sa_mask);
 sigIntHandler.sa_flags = 0;
 sigaction(SIGINT, &sigIntHandler, NULL);

//v2: begin of channel declarations section
//v2: end of channel declarations section


//v2: begin of instantiations section
//v2: instance inst_Arria10_top - instance number 0 of module Arria10_top
Arria10_top *inst_Arria10_top = new Arria10_top("Arria10_top");
//v2: end of instantiations section


//v2: begin of ports assignment section
//v2: ports assignment for instance inst_Arria10_top
//v2: end of ports assignment section

 sc_start();

//v2: begin of instantiations section
delete inst_Arria10_top;
//v2: end of instantiations section

 return 0;
}
