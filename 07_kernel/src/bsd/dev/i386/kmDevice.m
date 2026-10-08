/*
 * kmDevice.m (plan 327).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/kmDevice.m", functions and methods 0x195758-0x196d12).
 * The text is nearly the same as Darwin 0.1
 * kernel/bsd/dev/i386/kmDevice.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <driverkit/generalFuncs.h>
#import <machkit/NXLock.h>
#import <driverkit/i386/driverTypesPrivate.h>
#import <driverkit/kernelDriver.h>
#import <bsd/sys/conf.h>
#import <bsd/sys/tty.h>
#import <bsd/sys/fcntl.h>
#import <bsd/sys/errno.h>
#import <bsd/sys/msgbuf.h>
#import <bsd/dev/i386/kmDevice.h>
#import <bsd/dev/i386/BasicConsole.h>
#import <bsd/dev/i386/kbd_entries.h>
#import <bsd/dev/kmreg_com.h>
#import <bsd/sys/reboot.h>
#import <kernserv/prototypes.h>
/*
 * plan 327: the 4.2 SDK bsd/i386/reboot.h has no RB_POWERDOWN nor RB_EJECT;
 * powerOffRequest passes 0x90000 (names and values as in Darwin 0.1
 * bsd/i386/reboot.h; defined in the file like machdep.c, plan 241).
 */
#define	RB_POWERDOWN	0x00010000	/* power down on halt */
#define	RB_EJECT	0x00080000	/* eject disks on halt */
/*
 * plan 327 (D035): no i386 <machdep/i386/kernBootStruct.h> in any reference
 * tree.  The boot loader's parameter block at physical 0x11000; only the
 * field used here, at the original's offset.
 */
typedef struct {
	char	_reserved0[0x14c];
	int	graphicsMode;		/* +0x14c: booted in graphics mode */
} KERNBOOTSTRUCT;
#define	KERNSTRUCT_ADDR	((KERNBOOTSTRUCT *) 0x11000)
#import <driverkit/IODisplay.h>
#import <driverkit/IOFrameBufferDisplay.h>
#import <driverkit/IODisplayPrivate.h>
#import <driverkit/IOConfigTable.h>
#import <bsd/dev/i386/kmWaitCursor.h>
#import <bsd/sys/proc.h>

#import <kern/assert.h>


// Title strings for the various windows
const char *mach_title = "NeXT Mach Operating System";	// plan 327: 4.2 title	// Used by km.m also
static const char *alert_title  = "Alert";

// Module Globals
static int kmUnit;	// Incremented to keep track of what unit we're on
static id display;
	// display == nil means that we do not have a display object around
	// yet. In this case we use the basicConsole. When display != nil
	// we can use it's console support mechanism to do our displaying.

// The following function pointers are used by DoAlert and DoRestore. They
// get called at interrupt level and can't execute ObjC code. To avoid doing
// so we bind the lock and unlock methods that are used and call them thru
// these pointers.
static id (*lockProc)(), (*unlockProc)();

// Used for putting up alert panels very early, before kmId is valid.
IOConsoleInfo *kmAlertConsole;

LANG_TYPE glLanguage;

#define	AllocConsole()		\
	((display == nil) ? BasicAllocateConsole() : [display allocateConsoleInfo])

/*
 * Calculate incremented index for inBuf.
 */
static inline int
inbuf_incr(int x)
{
	if(++x == INBUF_SIZE) {
		return 0;
	}
	else {
		return x;
	}
}


@implementation kmDevice

