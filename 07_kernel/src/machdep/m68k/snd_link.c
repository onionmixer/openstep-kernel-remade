/* 
 * Copyright (c) 1988 NeXT, Inc.
 */
/*
 * HISTORY
 *  9-Oct-90  Gregg Kellogg (gk) at NeXT
 *	Fixed bug causing linked streams of different dma sizes to
 *	properly pause and resume.
 *
 * 25-Sep-90  Gregg Kellogg (gk) at NeXT
 *	Made pausing a stream work for streams that are linked.
 *
 *  7-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Re-worked the interface so that the size of the DSP DMA buffers can be
 *	greater or smaller than the sound buffers.  Before this only worked
 *	for DSP DMA buffers smaller than the sound buffers.
 *
 *  1-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Take number of dma descriptors from stream, not constant.
 *
 * 14-May-90  Gregg Kellogg (gk) at NeXT
 *	Changed to use us_timeout instead of timeout, as these can be
 *	called at levels > spl3().
 *
 * 10-Dec-88  Gregg Kellogg (gk) at NeXT
 *	Created.
 *
 */ 

/*
 * plan 756 (D169, D013, D024, D104): the 1997 m68k snd_link.c.
 * NeXTMach mk-108.1 nextdev/snd_link.c with the include lines in the OPENSTEP paths
 * the 1997 unit needs and these changes, written from the original bytes
 * [0x40842fe, 0x408503e) (plans 755-756):
 *	functions that differ from NeXTMach: snd_link_init, snd_link_reset, snd_link_shutdown, snd_link_resume, snd_link_dsp_complete, snd_link_snd_complete
 *	new function: snd_link_abort (clears the static link_active)
 *	snd_link_snd_complete is an external symbol (NeXTMach: static)
 *	ll_snd_var is not used any more: the dma sizes and the number of buffers
 *	come from the audio layer (names in <nextdev/snd_audio.h>, this project's
 *	declarations), the owner of the stream from snd_get_owner(), the start of
 *	a sound-out buffer is __NXAudioPlayStream() instead of snd_device_start()
 *	and the dsp queue is started through cdp->sndq.start
 *	(see the marked regions).
 * The original has no symbols for its static data: the NeXTMach statics keep their
 * names; link_stream, link_active, size, count, rate, device, owners and owner are
 * names given by this project (D169).  The duplicated link_thread store in
 * snd_link_shutdown, the empty-queue returns, the order of the statements in
 * snd_link_shutdown and the other forms marked plan 756 are forms that give the
 * original bytes, not evidence of the original source.  The file compiles with
 * the known warnings of the acceptance record (kfree and assert_wait argument
 * types, as NeXTMach).  Lines marked plan 756, and the lines of a plan 756
 * BEGIN/END region (which may include unchanged lines), differ from NeXTMach.
 */

#import <sound.h>
#import <dsp.h>
#if	NSOUND > 0 && NDSP > 0

/*
 * Special interface for sending dsp output directly to sound out.
 */

#import <kern/xpr.h>
#import <sys/buf.h>
#import <sys/param.h>
#import <mach/vm_param.h>	/* plan 756 (D104): NeXTMach <vm/vm_param.h> */
#import <sys/callout.h>
#import <sys/kernel.h>
#import <kern/sched_prim.h>
#import <vm/pmap.h>	/* plan 756 (D104): NeXTMach <next/pmap.h> */
#import <kernserv/m68k/us_timer.h>	/* plan 756 (D104): NeXTMach <next/us_timer.h> */
#import <nextdev/snd_var.h>
#import <nextdev/snd_dsp.h>
#import <nextdev/snd_snd.h>
#import <nextdev/snd_audio.h>	/* plan 756 (D169): this project's declarations of the audio layer names (07 nextdev/snd_audio.h) */

#import <machine/spl.h>

#if	XPR_DEBUG
extern int sdbgflag;
#define snd_dbug(f) {if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#define snd_dbug2(f) if (sdbgflag&2){if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#else	XPR_DEBUG
#define snd_dbug(f)
#define snd_dbug2(f)
#endif	XPR_DEBUG

