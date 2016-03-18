
CROSS_COMPILE=../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-
ARCH=arm

KERNEL_PATCH_FILES = $(shell find kernel_patches -type f)

ZIMAGE = kernel/linux-socfpga/arch/arm/boot/zImage
DTB    = kernel/linux-socfpga/arch/arm/boot/dts/socfpga_arria10_swvp.dtb

all: kernel/linux-socfpga/vmlinux buildsocvpsd/sd-angstrom-v2014.12-arria10swvp.img buildsocvpelf/linux-system-sd.elf

kernel/linux-socfpga/vmlinux: $(KERNEL_PATCH_FILES) kernel/linux-socfpga.tar.xz
	if [ ! -d kernel/linux-socfpga ]; then cd kernel && tar xf linux-socfpga.tar.xz; fi
	cd kernel && cp -rp ../kernel_patches/* linux-socfpga && cp -rf ../kernel_patches/.config linux-socfpga
	make -C kernel/linux-socfpga CROSS_COMPILE=../../$(CROSS_COMPILE) ARCH=$(ARCH)
	touch kernel/linux-socfpga/vmlinux

kernel/linux-socfpga.tar.xz:
	cd kernel && wget ftp://mentorweb.wv.mentorg.com/pub/a10ip/linux-socfpga.tar.xz

buildsocvpsd/sd-angstrom-v2014.12-arria10swvp.img: 
	if [ ! -f  buildsocvpsd/sd-angstrom-v2014.12-arria10swvp.img.tar.gz ]; then \
	  cd buildsocvpsd && \
	  wget ftp://mentorweb.wv.mentorg.com/pub/a10ip/sd-angstrom-v2014.12-arria10swvp.img.tar.gz; fi
	cd buildsocvpsd && gzip -cd sd-angstrom-v2014.12-arria10swvp.img.tar.gz | tar xvf -

kernel/linux-socfpga/arch/arm/boot/zImage: kernel/linux-socfpga/vmlinux

kernel/linux-socfpga/arch/arm/boot/dts/socfpga_arria10_swvp.dtb: kernel/linux-socfpga/vmlinux

buildsocvpelf/linux-system-sd.elf: $(ZIMAGE) $(DTB)
	make -C buildsocvpelf clean
	make -C buildsocvpelf DTB=../$(DTB) KERNEL=../$(ZIMAGE) CROSS_COMPILE=../$(CROSS_COMPILE) \
		IMAGE=linux-system-sd.elf
