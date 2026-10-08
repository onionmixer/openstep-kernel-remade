/*
 * driverkit/KernBusInterrupt.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernBusInterrupt.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <driverkit/KernBus.h>

@interface KernBusInterrupt : KernBusItem <KernBusInterrupt>
{
@private
    id		_attachedInterrupts;
    int		_attachedInterruptCount;
    id		_interruptLock;
    int		_suspendCount;
    id		_suspendLock;
    void	*_deviceHandler;
}

- initForResource: resource
	    item: (unsigned int)item
	withHandler: (void *)handler
	shareable: (BOOL)shareable;

@end

BOOL
KernBusInterruptDispatch(
	KernBusInterrupt	*interrupt,
	void			*state
);

void
KernBusInterruptSuspend(
	KernBusInterrupt	*interrupt
);

void
KernBusInterruptResume(
	KernBusInterrupt	*interrupt
);

#endif
