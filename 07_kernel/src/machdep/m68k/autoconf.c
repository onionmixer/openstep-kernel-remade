/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 12-Jul-90  Gregg Kellogg (gk) at NeXT
 *	Changes to support using queue structure to bus_ctrl volume table.
 *
 *  5-Mar-90  John Seamons (jks) at NeXT
 *	Redefined cpu_type and cpu_subtype definitions to indicate processor
 *	architecture instead of product types for the MC680x0.
 *
 * 22-Jan-90  Gregg Kellogg (gk) at NeXT
 *	Added uninstall_polled_intr and uninstall_scanned_intr.
 *	ASCII'ized interfaces.
 *
 * 02-Jan-87  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 */ 

/*
 * m68k: next/autoconf.c of the 1997 m68k kernel (plans 525-526, D024, D103, D104, D113).
 * Base: NeXTMach mk-108.1 next/autoconf.c (above notice and history).  The include
 * lines use the OPENSTEP paths (D104); next/autoconf.h, nextdev/scsireg.h and
 * nextdev/scsivar.h come from 07_kernel/nextmach; the next/cpu.h names this file
 * needs are defined here (next/cpu.h is assembly only, D109), P_MEMSIZE written from
 * the original bytes as in mem.c.  Removed because the original has no code for them:
 * the next/scr.h import, "master_cpu = 0;" and the lines after swapconf() in
 * configure() (set_cpu_number, the "master cpu at slot" message, machine_slot),
 * pflush_super() in ioaccess() and slave_config().  Changed from the original bytes:
 * kmem_alloc_pageable(map, &addr, size) in map_addr(), the seventh argument 1 of
 * pmap_enter_mapping() and m68k_page_mask in ioaccess().  bus_find is static, so the
 * original symbol table has no name for it (0x4065c02).  Lines marked plan 526
 * differ from NeXTMach.
 */

/*
 * Setup the system to run on the current machine.
 *
 * Configure() is called at boot time and initializes the bus device tables.
 * Available devices are determined (from possibilities mentioned
 * in ioconf.c), and the drivers are initialized.
 */

#import <next/autoconf.h>
#import <sys/systm.h>
#import <sys/dk.h>
#import <sys/conf.h>
#import <vm/vm_kern.h>
#import <mach/vm_param.h>
#import <m68k/cpu.h>	/* plan 526 (D113, D110): NeXTMach <next/cpu.h> */
#import <machine/spl.h>
#import <dev/m68k/scsireg.h>	/* plan 526 (D113, D104): NeXTMach <nextdev/scsireg.h> */
#import <dev/m68k/scsivar.h>	/* plan 526 (D113, D104): NeXTMach <nextdev/scsivar.h> */

/* plan 526 (D113): NeXTMach next/cpu.h names used here (next/cpu.h is assembly only, D109) */
extern volatile int *intrmask;
extern int intr_mask;
extern int slot_id;

#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_INDEX(i)	((i) & 0xf)
#define	I_IPL(i)	(((i) >> 4) & 7)
#define	I_BIT(i)	( 1 << (((i) >> 8) & 0x1f))

#define	I_IPL7_BITS	2
#define	I_IPL6_BITS	12
#define	I_IPL4_BITS	1
#define	I_IPL3_BITS	12

#define	I_SCC		I(5,0,17)
#define	I_REMOTE	I(5,1,16)
#define	I_BUS		I(5,2,15)
#define	I_SOFTINT1	I(2,0,1)
#define	I_SOFTINT0	I(1,0,0)

#define	SLOT_ID		slot_id
#define	P_EPROM		(SLOT_ID+0x00000000)
#define	P_MAINMEM	(SLOT_ID+0x04000000)
#define	P_MEMSIZE	(dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000)	/* plan 526 (D024): from the original bytes, as plan 510 mem.c */

/*
 * The following several variables are related to
 * the configuration process, and are used in initializing
 * the machine.
 */
