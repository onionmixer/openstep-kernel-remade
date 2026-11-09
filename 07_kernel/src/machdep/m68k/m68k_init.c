/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 11-Sep-90  Gregg Kellogg (gk) at NeXT
 *	Initialize event_h and event_m to point to distinct data locations.
 *	In a debug kernel this isn't a problem, because they're both reset
 *	to point to locations on a mappable page.  In a RELEASE configuration
 *	they also need to point to distinct data locations.
 *
 * 30-Jul-90  Gregg Kellogg (gk) at NeXT
 *	Moved declaration of disr_shadow from od.c to next_init.c (config).
 *
 * 28-Jun-90  John Seamons (jks) at NeXT
 *	Fix upper byte of hostid to be 0x01.  It became 0x00 with the new
 *	machine type definitions for the NeXT_CUBE and this caused backward
 *	compatibility problems.  The machine type doesn't belong in the hostid
 *	anyway -- it is available elsewhere.
 *
 * 15-Mar-90  John Seamons (jks) at NeXT
 *	Removed obsolete code to disable realtime clock interrupt.
 *
 *  7-Mar-90  John Seamons (jks) at NeXT
 *	Include next/bmap.h.
 *
 * 01-Mar-90  Brian Pinkerton (bpinker) at NeXT
 *	Updated _edata and _end to new loader symbols.
 *
 * 25-Oct-88  Mike DeMoney (mike) at NeXT
 *	Add cpu_rev global to hold cpu board revision.
 *
 * 19-Feb-88  John Seamons (jks) at NeXT
 *	Updated to Mach release 2.
 *
 * 17-Jan-88  John Seamons (jks) at NeXT
 *	Added a memory region for device space.
 *
 * 02-Dec-86  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 */ 

/*
 * plan 609 (D137, D013, D024, D104, D105, D110): the 1997 m68k m68k_init.
 * NeXTMach mk-108.1 next/next_init.c (NeXT_init) with the include lines in
 * OPENSTEP paths and the 1997 function written from the original bytes
 * [0x4094afe, 0x40951ec) and data [0x40b2b9e, 0x40b2bca) (plans 605-608):
 *	- one argument, a pointer to the block of the NeXTMach NeXT_init
 *	  arguments (struct m68k_init_args, same field order); no bzero
 *	- SCB: reboot_vector saved from monitor trap 13, which becomes mon_exit
 *	- machine type from the SCR1 word (re-read at P_SCR1_TURBO for type 4),
 *	  cpu_rev, board_rev, cpu_clk from cpu_clock_table; switch 0-9 with
 *	  types 4-9 sharing the default body (dma_chip from SCR1, probe_rl at
 *	  P_NCC); no disk_chip, scr1 or bmap_chip = 0 assignments
 *	- page size 4096 or 8192 only (m68k_page_size); one memory region loop
 *	  (OPENSTEP vm/pmap.h mem_region, no region_type) with the limit test
 *	  mem_size + size >= mem and pmsgbuf from the monitor region
 *	- after mon_reset: km_send and mon_rev when dma_chip != 313, master_cpu,
 *	  machine_slot and interrupt_stack, getlastaddr, pmap_bootstrap with the
 *	  1997 arguments, en_bufalloc, and the debugger address prompt and wait
 *	- no set_cpu_number, _nextdbginit, mallocdebuginit; no struct bootp
 *	  bootp or mem_region definition; rpc/types.h and nfs/nfs.h not imported
 * Forms fixed by the bytes: the non-volatile bit-field read of dma_chip, the
 * explicit cases 4-9, the monitor pointer variable for mon_rev.  User
 * decisions (D137): the authored names struct m68k_init_args, ap0,
 * cpu_clock_table, P_SCR1_TURBO, P_NCC, NeXT_TURBO, the kdb_net declaration
 * (only its +8 word is known) and the 1997 struct scr1 field names; explicit
 * case labels; the block-local monitor pointer; the file name m68k_init.c.
 * Lines marked plan 609 differ from NeXTMach; m68k_init is rewritten.
 */

#import <gdb.h>
#import <mallocdebug.h>

