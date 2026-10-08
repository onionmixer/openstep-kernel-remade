/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * Revision 2.7  89/01/30  22:02:58  rpd
 * 	Added declaration of selwait.  (The one in sys/systm.h is extern now.)
 * 	[89/01/25  14:52:22  rpd]
 * 
 * 04-Dec-89  Mike DeMoney (mike) at NeXT
 *  Added support for 8 bit through in cooked mode (for EUC support)
 *
 * 26-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes. Removed dir.h
 *
 * 27-Feb-88  John Seamons (jks) at NeXT
 *	Changed macros to conform to ANSI C.
 *
 * 27-Oct-87  David Golub (dbg) at Carnegie-Mellon University
 *	MACH_TT: select routines really do have to check whether the
 *	thread is waiting.  Pointer to select()'ing thread could be
 *	non-zero from the last time a select was done.
 *
 * 20-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Changed inode.h to vnode.h
 *
 * 17-Jun-87  Bill Bolosky (bolosky) at Carnegie-Mellon University
 *	Added several 'spltty's around code which must atomically
 *	set and clear bits in memory, since some machines don't
 *	have instructions for this.  Intentionally neglected to
 *	include CS_BUGFIX conditionals, as they would have been
 *	excessively ugly.
 *
 *  1-Apr-87  Robert Baron (rvb) at Carnegie-Mellon University
 *	Well, dynix code thinks NTTYDISC is 1 and we think it is 2.  So
 *	amuse dynix for now.
 *
 *  5-Mar-87  David L. Black (dlb) at Carnegie-Mellon University
 *	Can't switch consoles on Multimax.
 *
 * 31-Jan-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Support for multiple threads.
 */

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)tty.c	7.1 (Berkeley) 6/5/86
 */

#import <machine/reg.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/ioctl.h>
#import <sys/tty.h>
#import <sys/proc.h>
#import <sys/vnode.h>
#import <sys/file.h>
#import <sys/conf.h>
#import <sys/buf.h>
#import <sys/dk.h>
#import <sys/uio.h>
#import <sys/kernel.h>
#import <sys/syslog.h>		/* plan 245: log() */
#import <sys/termios.h>		/* plan 245: struct termios */

#import <machine/spl.h>

#import <kern/thread.h>		/* plan 245: thread_t */

extern struct tty	cons, *cons_tp;	/* plan 245: was next/cons.h */
#define	KMIOCDISABLCONS	_IO('k', 8)	/* plan 245: name from Darwin 0.1 bsd/dev/kmreg_com.h:92 */

int selwait;

/*
 * Table giving parity for characters and indicating
 * character classes to tty driver.  In particular,
 * if the low 6 bits are 0, then the character needs
 * no special processing on output.
 */

char partab[] = {	/* plan 245: 4.2 values (word characters 0100) */
	0001,	0201,	0201,	0001,	0201,	0001,	0001,	0201,
	0202,	0004,	0003,	0201,	0005,	0206,	0201,	0001,
	0201,	0001,	0001,	0201,	0001,	0201,	0201,	0001,
	0001,	0201,	0201,	0001,	0201,	0001,	0001,	0201,
	0200,	0000,	0000,	0200,	0000,	0200,	0200,	0000,
	0000,	0200,	0200,	0000,	0200,	0000,	0000,	0200,
	0100,	0300,	0300,	0100,	0300,	0100,	0100,	0300,
	0300,	0100,	0000,	0200,	0000,	0200,	0200,	0000,
	0200,	0100,	0100,	0300,	0100,	0300,	0300,	0100,
	0100,	0300,	0300,	0100,	0300,	0100,	0100,	0300,
	0100,	0300,	0300,	0100,	0300,	0100,	0100,	0300,
	0300,	0100,	0100,	0200,	0000,	0200,	0200,	0300,
	0000,	0300,	0300,	0100,	0300,	0100,	0100,	0300,
	0300,	0100,	0100,	0300,	0100,	0300,	0300,	0100,
	0300,	0100,	0100,	0300,	0100,	0300,	0300,	0100,
	0100,	0300,	0300,	0000,	0200,	0000,	0000,	0201,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100,
	0100,	0100,	0100,	0100,	0100,	0100,	0100,	0100
};

/*
 * Input mapping table-- if an entry is non-zero, when the
 * corresponding character is typed preceded by "\" the escape
 * sequence is replaced by the table value.  Mostly used for
 * upper-case only terminals.
 */
char	maptab[] ={
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,'|',000,000,000,000,000,'`',
	'{','}',000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,'~',000,
	000,'A','B','C','D','E','F','G',
	'H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W',
	'X','Y','Z',000,000,000,000,000,
};

short	tthiwat[NSPEEDS] = {	/* plan 245: 4.2 values */
	100, 100, 100, 100, 100, 100, 100, 200, 200, 400, 400, 400, 650, 650, 1300, 3000, 3000, 3000, 4000, 4000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
};
short	ttlowat[NSPEEDS] = {	/* plan 245: 4.2 values */
	30, 30, 30, 30, 30, 30, 30, 50, 50, 120, 120, 120, 200, 200, 400, 600, 400, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600
};
short	tthog[NSPEEDS] = {	/* plan 245: 4.2 values */
	1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024
};

struct	ttychars ttydefaults = {
	CERASE,	CKILL,	CINTR,	CQUIT,	CSTART,	CSTOP,	CEOF,
	CBRK,	CSUSP,	CDSUSP, CRPRNT, CFLUSH, CWERASE,CLNEXT
};

/*
 * plan 245: set the special character map from the termios state.
 */
#define	SETSPEC(tp, c) \
	((tp)->t_spec[(u_char)(c) >> 5] |= 1 << ((c) & 0x1f))
#define	SPEC(tp, ch) \
	{ char c = (ch); if (c != (char)0377) SETSPEC(tp, c); }

ttysetspec(np)
	register struct nty *np;
{
	register struct tty *tp = np->t;
	int i;
	long flags = tp->t_flags;
	register long pflags = np->t_pflags;

	for (i = 0; i < sizeof (tp->t_spec) / sizeof (tp->t_spec[0]); i++)
		tp->t_spec[i] = 0;
	if (flags & RAW)
		return;
	if (pflags & TP_IEXTEN) {
		SPEC(tp, tp->t_lnextc);
		SPEC(tp, tp->t_flushc);
	}
	if (pflags & TP_ISIG) {
		SPEC(tp, tp->t_intrc);
		SPEC(tp, tp->t_quitc);
		SPEC(tp, tp->t_suspc);
	}
	if (pflags & TP_IXON) {
		SPEC(tp, tp->t_stopc);
		SPEC(tp, tp->t_startc);
	}
	if ((flags & CRMOD) || (pflags & (TP_IGNCR|TP_ICRNL)))
		SETSPEC(tp, '\r');
	if (pflags & TP_INLCR)
		SETSPEC(tp, '\n');
	if ((flags & CBREAK) == 0) {
		SPEC(tp, tp->t_erase);
		SPEC(tp, tp->t_kill);
		SPEC(tp, tp->t_werasc);
		SPEC(tp, tp->t_rprntc);
	}
	if (flags & LCASE)
		for (i = 0; i < 0200; i++) SETSPEC(tp, i);
	if ((pflags & (TP_PARMRK|TP_IGNPAR|TP_PARENB)) == (TP_PARMRK|TP_PARENB))
		SETSPEC(tp, 0377);
}

static inline int
ttyspec(tp, c)				/* plan 245 */
struct tty *tp;
int c;
{
	return((tp->t_spec[c >> 5] >> (c & 0x1F)) & 1);
}
	

ttychars(tp)
	struct tty *tp;
{
	register struct nty *np = ttynty(tp);	/* plan 245 */

	tp->t_chars = ttydefaults;
	np->t_quote = '\\';
	np->t_min = 1;
	np->t_time = 0;
	ttysetspec(np);
}

/*
 * Wait for output to drain, then flush input waiting.
 */
ttywflush(tp)
	register struct tty *tp;
{

	ttywait(tp);
	ttyflush(tp, FREAD);
}

ttywait(tp)
	register struct tty *tp;
{
	register int s = spltty();

	while ((tp->t_outq.c_cc || tp->t_state&(TS_BUSY|TS_OUTPUTBUSY)) &&
	    (tp->t_state&TS_CARR_ON ||			/* plan 245 */
	     ttynty(tp)->t_pflags & TP_CLOCAL)) {
		(*tp->t_oproc)(tp);
		tp->t_state |= TS_ASLEEP;
		sleep((caddr_t)&tp->t_outq, TTOPRI);
	}
	splx(s);
}

/*
 * Flush all TTY queues
 */
ttyflush(tp, rw)
	register struct tty *tp;
{
	register s;

	s = spltty();
	if (rw & FREAD) {
		while (getc(&tp->t_canq) >= 0)
			;
		wakeup((caddr_t)&tp->t_rawq);
	}
	if (rw & FWRITE) {
		wakeup((caddr_t)&tp->t_outq);
		tp->t_state &= ~TS_TTSTOP;
		(*cdevsw[major(tp->t_dev)].d_stop)(tp, rw);
		while (getc(&tp->t_outq) >= 0)
			;
	}
	if (rw & FREAD) {
		while (getc(&tp->t_rawq) >= 0)
			;
		tp->t_rocount = 0;
		tp->t_rocol = 0;
		tp->t_state &= ~(TS_LOCAL|TS_INPUTFULL);
	}
	splx(s);
}

/*
 * Restart typewriter output following a delay
 * timeout.
 * The name of the routine is passed to the timeout
 * subroutine and it is called during a clock interrupt.
 */
ttrstrt(tp)
	register struct tty *tp;
{
	register int ipl = spltty();

	if (tp == 0)
		panic("ttrstrt");
	tp->t_state &= ~TS_TIMEOUT;
	(*linesw[tp->t_line].l_start)(tp);
        splx(ipl);
}

/*
 * Start output on the typewriter. It is used from the top half
 * after some characters have been put on the output queue,
 * from the interrupt routine to transmit the next
 * character, and after a timeout has finished.
 */
ttstart(tp)
	register struct tty *tp;
{
	register s;

	s = spltty();
	if ((tp->t_state & (TS_TIMEOUT|TS_TTSTOP|TS_BUSY|TS_OUTPUTFULL)) == 0 &&	/* plan 245 */
	    tp->t_oproc)		/* kludge for pty */
		(*tp->t_oproc)(tp);
	splx(s);
}

/*
 * Common code for tty ioctls.
 */