/* Probe routine for a pseudo-device driver. */
+ (BOOL)probe : deviceDescription
{
    kmDevice	*localKmId;
    KERNBOOTSTRUCT *kernbootstruct = KERNSTRUCT_ADDR;
    
    // We don't have to create an instance if alert() has been called
    // prior to autoconf and we're probing the first instance...
    if ((kmId != nil) && (kmUnit == 0))
	localKmId = kmId;
    else
	localKmId = [self new];
    
    // Proceed with initialization.
    if ([localKmId init:YES fb_mode: 
	    kernbootstruct->graphicsMode ? SCM_GRAPHIC : SCM_TEXT] == nil)
    {
	IOLog("kmDevice: continuing with bad kmDevice instance\n");
	[localKmId free];
	kmId = nil;
	return NO;
    }

    return YES;
}

+ (IODeviceStyle)deviceStyle
{
    return IO_PseudoDevice;
}

/* 
 * Can't put this in the kmDevice object because we might need it
 * before kmId is initialized.
 */
static int kmDeviceAnimationState = -1;
static simple_lock_data_t kmDeviceAnimationLock;
static int AnimationLockInitialized;

/*
 * Create a kmDevice. This should only be called once in the lifetime of 
 * the system. It can be called from kmDevice's probe:, or from km.m's
 * alert() (if alert is called before IOTask autoconf).
 */
+ new
{
	char 		name[20];
	kmDevice	*km_id;
	int i;
	
	if (!AnimationLockInitialized) {
	    simple_lock_init(&kmDeviceAnimationLock);
	    AnimationLockInitialized = 1;
	}

	km_id = [self alloc];	
	km_id->kmOpenLock = [NXLock new];
	(IMP)lockProc = [km_id->kmOpenLock methodFor:@selector(lock)];
	(IMP)unlockProc = [km_id->kmOpenLock methodFor:@selector(unlock)];
	km_id->kbId = nil;
	
	for(i=0; i<NUM_FB_DEVS; i++) {
		km_id->fbp[i] = NULL;
	}
	
	/*
	 * Global kmId is id of first kmDevice created.
	 */
	if(kmUnit == 0) {
		ASSERT(kmId == nil);
		kmId = km_id;
	}
	
	/*
	 * Special case for this one, it's hard coded - there is always 
	 * at least one of these, and it's created before autoconf.
	 */
	km_id->fbp[FB_DEV_NORMAL] = basicConsole;
	[kmId setUnit:kmUnit];
	sprintf(name, "kmDevice%d", kmUnit++);	
	[kmId setName:name];
	[kmId setDeviceKind:"kmDevice"];
	[kmId setLocation:NULL];
	return km_id;
}

/*
 * Reusable initialization method. kmOpenLock must already have been 
 * initialized. initKb enables initialiation of keyboard.
 */
- init : (BOOL)initKb
	 fb_mode : (ScreenMode)fb_mode
{
	id		rtn = self;
	
	[kmOpenLock lock];
	
	/*
	 * Init local instance variables.
	 */
	inDex = outDex 	= 0;
	blockIn 	= 0;
	alertRefCount 	= 0;
	fbMode          = fb_mode;
	simple_lock_init(&inBufLock);
	
	if(initKb) {
		/*
		 * connect to Keyboard.
		 */
		if([self initKb] == nil) {
			IOLog("kmDevice: No Keyboard Found\n");
			/* but continue anyway... */
		}
	}
	[super init];
	if(!hasRegistered) {
		[self registerDevice];
		hasRegistered = YES;
	}

	[kmOpenLock unlock];
	return rtn;
}

- initKb
// Description:	Initialize connection with PCKeyboard object
{
	IOReturn drtn;
	
	drtn = IOGetObjectForDeviceName("PCKeyboard0", &kbId);
	if(drtn) {
		IOLog("km init: Can't find PCKeyboard0 (%s)\n",
			[self stringFromReturn:drtn]);
		return nil;
	}
	
	drtn = [kbId becomeOwner:self];
	if(drtn) {
		IOLog("km init: becomeOwner failed (%s)\n",
			[self stringFromReturn:drtn]);
		return nil;
	}
	
	/*
	 * Also register to be notified if anyone else relinquishes
	 * ownership after we give it up. This allows us to take over
	 * the frame buffer and keyboard when the window server exits.
	 */
	drtn = [kbId desireOwnership:self];
	if(drtn) {
		IOLog("km init: desireOwnership failed (%s)\n",
			[self stringFromReturn:drtn]);
		return nil;
	}
	return self;
}