#import <sys/types.h>
#import <sys/param.h>
#import <sys/systm.h>
#import <sys/time.h>
#import <sys/kernel.h>
#import <sys/reboot.h>
#import <sys/errno.h>
#import <sys/ioctl.h>
#import <sys/tty.h>
#import <sys/socket.h>
#import <kern/xpr.h>
#import <sys/msgbuf.h>
#import <mach/vm_param.h>	/* plan 609 (D104): NeXTMach <vm/vm_param.h> */
#import <mach/vm_prot.h>	/* plan 609 (D104): NeXTMach <vm/vm_prot.h> */
#import <vm/vm_page.h>
#import <next/scb.h>
#import <m68k/cpu.h>	/* plan 609 (D110): NeXTMach <next/cpu.h> */
/* plan 609 (D104, D137): NeXTMach #import <next/pcb.h> left out (as machdep.c) */
#import <mach/m68k/vm_param.h>	/* plan 609 (D104): NeXTMach <next/vm_param.h> */
#import <m68k/cons.h>	/* plan 609 (D104): NeXTMach <next/cons.h> */
/* plan 609 (D104, D137): NeXTMach #import <next/scr.h> left out (as machdep.c) */
#import <next/clock.h>
#import <machdep/m68k/eventc.h>	/* plan 609 (D104): NeXTMach <next/eventc.h> */
#import <dev/m68k/snd_dspreg.h>	/* plan 609 (D104): NeXTMach <nextdev/snd_dspreg.h> */
#import <nextdev/kmreg.h>
#import <dev/m68k/monreg.h>	/* plan 609 (D104): NeXTMach <nextdev/monreg.h> */
#import <m68k/bmap.h>	/* plan 609 (D105): NeXTMach <next/bmap.h> */
/* plan 609 (D104, D137): NeXTMach #import <rpc/types.h>, <nfs/nfs.h> left out (no name used; nfs.h does not parse here) */
#import <m68k/mmu.h>	/* plan 609 (D104, D137): CACR_* names */
#import <kern/cpu_number.h>	/* plan 609 (D104, D137): master_cpu */
#import <mon/global.h>

/* plan 609 (D137, D024): NeXTMach next/cpu.h and next/scr.h names used here (values as NeXTMach) */
extern int slot_id, slot_id_bmap;
#define	SLOT_ID		slot_id
#define	SLOT_ID_BMAP	slot_id_bmap
#define	P_MON		(SLOT_ID+0x0200e000)
#define	P_TIMER		(SLOT_ID_BMAP+0x02016000)
#define	P_TIMER_CSR	(SLOT_ID_BMAP+0x02016004)
#define	P_EVENTC	(SLOT_ID_BMAP+0x0201a000)
#define	P_BMAP		(SLOT_ID+0x020c0000)
#define	P_INTRSTAT	(SLOT_ID+0x02007000)
#define	P_INTRMASK	(SLOT_ID+0x02007800)
#define	P_SCR1		(SLOT_ID+0x0200c000)
#define	P_SCR2		(SLOT_ID+0x0200d000)
#define	P_BRIGHTNESS	(SLOT_ID_BMAP+0x02010000)
#define	P_SCR1_TURBO	(SLOT_ID+0x02200000)	/* plan 609 (D137, D024): authored name, original 0x4094b6e */
#define	P_NCC		(SLOT_ID+0x02210000)	/* plan 609 (D137, D024): authored name, original 0x4094c5c */
#define	NeXT_CUBE	0
#define	NeXT_WARP9	1
#define	NeXT_X15	2
#define	NeXT_WARP9C	3
#define	NeXT_TURBO	4	/* plan 609 (D137, D024): authored name, original 0x4094b68 */
#define	MACHINE_TYPE(x)	((x) >> 4)
#define	BOARD_REV(x)	((x) & 0xf)
#define	SCR2_EKG_LED	0x00000001
struct scr1 {				/* plan 609 (D137, D024): 1997 layout from the original bfextu {16:8}, {29:3} */
	u_int	s_slot_id : 4,
		: 4,
		s_dma_rev : 8,
		s_cpu_rev : 8,
		s_vmem_speed : 2,
		s_mem_speed : 2,
		s_reserved : 1,
		s_cpu_clock : 3;
};
extern volatile int *scr2;
extern volatile u_char *brightness;
extern volatile int *intrmask;
extern int intr_mask;

