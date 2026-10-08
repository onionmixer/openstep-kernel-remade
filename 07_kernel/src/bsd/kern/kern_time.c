/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * 15-Oct-90  Gregg Kellogg (gk) at NeXT
 *	Fixed bug in realitexpire that caused it to look for a long long
 *	time if the it_value is quite a bit less than time.  This happens
 *	when someone sets the time way forward after a timer with an
 *	interval expires.
 *
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: removed dir.h
 *
 * 19-Jun-89  Mike DeMoney (mike) at NeXT
 *	Put timers back to BSD version since additional accuracy is lost
 *	once timeout's are "quantized".
 *
 *  5-Jan-88  Gregg Kellogg (gk) at NeXT
 *	NeXT: realtime timers are now handled using micro-second
 *	accurate timeout facility (us_timeout).
 *
 * 20-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Changed inode.h to vnode.h.  (Why is this here anyways?)
 *
 */

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_time.c	7.4 (Berkeley) 3/23/87
 */

#import <machine/spl.h>

#import <sys/param.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/vnode.h>
#import <sys/proc.h>

#import <machine/reg.h>
#import <machine/cpu.h>
#import <mach/time_value.h>		/* plan 145 (authored) */
#import <kern/host.h>			/* plan 145 (authored) */

extern volatile mapped_time_value_t *mtime;	/* plan 145 (authored) */

struct	timeval boottime;	/* plan 401 (D060; D024, no evidence for the place) */
/* 
 * Time of day and interval timer support.
 *
 * These routines provide the kernel entry points to get and set
 * the time-of-day and per-process interval timers.  Subroutines
 * here provide support for adding and subtracting timeval structures
 * and decrementing interval timers, optionally reloading the interval
 * timers when they expire.
 */

gettimeofday()
{
	register struct a {
		struct	timeval *tp;
		struct	timezone *tzp;
	} *uap = (struct a *)u.u_ap;
	struct timeval atv;

	if (uap->tp) {
		microtime(&atv);
		u.u_error = copyout((caddr_t)&atv, (caddr_t)uap->tp,
			sizeof (atv));
		if (u.u_error)
			return;
	}
#if	NeXT
	/* ignore timezone since we no longer support it in kernel */
#else	NeXT
	if (uap->tzp)
		u.u_error = copyout((caddr_t)&tz, (caddr_t)uap->tzp,
			sizeof (tz));
#endif	NeXT
}

settimeofday()
{
	register struct a {
		struct	timeval *tv;
		struct	timezone *tzp;
	} *uap = (struct a *)u.u_ap;
	struct timeval atv;
	struct timezone atz;

	if (uap->tv) {
		u.u_error = copyin((caddr_t)uap->tv, (caddr_t)&atv,
			sizeof (struct timeval));
		if (u.u_error)
			return;
		setthetime(&atv);
	}
#if	NeXT
	/* ignore timezone since we no longer support it in kernel */
#else	NeXT
	if (uap->tzp && suser()) {
		u.u_error = copyin((caddr_t)uap->tzp, (caddr_t)&atz,
			sizeof (atz));
		if (u.u_error == 0)
			tz = atz;
	}
#endif	NeXT
}

setthetime(tv)
	struct timeval *tv;
{
	struct timeval now;			/* plan 145 (authored) */
	time_value_t new_time;			/* plan 145 (authored) */

	if (!suser())
		return;
	getthetime(&now);			/* plan 145 (authored) */
	boottime.tv_sec += tv->tv_sec - now.tv_sec;
	boottime.tv_usec = 0;			/* plan 145 (authored) */
	new_time.seconds = tv->tv_sec;		/* plan 145 (authored) */
	new_time.microseconds = tv->tv_usec;	/* plan 145 (authored) */
	host_set_time(realhost.host_priv_self, new_time);	/* plan 145 (authored) */
}

/*
 * plan 145 (authored): read the mapped time (mach/time_value.h comment; volatile
 * mtime and a time_value_t local are the form that matches the original, run s5p119-v2).
 */
getthetime(tv)
	struct timeval *tv;
{
	time_value_t t;

	do {
		t.seconds = mtime->seconds;
		t.microseconds = mtime->microseconds;
	} while (t.seconds != mtime->check_seconds);
	tv->tv_sec = t.seconds;
	tv->tv_usec = t.microseconds;
}

/* plan 145: tickadj/tickdelta/timedelta/bigadj are not defined here in the original
 * (0x1dee40-0x1dee4c lie apart from this object's data); adjtime no longer uses them. */

