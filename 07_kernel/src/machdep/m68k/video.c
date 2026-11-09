/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 *
 * 12-Sep-90  Mike Paquette (mpaque) at NeXT
 *	Updated to reflect final Warp 9C hardware defs.
 *
 * 6-Jul-90  Mike Paquette (mpaque) at NeXT
 *	Reworked to support multiple built-in video devices.
 *
 * 13-Jun-90  Ted Cohn (tcohn) at NeXT
 *	Added argument NXCursorData to cursor routines.
 *	
 * 22-May-90  Ted Cohn (tcohn) at NeXT
 *	vidDisplayCursor, vidMoveCursor, and vidSetCursor now take wait cursor
 *	frame argument to put up the wait cursor.
 *	
 *  2-Apr-90  Ted Cohn (tcohn) at NeXT
 *	Modified vidSetCursor to take corrected sense of cursor data.
 *	That is, from premultiplied towards white to black.
 *
 * 15-Mar-90  John Seamons (jks) at NeXT
 *	Added support for auto poweron mode of new clock chip.
 *
 * 12-Mar-90  Ted Cohn (tcohn) at NeXT
 *	Call ev_unregister_screen upon closing video driver.  Added static
 *	vid_screen_token to record screen registration id around.
 *
 * 01-Mar-90  Ted Cohn (tcohn) at NeXT
 *	New device-specific (MegaPixel) cursor drawing routines added.
 *	New DKIOCREGISTER ioctl call added to register the screen to the
 *	ev driver.
 *
 * 28-Feb-90  John Seamons (jks) at NeXT
 *	New flag to DKIOCGADDR ioctl (STOP_ANIM) that temporarily stops boot
 *	icon animation.  Use CONTINUE_ANIM to start animation going again.
 *
 * 28-Feb-90  John Seamons (jks) at NeXT
 *	Pass thread as first argument to pmap_tt().
 *
 * 12-Dec-88  Leo Hourvitz (leo) at NeXT
 *	Old bright_set procedure now renamed to SetBrightness
 *
 * 15-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Don't allocate virtual space for video memory and MWF space.
 *	Just reset the maximum allowable size for the map that needs
 *	such access.
 *
 * 21-Sep-87  John Seamons (jks) at NeXT
 *	Created.
 */ 

/*
 * Video device driver
 *
 * This device driver is used to control and map into virtual memory the built-in
 * frame buffer on the CPU board.  There are several possible frame buffers supported
 * in our products, including the 2 bit grey and the 16 bit color frame buffers.  Since
 * there is at most one frame buffer on a CPU board, access to the frame buffer is
 * always through "/dev/vid0".  The characteristics of the installed frame buffer can
 * be read through an ioctl() call.  This provides backwards compatibility with certain 
 * programs (blit, fbshow, WindowServer) that explicitly open /dev/vid0 for the purpose
 * of controlling the boot animation.
 *
 * Maps the video RAM into virtual space with the MMU transparent translation
 * register #1.  This register is timeshared among multiple threads by
 * code in load_context() which reloads it from pcb->pcb_mmu_tt1.
 * The virtual space used is slot dependent because transparent translation
 * does not offset the PA and VA (it's always 1:1).
 *
 * Additional ioctl() calls support unmapping the video RAM, registering the cursor
 * functions with the event system.
 *
 * A generic procedural interface is provided for setting up vertical retrace event
 * handlers, as the hardware interface differs drastically for the different frame
 * buffers.
 *
 * Special autoconfiguration code is provided to support the startup Mach console
 * display (see nextdev/km.c).
 */

/*
 * plan 761 (D171, D013, D024, D104): the 1997 m68k video.c.
 * NeXTMach mk-108.1 nextdev/video.c with its notice, HISTORY and description kept
 * (the lines above), changed to what the original bytes [0x4089786, 0x408b300)
 * show (plans 760-761); the original has three built-in frame buffer entries
 * (video_dev[]: the 2 bit MegaPixel BW2 and two 16 bit color variants that share
 * everything but present() and config()) and the new screen registration of the
 * event system (ev_register_screen with four vectors and a driver-private shared
 * memory area, msp).
 *	functions that differ from NeXTMach: vidopen, vidioctl, vidProbeForFB, vidStopAnimation, vidSuspendAnimation, vidResumeAnimation, vidSetBrightness, vidInterruptEnable, vid_BW2_present, vid_BW2_config, vid_BW2_init, vid_BW2_MapFB, vid_BW2_DisplayCursor, vid_BW2_RemoveCursor, vid_BW2_SetBrightness, vid_BW2_installIntr, vid_BW2_intr, vid_BW2_SuspendAnim, vid_BW2_ResumeAnim, vid_C16_init, vid_C16_MapFB, vid_C16_DisplayCursor, vid_C16_RemoveCursor, vid_C16_SetBrightness, vid_C16_installIntr, vid_C16_intr, vid_C16_SuspendAnim, vid_C16_ResumeAnim
 *	new functions: vidGetFBAddrAndSize, vidApplyBrightness, vid_BW2_UnMapFB, vid_C16_present2, vid_C16_present1, vid_C16_config2, vid_C16_config1, vid_C16_UnMapFB, vid_ev_hide, vid_ev_show, vid_ev_move, vid_ev_level, vidRegisterScreen
 *	NeXTMach functions that are not in the 1997 unit: vidConfigureFB, vidMoveCursor, vid_probe_faulted, vid_early_probe, vid_BW2_SetCursor, vid_C16_present, vid_C16_config, vid_C16_SetCursor
 * The cursor hide/show/shield logic of vid_ev_hide, vid_ev_show and vid_ev_move is
 * that of NeXTMach nextdev/ev_cursor.c (SysHideCursor, SysShowCursor, CheckShield)
 * moved into this driver; the device cursor drawing functions are NeXTMach's
 * vid_*_DisplayCursor and vid_*_RemoveCursor rewritten for the msp structure of
 * <dev/m68k/video.h>.  The original has no symbols for its static functions and
 * static data: the NeXTMach statics keep their names; the new functions and
 * variables, the ioctls DKIOCGGAMMA, DKIOCSGAMMA and DKIOCRGAMMA and the local
 * names in the marked regions are given by this project (D171; the bytes do not
 * decide them).  The loops written for (i = n; i--; ), the skip written with
 * (char *)vramPtr + vramRow + vramRow, the zero initial values of the flags
 * doLeft and doRight and the one copy of dma_chip in chip are forms that give the
 * original bytes, not evidence of the original source.  The functions are in the
 * address order of the original.  Lines marked plan 761, and the lines of a plan
 * 761 BEGIN/END region (which may include unchanged lines), differ from NeXTMach.
 */

