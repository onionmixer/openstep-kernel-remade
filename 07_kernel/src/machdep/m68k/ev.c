/******************************************************************************

    ev.c
    Implementation of NeXT events driver
    
    Created by Leo Hourvitz 22Dec87 from nextmouse_routines.c
    
    Copyright 1987 NeXT, Inc.
    
    Modified:

    08Mar90 jks  Force km.showcount = 0 in evmmap() to keep alert panels
		 from hanging.
    01Feb87 Leo  Only select on read, not exceptional conditions
    15Feb88 Leo  Handle bright and dim
    07Mar88 Leo  Use vertical retrace features
    14Mar88 gk   Add sound key support
    22Jul88 avie Power key support.
    22Aug88 Leo  Make power key generate Sysdefined event subType 1
    19Sep88 Leo  Mach IPC changes
    07Nov88 avie Use sizeof(EvVars) instead of PAGE_SIZE for shared mem
    23Nov88 avie Update to port set technology.
    10Dec88 Leo  Rearrange driver, add evs driver, remove most ioctls
			     from ev driver
    15Dec88 Leo  Filter events with device address 15; workaround for bug
    06Mar89 dmitch Called AllKeysUp() in case of keyboard overflow in
		 evintr()
    08Mar89 Leo  Undo autoDim in evclose if autodimmed
    18Jun89 Leo  Make new version of shmem layout available
    07Jul89 dmitch Used KB_POLL_SETUP for MON_KM_POLL command
    24Aug89 Ted  ANSI Prototyping and some formatting.
    14Nov89 Ted  Added code to turn off boot animation.
    19Feb90 Ted  Modified for multiple driver support.
    23Feb90 Ted  Fixed evclose to test evOpenCalled instead of eventsOpen.
    26Feb90 Dave Added support for `absolute' and non-scaled mouse devices.
    05Mar90 Brian Free event port on close, use kern_port_t for event port.
    05Apr90 Ted  PMON support PMON_SOURCE_EV in LLEventPost.
    22May90 Ted  Added wait cursor support in evvert() and evopen().
    26May90 Ted  Fixed bug: UndoAutoDim only for user events in LLEventPost.
    18Jun90 Ted  Call to animateWaitCursor() to fix wait cursor sustain bug.

******************************************************************************/
/*
 * plan 689 (D161, D013, D024, D104, D110, D121, D154, D158): the 1997 m68k
 * ev.c.  NeXTMach mk-108.1 nextdev/ev.c with the include lines in OPENSTEP
 * paths (the 1997 SDK bsd/dev/m68k event.h and evio.h for ev_vars.h) and
 * these changes (plan 688), from the original bytes [0x40678ce, 0x4068710):
 *	evinit		nbic_bus_enable(); I_PFAIL also goes to call_nmi
 *			unless dma_chip is 313
 *	evopen		the shared memory setup moved to evmmap; evRetryMask
 *	evclose		thread_deallocate, round_page(sharedMemSize), kfree of
 *			evScreen; evg for evp and eventGlobals
 *	evselect	thread_reference of the selecting thread
 *	evmmap		kmem_alloc_wired of totalShmemSize; EvOffsets eop,
 *			EvGlobals evg, evs; process_adb_event when an ADB
 *			keyboard is present; callout_dispatch
 *	add_queued_event, process_queued_events, power_check, myAbs and
 *	UniqueEventNum (NeXTMach ev_cursor.c)	static inline
 *	ev_m_intr, ev_k_intr	new
 *	evintr		ns_callfree
 *	evvert		evretry; the VertRetraceClock increment at the end
 *	power_intr	static; UndoAutoDim when autodimmed
 *	evMsgThreadProc	ipc_kmsg_get_from_kernel, ipc_kmsg_copyin_compat_from_
 *			kernel, ipc_mqueue_send (three arguments, as in the
 *			original: called through a cast, which avoids the
 *			four-argument prototype)
 *	evnewevents	thread_deallocate_interrupt
 *	LLEventPost	evg; dontCoalesce; pressure
 * These spellings are this project's choices (the bytes do not show them;
 * D161): the ev_vars.h names as extern declarations in this file, the static
 * name sharedMemSize, the union hw_event * arguments, extern int ns_callfree,
 * the ipc_mqueue_send cast, the kfree cast, the NeXTMach forms where the
 * bytes allow others.  eventGlobals is renamed evg (the SDK name) in
 * LLEventPost without markers.  Lines marked plan 689 differ from NeXTMach
 * (a marked BEGIN/END region as a whole).
 */