/*
 * Interface to bsd code.
 */
- (int)kmOpen : (int)flag
{
	int rtn = 0;
	
	[kmOpenLock lock];
	if(flag & ( O_POPUP | O_ALERT )) {
		switch(fbMode) {
		    case SCM_TEXT:
		    	/*
			 * Easy case, we already have a place to do putc()'s. 
			 * Note for SCM_TEXT case, alert text just goes to 
			 * the normal console.
			 */
			break;
		    case SCM_ALERT:
			/* plan 327: no alertRefCount++ here in 4.2 */
			break;

		    default:
			/*
			 * plan 327: the 4.2 form -- suser() without arguments
			 * (non-zero for the super-user), no O_POPUP text-mode
			 * branch, the alert window is created and initialized
			 * (saveUnder FALSE, alert_title) before entering alert
			 * mode.
			 */
		    	ASSERT(fbp[FB_DEV_ALERT] == NULL);
			if(!suser()) {
				rtn = EACCES;
				goto out;
			}
			if(fbMode == SCM_OTHER) {
				rtn = EBUSY;
				goto out;
			}
			fbp[FB_DEV_ALERT] = AllocConsole();
			if (fbp[FB_DEV_ALERT] == NULL)
				fbp[FB_DEV_ALERT] = basicConsole;
			(*fbp[FB_DEV_ALERT]->Init)(
			    fbp[FB_DEV_ALERT], SCM_ALERT, FALSE, TRUE, alert_title );
			savedFbMode = fbMode;
			fbMode = SCM_ALERT;
			alertRefCount++;
		}
	}
	
	/*
	 * km.m takes care of Unix-y tty stuff.
	 */
out:
	[kmOpenLock unlock];
	return rtn;
}

- (int)kmPutc : (int)c
{
	switch(fbMode) {
	    case SCM_TEXT:
		(*fbp[FB_DEV_NORMAL]->PutC)(fbp[FB_DEV_NORMAL], c);
		return 0;
		
	    case SCM_ALERT:
	    	ASSERT(fbp[FB_DEV_ALERT] != NULL);
		(*fbp[FB_DEV_ALERT]->PutC)(fbp[FB_DEV_ALERT], c);
		return 0;

	    default:
	    	/*
		 * No place to put this text. This is not an error.
		 */
		return 0;
	}
}

/*
 * Blocking read routine. This assumes that interrupts and threads are 
 * working, since keyboard driver will need that functionality...OK?
 */
- (int)kmGetc
{
	int c;
	
	simple_lock(&inBufLock);
	blockIn = 1;
	while(inDex == outDex) {
		/*
		 * Just wait for something to show up...
		 */
		thread_sleep((int)inBuf, &inBufLock, TRUE);
		simple_lock(&inBufLock);
	} 
	c = inBuf[outDex];
	outDex = inbuf_incr(outDex);
	blockIn = 0;
	simple_unlock(&inBufLock);
	return c;
}

/*
 * ioctl equivalents. All return an errno.
 */
 
/*
 * Client finished with alert panel. Called from ioctl and from inside the 
 * kernel via alert_done().
 */
