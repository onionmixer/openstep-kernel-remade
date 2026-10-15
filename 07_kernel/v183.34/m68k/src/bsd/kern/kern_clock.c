/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/* plan 455 (m68k) begin: notice for the line marked "plan 455 (Darwin)" (D061 precedent) */
/*
 * The line marked "plan 455 (Darwin)" follows Darwin 0.1
 * kernel/bsd/kern/kern_clock.c:171 (kernel-1), whose notice is:
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
/* plan 455 (m68k) end */
/*
 * HISTORY
 * 14-May-90  Gregg Kellogg (gk) at NeXT
 *	NeXT uses timeouts from hardclock again.  Timeout and untimeout
 *	work as on other systems, they're scheduled via hardclock directly
 *	from softclock.  The us_timeout and us_abstimeout functions work
 *	as before.  Us_untimeout untimes out things scheduled via the above.
 *
 * 18-Feb-90  Gregg Kellogg (gk) at NeXT
 *	Moved defined of dk_ndrive to bsd/init_main.c
 *
 * Revision 2.19  89/10/11  13:36:45  dlb
 * 	Add untimeout_try for multiprocessors.
 * 	Remove timestamp support.
 * 	Don't reset timeofday clock here on multimax because multimax
 * 	     routine might block (XXX).
 * 
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes:  Remove dir.h inclusion
 *
 * 09-Jun-89  Mike DeMoney (mike) at NeXT
 *	NeXT no longer has special args for hardclock.  Usec_elapsed()
 *	no takes arg which is "usec_mark" so that usec_elapsed can be
 *	used in multiple contexts.  Hardclock was re-arranged so that
 *	stuff NeXT does from us_timer could be ifdef'ed out as a single
 *	chunk.  NeXT version of timeout no longer spl's, since it just
 *	calls us_timeout.  Hzto() converted back to be "time" rather
 *	than timefromboot base (for BSD compatability).
 *
 * 12-May-88  David Golub (dbg) at Carnegie-Mellon University
 *	MACH: eliminate updates to otherwise unused proc structure
 *	fields: p_rssize, p_cpticks.
 *
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	MACH_TIME_NEW is now standard.  Removed slow_clock.
 *	Get rid of u_ru.ru_{utime,stime}.  Autonice code removed
 *	for MACH_TIME_NEW (see schedcpu() in kern_synch.c).
 *	Replaced cpu_idle checks with check to see if current_thread()
 *	is an idle thread.
 *
 * 19-Apr-88  Gregg Kellogg (gk) at NeXT
 *	NeXT: Hardclock is run off the microsecond timer via softints.
 *
 * 29-Mar-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	MACH: Removed use of "sys/vm.h".
 *
 * 29-Dec-87  Robert Baron (rvb) at Carnegie-Mellon University
 *	Define softclock as a function before it is used as an argument
 *	to softcall so that gcc will get the correct type.
 *
 * 21-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Simplified conditionals, purged history.
 */

#import <simple_clock.h>
#import <stat_time.h>
#import <cpus.h>

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_clock.c	7.1 (Berkeley) 6/5/86
 */

#import <machine/reg.h>
#import <machine/psl.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/dk.h>
#import <sys/callout.h>
#import <sys/dir.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/proc.h>
#import <sys/table.h>

#import <machine/spl.h>

#import <kern/ast.h>

#import <machine/cpu.h>

#import <kern/thread.h>
#import <mach/machine.h>	/* plan 233: NeXTMach sys/machine.h */
#import <kern/sched.h>
#import <mach/time_value.h>	/* plan 233: NeXTMach sys/time_value.h */
#import <kern/timer.h>
#import <kern/xpr.h>

#import <mach/boolean.h>	/* plan 233: NeXTMach sys/boolean.h */
#if	SIMPLE_CLOCK	/* plan 455 (m68k) begin: hardclock elapsed time (original _hardclock 0x40033d2; D024, D074, D075) */
#import <kernserv/clock_timer.h>
extern ns_time_t	clock_value();
ns_time_t	last_hardclock[NCPUS];	/* D075: original __common 0x40b605c; as Darwin 0.1 kern_clock.c */

/*
 * m68k 64-bit division by a 32-bit divisor (divull/divul); the high word of
 * the quotient is written back, the low word returned (authored, D024).
 */
static inline unsigned int
ns_div_val(ll, divisor)
	ns_time_t	ll;
	unsigned int	divisor;
{
	unsigned int	*msw, *lsw;
	unsigned int	quo, rem;

	msw = &((unsigned int *)&ll)[0];
	lsw = &((unsigned int *)&ll)[1];

	asm("divull %2,%0:%1"
	    : "=d" (rem), "=d" (quo)
	    : "dmi" (divisor), "1" (*msw), "0" (0));
	*msw = quo;
	asm("divul %2,%0:%1"
	    : "=d" (rem), "=d" (quo)
	    : "dmi" (divisor), "1" (*lsw), "0" (rem));
	return (quo);
}

