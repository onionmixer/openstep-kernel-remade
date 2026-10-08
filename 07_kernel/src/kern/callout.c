/*
 * kern/callout.c -- deferred and delayed function calls run by kernel
 * threads (plan 256).
 *
 * Written for this project from the OPENSTEP 4.2 x86 kernel object
 * [0x169124, 0x16a158) (D024).  No reference text has the callout
 * interface; Darwin 0.1 kern/thread_call.c, a later form of the same
 * module, was consulted for structure only.  The list handling is
 * fixed by the bytes and may resemble it (D027).
 */

#import <mach/mach_types.h>

#import <kern/queue.h>
#import <kern/thread.h>
#import <kern/task.h>
#import <kern/sched_prim.h>

typedef unsigned long long	callout_time_t;		/* nanoseconds */

typedef void	(*callout_func_t)(void *arg, void *entry);

typedef struct callout_entry {
	queue_chain_t		q;		/* +0x00 */
	callout_func_t		func;		/* +0x08 */
	void			*arg;		/* +0x0c argument of this call */
	void			*arg0;		/* +0x10 default argument */
	callout_time_t		deadline;	/* +0x14 */
	int			status;		/* +0x1c */
} *callout_entry_t;

#define	IDLE		0
#define	PENDING		1
#define	DELAYED		2

/* the system clock and timer (machdep/i386/machine_clock.c) */
struct callout_timer_attributes {
	callout_time_t		max_value;
	callout_time_t		resolution;
};
#define	SYSTEM_CLOCK	1
extern callout_time_t	clock_value();
extern const struct callout_timer_attributes	*timer_attributes();
extern void		set_timer();
extern void		set_timer_expire_func();


#define	internal_entry_num	64
#define	callout_thread_min	4

static struct callout_entry	internal_entry_storage[internal_entry_num];
static simple_lock_data_t	callout_lock;
static queue_head_t		internal_entry_free_queue,
				pending_entry_queue, delayed_entry_queue;
static int			pending_entry_num, active_entry_num,
				callout_thread_num;

static boolean_t		callout_initialized = FALSE;

#define qe(x)		((queue_entry_t)(x))
#define CE(x)		((callout_entry_t)(x))

static void	callout_wakeup(void);
static void	callout_thread_continue(void);
static void	callout_activate_continue(void);
static void	callout_activate_thread(void);
static void	callout_delayed_interrupt(void);
static void	callout_thread(void);

static __inline__ callout_entry_t
internal_entry_allocate(void)
{
	if (queue_empty(&internal_entry_free_queue))
		panic("internalEntryAllocate");

	return (CE(dequeue_head(&internal_entry_free_queue)));
}

static __inline__ callout_entry_t
callout_entry_release(
	callout_entry_t		entry)
{
	if (entry >= internal_entry_storage &&
	    entry < &internal_entry_storage[internal_entry_num]) {
		enqueue_tail(&internal_entry_free_queue, qe(entry));
		entry = 0;
	}

	return (entry);
}

static __inline__ void
pending_entry_enqueue(
	callout_entry_t		entry)
{
	enqueue_tail(&pending_entry_queue, qe(entry));
	pending_entry_num++;

	entry->status = PENDING;
}

static __inline__ void
pending_entry_dequeue(
	callout_entry_t		entry)
{
	remqueue(&pending_entry_queue, qe(entry));
	pending_entry_num--;

	entry->status = IDLE;
}

/*
 * Keep the delayed queue sorted by deadline; an entry goes after the
 * entries with the same deadline.
 */
static __inline__ void
delayed_entry_enqueue(
	callout_entry_t		entry)
{
	callout_entry_t		current;

	current = CE(queue_first(&delayed_entry_queue));

	for (;;) {
		if (queue_end(&delayed_entry_queue, qe(current)) ||
		    entry->deadline < current->deadline) {
			current = CE(queue_prev(qe(current)));
			break;
		}
		else if (entry->deadline == current->deadline)
			break;

		current = CE(queue_next(qe(current)));
	}

	insque(qe(entry), qe(current));

	entry->status = DELAYED;
}