/*ARGSUSED*/
ttioctl(tp, com, data, flag)
	register struct tty *tp;
	caddr_t data;
{
	struct nty *np = ttynty(tp);		/* plan 245 */
	int dev = tp->t_dev;
	extern int nldisp;
	extern nodev();
	int s;
	register int newflags;

	/*
	 * If the ioctl involves modification,
	 * hang if in the background.
	 */
	switch (com) {

	case TIOCSETD:
	case TIOCSETP:
	case TIOCSETN:
	case TIOCFLUSH:
	case TIOCSETC:
	case TIOCSLTC:
	case TIOCSPGRP:
	case TIOCLBIS:
	case TIOCLBIC:
	case TIOCLSET:
	case TIOCSTI:
	case TIOCSWINSZ:
	case TIOCSETA:				/* plan 245 */
	case TIOCSETAW:
	case TIOCSETAF:
	case TIOCDRAIN:
	case TIOCSTART:
	case TIOCSTOP:
	case TIOCSBRK:
	case TIOCCBRK:
		while (u.u_procp->p_pgrp != tp->t_pgrp && tp == u.u_ttyp &&
		   (u.u_procp->p_flag&SVFORK) == 0 &&
		   !(u.u_procp->p_sigignore & sigmask(SIGTTOU)) &&
		   !(u.u_procp->p_sigmask & sigmask(SIGTTOU))) {
			gsignal(u.u_procp->p_pgrp, SIGTTOU);
			sleep((caddr_t)&lbolt, TTOPRI);
		}
		break;
	}

	/*
	 * Process the ioctl.
	 */
	switch (com) {

	/* get internal state - needed for TS_EXTPROC bit */
	case TIOCGSTATE:
		*(int *)data = tp->t_state;
		break;

	/* get discipline number */
	case TIOCGETD:
		*(int *)data = tp->t_line;
		break;

	/* set line discipline */
	case TIOCSETD: {
		register int t = *(int *)data;
		int error = 0;

		if ((unsigned) t >= nldisp)
			return (ENXIO);
#if	NeXT
		if (linesw[t].l_open == nodev)
			return ENXIO;
#endif	NeXT
		if (t != tp->t_line) {
			s = spltty();
			(*linesw[tp->t_line].l_close)(tp);
#if	NeXT
			tp->t_ldisc_data = NULL;
#endif	NeXT
			error = (*linesw[t].l_open)(dev, tp);
			if (error) {
#if	NeXT
				tp->t_ldisc_data = NULL;
#endif	NeXT
				(void) (*linesw[tp->t_line].l_open)(dev, tp);
				splx(s);
				return (error);
			}
			tp->t_line = t;
			splx(s);
		}
		break;
	}

	/* prevent more opens on channel */
	case TIOCEXCL:
		s = spltty();
		tp->t_state |= TS_XCLUDE;
		splx(s);
		break;

	case TIOCNXCL:
		s = spltty();
		tp->t_state &= ~TS_XCLUDE;
		splx(s);
		break;

	/* hang up line on last close */
	case TIOCHPCL:
		s = spltty();
		tp->t_state |= TS_HUPCLS;
		splx(s);
		break;

	case TIOCFLUSH: {
		register int flags = *(int *)data;

		if (flags == 0)
			flags = FREAD|FWRITE;
		else
			flags &= FREAD|FWRITE;
		ttyflush(tp, flags);
		break;
	}

	/* return number of characters immediately available */
	case FIONREAD:
		s = spltty();
		*(int *)data = ttnread(np);	/* plan 245 */
		splx(s);
		break;

	case TIOCOUTQ:
		*(int *)data = tp->t_outq.c_cc;
		break;

	case TIOCSTOP:
		s = spltty();
		if ((tp->t_state&TS_TTSTOP) == 0) {
			tp->t_state |= TS_TTSTOP;
			(*cdevsw[major(tp->t_dev)].d_stop)(tp, 0);
		}
		splx(s);
		break;

	case TIOCSTART:
		s = spltty();
		if ((tp->t_state&TS_TTSTOP) || (tp->t_flags&FLUSHO)) {
			tp->t_state &= ~TS_TTSTOP;
			tp->t_flags &= ~FLUSHO;
			ttstart(tp);
		}
		splx(s);
		break;

	/*
	 * Simulate typing of a character at the terminal.
	 */
	case TIOCSTI:
		if (u.u_uid && (flag & FREAD) == 0)
			return (EPERM);
		if (u.u_uid && u.u_ttyp != tp)
			return (EACCES);
		s = spltty();
		(*linesw[tp->t_line].l_rint)(*(u_char *)data, tp);	/* plan 245 */
		splx(s);
		break;

	case TIOCSETP:
	case TIOCSETN: {
		register struct sgttyb *sg = (struct sgttyb *)data;

		tp->t_erase = sg->sg_erase;
		tp->t_kill = sg->sg_kill;
		tp->t_ispeed = sg->sg_ispeed;
		tp->t_ospeed = sg->sg_ospeed;
		newflags = (tp->t_flags&0xffff0000) | (sg->sg_flags&0xffff);
		s = spltty();
		if (tp->t_flags&RAW || newflags&RAW || com == TIOCSETP) {
			ttywait(tp);
			ttyflush(tp, FREAD);
		} else if ((tp->t_flags&CBREAK) != (newflags&CBREAK)) {
			if (newflags&CBREAK) {
				struct clist tq;

				catq(&tp->t_rawq, &tp->t_canq);
				tq = tp->t_rawq;
				tp->t_rawq = tp->t_canq;
				tp->t_canq = tq;
			} else {
				tp->t_flags |= PENDIN;
				newflags |= PENDIN;
				ttwakeup(tp);
			}
		}
		tp->t_flags = newflags;
		NTYDEFAULTS(np);		/* plan 245 */
		ttysetspec(np);
		if (tp->t_flags&RAW) {
			tp->t_state &= ~TS_TTSTOP;
			ttstart(tp);
		}
		splx(s);
		break;
	}

	/* send current parameters to user */
	case TIOCGETP: {
		register struct sgttyb *sg = (struct sgttyb *)data;

		sg->sg_ispeed = tp->t_ispeed;
		sg->sg_ospeed = tp->t_ospeed;
		sg->sg_erase = tp->t_erase;
		sg->sg_kill = tp->t_kill;
		sg->sg_flags = tp->t_flags;
		break;
	}

	case FIONBIO:
		s = spltty();
		if (*(int *)data)
			tp->t_state |= TS_NBIO;
		else
			tp->t_state &= ~TS_NBIO;
		splx(s);
		break;

	case FIOASYNC:
		s = spltty();
		if (*(int *)data)
			tp->t_state |= TS_ASYNC;
		else
			tp->t_state &= ~TS_ASYNC;
		splx(s);
		break;

	case TIOCGETC:
		bcopy((caddr_t)&tp->t_intrc, data, sizeof (struct tchars));
		break;

	case TIOCSETC:
		bcopy(data, (caddr_t)&tp->t_intrc, sizeof (struct tchars));
		ttysetspec(np);
		break;

	/* set/get local special characters */
	case TIOCSLTC:
		bcopy(data, (caddr_t)&tp->t_suspc, sizeof (struct ltchars));
		ttysetspec(np);
		break;

	case TIOCGLTC:
		bcopy((caddr_t)&tp->t_suspc, data, sizeof (struct ltchars));
		break;

	/*
	 * Modify local mode word.
	 */
	case TIOCLBIS:
		tp->t_flags |= *(int *)data << 16;
		NTYDEFAULTS(np);		/* plan 245 */
		ttysetspec(np);
		break;

	case TIOCLBIC:
		tp->t_flags &= ~(*(int *)data << 16);
		NTYDEFAULTS(np);		/* plan 245 */
		ttysetspec(np);
		break;

	case TIOCLSET:
		tp->t_flags &= 0xffff;
		tp->t_flags |= *(int *)data << 16;
		NTYDEFAULTS(np);		/* plan 245 */
		ttysetspec(np);
		break;

	case TIOCLGET:
		*(int *)data = ((unsigned) tp->t_flags) >> 16;
		break;

	/*
	 * Allow SPGRP only if tty is open for reading.
	 * Quick check: if we can find a process in the new pgrp,
	 * this user must own that process.
	 * SHOULD VERIFY THAT PGRP IS IN USE AND IS THIS USER'S.
	 */
	case TIOCSPGRP: {
		struct proc *p = u.u_procp;
		int pgrp = *(int *)data;

		if (p->p_posix) {		/* plan 245: POSIX job control */
			register struct pgrp *pg = pgfind(pgrp);
			register struct posix_proc *px = get_posix_proc(p->p_pid);

			if (pgrp <= 0 || pg == 0)
				return (EINVAL);
			if (!isctty(p, px, np))
				return (ENOTTY);
			if (pg->pg_session != px->p_session)
				return (EPERM);
			np->t_posix_pgrp = pg;
			tp->t_pgrp = pg->pg_id;
			break;
		}
		if (u.u_uid && (flag & FREAD) == 0)
			return (EPERM);
		tp->t_pgrp = pgrp;
		break;
	}

	case TIOCGPGRP:
		if (u.u_procp->p_posix) {	/* plan 245 */
			register struct proc *p = u.u_procp;
			register struct posix_proc *px = get_posix_proc(p->p_pid);

			if (!isctty(p, px, np) || px->p_session->s_ttyp == 0)
				return (ENOTTY);
		}
		*(int *)data = tp->t_pgrp;
		break;

	case TIOCSWINSZ:
		if (bcmp((caddr_t)&tp->t_winsize, data,
		    sizeof (struct winsize))) {
			tp->t_winsize = *(struct winsize *)data;
			gsignal(tp->t_pgrp, SIGWINCH);
		}
		break;

	case TIOCGWINSZ:
		*(struct winsize *)data = tp->t_winsize;
		break;

	case TIOCSCONS:
		/* Set current console device to this line */
		/* plan 245: tell the old console device */
		if (tp != &cons)
			(*cdevsw[major(cons_tp->t_dev)].d_ioctl)
			    (cons_tp->t_dev, KMIOCDISABLCONS, 0, 0);
		cons_tp = tp;
		break;

	case TIOCGETA:				/* plan 245: POSIX termios */
		ttgettermios(np, (struct termios *)data);
		break;

	case TIOCSETA:
	case TIOCSETAW:
	case TIOCSETAF: {
		register struct termios *t = (struct termios *)data;
		int canon, oldcanon;

		s = spltty();
		if (t->c_ispeed == 0)
			t->c_ispeed = t->c_ospeed;
		if (com == TIOCSETAW || com == TIOCSETAF) {
			ttywait(tp);
			if (com == TIOCSETAF)
				ttyflush(tp, FREAD);
		}
		if ((t->c_cflag & CIGNORE) == 0 &&
		    (tp->t_state & TS_CARR_ON) == 0 &&
		    (np->t_pflags & TP_CLOCAL) && (t->c_cflag & CLOCAL) == 0) {
			tp->t_state &= ~TS_ISOPEN;
			tp->t_state |= TS_WOPEN;
			ttwakeup(tp);
		}
		oldcanon = (tp->t_flags & (RAW|CBREAK)) == 0;
		canon = (t->c_lflag & ICANON) != 0;
		if (com != TIOCSETAF && canon != oldcanon) {
			if (canon) {
				tp->t_flags |= PENDIN;
				ttwakeup(tp);
			} else {
				struct clist tq;

				catq(&tp->t_rawq, &tp->t_canq);
				tq = tp->t_rawq;
				tp->t_rawq = tp->t_canq;
				tp->t_canq = tq;
			}
		}
		if (canon == 0 && (np->t_min != t->c_cc[VMIN] ||
		    np->t_time != t->c_cc[VTIME]))
			ttwakeup(tp);
		ttsettermios(np, t);
		ttysetspec(np);
		splx(s);
		break;
	}

	case TIOCDRAIN:
		ttywait(tp);
		break;

	default:
		return (-1);
	}
	return (0);
}