volatile u_char		*eventc_latch, *eventc_h, *eventc_m, *eventc_l;

/*
 * this ain't pretty, but it'll work... we need something for event_high and
 * event_middle to point to until the VM system comes up and their memory
 * is allocated, so we make them point somewhere bogus until we have their page
 */
static unsigned int event_junk_h, event_junk_m;
volatile unsigned int	*event_high = &event_junk_h;
					/* high-order 32 bits of eventc */
volatile unsigned int	*event_middle = &event_junk_m;
					/* middle 12 bits of eventc */
u_char disr_shadow;		/* for cubes with floppy protos only */

volatile int	*intrstat;	/* pointer to interrupt status reg */
vm_size_t	mem_size, pagesize, mem;
vm_offset_t	virtual_avail, virtual_end;
struct		mon_global *mon_global;
/* plan 609 (D137, D024): NeXTMach mem_region[MAX_REGIONS] and struct bootp bootp left out (OPENSTEP vm/pmap.h declares mem_region) */
int		console_i, console_o;
u_char		etheraddr[6];
#define	NBOOTDEV	8
#define	NBOOTINFO	16
#define	NBOOTFILE	64
char		boot_dev[NBOOTDEV], boot_info[NBOOTINFO], boot_file[NBOOTFILE];
char		*boot_args;
int		default_page_size = 8192;	/* patchable */

int	breakpoint;	/* plan 609 (D137, D024): NeXTMach under #if GDB */

#if	MALLOCDEBUG
extern int mallocdebug;
#endif	MALLOCDEBUG

#if	DEBUG
int	show_info;	/* print initilization info */
#endif	DEBUG

/* plan 609 (D137, D024): the 1997 m68k_init (original 0x4094afe-0x40951ec) */
static int cpu_clock_table[8] = { 16, 20, 25, 33, 40, 50, 66, 80 };	/* plan 609 (D137, D024): authored name, original 0x40b2baa */

struct m68k_init_args {			/* plan 609 (D137, D024): authored name; the NeXTMach NeXT_init arguments */
	int			ra;
	struct mon_global	*mg;
	int			cons_i, cons_o;
	char			*dev, *args, *info;
	int			sid;
	int			mon_pagesize;
	int			mon_nr;
	struct mon_region	*mon_rp;
	u_char			*clientetheraddr;
	char			*file;
};

extern int (*reboot_vector)();		/* plan 609 (D137, D024) */
extern int mon_exit();			/* plan 609 (D137, D024) */
extern int ncc_chip;			/* plan 609 (D137, D024) */
extern char *mach_title;
extern vm_offset_t interrupt_stack[];
extern char intstacks[];		/* plan 609 (D137, D024) */
extern u_long kdb_ipaddr;		/* plan 609 (D137, D024) */
extern struct { int kn_pad[2]; int kn_connected; } kdb_net;	/* plan 609 (D137, D024): type unknown, +8 tested */

m68k_init (ap0)
	struct m68k_init_args *ap0;
{
	register int 	i;
	register struct mon_global *mg = ap0->mg;
	struct		scb *get_vbr(), *mon_scb;
	register	struct mem_region *rp;
	extern int	tickadj;
	int		see_msgs, skip, size;
	char		*ap;
	extern		int cache;
	struct scr1	s1;

	slot_id = ap0->sid;
	slot_id_bmap = ap0->sid;

	/* set up SCB */
	mon_scb = get_vbr();
	scb.scb_issp = mon_scb->scb_issp;	/* saved from monitor */
	scb.scb_ipc = mon_scb->scb_ipc;
	reboot_vector = mon_scb->scb_trap[13];
	scb.scb_trap[13] = mon_exit;		/* monitor exit */
	set_vbr (&scb);

	/* figure out chip type installed */
	s1 = *(volatile struct scr1 *) P_SCR1;
	if (MACHINE_TYPE(s1.s_cpu_rev) == NeXT_TURBO)
		s1 = *(volatile struct scr1 *) P_SCR1_TURBO;
	cpu_rev = s1.s_cpu_rev;
	machine_type = MACHINE_TYPE(cpu_rev);
	board_rev = BOARD_REV(cpu_rev);
	cpu_clk = cpu_clock_table[s1.s_cpu_clock];

