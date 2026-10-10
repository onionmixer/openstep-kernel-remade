/*
 * machdep/m68k/machspl.h -- m68k spl type (plan 430/433, authored, D024).
 * The original m68k kernel defines no _spl* symbol; the inline spl
 * functions come from the SDK header bsd/m68k/spl.h (plan 426, D069).
 */

/*
 * The line marked "(Darwin)" is machdep/i386/machspl.h:60, the same as
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
#ifndef _MACHDEP_M68K_MACHSPL_H_
#define _MACHDEP_M68K_MACHSPL_H_
typedef int spl_t;		/* (Darwin) */
#import <bsd/m68k/spl.h>
#endif
