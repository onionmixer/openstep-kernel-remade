/*	@(#)dma.c	1.0	08/12/87	(c) 1987 NeXT	*/
#define	CHAIN_READ	0

/* 
 **********************************************************************
 * HISTORY
 * 22-Aug-90  John Seamons (jks) at NeXT
 *	Added direction argument to dma_sync_cache.  It now calls
 *	cache_push_page for writes and cache_inval_page for reads.
 *	This is the same as it was a few versions ago.
 *
 * 01-Mar-90	Doug Mitchell at NeXT
 *	Added dma_close(); kalloc'd dc_tail in dma_init in case channel's
 *		tailbuf not physically contiguous.
 *
 * 20-Jun-89	Mike DeMoney (mike) at NeXT
 *	Removed last vestiges of DMA_HWIPL and DMA_SWIPL.  Changed all
 *	softint_sched's to sched at dc_hndlrpri.
 *
 * 24-May-89	Doug Mitchell at NeXT
 *	Delayed calling install_scanned_intr() until after DMA h/w is 
 *	initialized in dma_init().
 *
 * 25-May-88  John Seamons (jks) at NeXT
 *	Changes to dma_list that support padding DMA transfers before
 *	and after the actual data.
 *
 * 12-Apr-88  John Seamons (jks) at NeXT
 *	Changes to support DMA chip 313.
 *
 * 12-Aug-87  Mike DeMoney (mike) at NeXT
 *	Created.
 *
 * FIXME:
 *	DMA chip 313: BUSEXC in csr still seems to be broken.
 *
 **********************************************************************
 */

/*
 * plan 547 (D120, D103, D024): the 1997 m68k dma.c.  NeXTMach mk-108.1 nextdev/dma.c
 * gives the notice, CHAIN_READ, HISTORY, the layout, get_dma_state, dma_dequeue and
 * the NeXTMach lines kept in the other functions; the 1997 bodies of dma_init,
 * dma_close, dma_prep, dma_enqueue, dma_list, dma_start, dma_cleanup, dma_abort,
 * dma_intr, cache_flush, nitro_cache_flush and vcopy were written for this project
 * from the original bytes [0x4066410, 0x40678ce) (plans 545-546).  NeXTMach's
 * dma_va_list (#if 0), pcopy, pfill and dma_sync_cache are not in the 1997 kernel and
 * are left out; so are the dbug() lines (no code in the original).  Names the bytes do
 * not give, chosen by the user (D120): dma_prep (from its panic string), the statics
 * nitro_init and nitro_size, NITRO_CSR, NITRO_CACHE, TAILALLOC, struct en_x7 (P_ENET
 * byte 7) and dma_debug (the disabled check in dma_intr, form chosen in plan 546).
 * SLOT_ID and the P_* addresses are the NeXTMach next/cpu.h values (D107); P_MEMSIZE
 * is written from the original bytes as in mem.c (plan 510).  Include lines use the
 * OPENSTEP paths (D104): <m68k/cpu.h>, <m68k/psl.h>, <vm/pmap.h> for NeXTMach
 * <next/cpu.h>, <next/psl.h>, <next/pmap.h>; <kern/kalloc.h> is added for kalloc and
 * kfree; NeXTMach <next/event_meter.h> and <nextif/if_enreg.h> are not used.
 */

#import <iplmeas.h>

#import <sys/param.h>
#import <kern/xpr.h>
#import <kern/kalloc.h>
#import <sys/callout.h>
#import <m68k/cpu.h>
#import <m68k/psl.h>
#import <next/autoconf.h>
#import <vm/pmap.h>
#import <nextdev/dma.h>
#import <machine/spl.h>

extern int slot_id, slot_id_bmap;
extern int ncc_chip;
extern int cache;
extern void callout_dispatch();
extern void softint_run();

#define	SLOT_ID		slot_id
#define	SLOT_ID_BMAP	slot_id_bmap
#define	P_MAINMEM	(SLOT_ID+0x04000000)
#define	P_MEMSIZE	(dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000)
#define	P_DISK_CSR	(SLOT_ID+0x02000050)
#define	P_PRINTER_CSR	(SLOT_ID+0x02000090)
#define	P_ENETX_CSR	(SLOT_ID+0x02000110)
#define	P_ENET		(SLOT_ID_BMAP+0x02006000)
#define	NITRO_CSR	(SLOT_ID+0x02210000)
#define	NITRO_CACHE	(SLOT_ID+0x03e00000)