#import <sys/types.h>
#import <sys/param.h>
#import <sys/user.h>
#import <sys/ioctl.h>
#import <sys/systm.h>
#import <sys/kernel.h>
#import <sys/file.h>
#import <sys/proc.h>
#import <sys/conf.h>
#import <sys/callout.h>
#import <sys/reboot.h>
#import <kern/thread.h>
#import <kern/task.h>
/* plan 689 (D104, D110, D121, D158, D161) BEGIN: include lines in OPENSTEP paths, the next/cpu.h and ev_vars.h names */
#import <next/autoconf.h>
#import <next/clock.h>
#import <m68k/cpu.h>	/* plan 689 (D110): NeXTMach <next/cpu.h> */
/* plan 689 (D110, D161): the NeXTMach next/cpu.h names used here (km.c precedent) */
extern int slot_id;
extern volatile int *intrmask;
extern int intr_mask;
#define	SLOT_ID		slot_id
#define	P_MON		(SLOT_ID+0x0200e000)
#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_BIT(i)	( 1 << (((i) >> 8) & 0x1f))
#define	I_NMI		I(7,0,31)
#define	I_PFAIL		I(7,1,30)
#define	I_KYBD_MOUSE	I(3,10,3)
#define	I_POWER		I(3,11,2)
/* plan 689 (D121, D154): NeXTMach #import <next/scr.h> removed (no name used) */
#import <next/event_meter.h>
/* plan 689 (D121, D154): NeXTMach #import <next/xpr.h> removed (no name used) */
#import <next/kernel_pmon.h>
#import <dev/m68k/monreg.h>	/* plan 689 (D104): NeXTMach <nextdev/monreg.h> */
#import <nextdev/kmreg.h>
#import <dev/m68k/video.h>	/* plan 689 (D104): NeXTMach <nextdev/video.h> */
#import <nextdev/td.h>
#import <nextdev/dma.h>
#import <mon/global.h>
#import <mach/vm_param.h>	/* plan 689 (D104): NeXTMach <vm/vm_param.h> */
#import <vm/vm_kern.h>
#import <bsd/dev/m68k/event.h>	/* plan 689 (D104, D158): NeXTMach <nextdev/ev_vars.h>; the 1997 SDK m68k headers */
#import <bsd/dev/m68k/evio.h>	/* plan 689 (D104, D158) */
/* plan 689 (D024, D161): the NeXTMach nextdev/ev_vars.h names ev.c uses (1997 SDK EvGlobals evg) */
extern void evintr();
extern void process_mouse_event();
extern void process_kbd_event();
extern void process_adb_event();
extern void mouse_motion();
extern void DoKbdRepeat();
extern void DoAutoDim();
extern void UndoAutoDim();
extern void evretry();
extern int ns_callfree;
#define	NULLEVENTNUM 0
#define MOVEDEVENTMASK \
	(NX_MOUSEMOVEDMASK | NX_LMOUSEDRAGGEDMASK | NX_RMOUSEDRAGGEDMASK )
#define COALESCEEVENTMASK \
	(MOVEDEVENTMASK | NX_MOUSEEXITEDMASK)
#define MOUSEEVENTMASK \
	(NX_LMOUSEDOWNMASK|NX_RMOUSEDOWNMASK|NX_LMOUSEUPMASK|NX_RMOUSEUPMASK)
#define PRESSUREEVENTMASK \
	(NX_LMOUSEDOWNMASK|NX_LMOUSEUPMASK|NX_MOUSEMOVEDMASK|NX_LMOUSEDRAGGEDMASK)
#define FORCEMOUSEMOVED		16
#define FORCEMOUSEMOVEDMASK	(1 << FORCEMOUSEMOVED)
extern EvOffsets *eop;
extern EvGlobals *evg;
extern void *evs;
extern EvScreen *evScreen;
extern int evScreenSize;
extern int screens;
extern int totalShmemSize;
extern int evRetryMask;
extern int evOpenCalled;
extern int eventsOpen;
extern short waitSustain;
extern short waitSusTime;
extern short waitFrameRate;
extern short waitFrameTime;
extern port_t eventPort;
extern task_t eventTask;
struct _eventMsg {
    msg_header_t h;
    msg_type_t   t;
};
extern struct _eventMsg eventMsg;
#define EventsInQueue() \
	(eventsOpen && (evg->LLEHead != evg->LLETail))
