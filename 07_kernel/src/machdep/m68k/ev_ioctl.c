/******************************************************************************
	ev_ioctl.c
	System calls for NeXT mouse driver
	
	Created by Leo Hourvitz 22Dec87 from nextmouse_routines.c
	
	Copyright 1987 NeXT, Inc.
	
	Modified:

	01Feb87 Leo  Only select on read, not exceptional conditions
	15Feb88 Leo  Handle bright and dim
	07Mar88 Leo  Use vertical retrace features
	14Mar88 gk   Add sound key support
	22Jul88 avie Power key support.
	22Aug88 Leo  Make power key generate Sysdefined event subType 1
	19Sep88 Leo  Mach IPC changes
	07Nov88 avie Use sizeof(EvVars) instead of PAGE_SIZE for shared mem
	23Nov88 avie Update to port set technology.
	12Dec88 Leo  Autodim
	15Dec88 Leo  mouseHandedness
	24Aug89 Ted  ANSI
	31Jan90 Morris	Added EVSIOCADS ioctl.
	19Feb90 Ted  Major revision for multiple driver support.
	05Mar90 Brian Fix possible port leak on multiple calls to EVIOSEP
	22May90 Ted  Added wait cursor ioctl calls to evs driver
	25Jul90 Ted  Added EVSIOLLPE (was documented but didn't exist)
	08Aug90 Ted  Added EVSIOGADT and EVIODC ioctls.

******************************************************************************/
/*
 * plan 724 (D162, D013, D024, D104, D110, D158, D161): the 1997 m68k
 * ev_ioctl.c.  NeXTMach mk-108.1 nextdev/ev_ioctl.c with the include lines in
 * OPENSTEP paths (the 1997 SDK bsd/dev/m68k event.h, evio.h and evsio.h and
 * bsd/dev/ev_keymap.h for ev_vars.h) and these changes (plan 723), from the
 * original bytes [0x4068710, 0x4068fa2):
 *	evioctl		only EVIOSSCR (evsetup_screens) before the mmap call;
 *			no EVIOSV, EVIOSC, EVIODC; EVIOSM calls MoveTheCursor;
 *			EVIOST calls StartCursor without an argument
 *	evsioctl	evg for evp; kalloc and kfree; new EVSIOPTRLLPE,
 *			EVSIOGDADT, EVSIOSADS, EVSIOSADB, EVSIOCADB, EVSIOINFO;
 *			RecordBrightness after EVSIOSB; snd_device_vol_save
 *			after EVSIOSA; descending short loops for the mouse
 *			scaling arrays
 *	evsio_defaults, evsio_info	new static functions (EVSIOINFO)
 * These spellings are this project's choices (the bytes do not show them;
 * D162): the ev_vars.h and KeyMapping definitions as an in-file block, the
 * static names evsio_info and evsio_defaults, the (vm_offset_t) casts of
 * kfree, the short descending loops, EVSIOPTRLLPE with the text of
 * EVSIOLLPE.  Lines marked plan 724 differ from NeXTMach (a marked BEGIN/END
 * region as a whole).
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
#import <sys/vm.h>
#import <sys/reboot.h>
#import <kern/thread.h>
#import <kern/task.h>
/* plan 724 (D104, D110, D158, D161, D162) BEGIN: include lines in OPENSTEP paths, the next/cpu.h and ev_vars.h names, the KeyMapping layout */
#import <kern/kalloc.h>	/* plan 724 (D024): kalloc, kfree */
#import <next/clock.h>
#import <m68k/cpu.h>	/* plan 724 (D110): NeXTMach <next/cpu.h> (mon_rev) */
#import <next/event_meter.h>
#import <kern/xpr.h>
#import <dev/m68k/monreg.h>	/* plan 724 (D104): NeXTMach <nextdev/monreg.h> */
#import <nextdev/kmreg.h>
#import <nextdev/snd_snd.h>
#import <dev/m68k/video.h>	/* plan 724 (D104): NeXTMach <nextdev/video.h> */
#import <nextdev/td.h>
#import <nextdev/dma.h>
#import <mon/global.h>
#import <mach/vm_param.h>	/* plan 724 (D104): NeXTMach <vm/vm_param.h> */
#import <vm/vm_kern.h>
#import <bsd/dev/m68k/event.h>	/* plan 724 (D104, D158): NeXTMach <nextdev/ev_vars.h>; the 1997 SDK m68k headers */
#import <bsd/dev/m68k/evio.h>
#import <bsd/dev/ev_keymap.h>	/* plan 724 (D162): NX_NUMSPECIALKEYS (SDK) */
#import <bsd/dev/m68k/evsio.h>	/* plan 724 (D158, D162): real-machine copy, 07_kernel/nextdev */
#import <machine/spl.h>

