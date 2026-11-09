/* 
 * Copyright (c) 1988 NeXT, Inc.
 */
/*
 * HISTORY
 *
 *  20-Jul-90 Matt Christiano (mchristo) at NeXT
 *	Fixed ramping so that it would happen.
 *	Fixed snd_ramp() to ramp in the proper direction.
 *	Added snd_device_set_ramp function to selectively disable up/down
 *	ramps.
 *
 *  3-Oct-89  Gregg Kellogg (gk) at NeXT
 *	If the ramp buffer wasn't allocated a ramp can't be computed.  Changes
 *	were made to ensure that a ramp is calculated only if a buffer was
 *	allocated.
 *
 * 10-Dec-88  Gregg Kellogg (gk) at NeXT
 *	Created.
 *
 */ 

/*
 * plan 556 (D124, D103, D104, D110, D113, D024): the 1997 m68k snd_device.c.
 * NeXTMach mk-108.1 nextdev/snd_device.c with the include lines in OPENSTEP
 * paths and the 1997 bodies written from the original bytes [0x407ff14,
 * 0x4080556) (plan 555).  Per function:
 *   snd_device_set_volume, snd_device_get_volume, snd_vol_save,
 *   snd_device_probe, snd_device_def_dmasize, snd_device_def_high_water,
 *   snd_device_def_low_water: NeXTMach text unchanged;
 *   snd_device_init: NeXTMach first part only (no queue set-up, no ramp
 *   buffer); snd_device_set_parms, snd_device_get_parms: NeXTMach without
 *   the zero-fill parameter; snd_vol_set: NeXTMach with the new 1997 path
 *   for mon_rev != 0 written from the bytes; snd_device_vol_set,
 *   snd_device_vol_save: callout_dispatch instead of softint_sched;
 *   snd_dev_intr: written from the bytes (external, prints and resets the
 *   monitor csr); snd_device_attach: NeXTMach without the DMA set-up.
 * Removed (not in the original bytes): snd_device_reset,
 * snd_device_set_ramp, snd_dma_intr, snd_ovr, snd_device_start, snd_start,
 * snd_shutdown, mon_send_nodma, snd_ramp, their static prototypes and
 * SO_JUMP_WAIT.  mon_rev is declared by <m68k/cpu.h>.  Lines marked plan 556
 * differ from NeXTMach.
 */
#import <sound.h>
#if	NSOUND > 0

/*
 * Sound Out/In device driver
 */

#import <kern/xpr.h>
#import <sys/buf.h>
#import <sys/param.h>
#import <kern/thread.h>
#import <sys/callout.h>
#import <mach/vm_param.h>	/* plan 556 (D104): NeXTMach <vm/vm_param.h> */
#import <m68k/cpu.h>	/* plan 556 (D110): NeXTMach <next/cpu.h> */
#import <vm/pmap.h>	/* plan 556 (D104): NeXTMach <next/pmap.h> */
#import <dev/busvar.h>	/* plan 556 (D104): NeXTMach <nextdev/busvar.h> */
#import <nextdev/snd_snd.h>
#import <dev/m68k/monreg.h>	/* plan 556 (D104): NeXTMach <nextdev/monreg.h> */
#import <mon/nvram.h>

#import <machine/spl.h>

/* plan 556 (D124, D113): the NeXTMach next/cpu.h names this file needs */
extern int slot_id;
#define	SLOT_ID		slot_id
#define	P_MON		(SLOT_ID+0x0200e000)
#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_SOUND_OVRUN	I(3,5,8)

/* plan 556 (D124, D024): 1997 function this file calls (no declaration in the headers it imports) */
extern void callout_dispatch();

/* Let everyone else know our status */
extern int sound_active;

extern snd_var_t snd_var;
ll_snd_var_t ll_snd_var;

/* interrupt vectors */
void snd_dev_intr(void);	/* plan 556 (D124): external in 1997 (NeXTMach static) */

/* misclanioius routines */
static void snd_vol_set(void);
static void snd_vol_save(void);

/* Local Storage */
static volatile struct monitor *mon;
volatile int vol_r = -1, vol_l = -1, gpflags;
static int ni_spkren, ni_lowpass, ni_vol_r, ni_vol_l;

/* autoconfiguration */
int snd_device_probe(caddr_t addr, register int unit);
int snd_device_attach(register struct bus_device *bd);

struct bus_device	*sound_dinfo[NSOUND];
struct bus_driver	 sounddriver = {
	snd_device_probe, 0, snd_device_attach, 0, 0,
	(int (*)())snd_dev_intr, 0, 0, "sound", sound_dinfo
};

