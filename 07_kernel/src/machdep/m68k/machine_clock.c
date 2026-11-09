/*	@(#)us_timer.c	1.0	12/8/87		(c) 1987 NeXT	*/

/* 
 * Copyright (c) 1989 NeXT, Inc.
 */

/*
 * machdep/m68k/machine_clock.c -- the m68k system clock and timer of the
 * 1997 kernel (plans 539-542, D024, D103, D118).
 *
 * Written for this project from the original m68k bytes (__text
 * [0x4091e18, 0x4092436), __const 48 B at 0x40ad8ca, __bss 24 B at
 * 0x40b55ac) with the layout of this project's machdep/i386/machine_clock.c.
 * Taken from NeXTMach mk-108.1 next/us_timer.c (https://github.com/johnsonjh/
 * NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e; notices above, its
 * lines 1 and 4): timer_set() (lines 110-119), delay() (lines 498-507) and the
 * name us_timer_int (line 226).  ns_div() is this project's m68k
 * kern/ns_timer.c ns_div (plan 468, D024).  The event counter code is the
 * m68k eventc.h inlines.  Forms fixed by the bytes: ns_div in _set_timer,
 * the word-wise copy into now and the early returns of clock_value (plans
 * 539-541).
 */
#import <mach/mach_types.h>
#import <kernserv/clock_timer.h>
#import <kernserv/ns_timer.h>
#import <sys/time.h>
#import <sys/kernel.h>
#import <machdep/m68k/eventc.h>
#import <m68k/machparam.h>
#import <m68k/cpu.h>

#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_TIMER		I(6,0,29)
#define	SCR2_TIMERIPL7	0x00008000
#define	TIMER_ENABLE	0x80
#define	TIMER_UPDATE	0x40

extern volatile u_char	*timer_csr, *timer_high, *timer_low;
extern volatile int	*scr2;
extern ns_time_t	ns_per_tick;
extern int		hardclock_ps;
extern vm_address_t	hardclock_pc;
extern struct timeval	rtc_get();
extern ns_time_t	clock_value();
void			m68k_hardclock(void);

struct mc_attributes {
	ns_time_t	max_value;
	ns_time_t	resolution;
};

static const struct mc_attributes clock_attrs[] = {
	{ 0xffffffffffffffffULL, 1000 },	/* System */
	{ 0xffffffffffffffffULL, 1000 },	/* Calendar */
};

static const struct mc_attributes timer_attrs = {
	65535000, 500000
};

static ns_time_t	calendar_offset;
static ns_time_t	hardclock_next;
static int		(*timer_intr)();
static func		timer_expire;

static inline void timer_set(t)	/* NeXTMach next/us_timer.c:110-119 */
{
	*timer_csr = 0;
	*timer_low = 0xff;
	*timer_high = t>>8;
	*timer_low = t;
	*timer_csr = (TIMER_ENABLE|TIMER_UPDATE);
	*timer_low = 0xff;
	*timer_high = 0xff;
}

static inline void
ns_div(ll, divisor, remain)	/* 07 m68k kern/ns_timer.c ns_div (plan 468, D024) */
	ns_time_t	*ll;
	unsigned int	divisor;
	unsigned int	*remain;
{
	unsigned int	*msw, *lsw;
	unsigned int	quo, rem;

	msw = &((unsigned int *)ll)[0];
	lsw = &((unsigned int *)ll)[1];

	asm("divull %2,%0:%1"
	    : "=d" (rem), "=d" (quo)
	    : "dmi" (divisor), "1" (*msw), "0" (0));
	*msw = quo;
	asm("divul %2,%0:%1"
	    : "=d" (*remain), "=d" (quo)
	    : "dmi" (divisor), "1" (*lsw), "0" (rem));
	*lsw = quo;
}

static void
us_timer_int(int arg, vm_address_t pc, int ps)
{
	(void) *timer_csr;		/* clears the interrupt */
	event_sync();
	if (timer_intr)
		(*timer_intr)(arg, pc, ps);
}

void
hardclock_init(void)
{
	hardclock_next = clock_value(System) + ns_per_tick;
	ns_abstimeout((func)m68k_hardclock, 0, hardclock_next, 1);
}

void
statclock_init(void)
{
}

void
m68k_hardclock(void)
{
	int	s;

	s = splclock();
	clock_interrupt(tick, USERMODE(hardclock_ps), BASEPRI(hardclock_ps));
	hardclock(hardclock_pc, hardclock_ps);
	splx(s);
	hardclock_next += ns_per_tick;
	while (clock_value(System) > hardclock_next)
		hardclock_next += ns_per_tick;
	ns_abstimeout((func)m68k_hardclock, 0, hardclock_next, 1);
}

void
clock_timer_init(void)
{
	int	s;

	startrtclock();
	calendar_offset = 0;
	time = rtc_get();
	calendar_offset = timeval_to_ns_time(&time) - clock_value(System);
	s = splusclock();
	if (dma_chip == 313)
		*scr2 &= ~SCR2_TIMERIPL7;
	install_scanned_intr(I_TIMER, us_timer_int, 0);
	timer_set(0xffff);
	splx(s);
}

ns_time_t
clock_value(int which)
{
	struct tsval	ts;
	ns_time_t	now;

	event_set_ts(&ts);
	((unsigned int *)&now)[0] = ts.high_val;
	((unsigned int *)&now)[1] = ts.low_val;
	now *= 1000;
	switch (which) {
	case System:
		return (now);
	case Calendar:
		now += calendar_offset;
		return (now);
	default:
		return (0);
	}
}

void
set_clock(int which, ns_time_t ns)
{
	int		s;
	struct timeval	tv;

	if (which == Calendar) {
		s = splusclock();
		calendar_offset = ns - clock_value(System);
		splx(s);
		ns_time_to_timeval(ns, &tv);
		rtc_set(&tv);
	}
}

const struct mc_attributes *
clock_attributes(int which)
{
	switch (which) {
	case System:
		return (&clock_attrs[0]);
	case Calendar:
		return (&clock_attrs[1]);
	default:
		return (0);
	}
}

const struct mc_attributes *
timer_attributes(int which)
{
	if (which == 0)
		return (&timer_attrs);
	return (0);
}

void
set_timer_expire_func(int which, func expire)
{
	timer_expire = expire;
}

void
_set_timer_expire_func(int which, int (*intr)())
{
	timer_intr = intr;
}

void
set_timer(int which, ns_time_t interval)
{
	ns_untimeout(timer_expire, 0);
	ns_timeout(timer_expire, 0, interval, 0);
}

void
_set_timer(int which, ns_time_t interval)
{
	unsigned int	rem;
	unsigned int	t;

	ns_div(&interval, 1000, &rem);
	if (which == 0) {
		t = (unsigned int)interval;
		if (t < 500)
			t = 500;
		else if (t > 0xffff)
			t = 0xffff;
		timer_set(t);
	}
}

void
clear_timer(void)
{
}

/*
 *	Delay for the specified number of microseconds.
 */
void delay(unsigned int n)	/* NeXTMach next/us_timer.c:498-507 */
{
	register int d = event_get();

	while (event_delta(d) < (n+1))
		continue;
}