struct en_x7 { char en_pad[7]; u_char en_x7; };
#define	TAILALLOC	(2*DMA_MAXTAIL+DMA_ENDALIGNMENT)

#define	dma_debug	0

void dma_start(), dma_abort(), dma_intr(), cache_flush(), nitro_cache_flush(), vcopy();

static inline int get_dma_state(volatile struct dma_dev *ddp)
{
	int state;

	if (dma_chip == 313) {
		while ((state = ddp->dd_csr) == 0)
			continue;
		state &= (DMASTATE_MASK & ~DMACSR_BUSEXC);
	} else
		state = ddp->dd_csr & DMASTATE_MASK;
	return state;
}

/* plan 545 (D024): 1997 body from the original bytes (interrupt installed first, kalloc'd tail buffer) */
void
dma_init(dcp, device)
register struct dma_chan *dcp;
unsigned device;
{
	register volatile struct dma_dev *ddp;

	dcp->dc_flags &=~ (DMACHAN_BUSY | DMACHAN_CHAINING | DMACHAN_ERROR);
	ddp = dcp->dc_ddp;
	ddp->dd_csr = DMACMD_RESET;
	install_scanned_intr (device, (func)dma_intr, dcp);
	dcp->dc_tail = DMA_ENDALIGN(char *, dcp->dc_tailbuf);
	if (m68k_page_size - ((u_int)dcp->dc_tail & (m68k_page_size - 1)) < DMA_MAXTAIL) {
		dcp->dc_tailalloc = (char *)kalloc(TAILALLOC);
		dcp->dc_tail = DMA_ENDALIGN(char *, dcp->dc_tailalloc);
		if (m68k_page_size - ((u_int)dcp->dc_tail & (m68k_page_size - 1)) < DMA_MAXTAIL)
			dcp->dc_tail += DMA_MAXTAIL;
	}
	dcp->dc_ptail = pmap_resident_extract(pmap_kernel(), dcp->dc_tail);
	dcp->dc_current = NULL;
}

/* plan 545 (D024): 1997 body from the original bytes (frees dc_tailalloc) */
void
dma_close(dcp)
register struct dma_chan *dcp;
{
	if (dcp->dc_tailalloc) {
		kfree((vm_offset_t)dcp->dc_tailalloc, TAILALLOC);
		dcp->dc_tailalloc = NULL;
	}
}

/* plan 545 (D024): new in 1997, from the original bytes (static, 0x40664ee) */
static void
dma_prep(dcp, dhp)
register struct dma_chan *dcp;
register struct dma_hdr *dhp;
{
	if ((!(dhp->dh_flags & DMADH_LONGALIGN) && !DMA_BEGINALIGNED(dhp->dh_start)) ||
	    ((dhp->dh_flags & DMADH_LONGALIGN) && !DMA_LONGALIGNED(dhp->dh_start)))
		panic("dma_prep: bad DMA buffer alignment");
	cache_flush(dhp->dh_start, dhp->dh_stop, dcp->dc_direction);
	dhp->dh_flags |= DMADH_FLUSHED;
}

/* plan 545 (D024): NeXTMach with the 1997 dma_prep call from the original bytes */
void
dma_enqueue(dcp, dhp)
register struct dma_chan *dcp;
register struct dma_hdr *dhp;
{
	register int s;

	dhp->dh_state = 0;
	dhp->dh_link = NULL;

	if ((dcp->dc_flags & (DMACHAN_AUTOSTART|DMACHAN_BUSY|DMACHAN_ERROR))
	    != DMACHAN_AUTOSTART)
		dma_prep(dcp, dhp);
	s = spldma();
	if (dcp->dc_queue.dq_head == NULL) {	/* empty queue */
		dcp->dc_queue.dq_head = dcp->dc_queue.dq_tail = dhp;
	} else {				/* enqueue on tail */
		dcp->dc_queue.dq_tail->dh_link = dhp;
		dcp->dc_queue.dq_tail = dhp;
	}
	if ((dcp->dc_flags & (DMACHAN_AUTOSTART|DMACHAN_BUSY|DMACHAN_ERROR))
	    == DMACHAN_AUTOSTART)
		dma_start(dcp, dhp, dcp->dc_direction);
	splx(s);
}