int	dkn;		/* number of iostat dk numbers assigned so far */
struct	bus_hd bus_hd;	/* bus information */

static void bus_find (struct bus_ctrl *cinit, struct bus_device *dinit);

/*
 * Determine mass storage and memory configuration for a machine.
 * Get cpu type, and then switch out to machine specific procedures
 * which will probe adaptors to see what is out there.
 */
void configure(void)
{
	nbic_configure();	/* configure NeXT Bus Interface Chip */

	/* enable default interrupts */
	intr_mask |= I_BIT(I_SCC) | I_BIT(I_REMOTE) | I_BIT(I_BUS) |
		I_BIT(I_SOFTINT1) | I_BIT(I_SOFTINT0);
	*intrmask |= I_BIT(I_REMOTE) | I_BIT(I_BUS) |
		I_BIT(I_SOFTINT1) | I_BIT(I_SOFTINT0);

	bus_find (bus_cinit, bus_dinit);
	setconf();

	/*
	 * Configure swap area and related system
	 * parameter based on device(s) used.
	 */
	swapconf();
}

/*
 * Find devices on the bus.
 * Uses per-driver routine to probe for the device
 * and then fills in the tables, with help from a per-driver
 * slave initialization routine.
 */
static void bus_find (struct bus_ctrl *cinit, struct bus_device *dinit)
{
	struct bus_hd *bh;
	register struct bus_ctrl *bc;
	register struct bus_device *bd;
	register struct bus_driver *bdr;
	caddr_t map_addr();
	int dev_find();
	caddr_t vaddr;
	struct pseudo_init *pi;

	/*
	 * Call the init routine for each driver so it can do any
	 * early initialization required, such as clearing possibly
	 * pending interrupts, scarfing up dedicated buffers, and so on.
	 * Do the same thing for the pseudo devices.
	 */
	for (pi = pseudo_inits; pi->ps_func; pi++)
		(*pi->ps_func) (pi->ps_count);
	for (bc = cinit; bc && (bdr = bc->bc_driver); bc++) {
		queue_init(&bc->bc_tab);
		if (bdr->br_init)
			(*bdr->br_init)(bc->bc_addr);
	}
	spl0();

	/*
	 * Check each bus mass storage controller.
	 * See if it is really there, and if it is record it and
	 * then go looking for slaves.
	 */
	for (bc = cinit; bc && (bdr = bc->bc_driver); bc++) {
		if (vaddr = map_addr(bc->bc_addr, bdr->br_size))
			bc->bc_addr = vaddr;
		/*
		 * drivers now expect bus_ctrl to be initialized
		 * at probe time (other than bc_alive)
		 */
		bdr->br_cinfo[bc->bc_ctrl] = bc;
		bc->bc_hd = &bus_hd;
		if ((bc->bc_addr = (caddr_t)dev_find (bc->bc_addr, bc->bc_ctrl,
		    bc->bc_ipl, bdr, bdr->br_cname)) == 0) {
			if (vaddr)
				kmem_free (kernel_map, vaddr, bdr->br_size);
			continue;
		}
		bc->bc_alive = 1;
		for (bd = dinit; bd && bd->bd_driver; bd++) {
			if (bd->bd_driver != bdr || bd->bd_alive ||
			    bd->bd_ctrl != bc->bc_ctrl && bd->bd_ctrl != '?')
				continue;
			/*
			 * Drivers now assume that everything except
			 * bd_alive is initialized at slave time so
			 * slave detection can use the entire facilities
			 * of the driver.
			 */
			bd->bd_ctrl = bc->bc_ctrl;
			bd->bd_hd = &bus_hd;
			bd->bd_addr = bc->bc_addr;
			bd->bd_bc = bc;
			if (bdr->br_dinfo)
				bdr->br_dinfo[bd->bd_unit] = bd;
			if ((*bdr->br_slave)(bd, bc->bc_addr)) {
				bd->bd_alive = 1;
				if (bd->bd_dk && dkn < DK_NDRIVE)
					bd->bd_dk = dkn++;
				else
					bd->bd_dk = -1;
				if (bdr->br_flags & BUS_SCSI) {
					printf(
					  "%s%d at %s%d target %d lun %d\n",
					    bd->bd_name, bd->bd_unit,
					    bdr->br_cname, bc->bc_ctrl,
					    SCSI_TARGET(bd->bd_slave),
					    SCSI_LUN(bd->bd_slave));
				} else {
					printf("%s%d at %s%d slave %d\n",
					    bdr->br_dname, bd->bd_unit,
					    bdr->br_cname, bc->bc_ctrl,
					    bd->bd_slave);
				}
				if (bdr->br_attach)
					(*bdr->br_attach)(bd);
			}
		}
	}

	/*
	 * Now look for non-mass storage peripherals.
	 */
	for (bd = dinit; bd && (bdr = bd->bd_driver); bd++) {
		if (bd->bd_alive || bd->bd_slave != -1)
			continue;
		if (vaddr = map_addr(bd->bd_addr, bdr->br_size))
			bd->bd_addr = vaddr;
		bd->bd_dk = -1;
		if (bdr->br_dinfo)
			bdr->br_dinfo[bd->bd_unit] = bd;
		if ((bd->bd_addr = (caddr_t)dev_find (bd->bd_addr, bd->bd_unit,
		    bd->bd_ipl, bdr, bdr->br_dname)) == 0) {
			if (vaddr)
				kmem_free (kernel_map, vaddr, bdr->br_size);
			continue;
		}
		bd->bd_alive = 1;
		/* bd_type comes from driver */
		if (bdr->br_attach)
			(*bdr->br_attach)(bd);
	}
}


