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

/* Modified 2026-10-26: see 07_kernel/MODIFICATIONS.md */

/*
 * Copyright (c) 1993 NeXT Computer, Inc.  All rights reserved.
 *
 * kdp_machdep.c -- Machine-dependent code for Remote Debugging Protocol
 *
 * History:
 *
 * 10 Nov 1997	Herb Ruth [ruth1@apple.com]
 *	Added extern declarations for implicit function
 *	declarations. Changed dprintf macro to call kprintf()
 *	instead of safe_prf() when KDP_TEST_HARNESS==1.
 */

/*
 * m68k: machine-dependent KDP routines of the 1997 m68k kernel (plans 530-531,
 * D024, D103, D115).  The 13 entries of the m68k original (0x409295e-0x40929c6,
 * in this order) are 8 B each, "pea a6@; movel sp,a6; unlk a6; rts"; their source
 * bodies and signatures are not fixed by those bytes.  This file keeps the head
 * and the function signatures of machdep/i386/kdp_machdep.c (the i386 state
 * routines kdp_getstate/kdp_setstate are not in the m68k original) and gives
 * every function an empty body.  Lines marked plan 531 are not in the i386 file.
 */

#import <mach/boolean.h>	/* plan 531: boolean_t for kern/kdp_internal.h */
#import <kern/kdp_internal.h>

void
kdp_exception(
    unsigned char	*pkt,
    int			*len,
    unsigned short	*remote_port,
    unsigned int	exception,
    unsigned int	code,
    unsigned int	subcode
)
{
}

void
kdp_exception_ack(
    unsigned char	*pkt,
    int			len
)
{
}

kdp_error_t
kdp_machine_read_regs(
    unsigned int cpu,
    unsigned int flavor,
    char *data,
    int *size
)
{
}

kdp_error_t
kdp_machine_write_regs(
    unsigned int cpu,
    unsigned int flavor,
    char *data,
    int *size
)
{
}

void
kdp_machine_hostinfo(
    kdp_hostinfo_t *hostinfo
)
{
}

void
kdp_panic(
    const char		*msg
)
{
}

void
kdp_reboot(void)
{
}

int
kdp_intr_disbl(void)
{
}

void
kdp_intr_enbl(int s)
{
}

void
kdp_en_send_pkt(void *pkt, unsigned int pkt_len)
{
}

void
kdp_en_recv_pkt(void *pkt, unsigned int *pkt_len, unsigned int timeout)
{
}

void
kdp_us_spin(int usec)
{
}

void
kdp_flush_cache(void)
{
}