extern snd_var_t snd_var;
extern dsp_var_t dsp_var;
/* plan 756 (D024, D169) BEGIN: declarations and data */
extern int sound_active;
extern void thread_timeout();	/* plan 756 (D024): K&R declaration, the 1997 headers do not declare it */
extern void callout_dispatch();	/* plan 756 (D124 form): the 1997 softint_sched */
/* plan 756 END */

static void snd_link_init_buf (
	snd_dma_desc_t	*ddp,
	vm_address_t	bufs,
	int		nbufs,
	int		buf_size,
	int		(*free)(snd_dma_desc_t *),
	caddr_t		ptr,
	queue_t		q);
static void snd_link_reset(int direction);
static int snd_link_dsp_complete(register snd_dma_desc_t *ddp);
/* plan 756 (D024, D169) BEGIN: declarations and data */
int snd_link_snd_complete(register snd_dma_desc_t *ddp);
/* plan 756 END */

static queue_head_t snd_ddp_q[2], dsp_ddp_q[2];
static queue_head_t snd_pause_q[2], dsp_pause_q[2];
static snd_region_t snd_link_dsp_reg[2];
static thread_t link_thread[2];
static vm_address_t bufs[2];
static vm_size_t buf_size[2];
static u_int snd_buf_count[2];
static u_int dsp_buf_count[2];
static caddr_t link_stream = 0;	/* plan 756 (D169): this project's name; __data 0x40b21d0 of the original */
static int link_active = 0;	/* plan 756 (D169): this project's name; __data 0x40b21d4 of the original */

/*
 * Link between the DSP and sound devices is used for sound-out only.
 * 
/*
 * Initialize the dsp - sound link.
 */
