/*
 * driverkit/KernDevice.h - kernel-private header (plan 345, D030).
 *
 * Needed by the libDriver bus and display modules (plan 345) and earlier driverkit objects, whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernDevice.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <mach/mach_types.h>

#import <objc/Object.h>

/*
 * This object supports the
 * delivery of hardware device
 * interrupts via an IPC message
 * sent to a port.
 */

@interface KernDevice : Object
{
@private
    void	*_interruptPort;
    id		_interrupts;
    id		_deviceDescription;
}

- initWithDeviceDescription: deviceDescription;

- deviceDescription;

- attachInterruptPort: (port_t)interruptPort;
- detachInterruptPort;
- interrupt: (int)index;
- interrupts;

@end

@interface KernDeviceInterrupt : Object
{
@private
    id			_busInterrupt;
    id			_lock;
    void		*_handler;
    void		*_handlerArgument;
    void		*_ipcMessage;
    BOOL		_isSuspended;
}

- initWithInterruptPort: (void *)port;

- attachToBusInterrupt: busInterrupt
	    withArgument: (void *)argument;
- attachToBusInterrupt: busInterrupt
	withSpecialHandler: (void *)handler
		argument: (void *)argument
		atLevel: (int)level;
- detach;

- suspend;
- resume;

@end

/*
 * This primative is used
 * to deliver an interrupt
 * message to an IPC port
 * from an interrupt handler.
 * This routine is public API.
 */

void
IOSendInterrupt(
	void			*interrupt,
	void			*state,
	unsigned int		msgId
);

/*
 * These primatives provide the
 * ability to manipulate a device
 * interrupt from an interrupt
 * handler.  These only work
 * correctly from inside a bone-
 * fide interrupt handler.
 */

void
IOEnableInterrupt(
	void			*interrupt
);

void
IODisableInterrupt(
	void			*interrupt
);

/*
 * One of these primatives should
 * be invoked to indicate the
 * assertion of a hardware bus
 * interrupt for an attached device
 * interrupt.
 */
#if sparc
int
#else
void
#endif
KernDeviceInterruptDispatch(
	KernDeviceInterrupt	*interrupt,
	void			*state
);

void
KernDeviceInterruptDispatchShared(
	KernDeviceInterrupt	*interrupt,
	void			*state
);

#endif