/* plan 761 (D024, D171) BEGIN: includes, definitions, declarations and data */
#import <sys/types.h>
#import <sys/param.h>	/* plan 761 (D024): not imported by NeXTMach video.c */
#import <sys/errno.h>
#import <sys/callout.h>
#import <kern/task.h>
#import <kern/thread.h>
#import <sys/ioctl.h>
#import <sys/user.h>
#import <mach/vm_param.h>	/* plan 761 (D104): NeXTMach <vm/vm_param.h> */
#import <vm/vm_map.h>
#import <vm/vm_object.h>
#import <vm/pmap.h>
#import <m68k/cpu.h>	/* plan 761 (D104): NeXTMach <next/cpu.h> (D110) */
#import <m68k/vmparam.h>	/* plan 761 (D104): NeXTMach <next/vmparam.h> */
#import <machine/spl.h>	/* plan 761 (D024): not imported by NeXTMach video.c */
#import <nextdev/dma.h>
#import <dev/m68k/video.h>	/* plan 761 (D104): NeXTMach <nextdev/video.h> */
#import <bsd/dev/m68k/evio.h>	/* plan 761 (D104): NeXTMach <nextdev/ev_vars.h> */
#import <nextdev/kmreg.h>
#import <mon/global.h>
#import <mon/nvram.h>	/* plan 761 (D024): not imported by NeXTMach video.c */

/* plan 761 (D171): names of NeXTMach headers that are not in the 1997 SDK, and the gamma ioctls (values from the original bytes); defined here, as km.c (D104, D158) */
extern int slot_id, slot_id_bmap;
#define SLOT_ID		slot_id
#define NeXT_CUBE	0
#define NeXT_WARP9	1
#define NeXT_X15	2
#define NeXT_WARP9C	3
#define P_VIDEO_CSR	(SLOT_ID+0x02000180)
#define P_VIDEOMEM	(SLOT_ID + ((dma_chip == 313) ? 0x0b000000 : 0x0c000000))
#define PCB_TT1		0x80000000
#define PMAP_TT_DISABLE		0
#define PMAP_TT_ENABLE		1
#define PMAP_TT_NON_CACHEABLE	0
#define PMAP_TT_CACHEABLE	1
#define SLOT_ID_BMAP	slot_id_bmap
#define P_C16_VIDEOMEM	((dma_chip == 313) ? 0x2c000000 : 0x0c000000)
#define C16_VIDEO_NBPL	(C16_VIDEO_1120x832_MW * C16_VIDEO_NBPP)
#define C16_VIDEOSIZE	(C16_VIDEO_NBPL * C16_VIDEO_1120x832_H)
#define P_C16_DAC_0	((dma_chip == 313) ? (SLOT_ID_BMAP + 0x02018100) : (SLOT_ID + 0x0201c000))
#define P_C16_DAC_1	((dma_chip == 313) ? (SLOT_ID_BMAP + 0x02018101) : (SLOT_ID + 0x0201c001))
#define P_C16_DAC_3	((dma_chip == 313) ? (SLOT_ID_BMAP + 0x02018103) : (SLOT_ID + 0x0201c003))
#define P_C16_CMD_REG	(SLOT_ID_BMAP + 0x02018180)
#define CURSORWIDTH	16
#define CURSORHEIGHT	16
/* plan 761 (D171): this project's names for the ioctls 0x40307608, 0x80307608, 0x20007609 (not in <dev/m68k/video.h>) */
#define DKIOCGGAMMA	_IOR('v', 8, vid_gamma_t)
#define DKIOCSGAMMA	_IOW('v', 8, vid_gamma_t)
#define DKIOCRGAMMA	_IO('v', 9)
typedef unsigned char vid_gamma_t[48];

extern int evOpenCalled, autoDimmed, curBright, dimmedBrightness;
extern volatile u_char *brightness;
extern char boot_dev[], boot_info[], boot_file[];
extern struct km_console_info km_coni;

void vidStopAnimation();
void vidSuspendAnimation();
void vidResumeAnimation();
int vidProbeForFB();
static void vidApplyBrightness();
static int vidRegisterScreen();
static int vid_ev_move();
static int vid_ev_hide();
static int vid_ev_show();
static int vid_ev_level();
extern int console_o;

static int vid_BW2_present();
static void vid_BW2_config();
static void vid_BW2_init();
static vm_offset_t vid_BW2_MapFB();
static void vid_BW2_UnMapFB();
static void vid_BW2_DisplayCursor();
static void vid_BW2_RemoveCursor();
static void vid_BW2_SetBrightness();
static void vid_BW2_installIntr();
static void vid_BW2_intr();
static void vid_BW2_SuspendAnim();
static void vid_BW2_ResumeAnim();

static int vid_C16_present1();
static int vid_C16_present2();
static void vid_C16_config1();
static void vid_C16_config2();
static void vid_C16_init();
static vm_offset_t vid_C16_MapFB();
static void vid_C16_UnMapFB();
static void vid_C16_DisplayCursor();
static void vid_C16_RemoveCursor();
static void vid_C16_SetBrightness();
static void vid_C16_installIntr();
static void vid_C16_intr();
static void vid_C16_SuspendAnim();
static void vid_C16_ResumeAnim();

#define VID_NO_FB	-1
static int vidFBnum = VID_NO_FB;
static void (*vidIntrFunc)() = (void (*)()) 0;
static char vidAnimSuspended = 0;
static char vidBW2Suspended = 0;
typedef	void (*voidfptr_t)();

static struct
{
	int	(*present)();
	void	(*config)();
	void	(*init)();
	vm_offset_t (*MapFB)();
	void	(*UnMapFB)();
	void	(*DisplayCursor)();
	void	(*RemoveCursor)();
	void	(*SetBrightness)();
	void	(*installIntr)();
	void	(*suspendAnim)();
	void	(*resumeAnim)();
} video_dev[] =
{
    {	vid_BW2_present, vid_BW2_config, vid_BW2_init, vid_BW2_MapFB,
	vid_BW2_UnMapFB, vid_BW2_DisplayCursor, vid_BW2_RemoveCursor,
	vid_BW2_SetBrightness,
	vid_BW2_installIntr,
	vid_BW2_SuspendAnim, vid_BW2_ResumeAnim
    },
    {	vid_C16_present1, vid_C16_config1, vid_C16_init, vid_C16_MapFB,
	vid_C16_UnMapFB, vid_C16_DisplayCursor, vid_C16_RemoveCursor,
	vid_C16_SetBrightness,
	vid_C16_installIntr,
	vid_C16_SuspendAnim, vid_C16_ResumeAnim
    },
    {	vid_C16_present2, vid_C16_config2, vid_C16_init, vid_C16_MapFB,
	vid_C16_UnMapFB, vid_C16_DisplayCursor, vid_C16_RemoveCursor,
	vid_C16_SetBrightness,
	vid_C16_installIntr,
	vid_C16_SuspendAnim, vid_C16_ResumeAnim
    }
};