/* plan 756 (D024, D169) BEGIN: snd_link_abort, snd_link_init */
void snd_link_init(int direction)
{
	u_int size, count;
	snd_dma_desc_t *ddp, *ddp2;
	int s, dsp_buf_size, snd_buf_size;
	int small_buf_size, large_buf_size;
	struct chan_data *cdp = dsp_var.chan
		[direction == SND_DIR_PLAY ? DSP_SO_CHAN : DSP_SI_CHAN];
	int nbufs, buf_ratio;
	caddr_t device;
	queue_t owners;
	struct snd_owner *owner;

	ASSERT(curipl() == 0);
	snd_link_dsp_reg[direction].sound_q = &cdp->sndq;

	ASSERT(cdp);
	dsp_buf_size = cdp->sndq.dmasize;
	if (direction == SND_DIR_PLAY) {
		owners = &snd_var.sndout_owners;
		device = _NXAudioSndoutDevice;
	} else {
		owners = &snd_var.sndin_owners;
		device = _NXAudioSndinDevice;
	}
	(*__NXAudioGetBufferOptions)(device, &size, &count);
	snd_buf_size = size;
	owner = snd_get_owner(owners, snd_var.dspowner);
	if (owner == 0) {
		printf("SoundDSP: link could not get new stream owner\n");
		return;
	}
	link_stream = owner->stream;

	cdp->sndq.linked = TRUE;
	link_active = TRUE;

	if (dsp_buf_size < snd_buf_size) {
		small_buf_size = dsp_buf_size;
		large_buf_size = snd_buf_size;
	} else {
		small_buf_size = snd_buf_size;
		large_buf_size = dsp_buf_size;
	}
	buf_ratio = large_buf_size/small_buf_size;

	if (direction == SND_DIR_PLAY) {
		nbufs = count;
	} else {
		/*
		 * Take nbufs from dsp stream.
		 */
		nbufs = cdp->sndq.ndma;
	}
	buf_size[direction] = large_buf_size * nbufs;

	ASSERT(snd_buf_size <= PAGE_SIZE && snd_buf_size <= PAGE_SIZE);
	queue_init(&snd_ddp_q[direction]);
	queue_init(&dsp_ddp_q[direction]);
	queue_init(&snd_pause_q[direction]);
	queue_init(&dsp_pause_q[direction]);
	link_thread[direction] = 0;
	ddp = (snd_dma_desc_t *)kalloc(sizeof(snd_dma_desc_t)*nbufs);
	snd_dbug(("snd_link: ddp %d bytes at 0x%x\n", 
		sizeof(snd_dma_desc_t)*nbufs, ddp));
	ddp2 = (snd_dma_desc_t *)
		kalloc(sizeof(snd_dma_desc_t)*buf_ratio*nbufs);
	snd_dbug(("snd_link: ddp2 %d bytes at 0x%x\n", 
		sizeof(snd_dma_desc_t)*buf_ratio*nbufs, ddp2));
	bufs[direction] = (vm_address_t)
		kalloc(round_page(buf_size[direction]));
	snd_dbug(("snd_link: bufs[%d] %d bytes at 0x%x\n", direction,
		buf_size[direction], bufs[direction]));

	/*
	 * Initialize queued ddps and enqueue them.
	 */
	if (snd_buf_size == large_buf_size) {
		snd_link_init_buf(ddp, bufs[direction], nbufs, snd_buf_size,
			snd_link_snd_complete, (caddr_t)direction,
			&snd_ddp_q[direction]);
		snd_buf_count[direction] = nbufs;
		snd_link_init_buf(ddp2, bufs[direction], nbufs*buf_ratio,
			dsp_buf_size, snd_link_dsp_complete,
			(caddr_t)&snd_link_dsp_reg[direction],
			&dsp_ddp_q[direction]);
		dsp_buf_count[direction] = nbufs*buf_ratio;
	} else {
		snd_link_init_buf(ddp, bufs[direction], nbufs, dsp_buf_size,
			snd_link_dsp_complete,
			(caddr_t)&snd_link_dsp_reg[direction],
			&dsp_ddp_q[direction]);
		dsp_buf_count[direction] = nbufs;
		snd_link_init_buf(ddp2, bufs[direction], nbufs*buf_ratio,
			snd_buf_size, snd_link_snd_complete,
			(caddr_t)direction, &snd_ddp_q[direction]);
		snd_buf_count[direction] = nbufs*buf_ratio;
		(*__NXAudioSetBufferOptions)(device, 0, size,
			nbufs*buf_ratio);
	}
	(*__NXAudioInitLinkedStream)(link_stream);

	s = spldma();
	/*
	 * Start up dma.
	 */
	if (direction == SND_DIR_RECORD) {
		printf("SoundDSP: codec->dsp link broken\n");
	} else {
		/*
		 * Start up the dsp.
		 */
		while (!queue_empty(&dsp_ddp_q[direction])) {
			queue_remove_first(&dsp_ddp_q[direction], ddp,
				snd_dma_desc_t *, link);
			(*cdp->sndq.start)(ddp, SND_DIR_RECORD, 0);
		}
	}
	splx(s);
}

void snd_link_abort(void)
{
	link_active = FALSE;
}
/* plan 756 END */

static void snd_link_init_buf (
	snd_dma_desc_t	*ddp,
	vm_address_t	bufs,
	int		nbufs,
	int		buf_size,
	int		(*free)(snd_dma_desc_t *),
	caddr_t		ptr,
	queue_t		q)
{
	pmap_t k_pmap = (pmap_t)pmap_kernel();

	while (nbufs--) {
		ddp->vaddr = bufs;
		ddp->size = buf_size;
		ddp->ptr = ptr;
		ddp->free = free;
		ddp->hdr.dh_start = (char *)pmap_resident_extract(k_pmap,
						trunc_page(bufs))
				    + bufs%PAGE_SIZE;
		ddp->hdr.dh_stop = ddp->hdr.dh_start + buf_size;
		ddp->hdr.dh_drvarg = (int)ddp;
		queue_enter(q, ddp, snd_dma_desc_t *, link);
		ddp++;
		bufs += buf_size;
	}
}