/* plan 724 (D024, D161, D162): the NeXTMach nextdev/ev_vars.h names ev_ioctl.c uses (1997 SDK EvGlobals evg) */
#define BRIGHT_MAX	0x3d
#define BRIGHT_MIN	0x00
#define NUMKEYCODES	128
#define NUMMODIFIERS	16
#define MAXKEYREPEAT		1000
#define MAXINITIALKEYREPEAT	1000
typedef struct KeyMappingStruct {
    short shorts;
    char keyBits[NUMKEYCODES];
    int maxMod;
    unsigned char *modDefs[NUMMODIFIERS];
    unsigned char *keyDefs[NUMKEYCODES];
    int numSeqs;
    unsigned char *seqDefs;
    unsigned char specialKeys[NX_NUMSPECIALKEYS];
    unsigned char *mapping;
} KeyMapping;
struct _eventMsg {
    msg_header_t h;
    msg_type_t   t;
};
extern struct _eventMsg eventMsg;
extern int eventsOpen;
extern EvGlobals *evg;
extern port_t eventPort;
extern short leftENum, rightENum;
extern int keySema;
extern short waitSustain, waitFrameRate;
extern int keyRepeat, initialKeyRepeat;
extern int curMapLen, mapNotDefault;
extern KeyMapping *curMapping;
extern long clickTimeThresh;
extern Point clickSpaceThresh;
extern int numMouseScales;
extern short mouseScaleThresholds[MAXMOUSESCALINGS], mouseScaleFactors[MAXMOUSESCALINGS];
extern int autoDimPeriod, autoDimmed, autoDimTime, dimmedBrightness, curBright;
extern int mouseHandedness, buttonsTied;
extern int evsetup_screens();
extern void MoveTheCursor(), StartCursor(), ResetMouse(), ResetKbd();
extern void RecordBrightness(), DoAutoDim(), UndoAutoDim(), SetAttenuation();
extern int SetCurBrightness();
extern unsigned char *SetKeyMapping();
extern void LLEventPost(), evnewevents();
extern int adb_system_info();
#define EventsInQueue() \
	(eventsOpen && (evg->LLEHead != evg->LLETail))
#define EVSETSEMA() evg->cursorSema = 1
#define EVCLEARSEMA() evg->cursorSema = 0
/* plan 724 (D161, D162): end of the ev_vars.h names */

static int evsio_info();	/* plan 724 (D024, D162) */
/* plan 724 END */

/******************************************************************************
 	evioctl
	This is the ioctl routine for the ev driver itself.
******************************************************************************/

/* plan 724 (D024, D162) BEGIN: evioctl, from the original bytes */
evioctl(dev_t dev, int cmd, int *datap, int flag)
{
    int wereEvents;

    /* Only EVIOSSCR is legal before the mmap call is made */
    if ((!eventsOpen) && (cmd != EVIOSSCR))	/* plan 724 (D024, D162) */
	return(ENXIO);
    wereEvents = EventsInQueue();

    switch(cmd) {
    case EVIOSSCR:	/* plan 724 (D024, D162): set up screens */
	(void)evsetup_screens(datap);
	break;
    case EVIOSEP:	/* Set event port */
	if (object_copyin(current_task(), * (port_t *) datap, MSG_TYPE_PORT,
			  FALSE, datap)) {	/* plan 724 (D024, D162) */
		if (eventPort != PORT_NULL)
			port_release(eventPort);
		eventPort = * (port_t *) datap;
		eventMsg.h.msg_remote_port = (port_t) eventPort;
	} else
		return EINVAL;
  	break;
    case EVIOLLPE:	/* Low-level Post Event */
    {
	struct evioLLEvent *edp = (struct evioLLEvent *)datap;

	LLEventPost(edp->type, edp->location, &edp->data);
	break;
    }
    case EVIOSD:	/* StillDown */
	*datap = (leftENum == (*datap));
	break;
    case EVIORSD:	/* RightStillDown */
	*datap = (rightENum == (*datap));
	break;
    case EVIOSM:	/* SetMouse (position) */
    {
	Point *pp = (Point *)datap;

	MoveTheCursor(*pp, 0);	/* plan 724 (D024, D162) */
	break;
    }
    case EVIOST:	/* StartCursor (position) */
	StartCursor();	/* plan 724 (D024, D162) */
	break;
    case EVIOCM:	/* CurrentMouse (position) */
    {
	Point *pp = (Point *)datap;

	pp->x = evg->cursorLoc.x;
	pp->y = evg->cursorLoc.y;
	break;
    }
    default:
	return(EINVAL);
    } /* switch(cmd) */

    if ((!wereEvents) && EventsInQueue())
	evnewevents();
    return 0;
}
/* plan 724 END */