int DoRestore(void)
{
	int rtn = 0;
	
	if (kmAlertConsole) {	// No kmDevice yet!
	    (*kmAlertConsole->Restore)(kmAlertConsole);
	    (*kmAlertConsole->Free)(kmAlertConsole);
	    kmAlertConsole = NULL;
	    return 0;
	}
	
	if (kmId == nil)
	    return 0;

	/*
	 * Have to protect with kmOpenLock since we may alter frame buffer
	 * context.
	 */
	(*lockProc)(kmId->kmOpenLock, @selector(lock));
	if(kmId->fbMode == SCM_ALERT) {
		if(kmId->alertRefCount == 0) {
			/*
			 * No can do. I'm not sure when this could 
			 * ever happen...
			 */
			rtn = EBUSY;
			goto out;
		}
		if(--kmId->alertRefCount != 0) {
		
			/*
			 * Not out of the woods yet, other user(s) of alert
			 * panel still active. 
	    		 */
			goto out;
		}
		
		/*
		 * Last user of alert/popup window.
		 */
		kmId->fbMode = kmId->savedFbMode;
		if(kmId->fbMode != SCM_ALERT) {
			rtn = (*kmId->fbp[FB_DEV_ALERT]->Restore)(
			    kmId->fbp[FB_DEV_ALERT]);
			(*kmId->fbp[FB_DEV_ALERT]->Free)(
			    kmId->fbp[FB_DEV_ALERT]);
			kmId->fbp[FB_DEV_ALERT] = NULL;
		}
		else {
			IOLog("kmDevice: Recursive SCM_ALERT in restore!\n");
		}
		goto out;
	} else {
		/*
		 * Not in alert mode, this is a nop (and it's also somewhat
		 * unexpected...).
		 */
		rtn = EINVAL;
	}
out:
	(*unlockProc)(kmId->kmOpenLock, @selector(unlock));
	return rtn;
}

- (int)restore
{
    return DoRestore();
}

- (int)drawRect : (const struct km_drawrect *)kmRect
{
	struct km_drawrect rect = *kmRect;
	int size, ret;
	
	if(fbMode == SCM_ALERT) {	/* plan 327: 4.2 test */
	    	/*
		 * No can do.
		 */
		return EBUSY;
	}
	/*
	 * Copy in user data so the console DrawRect routine
	 * doesn't have to.
	 */
	rect.x &= ~3;				// Trunc to 4 pixel bound
	rect.width = (rect.width + 3) & ~3;	// Round up to 4 pixel boundary

	size = (rect.width >> 2) * rect.height;	// size in bytes

	rect.data.bits = (unsigned char *)kalloc( size );
	if (copyin(kmRect->data.bits, rect.data.bits, size)) {
	    ret = -1;
	    goto out;
	}

	ret = (*fbp[FB_DEV_NORMAL]->DrawRect)(fbp[FB_DEV_NORMAL], &rect);

out:
	kfree( rect.data.bits, size );
	return ret;
}

- (int)eraseRect : (const struct km_drawrect *)kmRect
{
        if(fbMode == SCM_ALERT) {	/* plan 327: 4.2 test */
	    	/*
		 * No can do.
		 */
		return EBUSY;
	}
	return (*fbp[FB_DEV_NORMAL]->EraseRect)(fbp[FB_DEV_NORMAL], kmRect);
}

- (int)disableCons
{
	/*
	 * This means that tty code has detected a "console 
	 * now invalid" situation.
	 */
#if 1	/* plan 327: enabled in 4.2 */
	if(fbMode == SCM_TEXT) {
		fbMode = SCM_OTHER;
	}
#endif
	return 0;
}

extern struct msgbuf *pmsgbuf;	/* plan 327: the 4.2 name (bsd/sys/msgbuf.h) */

/*
 * Dump contents of message buffer, if buffer valid and we have a text 
 * context.
 */
- (int)dumpMsgBuf
{
	char *mp;
	
	switch(fbMode) {
	    case SCM_TEXT:
	    case SCM_ALERT:
	    	break;
	    default:
	    	return 0;
	}
	if(pmsgbuf->msg_magic != MSG_MAGIC)
		return (0);
	mp = &pmsgbuf->msg_bufc[pmsgbuf->msg_bufx];
	do {
		if(*mp) {
			if(*mp == '\n') {
				[self kmPutc:'\r'];
			}
			[self kmPutc:*mp];
		}
		if(++mp >= &pmsgbuf->msg_bufc[MSG_BSIZE]) {
			mp = pmsgbuf->msg_bufc;
		}
	} while (mp != &pmsgbuf->msg_bufc[pmsgbuf->msg_bufx]);
	return 0;
}


