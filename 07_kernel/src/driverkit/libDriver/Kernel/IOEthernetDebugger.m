/*
 * IOEthernetDebugger.m (plan 310).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/IOEthernetDebugger.m", functions and methods 0x1aace0-0x1aae9e).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/IOEthernetDebugger.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <mach/boolean.h>
#import <mach/machine/simple_lock.h>
#import	<sys/types.h>
#import	<sys/socket.h>
#import <driverkit/IOEthernet.h>
#import <driverkit/IOEthernetPrivate.h>
/* plan 310: no <kern/kdp_en_debugger.h> -- the 4.2 kernel has no kdp_register_send_receive */

#ifndef ppc
extern int spl3();
#else
extern int splbio();
#endif

static id		debuggerDevice;
#ifndef sparc /* [ */
static int		savedIpl;
#ifndef ppc
int			(*debuggerIplRoutine)() = spl3;
#else
int			(*debuggerIplRoutine)() = splbio;
#endif
static BOOL		_kernDebuggerLocked = NO;
extern simple_lock_t	_kernDebuggerLock;
#endif sparc /* ] */

void	/* plan 310: external in the original */
    en_recv_pkt(
		void		*pkt,
		unsigned int	*pkt_len,
		unsigned int	timeout);

void	/* plan 310: external in the original */
    en_send_pkt(
		void		*pkt,
		unsigned int	pkt_len);

static void
    (*recvPkt_methd)(
		id, SEL,
		void *			pkt,
		unsigned int *		pkt_len,
		unsigned int		timeout);
#define RECV_PKT_SEL		@selector(receivePacket:length:timeout:)

static void
    (*sendPkt_methd)(
		id, SEL,
		void *			pkt,
		unsigned int		pkt_len);
#define SEND_PKT_SEL		@selector(sendPacket:length:)

#ifdef sparc
static BOOL
    (*reset_method)(
		id, SEL, 
		BOOL 		enable);
#define RESET_SEL	@selector(resetAndEnable:)
#endif sparc

@implementation IOEthernet(EthernetDebugger)

- (void)registerAsDebuggerDevice
{
    if (debuggerDevice == nil) {
	/* plan 310: no kdp_register_send_receive call in the original */
    	(IMP)recvPkt_methd = [self methodFor:RECV_PKT_SEL];
	(IMP)sendPkt_methd = [self methodFor:SEND_PKT_SEL];
#ifndef  sparc
	if ((IMP)recvPkt_methd && (IMP)sendPkt_methd)
	    debuggerDevice = self;
#else
	(IMP)reset_method = [self methodFor:RESET_SEL];
	if ((IMP)recvPkt_methd && (IMP)sendPkt_methd && (IMP)reset_method)
	    debuggerDevice = self;
#endif sparc
    }
}

#ifndef sparc /* [ */
- (void)reserveDebuggerLock
{
    if (self == debuggerDevice) {
	if (_kernDebuggerLocked) {
	    IOLog("reserveDebuggerLock: already locked\n");
	    return;
	}
    	savedIpl = (*debuggerIplRoutine)();
	simple_lock(_kernDebuggerLock);
	_kernDebuggerLocked = YES;
    }
}

- (void)releaseDebuggerLock
{
    if (self == debuggerDevice) {
	if (!_kernDebuggerLocked) {
	    return;
	}
	simple_unlock(_kernDebuggerLock);
	_kernDebuggerLocked = NO;
    	splx(savedIpl);
    }
}

#endif sparc /* ] */
@end

#ifndef sparc /* [ */
void reserveDebuggerLock(id debuggerDeviceObject)
{
    if (debuggerDeviceObject == debuggerDevice) {
	if (_kernDebuggerLocked) {
	    IOLog("reserveDebuggerLock: already locked\n");
	    return;
	}
	simple_lock(_kernDebuggerLock);
	_kernDebuggerLocked = YES;
    }
}

void releaseDebuggerLock(id debuggerDeviceObject)
{
    if (debuggerDeviceObject == debuggerDevice) {
	if (!_kernDebuggerLocked) {
	    return;
	}
	simple_unlock(_kernDebuggerLock);
	_kernDebuggerLocked = NO;
    }
}

#endif sparc /* ] */

void	/* plan 310 */
en_recv_pkt(
    void		*pkt,
    unsigned int	*pkt_len,
    unsigned int	timeout
)
{
    *pkt_len = 0;
    
    if (debuggerDevice)
    	(*recvPkt_methd)(debuggerDevice, RECV_PKT_SEL, pkt, pkt_len, timeout);    
}

void	/* plan 310 */
en_send_pkt(
    void		*pkt,
    unsigned int	pkt_len
)
{
    if (debuggerDevice)
    	(*sendPkt_methd)(debuggerDevice, SEND_PKT_SEL, pkt, pkt_len);
}

#ifdef sparc 
void
en_reset(
    BOOL	enable
)
{
    if (debuggerDevice)
    	(*reset_method)(debuggerDevice, RESET_SEL, enable);    
}
#endif sparc