extern short leftENum;
extern short rightENum;
extern long clickTime;
extern Point clickLoc;
extern int clickState;
extern long clickTimeThresh;
extern Point clickSpaceThresh;
extern int mouseDelX;
extern int mouseDelY;
extern int keySema;
extern unsigned char lastPressure;
extern int	autoDimPeriod;
extern int	autoDimmed;
extern int	autoDimTime;
/* plan 689 (D161): end of the ev_vars.h names */
#import <kern/xpr.h>
#import <machine/spl.h>
#import <machine/cpu.h>	/* SCR 2 address definition. */
#import <m68k/mmu.h>	/* plan 689 (D104): NeXTMach <machine/mmu.h> */
/* plan 689 END */

union hw_event {
    int data;
    struct mouse mouse_event;
    struct keyboard keyboard_event;
};

union hw_event curEvent; /* Why shouldn't this be a local in evintr? */

/* Forward Declarations */

extern evvert();
extern void evnewevents();
extern void LLEventPost();
static void evMsgThreadProc();	/* plan 689 (D024, D161) */
extern void AllKeysUp();
static void power_intr();	/* plan 689 (D024, D161) */
/* plan 689 (D024, D161): power_check is static inline */

/* Local state */

static struct proc *evSelProcess;	/* Process blocked on us, if one */
static int needsMsg;			/* A lock used between the driver code
					   and a kernel thread running
					   evMsgThreadFunc.  */
static int sharedMemSize;	/* plan 689 (D024, D161): new in 1997 (authored name) */
static char *sharedMem;		/* The page of memory shared between driver
				   and driver client */
				/* ...and how big that memory is */
#define SHMEMSIZE (sizeof(EvOffsets)+sizeof(EvVars)+sizeof(EventGlobals))

struct _eventMsg eventMsg	/* Message to send to client */
	= { { 0, 1, sizeof(msg_header_t)+sizeof(msg_type_t), 
	      MSG_TYPE_NORMAL, (port_t)0, (port_t)0, 0 },
	    { MSG_TYPE_UNSTRUCTURED, 0, 0, 1, 0, 0 } };

#define MAXQUEUEDEVENTS 5

/* Sometimes we have to hold off on processing events 
 * because the semaphore governing their particular variables 
 * is set.  If so, we queue them up in these arrays and look to
 * see if these have events in them during future vertical retraces.
 */

typedef struct _preQueued {
    int numQueued;		/* Number of unprocessed events */
    int *queueFlag;		/* Flag that must be 0 to process them */
    void (*queueFunc)();	/* Function to call to process them */
    union hw_event queuedUp[MAXQUEUEDEVENTS];
} PreQueued;

static PreQueued kbdQueued;
static PreQueued mouseQueued;
static int lleqSize;	/* number of entries in low-level queue */

/* Device vector routines for ev driver */

void evinit()
{
    extern int call_nmi();
/* plan 689 (D024, D161) BEGIN: evinit, from the original bytes */
    register int i;

    nbic_bus_enable();	/* plan 689 (D024, D161): NeXTMach *scr2 |= 0x80 */
    /* for now, hardwire one keyboard and mouse */
    /* FIXME: t/o and switch to SCC */
    km_send (MON_KM_USRREQ, KM_SET_ADRS(0));
    km_send (MON_KM_USRREQ, KM_SET_LEDS(0, 0));
    mon_send (MON_KM_POLL, KB_POLL_SETUP);

    /* enable interrupts */
    install_scanned_intr(I_POWER, (func)power_intr, 0); /*before retrace!*/
    install_scanned_intr(I_NMI, call_nmi, 0);
    if (dma_chip != 313)	/* plan 689 (D024, D161) */
	install_scanned_intr(I_PFAIL, call_nmi, 0);	/* plan 689 (D024, D161) */
    install_scanned_intr(I_KYBD_MOUSE, (func)evintr, 0);
/* plan 689 END */
}

/******************************************************************************
    evopen
    
    Opens the ev driver.  This routine allocates the shared memory to be
    used between itself and the WindowServer.
******************************************************************************/

int evopen(dev_t dev, int flag)
{
    /* plan 689 (D024, D161): EvOffsets *eop is global */
    extern struct km km;
    extern int keySema;
    static int evInitialized;
    extern struct mon_global *mon_global;	/* Turn off boot anim */
    struct mon_global *mg = mon_global;		/* Turn off boot anim */

    /* TURN OFF BOOT ANIMATION */
    *MG(char*, MG_flags) &= ~MGF_ANIM_RUN;

    /* Can't do this with pseudo-inits because it's needed before then. */
    if ((km.flags & KMF_INIT) == 0)
	kminit();	/* km.c: init keyboard/mouse device hardware  */

    /* This only needs to be done once. */
    if (!evInitialized) {
	evInitialized = 1;
	kernel_thread(kernel_task, evMsgThreadProc);
    }
    /* We can only be opened once */
/* plan 689 (D024, D161) BEGIN: evopen tail, from the original bytes */
    if (evOpenCalled)
	return(EBUSY);
    /* plan 689 (D024, D161): shared memory and 2.0 structures moved to evmmap */
    km.flags &= ~KMF_SEE_MSGS;
    km.save = 0;	
    km.showcount = 0;
    evSelProcess = NULL;
    eventPort = PORT_NULL;	/* plan 689 (D024, D161) */
    evOpenCalled = 1;	/* Driver now marked as open */
    evRetryMask = 0;	/* plan 689 (D024, D161) */
    return(0);		/* Successful open call */
/* plan 689 END */
}