/*
 * Release linkage resources
 */
/* plan 756 (D024, D169) BEGIN: snd_link_reset, snd_link_shutdown */
static void snd_link_reset(int direction)
{
	register snd_dma_desc_t *ddp, *first_ddp;
	struct chan_data *cdp = dsp_var.chan
		[direction == SND_DIR_PLAY ? DSP_SO_CHAN : DSP_SI_CHAN];
	int nbufs, req_bufs, s;

	ASSERT(curipl() == 0);

	s = spldma();
	/*
	 * Count up the number of dsp bufs.
	 */
	for (    nbufs = 0
	       , ddp = (snd_dma_desc_t *)queue_first(&dsp_ddp_q[direction])
	       , first_ddp = ddp
	     ; !queue_end(&dsp_ddp_q[direction], (queue_t)ddp)
	     ; nbufs++, ddp = (snd_dma_desc_t *)queue_next(&ddp->link))
		if (ddp < first_ddp)
			first_ddp = ddp;

	splx(s);

	ddp = first_ddp;
	req_bufs = dsp_buf_count[direction];
	if (nbufs && req_bufs == nbufs) {
		/*
		 * We can free the ddps, everything's in.
		 */
		kfree(ddp, nbufs * sizeof(*ddp));
		snd_dbug(("snd_link_reset: free %d bytes at 0x%x (dsp ddps)\n",
			nbufs * sizeof(*ddp), ddp));
		queue_init(&dsp_ddp_q[direction]);
		dsp_buf_count[direction] = 0;
	} else
		snd_dbug(("snd_link_reset: dsp bufs %d != req bufs %d\n",
			nbufs, req_bufs));

	s = spldma();
	/*
	 * Count up the number of sound bufs.
	 */
	for (    nbufs = 0
	       , ddp = (snd_dma_desc_t *)queue_first(&snd_ddp_q[direction])
	       , first_ddp = ddp
	     ; !queue_end(&snd_ddp_q[direction], (queue_t)ddp)
	     ; nbufs++, ddp = (snd_dma_desc_t *)queue_next(&ddp->link))
		if (ddp < first_ddp)
			first_ddp = ddp;

	splx(s);

	ddp = first_ddp;
	req_bufs = snd_buf_count[direction];
	if (nbufs && req_bufs == nbufs) {
		/*
		 * We can free the ddps, everything's in.
		 */
		kfree(ddp, nbufs * sizeof(*ddp));
		snd_dbug(("snd_link_reset: free %d bytes at 0x%x (snd ddps)\n",
			nbufs * sizeof(*ddp), ddp));
		queue_init(&snd_ddp_q[direction]);
		snd_buf_count[direction] = 0;
	} else
		snd_dbug(("snd_link_reset: snd bufs %d != req bufs %d\n",
			nbufs, req_bufs));

	/*
	 * Free up the buffer's when everything's in.
	 */
	if (snd_buf_count[direction] == 0 && dsp_buf_count[direction] == 0
	    && bufs[direction] && buf_size[direction]) {
		kfree(bufs[direction], round_page(buf_size[direction]));
		snd_dbug(("snd_link_reset: free %d bytes at 0x%x (bufs)\n",
			round_page(buf_size[direction]), bufs[direction]));
		bufs[direction] = 0;
		buf_size[direction] = 0;

		/*
		 * cdp may have been freed if we're shutting down.
		 */
		if (cdp)
			cdp->sndq.linked = FALSE;
	}
}

/*
 * Wait for sound to underrun/overrun
 */