#if	XPR_DEBUG
int sdbgflag;
#define snd_dbug(f) {if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#define snd_dbug2(f) if (sdbgflag&2){if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#else	XPR_DEBUG
#define snd_dbug(f)
#define snd_dbug2(f)
#endif	XPR_DEBUG

/*
 * Initialize volume/speaker from nvram (first time)
 * plan 556 (D124): only the NeXTMach volume part is left in 1997.
 */
void snd_device_init(int direction)
{
	struct nvram_info ni;

	if (direction == SND_DIR_PLAY && vol_r == -1) {
		/*
		 * Make sure volume is properly initialized.
		 */
		nvram_check(&ni);
		vol_r = ni.ni_vol_r;
		vol_l = ni.ni_vol_l;
		ni_vol_r = -1;
		ni_vol_l = -1;

		gpflags = 0;
		if (ni.ni_spkren) {
			gpflags |= SGP_SPKREN;
			ni_spkren = 0;
		} else
			ni_spkren = 1;
		if (ni.ni_lowpass) {
			gpflags |= SGP_LOWPASS;
			ni_lowpass = 0;
		} else
			ni_lowpass = 1;

		snd_vol_set();
	}
}

/*
 * Set sound device parameters, such as low-pass filter and speaker enable.
 * plan 556 (D124): no zero-fill parameter in 1997.
 */
void snd_device_set_parms(u_int parms)
{
	/* enable the speaker (bit-sense backwards) */
	if (parms&SND_PARM_SPEAKER)
		gpflags &= ~SGP_SPKREN;
	else
		gpflags |= SGP_SPKREN;

	/* Enable Low Pass Filter */
	if (parms&SND_PARM_LOWPASS)
		gpflags |= SGP_LOWPASS;
	else
		gpflags &= ~SGP_LOWPASS;

	/*
	 * If the parameters have actually change, reflect the change.
	 */
	if (ll_snd_var.gpflags != gpflags) {
		snd_vol_set();
		snd_vol_save();
	}
}

/*
 * Return sound device parameters.
 * plan 556 (D124): no zero-fill parameter in 1997.
 */
u_int snd_device_get_parms(void)
{
	register u_int parms;

	parms = (gpflags&SGP_LOWPASS) ? SND_PARM_LOWPASS : 0;
	parms |= (gpflags&SGP_SPKREN) ? 0 : SND_PARM_SPEAKER;

	return parms;
}

/*
 * Set the volume of both right and left channels (simplification if they're
 * the same).  The value(s) passed is inverted from the sense the hardware
 * understands (attinuation, rather than volume).
 */
void snd_device_set_volume(u_int volume)
{
	vol_l=  VOLUME_MAX
	      - ((volume&SND_VOLUME_LCHAN_MASK)>>SND_VOLUME_LCHAN_SHIFT);
	vol_r=  VOLUME_MAX
	      - ((volume&SND_VOLUME_RCHAN_MASK)>>SND_VOLUME_RCHAN_SHIFT);
	snd_vol_set();
	snd_vol_save();
}


/*
 * Return volume of both right and left channels.
 */
u_int snd_device_get_volume(void)
{

	return    ((VOLUME_MAX-vol_l)<<SND_VOLUME_LCHAN_SHIFT)
		| ((VOLUME_MAX-vol_r)<<SND_VOLUME_RCHAN_SHIFT);
}

/*
 * Thread to set volume/attributs.  We do this here, as it can take
 * a very long time.
 */