/* NeXTMach mk-108.1 nextdev/dma.c (dbug lines left out) */
struct dma_hdr *
dma_dequeue(dcp, doneflag)
register struct dma_chan *dcp;
{
	register int s;
	register struct dma_hdr *dhp;

	ASSERT(doneflag == DMADQ_DONE || (dcp->dc_flags & DMACHAN_BUSY) == 0);

	s = spldma();
	if ((dhp = dcp->dc_queue.dq_head) == NULL	/* empty queue */
	    || (doneflag == DMADQ_DONE && dhp->dh_state == 0)) {
		splx(s);
		return(NULL);
	}
	dcp->dc_queue.dq_head = dhp->dh_link;
	splx(s);
	return(dhp);
}

/* plan 545 (D024): 1997 body from the original bytes (no sector chaining, unaligned buffers through dc_align*) */
void
dma_list(dcp, fdhp, vaddr, bcount, pmap, direction, ndmahdr, before, after)
struct dma_chan *dcp;
dma_list_t fdhp;
vm_offset_t vaddr;
long bcount;
pmap_t pmap;
int direction, ndmahdr, before, after;
{
	struct dma_hdr *dhp;
	caddr_t start, stop;
	long rem;
	int during, unaligned = 0;
	vm_offset_t va, during_va;

	during = bcount - before - after;
	if (! DMA_BEGINALIGNED(vaddr)) {
		unaligned = 1;
		dcp->dc_flags |= DMACHAN_UNALIGNED;
		dcp->dc_alignva = (char *)vaddr;
		dcp->dc_alignpmap = pmap;
		dcp->dc_alignoff = DMA_BEGINALIGNMENT -
			(vaddr & (DMA_BEGINALIGNMENT-1));
		dcp->dc_alignlen = during - dcp->dc_alignoff;
		dcp->dc_alignlen -= dcp->dc_alignlen % DMA_ENDALIGNMENT;
		dcp->dc_alignrem = during - dcp->dc_alignlen;
		if (direction == DMACSR_WRITE) {
			vcopy(vaddr + dcp->dc_alignlen, pmap,
			      dcp->dc_tail, pmap_kernel(), dcp->dc_alignrem);
			vcopy(vaddr, pmap, vaddr + dcp->dc_alignoff, pmap,
			      dcp->dc_alignlen);
		}
		vaddr = DMA_BEGINALIGN(vm_offset_t, vaddr);
		during = dcp->dc_alignlen;
	}
	during_va = vaddr;
	for (dhp = fdhp; bcount > 0 || unaligned; dhp++) {
		if (before || during == 0)
			va = vaddr & ~m68k_page_mask;
		else
			va = during_va;
		start = (caddr_t)pmap_resident_extract(pmap, va);
		if (start == 0)
			panic("dma_list: zero pfnum");
		rem = m68k_page_size - (va & m68k_page_mask);
		if (before) {
			if (rem > before)
				rem = before;
			before -= rem;
		} else
		if (during) {
			if (rem > during)
				rem = during;
			during -= rem;
			during_va += rem;
		} else
		if (unaligned) {
			rem = dcp->dc_alignrem;
			start = (caddr_t)dcp->dc_ptail;
			if (dcp->dc_flags & DMACHAN_PAD)
				rem += 2*DMA_ENDALIGNMENT;
			rem = DMA_ENDALIGN(long, rem);
			unaligned = 0;
		} else {
			if (rem > after)
				rem = after;
			after -= rem;
		}
		stop = start + rem;
		bcount -= rem;
		dhp->dh_flags = 0;
		if (dma_chip == 313 && dhp != fdhp && (dhp-1)->dh_stop == start &&
		    stop - (dhp-1)->dh_start < MAX_CHAIN_LEN) {
			dhp--;
		} else {
			dhp->dh_start = start;
		}
		dhp->dh_stop = stop;
		dhp->dh_link = bcount > 0 ? dhp + 1 : NULL;
		dhp->dh_state = 0;
	}
	dcp->dc_taillen = 0;
	dhp--;
	if ((! DMA_ENDALIGNED(dhp->dh_stop) || (dcp->dc_flags & DMACHAN_PAD)) &&
	    (dcp->dc_flags & DMACHAN_UNALIGNED) == 0) {
		if (direction == DMACSR_READ) { /* FROM DEVICE TO MEM */
			rem = dhp->dh_stop - dhp->dh_start;
			rem = (rem&~(DMA_ENDALIGNMENT-1)) + 2*DMA_ENDALIGNMENT;
			if (rem <= DMA_MAXTAIL) {
				/* move entire last seg to tail buffer */
				dcp->dc_tailstart = dhp->dh_start;
				dcp->dc_taillen = dhp->dh_stop - dhp->dh_start;
			} else {
				dcp->dc_tailstart = (char *)
				 ((u_int)dhp->dh_stop &~ (DMA_ENDALIGNMENT-1));
				dcp->dc_taillen =
				    dhp->dh_stop - dcp->dc_tailstart;
				rem = 2 * DMA_ENDALIGNMENT;
				dhp->dh_stop = dcp->dc_tailstart;
				dhp->dh_link = dhp + 1;
				dhp++;
			}
			dhp->dh_start = (caddr_t)dcp->dc_ptail;
			dhp->dh_stop = dhp->dh_start + rem;
			dhp->dh_link = NULL;
			dhp->dh_state = 0;
			dhp->dh_flags = 0;
		} else {			/* FROM MEM TO DEVICE */
			dhp->dh_stop = (char *)
			    roundup((u_int)dhp->dh_stop, DMA_ENDALIGNMENT);
			dhp->dh_link = dhp + 1;
			/* guarantee that pre-fetches don't exhaust dma */
			dhp++;
			dhp->dh_start = (caddr_t)dcp->dc_ptail;
			dhp->dh_stop = dhp->dh_start + 3*DMA_ENDALIGNMENT;
			dhp->dh_link = NULL;
			dhp->dh_state = 0;
			dhp->dh_flags = 0;
		}
	}
	if (dhp - fdhp >= ndmahdr)
		panic("dma_list: dma_list_t overflow");
	fdhp->dh_flags = DMADH_INITBUF;
	if (dma_chip == 313 && dcp->dc_ddp == (struct dma_dev *)P_PRINTER_CSR)
		fdhp->dh_flags |= DMADH_LONGALIGN;
}

