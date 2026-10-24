/*
 *	File:	nextdev/nbic.c
 *	Author:	Avadis Tevanian, Jr.
 *
 *	Copyright (C) 1989 NeXT, Inc.
 */

/*
 * m68k: nextdev/nbic.c of the 1997 m68k kernel (plans 505-506, D103, D105).
 * Base: NeXTMach mk-108.1 nextdev/nbic.c (above notice).  nbic_bus_enable
 * is authored from the original bytes (D024; no reference text has it).
 * nbic_configure follows the original: no ROM overlay write here (done by
 * nbic_bus_enable), the NeXTbus ID probe and the machine-type test.  Values
 * without a name in the reference headers are numbers (D105); the include
 * lines use the OPENSTEP paths (D104).  Lines marked plan 506 differ from
 * NeXTMach.
 */

#import <sys/types.h>
#import <architecture/m68k/nbicreg.h>	/* plan 506 (D104): NeXTMach <nextdev/nbicreg.h> */
#import <m68k/cpu.h>	/* plan 506 (D105): machine_type, dma_chip */
#import <m68k/bmap.h>	/* plan 506 (D104, D105): NeXTMach <next/bmap.h> */

extern int slot_id;	/* plan 506 (D105) */

int	nbic_present;	/* plan 506: no initializer (original __common) */

/* plan 506 (D024, D105): authored from the original _nbic_bus_enable (0x40725e2-0x4072672) */
nbic_bus_enable()
{
	volatile int *scr2p = (volatile int *)(slot_id + 0x0200d000);
	volatile int *reg = (volatile int *)(slot_id + 0x02200010);

	switch (machine_type) {
	case 0:
	case 2:
	case 8:
	case 9:
		if (dma_chip == 313)
			*scr2p |= 0x80;
		else {
			*scr2p &= ~0x80;
			*reg &= ~0x300;
			*(volatile u_char *)(slot_id + 0x02012000) = 0x88;
		}
		if (bmap_chip)
			bmap_chip->bm_lo = 0;
		return (1);
	}
	return (0);
}

nbic_configure()
{
	if (nbic_bus_enable() && probe_rl(NBIC_IDR_BUS)) {	/* plan 506 */
		nbic_present = 1;
		printf("NBIC present\n");
		if (machine_type == 0 || machine_type == 2) {	/* plan 506 */
			*(volatile int *)NBIC_IDR = NBIC_IDR_VALID;
			*(volatile int *)NBIC_CR = NBIC_CR_STFWD;
		}
	}
}