adjtime()
{
	register struct a {
		struct timeval *delta;
		struct timeval *olddelta;
	} *uap = (struct a *)u.u_ap;
	struct timeval atv, oatv;
	time_value_t adj, oadj;			/* plan 145 (authored) */

	if (!suser()) 
		return;
	u.u_error = copyin((caddr_t)uap->delta, (caddr_t)&atv,
		sizeof (struct timeval));
	if (u.u_error)
		return;
	adj.seconds = atv.tv_sec;		/* plan 145 (authored) */
	adj.microseconds = atv.tv_usec;		/* plan 145 (authored) */
	host_adjust_time(realhost.host_priv_self, adj, &oadj);	/* plan 145 (authored) */
	if (uap->olddelta) {
		oatv.tv_sec = oadj.seconds;	/* plan 145 (authored) */
		oatv.tv_usec = oadj.microseconds;	/* plan 145 (authored) */
		(void) copyout((caddr_t)&oatv, (caddr_t)uap->olddelta,
			sizeof (struct timeval));
	}
}

#define SECDAY          ((unsigned)(24*60*60))          /* seconds per day */
#define SECYR           ((unsigned)(365*SECDAY))        /* per common year */
#define YRREF           70      /* UNIX time referenced to 1970 */

/*
 * plan 145 (authored): inittodr with the structure and messages of Darwin 0.1
 * kern_time.c:221-293 (APSL 1.0), using a local timeval instead of time.
 */
inittodr(base)
	time_t base;
{
	struct timeval now;
	long deltat;

	if (base < (87-YRREF) * SECYR || base < 0) {	/* fs < than 1987? */
		printf("WARNING: preposterous time in file system");
		goto check;
	}
	microtime(&now);
	boottime.tv_sec = now.tv_sec;
	boottime.tv_usec = 0;
	deltat = boottime.tv_sec - base;
	if (deltat < 0)
		deltat = -deltat;
	if ((deltat < 2*SECDAY) && (boottime.tv_sec > base))
		return;
	if (boottime.tv_sec < SECYR) {
		printf ("WARNING: clock not set properly");
		now.tv_sec = base;
		now.tv_usec = 0;
		setthetime(&now);
		boottime = now;
		goto check;
	}
	if (deltat > 90*SECDAY) {	/* assume rtc is way off */
		printf ("WARNING: preposterous time in Real Time Clock");
		now.tv_sec = base;
		now.tv_usec = 0;
		setthetime(&now);
		boottime = now;
		goto check;
	}
	printf("WARNING: clock lost %d days", deltat / SECDAY);
check:
	printf(" -- CHECK AND RESET THE DATE!\n");
}

/*
 * Get value of an interval timer.  The process virtual and
 * profiling virtual time timers are kept in the u. area, since
 * they can be swapped out.  These are kept internally in the
 * way they are specified externally: in time until they expire.
 *
 * The real time interval timer is kept in the process table slot
 * for the process, and its value (it_value) is kept as an
 * absolute time rather than as a delta, so that it is easy to keep
 * periodic real-time signals from drifting.
 *
 * Virtual time timers are processed in the hardclock() routine of
 * kern_clock.c.  The real time timer is processed by a timeout
 * routine, called from the softclock() routine.  Since a callout
 * may be delayed in real time due to interrupt processing in the system,
 * it is possible for the real time timeout routine (realitexpire, given below),
 * to be delayed in real time past when it is supposed to occur.  It
 * does not suffice, therefore, to reload the real timer .it_value from the
 * real time timers .it_interval.  Rather, we compute the next time in
 * absolute time the timer should go off.
 */
getitimer()
{
	register struct a {
		u_int	which;
		struct	itimerval *itv;
	} *uap = (struct a *)u.u_ap;
	struct itimerval aitv;
	int s;
	struct timeval now;			/* plan 145 (authored) */

	if (uap->which > 2) {
		u.u_error = EINVAL;
		return;
	}
	s = splclock();
	if (uap->which == ITIMER_REAL) {
		getthetime(&now);		/* plan 145 (authored) */
		/*
		 * Convert from absoulte to relative time in .it_value
		 * part of real time timer.  If time for real time timer
		 * has passed return 0, else return difference between
		 * current time and time for the timer to go off.
		 */
		aitv = u.u_procp->p_realtimer;
		if (timerisset(&aitv.it_value))
			if (timercmp(&aitv.it_value, &now, <))
				timerclear(&aitv.it_value);
			else
				timevalsub(&aitv.it_value, &now);
	} else
		aitv = u.u_timer[uap->which];
	splx(s);
	u.u_error = copyout((caddr_t)&aitv, (caddr_t)uap->itv,
	    sizeof (struct itimerval));
}

setitimer()
{
	register struct a {
		u_int	which;
		struct	itimerval *itv, *oitv;
	} *uap = (struct a *)u.u_ap;
	struct itimerval aitv, *aitvp;
	int s;
	register struct proc *p = u.u_procp;
	struct timeval now;			/* plan 145 (authored) */

	if (uap->which > 2) {
		u.u_error = EINVAL;
		return;
	}
	aitvp = uap->itv;
	if (uap->oitv) {
		uap->itv = uap->oitv;
		getitimer();
	}
	if (aitvp == 0)
		return;
	u.u_error = copyin((caddr_t)aitvp, (caddr_t)&aitv,
	    sizeof (struct itimerval));
	if (u.u_error)
		return;
	if (itimerfix(&aitv.it_value) || itimerfix(&aitv.it_interval)) {
		u.u_error = EINVAL;
		return;
	}
	s = splclock();
	if (uap->which == ITIMER_REAL) {
		getthetime(&now);		/* plan 145 (authored) */
		untimeout(realitexpire, (caddr_t)p);
		if (timerisset(&aitv.it_value)) {
			timevaladd(&aitv.it_value, &now);
			timeout(realitexpire, (caddr_t)p, hzto(&aitv.it_value));
		}
		p->p_realtimer = aitv;
	} else
		u.u_timer[uap->which] = aitv;
	splx(s);
}