static void
kmDeviceDrawCursor()
{
    IOConsoleInfo *device;
    ScreenMode mode;
    
    simple_lock(&kmDeviceAnimationLock);
    if (kmId == nil) {
	KERNBOOTSTRUCT *kernbootstruct = KERNSTRUCT_ADDR;
	device = basicConsole;
	mode = kernbootstruct->graphicsMode ? SCM_GRAPHIC : SCM_TEXT;
    } else {
	device = kmId->fbp[FB_DEV_NORMAL];
	mode = kmId->fbMode;
    }

    if (kmDeviceAnimationState > 0) {
	if (mode != SCM_GRAPHIC) {
	    kmDeviceAnimationState = -kmDeviceAnimationState;
	} else {
	    if (device)
		(void)(*device->DrawRect)(device,
		    &kmDeviceWaitCursor[kmDeviceAnimationState - 1]);
	    if (++kmDeviceAnimationState > KM_DEVICE_WAITCURSOR_NSTATES)
		kmDeviceAnimationState = 1;
	    ns_timeout((func)kmDeviceDrawCursor, 0, KM_DEVICE_WAITCURSOR_DELAY, 
			    CALLOUT_PRI_THREAD);
	}
    }
    simple_unlock(&kmDeviceAnimationLock);
}

/* Called once and only once from main(),
 * before autoconf.  The reason this doesn't initialize kmId and
 * call -animationCtl: is because there is some bad interaction
 * between km and basicConsole when you bring up an alert before
 * your real console device exists.  This should be fixed.  XXX
 */
void
kmEnableAnimation(void)
{
    KERNBOOTSTRUCT *kernbootstruct = KERNSTRUCT_ADDR;

    if (!AnimationLockInitialized) {
	simple_lock_init(&kmDeviceAnimationLock);
	AnimationLockInitialized = 1;
    }
    if (kernbootstruct->graphicsMode) {
	simple_lock(&kmDeviceAnimationLock);
	kmDeviceAnimationState = 1;
	simple_unlock(&kmDeviceAnimationLock);
	kmDeviceDrawCursor();
    }
}

void
kmDisableAnimation()
{
    if (kmId != nil)
	[kmId animationCtl:KM_ANIM_STOP];
}

- (int)animationCtl : (km_anim_ctl_t)ctl
{
	int doAnimation = 0;
	int ret = 0;
	
	if (fbMode != SCM_GRAPHIC)
	    return 0;
	    
	simple_lock(&kmDeviceAnimationLock);
	switch(ctl) {
	    case KM_ANIM_STOP:
	    case KM_ANIM_SUSPEND:
		if (kmDeviceAnimationState > 0) {
		    kmDeviceAnimationState = -kmDeviceAnimationState;
		    (void)(*fbp[FB_DEV_NORMAL]->EraseRect)
			(fbp[FB_DEV_NORMAL], &kmDeviceBlankCursor);
		}
		/* plan 327: no ns_untimeout() nor STOP reset in 4.2 */
		break;
	    case KM_ANIM_RESUME:
		if (kmDeviceAnimationState < 0) {
		    kmDeviceAnimationState = -kmDeviceAnimationState;
		    doAnimation = 1;
		}
		break;
	    default:
		ret = EINVAL;
		break;
	}
	simple_unlock(&kmDeviceAnimationLock);
	if (doAnimation)
	    kmDeviceDrawCursor();
	return ret;
}

- (int)getStatus : (unsigned *)statusp
{
        unsigned status = 0;

        if(fbMode == SCM_TEXT)	/* plan 327: 4.2 test */
            status |= KMS_SEE_MSGS;

	*statusp = status;
	return 0;
}

