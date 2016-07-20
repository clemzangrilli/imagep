#
# Makefile - build a kernel+filesystem image for stand-alone Linux booting
#
# Copyright (C) 2012 ARM Limited. All rights reserved.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE.txt file.

# VE
PHYS_OFFSET	:= 0x00000000
UART_BASE	:= 0x1c090000
SYSREGS_BASE	:= 0x1c010000
GIC_DIST_BASE   := 0xfffc1000
GIC_CPU_BASE    := 0xfffc2000
CNTFRQ		:= 0x01800000	# 24Mhz

#INITRD_FLAGS	:= -DUSE_INITRD
CPPFLAGS	+= $(INITRD_FLAGS) -g
CPPFLAGS	+= -Ulinux

BOOTLOADER	:= boot.S
MBOX_OFFSET	:= 0xfff8
KERNEL		?= Image
KERNEL_OFFSET	:= 0x80000
LD_SCRIPT	:= model.lds.S
IMAGE		:= linux-system.axf

FILESYSTEM	?= filesystem.cpio.gz
FS_OFFSET	:= 0x10000000
FILESYSTEM_START:= $(shell echo $$(($(PHYS_OFFSET) + $(FS_OFFSET))))
FILESYSTEM_SIZE	:= $(shell stat -Lc %s $(FILESYSTEM) 2>/dev/null || echo 0)
FILESYSTEM_END	:= $(shell echo $$(($(FILESYSTEM_START) + $(FILESYSTEM_SIZE))))

FDT_SRC		:= $(DTB)
FDT_INCL_REGEX	:= \(/include/[[:space:]]*"\)\([^"]\+\)\(".*\)
FDT_DEPS	:= $(FDT_SRC) $(addprefix $(dir $(FDT_SRC)), $(shell sed -ne 'sq$(strip $(FDT_INCL_REGEX)q\2q p' < $(FDT_SRC))))
FDT_OFFSET	:= 0x08000000

BOOTARGS	:= "console=ttyAMA0,115200n8 earlyprintk mem=2048M earlyprintk rdinit=/linuxrc ip=dhcp"
CHOSEN_NODE	:= chosen {						\
			bootargs = \"$(BOOTARGS)\";			\
			linux,initrd-start = <$(FILESYSTEM_START)>;	\
			linux,initrd-end = <$(FILESYSTEM_END)>;		\
		   };

CROSS_COMPILE	?= aarch64-linux-gnu-
CC		:= $(CROSS_COMPILE)gcc
LD		:= $(CROSS_COMPILE)ld
DTC		:= $(if $(wildcard ./dtc), ./dtc, $(shell which dtc))

all: $(IMAGE)

clean:
	rm -f $(IMAGE) boot.o model.lds fdt.dtb

$(IMAGE): boot.o model.lds fdt.dtb $(KERNEL) $(FILESYSTEM)
	$(LD) -o $@ --script=model.lds

boot.o: $(BOOTLOADER) Makefile
	$(CC) $(CPPFLAGS) -DCNTFRQ=$(CNTFRQ) -DUART_BASE=$(UART_BASE) -DSYSREGS_BASE=$(SYSREGS_BASE) -DGIC_DIST_BASE=$(GIC_DIST_BASE) -DGIC_CPU_BASE=$(GIC_CPU_BASE) -c -o $@ $(BOOTLOADER) -g

model.lds: $(LD_SCRIPT) Makefile
	$(CC) $(CPPFLAGS) -DPHYS_OFFSET=$(PHYS_OFFSET) -DMBOX_OFFSET=$(MBOX_OFFSET) -DKERNEL_OFFSET=$(KERNEL_OFFSET) -DFDT_OFFSET=$(FDT_OFFSET) -DFS_OFFSET=$(FS_OFFSET) -DKERNEL=$(KERNEL) -DFILESYSTEM=$(FILESYSTEM) -E -P -C -o $@ $<

#fdt.dtb: $(FDT_DEPS) Makefile
fdt.dtb: Makefile
	$(DTC) -O dts -I dtb $(DTB) | \
	sed -e 's%rdinit=/sbin/init%rootwait root=/dev/mmcblk0p2%' | \
#	sed -r -e 's/linux,initrd-start = <0x[0-9a-f]+>/linux,initrd-start = <'$(FILESYSTEM_START)'>/' | \
#	sed -r -e 's/linux,initrd-end = <0x[0-9a-f]+>/linux,initrd-end = <'$(FILESYSTEM_END)'>/' | \
	$(DTC) -O dtb -o $@ -
	
# The filesystem archive might not exist if INITRD is not being used
.PHONY: all clean $(FILESYSTEM)