/* plan 689 (D024, D161) BEGIN: evclose, from the original bytes */
int evclose(dev_t dev, int flag)
{
    if (!evOpenCalled)
	return(ENXIO);	/* Then how'd we get here? */
    evOpenCalled = 0;
    eventsOpen = 0;
    if (autoDimmed)
	UndoAutoDim();
    if (evSelProcess)	/* plan 689 (D024, D161) */
	thread_deallocate(evSelProcess);
    evSelProcess = NULL;
    TermMouse();
    if (sharedMem)
	kmem_free(kernel_map, sharedMem, round_page(sharedMemSize));	/* plan 689 (D024, D161) */
    if (evScreen)	/* plan 689 (D024, D161) */
	kfree((vm_offset_t)evScreen, evScreenSize);	/* plan 689 (D161) */
    screens = 0;	/* plan 689 (D024, D161) */
    evScreen = NULL;
    evScreenSize = 0;
    evg = NULL;	/* plan 689 (D024, D161) */
    sharedMem = NULL;
    eventTask = 0;
    if (eventPort != PORT_NULL) {	/* plan 689 (D024, D161) */
	port_release(eventPort);
	eventPort = PORT_NULL;
    }
    /* kmioctl (0, KMIOCPOPUP, mach_title, POPUP_NOM, 0, 0); */
    return(0);
}
/* plan 689 END */

/* plan 689 (D024, D161) BEGIN: evselect, from the original bytes */
int evselect(dev_t dev, int flag)
{
    int s;

    XPR(XPR_EVENT, ("evselect: thread 0x%x\n", current_thread()));
    if (flag == FREAD) {
	if (evg->LLEHead != evg->LLETail) {	/* plan 689 (D024, D161) */
	    XPR(XPR_EVENT, ("evselect: head != tail\n"));
	    return(1);
	}
	s = splhigh();
	if (evSelProcess) {
	    if (evSelProcess != (struct proc *)current_thread()) {
		splx(s);
		printf("Double select!\n");
		return(-1);
	    }
	}
	else {
	    evSelProcess = (struct proc *)current_thread();
	    thread_reference(current_thread());	/* plan 689 (D024, D161) */
	}
	splx(s);
    }
    return(0);
}
/* plan 689 END */

/* plan 689 (D024, D161) BEGIN: evmmap, from the original bytes (the shared memory setup moved here from evopen) */
int evmmap(dev_t dev, int off, int prot)
{
    /* plan 689 (D024, D161): NeXTMach static int returnValue removed */
    if (eventsOpen)
	return atop(pmap_resident_extract(pmap_kernel(), sharedMem+off));

    sharedMemSize = totalShmemSize;	/* plan 689 (D024, D161) */
    if (off >= round_page(totalShmemSize))	/* plan 689 (D024, D161) */
	return(-1);

    /* Now allocate shared memory. */	/* plan 689 (D024, D161): moved from evopen */
    if (kmem_alloc_wired(kernel_map, &sharedMem, round_page(totalShmemSize))
	!= KERN_SUCCESS)
	panic("ev: No space for shmem!\n");

    eop = (EvOffsets *) sharedMem;	/* plan 689 (D024, D161) */
    eop->evGlobalsOffset = sizeof(EvOffsets);
    eop->evShmemOffset = eop->evGlobalsOffset + sizeof(EvGlobals);
    evg = (EvGlobals *)((char *)eop + eop->evGlobalsOffset);
    evs = (void *)((char *)eop + eop->evShmemOffset);
    evg->waitCursorEnabled = TRUE;
    evg->globalWaitCursorEnabled = TRUE;
    /* Set wait cursor defaults */
    evg->waitThreshold = DefaultWCThreshold;
    waitFrameRate = DefaultWCFrameRate;
    waitSustain = DefaultWCSustain;	
    waitSusTime = 0;

    lleqSize = LLEQSIZE;
    mouseQueued.queueFlag = (int *) &evg->cursorSema;
    mouseQueued.queueFunc = process_mouse_event;
    kbdQueued.queueFlag = (int *) &keySema;
    if (adb_keybd_present())	/* plan 689 (D024, D161) */
	kbdQueued.queueFunc = process_adb_event;
    else
	kbdQueued.queueFunc = process_kbd_event;

    /* Get those events coming through! */
    InitMouse(lleqSize);
    
    /* Get ready fer them key events */
    InitKbd(0);
    
    /* Set eventsOpen last to avoid race conditions (all the interrupt-based
     * stuff doesn't run unless eventsOpen is nonzero).
     */
    eventsOpen = 1;
    
    /* Start vbl interrupts */
    callout_dispatch(CALLOUT_PRI_RETRACE, evvert, 0);	/* plan 689 (D024, D161) */
    eventTask = current_task();

    /* OK, remember the value we're returning this time */
    return atop(pmap_resident_extract(pmap_kernel(), sharedMem+off));
}
/* plan 689 END */