void snd_link_shutdown(int direction)
{
	int s, ndma, i;
	snd_dma_desc_t *ddp;
	snd_queue_t *q;

	ASSERT(curipl() == 0);
	snd_dbug(("snd_link_shutdown: reset dir %d\n", direction));
	s = splsound();
	link_thread[direction] = current_thread();
	if (direction == SND_DIR_PLAY) {
		ndma = 0;
		if (link_active) {
			i = 0;
			do {
				assert_wait(0, TRUE);
				thread_set_timeout(hz/2);
				thread_block();
				untimeout(thread_timeout, current_thread());
			} while (sound_active && ++i <= 3);
		}
	} else {
		link_thread[direction] = current_thread();
		ndma = dsp_var.chan[DSP_SI_CHAN]->sndq.ndma;
		q = &dsp_var.chan[DSP_SI_CHAN]->sndq;
	}

	/*
	 * Free ddps from paused queues.
	 */
	while (!queue_empty(&snd_pause_q[direction])) {
		queue_remove(&snd_pause_q[direction], ddp,
			snd_dma_desc_t *, link);
		queue_enter(&snd_ddp_q[direction], ddp,
			snd_dma_desc_t *, link);
	}
	while (!queue_empty(&dsp_pause_q[direction])) {
		queue_remove(&dsp_pause_q[direction], ddp,
			snd_dma_desc_t *, link);
		queue_enter(&dsp_ddp_q[direction], ddp,
			snd_dma_desc_t *, link);
	}

	if (ndma) {
		/*
		 * Wait for all dma's to complete.
		 */
		snd_dbug(("snd_link_shutdown: await %d dmas dir %d\n",
			ndma, direction));
		assert_wait((int)q, TRUE);
		thread_set_timeout(hz);
		thread_block();
		untimeout(thread_timeout, current_thread());
	}
	link_thread[direction] = 0;
	splx(s);
	snd_link_reset(direction);
}
/* plan 756 END */

/*
 * Pause data on a linked stream.
 */
void snd_link_pause(snd_queue_t *q)
{
	/*
	 * This is done implicitly when before data's passed on to the
	 * queue by looking at the paused bit.
	 */
	snd_dbug(("sl_pause: pausing queue 0x%x\n", q));
}

/*
 * Resume a paused stream that's linked.
 */
/* plan 756 (D024, D169) BEGIN: snd_link_dsp_complete, snd_link_resume, snd_link_snd_complete */
void snd_link_resume(snd_queue_t *q)
{
	int direction, s;
	snd_dma_desc_t *ddp;

	snd_dbug(("sl_resume: resuming queue 0x%x\n", q));

	/*
	 * Start up data waiting to be sent to this stream.
	 * Only start buffers that have counter parts in both queues.
	 */
	s = spldma();
	if (q == snd_link_dsp_reg[SND_DIR_PLAY].sound_q) {
		direction = SND_DIR_PLAY;
		while (!queue_empty(&dsp_pause_q[direction])) {
			queue_remove_first(&dsp_pause_q[direction], ddp,
				snd_dma_desc_t *, link);
			(*q->start)(ddp, 1-direction, 0);
		}
	} else if (q == snd_link_dsp_reg[SND_DIR_RECORD].sound_q) {
		snd_dbug2(("sl_resume: q dsp record\n", q));
		direction = SND_DIR_RECORD;
		while (!queue_empty(&dsp_pause_q[direction])) {
			queue_remove_first(&dsp_pause_q[direction], ddp,
				snd_dma_desc_t *, link);
			(*q->start)(ddp, 1-direction, 0);
		}
	}
	splx(s);
}

/*
 * Completion routine called when a dsp buffer is complete.
 */