#define NUM_VIDEO_DEVS (sizeof video_dev / sizeof video_dev[0])

static unsigned char vid_gamma_r[16] = {
	0x00, 0x4a, 0x66, 0x7b, 0x8c, 0x9b, 0xa8, 0xb4,
	0xc0, 0xca, 0xd4, 0xdd, 0xe6, 0xef, 0xf7, 0xff };
static unsigned char vid_gamma_g[16] = {
	0x00, 0x4a, 0x66, 0x7b, 0x8c, 0x9b, 0xa8, 0xb4,
	0xc0, 0xca, 0xd4, 0xdd, 0xe6, 0xef, 0xf7, 0xff };
static unsigned char vid_gamma_b[16] = {
	0x00, 0x4a, 0x66, 0x7b, 0x8c, 0x9b, 0xa8, 0xb4,
	0xc0, 0xca, 0xd4, 0xdd, 0xe6, 0xef, 0xf7, 0xff };
static const unsigned char vid_gamma_default[16] = {
	0x00, 0x4a, 0x66, 0x7b, 0x8c, 0x9b, 0xa8, 0xb4,
	0xc0, 0xca, 0xd4, 0xdd, 0xe6, 0xef, 0xf7, 0xff };

static int vid_screen_token;
static void * vidIntrFuncArg;
static vidShmemStruct *msp;
static unsigned int vid_disp_start, vid_disp_end, vid_rem_start, vid_rem_end;
static unsigned int vid_flush_flags;
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidopen */
vidopen(dev_t dev)
{
	if ( vidFBnum == VID_NO_FB )
	{
		if ( vidProbeForFB() == -1 )
			return ENODEV;
	}
        return 0;
}
/* plan 761 END */

vidclose(dev_t dev)
{
    ev_unregister_screen(vid_screen_token);
    vid_screen_token = 0;
}