/*
void set_new_ev_structs() {}
*/

/* plan 689 (D024, D161) BEGIN: static inline queue helpers and power_check (NeXTMach 308-336, 527-546); new ev_m_intr, ev_k_intr */
static inline void add_queued_event(PreQueued *preQueue)	/* plan 689 (D024, D161) */
{
    if (preQueue->numQueued < MAXQUEUEDEVENTS) {
	preQueue->queuedUp[preQueue->numQueued] = curEvent;
	preQueue->numQueued++;
    }
    else {
	/* Yow!  What can we do??? */ ;
#if PMON
	/* tcohn: Well, let's tell the PMON server, that's what! */
	pmon_log_event( PMON_SOURCE_EV,
			KP_EV_PREQUEUE_FULL,
			(preQueue == &mouseQueued) ? 0 : 1,
			curEvent.data,
			0);
#endif
    }
}

static inline void process_queued_events(PreQueued *preQueue)	/* plan 689 (D024, D161) */
{
    if (preQueue->numQueued&&(!*preQueue->queueFlag)) {
	int i;

	for (i=0; i<preQueue->numQueued; i++)
	    (*preQueue->queueFunc)(&preQueue->queuedUp[i]);
	preQueue->numQueued = 0;
    }
}

static inline void power_check()	/* plan 689 (D024, D161): NeXTMach 527-546, moved before evintr */
{
    extern volatile int	*intrstat;
    int bit;

    /*
     * Detect power key up motion.
     */
    bit = I_BIT(I_POWER);
    if ((intr_mask & bit) == 0) {
	/* Disabled ... means that we detected power key down */
	if ((*intrstat & bit))
	    return;	/* key still down */
	/*
	 * Reenable interrupt.
	 */
	*intrmask |= bit;
	intr_mask |= bit;
    }
}

void ev_m_intr(union hw_event *ev)	/* plan 689 (D024, D161): new in 1997 */
{
    if (eventsOpen) {
	int wereEvents;

	curEvent = *ev;
	wereEvents = EventsInQueue();
	add_queued_event(&mouseQueued);
	process_queued_events(&mouseQueued);
	if ((!wereEvents)&&EventsInQueue())
	    evnewevents();
    }
}

void ev_k_intr(union hw_event *ev)	/* plan 689 (D024, D161): new in 1997 */
{
    if (eventsOpen) {
	int wereEvents;

	curEvent = *ev;
	wereEvents = EventsInQueue();
	add_queued_event(&kbdQueued);
	process_queued_events(&kbdQueued);
	if ((!wereEvents)&&EventsInQueue())
	    evnewevents();
    } else		/* Revert to console driver */
	kmintr_process(ev);
}
/* plan 689 END */