/*
 * dma_start -- start dma at a particular dma header
 */
/* plan 545 (D024): 1997 body from the original bytes (dma_prep, chip 313 and Ethernet cases) */
void
dma_start(dcp, dhp, direction)
register struct dma_chan *dcp;
register struct dma_hdr *dhp;
register int direction;
{
	register volatile struct dma_dev *ddp;
	register struct dma_hdr *p;
	register int s;

	dcp->dc_direction = direction;
	ddp = dcp->dc_ddp;

	for (p = dhp; p; p = p->dh_link)
		dma_prep(dcp, p);
	s = spldma();

	if (dma_chip == 313) {
		/* direction must be set before next & limit written */
		ddp->dd_csr = DMACMD_RESET | direction;
		if (dhp->dh_flags & DMADH_INITBUF) {
			DMA_W(ddp->dd_next_initbuf, dhp->dh_start);
		} else {
			DMA_W(ddp->dd_next, dhp->dh_start);
		}
	} else {
		if (dhp->dh_flags & DMADH_INITBUF)
			ddp->dd_csr = DMACMD_RESET | DMACSR_INITBUF_TURBO | direction;
		else
			ddp->dd_csr = DMACMD_RESET | direction;
		DMA_W(ddp->dd_next, dhp->dh_start);
	}
	DMA_W(ddp->dd_limit, dhp->dh_stop);
	if (dcp->dc_flags & DMACHAN_ENETX) {
		if (dma_chip == 313) {
			DMA_W(ddp->dd_saved_next, dhp->dh_start);
			DMA_W(ddp->dd_saved_limit, dhp->dh_stop);
		} else {
			DMA_W(ddp->dd_start, dhp->dh_start);
		}
	}
	if (dma_chip != 313 && (dcp->dc_flags & DMACHAN_ENETR)) {
		DMA_W(((struct dma_dev *)P_ENETX_CSR)->dd_stop,
		    dhp->dh_start);
	}
	dcp->dc_current = dhp;

	if ((dhp = dhp->dh_link) != NULL) {
		DMA_W(ddp->dd_start, dhp->dh_start);
		DMA_W(ddp->dd_stop, dhp->dh_stop);
		if (dcp->dc_flags & DMACHAN_ENETX) {
			DMA_W(ddp->dd_saved_start, dhp->dh_start);
			DMA_W(ddp->dd_saved_stop, dhp->dh_stop);
		}
		ddp->dd_csr = DMACMD_STARTCHAIN | direction;
		dcp->dc_flags |= DMACHAN_CHAINING;
	} else {
		ddp->dd_csr = DMACMD_START | direction;
	}
	dcp->dc_flags |= DMACHAN_BUSY;
	splx(s);
}

