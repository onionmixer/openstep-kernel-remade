/*
 * kern/ns_timer.c -- nanosecond timer support.
 *
 * plan 234 (authored, D024): written from the original OPENSTEP 4.2
 * x86 kernel object [0x160478, 0x160adc).  The function list follows
 * the original symbol order; no reference text was copied.
 */

#import <sys/param.h>
#import <sys/kernel.h>
#import <kernserv/clock_timer.h>
#import <kernserv/ns_timer.h>
#import <kern/time_stamp.h>
#import <mach/time_value.h>

#define	NSEC_PER_SEC	1000000000
#define	NSEC_PER_USEC	1000

extern ns_time_t	clock_value();
extern void		set_clock();
extern void		hardclock_init();
extern void		calloutDispatchDelayed();
extern void		calloutRemove();

ns_time_t	ns_per_tick;

/*
 * Divide the 64-bit value *ll by divisor in place, one 32-bit word at
 * a time with divl, and return the remainder through *remain.
 */
static inline void
ns_div(ll, divisor, remain)
	ns_time_t	*ll;
	unsigned int	divisor;
	unsigned int	*remain;
{
	unsigned int	*msw, *lsw;
	unsigned int	quo, rem;

	lsw = &((unsigned int *)ll)[0];
	msw = &((unsigned int *)ll)[1];

	asm("divl %2"
	    : "=a" (quo), "=d" (rem)
	    : "rm" (divisor), "0" (*msw), "1" (0));
	*msw = quo;
	asm("divl %2"
	    : "=a" (quo), "=d" (*remain)
	    : "rm" (divisor), "0" (*lsw), "1" (rem));
	*lsw = quo;
}

void
ns_hardclock_init()
{
	ns_per_tick = NSEC_PER_SEC / hz;
	hardclock_init(ns_per_tick);
}

/*
 * Arrange that proc is called with arg after time nanoseconds.
 */
void
ns_timeout(func proc, void *arg, ns_time_t time, int pri)
{
	time += clock_value(System);	/* plan 234.1: time read before the call (variant t1) */
	calloutDispatchDelayed(proc, arg, time);
}

/*
 * Arrange that proc is called with arg at deadline (system clock).
 */
void
ns_abstimeout(func proc, void *arg, ns_time_t deadline, int pri)
{
	calloutDispatchDelayed(proc, arg, deadline);
}

boolean_t
ns_untimeout(func proc, void *arg)
{
	calloutRemove(proc, arg);
	return (TRUE);
}

void
ns_sleep(ns_time_t delay)
{
	int	s;
	extern void	wakeup();

	s = splnet();
	ns_timeout((func)wakeup, &delay, delay, 0);
	sleep((caddr_t)&delay, PZERO - 1);
	splx(s);
}

void
ns_time_to_timeval(ns_time_t nano_time, struct timeval *tvp)
{
	ns_div(&nano_time, NSEC_PER_SEC, (unsigned int *)&tvp->tv_usec);
	tvp->tv_sec = (unsigned int)nano_time;
	tvp->tv_usec /= NSEC_PER_USEC;
}

ns_time_t
timeval_to_ns_time(struct timeval *tvp)
{
	ns_time_t	a_time;

	a_time = (ns_time_t)tvp->tv_sec * 1000000 + tvp->tv_usec;
	a_time *= NSEC_PER_USEC;
	return (a_time);
}

void
ns_time_to_tsval(ns_time_t nano_time, struct tsval *tsp)
{
	unsigned int	remain;

	ns_div(&nano_time, NSEC_PER_USEC, &remain);
	tsp->low_val = (unsigned int)nano_time;
	tsp->high_val = (unsigned int)(nano_time >> 32);
}

ns_time_t
ticks_to_ns_time(unsigned int ticks)
{
	return (ticks * ns_per_tick);
}

/*
 * Divide the 64-bit value ll by divisor and return the low word of
 * the quotient.
 */
static inline unsigned int
ns_div_val(ll, divisor)
	ns_time_t	ll;
	unsigned int	divisor;
{
	unsigned int	*msw, *lsw;
	unsigned int	quo, rem;

	lsw = &((unsigned int *)&ll)[0];
	msw = &((unsigned int *)&ll)[1];

	asm("divl %2"
	    : "=a" (quo), "=d" (rem)
	    : "rm" (divisor), "0" (*msw), "1" (0));
	asm("divl %1"
	    : "=a" (quo)
	    : "rm" (divisor), "0" (*lsw), "d" (rem));
	return (quo);
}

/*
 * Microseconds since the previous call (system clock).
 */
unsigned int
sched_usec_elapsed()
{
	static ns_time_t	last;
	ns_time_t		now;
	unsigned int		usec;

	now = clock_value(System);
	if (last == 0)
		last = now;
	usec = ns_div_val(now - last, NSEC_PER_USEC);
	last = now;
	return (usec);
}

void
get_calendar_time_value(time_value_t *tvp)
{
	ns_time_t	now = clock_value(Calendar);	/* plan 234.1 (variant g1) */

	ns_div(&now, NSEC_PER_SEC, (unsigned int *)&tvp->microseconds);
	tvp->seconds = (unsigned int)now;
	tvp->microseconds /= NSEC_PER_USEC;
}

void
set_calendar_time_value(time_value_t *tvp)
{
	set_clock(Calendar, (ns_time_t)tvp->seconds * NSEC_PER_SEC +
		  (ns_time_t)tvp->microseconds * NSEC_PER_USEC);
}

/*
 * The calendar time as a timeval; never earlier than the previous
 * answer by less than a second.
 */
void
microtime(struct timeval *tvp)
{
	static ns_time_t	last_time = 0;
	ns_time_t		now;
	int			s;

	s = splusclock();
	now = clock_value(Calendar);
	if (last_time > now && last_time - now < NSEC_PER_SEC)
		now = last_time;
	last_time = now;
	splx(s);
	ns_time_to_timeval(now, tvp);
}

/*
 * Time since boot as a timeval.
 */
void
microboot(struct timeval *tvp)
{
	ns_time_to_timeval(clock_value(System), tvp);
}

void
us_timeout(func proc, void *arg, struct timeval *tvp, int pri)
{
	ns_timeout(proc, arg, timeval_to_ns_time(tvp), pri);
}

void
us_abstimeout(func proc, void *arg, struct timeval *tvp, int pri)
{
	ns_abstimeout(proc, arg, timeval_to_ns_time(tvp), pri);
}

boolean_t
us_untimeout(func proc, void *arg)
{
	return (ns_untimeout(proc, arg));
}