void evintr()
{
    register volatile struct monitor *mon = (volatile struct monitor*) P_MON;
    register int dev;
    struct mon_status csr;
    extern int sound_active, reconnect, recon_poll, reconpoll();

    csr = mon->mon_csr;
    curEvent.data = mon->mon_km_data;	/* clears interrupt */

    /* reenable keyboard if it is not responding */
    if ((curEvent.data & MON_NO_RESP) &&
	(curEvent.data & MON_MASTER) == 0 && !sound_active && reconnect) {
	    km_send (MON_KM_USRREQ, KM_SET_ADRS(0));
	    return;
    }

    dev = MON_DEV_ADRS (curEvent.data);
    if (csr.km_ovr) {
	mon->mon_csr.km_ovr = 1;	/* clear it */
	XPR(XPR_EVENT, ("evintr(B): keyboard overrun"));
	AllKeysUp();	/* ensure auto-repeating keys are shut off */
	return;
    }
    XPR(XPR_EVENT, ("evintr(B): dev = 0x%x  data = 0x%x\n",
	 dev,curEvent.data));
    if (csr.km_dav == 0) {
	printf ("0x%x spurious keyboard/mouse interrupt\n", csr);
	return;
    }
    /* Here, we filter events with a device of 15.  This is a 
     * workaround for the fact that we seem to get such events
     * immediately following a transmission to the keyboard
     * LEDs.  FIX!!! We should not be getting these 'events'
     * in the first place.  [Leo 15Dec88]
     */
    
    /* With the fastest possible keyboard scanning rate (used in 1.0.58 and
     * beyond), this hardware failure appears as a No Response Error.
     * [dpm 07/20/89]
     */
    if ((dev == 0xf) || (curEvent.data & MON_NO_RESP))
	return;
    if (dev & 1) {	/* odd device addresses are mice */
	if (eventsOpen) {
	    int wereEvents;
	    
	    wereEvents = EventsInQueue();
	    add_queued_event(&mouseQueued);
	    process_queued_events(&mouseQueued);
	    if ((!wereEvents)&&EventsInQueue())
		evnewevents();
	}
    } else if (eventsOpen) {	/* then to the event queue with it */
	int wereEvents;
    
	wereEvents = EventsInQueue();
#if EVENTMETER
	/* Check for event meter keys */
	if ((curEvent.keyboard_event.up_down == KM_DOWN) &&
	curEvent.keyboard_event.command_left &&
	curEvent.keyboard_event.command_right)
	if (curEvent.keyboard_event.key_code == UP_ARROW_KEY) {
	    event_run(EM_KEY_UP, eventGlobals->eventFlags&NX_SHIFTMASK);
	    return;
	} else if (curEvent.keyboard_event.key_code == DOWN_ARROW_KEY) {
	    event_run(EM_KEY_DOWN);
	    return;
	} 
#endif EVENTMETER
	/* check for key event during alert popups */
	if ((curEvent.keyboard_event.up_down == KM_DOWN)
	&& (km.flags & KMF_ALERT_KEY)) {
	    alert_key = kybd_process(&curEvent.keyboard_event);
	    return;
	}
	add_queued_event(&kbdQueued);
	process_queued_events(&kbdQueued);
	if ((!wereEvents)&&EventsInQueue())
	    evnewevents();
    } else {		/* Revert to console driver */
	kmintr_process(&curEvent.keyboard_event);
	power_check();	/* better place to do this? */
    }

    if (!recon_poll && reconnect && ns_callfree) {	/* plan 689 (D024, D161) */
	timeout (reconpoll, 0, hz*3);
	recon_poll = 1;
    }
    XPR(XPR_EVENT, ("evintr(B): exit"));
}

/* plan 689 (D024, D161) BEGIN: evvert, from the original bytes */
int evvert()
{
    int wereEvents;
    
    if (eventsOpen) {
    	wereEvents = EventsInQueue();
	/* Generate any repeat-key events */
	DoKbdRepeat(); 
	/* Move cursor for accumulated mouse motion */
	if ((mouseDelX || mouseDelY)	/* plan 689 (D024, D161) */
	|| (evg->movedMask & FORCEMOUSEMOVEDMASK))
	    mouse_motion();
	/* Check for leftover pre-queued events */
	if (mouseQueued.numQueued)
	    process_queued_events(&mouseQueued);
	if (kbdQueued.numQueued)
	    process_queued_events(&kbdQueued);
	/* If we put events in the queue this time, let waiters know */
	if ((!wereEvents) && EventsInQueue())
	    evnewevents();
	/* WAITCURSOR ACTION */
	if (waitSusTime) --waitSusTime; /* Do this every tick regardless */
	if (!evg->waitCursorSema && !evg->cursorSema)	/* plan 689 (D024, D161) */
	{
	    if ((evg->AALastEventSent != evg->AALastEventConsumed) &&
	    ((evg->VertRetraceClock - evg->AALastEventSent >
	    evg->waitThreshold)))
		evg->ctxtTimedOut = TRUE;
	    if (evg->waitCursorEnabled && evg->globalWaitCursorEnabled &&
	    evg->ctxtTimedOut)
	    {
		/* WAIT CURSOR SHOULD BE ON */
		if (!evg->waitCursorUp)
		    (void)ShowWaitCursor();	/* plan 689 (D024, D161) */
	    } else {
		/* WAIT CURSOR SHOULD BE OFF */
		if (evg->waitCursorUp && (waitSusTime == 0))
		    (void)HideWaitCursor();	/* plan 689 (D024, D161) */
	    }
	    /* Animate cursor */
	    if (evg->waitCursorUp)
	    if (--waitFrameTime == 0)
		    (void)AnimateWaitCursor();	/* plan 689 (D024, D161) */
	}
	power_check();
	if ((evg->VertRetraceClock > autoDimTime) && (!autoDimmed))
	    DoAutoDim();
	if (evRetryMask)	/* plan 689 (D024, D161) */
	    evretry();
    	/* Increment event time stamp */	/* plan 689 (D024, D161): moved from the head */
	if (!++evg->VertRetraceClock)
	    evg->VertRetraceClock++; /* skip 0 */
    }
    return(eventsOpen);
}
/* plan 689 END */