/******************************************************************************
	evsioctl
	
	is the ioctl routine for the evs (event status) driver.
	It is what allows any program -- not just the one program
	that can open the ev driver -- to set user parameters, such
	as key repeat.
******************************************************************************/

/* plan 724 (D024, D161, D162) BEGIN: evsioctl, from the original bytes */
evsioctl(dev_t dev, int cmd, int *datap, int flag)
{
    int wereEvents;

    if (!eventsOpen)
	return(ENXIO);	/* Then can't change its status */
    wereEvents = EventsInQueue();

    switch(cmd) {
    case EVSIOLLPE:	/* Low-level Post Event */
    {
	struct evioLLEvent *edp = (struct evioLLEvent *)datap;
	keySema++;
	evg->cursorSema++;
	LLEventPost(edp->type, edp->location, &edp->data);
	evg->cursorSema--;
	keySema--;
	break;
    }
    case EVSIOPTRLLPE:	/* plan 724 (D024, D162): same text as EVSIOLLPE */
    {
	struct evioLLEvent *edp = (struct evioLLEvent *)datap;
	keySema++;
	evg->cursorSema++;
	LLEventPost(edp->type, edp->location, &edp->data);
	evg->cursorSema--;
	keySema--;
	break;
    }
    case EVSIOSWT:	/* SetWaitThreshold */
	evg->waitThreshold = (*datap < 0) ? 0 : *datap;	/* plan 724 (D024, D162) */
	break;
    case EVSIOCWT:	/* CurrentWaitThreshold */
	*datap = evg->waitThreshold;
	break;
    case EVSIOSWS:	/* SetWaitSustain */
    	waitSustain = (*datap < 0) ? 0 : *datap;
	break;
    case EVSIOCWS:	/* CurrentWaitSustain */
	*datap = waitSustain;
	break;
    case EVSIOSWFR:	/* SetWaitFrameRate */
    	waitFrameRate = (*datap < 2) ? 0 : *datap;
	break;
    case EVSIOCWFR:	/* CurrentWaitFrameRate */
    	*datap = waitFrameRate;
	break;
    case EVSIOCKR:	/* CurrentKeyRepeat */
	*datap = keyRepeat;
	break;
    case EVSIOSKR:	/* SetKeyRepeat */
	if (((*datap) > 0) && ((*datap) <= MAXKEYREPEAT))
	    keyRepeat = (*datap);
	break;
    case EVSIOCIKR:	/* CurrentInitialKeyRepeat */
	*datap = initialKeyRepeat;
	break;
    case EVSIOSIKR:	/* SetInitialKeyRepeat */
	if (((*datap) > 0) && ((*datap) <= MAXINITIALKEYREPEAT))
		initialKeyRepeat = (*datap);
	break;
    case EVSIOCKM:	/* CurrentKeyMapping */
    {
	struct evsioKeymapping *ekmp = (struct evsioKeymapping *)datap;
	struct evsioKeymapping ekm;

	ekm.mapping = (char *)(curMapping->mapping);
	ekm.size = curMapLen;
	if (ekm.size < ekmp->size)
		ekmp->size = ekm.size;
	if (copyout(ekm.mapping, ekmp->mapping, ekmp->size))
		return(EINVAL);
	break;
    }
    case EVSIOCKML:	/* CurrentKeyMappingLength */
	*datap = curMapLen;
	break;
    case EVSIOSKM:	/* SetKeyMapping */
    {
	struct evsioKeymapping *ekmp = (struct evsioKeymapping *)datap;
	unsigned char *oldMapping;
	char *mappingData;
	int oldMapSize;

	mappingData = (char *) kalloc(ekmp->size);	/* plan 724 (D024, D162) */
	oldMapSize = curMapLen;
	/* Note order dependency in the if statement */
	if ((copyin(ekmp->mapping,mappingData,ekmp->size))  ||
	((oldMapping = SetKeyMapping(mappingData,ekmp->size)) == NULL)) {
	    kfree((vm_offset_t)mappingData, ekmp->size);	/* plan 724 (D024, D162) */
	    return(EINVAL);
	}
	/* Take care of freeing the old ampping data space if it was
	   allocated here previously, or of updating the mapNotDefault
	   variable if this is the first non-default map. */
	if (mapNotDefault)
	    kfree((vm_offset_t)oldMapping, oldMapSize);	/* plan 724 (D024, D162) */
	else
	    mapNotDefault = 1;
	break;
    }
    case EVSIORKBD:	/* ResetKeyboard */
	ResetKbd();
	break;

/* Mouse-related ioctls */

    case EVSIOSCT:	/* SetClickTime */
	clickTimeThresh = *datap;
	break;
    case EVSIOCCT:	/* CurrentClickTime */
	*datap = clickTimeThresh;
	break;
    case EVSIOSCS:	/* SetClickSpace */
    {
	Point *pp = (Point *)datap;

	clickSpaceThresh.x = pp->x;
	clickSpaceThresh.y = pp->y;
	break;
    }
    case EVSIOCCS:	/* CurrentClickSpace */
    {
	Point *pp = (Point *)datap;

	pp->x = clickSpaceThresh.x;
	pp->y = clickSpaceThresh.y;
	break;
    }
    case EVSIOSMS:	/* SetMouseScaling */
    {
	struct evsioMouseScaling *emsp = (struct evsioMouseScaling *)datap;
	short i;

	EVSETSEMA();
	numMouseScales = emsp->numScaleLevels;
	for (i=emsp->numScaleLevels-1; i != -1; i--) {
	    mouseScaleThresholds[i] = emsp->scaleThresholds[i];
	    mouseScaleFactors[i] = emsp->scaleFactors[i];
	}
	EVCLEARSEMA();
	break;
    }
    case EVSIOCMS:	/* CurrentMouseScaling */
    {
	struct evsioMouseScaling *emsp = (struct evsioMouseScaling *)datap;
	short i;

	emsp->numScaleLevels = ((numMouseScales > MAXMOUSESCALINGS) ?
	    MAXMOUSESCALINGS : numMouseScales);
	for (i=emsp->numScaleLevels-1; i != -1; i--) {
	    emsp->scaleThresholds[i] = mouseScaleThresholds[i];
	    emsp->scaleFactors[i] = mouseScaleFactors[i];
	}
	break;
    }
    case EVSIORMS:	/* ResetMouse */
    	ResetMouse();
	break;
    case EVSIOSADT:	/* SetAutoDimTime */
    	autoDimTime = autoDimTime - autoDimPeriod + (*((int *)datap));
    	autoDimPeriod = (*((int *)datap));
	break;
    case EVSIOCADT:	/* CurrentAutoDimTime (this should be CurentAutoDimPeriod...) */
    	(*((int *)datap)) = autoDimPeriod;
	break;
    case EVSIOGADT:	/* GetAutoDimTime */
    	(*((int *)datap)) = autoDimTime;
	break;
    case EVSIOGDADT:	/* plan 724 (D024, D162): GetDeltaAutoDimTime */
    	(*((int *)datap)) = autoDimTime - evg->VertRetraceClock;
	break;
    case EVSIOCADS:
    	(*((int *)datap)) = autoDimmed;
	break;
    case EVSIOSADS:	/* plan 724 (D024, D162): Force AutoDimmed on or off */
	if (*((int *)datap)) {
	    autoDimTime = evg->VertRetraceClock;
	    DoAutoDim();
	} else {
	    UndoAutoDim();
	    autoDimTime = evg->VertRetraceClock + autoDimPeriod;
	}
	break;
    case EVSIOSMH:	/* SetMouseHandedness */
    	mouseHandedness = (*((int *)datap));
	break;
    case EVSIOCMH:	/* CurrentMouseHandedness */
    	(*((int *)datap)) = mouseHandedness;
	break;
    case EVSIOSMBT:	/* SetMouseButtonsTied */
    	buttonsTied = (*((int *)datap));
	break;
    case EVSIOCMBT:	/* CurrentMouseButtonsTied */
    	(*((int *)datap)) = buttonsTied;
	break;
    case EVSIOSB:	/* Set Brightness */
    	/* SetCurBrightness is in ev_kbd.c */
    	curBright = SetCurBrightness(*((int *)datap));
	RecordBrightness();	/* plan 724 (D024, D162) */
    	break;
    case EVSIOCB:	/* Current Brightness */
    	(*((int *)datap)) = curBright;
    	break;
    case EVSIOSA:	/* Set Attenuation */
	SetAttenuation(3, *((int *)datap));
	snd_device_vol_set();
	snd_device_vol_save();	/* plan 724 (D024, D162) */
    	break;
    case EVSIOCA:	/* Current Attenuation */
    	(*((int *)datap)) = (vol_l + vol_r)/2;
    	break;
    case EVSIOSADB:	/* plan 724 (D024, D162): Set AutoDim Brightness */
	dimmedBrightness = *((int *)datap);
	dimmedBrightness = MAX(dimmedBrightness, BRIGHT_MIN);
	dimmedBrightness = MIN(dimmedBrightness, BRIGHT_MAX);
	if (autoDimmed)
	    DoAutoDim();
	break;
    case EVSIOCADB:	/* plan 724 (D024, D162): Current AutoDim Brightness */
	(*((int *)datap)) = dimmedBrightness;
	break;
    case EVSIOINFO:	/* plan 724 (D024, D162) */
	return(evsio_info((struct _NXEventSystemInfo_ioctl *)datap));
    default:
	return(EINVAL);
    } /* switch(cmd) */

    if ((!wereEvents)&&EventsInQueue())
	evnewevents();
    return 0;
}
/* plan 724 END */

