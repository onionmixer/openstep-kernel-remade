/*	@(#)mem.c	1.0	11/15/86	(c) 1986 NeXT	*/

/* 
 * Copyright (c) 1989 NeXT, Inc.
 */
/*
 * HISTORY
 * 15-Nov-86  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 *
 */ 

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)mem.c	7.1 (Berkeley) 6/5/86
 */

/*
 * m68k: next/mem.c of the 1997 m68k kernel (plans 509-510, D103, D104, D107).
 * Base: NeXTMach mk-108.1 next/mem.c (above notices).  The include lines use
 * the OPENSTEP paths (D104); next/mmu.h and nextdev/snd_dspreg.h come from
 * 07_kernel/nextmach (snd_dspreg.h without its next/cpu.h import, D107).
 * The next/cpu.h names this file needs are defined here (D107); P_MEMSIZE
 * is written from the original bytes (the memory size depends on dma_chip
 * and machine_type in the 1997 kernel).  Lines marked plan 510 differ from
 * NeXTMach.
 */

/*
 * Memory special file
 */

#import <sys/param.h>
#import <sys/dir.h>
#import <sys/user.h>
#import <sys/conf.h>
#import <sys/buf.h>
#import <sys/systm.h>
#import <sys/uio.h>
#import <vm/vm_map.h>
#import <vm/vm_kern.h>
#import <mach/vm_param.h>	/* plan 510 (D104): NeXTMach <vm/vm_param.h> */
#import <vm/vm_page.h>
#import <m68k/mmu.h>	/* plan 510 (D104): NeXTMach <next/mmu.h> */
#import <dev/busvar.h>	/* plan 510 (D104): NeXTMach <nextdev/busvar.h> */
#import <dev/m68k/snd_dspreg.h>	/* plan 510 (D104): NeXTMach <nextdev/snd_dspreg.h> */
#import <machine/spl.h>

extern int slot_id, slot_id_bmap;	/* plan 510 (D107) */

#define	SLOT_ID		slot_id	/* plan 510 (D107): NeXTMach next/cpu.h */
#define	SLOT_ID_BMAP	slot_id_bmap	/* plan 510 (D107): NeXTMach next/cpu.h */
#define	P_MAINMEM	(SLOT_ID+0x04000000)	/* plan 510 (D107): NeXTMach next/cpu.h */
#define	P_MEMSIZE	(dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000)	/* plan 510 (D107, D024): from the original bytes */
#define	P_DSP		(SLOT_ID_BMAP+0x02008000)	/* plan 510 (D107): NeXTMach next/cpu.h */

/*
 *	Memory interface minor device number definitions.
 */

#define	MM_MEM		0	/* /dev/mem: physical memory */
#define	MM_KMEM		1	/* /dev/kmem: per-process virtual memory */
#define	MM_NULL		2	/* /dev/null: EOF/rathole */
#define	MM_DSP		3	/* /dev/dsp: host interface registers */

/*
 *	See if memory interface is supported by machine architecture.
 */

mmopen (dev)
	dev_t	dev;
{
	switch (minor (dev)) {
	case MM_MEM:
	case MM_KMEM:
	case MM_NULL:
	case MM_DSP:
		break;

	default:
		return (EINVAL);
	}
	return (0);
}

mmread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	return (mmrw(dev, uio, UIO_READ));
}

mmwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	return (mmrw(dev, uio, UIO_WRITE));
}

mmrw(dev, uio, rw)
	dev_t dev;
	struct uio *uio;
	enum uio_rw rw;
{
	register int o, i;
	register u_int c, p;
	register struct iovec *iov;
	int error = 0;
	vm_offset_t	where;
	mem_region_t	rp;

	while (uio->uio_resid > 0 && error == 0) {
		iov = uio->uio_iov;
		if (iov->iov_len == 0) {
			uio->uio_iov++;
			uio->uio_iovcnt--;
			if (uio->uio_iovcnt < 0)
				panic("mmrw");
			continue;
		}
		switch (minor(dev)) {

		/* physical memory */
		case MM_MEM:
		
			/*
			 *  Just use transparent translation to get there.
			 *  Check bounds and use uiomove().
			 */
			p = trunc_page(uio->uio_offset);
			o = uio->uio_offset - p;
			c = min(PAGE_SIZE - o, (u_int)iov->iov_len);
			if (o < 0 || o > P_MAINMEM + P_MEMSIZE)
				goto fault;

			/* copyin/out will handle faults */
			error = uiomove((caddr_t) (p + o), c, rw, uio);
			continue;

		/* kernel virtual memory (includes direct translation) */
		case MM_KMEM:
			c = iov->iov_len;

			/* copyin/out will catch faults */
			error = uiomove((caddr_t)uio->uio_offset,
				(int)c, rw, uio);
			continue;

		case MM_NULL:
			if (rw == UIO_READ)
				return (0);
			c = iov->iov_len;
			break;

		case MM_DSP:
			/*
			 * Transfer at most sizeof(struct dsp_regs)
			 */
			c = MAX(iov->iov_len, sizeof(struct dsp_regs));
			uio->uio_offset %= sizeof(struct dsp_regs);
			uio->uio_offset += P_DSP;

			/* copyin/out will catch faults */
			error = uiomove((caddr_t)uio->uio_offset,
				(int)c, rw, uio);
			break;

		}
		if (error)
			break;
		iov->iov_base += c;
		iov->iov_len -= c;
		uio->uio_offset += c;
		uio->uio_resid -= c;
	}
	return (error);
fault:
	return (EFAULT);
}

/* allow mapping to any physical address, including other slots */
mmmmap (dev, off, prot)
	dev_t		dev;
	vm_offset_t	off;
{
	if (minor (dev) == MM_DSP)
		return (off == 0 ? atop (P_DSP) : -1);

	if (minor (dev) != MM_MEM)
		return (-1);

	return (atop (off));
}


