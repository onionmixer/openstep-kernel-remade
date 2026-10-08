/*
 * libDriver/volCheckPrivate.h - libDriver private header (plan 317, D030).
 *
 * Not in the OPENSTEP 4.2 SDK; needed by volCheck.m, whose object matches
 * the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/volCheckPrivate.h; kept as project-authored under D030, without Darwin's
 * notices (license judgement: D017).
 */

#import <driverkit/IODisk.h>
#import <driverkit/IODiskPartition.h>
#import <driverkit/volCheck.h>
#import <kernserv/insertmsg.h>
#import <kernserv/queue.h>
#ifdef	KERNEL
#import <kernserv/prototypes.h>
#else	KERNEL
#import <bsd/libc.h>
#endif	KERNEL

#undef	DRIVER_PRIVATE
#define DRIVER_PRIVATE
#import <bsd/dev/voldev.h>

/*
 * state per registered removable drive.
 */
typedef struct {
	id		diskObj;
	dev_t 		blockDev;
	dev_t		rawDev;
	int 		ejectCounter;
	BOOL	 	ejectRequestPending;
	BOOL	 	diskRequestPending;
	int		tag;
	int 		diskType;		// PR_DRIVE_FLOPPY, etc.
	queue_chain_t	link;
} volCheckEntry_t;

/*
 * Command to be queued in volCheckCmdQ.
 */
typedef enum {

	VC_REGISTER,
	VC_UNREGISTER,
	VC_REQUEST,
	VC_EJECTING,
	VC_NOTREADY,
	VC_RESPONSE,
	
} volCheckOp_t;

typedef struct {
	volCheckOp_t	op;
	id		diskObj;
	int		diskType;
	dev_t		blockDev;
	dev_t		rawDev;
	queue_chain_t	link;
} volCheckCmd_t;

/*
 * Delay in seconds between executing "eject" and requiring a "not ready"
 * state from the drive.
 */
#define VC_EJECT_DELAY		5