- (int)getScreenSize : (struct ConsoleSize *)size
{
	if (fbp[FB_DEV_NORMAL] == 0)
	    return EINVAL;
	
	(*fbp[FB_DEV_NORMAL]->GetSize)(fbp[FB_DEV_NORMAL], size);
	return 0;
}

#import <bsd/dev/i386/keycodes.h>

static int ProcessKbdEvent(PCKeyboardEvent *ke)
{
    // State of the modifier keys:
    static boolean_t	control_left, control_right,
			shift_left, shift_right,
			alt_left, alt_right;
    boolean_t valid, shift, control, alt, c;

    valid = FALSE;
    switch (ke->keyCode) {
	case 0x1D:
	    control_left = (ke->goingDown);
	    ke->keyCode = 0;
	    break;

	case 0x60:
	    control_right = (ke->goingDown);
	    ke->keyCode = 0;
	    break;
	    
	case 0x2A:
	    shift_left = ke->goingDown;
	    ke->keyCode = 0;
	    break;
	    
	case 0x36:
	    shift_right = ke->goingDown;
	    ke->keyCode = 0;
	    break;
	    
	case 0x38:
	    alt_left = ke->goingDown;
	    ke->keyCode = 0;
	    break;
	    
	case 0x61:
	    alt_right = ke->goingDown;
	    ke->keyCode = 0;
	    break;
	    
	default:
	    valid = TRUE;
    }

    if (!valid)
        return inv;

    shift = shift_right || shift_left;
    control = (control_left || control_right) ? (_N_KEYCODES * 2) : 0;
    c = ascii[((ke->keyCode << 1) | shift) + control];
    alt = (alt_right || alt_left)? 0x80 : 0;

    switch (c) {
	case dim:
	case bright:
	case loud:
	case quiet:
	    break;
    
	case up:
	case down:
	    break;
    
	default:
	    c |= alt;
	    break;
    }

    if (!ke->goingDown)	// Ignore keys coming up
	return(inv);
    return(c);
}

- (void)dispatchKeyboardEvent:(PCKeyboardEvent *)event;
// Description:	Called when the keyboard object receives a new keyboard
//		Event.Don't free the event object.
{
    register int c;
	extern struct tty cons;
	
    if ((c = ProcessKbdEvent(event)) == inv)
	return;

    // Normal ASCII data. pass it up.
    if(blockIn) {
	    //
	    // We're in 'blocking input' mode; add this to 
	    // the input buffer if there is room.
	    //
	    simple_lock(&inBufLock);
	    if(inbuf_incr(inDex) == outDex) {
		    //
		    // Overflow. Oh well.
		    //
		    simple_unlock(&inBufLock);
		    return;
	    }
	    inBuf[inDex] = c;
	    inDex = inbuf_incr(inDex);
	    thread_wakeup((int)inBuf);
	    simple_unlock(&inBufLock);
    }
    else {
	    //
	    // Normal console input.
	    //
	    struct tty *tp = &cons;

	    (*linesw[tp->t_line].l_rint) (c, tp);
    }
    return;
}

/*
 * ev driver (or DPS or ...) is taking over the screen and keyboard. 
 * This should always succeed.
 */
- (IOReturn)relinquishOwnershipRequest : device
{
	if(fbp[FB_DEV_ALERT]) {
		/*
		 * We have an alert panel active; get rid of it. We don't 
		 * have to do a restore operation.
		 */
		ASSERT(fbMode == SCM_ALERT);
		(*fbp[FB_DEV_ALERT]->Free)(fbp[FB_DEV_ALERT]);
		fbp[FB_DEV_ALERT] = NULL;
		
	}
	fbMode = SCM_OTHER;
	/*
	 * FIXME - notify parent of SCM_UNINIT.
	 */
	return IO_R_SUCCESS;
}