static int snd_link_dsp_complete(register snd_dma_desc_t *ddp)
{
	snd_dma_desc_t *ddp2;
	int direction;
	int s, rate;

	if (&snd_link_dsp_reg[SND_DIR_PLAY] == (snd_region_t *)ddp->ptr)
		direction = SND_DIR_PLAY;
	else
		direction = SND_DIR_RECORD;


	/*
	 * If this is the last buffer in a series, start up the
	 * sound-out buffer.
	 */
	snd_dbug2(("sl_dsp_comp: ddp 0x%x done\n",ddp));
	s = spldma();
	queue_enter(&dsp_ddp_q[direction], ddp, snd_dma_desc_t *, link);

	/*
	 * Closing down, don't send anything on to sound out.
	 */
	if (   (direction == SND_DIR_PLAY && !(dsp_var.flags&F_LINKEDOUT))
	    || (direction == SND_DIR_RECORD && !(dsp_var.flags&F_LINKEDIN)))
	{
		splx(s);
		callout_dispatch(CALLOUT_PRI_THREAD, snd_link_reset, direction);
		return 0;
	}

	if (queue_empty(&snd_ddp_q[direction])) {
		splx(s);
		return 0;
	}
	ddp2 = (snd_dma_desc_t *)queue_first(&snd_ddp_q[direction]);

	if (ddp->size > ddp2->size) {
		/*
		 * Send down the corresponding sound descriptors
		 */
		while (!queue_empty(&snd_ddp_q[direction])) {
			queue_remove_first(&snd_ddp_q[direction], ddp2,
				snd_dma_desc_t *, link);
			if (  ddp2->hdr.dh_start < ddp->hdr.dh_start
			    || ddp2->hdr.dh_stop > ddp->hdr.dh_stop)
			{
				snd_dbug2(("sl_dsp_comp: don't start ddp2 "
					"0x%x\n", ddp2));
				queue_enter_first(&snd_ddp_q[direction], ddp2,
					snd_dma_desc_t *, link);
				break;
			}
				snd_dbug2(("sl_dsp_comp: snd_q paused, "
					"add ddp %d to pause queue\n", ddp2));
			splx(s);

			rate = (dsp_var.flags&F_MODE_SND_HIGH) ? 2 : 1;
			if ((*__NXAudioPlayStream)(link_stream,
				ddp2->hdr.dh_start,
				ddp2->hdr.dh_stop - ddp2->hdr.dh_start,
				ddp2, 2,
				rate,
				0x8000, 0x8000, 0, 0, 0, 0))
			{
				snd_dbug2(("sl_dsp_comp: snd_device_start "
					"failed, req ddp2 0x%x\n", ddp2));
				s = spldma();
				queue_enter_first(&snd_ddp_q[direction], ddp2,
					snd_dma_desc_t *, link);
				break;
			}
			s = spldma();
		}
		splx(s);
	} else {
		queue_remove_first(&snd_ddp_q[direction], ddp2,
			snd_dma_desc_t *, link);

		/*
		 * If this is the last buffer in a series, send down
		 * the next sound descriptor.
		 */
		if (ddp2->hdr.dh_stop == ddp->hdr.dh_stop) {
			snd_dbug2(("sl_dsp_comp: snd_q paused, "
				"add ddp %d to pause queue\n", ddp2));
			splx(s);
			rate = (dsp_var.flags&F_MODE_SND_HIGH) ? 2 : 1;
			if ((*__NXAudioPlayStream)(link_stream,
				ddp2->hdr.dh_start,
				ddp2->hdr.dh_stop - ddp2->hdr.dh_start,
				ddp2, 2,
				rate,
				0x8000, 0x8000, 0, 0, 0, 0))
			{
				s = spldma();
				queue_enter_first(&snd_ddp_q[direction], ddp2,
						snd_dma_desc_t *, link);
				splx(s);
			}
		} else {
			queue_enter_first(&snd_ddp_q[direction], ddp2,
					snd_dma_desc_t *, link);
			splx(s);
			snd_dbug2(("sl_dsp_comp: requeue ddp2  0x%x\n", ddp2));
		}
	}

	return 1;
}