static __inline__ void
delayed_entry_dequeue(
	callout_entry_t		entry)
{
	remqueue(&delayed_entry_queue, qe(entry));

	entry->status = IDLE;
}

/*
 * Run the timer until the deadline of entry, at most for the longest
 * interval the timer takes.
 */
static __inline__ void
delayed_entry_set_timer(
	callout_entry_t		entry)
{
	callout_time_t		now, interval, longest;

	now = clock_value(SYSTEM_CLOCK);
	if (entry->deadline < now)
		interval = 0;
	else {
		longest = timer_attributes(0)->max_value;
		interval = entry->deadline - now;
		if (interval > longest)
			interval = longest;
	}

	set_timer(0, interval);
}

static __inline__ boolean_t
remove_from_pending_queue(
	callout_func_t		func,
	void			*arg,
	boolean_t		remove_all)
{
	boolean_t		removed = FALSE;
	callout_entry_t		entry;

	entry = CE(queue_first(&pending_entry_queue));

	while (!queue_end(&pending_entry_queue, qe(entry))) {
		if (entry->func == func && entry->arg == arg) {
			callout_entry_t	next = CE(queue_next(qe(entry)));

			pending_entry_dequeue(entry);
			callout_entry_release(entry);

			removed = TRUE;
			if (!remove_all)
				break;

			entry = next;
		}
		else
			entry = CE(queue_next(qe(entry)));
	}

	return (!remove_all ? removed : FALSE);
}

static __inline__ boolean_t
remove_from_delayed_queue(
	callout_func_t		func,
	void			*arg,
	boolean_t		remove_all)
{
	boolean_t		removed = FALSE;
	callout_entry_t		entry;

	entry = CE(queue_first(&delayed_entry_queue));

	while (!queue_end(&delayed_entry_queue, qe(entry))) {
		if (entry->func == func && entry->arg == arg) {
			callout_entry_t	next = CE(queue_next(qe(entry)));

			delayed_entry_dequeue(entry);
			callout_entry_release(entry);

			removed = TRUE;
			if (!remove_all)
				break;

			entry = next;
		}
		else
			entry = CE(queue_next(qe(entry)));
	}

	return (!remove_all ? removed : FALSE);
}

void
calloutInitialize(void)
{
	callout_entry_t		entry;

	if (!callout_initialized) {
		simple_lock_init(&callout_lock);

		queue_init(&pending_entry_queue);
		queue_init(&delayed_entry_queue);
		queue_init(&internal_entry_free_queue);

		for (entry = internal_entry_storage;
		     entry < &internal_entry_storage[internal_entry_num];
		     entry++)
			enqueue_tail(&internal_entry_free_queue, qe(entry));

		(void) kernel_thread(kernel_task,
		    callout_activate_thread, (void *) 0);

		set_timer_expire_func(0, callout_delayed_interrupt);

		callout_initialized = TRUE;
	}
}

callout_time_t
calloutDeadlineFromInterval(
	callout_time_t		interval)
{
	return (clock_value(SYSTEM_CLOCK) + interval);
}

void
calloutDispatch(
	callout_func_t		func,
	void			*arg)
{
	callout_entry_t		entry;
	int			s;

	if (!callout_initialized)
		return;

	s = splsched();
	simple_lock(&callout_lock);

	entry = internal_entry_allocate();
	entry->func = func;
	entry->arg = arg;
	entry->arg0 = 0;
	entry->deadline = 0;

	pending_entry_enqueue(entry);

	callout_wakeup();

	splx(s);
}

