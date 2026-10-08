/*
 * Mach Operating System
 * Copyright (c) 1994-1988 Carnegie Mellon University.
 * Copyright (c) 1993,1994 The University of Utah and
 * the Computer Systems Laboratory (CSL).
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON, THE UNIVERSITY OF UTAH AND CSL ALLOW FREE USE OF
 * THIS SOFTWARE IN ITS "AS IS" CONDITION, AND DISCLAIM ANY LIABILITY
 * OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF
 * THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 *	File:	clock_prim.c
 *	Author:	Avadis Tevanian, Jr.
 *	Date:	1986
 *
 *	Clock primitives.
 */
#include <cpus.h>
#include <mach_pcsample.h>
#include <stat_time.h>

#include <mach/boolean.h>
#include <mach/machine.h>
#include <mach/time_value.h>
#include <mach/vm_param.h>
#include <mach/vm_prot.h>
#include <kern/counters.h>
#include "cpu_number.h"
#include <kern/host.h>
#include <kern/lock.h>
#include <kern/mach_param.h>
#include <kern/processor.h>
#include <kern/sched.h>
#include <kern/sched_prim.h>
#include <kern/thread.h>
#include <kern/time_out.h>
#include <kern/time_stamp.h>
#include <vm/vm_kern.h>
#include <sys/time.h>
#include <machine/mach_param.h>	/* HZ */
#include <machine/machspl.h>



unsigned long long	time_of_boot;	/* plan 235: adjusted with timedelta */

int		hz = HZ;		/* number of ticks per second */
int		tick = (1000000 / HZ);	/* number of usec per tick */
time_value_t	time = { 0, 0 };	/* time since bootup (uncorrected) */

int		timedelta = 0;
int		tickdelta = 0;

#if	HZ > 500
int		tickadj = 1;		/* can adjust HZ usecs per second */
#else
int		tickadj = 500 / HZ;	/* can adjust 100 usecs per second */
#endif
int		bigadj = 1000000;	/* adjust 10*tickadj if adjustment
					   > bigadj */

/*
 *	This update protocol, with a check value, allows
 *		do {
 *			secs = mtime->seconds;
 *			usecs = mtime->microseconds;
 *		} while (secs != mtime->check_seconds);
 *	to read the time correctly.  (On a multiprocessor this assumes
 *	that processors see each other's writes in the correct order.
 *	We may have to insert fence operations.)
 */

mapped_time_value_t *mtime = 0;

#define update_mapped_time(time)				\
MACRO_BEGIN							\
	if (mtime != 0) {					\
		mtime->check_seconds = (time)->seconds;		\
		mtime->microseconds = (time)->microseconds;	\
		mtime->seconds = (time)->seconds;		\
	}							\
MACRO_END

decl_simple_lock_data(static,	timer_lock)	/* plan 235: static */

/*
 *	Handle clock interrupts.
 *
 *	The clock interrupt is assumed to be called at a (more or less)
 *	constant rate.  The rate must be identical on all CPUS (XXX - fix).
 *
 *	Usec is the number of microseconds that have elapsed since the
 *	last clock tick.  It may be constant or computed, depending on
 *	the accuracy of the hardware clock.
 *
 *	plan 235 (D024): no timeout queue here (the callouts run the
 *	timeouts); the time of boot follows clock adjustments
 *	(original 0x15bc30-0x15bda7).
 */
void clock_interrupt(usec, usermode, basepri)
	register int	usec;		/* microseconds per tick */
	boolean_t	usermode;	/* executing user code */
	boolean_t	basepri;	/* at base priority */
{
	register int		my_cpu = cpu_number();
	register thread_t	thread = current_thread();

#if	STAT_TIME
	/*
	 *	Increment the thread time, if using
	 *	statistical timing.
	 */
	if (usermode) {
	    timer_bump(&thread->user_timer, usec);
	}
	else {
	    timer_bump(&thread->system_timer, usec);
	}
#endif	STAT_TIME

	/*
	 *	Increment the CPU time statistics.
	 */
	{
	    extern void	thread_quantum_update(); /* in priority.c */
	    register int	state;

	    if (usermode)
		state = CPU_STATE_USER;
	    else if (!cpu_idle(my_cpu))
		state = CPU_STATE_SYSTEM;
	    else
		state = CPU_STATE_IDLE;

	    machine_slot[my_cpu].cpu_ticks[state]++;

	    /*
	     *	Adjust the thread's priority and check for
	     *	quantum expiration.
	     */

	    if (!(thread->state & TH_IDLE))	/* plan 235 (0x15bcb6) */
		thread_quantum_update(my_cpu, thread, 1, state);
	}

	/*
	 *	Time-of-day is updated only
	 *	on the master CPU.
	 */
	if (my_cpu == master_cpu) {

	    /*
	     *	Increment the time-of-day clock.
	     */
	    if (timedelta == 0) {
		time_value_add_usec(&time, usec);
	    }
	    else {
		register int	delta;

		if (timedelta < 0) {
		    delta = usec - tickdelta;
		    timedelta += tickdelta;
		    time_of_boot -= tickdelta * 1000;	/* plan 235 */
		}
		else {
		    delta = usec + tickdelta;
		    timedelta -= tickdelta;
		    time_of_boot += tickdelta * 1000;	/* plan 235 */
		}
		time_value_add_usec(&time, delta);
	    }
	    update_mapped_time(&time);
	}
}

