/*
 * PC support timeout and tick timers (plan 249).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024).
 * Darwin 0.1 machdep/i386/pc_support/PCtimers.c was consulted for
 * structure only; the original kernel uses the callout interface
 * (calloutDispatchDelayed/calloutRemove) instead of thread calls.  The
 * flag arithmetic is fixed by the bytes, so the text may resemble
 * Darwin's (D027).
 */

#import <mach/mach_types.h>

#import "PCprivate.h"

extern unsigned long long	calloutDeadlineFromInterval();
extern void			calloutDispatchDelayed();
extern void			calloutRemove();

#define	NSEC_PER_USEC	1000

static void	PCtimeoutExpired(PCcontext_t context);
static void	PCtickExpired(PCcontext_t context);

/*
 * Restart the timeout from now when the context asks for one
 * (plan 249: the callouts are queued before the expiry routines are
 * defined, so the compiler emits those routines in this order).
 */
static inline void
PCstartTimeout(
    PCcontext_t		context
)
{
    context->pendingTimers &= ~PC_CALL_TIMEOUT;

    if (context->expectedTimers & PC_CALL_TIMEOUT)
	calloutRemove(PCtimeoutExpired, context);

    if (context->runOptions & PC_RUN_TIMEOUT) {
	calloutDispatchDelayed(PCtimeoutExpired, context,
	    calloutDeadlineFromInterval(
		(unsigned long long)(context->timeout * NSEC_PER_USEC)));
	context->expectedTimers |= PC_CALL_TIMEOUT;
    }
    else
	context->expectedTimers &= ~PC_CALL_TIMEOUT;
}

/*
 * Callout: the timeout of a context expired.
 */
static void
PCtimeoutExpired(
    PCcontext_t		context
)
{
    if (context->expectedTimers & PC_CALL_TIMEOUT) {
	if (context->running)
	    context->pendingTimers |= PC_CALL_TIMEOUT;
	context->expectedTimers &= ~PC_CALL_TIMEOUT;
    }
}

/*
 * Deliver an expired tick and keep one running when asked for.
 */
static inline void
PCstartTick(
    PCcontext_t		context
)
{
    if (context->pendingTimers & PC_CALL_TICK) {
	context->pendingCallbacks |= PC_CALL_TICK;
	context->pendingTimers &= ~PC_CALL_TICK;
    }

    if (!(context->expectedTimers & PC_CALL_TICK) &&
	    (context->runOptions & PC_RUN_TICK)) {
	calloutDispatchDelayed(PCtickExpired, context,
	    calloutDeadlineFromInterval(
		(unsigned long long)(context->tick * NSEC_PER_USEC)));
	context->expectedTimers |= PC_CALL_TICK;
    }
}

/*
 * Callout: the tick of a context expired.
 */
static void
PCtickExpired(
    PCcontext_t		context
)
{
    if (context->expectedTimers & PC_CALL_TICK) {
	context->pendingTimers |= PC_CALL_TICK;
	context->expectedTimers &= ~PC_CALL_TICK;
    }
}

void
PCscheduleTimers(
    PCcontext_t		context
)
{
    PCstartTimeout(context);
    PCstartTick(context);
}

void
PCdeliverTimers(
    PCcontext_t		context
)
{
    context->pendingCallbacks |=
	context->pendingTimers & (PC_CALL_TIMEOUT | PC_CALL_TICK);
    context->pendingTimers &= ~(PC_CALL_TIMEOUT | PC_CALL_TICK);
}

boolean_t
PCtimersPending(
    PCcontext_t		context
)
{
    return ((context->pendingTimers & (PC_CALL_TIMEOUT | PC_CALL_TICK)) != 0);
}

void
PCcancelTimers(
    PCcontext_t		context
)
{
    calloutRemove(PCtimeoutExpired, context);
    calloutRemove(PCtickExpired, context);
}

void
PCcancelAllTimers(
    thread_t		thread
)
{
    PCshared_t		shared = threadPCShared(thread);
    int			i;

    for (i = 0; i < PCMAXCONTEXT; i++)
	PCcancelTimers(&shared->contexts[i]);
}