void
calloutDispatchUnique(
	callout_func_t		func,
	void			*arg)
{
	callout_entry_t		entry;
	int			s;

	if (!callout_initialized)
		return;

	s = splsched();
	simple_lock(&callout_lock);

	entry = CE(queue_first(&pending_entry_queue));
	while (!queue_end(&pending_entry_queue, qe(entry))) {
		if (entry->func == func && entry->arg == arg)
			break;
		entry = CE(queue_next(qe(entry)));
	}

	if (queue_end(&pending_entry_queue, qe(entry))) {
		entry = internal_entry_allocate();
		entry->func = func;
		entry->arg = arg;
		entry->arg0 = 0;
		entry->deadline = 0;

		pending_entry_enqueue(entry);

		callout_wakeup();
	}
	else
		simple_unlock(&callout_lock);

	splx(s);
}

void
calloutDispatchDelayed(
	callout_func_t		func,
	void			*arg,
	callout_time_t		deadline)
{
	callout_entry_t		entry;
	int			s;

	if (!callout_initialized)
		return;

	s = splsched();
	simple_lock(&callout_lock);

	entry = internal_entry_allocate();
	entry->func = func;
	entry->arg = arg;
	entry->arg0 = 0;
	entry->deadline = deadline;

	delayed_entry_enqueue(entry);

	if (queue_first(&delayed_entry_queue) == qe(entry))
		delayed_entry_set_timer(entry);

	simple_unlock(&callout_lock);
	splx(s);
}

void
calloutRemove(
	callout_func_t		func,
	void			*arg)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (!remove_from_pending_queue(func, arg, FALSE))
		(void) remove_from_delayed_queue(func, arg, FALSE);

	simple_unlock(&callout_lock);
	splx(s);
}

void
calloutRemoveAll(
	callout_func_t		func,
	void			*arg)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	(void) remove_from_pending_queue(func, arg, TRUE);
	(void) remove_from_delayed_queue(func, arg, TRUE);

	simple_unlock(&callout_lock);
	splx(s);
}

callout_entry_t
calloutEntryAllocate(
	callout_func_t		func,
	void			*arg0)
{
	callout_entry_t		entry;

	entry = CE(kalloc(sizeof (struct callout_entry)));

	entry->func = func;
	entry->arg = 0;
	entry->arg0 = arg0;
	entry->deadline = 0;
	entry->status = IDLE;

	return (entry);
}

void
calloutEntryFree(
	void			*e)
{
	callout_entry_t		entry = CE(e);	/* plan 256: the handle comes in untyped */
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status != IDLE) {
		simple_unlock(&callout_lock);
		panic("calloutEntryFree");
	}

	simple_unlock(&callout_lock);
	splx(s);

	kfree((vm_offset_t) entry, sizeof (struct callout_entry));
}

void
calloutEntryDispatch(
	callout_entry_t		entry)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status == IDLE) {
		entry->arg = entry->arg0;
		entry->deadline = 0;

		pending_entry_enqueue(entry);

		callout_wakeup();
	}
	else
		simple_unlock(&callout_lock);

	splx(s);
}

void
calloutEntryDispatchWithArgument(
	callout_entry_t		entry,
	void			*arg)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status == IDLE) {
		entry->arg = arg;
		entry->deadline = 0;

		pending_entry_enqueue(entry);

		callout_wakeup();
	}
	else
		simple_unlock(&callout_lock);

	splx(s);
}

void
calloutEntryDispatchDelayed(
	callout_entry_t		entry,
	callout_time_t		deadline)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status == IDLE) {
		entry->arg = entry->arg0;
		entry->deadline = deadline;

		delayed_entry_enqueue(entry);

		if (queue_first(&delayed_entry_queue) == qe(entry))
			delayed_entry_set_timer(entry);
	}

	simple_unlock(&callout_lock);
	splx(s);
}

void
calloutEntryDispatchWithArgumentDelayed(
	callout_entry_t		entry,
	void			*arg,
	callout_time_t		deadline)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status == IDLE) {
		entry->arg = arg;
		entry->deadline = deadline;

		delayed_entry_enqueue(entry);

		if (queue_first(&delayed_entry_queue) == qe(entry))
			delayed_entry_set_timer(entry);
	}

	simple_unlock(&callout_lock);
	splx(s);
}