/* plan 545 (D024): 1997 body from the original bytes (DMACHAN_UNALIGNED copy back) */
void
dma_cleanup(dcp, resid)
struct dma_chan *dcp;
long resid;
{
	long rem;

	dma_abort(dcp);
	if (resid < 0)
		panic("dma_cleanup: negative resid");
	if (dcp->dc_flags & DMACHAN_UNALIGNED) {
		rem = dcp->dc_alignlen + dcp->dc_alignrem;
		if (dcp->dc_direction)
			rem -= resid;
		vcopy(dcp->dc_alignva + dcp->dc_alignoff, dcp->dc_alignpmap,
		      dcp->dc_alignva, dcp->dc_alignpmap,
		      min(dcp->dc_alignlen, rem));
		rem -= dcp->dc_alignlen;
		if (rem > 0)
			vcopy(dcp->dc_tail, pmap_kernel(),
			      dcp->dc_alignva + dcp->dc_alignlen,
			      dcp->dc_alignpmap, rem);
		dcp->dc_flags &= ~DMACHAN_UNALIGNED;
	} else if (resid < dcp->dc_taillen)
		bcopy(dcp->dc_tail, dcp->dc_tailstart, dcp->dc_taillen-resid);
}

/*
 * dma_abort -- shutdown dma on channel
 */
/* plan 545 (D024): 1997 body from the original bytes */
void
dma_abort(dcp)
register struct dma_chan *dcp;
{
	register volatile struct dma_dev *ddp;
	register int s;

	ddp = dcp->dc_ddp;

	s = spldma();
	if (dcp->dc_flags & DMACHAN_BUSY) {
		dcp->dc_state = get_dma_state(ddp);
		dcp->dc_next = ddp->dd_next;
		if (dcp->dc_current) {
			dcp->dc_current->dh_state = get_dma_state(ddp);
			dcp->dc_current->dh_next = ddp->dd_next;
		}
	}
	ddp->dd_csr = DMACMD_RESET;
	dcp->dc_flags &=~ (DMACHAN_BUSY | DMACHAN_CHAINING);
	splx(s);
	return;
}

/*
 * dma_intr -- handle dma interrupts
 * MUST BE CALLED AT spldma!
 */
