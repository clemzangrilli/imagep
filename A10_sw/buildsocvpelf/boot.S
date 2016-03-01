/*
 * boot.S - simple register setup code for stand-alone Linux booting
 *
 * Copyright (C) 2011 ARM Limited. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE.txt file.
 */

	.syntax	unified
	.text

	.globl	_start
_start:
          movw r0,#0xfc00                      @ remaping 
            movt r0,#0xfffe
    	LDR     r1,=0xfffefc00
	ldr           r1, [r0]
	bic r1,r1,#0xf0000000
	bic r1,r1,#0x0f000000	 
	bic r1,r1,#0x00f00000
	
	   str    r1,[r0]
	@
#ifdef SMP
	@
	@ Program architected timer frequency
	@
	mrc	p15, 0, r0, c0, c1, 1		@ CPUID_EXT_PFR1
	lsr	r0, r0, #16
	ands	r0, r0, #1			@ Check generic timer support
	beq	1f
	ldr	r0, =24000000			@ 24MHz timer frequency
	mcr	p15, 0, r0, c14, c0, 0		@ CNTFRQ

1:
 	@ CPU initialisation
	@
	mrc	p15, 0, r0, c0, c0, 5		@ MPIDR (ARMv7 only)
	and	r0, r0, #15			@ CPU number
	cmp	r0, #0				@ primary CPU?
	beq	2f

	@
	@ TODO: Secondary CPUs.
	ldr	r1, =filesystem - 0x100
	adr	r2, 1f
	ldmia	r2, {r3 - r7}			@ move the code to a location
	stmia	r1, {r3 - r7}			@ less likely to be overridden
        mov     pc, r1
1:
	wfe
        b       1b
        nop
        nop
        nop
#endif
	@
	@ UART initialisation (38400 8N1)
	@
2:
	@
	@ Kernel parameters
	@
	mov	r0, #0
	ldr	r1, =4251			@ Not used
	ldr	r2, =dtb
	mov	r3, #0
	ldr	lr, =kernel
	mov     pc, lr				@ jump to the kernel
