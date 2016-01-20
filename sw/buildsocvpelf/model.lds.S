/*
 * model.lds.S - simple linker script for stand-alone Linux booting
 *
 * Copyright (C) 2011 ARM Limited. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE.txt file.
 */

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
TARGET(binary)

INPUT(./boot.o)
INPUT(KERNEL)
#ifdef USE_INITRD
INPUT(FILESYSTEM)
#endif
INPUT(DTB)

PHYS_OFFSET = 0x100000;

SECTIONS
{
	. = PHYS_OFFSET;
	.text : { boot.o }

	. = PHYS_OFFSET + 0x8000 - KERNEL_HDR_SZ ;
	kernel = . + KERNEL_HDR_SZ;
	.kernel : { KERNEL }

        . = PHYS_OFFSET + 0x01000000 - 0x100000;
	filesystem = .;
#ifdef USE_INITRD
	.filesystem : { FILESYSTEM }
	fs_size = . - filesystem;
#endif
	. = PHYS_OFFSET + 0x0F000000 - 0x100000;
         dtb = .;
         .dtb : { DTB }

        .data : { *(.data) }
	.bss : { *(.bss) }
}