ttnread(np)				/* plan 245: struct nty */
	struct nty *np;
{
	register struct tty *tp = np->t;
	int nread = 0;

	if (tp->t_flags & PENDIN)
		ttypend(tp);
	nread = tp->t_canq.c_cc;
	if (tp->t_flags & (RAW|CBREAK)) {
		nread += tp->t_rawq.c_cc;
		if (nread < np->t_min)		/* plan 245 */
			nread = 0;
	}
	return (nread);
}

ttselect(tp, rw)
	struct tty *tp;
	int rw;
{
	int nread;
	register struct nty *np = ttynty(tp);	/* plan 245 */
	int s = spltty();

	switch (rw) {

	case FREAD:
		nread = ttnread(np);
		if ((nread > 0) ||
		    ((np->t_pflags & TP_CLOCAL) == 0 &&	/* plan 245 */
		     (tp->t_state & TS_CARR_ON) == 0))
			goto win;
		if (selthreadcache(&tp->t_rsel))	/* plan 245 */
			tp->t_state |= TS_RCOLL;
		break;

	case FWRITE:
		if (tp->t_outq.c_cc <= TTLOWAT(tp))
			goto win;
		if (selthreadcache(&tp->t_wsel))	/* plan 245 */
			tp->t_state |= TS_WCOLL;
		break;
	}
	splx(s);
	return (0);
win:
	splx(s);
	return (1);
}

/*
 * Initial open of tty, or (re)entry to line discipline.
 * Establish a process group for distribution of
 * quits and interrupts from the tty.
 */
ttyopen(dev, tp)
	dev_t dev;
	register struct tty *tp;
{
	register struct proc *pp;
	register struct posix_proc *px;		/* plan 245 */
	struct nty *np;
        int oldipl;

	np = ttynty(tp);			/* plan 245: POSIX controlling tty */
	pp = u.u_procp;
	px = get_posix_proc(pp->p_pid);
	if (pp->p_posix) {
		if (px->p_session->s_leader == pp &&
		    px->p_session->s_ttyp == 0 &&
		    np->t_session == 0 &&
		    !px->p_posix_noctty) {
			u.u_ttyp = tp;
			u.u_ttyd = dev;
			np->t_session = px->p_session;
			px->p_session->s_ttyp = tp;
			np->t_posix_pgrp = px->p_posix_pgrp;
			tp->t_pgrp = px->p_pgid;
			pp->p_flag |= SCTTY;
		}
	} else if ((pp->p_flag & SCTTY) == 0) {
		u.u_ttyp = tp;
		u.u_ttyd = dev;
		np->t_session = px->p_session;
		px->p_session->s_ttyp = tp;
		if (tp->t_pgrp == 0) {
			enterpgrp(pp, pp->p_pid, 1);
			np->t_posix_pgrp = px->p_posix_pgrp;
			tp->t_pgrp = px->p_pgid;
		} else if (pp->p_pgrp != tp->t_pgrp)
			enterpgrp(pp, tp->t_pgrp, 0);
		pp->p_flag |= SCTTY;
	}
	tp->t_dev = dev;
	oldipl = spltty();
	tp->t_state &= ~TS_WOPEN;
	if ((tp->t_state & TS_ISOPEN) == 0) {
		tp->t_state |= TS_ISOPEN;
		splx(oldipl);
		NTYDEFAULTS(np);		/* plan 245 */
		bzero((caddr_t)&tp->t_winsize, sizeof(tp->t_winsize));
		if (tp->t_line != NTTYDISC)
			ttywflush(tp);
	} else splx(oldipl);
	ttysetspec(np);				/* plan 245 */
	return (0);
}

/*
 * "close" a line discipline
 */
ttylclose(tp)
	register struct tty *tp;
{

	ttywflush(tp);
	tp->t_line = 0;
}

/*
 * clean tp on last close
 */
ttyclose(tp)
	register struct tty *tp;
{
	register struct nty *np = ttynty(tp);	/* plan 245 */
	int s;

#if	NeXT
	if (cons_tp == tp) {
		cons_tp = &cons;

		/* plan 245: tell the old console device */
		(*cdevsw[major(tp->t_dev)].d_ioctl)
		    (tp->t_dev, KMIOCDISABLCONS, 0, 0);
	}
#endif	NeXT

	ttyflush(tp, FREAD|FWRITE);
	if (u.u_procp->p_posix) {		/* plan 245 */
		np->t_session = 0;
		np->t_posix_pgrp = 0;
	}
	if (u.u_ttyp == tp)			/* plan 245 */
		u.u_procp->p_flag &= ~SCTTY;
	tp->t_pgrp = 0;
	tp->t_state = 0;
#if	NeXT
	tp->t_line = 0;
	tp->t_ldisc_data = NULL;
#endif	NeXT
	s = spltty();				/* plan 245 */
	selthreadclear(&tp->t_wsel);
	selthreadclear(&tp->t_rsel);
	splx(s);
}

/*
 * Handle modem control transition on a tty.
 * Flag indicates new state of carrier.
 * Returns 0 if the line should be turned off, otherwise 1.
 */
ttymodem(tp, flag)
	register struct tty *tp;
{
	register struct nty *np = ttynty(tp);	/* plan 245 */

	if ((tp->t_state&TS_WOPEN) == 0 && (tp->t_flags & MDMBUF)) {
		/*
		 * MDMBUF: do flow control according to carrier flag
		 */
		if (flag) {
			tp->t_state &= ~TS_TTSTOP;
			ttstart(tp);
		} else if ((tp->t_state&TS_TTSTOP) == 0) {
			tp->t_state |= TS_TTSTOP;
			(*cdevsw[major(tp->t_dev)].d_stop)(tp, 0);
		}
	} else if (flag == 0) {
		/*
		 * Lost carrier.
		 */
		tp->t_state &= ~TS_CARR_ON;
		if (tp->t_state & TS_ISOPEN &&
		    (np->t_pflags & TP_CLOCAL) == 0) {	/* plan 245 */
#ifdef NeXT
			/*
			 * This makes selects work correctly
			 * when carrier goes away (they should return)
			 */
			ttwakeup(tp);
#endif NeXT
			if ((tp->t_flags & NOHANG) == 0) {
				gsignal(tp->t_pgrp, SIGHUP);
				gsignal(tp->t_pgrp, SIGCONT);
				ttyflush(tp, FREAD|FWRITE);
				return (0);
			}
		}
	} else {
		/*
		 * Carrier now on.
		 */
		tp->t_state |= TS_CARR_ON;
		wakeup((caddr_t)&tp->t_rawq);
	}
	return (1);
}

/*
 * Default modem control routine (for other line disciplines).
 * Return argument flag, to turn off device on carrier drop.
 */
nullmodem(tp, flag)
	register struct tty *tp;
	int flag;
{
	register struct nty *np = ttynty(tp);	/* plan 245 */

	if (flag)
		tp->t_state |= TS_CARR_ON;
	else {
		tp->t_state &= ~TS_CARR_ON;
		if ((np->t_pflags & TP_CLOCAL) == 0)	/* plan 245 */
			return (0);
	}
	return (flag);
}

/*
 * plan 245: is c the special character v?  (\377 means "not set")
 */
#define	CCEQ(v, c)	((char)(c) != (char)0377 && (char)(c) == (char)(v))

/*
 * Is c a break char for tp?  (plan 245: a macro in 4.2)
 */
#define	ttbreakc(c, tp) \
	((c) == '\n' || \
	 (((c) == ((tp)->t_eofc&0377) || (c) == ((tp)->t_brkc&0377)) && \
	  (c) != 0377))

/*
 * reinput pending characters after state switch
 * call at spltty().
 */
ttypend(tp)
	register struct tty *tp;
{
	struct clist tq;
	register c;

	tp->t_flags &= ~PENDIN;
	tp->t_state |= TS_TYPEN;
	tq = tp->t_rawq;
	tp->t_rawq.c_cc = 0;
	tp->t_rawq.c_cf = tp->t_rawq.c_cl = 0;
	while ((c = getc(&tq)) >= 0)
		ttyinput(c, tp);
	tp->t_state &= ~TS_TYPEN;
}

/*
 * Handle ttyinput flow control
 */
static inline void
ttyflowctl(tp)
struct tty *tp;
{
	/*
	 * Block further input iff:
	 * Current input > threshold AND input is available to user program
	 */
	if (tp->t_rawq.c_cc + tp->t_canq.c_cc >= TTYHOG(tp)/2 && 
	    ((tp->t_flags & (RAW|CBREAK)) || (tp->t_canq.c_cc > 0))) {
		if ((tp->t_flags&TANDEM) && tp->t_stopc != (char)0377 &&	/* plan 245 */
		    putc(tp->t_stopc, &tp->t_outq) == 0) {
			tp->t_state |= TS_TBLOCK;
			ttstart(tp);
		}
		tp->t_state |= TS_INPUTFULL;
	}
}

/*
 * Place a character on raw TTY input queue,
 * putting in delimiters and waking up top
 * half as needed.  Also echo if required.
 * The arguments are the character and the
 * appropriate tty structure.
 */
ttyinput(c, tp)
	register c;
	register struct tty *tp;
{
	register struct nty *np = ttynty(tp);	/* plan 245 */

	if ((np->t_pflags & TP_CREAD) == 0)	/* plan 245 */
		return;
	/*
	 * If input is pending take it first.
	 */
	if (tp->t_flags & PENDIN)
		ttypend(tp);
	tk_nin++;

	if ((c & TTY_ERRORMASK) == 0 && (tp->t_flags & RAW)) {	/* plan 245 */
		/*
		 * Raw mode, just put character
		 * in input q w/o interpretation.
		 */
		if (tp->t_rawq.c_cc > TTYHOG(tp)) {
			log(LOG_WARNING, "tty%d: raw input overrun\n",	/* plan 245 */
			    tp->t_dev);
			ttwakeup(tp);
		} else {
			if (putc(c, &tp->t_rawq) >= 0) {
				if (ttcheckwakeup(np))	/* plan 245 */
					ttwakeup(tp);
				ttyecho(c, np);
			}
		}
		tp->t_flags &= ~FLUSHO;
		if ((np->t_pflags & TP_IEXTEN) &&	/* plan 245 */
		    ((tp->t_flags & DECCTQ) == 0 ||
		     (tp->t_stopc != (char)0377 && tp->t_startc == tp->t_stopc)))
		   	tp->t_state &= ~TS_TTSTOP;
	} else
		ttcooked(c, np);		/* plan 245: struct nty */
	ttyflowctl(tp);
	ttstart(tp);
}

