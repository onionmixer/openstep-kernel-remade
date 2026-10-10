/*
 * machdep/m68k/pmap.h -- m68k pmap interface (plan 430/433, authored, D024).
 * Layout from the original bytes: _task_info reads the resident count
 * at pmap+0x10.  The member names and the PMAP_* and pmap_resident_count
 * macros follow NeXTMach mk-108.1 next/pmap.h:155-160 and 217-227.
 */
/* 
 * NeXTMach next/pmap.h:
 * Copyright (c) 1987, 1988, 1989, 1990 NeXT, Inc.
 */

/*
 * The lines marked "(Darwin)" follow machdep/i386/pmap.h:119-120
 * (i386_ptob/i386_btop changed to m68k_ptob/m68k_btop); otherwise the same as
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
#ifndef _MACHDEP_M68K_PMAP_H_
#define _MACHDEP_M68K_PMAP_H_
#import <mach/vm_statistics.h>
#import <mach/m68k/vm_param.h>
struct pmap {
	unsigned int		mmu_rp[2];
	void			*pt1;
	int			ref_count;
	struct pmap_statistics	stats;		/* resident_count at 0x10 (_task_info) */
};
typedef struct pmap *pmap_t;
#define PMAP_NULL	((pmap_t) 0)
#define PMAP_ACTIVATE(pmap, thread, cpu)
#define PMAP_DEACTIVATE(pmap, thread, cpu)
#define PMAP_CONTEXT(pmap, thread)
#define pmap_resident_count(pmap)	((pmap)->stats.resident_count)
#define pmap_phys_address(frame)	((vm_offset_t) (m68k_ptob(frame)))	/* (Darwin) */
#define pmap_phys_to_frame(phys)	((unsigned int) (m68k_btop(phys)))	/* (Darwin) */
#endif