/* plan 761 (D024, D171) BEGIN: vidioctl */
vidioctl(dev, cmd, data, flag)
    dev_t dev;
    caddr_t data;
{
    struct pcb		*pcb = current_thread()->pcb;
    extern		struct mon_global *mon_global;
    struct		nvram_info ni, *nip;
    int			*bp;

    switch (cmd) {

    case DKIOCGADDR:
	if (*(int*)data == STOP_ANIM) {
	    vidSuspendAnimation();
	} else
	if (*(int*)data == CONTINUE_ANIM) {
	    vidResumeAnimation();
	} else {
	    vidStopAnimation();
	}
	if (pcb->pcb_flags & PCB_TT1)
	    return EBUSY;
	if (*(int*)data != CONTINUE_ANIM) {
	    vidStopAnimation();
	}
	if ((*(vm_offset_t*) data = (*video_dev[vidFBnum].MapFB)()) == 0)
	    return ENXIO;
	break;

    case DKIOCBRIGHT:
	bp = (int *)data;
	nvram_check(&ni);
	*bp = ni.ni_brightness = SetCurBrightness(*bp);
	nvram_set(&ni);
	return 0;

    case DKIOCGNVRAM:
	if (!suser())
	    return u.u_error;
	nvram_check (data);
	return 0;

    case DKIOCSNVRAM:
	if (!suser())
	    return u.u_error;
	nip = (struct nvram_info*) data;
	nvram_check (&ni);

	if (strncmp (ni.ni_bootcmd, nip->ni_bootcmd, NVRAM_BOOTCMD)) {
	    strcpy (boot_dev, nip->ni_bootcmd);
	    boot_info[0] = 0;
	    boot_file[0] = 0;
	}
	if (ni.ni_auto_poweron != nip->ni_auto_poweron)
		rtc_set_auto_poweron (nip->ni_auto_poweron);
	nvram_set (nip);
	return 0;

    case DKIOCGALARM:
    	return (rtc_alarm (0, data));

    case DKIOCSALARM:
    	if (!suser())
	    return u.u_error;
	return (rtc_alarm (data, 0));

    case DKIOCREGISTER:
	return vidRegisterScreen();

    case DKIOCDISABLE:
	if ((pcb->pcb_flags & PCB_TT1) == 0)
	    return ENXIO;
	(*video_dev[vidFBnum].UnMapFB)();
	return 0;

    case DKIOCGFBINFO: {
	struct km_console_info kmcons;
	struct km_console_info *kp = *((struct km_console_info **) data);
	(*video_dev[vidFBnum].config)(&kmcons);
	return ( copyout( &kmcons, kp, sizeof (struct km_console_info) ) );
    }

    case DKIOCGGAMMA:
	bcopy (vid_gamma_r, data, sizeof (vid_gamma_t));
	break;

    case DKIOCSGAMMA:
	bcopy (data, vid_gamma_r, sizeof (vid_gamma_t));
	vidApplyBrightness();
	break;

    case DKIOCRGAMMA: {
	int i;
	for (i = 0; i < 16; i++) {
	    vid_gamma_r[i] = vid_gamma_default[i];
	    vid_gamma_g[i] = vid_gamma_default[i];
	    vid_gamma_b[i] = vid_gamma_default[i];
	}
	vidApplyBrightness();
	break;
    }
    default:
	return ENOTTY;
    }
    return 0;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidProbeForFB */
/*
 * Scan down the list of video devices.  Return the FB number of the video
 * device found, or -1 if none is found.  This routine should only be called
 * from km.c, very early in the startup process, before probe_rb() is available.
 */
 int
vidProbeForFB()
{
	short fb_num;

	for ( fb_num = NUM_VIDEO_DEVS - 1; fb_num >= 0; --fb_num) {
	    if ( (*video_dev[fb_num].present)() == TRUE ){
		vidFBnum = fb_num;
		(*video_dev[fb_num].init)();
		return fb_num;
	    }
	}
	return -1;
}
/* plan 761 END */

/*
 * Fill in the console info structure for the current video device, if any.
 * vidProbeForFB() must have been called succesfully for this to work.  This must be 
 * done procedurally, due to the presence of the 'slotid' variable in address macros.
 */
 void
vidGetConsoleInfo(struct km_console_info *kp)
{
	if ( vidFBnum != VID_NO_FB )
		(*video_dev[vidFBnum].config)(kp);
}

/* plan 761 (D024, D171) BEGIN: vidGetFBAddrAndSize */
 void
vidGetFBAddrAndSize(vm_offset_t *addr, vm_size_t *size)
{
	struct km_console_info kmcons;

	if ( vidFBnum == VID_NO_FB ) {
		if ( vidProbeForFB() == -1 ) {
			*addr = 0;
			*size = 0;
			return;
		}
	}
	(*video_dev[vidFBnum].config)(&kmcons);
	*addr = kmcons.map_addr[KM_CON_FRAMEBUFFER].phys_addr;
	*size = km_coni.map_addr[KM_CON_FRAMEBUFFER].size + km_coni.map_addr[KM_CON_BACKINGSTORE].size;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidStopAnimation */
/*
 * Generic 'stop animation' call.  Flag the boot ROM to stop the animation
 * after the next retrace interrupt.
 */
 void
vidStopAnimation()
{
	extern		struct mon_global *mon_global;
	struct		mon_global *mg = mon_global;

	*MG (char*, MG_flags) &= ~MGF_ANIM_RUN;
	if ( vidIntrFunc )
		vidResumeAnimation();
	DELAY (100000);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidSuspendAnimation */
 void
vidSuspendAnimation()
{
	if ( vidFBnum != VID_NO_FB && !vidAnimSuspended ) {
		(*video_dev[vidFBnum].suspendAnim)();
		vidAnimSuspended = 1;
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidResumeAnimation */
 void
vidResumeAnimation()
{
	if ( vidFBnum != VID_NO_FB && vidAnimSuspended ) {
		(*video_dev[vidFBnum].resumeAnim)();
		vidAnimSuspended = 0;
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidSetBrightness */
/*
 * Set the brightness of the built-in frame buffer, if any.
 * This is called from SetCurBrightness(), in ev_kbd.c
 */
 void
vidSetBrightness( int level )
{
	if ( vidFBnum != VID_NO_FB )
		(*video_dev[vidFBnum].SetBrightness)(level);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidApplyBrightness */
 static void
vidApplyBrightness()
{
	int level;
	struct nvram_info ni;

	if ( evOpenCalled ) {
		if ( autoDimmed && dimmedBrightness < curBright )
			level = dimmedBrightness;
		else
			level = curBright;
	} else {
		nvram_check(&ni);
		level = ni.ni_brightness;
	}
	vidSetBrightness( level );
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidInterruptEnable */
/*
 * Install a function as the vertical retrace interrupt handler.  The interrupt
 * passes control to our device specific code, which clears the interrupt.  Our
 * interrupt code then passes control to the specified function, to drive retrace
 * time events.
 */
 void
vidInterruptEnable( voidfptr_t func, void *arg )
{
	if ( vidFBnum == VID_NO_FB )
	{
		if ( vidProbeForFB() == -1 )
			return;
	}
	vidIntrFunc = func;
	vidIntrFuncArg = arg;
	(*video_dev[vidFBnum].installIntr)();
}
/* plan 761 END */

/*
 * Disable vertical retrace interrupts.
 * Clear the interrupt handler pointer.
 */
 void
vidInterruptDisable()
{
	int s;
	/* Make sure that a display device is configured */
	if ( vidFBnum == VID_NO_FB )
		return;
	/* Clear out the function and it's arg. */
	s = splhigh();
	vidIntrFunc = (voidfptr_t) 0;
	vidIntrFuncArg = (void *) 0;
	splx(s);
}

/* plan 761 (D024, D171) BEGIN: vid_BW2_present */
/*
 *	2 Bit Display Device code.
 */
 static int
vid_BW2_present()
{
	switch (machine_type) {
	case NeXT_CUBE:
	case NeXT_WARP9:
	case NeXT_X15:
	case 4:
	case 8:
		return TRUE;
	}
	if (dma_chip != 313 && !(machine_type & 1))
		return TRUE;
	return FALSE;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_config */
 static void
vid_BW2_config(struct km_console_info * kp)
{
	unsigned int w, mw, h;

	if (dma_chip != 313) {
		w = *(unsigned int *)(SLOT_ID + 0x02200088) & 0xfff;
		w = mw = w << 2;
		h = *(unsigned int *)(SLOT_ID + 0x0220008c);
		h &= 0xfff;
	} else {
		w = 1120;
		mw = 1152;
		h = 832;
	}
	kp->pixels_per_word = 16;
	kp->bytes_per_scanline = mw >> 2;
	kp->dspy_w = w;
	kp->dspy_max_w = mw;
	kp->dspy_h = h;
	kp->flag_bits = 0;
	kp->color[0] = WHITE;
	kp->color[1] = LT_GRAY;
	kp->color[2] = DK_GRAY;
	kp->color[3] = BLACK;
	
	kp->map_addr[KM_CON_FRAMEBUFFER].virt_addr = P_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].phys_addr = P_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].size = kp->bytes_per_scanline * h;
	kp->map_addr[KM_CON_BACKINGSTORE].phys_addr = kp->map_addr[KM_CON_BACKINGSTORE].virt_addr =
					P_VIDEOMEM + kp->map_addr[KM_CON_FRAMEBUFFER].size;
	kp->map_addr[KM_CON_BACKINGSTORE].size = (VIDEO_MH - h) * kp->bytes_per_scanline;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_init */
 static void
vid_BW2_init()
{
	struct nvram_info ni;

	nvram_check(&ni);
	vid_BW2_SetBrightness(ni.ni_brightness);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_MapFB */
/*
 * Transparently map the frame buffer into the user task's virtual memory.
 * Limit the maximum virtual address of the calling task to be less than the
 * mapped region, to avoid the chaos that would otherwise occur should the VM grow
 * to overlap the hardware addresses.
 *
 * This hardware includes a memory write function space to perform compositing.  In
 * this space, several physical addresses are aliased to the same video RAM through the
 * compositing hardware.  This forces us to serialize all accesses, so we can't cache
 * this memory.  This means we don't normally do burst reads or writes to the 2 bit
 * frame buffer!
 */
 static vm_offset_t
vid_BW2_MapFB()
{
	vm_offset_t addr;

	addr = P_VIDEOMEM & ~(VID_MAPPED_SIZE - 1);
	if (vm_allocate(current_task()->map, &addr, VID_MAPPED_SIZE, FALSE) != KERN_SUCCESS)
		return 0;
	pmap_tt (current_thread(), PMAP_TT_ENABLE, addr, VID_MAPPED_SIZE,
		PMAP_TT_NON_CACHEABLE);
	return ( (vm_offset_t) P_VIDEOMEM );
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_UnMapFB */
 static void
vid_BW2_UnMapFB()
{
	vm_offset_t addr = P_VIDEOMEM & ~(VID_MAPPED_SIZE - 1);

	vm_deallocate(current_task()->map, addr, VID_MAPPED_SIZE);
	pmap_tt (current_thread(), PMAP_TT_DISABLE, 0, 0, 0);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_DisplayCursor */
/*
 * vid_BW2_DisplayCursor displays the cursor on the MegaPixel framebuffer by first
 * saving what's underneath the cursor, then drawing the cursor there.
 * NOTE: The topleft of the cursorRect passed in is not necessarily the
 * cursor location. The cursorRect is adjusted to compensate for
 * the cursor hotspot.
 */
 static void
vid_BW2_DisplayCursor()
{
    Bounds saveRect;
    unsigned short chip;
    unsigned int vramRow;
    volatile unsigned int *cursPtr;
    volatile unsigned int *vramPtr;
    volatile unsigned int *savePtr;
    volatile unsigned int *maskPtr;
    short i;
    register unsigned int workreg;
    short x;
    char doLeft = 0;
    int doRight = 0;
    int skew, rSkew;

    saveRect = msp->cursorRect;
    if (saveRect.miny < msp->screenBounds.miny) saveRect.miny = msp->screenBounds.miny;
    if (saveRect.maxy > msp->screenBounds.maxy) saveRect.maxy = msp->screenBounds.maxy;
    x = msp->cursorRect.minx - msp->screenBounds.minx;
    saveRect.minx = x-(x & PPXMASK)+msp->screenBounds.minx;
    saveRect.maxx = saveRect.minx + 32;
    msp->saveRect = saveRect;
    chip = dma_chip;
    vramRow = 70;
    if (chip == 313)
	vramRow = 72;
    vramPtr = (unsigned int *)(SLOT_ID + ((chip == 313) ? 0x0b000000 : 0x0c000000)) + (vramRow * (saveRect.miny - msp->screenBounds.miny)) +
	       ((saveRect.minx - msp->screenBounds.minx) >> 4);
    skew = (msp->cursorRect.minx & PPXMASK)<<1;
    rSkew = 32-skew;
    savePtr = msp->cursor.bw.save;
    cursPtr = msp->cursor.bw.image[msp->frame];
    maskPtr = msp->cursor.bw.mask[msp->frame];
    i = saveRect.miny - msp->cursorRect.miny;
    cursPtr += i;
    maskPtr += i;
    doLeft = (saveRect.minx >= msp->screenBounds.minx);
    doRight = (saveRect.maxx <= msp->screenBounds.maxx);

    if (doLeft) {
	if (doRight) {
	    for (i = saveRect.maxy - saveRect.miny; i--; ) {
		volatile unsigned int *rp = vramPtr + 1;

		*savePtr++ = workreg = *vramPtr;
		*vramPtr = (workreg&(~((*maskPtr)>>skew))) | ((*cursPtr)>>skew);
		*savePtr++ = workreg = *rp;
		*rp = (workreg & (~((*maskPtr)<<rSkew)))
			       | ((*cursPtr)<<rSkew);
		vramPtr += vramRow;
		cursPtr++;
		maskPtr++;
	    }
	} else {
	    for (i = saveRect.maxy - saveRect.miny; i--; ) {

		*savePtr++ = workreg = *vramPtr;
		*vramPtr = (workreg&(~((*maskPtr)>>skew))) | ((*cursPtr)>>skew);
		vramPtr += vramRow;
		cursPtr++;
		maskPtr++;
	    }
	}
    } else if (doRight) {
	for (i = saveRect.maxy - saveRect.miny; i--; ) {
	    volatile unsigned int *rp = vramPtr + 1;

	    *savePtr++ = workreg = *rp;
	    *rp = (workreg & (~((*maskPtr)<<rSkew)))
			   | ((*cursPtr)<<rSkew);
	    vramPtr += vramRow;
	    cursPtr++;
	    maskPtr++;
	}
    }
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_RemoveCursor */
/*
 * vidRemoveCursor erases the cursor by replacing the background image that
 * was saved by the previous call to vidDisplayCursor.
 */
 static void
vid_BW2_RemoveCursor()
{
    Bounds saveRect = msp->saveRect;
    unsigned short chip;
    int i;
    int doLeft = 0, doRight = 0;
    unsigned int vramRow;
    unsigned int lmask, rmask;
    volatile unsigned int *vramPtr;
    volatile unsigned int *savePtr;
    static unsigned int vid_mask_array[16] = {
	0xFFFFFFFF,0x3FFFFFFF,0x0FFFFFFF,0x03FFFFFF,
	0x00FFFFFF,0x003FFFFF,0x000FFFFF,0x0003FFFF,
	0x0000FFFF,0x00003FFF,0x00000FFF,0x000003FF,
        0x000000FF,0x0000003f,0x0000000F,0x00000003};

    chip = dma_chip;
    vramRow = 70;
    if (chip == 313)
	vramRow = 72;
    vramPtr = (unsigned int *)(SLOT_ID + ((chip == 313) ? 0x0b000000 : 0x0c000000)) + (vramRow * (saveRect.miny - msp->screenBounds.miny)) +
	       ((saveRect.minx - msp->screenBounds.minx) >> 4);
    savePtr = msp->cursor.bw.save;
    if (doLeft = (saveRect.minx >= msp->screenBounds.minx))
    	lmask = vid_mask_array[msp->oldCursorRect.minx-saveRect.minx];
    if (doRight = (saveRect.maxx <= msp->screenBounds.maxx))
	rmask = ~vid_mask_array[16-(saveRect.maxx-msp->oldCursorRect.maxx)];
    if (doLeft) {
	if (doRight) {
	    for (i = saveRect.maxy-saveRect.miny; i--; ) {
		*vramPtr = (*vramPtr&(~lmask))|(*savePtr++&lmask);
		*(vramPtr+1)=(*(vramPtr+1)&(~rmask))|(*savePtr++&rmask);
		vramPtr += vramRow;
	    }
	} else {
	    for (i = saveRect.maxy-saveRect.miny; i--; ) {
		*vramPtr = (*vramPtr&(~lmask))|(*savePtr++&lmask);
		vramPtr += vramRow;
	    }
	}
    } else if (doRight) {
	for (i = saveRect.maxy-saveRect.miny; i--; ) {
	    *(vramPtr+1)=(*(vramPtr+1)&(~rmask))|(*savePtr++&rmask);
	    vramPtr += vramRow;
	}
    }
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_SetBrightness */
/*
 * Set the brightness of the MegaPixel display.
 */
 static void
vid_BW2_SetBrightness(int level)
{
    static char	bright_table[0x3d+1] = {
	0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3e, 0x3d, 0x3b, 0x37, 0x2f,
	0x1e, 0x3c, 0x39, 0x33, 0x27, 0x0e, 0x1d, 0x3a, 0x35, 0x2b, 0x16,
	0x2c, 0x18, 0x30, 0x21, 0x02, 0x05, 0x0b, 0x17, 0x2e, 0x1c, 0x38,
	0x31, 0x23, 0x06, 0x0d, 0x1b, 0x36, 0x2d, 0x1a, 0x34, 0x29, 0x12,
	0x24, 0x08, 0x11, 0x22, 0x04, 0x09, 0x13, 0x26, 0x0c, 0x19, 0x32,
	0x25, 0x0a, 0x15, 0x2a, 0x14, 0x28, 0x10
    };

    level = bright_table[level];
    *brightness = level | 0x40;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_installIntr */
/*
 * Install a retrace interrupt handler that knows how to ack interrupts from
 * the installed frame buffer.  This handler will then call softint_run().
 */
 static void
vid_BW2_installIntr()
{
	struct dma_dev *vddp = (struct dma_dev*) P_VIDEO_CSR;
	volatile int *p2 = (volatile int *)(SLOT_ID + 0x02200080);

	install_scanned_intr((dma_chip != 313) ? 0xd30 : 0x538, vid_BW2_intr, (void *)0);
	if (dma_chip == 313)
		vddp->dd_limit = (char*) 0xea;
	else
		*p2 = 0x06000000;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_intr */
/*
 * Ack the interrupt from the 2 bit frame buffer, and then transfer control to
 * the soft int package to run retrace time tasks.
 */
 static void
vid_BW2_intr()
{
	struct dma_dev *vddp = (struct dma_dev*) P_VIDEO_CSR;
	volatile int *p2 = (volatile int *)(SLOT_ID + 0x02200080);

	if (dma_chip == 313)
		vddp->dd_csr = 0x00100000;
	else
		*p2 = 0x05000000;
	if ( vidIntrFunc != (voidfptr_t) 0 )
		(*vidIntrFunc)( vidIntrFuncArg );
	if (dma_chip != 313)
		*p2 = 0x06000000;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_SuspendAnim */
 static void
vid_BW2_SuspendAnim()
{
	extern		struct mon_global *mon_global;
	struct		mon_global *mg = mon_global;

	if (curipl() <= 2) {
		*MG (char*, MG_flags) &= ~MGF_ANIM_RUN;
		vidBW2Suspended = 1;
		DELAY (100000);
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_BW2_ResumeAnim */
 static void
vid_BW2_ResumeAnim()
{
	extern		struct mon_global *mon_global;
	struct		mon_global *mg = mon_global;

	if (vidBW2Suspended) {
		vidBW2Suspended = 0;
		*MG (char*, MG_flags) |= MGF_ANIM_RUN;
		if (!(km.flags & KMF_SEE_MSGS) && !console_o &&
		    *MG (short *, 780) > 23 && *MG (int *, 782))
			callout_dispatch(2, *MG (int *, 782), 0);
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_present2 (with its macros) */
/* ---- 16 bit color frame buffer ---- */

 static int
vid_C16_present2()
{
	if (machine_type == NeXT_WARP9C)
		return TRUE;
	return FALSE;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_present1 */
 static int
vid_C16_present1()
{
	switch (machine_type) {
	case 5:
	case 9:
		return TRUE;
	}
	if (dma_chip != 313 && (machine_type & 1))
		return TRUE;
	return FALSE;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_config2 */
 static void
vid_C16_config2(struct km_console_info * kp)
{
	kp->pixels_per_word = 2;
	kp->bytes_per_scanline = C16_VIDEO_NBPL;
	kp->dspy_w = C16_VIDEO_1120x832_W;
	kp->dspy_max_w = C16_VIDEO_1120x832_MW;
	kp->dspy_h = C16_VIDEO_1120x832_H;
	kp->flag_bits = 2;
	kp->color[0] = C16_WHITE;
	kp->color[1] = C16_LT_GRAY;
	kp->color[2] = C16_DK_GRAY;
	kp->color[3] = C16_BLACK;
	kp->map_addr[KM_CON_FRAMEBUFFER].virt_addr = P_C16_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].phys_addr = P_C16_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].size = C16_VIDEOSIZE;
	kp->map_addr[KM_CON_BACKINGSTORE].virt_addr = P_C16_VIDEOMEM + C16_VIDEOSIZE;
	kp->map_addr[KM_CON_BACKINGSTORE].phys_addr = P_C16_VIDEOMEM + C16_VIDEOSIZE;
	kp->map_addr[KM_CON_BACKINGSTORE].size = (C16_VIDEO_1120x832_MH - C16_VIDEO_1120x832_H) * C16_VIDEO_NBPL;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_config1 */
 static void
vid_C16_config1(struct km_console_info * kp)
{
	unsigned int w, mw, h, nbpl;

	w = (*(unsigned int *)(SLOT_ID + 0x02200088)) & 0xfff;
	w *= 4;
	h = (*(unsigned int *)(SLOT_ID + 0x0220008c)) & 0xfff;
	kp->pixels_per_word = 2;
	nbpl = w + w;
	kp->bytes_per_scanline = nbpl;
	kp->dspy_w = w;
	kp->dspy_max_w = w;
	kp->dspy_h = h;
	kp->flag_bits = 2;
	kp->color[0] = C16_WHITE;
	kp->color[1] = C16_LT_GRAY;
	kp->color[2] = C16_DK_GRAY;
	kp->color[3] = C16_BLACK;
	kp->map_addr[KM_CON_FRAMEBUFFER].virt_addr = P_C16_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].phys_addr = P_C16_VIDEOMEM;
	kp->map_addr[KM_CON_FRAMEBUFFER].size = w * (h << 1);
	kp->map_addr[KM_CON_BACKINGSTORE].phys_addr = kp->map_addr[KM_CON_BACKINGSTORE].virt_addr =
					P_C16_VIDEOMEM + nbpl * h;
	kp->map_addr[KM_CON_BACKINGSTORE].size = C16_VID_SIZE - kp->map_addr[KM_CON_FRAMEBUFFER].size;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_init */
/*
 * Initialize the RAMDAC to: blink off, all channels unmasked.
 * Load the LUT, via SetBrightness. 
 *
 * This is straight out of the BrookTree 463 manual.  Please
 * refer to the part manual for details.
 */
 static void
vid_C16_init()
{
	struct nvram_info ni;
    
	nvram_check(&ni);
	vid_C16_SetBrightness(ni.ni_brightness);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_MapFB */
/*
 * Transparently map the frame buffer into the user task's virtual memory.
 * Limit the maximum virtual address of the calling task to be less than the
 * mapped region, to avoid the chaos that would otherwise occur should the VM grow
 * to overlap the hardware addresses.
 * 
 * There's no magic hardware here to do compositing, and therefore no physical address
 * aliasing problem.  We can cache this region and do burst reads and writes.
 */
 static vm_offset_t
vid_C16_MapFB()
{
	vm_offset_t addr;

	addr = P_C16_VIDEOMEM;
	if (vm_allocate(current_task()->map, &addr, VID_MAPPED_SIZE, FALSE) != KERN_SUCCESS)
		return 0;
	pmap_tt (current_thread(), PMAP_TT_ENABLE, addr, VID_MAPPED_SIZE,
		PMAP_TT_CACHEABLE);
	return ( (vm_offset_t) P_C16_VIDEOMEM );
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_UnMapFB */
 static void
vid_C16_UnMapFB()
{
	vm_offset_t addr = P_C16_VIDEOMEM;

	vm_deallocate(current_task()->map, addr, VID_MAPPED_SIZE);
	pmap_tt (current_thread(), PMAP_TT_DISABLE, 0, 0, 0);
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_DisplayCursor */
/*
 * vid_C16_DisplayCursor displays the cursor on the Warp 9C framebuffer by first
 * saving what's underneath the cursor, then drawing the cursor there.
 * NOTE: The topleft of the cursorRect passed in is not necessarily the
 * cursor location. The cursorRect is adjusted to compensate for
 * the cursor hotspot.
 *
 * Since the frame buffer is cacheable, flush at the end of the drawing
 * operation.
 */
 static void
vid_C16_DisplayCursor()
{
    Bounds saveRect;
    unsigned int vramRow;
    volatile unsigned short *cursPtr;
    volatile unsigned short *vramPtr;
    unsigned short *savePtr;
    short i, j, width, cursRow;
    unsigned short s, d, f;

    saveRect = msp->cursorRect;
    if (saveRect.miny < msp->screenBounds.miny) saveRect.miny = msp->screenBounds.miny;
    if (saveRect.maxy > msp->screenBounds.maxy) saveRect.maxy = msp->screenBounds.maxy;
    if (saveRect.minx < msp->screenBounds.minx) saveRect.minx = msp->screenBounds.minx;
    if (saveRect.maxx > msp->screenBounds.maxx) saveRect.maxx = msp->screenBounds.maxx;
    msp->saveRect = saveRect;
    vramRow = km_coni.dspy_max_w;
    vramPtr = (unsigned short *)P_C16_VIDEOMEM + vramRow * (saveRect.miny - msp->screenBounds.miny) + (saveRect.minx - msp->screenBounds.minx);
    vid_disp_start = (unsigned int) vramPtr;
    width = saveRect.maxx - saveRect.minx;
    vramRow -= width;
    cursRow = CURSORWIDTH - width;
    savePtr = msp->cursor.rgb.save;
    cursPtr = msp->cursor.rgb.image[msp->frame];
    cursPtr += (saveRect.miny - msp->cursorRect.miny) * CURSORWIDTH +
	       (saveRect.minx - msp->cursorRect.minx);
    for (i = saveRect.maxy - saveRect.miny; i--; ) {
	for (j = width; j--; ) {
	    d = *vramPtr; *savePtr++ = d;
	    s = *cursPtr++;
	    if (s == 0)
		vramPtr++;
	    else {
		f = (~s) & (unsigned int)0x000F;
		if (f != 0)
		    s += (((((d & 0xF0F0)>>4)*f + 0x0F0F) & 0xF0F0) | ((((d & 0x0F0F)*f+0x0F0F)>>4) & 0x0F0F));
		*vramPtr++ = s;
	    }
	}
	cursPtr += cursRow;
	vramPtr = (volatile unsigned short *)((char *)vramPtr + vramRow + vramRow);
    }
    vid_disp_end = (unsigned int) (vramPtr + 1);
    vid_flush_flags |= 1;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_RemoveCursor */
/*
 * vid_C16_RemoveCursor erases the cursor by replacing the background image that
 * was saved by the previous call to vidDisplayCursor.
 *
 * Since the frame buffer is cacheable, flush at the end of the drawing
 * operation.
 */
 static void
vid_C16_RemoveCursor()
{
    Bounds saveRect = msp->saveRect;
    short i, j, width;
    unsigned int vramRow;
    volatile unsigned short *vramPtr;
    volatile unsigned short *savePtr;

    vramRow = km_coni.dspy_max_w;
    vramPtr = (unsigned short *)P_C16_VIDEOMEM + vramRow * (saveRect.miny - msp->screenBounds.miny) + (saveRect.minx - msp->screenBounds.minx);
    width = saveRect.maxx - saveRect.minx;
    vramRow -= width;
    savePtr = msp->cursor.rgb.save;
    vid_rem_start = (unsigned int) vramPtr;
    for (i = saveRect.maxy - saveRect.miny; i--; ) {
	for (j = width; j--; )
		*vramPtr++ = *savePtr++;
	vramPtr += vramRow;
    }
    vid_rem_end = (unsigned int) (vramPtr + 1);
    vid_flush_flags |= 2;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_SetBrightness */
/*
 * Set the brightness of the Warp 9C display.  Brightness is set by scaling the
 * contents of the LUT in the RAMDAC!
 *
 * This is derived from the BrookTree 463 manual.  Please
 * refer to the part manual for details on loading the CLUT.
 */
 static void
vid_C16_SetBrightness(unsigned int level)
{
	volatile unsigned char *dac0 = (volatile unsigned char *) P_C16_DAC_0;
	volatile unsigned char *dac1 = (volatile unsigned char *) P_C16_DAC_1;
	volatile unsigned char *dac3 = (volatile unsigned char *) P_C16_DAC_3;
	unsigned int scale = (level << 6) / 61;
	unsigned int idx = 0;
	unsigned int r, g, b;
	int i, j;

	for (i = 0; i < 16; i++) {
		r = (vid_gamma_r[i] * scale) >> 6;
		g = (vid_gamma_g[i] * scale) >> 6;
		b = (vid_gamma_b[i] * scale) >> 6;
		if (r > 255) r = 255;
		if (g > 255) g = 255;
		if (b > 255) b = 255;
		for (j = 0; j < 16; j++) {
			*dac0 = idx;
			*dac1 = (idx & 0xff00) >> 8;
			*dac3 = r;
			*dac3 = g;
			*dac3 = b;
			idx++;
		}
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_installIntr */
/*
 * Install a retrace interrupt handler that knows how to ack interrupts from
 * the installed frame buffer.  This handler will then call softint_run().
 */
 static void
vid_C16_installIntr()
{
	volatile unsigned char *cmd = (volatile unsigned char *) P_C16_CMD_REG;
	volatile int *p2 = (volatile int *)(SLOT_ID + 0x02200080);

	install_scanned_intr(0xd30, vid_C16_intr, (void *)0);
	if (dma_chip == 313)
		*cmd = 6;
	else
		*p2 = 0x06000000;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_intr */
/*
 * Ack the interrupt from the color frame buffer, and then transfer control to
 * the soft int package to run retrace time tasks.
 */
 static void
vid_C16_intr()
{
	volatile unsigned char *cmd = (volatile unsigned char *) P_C16_CMD_REG;
	volatile int *p2 = (volatile int *)(SLOT_ID + 0x02200080);

	if (dma_chip == 313)
		*cmd = 5;
	else
		*p2 = 0x05000000;
	if ( vidIntrFunc != (voidfptr_t) 0 )
		(*vidIntrFunc)( vidIntrFuncArg );
	if (dma_chip == 313)
		*cmd = 6;
	else
		*p2 = 0x06000000;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_SuspendAnim */
/*
 * Suspend and resume the boot animation, by disabling and enabling the
 * vertical retrace interrupt.
 */
 static void
vid_C16_SuspendAnim()
{
	extern		struct mon_global *mon_global;
	struct		mon_global *mg = mon_global;

	if (curipl() <= 2) {
		*MG (char*, MG_flags) &= ~MGF_ANIM_RUN;
		vidBW2Suspended = 1;
		DELAY (100000);
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_C16_ResumeAnim */
 static void
vid_C16_ResumeAnim()
{
	extern		struct mon_global *mon_global;
	struct		mon_global *mg = mon_global;

	if (vidBW2Suspended) {
		vidBW2Suspended = 0;
		*MG (char*, MG_flags) |= MGF_ANIM_RUN;
		if (!(km.flags & KMF_SEE_MSGS) && !console_o &&
		    *MG (short *, 780) > 23 && *MG (int *, 782))
			callout_dispatch(2, *MG (int *, 782), 0);
	}
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_ev_hide (with its macros) */
#define VID_MIN(a, b)	(((a) < (b)) ? (a) : (b))
#define VID_MAX(a, b)	(((a) > (b)) ? (a) : (b))

#define VID_CACHE_FLUSH() \
    if (vid_flush_flags == 3) \
	cache_flush(VID_MIN(vid_disp_start, vid_rem_start), VID_MAX(vid_disp_end, vid_rem_end), 0); \
    else if (vid_flush_flags == 2) \
	cache_flush(vid_rem_start, vid_rem_end, 0); \
    else if (vid_flush_flags == 1) \
	cache_flush(vid_disp_start, vid_disp_end, 0)

#define VID_HIDE() \
    if (!msp->cursorShow++) \
	(*video_dev[vidFBnum].RemoveCursor)()

#define VID_SHOW() \
    if (msp->cursorShow) \
	if (!--msp->cursorShow) { \
	    { Point spot = msp->hotSpot[msp->frame]; \
	    msp->cursorRect.maxx = (msp->cursorRect.minx = \
		msp->cursorLoc.x - spot.x) + CURSORWIDTH; \
	    msp->cursorRect.maxy = (msp->cursorRect.miny = \
		msp->cursorLoc.y - spot.y) + CURSORHEIGHT; } \
	    (*video_dev[vidFBnum].DisplayCursor)(); \
	    msp->oldCursorRect = msp->cursorRect; \
	}

#define VID_SHIELD() \
    if (msp->shieldFlag) { \
	int intersect; \
	Bounds tempRect; \
	{ Point spot = msp->hotSpot[msp->frame]; \
	tempRect.maxx = (tempRect.minx = \
	    msp->cursorLoc.x - spot.x) + CURSORWIDTH; \
	tempRect.maxy = (tempRect.miny = \
	    msp->cursorLoc.y - spot.y) + CURSORHEIGHT; } \
	intersect = (tempRect.minx < msp->shieldRect.maxx && \
		     tempRect.maxx > msp->shieldRect.minx && \
		     tempRect.miny < msp->shieldRect.maxy && \
		     tempRect.maxy > msp->shieldRect.miny); \
	if (intersect != msp->shielded) { \
	    if (msp->shielded = intersect) { VID_HIDE(); } else { VID_SHOW(); } \
	} \
    }

 static int
vid_ev_hide(EvScreen *es)
{
    vid_flush_flags = 0;
    if (msp->cursorSema)
	return 1;
    msp->cursorSema = 1;
    VID_HIDE();
    msp->cursorSema = 0;
    VID_CACHE_FLUSH();
    return 0;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_ev_show */
 static int
vid_ev_show(EvScreen *es, Point loc, int frame)
{
    vid_flush_flags = 0;
    if (msp->cursorSema)
	return 1;
    msp->cursorSema = 1;
    msp->frame = frame;
    msp->cursorLoc = loc;
    VID_SHIELD();
    VID_SHOW();
    msp->cursorSema = 0;
    VID_CACHE_FLUSH();
    return 0;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_ev_move */
 static int
vid_ev_move(EvScreen *es, Point loc, int frame)
{
    vid_flush_flags = 0;
    if (msp->cursorSema)
	return 1;
    msp->cursorSema = 1;
    msp->frame = frame;
    msp->cursorLoc = loc;
    VID_HIDE();
    if (msp->cursorObscured) {
	msp->cursorObscured = 0;
	if (msp->cursorShow)
	    --msp->cursorShow;
    }
    VID_SHIELD();
    VID_SHOW();
    msp->cursorSema = 0;
    VID_CACHE_FLUSH();
    return 0;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vid_ev_level */
 static int
vid_ev_level(EvScreen *es, int level)
{
    vidSetBrightness(level);
    return 0;
}
/* plan 761 END */

/* plan 761 (D024, D171) BEGIN: vidRegisterScreen */
 static int
vidRegisterScreen()
{
    EvScreen *es;

    vid_screen_token = ev_register_screen(&es, 0, vid_ev_move, vid_ev_hide,
	vid_ev_show, vid_ev_level);
    if (vid_screen_token < 0)
	return ENXIO;
    msp = (vidShmemStruct *) es->shmemPtr;
    bzero(msp, es->shmemSize);
    msp->cursorShow = 1;
    msp->screenBounds = es->bounds;
    return 0;
}
/* plan 761 END */
