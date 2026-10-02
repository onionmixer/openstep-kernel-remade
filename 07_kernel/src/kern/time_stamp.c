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

/* Modified 2026-10-01: see 07_kernel/MODIFICATIONS.md */

/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * 15-Feb-88  Gregg Kellogg (gk) at NeXT
 *	NeXT: use microsecond counter like multimax
 *
 * 16-Jun-87  David Black (dlb) at Carnegie-Mellon University
 *	machtimer.h --> timer.h  Changed to cpp symbols for multimax.
 *
 *  5-Apr-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	ts.h -> time_stamp.h
 *
 * 30-Mar-87  David Black (dlb) at Carnegie-Mellon University
 *	Created.
 */ 
#import <mach/kern_return.h>
#import <kern/time_stamp.h>
#import <kern/clock.h>

/* Reconstructed from the original binary (no reference source), 2026-10-01: see 07_kernel/MODIFICATIONS.md */
extern unsigned long long clock_value(clock_type_t which_clock);
extern void ns_time_to_tsval(unsigned long long value, struct tsval *tsp);

#if	m68k
#import <machdep/m68k/eventc.h>
#endif	m68k

/*
 *	ts.c - kern_timestamp system call.
 */

kern_return_t kern_timestamp(tsp)
	struct	tsval	*tsp;
{
	struct tsval	ts;

#if	m68k
	event_set_ts(&ts);
#else	m68k
	/* Reconstructed from the original binary (no reference source), 2026-10-01: see 07_kernel/MODIFICATIONS.md */
	unsigned long long	now;

	now = clock_value(System);
	ns_time_to_tsval(now, &ts);
#endif	m68k

	if (copyout(&ts, tsp, sizeof(struct tsval)) != KERN_SUCCESS)
		return(KERN_INVALID_ADDRESS);

	return(KERN_SUCCESS);
}
