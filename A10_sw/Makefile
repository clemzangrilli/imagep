
CROSS_COMPILE=../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-
ARCH=arm

KERNEL_PATCH_FILES = $(shell find kernel_patches -type f)

ZIMAGE = kernel/linux-socfpga/arch/arm/boot/zImage
DTB    = kernel/linux-socfpga/arch/arm/boot/dts/socfpga_arria10_swvp.dtb

all: kernel/linux-socfpga/vmlinux filesystem/Software/arria10/linux/sd-angstrom-v2014.12-arria10swvp.img buildsocvpelf/linux-system-sd.elf

kernel/linux-socfpga/vmlinux: $(KERNEL_PATCH_FILES) kernel/linux-socfpga.tar.xz
	if [ ! -d kernel/linux-socfpga ]; then cd kernel && tar xf linux-socfpga.tar.xz; fi
	cd kernel && cp -rp ../kernel_patches/* linux-socfpga && cp -rf ../kernel_patches/.config linux-socfpga
	make -C kernel/linux-socfpga CROSS_COMPILE=../../$(CROSS_COMPILE) ARCH=$(ARCH)
	touch kernel/linux-socfpga/vmlinux

kernel/linux-socfpga.tar.xz:
	cd kernel && wget ftp://mentorweb.wv.mentorg.com/pub/a10ip/linux-socfpga.tar.xz

filesystem/Software/arria10/linux/sd-angstrom-v2014.12-arria10swvp.img: 
	if [ ! -f filesystem/linux-arria10swvp-socfpga-3.10-ltsi-angstrom-v2014.12.tgz ]; then \
	  mkdir -p filesystem && cd filesystem && \
	  wget --no-cache http://rocketboards.org/foswiki/pub/Documentation/Arria10SoCVPLinux/linux-arria10swvp-socfpga-3.10-ltsi-angstrom-v2014.12.tgz; fi
	cd filesystem && tar xvf linux-arria10swvp-socfpga-3.10-ltsi-angstrom-v2014.12.tgz

kernel/linux-socfpga/arch/arm/boot/zImage: kernel/linux-socfpga/vmlinux

kernel/linux-socfpga/arch/arm/boot/dts/socfpga_arria10_swvp.dtb: kernel/linux-socfpga/vmlinux

buildsocvpelf/linux-system-sd.elf: $(ZIMAGE) $(DTB)
	make -C buildsocvpelf clean
	make -C buildsocvpelf DTB=../$(DTB) KERNEL=../$(ZIMAGE) CROSS_COMPILE=../$(CROSS_COMPILE) \
		IMAGE=linux-system-sd.elf