ttyblkin(cp, n, tp)
char *cp;
int n;
struct tty *tp;
{
	struct nty *np = ttynty(tp);		/* plan 245 */

	if ((np->t_pflags & TP_CREAD) == 0)	/* plan 245 */
		return;
	/*
	 * If input is pending take it first.
	 */
	if (tp->t_flags&PENDIN)
		ttypend(tp);
	tk_nin += n;

	if (tp->t_flags&RAW) {
		/*
		 * Raw mode, just put character
		 * in input q w/o interpretation.
		 */
		if (tp->t_rawq.c_cc+n > TTYHOG(tp)) {
#ifdef NeXT
			n = TTYHOG(tp) - tp->t_rawq.c_cc;
			if (n < 0)
				n = 0;
			log(LOG_WARNING, "tty%d: raw input overrun\n",	/* plan 245 */
			    tp->t_dev);
#else	NeXT
			ttyflush(tp, FREAD|FWRITE);
			n = 0;
#endif NeXT
		}
		if (n - b_to_q(cp, n, &tp->t_rawq) > 0 &&
		    ttcheckwakeup(np))		/* plan 245 */
			ttwakeup(tp);
		tp->t_flags &= ~FLUSHO;
		if (tp->t_flags & ECHO)
			tk_nout += b_to_q(cp, n, &tp->t_outq);
		/*
		 * If DEC-style start/stop is enabled don't restart
		 * output until seeing the start character.
		 */
		if ((np->t_pflags & TP_IEXTEN) &&	/* plan 245 */
		    ((tp->t_flags & DECCTQ) == 0 ||
		     (tp->t_stopc != (char)0377 && tp->t_startc == tp->t_stopc)))
			tp->t_state &= ~TS_TTSTOP;
	} else {
		while (--n >= 0)			/* plan 245 */
			ttcooked(*cp++ & 0377, np);
	}
	ttyflowctl(tp);
	ttstart(tp);
}

ttcooked(c, np)				/* plan 245: POSIX termios input */
	register c;
	struct nty *np;
{
	register struct tty *tp = np->t;
	long t_flags = tp->t_flags;
	long pflags = np->t_pflags;
	register int err;
	int i, s;

	/*
	 * Receive errors and break.
	 */
	if (err = (c & TTY_ERRORMASK)) {
		c &= ~TTY_ERRORMASK;
		if ((err & TTY_FE) && c == 0) {		/* Break. */
			if (pflags & TP_IGNBRK)
				goto endcase;
			else if (pflags & TP_BRKINT) {
				ttyflush(tp, FREAD|FWRITE);
				gsignal(tp->t_pgrp, SIGINT);
				goto endcase;
			} else if (pflags & TP_PARMRK)
				goto parmrk;
		} else if (((err & TTY_PE) && (pflags & TP_INPCK)) ||
		    (err & TTY_FE)) {
			if (pflags & TP_IGNPAR)
				goto endcase;
			else if (pflags & TP_PARMRK) {
parmrk:
				(void) putc(0377 | TTY_QUOTE, &tp->t_rawq);
				(void) putc(0 | TTY_QUOTE, &tp->t_rawq);
				c |= TTY_QUOTE;
			} else
				c = 0 | TTY_QUOTE;
		}
	}

	/*
	 * Ignore any high bit added during
	 * previous ttyinput processing.
	 */
	if ((tp->t_state&TS_TYPEN) == 0 && (t_flags&(PASS8|RAW)) == 0 &&
	    (pflags & TP_ISTRIP))
		c &= ~0200;

	/*
	 * Check for literal nexting very first
	 */
	if (tp->t_state&TS_LNCH) {
		c |= TTY_QUOTE;
		tp->t_state &= ~TS_LNCH;
	}

	/*
	 * Scan for special characters.  This code
	 * is really just a big case statement with
	 * non-constant cases.  The bottom of the
	 * case statement is labeled ``endcase'', so goto
	 * it after a case match, or similar.
	 */
	if ((c & TTY_QUOTE) || (tp->t_state & TS_EXTPROC) ||
	    !ttyspec(tp, c))
		goto notspecial;
	if ((pflags & (TP_PARMRK|TP_IGNPAR|TP_PARENB)) ==
	    (TP_PARMRK|TP_PARENB) && c == 0377) {
		(void) putc(0377 | TTY_QUOTE, &tp->t_rawq);
		c = 0377 | TTY_QUOTE;
	}
	if (pflags & TP_IEXTEN) {
		if (CCEQ(tp->t_lnextc, c)) {
			if (t_flags&ECHO) {
				if (t_flags&CRTERA)
					ttyoutstr("^\b", tp);
				else
					ttyecho(c, np);
			}
			tp->t_state |= TS_LNCH;
			goto endcase;
		}
		if (CCEQ(tp->t_flushc, c)) {
			if (t_flags&FLUSHO)
				tp->t_flags &= ~FLUSHO;
			else {
				ttyflush(tp, FWRITE);
				ttyecho(c, np);
				if (tp->t_rawq.c_cc + tp->t_canq.c_cc)
					ttyretype(np);
				tp->t_flags |= FLUSHO;
			}
			goto startoutput;
		}
	}

	/*
	 * Look for interrupt/quit/suspend chars.
	 */
	if (pflags & TP_ISIG) {
		if (CCEQ(tp->t_intrc, c) || CCEQ(tp->t_quitc, c)) {
			if ((t_flags&NOFLSH) == 0)
				ttyflush(tp, FREAD|FWRITE);
			ttyecho(c, np);
			gsignal(tp->t_pgrp,
			    CCEQ(tp->t_intrc, c) ? SIGINT : SIGQUIT);
			goto endcase;
		}
		if (CCEQ(tp->t_suspc, c)) {
			if ((t_flags&NOFLSH) == 0)
				ttyflush(tp, FREAD);
			ttyecho(c, np);
			gsignal(tp->t_pgrp, SIGTSTP);
			goto endcase;
		}
	}

	/*
	 * Handle start/stop characters.
	 */
	if (pflags & TP_IXON) {
		if (CCEQ(tp->t_stopc, c)) {
			if ((tp->t_state&TS_TTSTOP) == 0) {
				tp->t_state |= TS_TTSTOP;
				(*cdevsw[major(tp->t_dev)].d_stop)(tp, 0);
				return;
			}
			if (!CCEQ(tp->t_startc, c))
				return;
			goto endcase;
		}
		if (CCEQ(tp->t_startc, c))
			goto restartoutput;
	}

	/*
	 * IGNCR, ICRNL, & INLCR
	 */
	if (c == '\r') {
		if (pflags & TP_IGNCR)
			goto endcase;
		else if ((t_flags & CRMOD) || (pflags & TP_ICRNL))
			c = '\n';
	} else if (c == '\n' && (pflags & TP_INLCR))
		c = '\r';

	if ((t_flags & LCASE) && c <= 0177) {
		if (tp->t_state&TS_BKSL) {
			ttyrub(unputc(&tp->t_rawq), np);
			if (maptab[c])
				c = maptab[c];
			c |= TTY_QUOTE;
			tp->t_state &= ~(TS_BKSL|TS_QUOT);
notspecial:
			if (t_flags&(RAW|CBREAK))
				goto cbreak;
			goto putit;
		} else if (c >= 'A' && c <= 'Z')
			c += 'a' - 'A';
		else if (c == '\\')
			tp->t_state |= TS_BKSL;
	}

	/*
	 * Cbreak mode, don't process line editing
	 * characters; check high water mark for wakeup.
	 */
	if (t_flags&(RAW|CBREAK)) {
cbreak:
		if (tp->t_rawq.c_cc > TTYHOG(tp)) {
			if (tp->t_outq.c_cc < TTHIWAT(tp) &&
			    (pflags & TP_IMAXBEL))
				(void) ttyoutput(CTRL('g'), tp);
			log(LOG_WARNING, "tty%d: cbreak input overrun\n",
			    tp->t_dev);
		} else if (putc(c, &tp->t_rawq) >= 0) {
			if (ttcheckwakeup(np))
				ttwakeup(tp);
			ttyecho(c, np);
		}
		goto endcase;
	}

	/*
	 * From here on down cooked mode character
	 * processing takes place.
	 */
	if ((tp->t_state&TS_QUOT) &&
	    (CCEQ(tp->t_erase, c) || CCEQ(tp->t_kill, c))) {
		ttyrub(unputc(&tp->t_rawq), np);
		c |= TTY_QUOTE;
		goto putit;
	}
	if (CCEQ(tp->t_erase, c)) {
		if (tp->t_rawq.c_cc) {
			ttyrub(c = unputc(&tp->t_rawq), np);
			if ((t_flags & EUCBKSP) && (c & 0200)
			  && tp->t_rawq.c_cc) {
				c = unputc(&tp->t_rawq);
				if ((char)c != (char)0216)	/* EUC SS2 */
					ttyrub(c, np);
			}
		}
		goto endcase;
	}
	if (CCEQ(tp->t_kill, c)) {
		if ((pflags & TP_ECHOK) && (t_flags & CRTKIL) &&
		    tp->t_rawq.c_cc == tp->t_rocount) {
			while (tp->t_rawq.c_cc)
				ttyrub(unputc(&tp->t_rawq), np);
		} else {
			ttyecho(c, np);
			if (pflags & TP_ECHOK)
				ttyecho('\n', np);
			while (getc(&tp->t_rawq) > 0)
				;
			tp->t_rocount = 0;
		}
		tp->t_state &= ~TS_LOCAL;
		goto endcase;
	}

	/*
	 * Word erase (ALTWERASE: by character class)
	 */
	if (CCEQ(tp->t_werasc, c)) {
		int alt = pflags & TP_ALTWERASE;
		register int ctype;

		/* erase whitespace */
		while ((c = unputc(&tp->t_rawq)) == ' ' || c == '\t')
			ttyrub(c, np);
		if (c == -1)
			goto endcase;
		/* erase the last character of the word */
		ttyrub(c, np);
		c = unputc(&tp->t_rawq);
		if (c == -1)
			goto endcase;
		ctype = partab[c & 0377] & 0100;
		/* erase the rest of the word */
		while (c != ' ' && c != '\t' &&
		    (alt == 0 || (partab[c & 0377] & 0100) == ctype)) {
			ttyrub(c, np);
			c = unputc(&tp->t_rawq);
			if (c == -1)
				goto endcase;
		}
		(void) putc(c, &tp->t_rawq);
		goto endcase;
	}
	if (CCEQ(tp->t_rprntc, c)) {
		ttyretype(np);
		goto endcase;
	}

putit:
	/*
	 * Check for input buffer overflow
	 */
	if (tp->t_rawq.c_cc+tp->t_canq.c_cc >= TTYHOG(tp)) {
		if ((pflags & TP_IMAXBEL) &&
		    tp->t_outq.c_cc < TTHIWAT(tp))
			(void) ttyoutput(CTRL('g'), tp);
		log(LOG_WARNING, "tty%d: canon input overrun\n",
		    tp->t_dev);
		goto endcase;
	}

