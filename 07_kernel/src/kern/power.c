/*
 * kern/power.c -- power management callout and kernel server side.
 *
 * plan 238 (authored, D024): written from the original OPENSTEP 4.2
 * x86 kernel object [0x160adc, 0x160e84).  The types and constants
 * come from kern/power.h; no reference function text was copied.
 */

#import <mach/mach_types.h>
#import <kern/host.h>
#import <kern/power.h>

extern void			*calloutEntryAllocate();
extern unsigned long long	calloutDeadlineFromInterval();
extern void			calloutEntryDispatchDelayed();

/* the power state the system was last put in */
static PMPowerState	system_state;

/*
 * Take one power management event and act on it; the event is
 * returned through event_p when it is not null.
 */
static PMReturn
handle_power_event(PMPowerEvent *event_p)
{
	PMPowerEvent	event;
	PMReturn	ret;

	ret = PMGetPowerEvent(&event);
	if (ret == PM_R_SUCCESS) {
		switch (event) {
		case PM_STANDBY_REQUEST:
		case PM_USER_STANDBY_REQUEST:
			system_state = PM_STANDBY;
			PMSetPowerState(PM_SYSTEM_DEVICE, PM_STANDBY);
			break;

		case PM_SUSPEND_REQUEST:
		case PM_CRITICAL_SUSPEND:
		case PM_USER_SUSPEND_REQUEST:
			system_state = PM_SUSPENDED;
			PMSetPowerState(PM_SYSTEM_DEVICE, PM_SUSPENDED);
			system_state = PM_READY;
			PMSetPowerState(PM_SYSTEM_DEVICE, PM_READY);
			break;

		case PM_NORMAL_RESUME:
		case PM_CRITICAL_RESUME:
		case PM_STANDBY_RESUME:
			if (system_state != PM_READY) {
				system_state = PM_READY;
				PMSetPowerState(PM_SYSTEM_DEVICE, PM_READY);
			}
			/* and read the clock again */
		case PM_UPDATE_TIME:
			PMUpdateClock();
			break;

		case PM_BATTERY_LOW:
		case PM_POWER_STATUS_CHANGE:
			break;
		}
		if (event_p)
			*event_p = event;
	}
	return (ret);
}

/*
 * Poll for power events about once a second (1.01 s).
 */
void
power_callout(void *arg, void *entry)
{
	(void) handle_power_event((PMPowerEvent *)0);
	if (entry == 0)
		entry = calloutEntryAllocate(power_callout, 0);
	calloutEntryDispatchDelayed(entry,
	    calloutDeadlineFromInterval(1010000000LL));
}

void
power_init()
{
	static boolean_t	initialized = FALSE;

	if (initialized == FALSE) {
		if (PMConnect() == PM_R_SUCCESS)
			power_callout(0, 0);
		system_state = PM_READY;
		initialized = TRUE;
	}
}

/*
 * Kernel server side of the power management MIG interface.
 */
kern_return_t
kern_PMSetPowerState(host_t host, PMDeviceID device, PMPowerState state)
{
	if (host != &realhost)
		return (KERN_INVALID_HOST);
	return (PMSetPowerState(device, state));
}

kern_return_t
kern_PMGetPowerEvent(host_t host, PMPowerEvent *event_p)
{
	if (host != &realhost)
		return (KERN_INVALID_HOST);
	return (handle_power_event(event_p));
}

kern_return_t
kern_PMGetPowerStatus(host_t host, PMPowerStatus *status_p)
{
	if (host != &realhost)
		return (KERN_INVALID_HOST);
	return (PMGetPowerStatus(status_p));
}

kern_return_t
kern_PMSetPowerManagement(host_t host, PMDeviceID device,
			  PMPowerManagementState state)
{
	if (host != &realhost)
		return (KERN_INVALID_HOST);
	return (PMSetPowerManagement(device, state));
}

kern_return_t
kern_PMRestoreDefaults(host_t host)
{
	if (host != &realhost)
		return (KERN_INVALID_HOST);
	return (PMRestoreDefaults());
}