extern short prettyShutdown;

- (void) returnToVGAMode
{
	if ([display respondsTo:@selector(revertToVGAMode)])
	{
		[display revertToVGAMode];
		// DELAY 101ms   fixme (this might not be necessary now)
		// might be useful before hitting the VGA registers
		IODelay(101000);
	}
}


/*
 * Called when ev/DPS, which has been the owner of Keyboard, relinquishes 
 * ownership. I think this means that we unconditionally go to SCM_TEXT 
 * mode...
 */

static char *k_languages[L_NUM_LANGUAGE] = {
	"English",
	"French",
	"German",
	"Spanish",
	"Italian",
	"Swedish",
	"Japanese", 
	};


- (IOReturn)canBecomeOwner : device
{
	IOReturn drtn;
	static short checkedSystemConfig = 0;
	static short preventPrettyShutdown = 0;
	
	/*
	 * Regain control of keyboard.
	 */
	if(drtn = [kbId becomeOwner:self]) {
	    IOLog("km canBecomeOwner: becomeOwner failed (%s)\n",
		    [self stringFromReturn:drtn]);
	    /*
	     * But continue, although we have no keyboard...
	     */
	}

	if (!checkedSystemConfig) {
	    IOConfigTable	*configTable;
	    const char		*val;
	    
	    checkedSystemConfig = 1;
	    configTable = [IOConfigTable newFromSystemConfig];
	    val = [configTable valueForStringKey:"Shutdown Graphics"];
	    if (val) {
		if (!strcmp(val,"No"))
		    preventPrettyShutdown = 1;
		[IOConfigTable freeString:val];
	    }

	    val = [configTable valueForStringKey:"Language"];
	    if (val) {
		int 		i;
		
		for (i=0; i<L_NUM_LANGUAGE; i++) {
		    if (!strcmp(val, k_languages[i])) {
			glLanguage = i;
			break;
		    }
		}
		[IOConfigTable freeString:val];
	    }

	    [configTable free];
	}

	if (preventPrettyShutdown)
	    prettyShutdown = 0;

	if ((display == nil) || prettyShutdown) {
	    [self returnToVGAMode];
	    fbp[FB_DEV_NORMAL] = basicConsole;
	} else {
	    fbp[FB_DEV_NORMAL] = [display allocateConsoleInfo];
	}
	
	if (prettyShutdown)
	    fbMode = SCM_GRAPHIC;
	else
	    fbMode = SCM_TEXT;
	    
	(*fbp[FB_DEV_NORMAL]->Init)(
	    fbp[FB_DEV_NORMAL], fbMode, TRUE, TRUE, mach_title);

	[self drawGraphicPanel: KM_PANEL_NS];
	
	switch(prettyShutdown) {
	case 1:
	    [self graphicPanelString: "Restarting the computer...\n"];
	    break;
	case 2:
	    [self graphicPanelString: "Please wait until it's safe\n"
				      "to turn off the computer.\n"];
	    break;
	default:
	    [self graphicPanelString: "Please wait..."];
	}
	/* plan 327: no kmDeviceAnimationState = -1 in 4.2 */
	[self animationCtl: KM_ANIM_RESUME];

	return IO_R_SUCCESS;
}


- (void)powerOffRequest
{
	char instr[100];
	
	printf("\nReally Shut down (y/n)? ");
	gets(instr, instr);
	if(instr[0] != 'y') {
		printf("...aborting shutdown\n");
	}
	else {
		boot(RB_BOOT, RB_POWERDOWN | RB_EJECT, "");
	}
}


/*
 * Kernel internal alert panel support.
 */

/*
 * plan 327: in 4.2 DoAlert() is the alert routine itself (no DoSafeAlert(),
 * saveUnder always FALSE, no alertRefCount++ when already in alert mode,
 * alert mode entered after the window is initialized).
 */