	/*
	 * Put data char in q for user and
	 * wakeup on seeing a line delimiter.
	 */
	if (putc(c, &tp->t_rawq) >= 0) {
		if (ttbreakc(c, tp)) {
			tp->t_rocount = 0;
			catq(&tp->t_rawq, &tp->t_canq);
			ttwakeup(tp);
		} else if (tp->t_rocount++ == 0)
			tp->t_rocol = tp->t_col;
		tp->t_state &= ~TS_QUOT;
	    if ((tp->t_state&TS_EXTPROC) == 0) {
		if (CCEQ(np->t_quote, c))
			tp->t_state |= TS_QUOT;
		if (tp->t_state&TS_ERASE) {
			tp->t_state &= ~TS_ERASE;
			(void) ttyoutput('/', tp);
		}
		i = tp->t_col;
		ttyecho(c, np);
		if (CCEQ(tp->t_eofc, c) && t_flags&ECHO) {
			i = MIN(2, tp->t_col - i);
			while (i > 0) {
				(void) ttyoutput('\b', tp);
				i--;
			}
		}
	    }
	}
endcase:
	/*
	 * If DEC-style start/stop is enabled don't restart
	 * output until seeing the start character.
	 */
	if ((pflags & TP_IEXTEN) == 0)
		return;
	if (t_flags&DECCTQ && tp->t_state&TS_TTSTOP &&
	    !CCEQ(tp->t_startc, tp->t_stopc))
		return;
restartoutput:
	tp->t_state &= ~TS_TTSTOP;
	tp->t_flags &= ~FLUSHO;
startoutput:
	return;
}

/*
 * Put character on TTY output queue, adding delays,
 * expanding tabs, and handling the CR/NL bit.
 * This is called both from the top half for output,
 * and from interrupt level for echoing.
 * The arguments are the character and the tty structure.
 * Returns < 0 if putc succeeds, otherwise returns char to resend
 * Must be recursive.
 */
ttyoutput(c, tp)
	register c;
	register struct tty *tp;
{
	register char *colp;
	struct nty *np = ttynty(tp);		/* plan 245 */
	long flags = tp->t_flags;
	int col, delay;

	if ((flags & (RAW|LITOUT)) || (np->t_pflags & TP_OPOST) == 0) {
		if (flags&FLUSHO)
			return (-1);
		if (putc(c, &tp->t_outq))
			return (c);
		tk_nout++;
		return (-1);
	}

	/*
	 * Ignore EOT in normal mode to avoid
	 * hanging up certain terminals.
	 */
	c &= ((flags & PASS8OUT) ||
	      (np->t_pflags & TP_CSIZE) == TP_CS8) ? 0377 : 0177;	/* plan 245 */
	if (c == CEOT && (flags&CBREAK) == 0)
		return (-1);
	/*
	 * Turn tabs to spaces as required
	 *
	 * Special case if we have external processing, we don't
	 * do the tab expansion because we'll probably get it
	 * wrong.  If tab expansion needs to be done, let it
	 * happen externally.
	 */
	if (c == '\t' && (flags&TBDELAY) == XTABS &&
	    (tp->t_state&TS_EXTPROC) == 0) {
		register int s;

		c = 8 - (tp->t_col&7);
		if ((flags&FLUSHO) == 0) {
			s = spltty();		/* don't interrupt tabs */
			c -= b_to_q("        ", c, &tp->t_outq);
			tk_nout += c;
			splx(s);
		}
		tp->t_col += c;
		return (c ? -1 : '\t');
	}
	tk_nout++;
	/*
	 * for upper-case-only terminals,
	 * generate escapes.
	 */
	if (flags&LCASE) {
		colp = "({)}!|^~'`";
		while (*colp++)
			if (c == *colp++) {
				if (ttyoutput('\\', tp) >= 0)
					return (c);
				c = colp[-2];
				break;
			}
		if ('A' <= c && c <= 'Z') {
			if (ttyoutput('\\', tp) >= 0)
				return (c);
		} else if ('a' <= c && c <= 'z')
			c += 'A' - 'a';
	}

	/*
	 * turn <nl> to <cr><lf> if desired.
	 */
	if (c == '\n' && ((flags&CRMOD) || (np->t_pflags & TP_ONLCR)))	/* plan 245 */
		if (ttyoutput('\r', tp) >= 0)
			return (c);
	if ((flags&FLUSHO) == 0 && putc(c, &tp->t_outq))
		return (c);
	/*
	 * Calculate delays.
	 * The numbers here represent clock ticks
	 * and are not necessarily optimal for all terminals.
	 * The delays are indicated by characters above 0200.
	 * In raw mode there are no delays and the
	 * transmission path is 8 bits wide.
	 *
	 * SHOULD JUST ALLOW USER TO SPECIFY DELAYS
	 */
	col = tp->t_col;			/* plan 245 */
	delay = 0;
	switch (partab[c]&077) {

	case ORDINARY:
		col++;
		break;

	case CONTROL:
		break;

	case BACKSPACE:
		if (col > 0)
			col--;
		break;

	/*
	 * This macro is close enough to the correct thing;
	 * it should be replaced by real user settable delays
	 * in any event...
	 */
#define	mstohz(ms)	(((ms) * hz) >> 10)
	case NEWLINE:
		switch ((flags >> 8) & 03) {
		case 1: /* tty 37 */
			if (col > 0) {
				delay = (((unsigned)col) >> 4) + 3;
				if ((unsigned)delay > 6)
					delay = 6;
			}
			break;
		case 2: /* vt05 */
			delay = mstohz(100);
			break;
		}
		col = 0;
		break;

	case TAB:
		if ((flags & TBDELAY) == TAB1) { /* tty 37 */
			delay = 1 - (col | ~07);
			if (delay < 5)
				delay = 0;
		}
		col = (col + 8) & ~07;
		break;

	case VTAB:
		if (flags&VTDELAY) /* tty 37 */
			delay = 0177;
		break;

	case RETURN:
		switch ((tp->t_flags >> 12) & 03) {
		case 1: /* tn 300 */
			delay = mstohz(83);
			break;
		case 2: /* ti 700 */
			delay = mstohz(166);
			break;
		case 3: /* concept 100 */
			if ((delay = col) >= 0)
				for (; delay < 9; delay++)
					(void) putc(0177, &tp->t_outq);
			delay = 0;
			break;
		}
		col = 0;
	}
	tp->t_col = col;			/* plan 245 */
	if (delay && (tp->t_flags & (FLUSHO|PASS8OUT)) == 0 &&
	    (np->t_pflags & TP_CSIZE) != TP_CS8)	/* plan 245 */
		(void) putc(delay|0200, &tp->t_outq);
	return (-1);
}
#undef mstohz

/*
 * Called from device's read routine after it has
 * calculated the tty-structure given as argument.
 */
ttread(tp, uio)
	register struct tty *tp;
	struct uio *uio;
{
	struct nty *np = ttynty(tp);		/* plan 245: POSIX VMIN/VTIME */
	register struct clist *qp;
	register c, t_flags;
	int s, first, error = 0;
	int timing, lastcc;
	struct timeval start;
	extern int wakeup();

restart:
	timing = 0;
loop:
	t_flags = tp->t_flags;
	/*
	 * Take any pending input first.
	 */
	s = spltty();
	if (t_flags&PENDIN)
		ttypend(tp);
	splx(s);

	while ((tp->t_state&TS_CARR_ON)==0 && (np->t_pflags&TP_CLOCAL)==0)
		if (tp->t_state&TS_ONDELAY) { /* open O_NDELAY */
			if (tp->t_state&TS_NBIO) {
				if (u.u_procp->p_posix)
					return (EAGAIN);
				return (EWOULDBLOCK);
			} else 
				/* wake up on carrier transition */
				sleep((caddr_t)&tp->t_rawq, TTIPRI);
		}
		else 
			return(EIO);

	/*
	 * Hang process if it's in the background.
	 */
	if (u.u_procp->p_posix) {
		register struct proc *p = u.u_procp;
		register struct posix_proc *px = get_posix_proc(p->p_pid);
		register struct pgrp *pg;

		if (tp == u.u_ttyp &&
		    (pg = px->p_posix_pgrp)->pg_id != tp->t_pgrp) {
			if ((p->p_sigignore & sigmask(SIGTTIN)) ||
			    (p->p_sigmask & sigmask(SIGTTIN)) ||
			    pg->pg_jobc == 0 || p->p_flag&SVFORK)
				return (EIO);
			gsignal(pg->pg_id, SIGTTIN);
			sleep((caddr_t)&lbolt, TTIPRI);
			goto loop;
		}
	} else if (tp == u.u_ttyp && u.u_procp->p_pgrp != tp->t_pgrp) {
		if ((u.u_procp->p_sigignore & sigmask(SIGTTIN)) ||
		   (u.u_procp->p_sigmask & sigmask(SIGTTIN)) ||
		    u.u_procp->p_flag&SVFORK)
			return (EIO);
		gsignal(u.u_procp->p_pgrp, SIGTTIN);
		sleep((caddr_t)&lbolt, TTIPRI);
		goto loop;
	}

	s = spltty();
	if (t_flags&(RAW|CBREAK)) {
		register int min = np->t_min;
		register int time = np->t_time;

		qp = &tp->t_rawq;
		if (time == 0) {
			if (qp->c_cc < min)
				goto sleep;
			goto read;
		}
		time *= 100000;			/* tenths of a second to usec */
		if (min > 0) {
			if (tp->t_rawq.c_cc <= 0)
				goto sleep;
			if (tp->t_rawq.c_cc >= min)
				goto read;
			if (!timing) {
				timing = 1;
				getthetime(&start);
			} else if (lastcc < tp->t_rawq.c_cc)
				getthetime(&start);
			else {
				struct timeval now;

				getthetime(&now);
				time -= (now.tv_sec - start.tv_sec) * 1000000 +
				    (now.tv_usec - start.tv_usec);
			}
			lastcc = qp->c_cc;
		} else {
			if (tp->t_rawq.c_cc > 0)
				goto read;
			if (!timing) {
				timing = 1;
				getthetime(&start);
			} else {
				struct timeval now;

				getthetime(&now);
				time -= (now.tv_sec - start.tv_sec) * 1000000 +
				    (now.tv_usec - start.tv_usec);
			}
		}
		if (time <= 0)
			goto read;
		time = (time * hz + 999999) / 1000000;
		untimeout(wakeup, (caddr_t)qp);
		timeout(wakeup, (caddr_t)qp, time);
	} else {
		qp = &tp->t_canq;
		if (qp->c_cc > 0)
			goto read;
	}

sleep:
	/*
	 * No input, sleep on rawq awaiting hardware
	 * receipt and notification.
	 */
	{
		int carrier = (tp->t_state&TS_CARR_ON) ||
		    (np->t_pflags&TP_CLOCAL);

		if (!carrier && (tp->t_state&TS_ISOPEN)) {
			splx(s);
			return (0);
		}
	}
	if (tp->t_state&TS_NBIO) {
		splx(s);
		if (u.u_procp->p_posix)
			return (EAGAIN);
		return (EWOULDBLOCK);
	}
	sleep((caddr_t)&tp->t_rawq, TTIPRI);
	splx(s);
	goto loop;

read:
	splx(s);