#endif	/* SIMPLE_CLOCK; plan 455 (m68k) end */

extern struct callout *callout;	/* plan 401: defined in conf/param.c (as NeXTMach sys/callout.h:48 extern) */
int ncallout;

/*
 * plan 233 (authored, D024; original _hardclock 0x10349c): the
 * NeXTMach hardclock without the clock tick, master-cpu, time-of-day
 * and callout parts, which OPENSTEP keeps in the Mach clock code.
 */
/*ARGSUSED*/
hardclock(pc, ps)
	caddr_t pc;
	int ps;
{
	register thread_t	thread;
#if	SIMPLE_CLOCK	/* plan 455 (m68k) begin */
	ns_time_t	new_hardclock;
	ns_time_t	delta_hardclock;
	unsigned int	myticks;
#define	tick	myticks
#endif	/* SIMPLE_CLOCK; plan 455 (m68k) end */

	thread = current_thread();
#if	SIMPLE_CLOCK	/* plan 455 (m68k) begin: time since the previous hardclock, in microseconds (D074) */
	new_hardclock = clock_value(System);
	delta_hardclock = new_hardclock - last_hardclock[cpu_number()];
	myticks = ns_div_val(delta_hardclock, 1000);
	last_hardclock[cpu_number()] = new_hardclock;	/* plan 455 (Darwin): as Darwin 0.1 kern_clock.c:171 */
#endif	/* SIMPLE_CLOCK; plan 455 (m68k) end */

	/*
	 * Charge the time out based on the mode the cpu is in.
	 * Here again we fudge for the lack of proper interval timers
	 * assuming that the current state has been around at least
	 * one tick.
	 */
	if (USERMODE(ps)) {
		if (u.u_procp) {
			if (u.u_prof.pr_scale) {
				u.u_procp->p_flag |= SOWEUPC;
				ast_on(cpu_number(), AST_UNIX);
			}
		}
		/*
		 * CPU was in user state.  Increment
		 * user time counter, and process process-virtual time
		 * interval timer. 
		 */
		if (timerisset(&u.u_timer[ITIMER_VIRTUAL].it_value) &&
		    itimerdecr(&u.u_timer[ITIMER_VIRTUAL], tick) == 0)
			psignal(u.u_procp, SIGVTALRM);
	}

	/*
	 * If the cpu is currently scheduled to a process, then
	 * charge it with resource utilization for a tick, updating
	 * statistics which run in (user+system) virtual time,
	 * such as the cpu time limit and profiling timers.
	 * This assumes that the current process has been running
	 * the entire last tick.
	 */
	if (u.u_procp && !(thread->state & TH_IDLE))
	{
		if (u.u_rlimit[RLIMIT_CPU].rlim_cur != RLIM_INFINITY) {
		    time_value_t	sys_time, user_time;

		    thread_read_times(thread, &user_time, &sys_time);
		    if ((sys_time.seconds + user_time.seconds + 1) >
		        u.u_rlimit[RLIMIT_CPU].rlim_cur) {
			psignal(u.u_procp, SIGXCPU);
			if (u.u_rlimit[RLIMIT_CPU].rlim_cur <
			    u.u_rlimit[RLIMIT_CPU].rlim_max)
				u.u_rlimit[RLIMIT_CPU].rlim_cur += 5;
			}
		}
		if (timerisset(&u.u_timer[ITIMER_PROF].it_value) &&
		    itimerdecr(&u.u_timer[ITIMER_PROF], tick) == 0)
			psignal(u.u_procp, SIGPROF);
	}

	gatherstats(pc, ps);
}
#if	SIMPLE_CLOCK	/* plan 455 (m68k) begin */
#undef	tick
#endif	/* SIMPLE_CLOCK; plan 455 (m68k) end */

/*
 * Gather statistics on resource utilization.
 *
 * We make a gross assumption: that the system has been in the
 * state it is in (user state, kernel state, interrupt state,
 * or idle state) for the entire last time interval, and
 * update statistics accordingly.
 */