	switch (machine_type) {
	
	case NeXT_CUBE:
		cpu_type = MC68030;
		dma_chip = 313;
		break;

	case NeXT_WARP9:
	case NeXT_X15:
	case NeXT_WARP9C:
		cpu_type = MC68040;
		slot_id_bmap += 0x00100000;	// remap byte devices to BMAP chip
		dma_chip = 313;
		bmap_chip = (struct bmap_chip*) P_BMAP;
		break;

	case NeXT_TURBO:	/* plan 609 (D137, D024): cases 4-9 explicit */
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	default:
		cpu_type = MC68040;
		dma_chip = ((struct scr1 *) P_SCR1)->s_dma_rev;	/* plan 609 (D137, D024): bit-field read without volatile (fixed by the bytes) */
		cpu_clk = cpu_clock_table[s1.s_cpu_clock ^ 4];
		if (probe_rl (P_NCC)) {
			ncc_chip = 1;
			cpu_clk = 40;
		}
		break;
	}
	
	switch (cpu_type) {
	
	case MC68030:
		cache = CACR_CLR_ENA;
		break;
		
	case MC68040:
	default:
		cache = CACR_040_IE | CACR_040_DE;
		break;
	}

	intrmask = (int*) P_INTRMASK;
	intrstat = (int*) P_INTRSTAT;
	*intrmask = 0;		/* disable interrupts */
	intr_mask = 0;
	eventc_latch = (u_char*) P_EVENTC;
	eventc_h = (u_char*) (P_EVENTC + 1);
	eventc_m = (u_char*) (P_EVENTC + 2);
	eventc_l = (u_char*) (P_EVENTC + 3);
	scr2 = (int*) P_SCR2;
	*scr2 &= ~(DSP_RESET|SCR2_EKG_LED);	/* Can't take any interrupts */
	brightness = (u_char*) P_BRIGHTNESS;
	timer_csr = (u_char*) P_TIMER_CSR;
	timer_high = (u_char*) P_TIMER;
	timer_low = (u_char*) (P_TIMER+1);

	/* copy boot parameters from monitor stack */
	mon_global = ap0->mg;
	bcopy (ap0->clientetheraddr, etheraddr, 6);
	hostid = 0x01000000 | ((u_int)etheraddr[3] << 16) |
		  ((u_int)etheraddr[4] << 8) | (u_int)etheraddr[5];
	strncpy (boot_dev, ap0->dev, NBOOTDEV);
	strncpy (boot_file, ap0->file, NBOOTFILE);

	ap = ap0->args;
	if (ap) {
		while (*ap) {
			if (strncmp("pagesize=", ap, 9) == 0) {
				getval(ap+8, &pagesize);
				break;
			}
			if (strncmp("mem=", ap, 4) == 0) {
				getval(ap+3, &mem);
				mem *= 1024;
				break;
			}
			ap++;
		}
	}
	if (pagesize == 4096 || pagesize == 8192)
		m68k_page_size = pagesize;
	else
		m68k_page_size = default_page_size;

	/*
	 *	Virtual page size must be at least the physical page size.
	 */
	pmap_set_page_size();
	if (page_size < m68k_page_size)
		page_size = m68k_page_size;
	vm_set_page_size();

	/* configure memory regions */
	num_regions = ap0->mon_nr;
	for (i = 0, skip = 0; i < num_regions; i++) {
		rp = &mem_region[i];
		if (skip == 0) {
			rp->first_phys_addr = ap0->mon_rp[i].first_phys_addr;
			rp->last_phys_addr = ap0->mon_rp[i].last_phys_addr;
			size = rp->last_phys_addr - rp->first_phys_addr;
		} else {
			rp->first_phys_addr = 0;
			rp->last_phys_addr = 0;
			size = 0;
		}
		
		/* limit memory used if requested */
		if (mem && skip == 0 && (mem_size + size >= mem)) {
			rp->last_phys_addr = rp->first_phys_addr + (mem - mem_size);
			skip = 1;
		}
		mem_size += rp->last_phys_addr - rp->first_phys_addr;
		if (ap0->mon_rp[i].first_phys_addr)
			pmsgbuf = (struct msgbuf *)
				(m68k_trunc_page (ap0->mon_rp[i].last_phys_addr) + 256);
	}