	/*
	 * Input present, perform input mapping
	 * and processing.
	 */
	first = 1;
	while ((c = getc(qp)) >= 0) {
		/*
		 * Check for delayed suspend character.
		 */
		if (CCEQ(tp->t_dsuspc, c) && (t_flags&RAW) == 0 &&
		    (np->t_pflags&TP_ISIG)) {
			gsignal(tp->t_pgrp, SIGTSTP);
			if (first) {
				sleep((caddr_t)&tp->t_rawq, TTIPRI);
				goto restart;
			}
			break;
		}
		/*
		 * Interpret EOF only in cooked mode.
		 */
		if (CCEQ(tp->t_eofc, c) && (t_flags&(RAW|CBREAK)) == 0)
			break;
		/*
		 * Give user character.
		 */
 		error = ureadc(c, uio);
		if (error)
			break;
 		if (uio->uio_resid == 0)
			break;
		/*
		 * In cooked mode check for a "break character"
		 * marking the end of a "line of input".
		 */
		if ((t_flags&(RAW|CBREAK)) == 0 && ttbreakc(c, tp))
			break;
		first = 0;
	}

	/*
	 * Look to unblock input now that (presumably)
	 * the input queue has gone down.
	 */
	if (tp->t_rawq.c_cc < TTYHOG(tp)/5) {
		s = spltty();
		tp->t_state &= ~TS_INPUTFULL;
		splx(s);
		if ((tp->t_state&(TS_TBLOCK|TS_INPUTAVAIL)) == TS_TBLOCK &&
		    tp->t_startc != (char)0377 &&
		    putc(tp->t_startc, &tp->t_outq) == 0) {
			s = spltty();
			tp->t_state &= ~TS_TBLOCK;
			splx(s);
			ttstart(tp);
		}
	}
	return (error);
}

/*
 * Check the output queue on tp for space for a kernel message
 * (from uprintf/tprintf).  Allow some space over the normal
 * hiwater mark so we don't lose messages due to normal flow
 * control, but don't let the tty run amok.
 */
ttycheckoutq(tp, wait)
	register struct tty *tp;
	int wait;
{
	int hiwat, s;

	hiwat = TTHIWAT(tp);
	s = spltty();
	if (tp->t_outq.c_cc > hiwat + 200)
	    while (tp->t_outq.c_cc > hiwat) {
		ttstart(tp);
		if (wait == 0) {
			splx(s);
			return (0);
		}
		tp->t_state |= TS_ASLEEP;
		sleep((caddr_t)&tp->t_outq, TTOPRI);
	}
	splx(s);
	return (1);
}

/*
 * Called from the device's write routine after it has
 * calculated the tty-structure given as argument.
 */
ttwrite(tp, uio)
	register struct tty *tp;
	register struct uio *uio;
{
	register char *cp;
	register int cc, ce, c;
	struct nty *np = ttynty(tp);		/* plan 245 */
	int i, hiwat, cnt, error, s;
	char obuf[OBUFSIZ];

	hiwat = TTHIWAT(tp);
	cnt = uio->uio_resid;
	error = 0;
loop:
	while ((tp->t_state&TS_CARR_ON)==0 &&
	    (np->t_pflags & TP_CLOCAL) == 0)	/* plan 245 */
		if (tp->t_state&TS_ONDELAY) { /* assume O_NDELAY */
			if (tp->t_state&TS_NBIO)
			{
				if (u.u_procp->p_posix)	/* plan 245 */
					return (EAGAIN);
				return (EWOULDBLOCK);
			}
			else 
				/* wake up on carrier transition */
				sleep((caddr_t)&tp->t_rawq, TTIPRI);
		}
		else 
			return(EIO);
	/*
	 * Hang the process if it's in the background.
	 */
	if (u.u_procp->p_posix) {		/* plan 245: POSIX job control */
		register struct proc *p = u.u_procp;
		register struct pgrp *pg =
		    get_posix_proc(p->p_pid)->p_posix_pgrp;

		if (pg->pg_id != tp->t_pgrp && tp == u.u_ttyp &&
		    (tp->t_flags&TOSTOP) &&
		    !(p->p_sigignore & sigmask(SIGTTOU)) &&
		    !(p->p_sigmask & sigmask(SIGTTOU))) {
			if (pg->pg_jobc == 0)
				return (EIO);
			gsignal(pg->pg_id, SIGTTOU);
			sleep((caddr_t)&lbolt, TTIPRI);
			goto loop;
		}
	} else if (u.u_procp->p_pgrp != tp->t_pgrp && tp == u.u_ttyp &&
	    (tp->t_flags&TOSTOP) && (u.u_procp->p_flag&SVFORK)==0 &&
	    !(u.u_procp->p_sigignore & sigmask(SIGTTOU)) &&
	    !(u.u_procp->p_sigmask & sigmask(SIGTTOU))) {
		gsignal(u.u_procp->p_pgrp, SIGTTOU);
		sleep((caddr_t)&lbolt, TTIPRI);
		goto loop;
	}

	/*
	 * Process the user's data in at most OBUFSIZ
	 * chunks.  Perform lower case simulation and
	 * similar hacks.  Keep track of high water
	 * mark, sleep on overflow awaiting device aid
	 * in acquiring new space.
	 */
	while (uio->uio_resid > 0) {
		/*
		 * Grab a hunk of data from the user.
		 */
		cc = uio->uio_iov->iov_len;
		if (cc == 0) {
			uio->uio_iovcnt--;
			uio->uio_iov++;
			if (uio->uio_iovcnt <= 0)
				panic("ttwrite");
			continue;
		}
		if (cc > OBUFSIZ)
			cc = OBUFSIZ;
		cp = obuf;
		error = uiomove(cp, cc, UIO_WRITE, uio);
		if (error)
			break;
		if (tp->t_outq.c_cc > hiwat)
			goto ovhiwat;
		if (tp->t_flags&FLUSHO)
			continue;
		/*
		 * If we're mapping lower case or kludging tildes,
		 * then we've got to look at each character, so
		 * just feed the stuff to ttyoutput...
		 */
#if	NeXT
		/* NeXT stole the TILDE bit to use as the EUC bit */
		if ((tp->t_flags & (LCASE|RAW|LITOUT)) == LCASE &&	/* plan 245 */
		    (np->t_pflags & TP_OPOST))
#else	NeXT
		if (tp->t_flags & (LCASE|TILDE))
#endif	NeXT
		{
			while (cc > 0) {
				c = *cp++;
				tp->t_rocount = 0;
				if (ttyoutput(c, tp) >= 0) {	/* plan 245 */
					/* out of clists, wait a bit */
					ttstart(tp);
					sleep((caddr_t)&lbolt, TTOPRI);
					tp->t_rocount = 0;
					if (cc != 0) {
						uio->uio_iov->iov_base -= cc;
						uio->uio_iov->iov_len += cc;
						uio->uio_resid += cc;
						uio->uio_offset -= cc;
					}
					goto loop;
				}
				--cc;
				if (tp->t_outq.c_cc > hiwat)
					goto ovhiwat;
			}
			continue;
		}
		/*
		 * plan 245: strip the eighth bit unless 8-bit output
		 */
		if ((tp->t_flags & (RAW|LITOUT|PASS8OUT)) == 0 &&
		    (np->t_pflags & TP_OPOST) &&
		    (np->t_pflags & TP_CSIZE) != TP_CS8) {
			register char *p;

			for (p = cp, ce = cc - 1; ce >= 0; ce--)
				*p++ &= 0177;
		}
		/*
		 * If nothing fancy need be done, grab those characters we
		 * can handle without any of ttyoutput's processing and
		 * just transfer them to the output q.  For those chars
		 * which require special processing (as indicated by the
		 * bits in partab), call ttyoutput.  After processing
		 * a hunk of data, look for FLUSHO so ^O's will take effect
		 * immediately.
		 */
		while (cc > 0) {
			if ((tp->t_flags & (RAW|LITOUT)) ||
			    (np->t_pflags & TP_OPOST) == 0)	/* plan 245 */
				ce = cc;
			else {
				ce = cc - scanc((unsigned)cc, (caddr_t)cp,
				   (caddr_t)partab, 077);
				/*
				 * If ce is zero, then we're processing
				 * a special character through ttyoutput.
				 */
				if (ce == 0) {
					tp->t_rocount = 0;
					if (ttyoutput(*cp, tp) >= 0) {
					    /* no c-lists, wait a bit */
					    ttstart(tp);
					    sleep((caddr_t)&lbolt, TTOPRI);
					    if (cc != 0) {
					        uio->uio_iov->iov_base -= cc;
					        uio->uio_iov->iov_len += cc;
					        uio->uio_resid += cc;
						uio->uio_offset -= cc;
					    }
					    goto loop;
					}
					cp++, cc--;
					if (tp->t_flags&FLUSHO ||
					    tp->t_outq.c_cc > hiwat)
						goto ovhiwat;
					continue;
				}
			}
			/*
			 * A bunch of normal characters have been found,
			 * transfer them en masse to the output queue and
			 * continue processing at the top of the loop.
			 * If there are any further characters in this
			 * <= OBUFSIZ chunk, the first should be a character
			 * requiring special handling by ttyoutput.
			 */
			tp->t_rocount = 0;
			i = b_to_q(cp, ce, &tp->t_outq);
			ce -= i;
			tp->t_col += ce;
			cp += ce, cc -= ce, tk_nout += ce;
			if (i > 0) {
				/* out of c-lists, wait a bit */
				ttstart(tp);
				sleep((caddr_t)&lbolt, TTOPRI);
				uio->uio_iov->iov_base -= cc;
				uio->uio_iov->iov_len += cc;
				uio->uio_resid += cc;
				uio->uio_offset -= cc;
				goto loop;
			}
			if (tp->t_flags&FLUSHO || tp->t_outq.c_cc > hiwat)
				goto ovhiwat;
		}
	}
	ttstart(tp);
	return (error);

ovhiwat:
	s = spltty();
	if (cc != 0) {
		uio->uio_iov->iov_base -= cc;
		uio->uio_iov->iov_len += cc;
		uio->uio_resid += cc;
		uio->uio_offset -= cc;
	}
	/*
	 * This can only occur if FLUSHO
	 * is also set in t_flags.
	 */
	ttstart(tp);
	if (tp->t_outq.c_cc <= hiwat) {
		splx(s);
		goto loop;
	}
	if (tp->t_state&TS_NBIO) {
		splx(s);
		if (uio->uio_resid == cnt)
		{
			if (u.u_procp->p_posix)		/* plan 245 */
				return (EAGAIN);
			return (EWOULDBLOCK);
		}
		return (0);
	}
	tp->t_state |= TS_ASLEEP;
	sleep((caddr_t)&tp->t_outq, TTOPRI);
	splx(s);
	goto loop;
}