static int intr_spurious_count;

int intr_spurious(void)
{
	if ((intr_spurious_count++ % 256) == 1)
		printf ("ipl%d: spurious interrupt\n", POLLED_IPL);
	return (1);
}

func poll_intr[NPOLL] = {(func)intr_spurious};

int install_polled_intr (int which, func intr)
{
	register int i;
	register func *ip;
	register int ipl = I_IPL(which);

	/* only one ipl is polled */
	if (ipl != POLLED_IPL) {
		printf ("illegal polling ipl %d\n", ipl);
		return (-1);
	}
	for (ip = poll_intr, i = 0; i < NPOLL; ip++, i++)
		if (*ip == 0)
			break;
	if (i >= NPOLL)
		panic ("too many polled interupt routines");
	ip[0] = ip[-1];		/* move spurious routine to end */
	ip[-1] = intr;
	return (0);
}

func ipl3_scan[I_IPL3_BITS], ipl4_scan[I_IPL4_BITS],
	ipl6_scan[I_IPL6_BITS], ipl7_scan[I_IPL7_BITS];
void *ipl3_arg[I_IPL3_BITS], *ipl4_arg[I_IPL4_BITS],
	*ipl6_arg[I_IPL6_BITS], *ipl7_arg[I_IPL7_BITS];

int install_scanned_intr (int which, func intr, void *arg)
{
	register int ipl = I_IPL(which);
	register int index = I_INDEX(which);
	register func *sp;
	register void **ap;

	switch (ipl) {

	case 3:	 sp = ipl3_scan;  ap = ipl3_arg;  break;
	case 4:	 sp = ipl4_scan;  ap = ipl4_arg;  break;
	case 6:	 sp = ipl6_scan;  ap = ipl6_arg;  break;
	case 7:	 sp = ipl7_scan;  ap = ipl7_arg;  break;

	default:
		printf ("illegal scanning ipl %d\n", ipl);
		return (-1);
	}
	sp[index] = intr;
	ap[index] = arg;
	intr_mask |= I_BIT (which);
	*intrmask |= I_BIT (which);		/* enable interrupt */
	return (0);
}