	/* configure console device */
	cons_tp = &cons;
	console_i = ap0->cons_i;
	console_o = ap0->cons_o;

	switch (console_i) {

	case CONS_I_KBD:
	default:
		cons.t_dev = makedev(12, 0);		/* km */
		break;

	case CONS_I_SCC_A:
		cons.t_dev = makedev(11, 0);		/* zs */
		break;
	}

	switch (console_o) {

	case CONS_O_BITMAP:
	default:
		cons.t_dev = makedev(12, 0);		/* km */

		/* see msgs if booting single user or asking for root dev */
		see_msgs = 0;
		ap = ap0->args;
		if (ap) {
			while (isargsep (*ap))
				ap++;
			if (*ap == '-') do {
				switch (*ap) {
					case 'a':
					case 's':
					case 'w':
						see_msgs = 1;
						break;
				}
			} while (*ap && !isargsep (*ap++));
		}

		/* if the monitor has a popup we should too */
		if (*MG (short*, MG_km_flags) & KMF_SEE_MSGS)
			see_msgs = 1;
		kminit();
		if (see_msgs)
			kmpopup (mach_title, POPUP_FULL, 0, 0, 0);
		break;

	case CONS_O_SCC_A:
		cons.t_dev = makedev(11, 0);		/* zs */
		break;
	}
	boot_args = ap0->args;
	getargs(ap0->args, 0);

	printf ("NeXT ROM Monitor %d.%d v%d\n",
		mg->mg_major, mg->mg_minor, mg->mg_seq);
	
	/* hz may have been specified as a kernel argument */
	tick = 1000000 / hz;
	tickadj = 240000 / (60 * hz);		/* can adjust 240ms in 60s */

	/* Initialize keyboard monitor and line printer interface */
	mon_reset();

	if (dma_chip != 313) {
		km_send (0xc5, 0xf0000000);
		{
		volatile struct monitor *mon = (struct monitor *) P_MON;	/* plan 609 (D137, D024): pointer variable (fixed by the bytes), block-local (user decision) */
		mon_rev = mon->mon_km_data >> 16;
		}
	}

	master_cpu = 0;
	machine_slot[master_cpu].running = TRUE;
	for (i = 0; i < NCPUS; i++) {
		machine_slot[i].is_cpu = TRUE;
		machine_slot[i].clock_freq = cpu_clk;
		if (machine_type == NeXT_CUBE) {
			machine_slot[i].cpu_type = CPU_TYPE_MC680x0;
			machine_slot[i].cpu_subtype = CPU_SUBTYPE_MC68030;
		} else {
			machine_slot[i].cpu_type = CPU_TYPE_MC680x0;
			machine_slot[i].cpu_subtype = CPU_SUBTYPE_MC68040;
		}
		interrupt_stack[i] = (vm_offset_t) intstacks + i * 4096;
	}

	mem_region[0].first_phys_addr = getlastaddr();
	pmap_bootstrap(mem_region, num_regions, &virtual_avail, &virtual_end,
		(vm_offset_t) pmsgbuf - 256);
	en_bufalloc(0);

	if (breakpoint) {
		if (kdb_ipaddr == 0) {
			char line[32];
			u_long addr;

			do {
				printf("ip address? ");
				gets(line, line);
			} while (inet_aton(line, &addr) == 0);
			kdb_ipaddr = addr;
		}
		printf("Waiting for connection from debugger\n");
		while (kdb_net.kn_connected == 0)
			kdbg_connect(0);
	}
}
/* plan 779 (D178): bootp (NeXTMach next/next_init.c:95) and the size-only names written to match the original bytes (D024, plan 778.15) */
#import <netinet/in.h>
#import <netinet/in_systm.h>
#import <netinet/ip.h>
#import <netinet/udp.h>
#import <netinet/bootp.h>
struct bootp	bootp;
u_char	cpu_type, machine_type, mon_rev, board_rev, cpu_clk, cpu_rev;
int	intr_mask;
int	(*reboot_vector)();
int	vmlog_send;
struct mem_region	mem_region[MAX_REGIONS];
int	num_regions;
volatile int	*intrmask;
int	ncc_chip;
int	slot_id_bmap;
u_long	kdb_ipaddr;
vm_offset_t	interrupt_stack[NCPUS];
