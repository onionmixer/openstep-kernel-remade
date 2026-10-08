/*
 * machdep/i386/machine_clock.c -- the i386 system clock and timer
 * (8254 counter 0).
 *
 * plans 240, 386, 389, 390 (authored, D024): written from the original
 * OPENSTEP 4.2 x86 kernel bytes (__text [0x187844, 0x187fe9),
 * __const [0x1d14a0, 0x1d14dc), __data [0x1e17f8, 0x1e1841)).  No
 * reference function text was copied.
 */

#import <mach/mach_types.h>
#import <kernserv/clock_timer.h>
#import <kernserv/ns_timer.h>
#import <sys/time.h>
#import <machdep/i386/io_inline.h>
#import <machdep/i386/timer.h>
#import <machdep/i386/timer_inline.h>
#import <machdep/i386/intr_exported.h>
#import <machdep/i386/thread.h>

#define	MC_NSEC_PER_TICK	10000000	/* 100 Hz */
#define	CLKNUM		1193167		/* 8254 input clock, Hz */

extern int			tick;
extern unsigned long long	time_of_boot;

/* attributes of a clock or timer (the original's 16-byte records) */
struct mc_attributes {
	ns_time_t	max_value;
	ns_time_t	resolution;
};

static const struct mc_attributes clock_attrs[] = {
	{ 0xffffffffffffffffULL, MC_NSEC_PER_TICK },	/* System */
	{ 0xffffffffffffffffULL, 1000000000 },		/* Calendar */
};

static const struct mc_attributes timer_attrs = {
	0xffffffffffffffffULL, MC_NSEC_PER_TICK
};

unsigned int	us_spin_us_const = 0x2000;

static ns_time_t	system_time;		/* at the last tick */
static unsigned short	last_count;		/* counter at the last read */
static unsigned short	reload;			/* counter reload value */
static ns_time_t	timer_deadline;
static void		(*timer_expire)();
static boolean_t	hardclock_enabled;

/* the interrupted context handed to the BSD clock code */
struct mc_frame {
	unsigned int	pc;
	unsigned int	ps;
	unsigned int	ipl;
};

static void	machine_hardclock(struct mc_frame *);
static ns_time_t	system_time_stamp(void);

void
system_timer_dispatch(int irq, thread_saved_state_t *state, int ipl)
{
	struct mc_frame	frame;
	register int	level = ipl;	/* plan 240.1: read first (variant d5) */

	system_time += MC_NSEC_PER_TICK;
	last_count = reload;
	if (state) {
		frame.pc = state->frame.eip;
		if ((state->frame.eflags & EFL_VM) == 0)
			frame.ps = state->frame.cs.rpl;
		else
			frame.ps = 3;
	} else {
		frame.pc = 0;
		frame.ps = 0;
	}
	frame.ipl = level;
	if (hardclock_enabled)
		machine_hardclock(&frame);
	if (timer_expire && timer_deadline != 0 &&
	    timer_deadline <= system_time) {
		timer_deadline = 0;
		(*timer_expire)(0, 0, 0);
	}
}

void
hardclock_init(ns_time_t ns_per_tick)
{
	hardclock_enabled = TRUE;
}

void
statclock_init(void)
{
}

static void
machine_hardclock(struct mc_frame *frame)
{
	clock_interrupt(tick, frame->ps == 3, frame->ipl == 0);
	hardclock(frame->pc, (frame->ipl << 8) | frame->ps);
}

/*
 * Scale us_spin by timing a 1-unit spin with counter 0.
 */
void
us_spin_calibrate(void)
{
	timer_ctl_reg_t	reg;
	timer_cnt_val_t	leftover;
	int		s;

	reg = (timer_ctl_reg_t){ 0 };
	reg.rw = TIMER_CTL_RW_BOTH;
	timer_set_ctl(reg);
	s = splusclock();
	timer_write(TIMER_CNT0_SEL, TIMER_COUNT_MAX);
	us_spin(1);
	timer_latch(TIMER_CNT0_SEL);
	leftover = timer_read(TIMER_CNT0_SEL);
	splx(s);
	us_spin_us_const = (CLKNUM / (int)(TIMER_COUNT_MAX - leftover)) * us_spin_us_const / 1000000;
}

static inline unsigned int
clock_timer_constant(void)
{
	ns_time_t	res;
	unsigned int	count;
	int		i;

	res = timer_attrs.resolution;
	count = CLKNUM;
	for (i = 0; res > 1; i++)
		res /= 10;
	if (res == 0)
		panic("clock_timer_constant 1");
	i = 9 - i;
	if ((unsigned)i > 5)
		panic("clock_timer_constant 2");
	while (i > 0) {
		count /= 10;
		i--;
	}
	return (count);
}

void
clock_timer_init(void)
{
	struct timeval	tv;
	timer_ctl_reg_t	reg;
	int		s;
	unsigned int	count;
	timer_cnt_val_t	c;

	intr_register_irq(0, (intr_handler_t)system_timer_dispatch, 0, 6);
	intr_enable_irq(0);
	tv.tv_usec = 0;
	readtodc(&tv);
	time_of_boot = timeval_to_ns_time(&tv);

	s = splusclock();
	reg = (timer_ctl_reg_t){ 0 };
	reg.mode = TIMER_NDIVMODE;
	reg.rw = TIMER_CTL_RW_BOTH;
	timer_set_ctl(reg);
	count = clock_timer_constant();
	if (count > 0xffff)
		panic("clock_timer_constant 3");
	/*
	 * plan 390: last_count is assigned after the counter is written;
	 * the compiler moves that store up to the copy of count (original
	 * [0x187b47, 0x187b56)).
	 */
	c = count;
	reload = c;
	timer_write(TIMER_CNT0_SEL, c);
	last_count = c;
	splx(s);
}

ns_time_t
clock_value(int which)
{
	ns_time_t	now = system_time_stamp();

	switch (which) {
	case System:
		break;
	case Calendar:
		now += time_of_boot;
		break;
	default:
		now = 0;
		break;
	}
	return (now);
}

void
set_clock(int which, ns_time_t ns)
{
	int		s;
	struct timeval	tv;

	if (which == Calendar) {
		s = splusclock();
		time_of_boot = ns - system_time;
		splx(s);
		ns_time_to_timeval(ns, &tv);
		writetodc(&tv);
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
set_timer_expire_func(int which, void (*expire)())
{
	if (timer_expire == 0)
		timer_expire = expire;
}

void
set_timer(int which, ns_time_t interval)
{
	int		s;
	ns_time_t	t;

	if (which == 0) {
		t = (interval + MC_NSEC_PER_TICK - 1) / MC_NSEC_PER_TICK *
		    MC_NSEC_PER_TICK;
		s = splusclock();
		timer_deadline = system_time + t;
		splx(s);
	}
}

/*
 * The system time now: the time of the last tick plus the part of
 * the current tick counter 0 has counted down.
 */
static ns_time_t
system_time_stamp(void)
{
	ns_time_t	delta, now;
	int		s;
	timer_cnt_val_t	last, count;

	s = splusclock();
	now = system_time;
	last = last_count;
	timer_latch(TIMER_CNT0_SEL);
	count = timer_read(TIMER_CNT0_SEL);
	last_count = count;
	splx(s);
	if (count > last)
		now += MC_NSEC_PER_TICK;
	delta = reload - count;
	delta *= 1000000000;
	return (now + delta / CLKNUM);
}

unsigned int
event_get(void)
{
	return ((unsigned int)system_time_stamp());
}