/*ARGSUSED*/
gatherstats(pc, ps)
	caddr_t pc;
	int ps;
{
	register int cpstate, s;

	/*
	 * Determine what state the cpu is in.
	 */
	if (USERMODE(ps)) {
		/*
		 * CPU was in user state.
		 */
		if (u.u_procp->p_nice > NZERO)
			cpstate = CP_NICE;
		else
			cpstate = CP_USER;
	} else {
		/*
		 * CPU was in system state.  If profiling kernel
		 * increment a counter.  If no process is running
		 * then this is a system tick if we were running
		 * at a non-zero IPL (in a driver).  If a process is running,
		 * then we charge it with system time even if we were
		 * at a non-zero IPL, since the system often runs
		 * this way during processing of system calls.
		 * This is approximate, but the lack of true interval
		 * timers makes doing anything else difficult.
		 */
		cpstate = CP_SYS;
		if ((current_thread()->state & TH_IDLE) && BASEPRI(ps))
			cpstate = CP_IDLE;
	}
	/*
	 * We maintain statistics shown by user-level statistics
	 * programs:  the amount of time in each cpu state, and
	 * the amount of time each of DK_NDRIVE ``drives'' is busy.
	 */
	cp_time[cpstate]++;
	for (s = 0; s < DK_NDRIVE; s++)
		if (dk_busy & (1 << s))
			dk_time[s]++;
}

/*
 * plan 233 (authored, D024; original _timeout 0x103658,
 * _untimeout 0x103684): the tick timeouts are nanosecond timeouts.
 */
timeout(fun, arg, t)
	int (*fun)();
	caddr_t arg;
	register int t;
{
	extern unsigned long long	ticks_to_ns_time();

	ns_timeout(fun, arg, ticks_to_ns_time(t), 0);
}

untimeout(fun, arg)
	int (*fun)();
	caddr_t arg;
{
	(void) ns_untimeout(fun, arg);
}

/*
 * Compute number of hz until specified time.
 * Used to compute third argument to timeout() from an
 * absolute time.
 */
hzto(tv)
	struct timeval *tv;
{
	register long ticks;
	register long sec;
	struct timeval now;

	/*
	 * plan 233 (original 0x1036a4): the current time from getthetime,
	 * without splhigh.
	 */
	getthetime(&now);
	/*
	 * If number of milliseconds will fit in 32 bit arithmetic,
	 * then compute number of milliseconds to time and scale to
	 * ticks.  Otherwise just compute number of hz in time, rounding
	 * times greater than representible to maximum value.
	 *
	 * Delta times less than 25 days can be computed ``exactly''.
	 * Maximum value for any timeout in 10ms ticks is 250 days.
	 */
	sec = tv->tv_sec - now.tv_sec;
	if (sec <= 0x7fffffff / 1000 - 1000)
		ticks = ((tv->tv_sec - now.tv_sec) * 1000 +
			(tv->tv_usec - now.tv_usec) / 1000) / (tick / 1000);
	else if (sec <= 0x7fffffff / hz)
		ticks = sec * hz;
	else
		ticks = 0x7fffffff;
	return (ticks);
}

/*
 * Convert ticks to a timeval
 */
ticks_to_timeval(ticks, tvp)
	register long ticks;
	struct timeval *tvp;
{
	tvp->tv_sec = ticks/hz;
	tvp->tv_usec = (ticks%hz) * tick;
}

/*
 * plan 233 (authored, D024; original _profil 0x10374c): set the
 * first profiling buffer and free the ones add_profil chained on.
 */
profil()
{
	register struct a {
		short	*bufbase;
		unsigned bufsize;
		unsigned pcoffset;
		unsigned pcscale;
	} *uap = (struct a *)u.u_ap;
	register struct uuprof *upp = &u.u_prof;
	register struct uuprof *p, *next;

	upp->pr_base = uap->bufbase;
	upp->pr_size = uap->bufsize;
	upp->pr_off = uap->pcoffset;
	upp->pr_scale = uap->pcscale;
	if (upp->pr_lock == 0) {
		upp->pr_lock = simple_lock_alloc();
		simple_lock_init(upp->pr_lock);
	}
	for (p = upp->pr_next; p; p = next) {
		next = p->pr_next;
		kfree((vm_offset_t)p, sizeof (struct uuprof));
	}
	upp->pr_next = 0;
}

/*
 * plan 233 (authored, D024; original _add_profil 0x1037d0): chain one
 * more profiling buffer while profiling is on.
 */
add_profil()
{
	register struct a {
		short	*bufbase;
		unsigned bufsize;
		unsigned pcoffset;
		unsigned pcscale;
	} *uap = (struct a *)u.u_ap;
	register struct uuprof *upp = &u.u_prof;
	register struct uuprof *p;

	if (upp->pr_scale == 0)
		return;
	p = (struct uuprof *)kalloc(sizeof (struct uuprof));
	p->pr_base = uap->bufbase;
	p->pr_size = uap->bufsize;
	p->pr_off = uap->pcoffset;
	p->pr_scale = uap->pcscale;
	p->pr_next = upp->pr_next;
	upp->pr_next = p;
}