/* plan 545 (D024): 1997 body from the original bytes (messages, callout_dispatch, Ethernet cases) */
void
dma_intr(dcp, pc, ps)
register struct dma_chan *dcp;
caddr_t pc;
int ps;
{
	register volatile struct dma_dev *ddp;
	register struct dma_hdr *dhp, *ndhp;
	register int state, busexc;

	ddp = dcp->dc_ddp;
	dhp = dcp->dc_current;

	if ((dcp->dc_flags & DMACHAN_BUSY) == 0 || dhp == NULL) {
		printf ("spurious DMA interrupt: channel 0x%x\n", ddp);
		ddp->dd_csr = DMACMD_RESET;
		return;
	}

	state = get_dma_state(ddp);
	if (state == DMASTATE_SINGLE || state == DMASTATE_CHAINING) {
		state = get_dma_state(ddp);
		if (state == DMASTATE_SINGLE || state == DMASTATE_CHAINING) {
			printf("spurious DMA interrupt: state 0x%x channel 0x%x\n",
			    state, ddp);
			return;
		}
		printf("bad dma csr read, ddp=0x%x\n", ddp);
	}

	dhp->dh_state = state;

	if (state == DMASTATE_1STDONE) {
		if (dcp->dc_flags & DMACHAN_ENETR) {
			if (dma_chip == 313)
				dhp->dh_next = ddp->dd_saved_limit;
			else
				dhp->dh_next = ((volatile struct dma_dev *)
				    P_DISK_CSR)->dd_next;
		}
		dcp->dc_current = dhp = dhp->dh_link;

		/* see if we have yet another buffer to chain */
		if ((ndhp = dhp->dh_link) != NULL) {
			if ((ndhp->dh_flags & DMADH_FLUSHED) == 0 && dma_debug)
				panic("dma_intr: DMA buffer not cache flushed");
			DMA_W(ddp->dd_start, ndhp->dh_start);
			DMA_W(ddp->dd_stop, ndhp->dh_stop);
			if (dcp->dc_flags & DMACHAN_ENETX) {
				DMA_W(ddp->dd_saved_start, ndhp->dh_start);
				DMA_W(ddp->dd_saved_stop, ndhp->dh_stop);
			}
			ddp->dd_csr = DMACMD_CHAIN | dcp->dc_direction;
		} else {
			ddp->dd_csr = DMACMD_WRAPUP | dcp->dc_direction;
			dcp->dc_flags &=~ DMACHAN_CHAINING;
		}
		if (dcp->dc_flags & DMACHAN_CHAININTR)
			callout_dispatch (dcp->dc_hndlrpri, dcp->dc_handler,
				       dcp->dc_hndlrarg);

		/* check to see if update was made in time */
		state = get_dma_state(ddp);
		if (state != DMASTATE_XDONE && state != DMASTATE_XERR2) {
			/* We made update in time */
			return;
		}

		/*
		 * we missed update,
		 * just pretend we didn't even try
		 */
		state &= ~DMACSR_SUPDATE;
		dcp->dc_flags &=~ DMACHAN_CHAINING;
		dhp->dh_state = state;
	}

	if (dcp->dc_flags & DMACHAN_CHAINING) {
		if (dcp->dc_flags & DMACHAN_ENETR) {
			if (dma_chip == 313)
				dhp->dh_next = ddp->dd_saved_limit;
			else
				dhp->dh_next = ((volatile struct dma_dev *)
				    P_DISK_CSR)->dd_next;
		}
		dhp->dh_state = DMASTATE_1STDONE;
		dcp->dc_current = dhp->dh_link;
		dhp = dcp->dc_current;
		dhp->dh_state = state;
	}

	if (dma_chip != 313 && (dcp->dc_flags & DMACHAN_ENETR))
		dhp->dh_next = ddp->dd_next +
		    (((volatile struct en_x7 *)P_ENET)->en_x7 | ~0xf);
	else
		dhp->dh_next = ddp->dd_next;
	dcp->dc_flags &= ~ (DMACHAN_BUSY | DMACHAN_CHAINING);
	if (dma_chip == 313)
		busexc = 0;
	else
		busexc = (state & DMACSR_BUSEXC);
	if (!busexc && (dcp->dc_flags & DMACHAN_AUTOSTART) &&
	    (ndhp = dhp->dh_link) != NULL) {
		dma_start(dcp, ndhp, dcp->dc_direction);
		if (dcp->dc_flags & DMACHAN_CHAININTR)
			callout_dispatch (dcp->dc_hndlrpri, dcp->dc_handler,
				       dcp->dc_hndlrarg);
		return;
	}
	dcp->dc_current = NULL;

	ddp->dd_csr = DMACMD_RESET;
	dcp->dc_state = state;
	dcp->dc_next = ddp->dd_next;
	if (state == DMASTATE_XDONE)
		dcp->dc_flags |= DMACHAN_ERROR;
	if (dcp->dc_flags & DMACHAN_DMAINTR)
		(*dcp->dc_dmaintr) (dcp->dc_hndlrarg);
	if (dcp->dc_flags & (DMACHAN_INTR|DMACHAN_ERROR)) {
		callout_dispatch (dcp->dc_hndlrpri, dcp->dc_handler,
				dcp->dc_hndlrarg);
#if NIPLMEAS == 0
		if (srtoipl(ps) < (dcp->dc_hndlrpri+1)
		    && dcp->dc_hndlrpri != CALLOUT_PRI_THREAD) {
			SPLD_MACRO(dcp->dc_hndlrpri+1);
			/* Now running at < spldma() */
			softint_run(dcp->dc_hndlrpri);
			/* go back to interrupt level for return */
			spldma();
		}
#endif NIPLMEAS == 0
	}
}