void DoAlert(const char *windowTitle, const char *msg)
{
    if (kmId == nil)
    {
	// We haven't created a kmDevice yet! We can't put up a panel or
	// call ObjC stuff.  Create an alert console.
	if (kmAlertConsole)
	    return;
	// ...unless we already have basicConsole in a text mode.
	if (basicConsoleMode == SCM_ALERT ||
	    basicConsoleMode == SCM_TEXT) {
		if (basicConsole)
		    while (*msg)
			(basicConsole->PutC)(basicConsole, *msg++);
		return;
	}
	kmAlertConsole = BasicAllocateConsole();
	if (kmAlertConsole) {
	    (*kmAlertConsole->Init)(
		kmAlertConsole, SCM_ALERT, FALSE, TRUE, windowTitle);
	    while(*msg)
		(kmAlertConsole->PutC)(kmAlertConsole, *msg++);
	}
	return;
    }

    /* 
     * Create alert panel if necessary
     */
    (*lockProc)(kmId->kmOpenLock, @selector(lock));
    switch(kmId->fbMode) {
	case SCM_TEXT:
	    /*
	     * Easy case, we already have a place to do putc()'s. 
	     * Note for SCM_TEXT case, alert text just goes to 
	     * the normal console.
	     */
	    break;

	/*
	 * FIXME - maybe do a case for SCM_UNINIT, do allow printfs
	 * via alert() very early in boot.
	 */		
	case SCM_ALERT:
	    break;

	default:
	    /*
	     * Create an alert window.
	     */
	    ASSERT(kmId->fbp[FB_DEV_ALERT] == NULL);		
	    kmId->fbp[FB_DEV_ALERT] = AllocConsole();
	    if (kmId->fbp[FB_DEV_ALERT] == NULL)
		kmId->fbp[FB_DEV_ALERT] = basicConsole;

	    (*kmId->fbp[FB_DEV_ALERT]->Init)(
		kmId->fbp[FB_DEV_ALERT], SCM_ALERT, FALSE, TRUE, windowTitle);

	    /*
	     * Jump into "alert mode". 
	     */
	    kmId->savedFbMode = kmId->fbMode;
	    kmId->fbMode = SCM_ALERT;
	    kmId->alertRefCount++;
	    break;
    }
    (*unlockProc)(kmId->kmOpenLock, @selector(unlock));
    
    /*
     * Print alert message.
     */
    {
    IOConsoleInfo *cons;
    
    if (kmId->fbMode == SCM_ALERT) cons = kmId->fbp[FB_DEV_ALERT];
    else cons = kmId->fbp[FB_DEV_NORMAL];
    while(*msg)
	(*cons->PutC)(cons, *msg++);
    }
    
    return;
}



- (void)doAlert	: (const char *)windowTitle
		   msg : (const char *)msg
{
    DoAlert(windowTitle, msg);	/* plan 327 */
}

int kmtrygetc()
{
    int c;
    PCKeyboardEvent *event;
    
    event = steal_keyboard_event();
    if (event == (PCKeyboardEvent *)0)
        return -1;
	
    c = ProcessKbdEvent(event);
    return (c == inv ? -1 : c);
}

- (void)registerDisplay:newDisplay
{
    if (display == nil)
        display = newDisplay;
}

- (void)unregisterDisplay:oldDisplay
{
    if (display == oldDisplay)
        display = nil;
}

- (IOReturn)setIntValues		: (unsigned *)parameterArray
			   forParameter : (IOParameterName)parameterName
			          count : (unsigned)count
{
	if(!strcmp(parameterName, "prettyShutdown"))
	{
		prettyShutdown = (short)(*parameterArray);
		return IO_R_SUCCESS;
	}
	else
	{ 
	/* Pass parameters we don't recognize to our superclass. */
        return [super setIntValues:parameterArray
		forParameter:parameterName count:count];
	}
}

@end

/* end of kmDevice.m */