/*
 * Rubout one character from the rawq of tp
 * as cleanly as possible.
 */
ttyrub(c, np)				/* plan 245: struct nty, TTY_QUOTE */
	register c;
	register struct nty *np;
{
	register struct tty *tp = np->t;
	register char *cp;
	register int savecol;
	int s, qc;
	char *nextc3();

	if ((tp->t_flags&ECHO) == 0 || (tp->t_state&TS_EXTPROC))
		return;
	tp->t_flags &= ~FLUSHO;
	if (tp->t_flags&CRTBS) {
		if (tp->t_rocount == 0) {
			/*
			 * Screwed by ttwrite; retype
			 */
			ttyretype(np);
			return;
		}
		if (c == ('\t'|TTY_QUOTE) || c == ('\n'|TTY_QUOTE))
			ttyrubo(tp, 2);
		else switch (partab[c&=0377]&077) {

		case ORDINARY:
			ttyrubo(tp, 1);
			break;

		case VTAB:
		case BACKSPACE:
		case CONTROL:
		case RETURN:
		case NEWLINE:				/* plan 245 */
			if (tp->t_flags&CTLECH)
				ttyrubo(tp, 2);
			break;

		case TAB:
			if (tp->t_rocount < tp->t_rawq.c_cc) {
				ttyretype(np);
				return;
			}
			s = spltty();
			savecol = tp->t_col;
			tp->t_state |= TS_CNTTB;
			tp->t_flags |= FLUSHO;
			tp->t_col = tp->t_rocol;
			for (cp = tp->t_rawq.c_cf - 1;
			     cp = nextc3(&tp->t_rawq, cp, &qc); )
				ttyecho(qc, np);
			tp->t_flags &= ~FLUSHO;
			tp->t_state &= ~TS_CNTTB;
			splx(s);
			/*
			 * savecol will now be length of the tab
			 */
			savecol -= tp->t_col;
			tp->t_col += savecol;
			if (savecol > 8)
				savecol = 8;		/* overflow screw */
			while (--savecol >= 0)
				(void) ttyoutput('\b', tp);
			break;

		default:
			panic("ttyrub");
		}
	} else if (tp->t_flags&PRTERA) {
		if ((tp->t_state&TS_ERASE) == 0) {
			(void) ttyoutput('\\', tp);
			tp->t_state |= TS_ERASE;
		}
		ttyecho(c, np);
	} else
		ttyecho(tp->t_erase & 0377, np);
	tp->t_rocount--;
}

/*
 * Crt back over cnt chars perhaps
 * erasing them.
 */
ttyrubo(tp, cnt)
	register struct tty *tp;
	int cnt;
{
	register char *rubostring = tp->t_flags&CRTERA ? "\b \b" : "\b";

	while (--cnt >= 0)
		ttyoutstr(rubostring, tp);
}

/*
 * Reprint the rawq line.
 * We assume c_cc has already been checked.
 */
ttyretype(np)				/* plan 245: struct nty, nextc3 */
	register struct nty *np;
{
	register struct tty *tp = np->t;
	register char *cp;
	char *nextc3();
	int s, c;

	if (tp->t_rprntc != (char)0377)
		ttyecho(tp->t_rprntc & 0377, np);
	(void) ttyoutput('\n', tp);
	s = spltty();
	for (cp = tp->t_canq.c_cf - 1; cp = nextc3(&tp->t_canq, cp, &c); )
		ttyecho(c, np);
	for (cp = tp->t_rawq.c_cf - 1; cp = nextc3(&tp->t_rawq, cp, &c); )
		ttyecho(c, np);
	tp->t_state &= ~TS_ERASE;
	splx(s);
	tp->t_rocount = tp->t_rawq.c_cc;
	tp->t_rocol = 0;
}

/*
 * Echo a typed character to the terminal
 */
ttyecho(c, np)				/* plan 245: struct nty */
	register c;
	register struct nty *np;
{
	register struct tty *tp = np->t;

	if ((tp->t_state&TS_CNTTB) == 0)
		tp->t_flags &= ~FLUSHO;
	if ((tp->t_flags&ECHO) == 0 &&
	    ((np->t_pflags&TP_ECHONL) == 0 || c != '\n'))	/* plan 245 */
		return;
	if (tp->t_state&TS_EXTPROC)
		return;
	if (tp->t_flags&CTLECH) {
		if ((c&0377) <= 037 && c!='\t' && c!='\n' || (c&0377) == 0177) {
			(void) ttyoutput('^', tp);
			c &= 0377;			/* plan 245 */
			if (c == 0177)
				c = '?';
			else if (tp->t_flags&LCASE)
				c += 'a' - 1;
			else
				c += 'A' - 1;
		}
	}
	c &= 0377;
	/*
	 * Do not echo non-printing control characters.  Mainly
	 * to stop causing special actions on most terminals.
	 */
	if ((040 <= c && ((tp->t_flags & PASS8) ||
	    (np->t_pflags & TP_ISTRIP) || c <= 0176))		/* plan 245 */
	  || (07 <= c && c <= 012) || c == 015)
	    (void) ttyoutput(c, tp);
}

/*
 * send string cp to tp
 */
ttyoutstr(cp, tp)			/* plan 245: was ttyout */
	register char *cp;
	register struct tty *tp;
{
	register char c;

	while (c = *cp++)
		(void) ttyoutput(c, tp);
}

/*
 * plan 245: may a reader be woken?  Not while a RAW/CBREAK read
 * still waits for t_min characters without a timer.
 */
ttcheckwakeup(np)
	register struct nty *np;
{
	register struct tty *tp = np->t;

	if ((tp->t_flags & (RAW|CBREAK)) &&
	    tp->t_rawq.c_cc < np->t_min && np->t_time == 0)
		return (0);
	return (1);
}

ttwakeup(tp)
	struct tty *tp;
{
	int s = spltty();			/* plan 245 */

	if (tp->t_rsel) {
		selwakeup(tp->t_rsel, tp->t_state&TS_RCOLL);
		selthreadclear(&tp->t_rsel);	/* plan 245 */
		tp->t_state &= ~TS_RCOLL;
	}
	splx(s);
	if (tp->t_state & TS_ASYNC)
		gsignal(tp->t_pgrp, SIGIO); 
	wakeup((caddr_t)&tp->t_rawq);
}

#if	NeXT

int
tty_ld_install(int ld_number,
	int ld_kind,
	int (*ld_open)(dev_t dev, struct tty *tp),
	int (*ld_close)(struct tty *tp),
	int (*ld_read)(struct tty *tp, struct uio *uiop),
	int (*ld_write)(struct tty *tp, struct uio *uiop),
	int (*ld_ioctl)(struct tty *tp, int command, void *dataptr, int flag),
	int (*ld_rint)(int c, struct tty *tp),
	int (*ld_rend)(char *cp, int n, struct tty *tp),
	int (*ld_start)(struct tty *tp),
	int (*ld_modem)(struct tty *tp, int dcd_on),
	int (*ld_select)(struct tty *tp, int rw)
) {
	extern nodev();
	extern int nldisp;
	int s;

	if (ld_number < 0 || ld_number >= nldisp)
		return -1;
	if (linesw[ld_number].l_open != nodev 
	 || linesw[ld_number].l_close != nodev
	 || linesw[ld_number].l_read != nodev
	 || linesw[ld_number].l_write != nodev
	 || linesw[ld_number].l_ioctl != nodev
	 || linesw[ld_number].l_rint != nodev
	 || linesw[ld_number].l_rend != nodev
	 || linesw[ld_number].l_start != nodev
	 || linesw[ld_number].l_modem != nodev
	 || linesw[ld_number].l_select != nodev)
		return -1;

	s = spltty();
	linesw[ld_number].l_kind = ld_kind;
	linesw[ld_number].l_open = (int (*)())ld_open;
	linesw[ld_number].l_close = (int (*)())ld_close;
	linesw[ld_number].l_read = (int (*)())ld_read;
	linesw[ld_number].l_write = (int (*)())ld_write;
	linesw[ld_number].l_ioctl = (int (*)())ld_ioctl;
	linesw[ld_number].l_rint = (int (*)())ld_rint;
	linesw[ld_number].l_rend = (int (*)())ld_rend;
	linesw[ld_number].l_start = (int (*)())ld_start;
	linesw[ld_number].l_modem = (int (*)())ld_modem;
	linesw[ld_number].l_select = (int (*)())ld_select;
	splx(s);
	return 0;
}

void tty_ld_remove(int ld_number)
{
	int s;
	extern nodev();
	extern int nldisp;
	
	if (ld_number < 0 || ld_number >= nldisp)
		return;

	s = spltty();
	linesw[ld_number].l_open = nodev;
	linesw[ld_number].l_close = nodev;
	linesw[ld_number].l_read = nodev;
	linesw[ld_number].l_write = nodev;
	linesw[ld_number].l_ioctl = nodev;
	linesw[ld_number].l_rint = nodev;
	linesw[ld_number].l_rend = nodev;
	linesw[ld_number].l_start = nodev;
	linesw[ld_number].l_modem = nodev;
	linesw[ld_number].l_select = nodev;
	splx(s);
}

void
ttydevstart(struct tty *tp)
{
	if (tp->t_oproc)
		(*tp->t_oproc)(tp);
}

void
ttydevstop(struct tty *tp)
{
	(*cdevsw[major(tp->t_dev)].d_stop)(tp, 0);
}

void
ttyselwait(struct tty *tp, int rw)
{
	int s = spltty();

	switch (rw) {

	case FREAD:
		if (selthreadcache(&tp->t_rsel))	/* plan 245 */
			tp->t_state |= TS_RCOLL;
		break;

	case FWRITE:
		if (selthreadcache(&tp->t_wsel))	/* plan 245 */
			tp->t_state |= TS_WCOLL;
		break;
	}
	splx(s);
}

void
ttselwakeup(struct tty *tp)
{
	int s = spltty();

	if (tp->t_rsel) {
		selwakeup(tp->t_rsel, tp->t_state&TS_RCOLL);
		tp->t_state &= ~TS_RCOLL;
		selthreadclear(&tp->t_rsel);	/* plan 245 */
	}
	splx(s);
}

/*
 * plan 245: set the tty state from a POSIX termios structure.
 */
ttsettermios(np, t)
	struct nty *np;
	struct termios *t;
{
	register struct tty *tp = np->t;
	register tcflag_t iflag = t->c_iflag;
	tcflag_t lflag = t->c_lflag;
	tcflag_t oflag = t->c_oflag;
	tcflag_t cflag = t->c_cflag;
	register long flags = 0, pflags = 0;

