/*
 * driverkit/autoconfCommon.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/autoconfCommon.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <objc/objc.h>

#import <mach/port.h>
#import <driverkit/driverTypes.h>
#import <driverkit/IODeviceDescription.h>

/*
 * Routines to be implemented in machine-dependent layer.
 */
 
/*
 * Start up native devices (those with hard-coded configuration).
 */
void probeNativeDevices(void);

/*
 * Perform machine dependent hardware probe/config.
 */
void probeHardware(void);

/*
 * Start up all non-native direct drivers. Called after probeHardware(). 
 */
void probeDirectDevices(void);

/*
 * Passed to configureThread() from kern_IOProbeDriver().
 */
struct probeDriverArgs {
	id		waitLock;
	unsigned char	*configData;
	BOOL		rtn;
};

extern void configureThread(struct probeDriverArgs *args);

/*
 * Data to be declared in machine-dependent layer.
 */
extern char 		*indirectDevList[];	// indirect device list
extern char		*pseudoDevList[];	// pseudo device list

#endif	/* DRIVER_PRIVATE */