/* plan 545 (D024): new in 1997, from the original bytes */
void
cache_flush(start, stop, direction)
vm_offset_t start, stop;
int direction;
{
	vm_offset_t va, pa, len;

	if (dma_chip == 313) {
		start &= 0x3fffffff;
		stop &= 0x3fffffff;
	}
	for (va = start; va < stop; va += len) {
		len = m68k_page_size - (va & m68k_page_mask);
		if (va + len > stop)
			len = stop - va;
		pa = pmap_resident_extract(pmap_kernel(), va);
		if (pa == 0)
			panic("cache_flush: page not resident");
		if (direction == DMACSR_WRITE)
			cache_push_page(pa);
		else {
			cache_inval_page(pa);
			if (ncc_chip)
				nitro_cache_flush(pa, len);
		}
	}
}

static int	nitro_init;
static int	nitro_size;

/* plan 545 (D024): new in 1997, from the original bytes */
void
nitro_cache_flush(pa, len)
vm_offset_t pa;
unsigned len;
{
	int i;
	vm_offset_t off;

	if (cache == 0)
		return;
	if (!nitro_init) {
		nitro_init = 1;
		if (*(volatile u_int *)NITRO_CSR & 0x11e) {
			switch (*(volatile u_int *)NITRO_CSR & 0x18) {
			case 0x18:
				nitro_size = 0x80000;
				break;
			case 0x10:
				nitro_size = 0x40000;
				break;
			case 0x08:
				nitro_size = 0x20000;
				break;
			case 0x00:
				nitro_size = 0x10000;
				break;
			}
		} else {
			nitro_size = 0x20000;
			*(volatile u_int *)NITRO_CSR = 0x10c;
		}
		for (i = 0; i < nitro_size; i += 32)
			*(volatile int *)(i + NITRO_CACHE) = 0;
		*(volatile int *)NITRO_CSR |= 1;
	}
	off = pa & (nitro_size - 1);
	for (i = 0; i < (len + 31) >> 5; i++)
		*(volatile int *)((i << 5) + (off + SLOT_ID) + 0x03e00000) = 0;
	asm volatile ("nop");
}

/* plan 545 (D024): new in 1997, from the original bytes */
void
vcopy(src, spmap, dst, dpmap, len)
vm_offset_t src, dst;
pmap_t spmap, dpmap;
int len;
{
	int n, off;

	if (src > dst) {
		while (len) {
			n = MIN(len, m68k_page_size - (src & m68k_page_mask));
			n = MIN(n, m68k_page_size - (dst & m68k_page_mask));
			bcopy(pmap_resident_extract(spmap, src),
			      pmap_resident_extract(dpmap, dst), n);
			src += n;
			dst += n;
			len -= n;
		}
	} else {
		src += len;
		dst += len;
		while (len) {
			off = src & m68k_page_mask;
			if (off == 0)
				off = m68k_page_size;
			n = len;
			if (n > off)
				n = off;
			off = dst & m68k_page_mask;
			if (off == 0)
				off = m68k_page_size;
			if (n > off)
				n = off;
			src -= n;
			dst -= n;
			bcopy(pmap_resident_extract(spmap, src),
			      pmap_resident_extract(dpmap, dst), n);
			len -= n;
		}
	}
}
