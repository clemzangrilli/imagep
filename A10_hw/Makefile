#
#  "make" with no arguments will generate code for all mb files and compile everything
#  "make run" will compile iff needed and run the simulation
#  "make clean" remove all generated/object data
#

MODELS = models
SC_MAIN = sc_main

PROJECT = $(patsubst %.v2p,%,$(wildcard *.v2p))
PROJECTEXE = $(PROJECT)/build/D_PRJDIR_/$(SC_MAIN).exe

SRCS = $(wildcard *.cpp) $(wildcard ../fpga_hw/$(MODELS)/*.cpp) $(wildcard ../fpga_hw/$(MODELS)/*.h)

all: $(PROJECTEXE)

.PHONY : ../fpga_hw/fswebcam

$(PROJECTEXE): $(SRCS) ../../jpeg/objdir/libvmodels.a ../fpga_hw/fswebcam/libfswebcam.a
	vista_build_project $(PROJECT)

../fpga_hw/fswebcam/libfswebcam.a:
	make -C ../fpga_hw/fswebcam

../../jpeg/objdir/libvmodels.a: ../../jpeg/jpeg_algorithm/jpeg.cpp
	cd ../../jpeg && make

run: $(PROJECTEXE) ../A10_sw/buildsocvpelf/linux-system-sd.elf
	vista_simulate $(PROJECT)

vista: $(PROJECTEXE) ../A10_sw/buildsocvpelf/linux-system-sd.elf
	vista -no-stop-after-elaboration -simscript simscript.tcl -exec -project $(PROJECT)

batch: $(PROJECTEXE) ../A10_sw/buildsocvpelf/linux-system-sd.elf
	vista -batch -exec -project $(PROJECT)

../A10_sw/buildsocvpelf/linux-system-sd.elf:
	make -C ../A10_sw
 
COMMAND = "if {![does_tlm_library_exist $(MODELS)]} \
              {create_tlm_library $(MODELS) $(MODELS)}; \
           reload_tlm_library $(MODELS);\
           foreach n [glob -directory $(MODELS) -tails *.mb] { \
             save_model -g TLM/$(MODELS)/[lindex [split \$$n .] 0] }"

mb:
	make -C ../fpga_hw
	if [ -e $(MODELS) ]; then vista_model_builder -c $(COMMAND); fi

clean:
	rm -rf vista_work $(PROJECT) sim papoulis_project
	find . -name "*~" -exec rm {} \;
	rm -rf vista_*

