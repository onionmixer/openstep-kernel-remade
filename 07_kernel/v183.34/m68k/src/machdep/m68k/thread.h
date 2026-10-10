/*
 * machdep/m68k/thread.h -- m68k pcb (plan 430-433, authored, D024).
 * Layout from the original bytes: USER_REGS in _init_task returns
 * pcb+0x48 when pcb+0x4c is set; aston/astoff use a 32-bit word at
 * pcb+0x54 (plan 432).  pcb_synch follows NeXTMach mk-108.1 next/pcb.h:67.
 */
/* 
 * NeXTMach next/pcb.h:
 * Copyright (c) 1987, 1988 NeXT, Inc.
 */

/*
 * The lines marked "(Darwin)" follow machdep/i386/thread.h:180-185
 * (USER_REGS with the m68k fields) and machdep/ppc/thread.h:97-98; otherwise the same as
 * Darwin 0.1 (kernel-1), whose notice is:
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
struct pcb {
	char	pcb_head[0x48];
	void	*pcb_regs;		/* +0x48: returned by USER_REGS (_init_task) */
	int	pcb_regs_valid;		/* +0x4c: tested by USER_REGS (_init_task) */
	char	pcb_pad50[4];		/* +0x50 */
	int	pcb_flags;		/* +0x54 */
};
typedef struct pcb *pcb_t;
extern void *thread_user_state();
#define current_stack_pointer()	(stack_pointers[cpu_number()])	/* (Darwin) */
#define USER_REGS(thread) \
    ((thread)->pcb->pcb_regs_valid ? (thread)->pcb->pcb_regs : (void *)thread_user_state(thread))	/* (Darwin) */
#define pcb_synch(thread)
#define pcb_common_init(task)		/* (Darwin) */
#define pcb_common_terminate(task)	/* (Darwin) */
#endif