	if ((iflag & (BRKINT|ICRNL|IGNCR|INLCR|ISTRIP|IXON|IMAXBEL)) == 0 &&
	    (oflag & OPOST) == 0 &&
	    (lflag & (ICANON|ISIG|IEXTEN)) == 0 &&
	    (cflag & (CSIZE|PARENB)) == CS8) {
		flags = RAW;
		goto common;
	}
	if (iflag & BRKINT)
		pflags |= TP_BRKINT;
	if (iflag & ISTRIP)
		pflags |= TP_ISTRIP;
	if (iflag & INLCR)
		pflags |= TP_INLCR;
	if (iflag & IGNCR)
		pflags |= TP_IGNCR;
	if (iflag & IXON)
		pflags |= TP_IXON;
	if (iflag & IMAXBEL)
		pflags |= TP_IMAXBEL;
	if (oflag & OPOST)
		pflags |= TP_OPOST;
	if ((oflag & ONLCR) && (iflag & ICRNL))
		flags |= CRMOD;
	else {
		if (oflag & ONLCR)
			pflags |= TP_ONLCR;
		if (iflag & ICRNL)
			pflags |= TP_ICRNL;
	}
	if ((lflag & ICANON) == 0)
		flags |= CBREAK;
	if (lflag & ISIG)
		pflags |= TP_ISIG;
	if (lflag & IEXTEN)
		pflags |= TP_IEXTEN;
	if (cflag & PARENB)
		pflags |= TP_PARENB;
	switch (cflag & CSIZE) {
	case CS5:
		pflags |= TP_CS5;
		break;
	case CS6:
		pflags |= TP_CS6;
		break;
	case CS7:
		pflags |= TP_CS7;
		break;
	case CS8:
		pflags |= TP_CS8;
		if ((cflag & PARENB) == 0) {
			if (oflag & OPOST)
				flags |= PASS8OUT;
			else
				flags |= LITOUT;
			if ((iflag & ISTRIP) == 0)
				flags |= PASS8;
		}
		break;
	}
common:
	/* the original tests bit 0x80 of c_lflag here */
	if (cflag & PARODD)
		flags |= ODDP;
	else if (lflag & IEXTEN) {
		if (cflag & PAR1)
			flags |= ANYP;
		else if ((cflag & PAR0) == 0)
			flags |= EVENP;
	} else
		flags |= EVENP;
	if (cflag & CSTOPB)
		pflags |= TP_CSTOPB;
	if (cflag & CREAD)
		pflags |= TP_CREAD;
	if ((cflag & HUPCL) == 0)
		flags |= NOHANG;
	if (cflag & CLOCAL)
		pflags |= TP_CLOCAL;
	if (cflag & CSTOPB110)
		pflags |= TP_CSTOPB110;
	if (iflag & IGNBRK)
		pflags |= TP_IGNBRK;
	if (iflag & IGNPAR)
		pflags |= TP_IGNPAR;
	if (iflag & PARMRK)
		pflags |= TP_PARMRK;
	if (iflag & INPCK)
		pflags |= TP_INPCK;
	if (iflag & IXOFF)
		flags |= TANDEM;
	if ((iflag & IXANY) == 0)
		flags |= DECCTQ;
	flags |= oflag & ALLDELAY;
	if (lflag & ECHOE)
		flags |= CRTBS;
	if (lflag & ECHOK)
		pflags |= TP_ECHOK;
	if (lflag & ECHOKE)
		flags |= CRTKIL;
	if (lflag & ECHOCRT)
		flags |= CRTERA;
	if (lflag & ECHOPRT)
		flags |= PRTERA;
	if (lflag & ECHOCTL)
		flags |= CTLECH;
	if (lflag & ECHONL)
		pflags |= TP_ECHONL;
	if (lflag & ALTWERASE)
		pflags |= TP_ALTWERASE;
	if (lflag & XLCASE)
		flags |= LCASE;
	if (lflag & XEUCBKSP)
		flags |= EUCBKSP;
	flags |= lflag & (NOFLSH|TOSTOP|MDMBUF|ECHO);
	np->t->t_flags = flags;
	np->t_pflags = pflags;
	tp->t_ispeed = t->c_ispeed;
	tp->t_ospeed = t->c_ospeed;
	tp->t_erase = t->c_cc[VERASE];
	tp->t_kill = t->c_cc[VKILL];
	tp->t_intrc = t->c_cc[VINTR];
	tp->t_quitc = t->c_cc[VQUIT];
	tp->t_startc = t->c_cc[VSTART];
	tp->t_stopc = t->c_cc[VSTOP];
	tp->t_eofc = t->c_cc[VEOF];
	tp->t_brkc = t->c_cc[VEOL];
	tp->t_suspc = t->c_cc[VSUSP];
	tp->t_dsuspc = t->c_cc[VDSUSP];
	tp->t_rprntc = t->c_cc[VREPRINT];
	tp->t_flushc = t->c_cc[VDISCARD];
	tp->t_werasc = t->c_cc[VWERASE];
	tp->t_lnextc = t->c_cc[VLNEXT];
	np->t_min = t->c_cc[VMIN];
	np->t_time = t->c_cc[VTIME];
	np->t_quote = t->c_cc[VQUOTE];
}

/*
 * plan 245: report the tty state as a POSIX termios structure.
 */
ttgettermios(np, t)
	struct nty *np;
	register struct termios *t;
{
	struct tty *tp = np->t;
	long flags = tp->t_flags;
	register long pflags = np->t_pflags;
	register tcflag_t iflag = 0, oflag = 0, lflag = 0, cflag = 0;

	if (flags & RAW) {
		cflag = CS8;
		goto common;
	}
	if (pflags & TP_BRKINT)
		iflag |= BRKINT;
	if (pflags & TP_ISTRIP)
		iflag |= ISTRIP;
	if (pflags & TP_INLCR)
		iflag |= INLCR;
	if (pflags & TP_IGNCR)
		iflag |= IGNCR;
	if (pflags & TP_IXON)
		iflag |= IXON;
	if (pflags & TP_IMAXBEL)
		iflag |= IMAXBEL;
	if (pflags & TP_OPOST)
		oflag |= OPOST;
	if (flags & CRMOD) {
		iflag |= ICRNL;
		oflag |= ONLCR;
	} else {
		if (pflags & TP_ICRNL)
			iflag |= ICRNL;
		if (pflags & TP_ONLCR)
			oflag |= ONLCR;
	}
	if ((flags & CBREAK) == 0)
		lflag |= ICANON;
	if (pflags & TP_ISIG)
		lflag |= ISIG;
	if (pflags & TP_IEXTEN)
		lflag |= IEXTEN;
	if (flags & (PASS8|LITOUT|PASS8OUT)) {
		cflag |= CS8;
		if (flags & PASS8)
			iflag &= ~ISTRIP;
		if (flags & LITOUT)
			oflag &= ~OPOST;
	} else {
		if (pflags & TP_PARENB)
			cflag |= PARENB;
		switch (pflags & TP_CSIZE) {
		case TP_CS5:
			cflag |= CS5;
			break;
		case TP_CS6:
			cflag |= CS6;
			break;
		case TP_CS7:
			cflag |= CS7;
			break;
		case TP_CS8:
			cflag |= CS8;
			break;
		}
	}
common:
	switch (flags & ANYP) {
	case ODDP:
		cflag |= PARODD;
		break;
	case EVENP:
		break;
	case ANYP:
		cflag |= PAR1;
		break;
	case 0:
		cflag |= PAR0;
		break;
	}
	if (pflags & TP_CSTOPB)
		cflag |= CSTOPB;
	if (pflags & TP_CREAD)
		cflag |= CREAD;
	if ((flags & NOHANG) == 0)
		cflag |= HUPCL;
	if (pflags & TP_CLOCAL)
		cflag |= CLOCAL;
	if (pflags & TP_CSTOPB110)
		cflag |= CSTOPB110;
	if (pflags & TP_IGNBRK)
		iflag |= IGNBRK;
	if (pflags & TP_IGNPAR)
		iflag |= IGNPAR;
	if (pflags & TP_PARMRK)
		iflag |= PARMRK;
	if (pflags & TP_INPCK)
		iflag |= INPCK;
	if (flags & TANDEM)
		iflag |= IXOFF;
	if ((flags & DECCTQ) == 0)
		iflag |= IXANY;
	oflag |= flags & ALLDELAY;
	if (flags & CRTBS)
		lflag |= ECHOE;
	if (pflags & TP_ECHOK)
		lflag |= ECHOK;
	if (flags & CRTKIL)
		lflag |= ECHOKE;
	if (flags & CRTERA)
		lflag |= ECHOCRT;
	if (flags & PRTERA)
		lflag |= ECHOPRT;
	if (flags & CTLECH)
		lflag |= ECHOCTL;
	if (pflags & TP_ECHONL)
		lflag |= ECHONL;
	if (pflags & TP_ALTWERASE)
		lflag |= ALTWERASE;
	if (flags & LCASE)
		lflag |= XLCASE;
	if (flags & EUCBKSP)
		lflag |= XEUCBKSP;
	lflag |= flags & (NOFLSH|TOSTOP|MDMBUF|ECHO);
	t->c_iflag = iflag;
	t->c_oflag = oflag;
	t->c_lflag = lflag;
	t->c_cflag = cflag;
	t->c_ispeed = tp->t_ispeed;
	t->c_ospeed = tp->t_ospeed;
	t->c_cc[VERASE] = tp->t_erase;
	t->c_cc[VKILL] = tp->t_kill;
	t->c_cc[VINTR] = tp->t_intrc;
	t->c_cc[VQUIT] = tp->t_quitc;
	t->c_cc[VSTART] = tp->t_startc;
	t->c_cc[VSTOP] = tp->t_stopc;
	t->c_cc[VEOF] = tp->t_eofc;
	t->c_cc[VEOL] = tp->t_brkc;
	t->c_cc[VSUSP] = tp->t_suspc;
	t->c_cc[VDSUSP] = tp->t_dsuspc;
	t->c_cc[VREPRINT] = tp->t_rprntc;
	t->c_cc[VDISCARD] = tp->t_flushc;
	t->c_cc[VWERASE] = tp->t_werasc;
	t->c_cc[VLNEXT] = tp->t_lnextc;
	t->c_cc[VMIN] = np->t_min;
	t->c_cc[VTIME] = np->t_time;
	t->c_cc[VQUOTE] = np->t_quote;
}

/*
 * plan 245: the termios state (struct nty) of a tty; the list is kept
 * most recently used first.
 */
static struct nty	*ntys;

struct nty *
ttynty(tp)
	register struct tty *tp;
{
	register struct nty *np, **npp;
	int s = spltty();

	if (tp == 0)
		panic("ttynty(0)");
	for (npp = &ntys; (np = *npp) != 0; npp = &np->t_nforw)
		if (np->t == tp)
			break;
	if (np)
		*npp = np->t_nforw;
	else {
		np = (struct nty *)kalloc(sizeof (struct nty));
		np->t = tp;
		NTYDEFAULTS(np);
		np->t_session = 0;
		np->t_posix_pgrp = 0;
	}
	np->t_nforw = ntys;
	ntys = np;
	splx(s);
	return (np);
}

nullioctl()				/* plan 245 */
{
	return (-1);
}

#endif	NeXT