int snd_link_snd_complete(register snd_dma_desc_t *ddp)
{
	register snd_dma_desc_t *ddp2;
	int direction = (int)ddp->ptr;
	struct chan_data *cdp = dsp_var.chan
		[direction == SND_DIR_PLAY ? DSP_SO_CHAN : DSP_SI_CHAN];
	int s;
	int r = 1;

	snd_dbug2(("sl_snd_comp: ddp 0x%x done\n", ddp));
	/*
	 * If this is the last buffer in a series, start up the
	 * sound-out buffer.
	 */
	s = spldma();
	queue_enter(&snd_ddp_q[direction], ddp, snd_dma_desc_t *, link);

	/*
		/*
		 * Wait for all dma's to complete.
		 */

	/*
	 * Closing down, don't send anything on to sound out.
	 */
	if (   (direction == SND_DIR_PLAY && !(dsp_var.flags&F_LINKEDOUT))
	    || (direction == SND_DIR_RECORD && !(dsp_var.flags&F_LINKEDIN)))
	{
		splx(s);
		callout_dispatch(CALLOUT_PRI_THREAD, snd_link_reset, direction);
		return 0;
	}

	if (queue_empty(&dsp_ddp_q[direction])) {
		splx(s);
		return 0;
	}
	ddp2 = (snd_dma_desc_t *)queue_first(&dsp_ddp_q[direction]);

	if (ddp->size > ddp2->size) {
		/*
		 * Send down the corresponding dsp descriptors
		 */
		while (!queue_empty(&dsp_ddp_q[direction])) {
			queue_remove_first(&dsp_ddp_q[direction], ddp2,
				snd_dma_desc_t *, link);
			if (  ddp2->hdr.dh_start < ddp->hdr.dh_start
			    || ddp2->hdr.dh_stop > ddp->hdr.dh_stop)
			{
				snd_dbug2(("sl_snd_comp: don't start ddp2 "
					"0x%x\n", ddp2));
				queue_enter_first(&dsp_ddp_q[direction], ddp2,
					snd_dma_desc_t *, link);
				break;
			}
			/*
			 * Don't start up a paused stream.
			 */
			if (cdp->sndq.paused) {
				snd_dbug2(("sl_snd_comp: q paused, "
					"add ddp %d to pause queue\n", ddp2));
				queue_enter(&dsp_pause_q[direction],
					ddp2, snd_dma_desc_t *, link);
				break;
			}
			splx(s);
			snd_dbug2(("sl_snd_comp: start ddp 0x%x\n",ddp2));
			r = (*cdp->sndq.start)(ddp2, 1-direction, 0);
			if (!r) {
				snd_dbug2(("sl_snd_comp: (*cdp->sndq.start) "
					"failed, req ddp2 0x%x\n", ddp2));
				s = spldma();
				queue_enter_first(&dsp_ddp_q[direction], ddp2,
					snd_dma_desc_t *, link);
				break;
			}
			s = spldma();
		}
		splx(s);
	} else {
		/*
		 * If this is the last buffer in a series, send down
		 * the next dsp descriptor.
		 */
		queue_remove_first(&dsp_ddp_q[direction], ddp2,
			snd_dma_desc_t *, link);

		if (ddp2->hdr.dh_stop == ddp->hdr.dh_stop) {
		    if (cdp->sndq.paused) {
			snd_dbug2(("sl_snd_comp: q paused, "
				"add ddp %d to pause queue\n", ddp2));
			queue_enter(&dsp_pause_q[direction],
				ddp2, snd_dma_desc_t *, link);
		    } else {
			splx(s);
			snd_dbug2(("sl_snd_comp: start ddp2 0x%x\n", ddp2));
			r = (*cdp->sndq.start)(ddp2, 1-direction, 0);
			if (!r) {
				snd_dbug2(("sl_snd_comp: (*cdp->sndq.start) "
					"failed, req ddp2 0x%x\n", ddp2));
				s = spldma();
				queue_enter_first(&snd_ddp_q[direction], ddp2,
						snd_dma_desc_t *, link);
				splx(s);
			}
		    }
		} else {
			queue_enter_first(&dsp_ddp_q[direction], ddp2,
				snd_dma_desc_t *, link);
			splx(s);
			snd_dbug2(("sl_snd_comp: requeue ddp2 0x%x\n", ddp2));
		}
	}
	
	return r;
}
/* plan 756 END */

#endif	NSOUND > 0 && NDSP > 0