static void snd_vol_set(void)
{
	register int flags, bits, i;

	ni_spkren = (gpflags&SGP_SPKREN) == SGP_SPKREN;
	ni_lowpass = (gpflags&SGP_LOWPASS) == SGP_LOWPASS;
	snd_dbug(("snd_vol_set vol_r %x, vol_l %x, gpflags %x\n",
		   vol_r, vol_l, gpflags, 0, 0, 0, 0, 0, 0));
	ll_snd_var.gpflags = gpflags;

	if (vol_r == ni_vol_r && vol_l == ni_vol_l)
		mon_send(MON_GP_OUT, ll_snd_var.gpflags<<24);
	else {
		vol_r &= VOLUME_MASK;
		vol_l &= VOLUME_MASK;
		if (mon_rev) {	/* plan 556 (D124, D024): 1997 path from the original bytes */
			mon_send(MON_GP_OUT, ll_snd_var.gpflags<<24);
			DELAY(200);
			/* 0xc2: 1997 monitor command, no name in monreg.h */
			if (vol_r == vol_l)
				mon_send(0xc2, (VOLUME_RCHAN|VOLUME_LCHAN|vol_r)<<24);
			else {
				mon_send(0xc2, (VOLUME_RCHAN|vol_r)<<24);
				DELAY(200);
				mon_send(0xc2, (VOLUME_LCHAN|vol_l)<<24);
			}
			DELAY(200);
			ni_vol_r = vol_r;
			ni_vol_l = vol_l;
		} else
			flags = ll_snd_var.gpflags<<24;
	}

	while (vol_r != ni_vol_r || vol_l != ni_vol_l) {
		if (vol_r == vol_l) {
			bits = 0x700 | VOLUME_RCHAN
				| VOLUME_LCHAN | vol_r;
			ni_vol_r = vol_r;
			ni_vol_l = vol_l;
		} else if (vol_r != ni_vol_r) {
			bits = 0x700 | VOLUME_RCHAN | vol_r;
			ni_vol_r = vol_r;
		} else {
			bits = 0x700 | VOLUME_LCHAN | vol_l;
			ni_vol_l = vol_l;
		}

		/*
		 * Set volume control port to 0
		 */
		mon_send(MON_GP_OUT, flags);
		DELAY(200);

		/*
		 * shift out the bits one at a time.
		 */
		for (i = 10; i >= 0; i--) {
			mon_send(MON_GP_OUT,
				 flags
				 | ((bits&(1<<i))
					?(SGP_VSCD<<24):0));
			DELAY(200);
			mon_send(MON_GP_OUT,
				 flags
				 | ((bits&(1<<i))?(SGP_VSCD<<24):0)
				 | (SGP_VSCCK<<24));
			DELAY(200);
		}

		/*
		 * strobe the data
		 */
		mon_send(MON_GP_OUT, flags);
		DELAY(200);
		mon_send(MON_GP_OUT, flags | (SGP_VSCS<<24));
		DELAY(200);
		mon_send(MON_GP_OUT, flags);
		DELAY(200);
	}
}

void snd_device_vol_set(void)
{
	callout_dispatch(CALLOUT_PRI_THREAD, snd_vol_set, 0);	/* plan 556 (D124): NeXTMach softint_sched */
}

/*
 * Save out modified volume parameters.
 */
static void snd_vol_save(void)
{
	struct nvram_info ni;

	nvram_check(&ni);
	ni.ni_vol_r = ni_vol_r;
	ni.ni_vol_l = ni_vol_l;
	ni.ni_lowpass = ni_lowpass;
	ni.ni_spkren = ni_spkren;
	nvram_set(&ni);
}

void snd_device_vol_save(void)
{
	callout_dispatch(CALLOUT_PRI_THREAD, snd_vol_save, 0);	/* plan 556 (D124): NeXTMach softint_sched */
}

/*
 * plan 556 (D124, D024): 1997 overrun interrupt, written from the original
 * bytes (0x4080404).
 */
void snd_dev_intr(void)
{
	printf("SoundDSP: snd_dev_intr called!\n");
	mon_csr_and(~(DMAOUT_DMAEN>>24));
	mon_csr_or(DMAOUT_OVR>>24);
	mon_csr_and(~(DMAIN_DMAEN>>24));
	mon_csr_or(DMAIN_OVR>>24);

	mon_send(MON_SNDIN_CTRL(0), 0);
	mon_send(MON_SNDOUT_CTRL(0), 0);
	mon_send(MON_GP_OUT, 0xff);
}

/*
 * Check to see if there's a device there (of course there is!)
 */
int snd_device_probe(caddr_t addr, register int unit)
{
	if (unit != 0) return (0);
	addr += slot_id;
	return((int)addr);
}

/*
 * Attach to this device.
 */
int snd_device_attach(register struct bus_device *bd)
{
	mon = (struct monitor *)P_MON;

	/* Initialize csr */
	mon_csr_and(~(DMAOUT_DMAEN>>24));
	mon_csr_or(DMAOUT_OVR>>24);
	mon_csr_and(~(DMAIN_DMAEN>>24));
	mon_csr_or(DMAIN_OVR>>24);

	mon_send(MON_SNDIN_CTRL(0), 0);
	mon_send(MON_SNDOUT_CTRL(0), 0);
	mon_send(MON_GP_OUT, 0xff);

	/* plan 556 (D124): no DMA channel set-up in 1997 */

	/* enable interrupts */
	install_scanned_intr (I_SOUND_OVRUN, (int (*)())snd_dev_intr, 0);

	return(0);
}

int snd_device_def_dmasize(int direction)
{
	return direction == SND_DIR_PLAY ? PAGE_SIZE : 256;
}
int snd_device_def_high_water(int direction)
{
	return direction == SND_DIR_PLAY
		? SND_DEF_HIGH_WATER_HIGH
		: SND_DEF_HIGH_WATER_LOW;
}

int snd_device_def_low_water(int direction)
{
	return direction == SND_DIR_PLAY
		? SND_DEF_LOW_WATER_HIGH
		: SND_DEF_LOW_WATER_LOW;
}
#endif	NSOUND > 0