/* plan 724 (D024, D162) BEGIN: evsio_defaults and evsio_info, new in 1997 (EVSIOINFO) */
/* plan 724 (D024, D162): the default devices when adb_system_info() finds none */
static int evsio_defaults(NXEventSystemDevice *dev, int max)
{
    int n = 0;

    if (max > 0) {
	dev[0].interface = NX_EVS_DEVICE_INTERFACE_NeXT;
	dev[0].interface_addr = 0;
	dev[0].dev_type = NX_EVS_DEVICE_TYPE_KEYBOARD;
	dev[0].id = mon_rev;
	n++;
    }
    if (max > 1) {
	dev[1].interface = NX_EVS_DEVICE_INTERFACE_NeXT;
	dev[1].interface_addr = 1;
	dev[1].dev_type = NX_EVS_DEVICE_TYPE_MOUSE;
	dev[1].id = mon_rev;
	n++;
    }
    return n;
}

/* plan 724 (D024, D162): EVSIOINFO */
static int evsio_info(struct _NXEventSystemInfo_ioctl *info)
{
    NXEventSystemDeviceList list;
    NXEventSystemDevice *dev = list.dev;
    int n;

    if (info->flavor == __OLD_NX_EVS_DEVICE_INFO) {
	if (info->size == 0) {
	    info->size = NX_EVS_DEVICE_INFO_COUNT;
	    return(0);
	}
	n = adb_system_info(dev, NX_EVS_DEVICE_MAX);
	if (n == 0)
	    n = evsio_defaults(dev, NX_EVS_DEVICE_MAX);
	n *= sizeof(NXEventSystemDevice) / sizeof(int);
	if (n < info->size)
	    info->size = n;
    } else
	return(EINVAL);
    if (copyout(dev, info->data, info->size * sizeof(int)))
	return(EFAULT);
    return(0);
}
/* plan 724 END */
