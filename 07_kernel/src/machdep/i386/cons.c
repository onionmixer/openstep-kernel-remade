/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 12-Aug-87  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 */ 

/*
 * Indirect driver for console.
 */
/*
 * The cons part of the line marked "plan 400 (Darwin)" is the same as
 * Darwin 0.1 kernel/bsd/dev/i386/cons.c:47 (kernel-1), whose notice is:
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

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/conf.h>
#import <sys/user.h>
#import <sys/ioctl.h>
#import <sys/tty.h>
#import <sys/proc.h>
#import <sys/uio.h>
struct tty	cons, *cons_tp;	/* plan 276: was next/cons.h (m68k), as tty.c plan 245; plan 400 (Darwin): defined here (cons as Darwin 0.1 bsd/dev/i386/cons.c:47, cons_tp D059) */

/*ARGSUSED*/
cnopen(dev, flag)
	dev_t dev;
	int flag;
{
	dev_t device;
	register struct proc *pp;
	register struct posix_proc *px;		/* plan 276 */
	struct nty *np;				/* plan 276 */

	np = ttynty(cons_tp);			/* plan 276: POSIX controlling tty, as ttyopen (tty.c plan 245) */
	device = cons_tp->t_dev;
	
	/*
	 *  Must setup pgrp/controlling tty here because we cannot pass
	 *  "dev" as the first argument to the open routine (must be
	 *  "device" otherwise we loop in ttyopen).  We want the
	 *  u.u_ttyd to be set to the indirect "dev" and not the dereferenced
	 *  "device".
	 */
	pp = u.u_procp;
	px = get_posix_proc(pp->p_pid);		/* plan 276 */
	if (pp->p_posix) {
		if (px->p_session->s_leader == pp &&
		    px->p_session->s_ttyp == 0 &&
		    np->t_session == 0 &&
		    !px->p_posix_noctty) {
			u.u_ttyp = cons_tp;
			u.u_ttyd = dev;
			np->t_session = px->p_session;
			px->p_session->s_ttyp = cons_tp;
			np->t_posix_pgrp = px->p_posix_pgrp;
			cons_tp->t_pgrp = px->p_pgid;
			pp->p_flag |= SCTTY;
		}
	} else if ((pp->p_flag & SCTTY) == 0) {
		u.u_ttyp = cons_tp;
		u.u_ttyd = dev;
		np->t_session = px->p_session;
		px->p_session->s_ttyp = cons_tp;
		if (cons_tp->t_pgrp == 0) {
			enterpgrp(pp, pp->p_pid, 0);
			np->t_posix_pgrp = px->p_posix_pgrp;
			cons_tp->t_pgrp = px->p_pgid;
		} else if (pp->p_pgrp != cons_tp->t_pgrp)
			enterpgrp(pp, cons_tp->t_pgrp, 0);
	}
	return ((*cdevsw[major(device)].d_open)(device, flag));
}

/*ARGSUSED*/
cnread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	dev_t device;

	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_read)(device, uio));
}

/*ARGSUSED*/
cnwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	dev_t device;

	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_write)(device, uio));
}

/*ARGSUSED*/
cnioctl(dev, cmd, addr, flag)
	dev_t dev;
	int cmd;
	caddr_t addr;
	int flag;
{
	dev_t device;

	if (cmd == TIOCNOTTY) {
		/* plan 276: POSIX session form, as syioctl (tty_tty.c plan 156) */
		struct proc *p;
		struct posix_proc *px;

		p = u.u_procp;
		px = get_posix_proc(p->p_pid);
		cons_tp = &cons;
		if (SESS_LEADER(p, px)) {
			px->p_session->s_ttyp = 0;
			px->p_session->s_ttyd = 0;
		}
		p->p_flag &= ~SCTTY;
		return (0);
	}
	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_ioctl)(device, cmd, addr, flag));
}

/*ARGSUSED*/
cnselect(dev, flag)
	dev_t dev;
	int flag;
{
	dev_t device;

	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_select)(device, flag));
}

cngetc()
{
	dev_t device;

	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_getc)(device));
}

/*ARGSUSED*/
cnputc(c)
	char c;
{
	dev_t device;

	device = cons_tp->t_dev;
	return ((*cdevsw[major(device)].d_putc)(device, c));
}

#if	NCPUS > 1
slave_cnenable()
{
	/* FIXME: what to do here? */
}
#endif	NCPUS > 1
