/*
 * machdep/m68k/thread.h -- m68k pcb (plans 430-433, 620-622; D024, D142).
 * struct pcb is the 1997 m68k layout (416 B) read from the original bytes
 * (plan 620.2: _pcb_module_init zinit 0x1a0, _thread_user_state +0x48/+0x4c,
 * locore __switch_context +0x00/+0x54/+0x58/+0x5c/+0x134/+0x194, trap5/trap6
 * +0x50) with the field names of NeXTMach mk-108.1 next/pcb.h:23-33, placed in
 * the 1997 order; the types of saved_regs and pcb_flags and the name of the
 * new field pcb_save_area are plan 622 choices (marked).  aston/astoff use a
 * 32-bit pcb_flags (plan 432: the u_char form does not give the original
 * bset/bclr).  pcb_synch follows NeXTMach mk-108.1 next/pcb.h:67.
 */
/* 
 * NeXTMach next/pcb.h:
 * Copyright (c) 1987, 1988 NeXT, Inc.
 */

/*
 * The lines marked "(Darwin)" follow machdep/i386/thread.h:180-185
 * (USER_REGS with the m68k fields, named as in plan 622) and machdep/ppc/thread.h:97-98
 * of Darwin 0.1 (kernel-1), whose notice is:
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * "Portions Copyright (c) 1999 Apple Computer, Inc.  All Rights
 * Reserved.  This file contains Original Code and/or Modifications of
 * Original Code as defined in and that are subject to the Apple Public
 * Source License Version 1.0 (the 'License').  You may not use this file
 * except in compliance with the License.  Please obtain a copy of the
 * License at http://www.apple.com/publicsource and read it before using
 * this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License."
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef _MACHDEP_M68K_THREAD_H_
#define _MACHDEP_M68K_THREAD_H_
/* plan 622 (D142): the 1997 m68k pcb (plan 620.2) with NeXTMach next/pcb.h names */
#import <sys/types.h>	/* plan 622 (D142): u_char, u_short, u_int */
#import <m68k/reg.h>	/* plan 622 (D142): NeXTMach next/pcb.h:13 <next/reg.h> */
#import <m68k/mmu.h>	/* plan 622 (D142): NeXTMach next/pcb.h:15 <next/mmu.h> */
/*	@(#)fpc.h	1.0	03/12/87	(c) 1987 NeXT	*/
/* plan 622 (D142): NeXTMach next/fpc.h:34-42 (notice above: fpc.h:1) */
struct fpc_internal {			/* internal state */
	u_char	fpc_version;		/* microcode version # */
	u_char	fpc_framesize;		/* sizeof fpc_frame */
#define	FPC_NULLSIZE	0
#define	FPC_IDLESIZE	56
	u_short	fpc_reserved;
#define	FPC_MAXFRAME	212		/* worst-case frame size */
	u_char	fpc_frame[FPC_MAXFRAME]; /* internal state frame */
};
/* plan 622 (D142): NeXTMach next/fpc.h:21-27 and 32; the u_char state and FPC_* lines 28-31 are left out (108 B from pcb+0x134 to pcb+0x1a0) */
struct fpc_external {			/* externally visible state */
	struct fpc_regs {
		int	fp[3];		/* 96-bit extended format */
	} regs[8];
	int	cr;			/* control */
	int	sr;			/* status */
	int	iar;			/* instruction address */
};
struct pcb {
	struct	regs pcb_r;		/* +0x000 */
	struct	regs *saved_regs;	/* +0x048; plan 622 (D142): NeXTMach struct NeXT_saved_state * */
	void	*pcb_save_area;		/* +0x04c; plan 622 (D142): authored name (no NeXTMach field) */
	int	thread_user_reg;	/* +0x050 */
	int	pcb_flags;		/* +0x054; plan 432: NeXTMach u_char */
	union {
		struct	mmu_030_tt tt1_030;
		struct mmu_040_tt tt1_040;
	} mmu_tt1;			/* +0x058 */
	struct	fpc_internal pcb_fpc_i;	/* +0x05c */
	struct	fpc_external pcb_fpc_e;	/* +0x134 */
};
typedef struct pcb *pcb_t;
extern void *thread_user_state();
#define current_stack_pointer()	(stack_pointers[cpu_number()])	/* (Darwin) */
#define USER_REGS(thread) \
    ((thread)->pcb->pcb_save_area ? (void *)(thread)->pcb->saved_regs : (void *)thread_user_state(thread))	/* (Darwin) */
#define pcb_synch(thread)
#define pcb_common_init(task)		/* (Darwin) */
#define pcb_common_terminate(task)	/* (Darwin) */
#endif