/*
 * plan 235 (authored, D024; original 0x15c0ac, no symbol): callout
 * handler of a timer element.
 */
static void service_timer();

/*
 * plan 235 (authored, D024; original _init_timeout_element 0x15bda8):
 * make the element's callout call service_timer with the element.
 */
void init_timeout_element(telt)
	register timer_elt_t	telt;
{
	telt->call.func = (thread_call_func_t)service_timer;
	telt->call.spec_proto = telt;
	telt->call.status = IDLE;
}

/*
 *	Set timeout.
 *
 *	Parameters:
 *		telt	 timer element.  Function and param are already set.
 *		interval time-out interval, in hz.
 */
void set_timeout(telt, interval)
	register timer_elt_t	telt;	/* already loaded */
	register unsigned int	interval;
{
	spl_t			s;
	extern unsigned long long	ticks_to_ns_time();
	extern unsigned long long	calloutDeadlineFromInterval();

	s = splsched();
	simple_lock(&timer_lock);
	/* plan 235 (original 0x15bdf0-0x15be03) */
	calloutEntryDispatchDelayed(&telt->call,
		calloutDeadlineFromInterval(ticks_to_ns_time(interval)));
	telt->set = TELT_SET;
	simple_unlock(&timer_lock);
	splx(s);
}

boolean_t reset_timeout(telt)
	register timer_elt_t	telt;
{
	spl_t	s;

	s = splsched();
	simple_lock(&timer_lock);
	if (telt->set) {
	    calloutEntryRemove(&telt->call);	/* plan 235 */
	    telt->set = TELT_UNSET;
	    simple_unlock(&timer_lock);
	    splx(s);
	    return TRUE;
	}
	else {
	    simple_unlock(&timer_lock);
	    splx(s);
	    return FALSE;
	}
}

void init_timeout()
{
	simple_lock_init(&timer_lock);
}

/*
 * Read the time.
 */
kern_return_t
host_get_time(host, current_time)
	host_t		host;
	time_value_t	*current_time;	/* OUT */
{
	if (host == HOST_NULL)
		return(KERN_INVALID_HOST);

	do {
		current_time->seconds = mtime->seconds;
		current_time->microseconds = mtime->microseconds;
	} while (current_time->seconds != mtime->check_seconds);

	return (KERN_SUCCESS);
}

/*
 * Set the time.  Only available to privileged users.
 */
kern_return_t
host_set_time(host, new_time)
	host_t		host;
	time_value_t	new_time;
{
	spl_t	s;

	if (host == HOST_NULL)
		return(KERN_INVALID_HOST);

	s = splhigh();
	time = new_time;
	update_mapped_time(&time);
	set_calendar_time_value(&time);	/* plan 235 (was resettodr) */
	splx(s);

	return (KERN_SUCCESS);
}

/*
 * Adjust the time gradually.
 */
kern_return_t
host_adjust_time(host, new_adjustment, old_adjustment)
	host_t		host;
	time_value_t	new_adjustment;
	time_value_t	*old_adjustment;	/* OUT */
{
	time_value_t	oadj;
	unsigned int	ndelta;
	spl_t		s;

	if (host == HOST_NULL)
		return (KERN_INVALID_HOST);

	ndelta = new_adjustment.seconds * 1000000
		+ new_adjustment.microseconds;

	s = splhigh();			/* plan 235 (was splclock) */

	oadj.seconds = timedelta / 1000000;
	oadj.microseconds = timedelta % 1000000;

	if (timedelta == 0) {
	    if (ndelta > bigadj)
		tickdelta = 10 * tickadj;
	    else
		tickdelta = tickadj;
	}
	if (ndelta % tickdelta)
	    ndelta = ndelta / tickdelta * tickdelta;

	timedelta = ndelta;

	splx(s);

	*old_adjustment = oadj;

	return (KERN_SUCCESS);
}

/*
 * plan 235 (D024; original _mach_clock_bootstrap 0x15c024): the Mach4
 * mapable_time_init with the calendar time read at start-up.
 */
void mach_clock_bootstrap()
{
	spl_t	s;

	if (kmem_alloc_wired(kernel_map, (vm_offset_t *) &mtime, page_size)
						!= KERN_SUCCESS)
		panic("mappable_time_init");	/* plan 235 (0x1dee54) */
	bzero((char *)mtime, page_size);
	s = splhigh();
	get_calendar_time_value(&time);
	update_mapped_time(&time);
	splx(s);
}

static void
service_timer(telt)
	timer_elt_t	telt;
{
	spl_t		s;
	int		(*fcn)();
	char		*param;

	s = splsched();
	simple_lock(&timer_lock);
	fcn = telt->fcn;
	param = telt->param;
	telt->set = TELT_UNSET;
	simple_unlock(&timer_lock);
	splx(s);
	(*fcn)(param);
}
