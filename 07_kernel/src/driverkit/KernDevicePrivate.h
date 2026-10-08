/*
 * driverkit/KernDevicePrivate.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernDevicePrivate.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	KERNEL_PRIVATE
 
#import <mach/mach_types.h>
#import <ipc/ipc_kmsg.h>
#import <kern/thread_call_private.h>
 
#import <objc/objc.h>
				
@interface KernDevice(Private)

- (void)_detachInterruptSources;

@end

typedef struct KernDeviceInterrupt_ {
    @defs(KernDeviceInterrupt)
} KernDeviceInterrupt_;

/*
 * Information used to send an ipc
 * message from interrupt context.
 * Besides one static reference, we
 * hold an extra reference to the
 * interrupt port.  This obviates
 * the need to aquire a reference
 * at interrupt time for the in
 * transit message.
 */

typedef struct _KernDeviceInterruptMsg {
    struct ipc_kmsg		kmsg;
    ipc_port_t			iport;
    id				lock;
    struct _thread_call	callout;
    BOOL			queued	:1,	/* on message queue */
				pending	:1,	/* callout pending */
				destroy	:1,	/* destroy on release */
					:0;
} KernDeviceInterruptMsg;

void
KernDeviceInterruptMsgRelease(
	void				*msg
);

static
KernDeviceInterruptMsg *
_KernDeviceInterruptMsgCreate(
	ipc_port_t			interruptPort
);
static
void
_KernDeviceInterruptMsgDestroy(
	KernDeviceInterruptMsg		*interruptMsg
);

static
void
_KernDeviceInterruptCallout(
    	KernDeviceInterruptMsg		*interruptMsg
);

#endif
