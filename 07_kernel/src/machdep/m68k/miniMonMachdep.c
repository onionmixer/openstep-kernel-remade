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

/* Modified 2026-10-30: see 07_kernel/MODIFICATIONS.md */

/*
 * Copyright (c) 1993 NeXT Computer, Inc.  All rights reserved.
 *
 * miniMonMachdep.c -- Machine-dependent code for mini-monitor.
 *
 * HISTORY
 * 04-Oct-1993		Curtis Galloway at NeXT
 *	Created.
 *
 */

/*
 * m68k: the mini-monitor machine-dependent entries of the 1997 m68k kernel
 * (plans 601-602, D024, D103, D115, D135).  The six entries of the m68k
 * original [0x4094a7c, 0x4094ab2), in the order of the i386 file, are
 * "pea a6@; movel sp,a6; unlk a6; rts", with "clrl d0" before the unlk in
 * miniMonReboot, miniMonHalt and miniMonGdb (they return FALSE); the other
 * three have empty bodies.  _miniMonMDCommands (0x40b2b92, 12 B of zero) is
 * the end entry only.  This file keeps the head and the six signatures of
 * machdep/i386/miniMonMachdep.c; the i386 bodies, the i386 commands
 * (miniMonBacktrace, miniMonDump and their helpers ishex, xx, xtoi) and the
 * <sys/reboot.h> and <kern/thread.h> imports are not in it.  Lines marked
 * plan 602 differ from the i386 file.
 */
#import <kern/miniMonPrivate.h>

miniMonCommand_t miniMonMDCommands[] =
{
    {0,0,0}	/* plan 602 (D135): the end entry only (the m68k original has no command) */
};

extern boolean_t
miniMonReboot(char *line)
{
    return FALSE;
}

extern boolean_t
miniMonHalt(char *line)
{
    return FALSE;
}

extern boolean_t
miniMonGdb(char *line)
{
    return FALSE;
}

extern int
miniMonTryGetchar(void)
{
}

extern int
miniMonGetchar(void)
{
}

extern void
miniMonPutchar(int c)
{
}