int force_power_down = 0;

/* plan 689 (D024, D161) BEGIN: power_intr, from the original bytes */
static void power_intr()	/* plan 689 (D024, D161) */
{
    extern volatile int	*intrstat;
    int bit;
    int wereEvents;

    /* The power key will continually interrupt until released (and even then,
     * after a short additional time period). So disable more interrupts.
     */
    if (!rtc_intr())
    	return;
    bit = I_BIT(I_POWER);
    *intrmask &= ~bit;
    intr_mask &= ~bit;
    if (force_power_down)
	rtc_power_down();
    if (autoDimmed)	/* plan 689 (D024, D161) */
	UndoAutoDim();	/* plan 689 (D024, D161) */
    if (eventsOpen) {
	NXEventData powerData;
	static Point powerPoint = { 0, 0 };

#define HARD_OFF_MASK (NX_NEXTLCMDKEYMASK|NX_NEXTLALTKEYMASK)

	if ((evg->eventFlags & HARD_OFF_MASK) == HARD_OFF_MASK) {	/* plan 689 (D024, D161) */
	    /*
	     * Immediate power down
	     */
	    rtc_power_down();
	}
	wereEvents = EventsInQueue();
	powerData.compound.subType = 1;
	LLEventPost(NX_SYSDEFINED,powerPoint,&powerData);
	if ((!wereEvents) && EventsInQueue())
	    evnewevents();
	/*
	 * Vertical retrace will reenable interrupts.
	 */
    } else {
	km_power_down();
    }
}
/* plan 689 END */

/* plan 689 (D024, D161): power_check is static inline before evintr */

/* plan 689 (D024, D161) BEGIN: evMsgThreadProc, from the original bytes */
static void evMsgThreadProc()
{
    int	s;

    /* plan 689 (D024, D161): NeXTMach (current_thread())->ipc_kernel = TRUE removed */
    s = splhigh();	/* could possibly be lower */
    while (1) {
	if (!needsMsg) {
	    assert_wait(&eventMsg, TRUE);
	    (void) splx(s);
	    thread_block();
	    s = splhigh();
	}
	needsMsg = 0;
	if (eventsOpen) {
	    ipc_kmsg_t	new_kmsg;	/* plan 689 (D024, D161) */
	    mach_msg_return_t	r;	/* plan 689 (D024, D161) */

	    r = ipc_kmsg_get_from_kernel((mach_msg_header_t *) &eventMsg,	/* plan 689 (D024, D161) */
		eventMsg.h.msg_size, 0, &new_kmsg);
	    if (r == MACH_MSG_SUCCESS) {	/* plan 689 (D024, D161) */
		ipc_kmsg_copyin_compat_from_kernel(new_kmsg);
		r = ((mach_msg_return_t (*)()) ipc_mqueue_send)(new_kmsg, 0, 0);
	    }
	    if (r != MACH_MSG_SUCCESS)	/* plan 689 (D024, D161) */
		printf("evMsgThreadProc: msg to window server fails (%d)", r);
	}
    }
}
/* plan 689 END */

/* plan 689 (D024, D161) BEGIN: evnewevents, from the original bytes */
void evnewevents()
{
    if (evSelProcess) {	/* Wakeup our sleeper */
	selwakeup(evSelProcess, 0);
	thread_deallocate_interrupt(evSelProcess);	/* plan 689 (D024, D161) */
	evSelProcess = NULL;
    }
    if (eventPort) {
    	needsMsg = 1;
	thread_wakeup(&eventMsg);
	/* evp->pendingMsg = 1; */
    }
}
/* plan 689 END */

