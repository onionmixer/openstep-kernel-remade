/*
 * machdep/m68k/xpr.h -- m68k XPR timestamp (plan 430/433, authored, D024).
 * XPR_TIMESTAMP and the eventc.h import follow NeXTMach mk-108.1
 * next/xpr.h:18-20 (import path mapped to machdep/m68k).
 */
/* 
 * NeXTMach next/xpr.h:
 * Copyright (c) 1987, 1988, 1989 NeXT, Inc.
 */

/*
 * The lines marked "(Darwin)" are machdep/i386/xpr.h:45-47, the same as
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
#ifndef _MACHDEP_M68K_XPR_H_
#define _MACHDEP_M68K_XPR_H_
#ifdef	KERNEL_BUILD		/* (Darwin) */
#import "uxpr.h"		/* (Darwin) */
#import "xpr_debug.h"		/* (Darwin) */
#endif
#import <machdep/m68k/eventc.h>
#import <mach/machine.h>	/* plan 430: i386 gets it through the DriverKit chain of its xpr.h */
#define XPR_TIMESTAMP	event_get()
#endif