void
calloutEntryRemove(
	callout_entry_t		entry)
{
	int			s;

	s = splsched();
	simple_lock(&callout_lock);

	if (entry->status == PENDING) {
		pending_entry_dequeue(entry);
		callout_entry_release(entry);
	}
	else if (entry->status == DELAYED) {
		delayed_entry_dequeue(entry);
		callout_entry_release(entry);
	}

	simple_unlock(&callout_lock);
	splx(s);
}

/*
 * Called with the lock held; releases it.  Wake a callout thread, and
 * the activation thread when the calls outnumber the threads.
 */
static void
callout_wakeup(void)
{
	boolean_t		more_threads = FALSE;

	if (callout_thread_num < active_entry_num + pending_entry_num)
		more_threads = TRUE;

	simple_unlock(&callout_lock);

	thread_wakeup_one((event_t) &pending_entry_num);

	if (more_threads)
		thread_wakeup_one((event_t) &callout_thread_num);
}

static void
callout_thread_continue(void)
{
	thread_t		self = current_thread();
	callout_entry_t		entry;
	callout_func_t		func;
	void			*arg;

	(void) splsched();
	simple_lock(&callout_lock);

	while (pending_entry_num > 0) {
		entry = CE(dequeue_head(&pending_entry_queue));
		pending_entry_num--;

		func = entry->func;
		arg = entry->arg;

		entry->status = IDLE;
		entry = callout_entry_release(entry);

		active_entry_num++;

		simple_unlock(&callout_lock);
		(void) spl0();

		(*func)(arg, entry);

		(void) splsched();
		simple_lock(&callout_lock);

		active_entry_num--;
	}

	if ((callout_thread_num - active_entry_num) <= callout_thread_min) {
		assert_wait((event_t) &pending_entry_num, FALSE);
		simple_unlock(&callout_lock);

		thread_block_with_continuation(callout_thread_continue);
	}

	callout_thread_num--;

	simple_unlock(&callout_lock);
	(void) spl0();

	thread_terminate(self);
	thread_halt_self();
}

static void
callout_activate_continue(void)
{
	thread_t		self = current_thread();

	(void) splsched();
	simple_lock(&callout_lock);

	if (callout_thread_num < active_entry_num + pending_entry_num) {
		callout_thread_num++;

		simple_unlock(&callout_lock);

		(void) kernel_thread(self->task, callout_thread, (void *) 0);

		thread_block_with_continuation(callout_activate_continue);
	}

	assert_wait((event_t) &callout_thread_num, FALSE);
	simple_unlock(&callout_lock);

	thread_block_with_continuation(callout_activate_continue);
}

static void
callout_activate_thread(void)
{
	stack_privilege(current_thread());

	callout_activate_continue();
}

/*
 * Timer expiry: move the entries whose deadline has passed to the
 * pending queue and restart the timer for the next one.
 */
static void
callout_delayed_interrupt(void)
{
	callout_time_t		now = clock_value(SYSTEM_CLOCK);
	queue_head_t		expired;
	callout_entry_t		entry;
	int			s;

	queue_init(&expired);

	s = splsched();
	simple_lock(&callout_lock);

	entry = CE(queue_first(&delayed_entry_queue));
	while (!queue_end(&delayed_entry_queue, qe(entry))) {
		if (entry->deadline > now)
			break;

		delayed_entry_dequeue(entry);
		enqueue_tail(&expired, qe(entry));

		entry = CE(queue_first(&delayed_entry_queue));
	}

	if (!queue_end(&delayed_entry_queue, qe(entry)))
		delayed_entry_set_timer(entry);

	while ((entry = CE(dequeue_head(&expired))) != 0) {
		pending_entry_enqueue(entry);

		callout_wakeup();

		simple_lock(&callout_lock);
	}

	simple_unlock(&callout_lock);
	splx(s);
}

static void
callout_thread(void)
{
	stack_privilege(current_thread());

	callout_thread_continue();
}