/* plan 689 (D024, D161) BEGIN: static inline myAbs; UniqueEventNum from NeXTMach ev_cursor.c:35-40 */
static inline int myAbs(int a) { return(a > 0 ? a : -a); }	/* plan 689 (D024, D161) */

static inline short UniqueEventNum()	/* plan 689 (D024, D161): NeXTMach ev_cursor.c:35-40 */
{
    while (++evg->eNum == NULLEVENTNUM)
	; /* sic */
    return(evg->eNum);
}
/* plan 689 END */

/* LLEventPost 
 *
 * This routine actually places events in the event queue which is in
 * the EventGlobals structure.  It is called from all parts of the ev
 * driver.
 */

void LLEventPost(int what, Point location, NXEventData *myData)
{
    int	theClock = evg->VertRetraceClock;
    NXEQElement *theHead = (NXEQElement *)
	&evg->lleq[evg->LLEHead];
    NXEQElement *theLast = (NXEQElement *)
	&evg->lleq[evg->LLELast];
    NXEQElement *theTail = (NXEQElement *)
	&evg->lleq[evg->LLETail];

    /* Some events affect screen dimming */
    if (EventCodeMask(what) & NX_UNDIMMASK) {
    	if (autoDimmed)
	    UndoAutoDim();
    	else
    	    autoDimTime = theClock + autoDimPeriod;
    }
    if ((!evg->dontCoalesce)	/* plan 689 (D024, D161) */
    && (theHead != theTail)	/* plan 689 (D024, D161) */
    && (!theLast->sema)
    && (theLast->event.type == what)
    && (EventCodeMask(what) & COALESCEEVENTMASK)) {
    /* coalesce events */
	theLast->event.location.x = location.x;
	theLast->event.location.y = location.y;
	theLast->event.time = theClock;
	if (myData != NULL)	/* dspring 22Mar90 */
	    theLast->event.data = *myData;
    } else if (theTail->next != evg->LLEHead) {
	/* store event in tail */
	theTail->event.type = what;
	theTail->event.location.x = location.x;
	theTail->event.location.y = location.y;
	theTail->event.flags = evg->eventFlags;
	theTail->event.time = theClock;
	theTail->event.window = 0;
	if (myData != NULL)
	    theTail->event.data = *myData;
	switch(what) {
	case NX_LMOUSEDOWN:
	    theTail->event.data.mouse.eventNum =
		leftENum = UniqueEventNum();
	    break;
	case NX_RMOUSEDOWN:
	    theTail->event.data.mouse.eventNum =
		rightENum = UniqueEventNum();
	    break;
	case NX_LMOUSEUP:
	    theTail->event.data.mouse.eventNum = leftENum;
	    leftENum = NULLEVENTNUM;
	    break;
	case NX_RMOUSEUP:
	    theTail->event.data.mouse.eventNum = rightENum;
	    rightENum = NULLEVENTNUM;
	    break;
	}
	if (EventCodeMask(what) & PRESSUREEVENTMASK) {	/* plan 689 (D024, D161) */
	    theTail->event.data.mouse.pressure = lastPressure;	/* plan 689 (D024, D161) */
	}	/* plan 689 (D024, D161) */
	if (EventCodeMask(what) & MOUSEEVENTMASK) { /* Click state */
	    if (((theClock - clickTime) <= clickTimeThresh)
	    && (myAbs(location.x - clickLoc.x) <= clickSpaceThresh.x)
	    && (myAbs(location.y - clickLoc.y) <= clickSpaceThresh.y)) {
		theTail->event.data.mouse.click = 
		    ((what == NX_LMOUSEDOWN)||(what == NX_RMOUSEDOWN)) ?
		    (clickTime=theClock,++clickState) : clickState ;
	    } else if ((what == NX_LMOUSEDOWN)||(what == NX_RMOUSEDOWN)) {
		clickLoc = location;
		clickTime = theClock;
		clickState = 1;
		theTail->event.data.mouse.click = clickState;
	    } else
		theTail->event.data.mouse.click = 0;
	}
#if PMON
	pmon_log_event(PMON_SOURCE_EV,
		       KP_EV_POST_EVENT,
		       what,
		       evg->eventFlags,
		       theClock);
#endif
	evg->LLETail = theTail->next;
	evg->LLELast = theLast->next;
    }
 /*
  * if queue is full, ignore event, too hard to take care of all cases 
  */
#if PMON
    else
	pmon_log_event( PMON_SOURCE_EV,
			KP_EV_QUEUE_FULL,
			what,
			evg->eventFlags,
			theClock);
#endif
}










#import "ev_vars.h"	/* plan 779 (D178): ev variables written to match the original bytes (D024, plan 778.15) */