/*
 * Real interval timer expired:
 * send process whose timer expired an alarm signal.
 * If time is not set up to reload, then just return.
 * Else compute next time timer should go off which is > current time.
 * This is where delay in processing this timeout causes multiple
 * SIGALRM calls to be compressed into one.
 */
realitexpire(p)
	register struct proc *p;
{
	int s;
	struct timeval now;			/* plan 145 (authored) */

	psignal(p, SIGALRM);
	if (!timerisset(&p->p_realtimer.it_interval)) {
		timerclear(&p->p_realtimer.it_value);
		return;
	}
#if	NeXT
	/*
	 * If the time's way off, don't try to compensate by getting
	 * there incrementally.
	 */
	getthetime(&now);			/* plan 145 (authored) */
	s = splclock();
	if (p->p_realtimer.it_value.tv_sec < now.tv_sec - 10) {
		p->p_realtimer.it_value = now;
		timeout(realitexpire, (caddr_t)p,
			hzto(&p->p_realtimer.it_value));
		splx(s);
		return;
		
	}
	splx(s);
#endif	NeXT
	for (;;) {
		s = splclock();
		timevaladd(&p->p_realtimer.it_value,
		    &p->p_realtimer.it_interval);
		if (timercmp(&p->p_realtimer.it_value, &now, >)) {
			timeout(realitexpire, (caddr_t)p,
			    hzto(&p->p_realtimer.it_value));
			splx(s);
			return;
		}
		splx(s);
	}
}

/*
 * Check that a proposed value to load into the .it_value or
 * .it_interval part of an interval timer is acceptable, and
 * fix it to have at least minimal value (i.e. if it is less
 * than the resolution of the clock, round it up.)
 */
itimerfix(tv)
	struct timeval *tv;
{

	if (tv->tv_sec < 0 || tv->tv_sec > 100000000 ||
	    tv->tv_usec < 0 || tv->tv_usec >= 1000000)
		return (EINVAL);
	if (tv->tv_sec == 0 && tv->tv_usec != 0 && tv->tv_usec < tick)
		tv->tv_usec = tick;
	return (0);
}

/*
 * Decrement an interval timer by a specified number
 * of microseconds, which must be less than a second,
 * i.e. < 1000000.  If the timer expires, then reload
 * it.  In this case, carry over (usec - old value) to
 * reducint the value reloaded into the timer so that
 * the timer does not drift.  This routine assumes
 * that it is called in a context where the timers
 * on which it is operating cannot change in value.
 */
itimerdecr(itp, usec)
	register struct itimerval *itp;
	int usec;
{

	if (itp->it_value.tv_usec < usec) {
		if (itp->it_value.tv_sec == 0) {
			/* expired, and already in next interval */
			usec -= itp->it_value.tv_usec;
			goto expire;
		}
		itp->it_value.tv_usec += 1000000;
		itp->it_value.tv_sec--;
	}
	itp->it_value.tv_usec -= usec;
	usec = 0;
	if (timerisset(&itp->it_value))
		return (1);
	/* expired, exactly at end of interval */
expire:
	if (timerisset(&itp->it_interval)) {
		itp->it_value = itp->it_interval;
		itp->it_value.tv_usec -= usec;
		if (itp->it_value.tv_usec < 0) {
			itp->it_value.tv_usec += 1000000;
			itp->it_value.tv_sec--;
		}
	} else
		itp->it_value.tv_usec = 0;		/* sec is already 0 */
	return (0);
}

/*
 * Add and subtract routines for timevals.
 * N.B.: subtract routine doesn't deal with
 * results which are before the beginning,
 * it just gets very confused in this case.
 * Caveat emptor.
 */
timevaladd(t1, t2)
	struct timeval *t1, *t2;
{

	t1->tv_sec += t2->tv_sec;
	t1->tv_usec += t2->tv_usec;
	timevalfix(t1);
}

timevalsub(t1, t2)
	struct timeval *t1, *t2;
{

	t1->tv_sec -= t2->tv_sec;
	t1->tv_usec -= t2->tv_usec;
	timevalfix(t1);
}

timevalfix(t1)
	struct timeval *t1;
{

	if (t1->tv_usec < 0) {
		t1->tv_sec--;
		t1->tv_usec += 1000000;
	}
	if (t1->tv_usec >= 1000000) {
		t1->tv_sec++;
		t1->tv_usec -= 1000000;
	}
}