int uninstall_polled_intr(int which, func intr)
{
	register int i, s;
	register func *ip;
	register int ipl = I_IPL(which);

	/* only one ipl is polled */
	if (ipl != POLLED_IPL) {
		printf ("illegal polling ipl %d\n", ipl);
		return (-1);
	}
	
	s = splhigh();
	for (ip = poll_intr, i = 0; i < NPOLL; ip++, i++)
		if (*ip == intr)
			break;
	if (i >= NPOLL) {
		splx(s);
		return (-1);	/* Interrupt handler not found. */
	}

	/*
	 * Move the rest of the interrupt handlers up.
	 */
	for (; i < (NPOLL - 1) && *ip; ip++, i++)
		ip[0] = ip[1];
	*ip = (func)0;	/* Zero emptied slot, so install_polled_intr() is happy. */
	splx(s);
	return (0);
}

int uninstall_scanned_intr(int which)
{
	register int ipl = I_IPL(which);
	register int index = I_INDEX(which);
	register func *sp;
	register void **ap;
	int s;

	switch (ipl) {

	case 3:	 sp = ipl3_scan;  ap = ipl3_arg;  break;
	case 4:	 sp = ipl4_scan;  ap = ipl4_arg;  break;
	case 6:	 sp = ipl6_scan;  ap = ipl6_arg;  break;
	case 7:	 sp = ipl7_scan;  ap = ipl7_arg;  break;

	default:
		printf ("illegal scanning ipl %d\n", ipl);
		return (-1);
	}
	s = splhigh();

	sp[index] = (func)0;
	ap[index] = 0;
	intr_mask &= ~I_BIT (which);
	*intrmask &= ~I_BIT (which);		/* enable interrupt */

	splx(s);
	return (0);
}

caddr_t map_addr(register caddr_t addr, int size)
{
	caddr_t reg;	/* plan 526 (D024): not register, its address is passed */
	caddr_t ioaccess(vm_offset_t phys, vm_offset_t virt, vm_size_t size);

	/* setup mapping if outside transparently mapped space */
	/* FIXME: how does this all work for devices in other slots? */
	if (addr < (caddr_t) P_EPROM ||
	    addr >= (caddr_t) (P_MAINMEM + P_MEMSIZE)) {
		if (kmem_alloc_pageable (kernel_map, &reg, size) != KERN_SUCCESS)	/* plan 526 (D024) */
			panic ("map_addr: no memory for device");
		reg = ioaccess ((vm_offset_t)addr, (vm_offset_t)reg,
			(vm_size_t)size);
		return(reg);
	}
	return(0);
}

int dev_find (
	register caddr_t addr,
	int unit,
	int ipl,
	register struct bus_driver *bdr,
	char * devname)
{
	if ((addr = (caddr_t)(*bdr->br_probe)(addr, unit)) == 0)
		return(0);
	printf("%s%d at 0x%x ", devname, unit, addr);
	if (ipl != 0)
		if (install_polled_intr (ipl, bdr->br_intr) >= 0)
			printf("ipl %d", ipl);
	printf ("\n");
	return ((int)addr);
}

/*
 * Make an IO device area accessible at physical address pa
 * by mapping kernel ptes starting at pte.  Note that entry
 * is marked non-cacheable.
 */
caddr_t ioaccess (vm_offset_t phys, vm_offset_t virt, vm_size_t size)
{
	register vm_offset_t	pa = phys;
	register vm_offset_t	va = virt;
	register int		i = atop (round_page (size));

	do {
		pmap_enter_mapping (pmap_kernel(), va, pa,
			VM_PROT_READ | VM_PROT_WRITE, 0, 0, 1);	/* plan 526 (D024) */
		pa += page_size;
		va += page_size;
	} while (--i > 0);

	return ((caddr_t) (virt + (phys & m68k_page_mask)));	/* plan 526 (D113): NeXTMach NeXT_page_mask */
}


/*
 * Configure swap space and related parameters.
 */
void swapconf(void)
{
	/*
	 *	We swap to normal file systems for new VM.
	 */
	dumplo = 0;		/* make it easy to look in /dev/xxb */
}


