/* 
 * Copyright (c) 1987, 1988, 1989 NeXT, Inc.
 */
/*
 *
 * HISTORY
 * 24-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Change kill_tasks to deal with processor_set cleanup properly.
 *
 * 9-July-90  Mike Paquette (mpaque) at NeXT
 *	Removed hardware bit fiddling from softint code, replaced with video calls.
 *
 *  4-Jun-90  Brian Pinkerton at NeXT
 *	Removed call to vm_object_shutdown on reboot/halt.  This is now handled in
 *	unmount_all() in proper sequence with the rest of the shutdown.
 *
 * 4-April-90  Mike Paquette (mpaque) at NeXT
 *	Added call to km_switch_to_vm() to startup, so console I/O will work.
 *
 * 19-Mar-90  Gregg Kellogg (gk) at NeXT
 *	defined boothowto here.  It's externed in the header file now.
 *
 * 15-Mar-90  John Seamons (jks) at NeXT
 *	Removed obsolete call to stoprtclock().
 *	Moved rtc_power_down() to next/clock.c.
 *
 * 06-Mar-90  Gregg Kellogg (gk) at NeXT
 *	Changed kill_tasks to get tasks from processor sets, rather
 *	than all_tasks.
 *	Increased size of boot_param string from 32 to 128 bytes.
 *	Took out simple_unlock in softint_th, as this is done by
 *	thread_sleep().
 *
 * 28-Feb-90  John Seamons (jks) at NeXT
 *	Added argument to boot() that optionally specifies the
 *	command to reboot with.
 *
 * Revision 2.19  89/10/11  14:56:08  dlb
 * 	Encase multiprocessor shutdown code in NCPUS > 1.
 * 	[89/09/06            dlb]
 * 	Replace should_exit with processor shutdown logic.
 * 	New calling sequence for vm_map_pageable.
 * 	[89/02/02            dlb]
 * 
 * 29-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes
 *
 * 15-Jun-89  Mike DeMoney (mike) at NeXT
 *	Moved microtime() to us_timer.c
 *
 * 16-Feb-88  John Seamons (jks) at NeXT
 *	Updated to Mach release 2.
 *
 *  4-Jan-88  Gregg Kellogg (gk) at NeXT
 *	softints may generate calls immediately with level == ..._NOW
 *
 * 22-Dec-87  Gregg Kellogg (gk) at NeXT
 *	Microtime() now get's it's microsecond time base from the
 *	microsecond counter.
 *
 *  5-Dec-87  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Condensed buffer size calculations.  Use one buffer per page,
 *	since pages are virtual-size.
 *
 * 26-Oct-87  Peter King (king) at NeXT
 *	SUN_VFS: Allocate space for dnlc cache instead of namei cache.
 *
 * 14-Sep-87  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Added call to panic_init(), as directed by David Black.
 *
 *  4-Sep-87  Michael Young (mwyoung) at Carnegie-Mellon University
 *	CS_BUGFIX: Correct calculation of second-boundary rollover
 *	in microtime().
 *
 * 28-Aug-87  David Golub (dbg) at Carnegie-Mellon University
 *	Remove arg_zone - exec now uses kernel_pageable_map (allocated
 *	in init_main).
 *
 * 23-Dec-86  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 *
 **********************************************************************
 */ 

/*
 * plan 600 (D134, D013, D024, D104, D105, D110, D116): the 1997 m68k
 * machdep.c.  NeXTMach mk-108.1 next/machdep.c with the include lines in
 * OPENSTEP paths and the 1997 changes written from the original bytes
 * [0x40936a4, 0x4094a7c) and data [0x40b2b82, 0x40b2b92) (plans 580-599):
 *	mon_call	adb_watchdog(0)/(1) around trap #13; no movl of boot_action
 *	kernel_thread_noblock, kernel_thread_noblock_start
 *			new here (NeXTMach has a reaper form in kern/thread.c):
 *			callout_dispatch of kernel_thread(kernel_task, start, 0)
 *	halt_thread, reboot_mach
 *			boot(RB_BOOT, how, "") (three arguments)
 *	nmi		NMI status and parity error registers when dma_chip != 313
 *	mini_mon	serial console (zsopen/zstrygetc), no restart = 1,
 *			adb_watchdog, kdbg_connect(1), kdb_ipaddr help line
 *	softint_sched	a wrapper of the new callout_dispatch (the NeXTMach
 *			softint_sched body); new callout_remove
 *	softint_run	nmi_big through callout_dispatch; the RETRACE list is
 *			detached and run once
 *	startup_early	ns_callout instead of callout/us_callout; bufpages,
 *			nbuf (16..254) and nmfsbuf defaults
 *	startup		ns_callout_init(); mb_map of nmbclusters * MCLBYTES;
 *			animation through callout_dispatch; adb_initialize()
 *	as_tune		mg_seq >= 60 and mg_as_tune test at splhigh
 *	sendsig		no TRACE_AST block
 *	addupc		the 1997 chained-buffer form (as machdep/i386/machdep.c)
 *	data		nmfsbuf added, nsoftint 50; nrnode and waittime not here
 * Removed (not in the original object): setregs, boot, unmount_all,
 * kill_tasks, physstrat, and with them the en.h, od.h and sys/vfs.h
 * imports.  vmtime, cpu_number and dumpsys are not compiled (as NeXTMach).
 * Forms and names not fixed by the bytes are user decisions (D134):
 * the casts on intrstat, the parity address expression, the authored
 * names P_NMI_STAT, P_PERR_CLR and P_PERR_ADDR, kernel_thread_noblock_start,
 * struct ns_callout in this file, atop(mem_size / 10 / 2), the MG() forms
 * and the 07 NeXTMach copy of next/scb.h.  Changed lines and blocks are
 * marked plan 600; removed code is marked where it was.
 */
#import <cpus.h>
#import <confdep.h>
#import <cputypes.h>
#import <quota.h>
#import <show_space.h>
#import <gdb.h>

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)machdep.c	7.1 (Berkeley) 6/5/86
 */

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/dir.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/dnlc.h>
#import <sys/vm.h>
#import <sys/proc.h>
#import <sys/buf.h>
#import <sys/reboot.h>
#import <sys/conf.h>
#import <sys/vnode.h>
#import <ufs/inode.h>
#import <sys/file.h>
#import <sys/clist.h>
#import <sys/callout.h>
#import <sys/mbuf.h>
#import <sys/msgbuf.h>
#import <sys/ioctl.h>
#import <sys/signal.h>
#import <sys/tty.h>
#import <kern/task.h>
#if	QUOTA
#import <ufs/quotas.h>
#endif	QUOTA
#if	NCPUS > 1
#import <kern/processor.h>
#import <kern/thread.h>
#import <kern/lock.h>
#endif	NCPUS > 1
#import <kern/xpr.h>
#import <vm/vm_kern.h>
#import <mach/vm_param.h>	/* plan 600 (D104): NeXTMach <vm/vm_param.h> */
#import <vm/vm_page.h>
#import <m68k/vmparam.h>	/* plan 600 (D104): NeXTMach <next/vmparam.h> */
#import <next/autoconf.h>
#import <m68k/cpu.h>	/* plan 600 (D110): NeXTMach <next/cpu.h> */
/* plan 600 (D134, D024): NeXTMach next/cpu.h names used here (next/cpu.h:96,98,152,153,213,216,262) */
#define	P_MAINMEM	(SLOT_ID+0x04000000)	/* plan 600 (D134, D024): next/cpu.h:188 */
#define	I_PFAIL		I(7,1,30)	/* plan 600 (D134, D024): next/cpu.h:221 */
#define	P_NMI_STAT	(SLOT_ID+0x02200020)	/* plan 600 (D134): authored name */
#define	P_PERR_CLR	(SLOT_ID+0x02200004)	/* plan 600 (D134): authored name */
#define	P_PERR_ADDR	(SLOT_ID+0x02200008)	/* plan 600 (D134): authored name */
extern int slot_id, slot_id_bmap;
#define	SLOT_ID		slot_id
#define	SLOT_ID_BMAP	slot_id_bmap
#define	P_DSP		(SLOT_ID_BMAP+0x02008000)
#define	P_MON		(SLOT_ID+0x0200e000)
#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_BIT(i)	( 1 << (((i) >> 8) & 0x1f))
#define	I_POWER		I(3,11,2)
#import <m68k/reg.h>	/* plan 600 (D104): NeXTMach <next/reg.h> */
#import <m68k/psl.h>	/* plan 600 (D104): NeXTMach <next/psl.h> */
/* plan 600 (D134, D024): NeXTMach #import <next/pcb.h> left out (struct pcb of the staged machdep/m68k/thread.h) */
/* plan 600 (D134, D024): NeXTMach next/scr.h not imported; its names used here */
#define	SCR2_LOCALINT	0x01000000
#define	SCR2_EKG_LED	0x00000001
extern volatile int *scr2;
#import <next/scb.h>	/* plan 600 (D134): the 07 NeXTMach copy 07_kernel/nextmach/next/scb.h */
#import <m68k/cons.h>	/* plan 600 (D104): NeXTMach <next/cons.h> */
#import <next/event_meter.h>
#import <kernserv/m68k/us_timer.h>	/* plan 600 (D104): NeXTMach <next/us_timer.h> */
/* plan 600 (D134): NeXTMach next/us_timer.h us_callfree and us_callout not declared (the 1997 startup_early allocates ns_callout) */
#import	<m68k/bmap.h>	/* plan 600 (D105): NeXTMach <next/bmap.h> */
#import <dev/m68k/monreg.h>	/* plan 600 (D104): NeXTMach <nextdev/monreg.h> */
#import <nextdev/kmreg.h>
#import <dev/m68k/video.h>	/* plan 600 (D116): NeXTMach <nextdev/video.h>, the SDK header */
#import <nextdev/dma.h>
#import <mon/global.h>
#import <dev/m68k/snd_dspreg.h>	/* plan 600 (D104): NeXTMach <nextdev/snd_dspreg.h> */

#import <machine/spl.h>

int	boothowto;
vm_offset_t	usrpt, eusrpt;
int	astune_rate, astune_calls;

/*
 * Declare these as initialized data so we can patch them.
 */
#ifdef	NBUF
int	nbuf = NBUF;
#else
int	nbuf = 0;
#endif
int	nmfsbuf = 0;	/* plan 600 (D134, D024) */
#ifdef	BUFPAGES
int	bufpages = BUFPAGES;
#else
int	bufpages = 0;
#endif
/* plan 600 (D134, D024): NeXTMach nrnode removed (defined elsewhere in the original) */
#if	SHOW_SPACE
int	show_space;
#endif	SHOW_SPACE

vm_map_t	buffer_map;
char *boot_action, boot_param[128];

mon_boot (args)
	char *args;
{
	extern char boot_dev[], boot_info[], boot_file[], *boot_args;

	strcat (boot_param, boot_dev);
	strcat (boot_param, " ");
	if (boot_info[0]) {
		strcat (boot_param, boot_info);
		strcat (boot_param, " ");
	}
	strcat (boot_param, boot_file);
	strcat (boot_param, " ");
	if (args) {
		strcat (boot_param, args);
		strcat (boot_param, " ");
	}
	strcat (boot_param, boot_args);
	mon_call (boot_param);
}

mon_call (action)
	char *action;
{
	adb_watchdog(0);	/* plan 600 (D134, D024) */
	boot_action = action;
	asm ("trap #13");	/* plan 600 (D134, D024): no movl _boot_action, d0 */
	adb_watchdog(1);	/* plan 600 (D134, D024) */
}

/* plan 600 (D134, D024): 1997 kernel_thread_noblock (original 0x4093792, 0x40937ac) */
static void
kernel_thread_noblock_start(start)
	void (*start)();
{
	kernel_thread(kernel_task, start, 0);
}

void
kernel_thread_noblock(task, start)
	task_t task;
	void (*start)();
{
	callout_dispatch(CALLOUT_PRI_THREAD, kernel_thread_noblock_start, start);
}

int reboot_how;

halt_thread() {
	boot (RB_BOOT, reboot_how, "");	/* plan 600 (D134, D024) */
}

reboot_mach (how)
{
	if (kernel_task) {
		reboot_how = how;
		kernel_thread_noblock(kernel_task, halt_thread);
	} else
		boot(RB_BOOT, how|RB_NOSYNC, "");	/* plan 600 (D134, D024) */
}

/* nmi mini-monitor */
int	nmi_cont, nmi_gdb, nmi_mon, nmi_help, nmi_halt, nmi_msg, nmi_stay,
	nmi_reboot, nmi_big;
#if	XPR_DEBUG
int	nmi_xpr, nmi_xprclear;
#endif	XPR_DEBUG

nmi(ksp, usp, isp, pc, sr)	/* plan 600 (D134, D024): 1997 nmi from the original bytes 0x409382c */
{
	register struct monitor *mon = (struct monitor*) P_MON;
	union kybd_event ke;
	int do_mon = 0, do_restart = 0;
	extern int *intrstat;	/* as mini_mon */

	if (dma_chip != 313 && (*(volatile int *)P_NMI_STAT & 1)) {	/* plan 600 (D134, D024) */
		*(volatile int *)P_NMI_STAT = 0;
		do_mon = 1;
	} else {
		ke.data = mon->mon_km_data;
		mon->mon_csr.km_clr_nmi = 1;
		if (ke.k.up_down != 1) {
			if (ke.k.command_left && ke.k.command_right)
				do_mon = 1;
			else if (ke.k.command_left == 0)
				do_restart = 1;
		}
	}
	if (dma_chip != 313 && (*(volatile int *)intrstat & I_BIT(I_PFAIL))) {
		u_int simm;
		caddr_t mainmem;	/* plan 600 (D134, D024) */

		*(volatile int *)P_PERR_CLR = 0;	/* plan 600 (D134, D024) */
		*(volatile int *)P_PERR_CLR = 0;
		simm = (*(volatile u_int *)P_PERR_ADDR -	/* plan 600 (D134, D024) */
			(u_int)(mainmem = (caddr_t)P_MAINMEM)) /
			(0x08000000 / num_regions);
		printf("parity error at address 0x%x, SIMM memory sockets %d and %d (%s)\n",
			*(volatile int *)P_PERR_ADDR, simm & ~1, (simm & ~1) | 1,
			(simm & 1) ? "back" : "front");
		panic("parity error");
	}
	if (do_mon)
		mini_mon("nmi", "NMI Mini-Monitor (type \"?\" for help)",
			ksp, usp, isp, pc, sr);
	else if (do_restart)
		mini_mon("restart", "Restart/Power-Off");
}

mini_mon(prompt, title, ksp, usp, isp, pc, sr)
	char *prompt, *title;
{
	register int i, saved = 0, s = splhigh(), restart, c, panic, serial;	/* plan 600 (D134, D024) */
	char line[256];
	extern int zsopen();	/* plan 600 (D134, D024) */
	extern int *intrstat;
	extern struct mon_global *mon_global;
	struct mon_global *mg = mon_global;

	restart = strcmp(prompt, "restart") == 0;
	panic = strcmp(prompt, "panic") == 0;
	serial = cdevsw[major(cons_tp->t_dev)].d_open == zsopen;	/* plan 600 (D134, D024) */
	if ((cons_tp != &cons || (km.flags & KMF_SEE_MSGS) == 0) && !serial) {	/* plan 600 (D134, D024) */
		saved = 1;
		if (restart)	/* plan 600 (D134, D024): NeXTMach restart = 1 removed */
			kmpopup(title, POPUP_ALERT, 50, 6, 0);
		else
			kmpopup(title, POPUP_NOM, 0, 0, 0);
		if (panic) {	/* plan 600 (D134, D024) */
			kmioctl(0, KMIOCDUMPLOG, 0, 0);
			if ((ksp & RB_DEBUG) == 0)
				return;
			printf("\n");	/* plan 600 (D134, D024) */
		}
	} else
		nmi_prf("\n");
	adb_watchdog(0);	/* plan 600 (D134, D024) */
	if (restart) {
		nmi_prf("Restart or power off?  Type r to restart,\n");
		nmi_prf("press Power key to power off.  Type n to cancel.\n");
		while (1) {
			c = serial ? zstrygetc(cons_tp->t_dev) : kmtrygetc();	/* plan 600 (D134, D024) */
			if (c == 'r')
				reboot_mach(RB_AUTOBOOT);
			if (c == 'h')
				reboot_mach(RB_HALT);
			if (c != -1)
				break;
			if ((*intrstat & I_BIT(I_POWER)) && rtc_intr()) {
				vidStopAnimation();	/* Signal the ROM */
				vidSuspendAnimation();	/* Mask retrace interrupts */
				reboot_mach(RB_POWERDOWN | RB_EJECT);
				break;
			}
		}
		goto out;
	}
	if (strcmp(prompt, "nmi") == 0)
		nmi_prf("nmi: pc 0x%x sr 0x%x isp 0x%x ksp 0x%x "
			"usp 0x%x\n", pc, sr, isp, ksp, usp);

	while (1) {
		nmi_prf("%s> ", prompt);
		
		/* check for network debugger connection */
		do {
			c = serial ? zstrygetc(cons_tp->t_dev) : kmtrygetc();	/* plan 600 (D134, D024) */
#if	GDB
			if (kdbg_connect(1))	/* plan 600 (D134, D024) */
				goto cont;
#endif	GDB
		} while (c == -1);
		line[0] = c;
		if (c == '\n' || c == '\r') {
			nmi_prf("\n");
			line[0] = 0;	/* plan 600 (D134, D024) */
		} else {
			nmi_prf("%c", c);
			gets(line, &line[1]);
		}
		if (getargs(line, 1) || nmi_help) {
			nmi_help = 0;
			nmi_prf("commands are: (can be abbreviated)\n"
#if	GDB
				"\tgdb - break to debugger\n"
				"\tkdb_ipaddr=n - set default ip address\n"	/* plan 600 (D134, D024) */
#endif	GDB
				"\t?, help - print this list\n");
#if	XPR_DEBUG
			nmi_prf(
				"\txpr - dump xprbufs to screen\n"
				"\txpr=n - dump last n xprbufs\n"
				"\txprclear - clear xprbufs\n");
#endif	XPR_DEBUG
			nmi_prf(
				"\tstay - keep this window around\n"
				"\treboot - sync and reboot system\n"
				"\thalt - sync and halt system\n"
				"\tmonitor - exit to monitor\n"
				"\tmsg - dump kernel msg buffer to screen\n"
				"\tmsg=n - dump last n msg buffers\n"
				"\tbig - make NMI window bigger\n"
				"\tcontinue - resume execution\n"
				"or set any kernel flag (e.g. debug=2)\n"
				"or examine any kernel flag (e.g. debug=)\n");
			continue;
		}
#if	GDB
		if (nmi_gdb) {
			nmi_gdb = 0;
			asm("trap #15");	/* return to gdb */	/* plan 600 (D134, D024) */
			break;
		} else
#endif	GDB
		if (nmi_big) {
			if (panic) {
				nmi_prf ("can't make window bigger after a panic\n");
				nmi_big = 0;
				continue;
			}
			break;
		} else
		if (nmi_cont) {
			nmi_cont = 0;
			break;
		} else
		if (nmi_mon) {
			nmi_mon = 0;
			mon_call("-h");
			km_clear_screen();
			break;
		} else
		if (nmi_halt) {
			nmi_halt = 0;
			reboot_mach(RB_HALT);
			goto out;
		} else
		if (nmi_reboot) {
			nmi_reboot = 0;
			reboot_mach(RB_AUTOBOOT);
			goto out;
		} else
		if (nmi_msg) {
			int nlines, col;
			char *mp, c;

			nlines = km.nc_h * 3/4;
			col = 0;
			if (pmsgbuf->msg_magic != MSG_MAGIC)
				continue;
			mp = &pmsgbuf->msg_bufc[pmsgbuf->msg_bufx];
			while (nmi_msg > 1) {
				do {
					if (mp == pmsgbuf->msg_bufc)
						mp = &pmsgbuf->msg_bufc
							[MSG_BSIZE];
					mp--;
				} while (*mp != '\n');
				nmi_msg--;
			}
			nmi_msg = 0;
			do {
				if (c = *mp) {
					cnputc (*mp);
					if (++col >= km.nc_w || *mp == '\n') {
						col = 0;
						nlines--;
					}
				}
				if (nlines <= 0) {
					if (c != '\n')
						cnputc ('\n');
					nmi_prf ("more? ");
					gets (line, line);
					if (*line == 'n' || *line == 'q')
						break;
					nlines = km.nc_h * 3/4;
				}
				if (++mp >= &pmsgbuf->msg_bufc[MSG_BSIZE])
					mp = pmsgbuf->msg_bufc;
			} while (mp != &pmsgbuf->msg_bufc[pmsgbuf->msg_bufx]);
			if (c != '\n')
				cnputc ('\n');
		}
#if	XPR_DEBUG
		else
		if (nmi_xpr) {
			extern struct xprbuf *xprptr, *xprlast, *xprbase;
			register struct xprbuf *x = xprptr;
			register int nlines, col, last_ts;
			static xpr_hdr;
			char *sp, c;

			if (!x) {
				nmi_prf("xpr tracing not enabled\n");
			}
			nlines = km.nc_h * 3/4;
			col = 0;
			xpr_hdr = 1;
			while (nmi_xpr > 1) {
				if (x == xprbase)
					x = xprlast;
				else
					x--;
				nmi_xpr--;
			}
			nmi_xpr = 0;
			last_ts = x->timestamp;
			while (1) {
				if (x->msg && (xpr_hdr || x->msg[0] == '\n')) {
					if (x->msg[0] == '\n' && col)
						cnputc ('\n');
					sprintf(line, "%u<%d>:\t",
					    x->timestamp,
					    x->timestamp - last_ts);
					col = strlen (line) + 7;
					nmi_prf (line);
					last_ts = x->timestamp;
					xpr_hdr = 0;
					if (x->msg[0] == '\n')
						nlines--;
				}
				if (x->msg) {
					if (x->msg[strlen(x->msg)-1] == '\n')
						xpr_hdr = 1;
					sp = line;
					sprintf(sp, x->msg, x->arg1, x->arg2,
					       x->arg3, x->arg4, x->arg5);
					while (*sp) {
						cnputc (c = *sp++);
						if (c == '\t')
							col += 7;
						if (++col >= km.nc_w ||
						    c == '\n') {
							col = 0;
							nlines--;
						}
					}
				}
				if (nlines <= 0) {
					if (c != '\n')
						cnputc ('\n');
					nmi_prf("more? ");
					gets(line, line);
					if (*line == 'n' || *line == 'q')
						break;
					nlines = km.nc_h * 3/4;
				}
				if (++x == xprlast)
					x = xprbase;
				if (x == xprptr) {
					if (xpr_hdr == 0)
						cnputc ('\n');
					break;
				}
			}
		} else
		if (nmi_xprclear) {
			extern struct xprbuf *xprptr, *xprlast, *xprbase;
			register struct xprbuf *x = xprbase;

			nmi_xprclear = 0;
			while (x != xprlast) {
				x->msg = 0;
				x++;
			}
			xprptr = xprbase;
		}
#endif	XPR_DEBUG
	}
cont:
	nmi_prf ("\n");
out:
	if (saved && !nmi_stay)
		kmrestore();
	nmi_stay = 0;
	resynctime();
	adb_watchdog(1);	/* plan 600 (D134, D024) */
	splx(s);
}

/* keep nmi messages from getting written to message log */
nmi_prf(fmt, x1)
	char *fmt;
	unsigned x1;
{
	prf(fmt, &x1, 1, 0);
}

/*
 *	Routines that implement software interrupts.
 */
int	nsoftint = 50;	/* plan 600 (D134, D024): NeXTMach 100 */			/* number of simultaneous softints */

struct	softint {
	struct	softint *si_next;	/* pointer to next cell */
	func	si_proc;		/* procedure to call */
	caddr_t	si_arg;			/* argument to called procedure */
} *softint, *softint_head[N_CALLOUT_PRI], *softint_tail[N_CALLOUT_PRI],
  *softint_free;

thread_t softint_thread;
decl_simple_lock_data(static,	softint_th_lock)

softint_sched (level, proc, arg)	/* plan 600 (D134, D024) */
	int level;
	func proc;
	caddr_t arg;
{
	callout_dispatch(level, proc, arg);
}

callout_dispatch (level, proc, arg)	/* plan 600 (D134, D024) */
	register int level;
	register func proc;
	register caddr_t arg;
{
	register struct softint *si, **head, **tail;
	register int s;
	int softint_run();

	if (level < 0 || level >= N_CALLOUT_PRI) {
		printf("callout_dispatch(%d, 0x%x, %d)\n", level, proc, arg);	/* plan 600 (D134, D024) */
		panic("callout_dispatch");
	}

	if (level == CALLOUT_PRI_NOW) {
		(*proc)(arg);
		return;
	}

	s = spldma();
	head = &softint_head[level];
	for (si = *head; si; si = si->si_next)
		if (proc == si->si_proc && arg == si->si_arg)
			goto out;		/* duplicate entry */
	if ((si = softint_free) == 0)
		panic("out of softints");
	softint_free = si->si_next;
	tail = &softint_tail[level];
	if (*head) {
		(*tail)->si_next = si;
		*tail = si;
	} else {
		*head = *tail = si;

		switch (level) {
		case CALLOUT_PRI_RETRACE:
			vidInterruptEnable( softint_run, (void *)CALLOUT_PRI_RETRACE);
			break;
		}
	}
	si->si_next = 0;
	si->si_proc = proc;
	si->si_arg = arg;

	switch (level) {
	case CALLOUT_PRI_SOFTINT0:
	case CALLOUT_PRI_SOFTINT1:
		*scr2 |= SCR2_LOCALINT * (level + 1);
		break;
	case CALLOUT_PRI_DSP:
		((struct dsp_regs *)P_DSP)->icr |= ICR_TREQ;
		break;
	case CALLOUT_PRI_THREAD:	/* plan 600 (D134, D024) */
		callout_dispatch(CALLOUT_PRI_SOFTINT0,
			thread_wakeup, (int)softint_thread);
		break;
	}
out:
	splx(s);
}

/* plan 600 (D134, D024): 1997 callout_remove (original 0x4093fb8) */
int
callout_remove(proc, arg)
	register func proc;
	register caddr_t arg;
{
	register struct softint *si, *psi, **head, **tail;
	register int level, s;

	s = spldma();
	for (level = 0; level < N_CALLOUT_PRI; level++) {
		head = &softint_head[level];
		tail = &softint_tail[level];
		for (psi = si = *head; si; psi = si, si = si->si_next) {
			if (proc == si->si_proc && arg == si->si_arg) {
				if (si == *head) {
					*head = si->si_next;
					psi = 0;
				} else
					psi->si_next = si->si_next;
				if (si == *tail)
					*tail = psi;
				si->si_next = softint_free;
				softint_free = si;
				splx(s);
				return 1;
			}
		}
	}
	splx(s);
	return 0;
}

void softint_th(void)
{
	int s;
	simple_lock_init(&softint_th_lock);

	while (1) {
		softint_run(CALLOUT_PRI_THREAD);
		s = splsched();
		if (softint_head[CALLOUT_PRI_THREAD] == 0) {
			simple_lock(&softint_th_lock);
			thread_sleep((int)softint_thread,
				     simple_lock_addr(softint_th_lock),
				     TRUE);
		}
		splx(s);
	}
}

softint_run (level)
	register int level;
{
	register struct softint *si, *psi, *ssi, **head, **tail, *lhead, *ltail;	/* plan 600 (D134, D024) */
	register func proc;
	register caddr_t arg;
	register int s;
#ifdef DEBUG
	int ipl;

	switch (level) {
		default:
			ASSERT(curipl() == level + 1);
			break;
		case CALLOUT_PRI_THREAD:
			ASSERT(curipl() == 0);
			break;
	}
#endif DEBUG

	if (nmi_big) {
		int km_big();
		
		nmi_big = 0;
		callout_dispatch(CALLOUT_PRI_THREAD, km_big, 0);	/* plan 600 (D134, D024) */
	}

	switch (level) {
	case CALLOUT_PRI_SOFTINT0:
	case CALLOUT_PRI_SOFTINT1:

		/* ack interrupt */
		s = spldma();
		*scr2 &= ~(SCR2_LOCALINT * (level + 1));
		splx(s);

		/* fall into ... */

	case CALLOUT_PRI_THREAD:
	case CALLOUT_PRI_DSP:		/* dsp does intr ack. */
		while (1) {
			s = spldma();
			head = &softint_head[level];
			if (si = *head) {
				proc = si->si_proc;
				arg = si->si_arg;
				*head = si->si_next;
				si->si_next = softint_free;
				softint_free = si;
				if (*head == 0)
					softint_tail[level] = 0;
			}
			splx(s);
			if (si == 0)
				return;
			(proc)(arg);
#ifdef DEBUG
			if (curipl() != srtoipl(s)) {
				XPR(XPR_MEAS, ("BAD CALLOUT IPL: func 0x%x "
				    "old ipl %d new ipl %d\n",
				    proc, srtoipl(s), curipl()));
			}
#endif DEBUG

		}
		break;

	case CALLOUT_PRI_RETRACE:	/* plan 600 (D134, D024): run the detached list once */
		head = &softint_head[level];
		tail = &softint_tail[level];
		s = spldma();
		lhead = *head;
		ltail = *tail;
		*tail = 0;
		*head = 0;
		splx(s);
		for (si = lhead, psi = 0; si; ) {
			proc = si->si_proc;
			arg = si->si_arg;
			if ((proc)(arg) == 0) {
				if (psi) {
					psi->si_next = si->si_next;
					if (ltail == si)	/* plan 600 (D134, D024) */
						ltail = psi;
				} else if ((lhead = si->si_next) == 0)
					ltail = 0;
				s = spldma();
				ssi = si->si_next;
				si->si_next = softint_free;
				softint_free = si;
				si = ssi;
				splx(s);
			} else {
				psi = si;
				si = si->si_next;
			}
		}
		s = spldma();
		if (*head == 0) {
			*head = lhead;
			*tail = ltail;
		} else {
			ltail->si_next = *head;
			*head = lhead;
		}
		splx(s);
		break;
	}
}

/*
 * Machine-dependent early startup code
 */
/* plan 600 (D134, D024): the m68k callout entry of 07_kernel/v183.34/m68k/src/kern/ns_timer.c:123-129 */
struct ns_callout {
	struct ns_callout	*c_next;
	ns_time_t		c_time;
	void			*c_arg;
	func			c_func;
	int			c_pri;
};
extern struct ns_callout *ns_callout;	/* plan 600 (D134, D024) */

startup_early()
{
	register caddr_t firstaddr, v;

	v = firstaddr = (caddr_t) mem_region[0].first_phys_addr;
#if	SHOW_SPACE
#define	valloc(name, type, num)	\
	(name) = (type *)(v); (v) = (caddr_t)((name)+(num));\
	if (show_space) \
		printf(#name " = %d(0x%x) bytes @%x, %d cells @ %d bytes\n",\
		 num*sizeof(type), num*sizeof(type), name, num, sizeof(type))
#define	valloclim(name, type, num, lim)	\
	(name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)));\
	if (show_space) \
		printf(#name " = %d(0x%x) bytes @%x, %d cells @ %d bytes\n",\
		 num*sizeof(type), num*sizeof(type), name, num, sizeof(type))
#else	SHOW_SPACE
#define	valloc(name, type, num)	\
	(name) = (type *)(v); (v) = (caddr_t)((name)+(num));
#define	valloclim(name, type, num, lim)	\
	(name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)));
#endif	SHOW_SPACE
	valloc(cfree, struct cblock, nclist);
	valloc(ns_callout, struct ns_callout, ncallout);	/* plan 600 (D134, D024) */
	valloc(softint, struct softint, nsoftint);
	valloc(ncache, struct ncache, ncsize);
#if	QUOTA
	valloclim(dquot, struct dquot, ndquot, dquotNDQUOT);
#endif	QUOTA
	
#define	PRIVATE_BUFS 0 /* Don't turn this on until we have fault ahead etc. */
	/*
	 * Use a small number of bufpages to support indirect blocks
	 * and a large number of buf headers to support the pager's use
	 * of private pages.
	 */
 	if (bufpages == 0)
		bufpages = atop(mem_size / 10 / 2) & ~1;	/* plan 600 (D134, D024) */
	if (nbuf == 0) {	/* plan 600 (D134, D024) */
		if ((nbuf = bufpages) < 16)
			nbuf = 16;
	}
	if (nbuf > 254)
		nbuf = 254;
	if (bufpages > nbuf * (MAXBSIZE / PAGE_SIZE))
		bufpages = nbuf * (MAXBSIZE / PAGE_SIZE);
	valloc(buf, struct buf, nbuf);
	if (nmfsbuf == 0)	/* plan 600 (D134, D024) */
		nmfsbuf = nbuf / 2;
#undef	valloc
#undef	valloclim

	/*
	 * Clear space allocated thus far.
	 */
	bzero(firstaddr, v - firstaddr);
	mem_region[0].first_phys_addr = (int) v;

#if	SHOW_SPACE
	if (show_space)
		printf("early data structures %d@%x-%x\n",
			v - firstaddr, firstaddr, v);
#endif	SHOW_SPACE
}

startup(firstaddr)
	caddr_t	firstaddr;
{
	register unsigned int i;
	register caddr_t v;
	int base, residual, e;
	vm_size_t	size;
	kern_return_t	ret;
	vm_offset_t	trash_offset;
	extern long map_size;
	extern struct mon_global *mon_global;
	struct mon_global *mg = mon_global;
	extern int console_o;
	int as_tune(), msize;
	extern u_int fpu_version;
#if	SHOW_SPACE
	extern int	vm_page_wire_count;
#endif	SHOW_SPACE

	km_switch_to_vm();	/* Have km package remap console frame buffer */
#if	SHOW_SPACE
	if (show_space)
		printf("startup: enter wire %d\n", vm_page_wire_count);
#endif	SHOW_SPACE

	panic_init();

	/*
	 * Good {morning,afternoon,evening,night}.
	 */

	printf(version);
	printf("FPU version 0x%x\n", fpu_version >> 24);

#define MEG	(1024*1024)
	msize = roundup(mem_size, MEG);
	printf("physical memory = %d.%d%d megabytes.\n", msize/MEG,
		((msize%MEG)*10)/MEG,
		((msize%(MEG/10))*100)/MEG);

	/*
	 * Allocate space for system data structures.
	 * The first available real memory address is in "firstaddr".
	 * The first available kernel virtual address is in "v".
	 * As pages of kernel virtual memory are allocated, "v" is incremented.
	 * As pages of memory are allocated and cleared,
	 * "firstaddr" is incremented.
	 * An index into the kernel page table corresponding to the
	 * virtual memory address maintained in "v" is kept in "mapaddr".
	 */
	/*
	 *	It is possible that someone has allocated some stuff
	 *	before here, (like vcons_init allocates the unibus map),
	 *	so, we look for enough space to put the dynamic data
	 *	structures, then free it with the assumption that we
	 *	can just get it back later (at the same address).
	 */
	firstaddr = (caddr_t) round_page(firstaddr);
	/*
	 *	Between the following find, and the next one below
	 *	we can't cause any other memory to be allocated.  Since
	 *	below is the first place we really need an object, it
	 *	will cause the object zone to be expanded, and will
	 *	use our memory!  Therefore we allocate a dummy object
	 *	here.  This is all a hack of course.
	 */
	ret = vm_map_find(kernel_map, vm_object_allocate(0), (vm_offset_t) 0,
		&firstaddr,
		8*1024*1024, TRUE);	/* size big enough for worst case */
	ASSERT(ret == KERN_SUCCESS);
	vm_map_remove(kernel_map, firstaddr, firstaddr + 8*1024*1024);
	v = firstaddr;
#if	SHOW_SPACE
#define	valloc(name, type, num)	\
	(name) = (type *)(v); (v) = (caddr_t)((name)+(num));\
	if (show_space) \
		printf(#name " = %d(0x%x) bytes @%x, %d cells @ %d bytes\n",\
		 num*sizeof(type), num*sizeof(type), name, num, sizeof(type))
#define	valloclim(name, type, num, lim)	\
	(name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)));\
	if (show_space) \
		printf(#name " = %d(0x%x) bytes @%x, %d cells @ %d bytes\n",\
		 num*sizeof(type), num*sizeof(type), name, num, sizeof(type))
#else	SHOW_SPACE
#define	valloc(name, type, num)	\
	(name) = (type *)(v); (v) = (caddr_t)((name)+(num));
#define	valloclim(name, type, num, lim)	\
	(name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)));
#endif	SHOW_SPACE

	/*
	 * Now allocate buffers proper.  They are different than the above
	 * in that they usually occupy more virtual memory than physical.
	 */
	valloc(buffers, char, MAXBSIZE * nbuf);
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
#if	SHOW_SPACE
	if (show_space)
		printf("bufpages %d nbuf %d base %d residual %d\n",
			bufpages, nbuf, base, residual);
#endif	SHOW_SPACE

	/*
	 *	Allocate virtual memory for buffer pool.
	 */
	v = (caddr_t) round_page(v);
	size = (vm_size_t) (v - firstaddr);
	buffer_map = kmem_suballoc(kernel_map, &firstaddr,
		&trash_offset /* max */, size, TRUE);
	ret = vm_map_find(buffer_map, vm_object_allocate(size),
		(vm_offset_t) 0, &firstaddr, size, FALSE);
	ASSERT(ret == KERN_SUCCESS);
#if	SHOW_SPACE
	if (show_space)
		printf("vm buffer pool wire %d\n", vm_page_wire_count);
#endif	SHOW_SPACE

	for (i = 0; i < nbuf; i++) {
		vm_size_t	thisbsize;
		vm_offset_t	curbuf;

		/*
		 * First <residual> buffers get (base+1) physical pages
		 * allocated for them.  The rest get (base) physical pages.
		 *
		 * The rest of each buffer occupies virtual space,
		 * but has no physical memory allocated for it.
		 */

		thisbsize = PAGE_SIZE*(i < residual ? base+1 : base);
		curbuf = (vm_offset_t)buffers + i * MAXBSIZE;
		vm_map_pageable(buffer_map, curbuf, curbuf+thisbsize, FALSE);
	}

#if	SHOW_SPACE
	if (show_space)
		printf("buffers wired wire %d\n", vm_page_wire_count);
#endif	SHOW_SPACE

	{
		register int	nbytes;
		extern int	vm_page_free_count;

		nbytes = ptoa(vm_page_free_count);
		printf("available memory = %d.%d%d megabytes.\n", nbytes/MEG,
			((nbytes%MEG)*10)/MEG,
			((nbytes%(MEG/10))*100)/MEG);
		nbytes = ptoa(bufpages);
		printf("using %d buffers containing %d.%d%d megabytes of memory\n",
			nbuf,
			nbytes/MEG,
			((nbytes%MEG)*10)/MEG,
			((nbytes%(MEG/10))*100)/MEG);
	}

	/*
	 * Initialize callouts
	 */
	ns_callout_init();	/* plan 600 (D134, D024) */

	/*
	 * Initialize softints
	 */
	softint_free = softint;
	for (i = 1; i < nsoftint; i++)
		softint[i-1].si_next = &softint[i];
	softint[nsoftint-1].si_next = 0;
	
	/*
	 * Initialize memory allocator and swap
	 * and user page table maps.
	 */
	mb_map = kmem_suballoc(kernel_map, &mbutl, &embutl,
		nmbclusters * MCLBYTES, FALSE);	/* plan 600 (D134, D024): NeXTMach ptoa(nmbclusters) */

	/* boot icon animation */
	if ((km.flags & KMF_SEE_MSGS) == 0 && console_o == CONS_O_BITMAP &&	/* plan 600 (D134, D024) */
	    *MG(short*, MG_seq) >= 24 &&
	    *MG(int*, MG_anim_run))
		callout_dispatch(CALLOUT_PRI_RETRACE,
			*MG(int*, MG_anim_run), 0);

	/*
	 *	Just tune once within 1/hz seconds as periodic
	 *	tuning breaks DMA for reasons we don't understand.
	 */
	if (bmap_chip) {
		if (astune_rate == 0)
			astune_rate = 1;
		timeout (as_tune, 0, astune_rate*hz);
	}

	/*
	 * Configure the system.
	 */
	if (dma_chip != 313)	/* plan 600 (D134, D024) */
		adb_initialize();
	configure();

#if	SHOW_SPACE
	if (show_space)
		printf("startup: exit wire %d\n", vm_page_wire_count);
#endif	SHOW_SPACE
}

/* retune AS periodically while the BMAP chip warms up */
as_tune (calls)
{
	extern struct mon_global *mon_global;
	struct mon_global *mg = mon_global;
	int s;

	if (mg->mg_seq >= 60 && mg->mg_as_tune) {	/* plan 600 (D134, D024) */
		s = splhigh();
		mg->mg_as_tune();
		splx(s);
	}
	if (++calls < astune_calls)
		timeout (as_tune, calls, astune_rate*hz);
}

#ifdef PGINPROF
/*
 * Return the difference (in microseconds)
 * between the  current time and a previous
 * time as represented  by the arguments.
 * If there is a pending clock interrupt
 * which has not been serviced due to high
 * ipl, return error code.
 */
vmtime(otime, olbolt, oicr)
	register int otime, olbolt;
{
	struct timeval tv;
	microtime(&tv);
	return(((tv-otime)*HZ + lbolt-olbolt)*(1000000/HZ));
}
#endif

/* plan 600 (D134, D024): NeXTMach setregs removed (not in the original object) */

#if	DEBUG
int signaltrace;
#endif	DEBUG

/*
 * Send an interrupt to process.
 *
 * The stack is setup to call the signal handler which is
 * really a signal trampoline created by libc.
 * The library does this by intercepting the sigvec
 * system call, saving the address of the user's signal
 * handler, and specifing sigtramp as the signal handler
 * to the actual sigvec syscall.  When sigtramp gets called in
 * response to the signal it calls the user's signal handler
 * and then does a syscall to the sigreturn routine below.
 * This scheme keeps the signal trampoline out of the kernel
 * u area or PCB and in libc where it belongs.  In the library
 * it's easier to save state (like the FPC) than if the
 * trampoline code is in the kernel.
 *
 * In the code below a prototype stack is built and copied
 * to the user stack with copyout because we have no direct
 * access to the user stack.
 */
sendsig(p, sig, mask)
	int (*p)(), sig, mask;
{
	register struct regs *r;
	struct sigframe {
		int	sf_signum;
		int	sf_code;
		struct	sigcontext *sf_scp;
	} sf;
	register struct sigframe *sfp;
	struct sigcontext sc;
	register struct sigcontext *scp;
	int oonstack;

	r = (struct regs*) u.u_ar0;
	oonstack = u.u_onstack;
	if (!u.u_onstack && (u.u_sigonstack & sigmask(sig))) {
		scp = (struct sigcontext *)u.u_sigsp - 1;
		u.u_onstack = 1;
	} else
		scp = (struct sigcontext *)r->r_sp - 1;
	sfp = (struct sigframe *)scp - 1;
	/* 
	 * Build the argument list for the signal handler.
	 */
	sf.sf_signum = sig;
	if (sig == SIGILL || sig == SIGFPE || sig == SIGEMT) {
		sf.sf_code = u.u_code;
		u.u_code = 0;
	} else
		sf.sf_code = 0;
	sf.sf_scp = scp;
	if (copyout((caddr_t) &sf, (caddr_t) sfp, sizeof(sf)))
		goto bad;
	/*
	 * Build the signal context to be used by sigreturn.
	 */
	sc.sc_onstack = oonstack;
	sc.sc_mask = mask;
	sc.sc_sp = r->r_sp;
	sc.sc_pc = r->r_pc;
	sc.sc_ps = r->r_sr;
	sc.sc_d0 = r->r_d0;
#if	DEBUG
	if (signaltrace) {
		printf("sendsig: sigcontext: sp 0x%x sr 0x%x pc 0x%x, sighndlr=0x%x\n",
			r->r_sp, r->r_sr, r->r_pc, p);
		printf("\tsignum %d code %d scp 0x%x\n", sig, sf.sf_code, scp);
	}
#endif	DEBUG

	/*
	 *	If tracing for AST, then don't restore with tracing
	 *	enabled in case a future AST request is made which
 	 *	would interpret the existing tracing as user requested
	 *	instead of AST requested.
	 */

	/* plan 600 (D134, D024): NeXTMach TRACE_AST/pcb_flags test removed (the original sendsig 0x40947be has none) */
	if (copyout((caddr_t) &sc, (caddr_t) scp, sizeof(sc)))
		goto bad;
	r->r_sp = (int)sfp;
	r->r_pc = (int)p;
	return;
bad:
	u.u_signal[SIGILL] = SIG_DFL;
	sig = sigmask(SIGILL);
	u.u_procp->p_sigignore &= ~sig;
	u.u_procp->p_sigcatch &= ~sig;
	u.u_procp->p_sigmask &= ~sig;
	psignal(u.u_procp, SIGILL);
	return;
}

/*
 * System call to cleanup state after a signal has been taken.
 * Called by signal trampoline code in libc.
 * Reset signal mask and stack state from context left by sendsig (above).
 * Return to previous pc and sr as specified by context left by sendsig.
 * Check carefully to make sure that the user has not modified the
 * sr to gain improper priviledges or to cause a machine fault.
 *
 * FIXME: when Sun binary compatibility isn't an issue anymore modify
 * to use 4.3 syscall semantics: syscall code #139 -> #103, passes
 * sigcontext argument.  Modify libc/sigtramp accordingly!
 */

sigreturn()
{
	struct sigcontext sc, *scp = 0;
	register struct regs *r = (struct regs*) u.u_ar0;

	/* + NBPW skips over syscall return pc */
	if (copyin((caddr_t) r->r_sp + NBPW, (caddr_t) &scp, sizeof(scp)))
		goto bad;
	if (copyin ((caddr_t) scp, (caddr_t) &sc, sizeof(sc)))
		goto bad;
	u.u_eosys = JUSTRETURN;
	u.u_onstack = sc.sc_onstack & 01;
	u.u_procp->p_sigmask = sc.sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	r->r_sp = sc.sc_sp;
	r->r_pc = sc.sc_pc;
	r->r_sr = sc.sc_ps;
	r->r_d0 = sc.sc_d0;
#if	DEBUG
	if (signaltrace)
		printf("sigreturn: sigcontext: sp 0x%x sr 0x%x pc 0x%x\n",
			r->r_sp, r->r_sr, r->r_pc);
#endif	DEBUG
	r->r_sr &= ~SR_USERCLR;
bad:
	return;
}

#import <mach/machine.h>	/* plan 600 (D104): NeXTMach <sys/machine.h> */
halt_cpu()
{
	machine_slot[cpu_number()].running = FALSE;
	while (1)
		asm("stop #0");		/* FIXME: good enough? */
}

/* plan 600 (D134, D024): NeXTMach boot (and waittime) removed (not in the original object) */

/* plan 600 (D134, D024): NeXTMach unmount_all (and its sys/vfs.h import) removed (not in the original object) */

/* plan 600 (D134, D024): NeXTMach kill_tasks removed (not in the original object) */

#if 0
int	dumpmag = 0x8fca0101;	/* magic number for savecore */
long	dumpsize = 0;		/* also for savecore */

/*
 *	Dump the system by writing out all physical regions of memory.
 *	Kernel debuggers will have to reconstruct the "holes" between
 *	regions by looking at the information in NeXT_phys_region.
 */
dumpsys()
{
	register int i, bno, err;
	register vm_offset_t pa;
	register mem_region_t rp;
	int (*dumper)(), blkinc;

	if (dumpdev == NODEV) {
		printf("no dump device set\n");
		return;
	}
	dumpsize = btoc(mem_size);
	printf("\ndumping to dev (%d,%d) offset %d\n",
		major(dumpdev), minor(dumpdev), dumplo);

	dumper = bdevsw[major(dumpdev)].d_dump;
	bno = dumplo;
	for (i = 0; i < num_regions && !err; i++) {
		rp = &mem_region[i];
		for (pa = rp->base_phys_addr; pa < rp->last_phys_addr && !err;
		    pa += NeXT_page_size) {
			err = (*dumper)(dumpdev, pa, bno, &blkinc);
			bno += blkinc;
		}
	}

	printf("dump ");
	switch (err) {

	case ENXIO:
		printf("device bad\n");
		break;

	case EFAULT:
		printf("device not ready\n");
		break;

	case EINVAL:
		printf("area improper\n");
		break;

	case EIO:
		printf("i/o error\n");
		break;

	case 0:
		printf("succeeded\n");
		break;

	default:
		printf("failed: unknown error\n");
		break;
	}
}
#endif

/* plan 600 (D134, D024): NeXTMach physstrat removed (not in the original object) */

#if	NCPUS > 1
/*
 *	cpu_number() provides a convenient way to get the current cpu number
 *	without the hassle of including a bunch of header files.
 */
cpu_number()
{
	extern int slot_id;

	return(slot_id >> 25);
}
#endif	NCPUS > 1

#if	DEBUG
int light_acquired = 0;
#endif	DEBUG

light_on()
{
	register int s;

#if	DEBUG
	if (light_acquired)
		return;
#endif	DEBUG
#if	EVENTMETER
	if (em.flags & EMF_LEDS)
		km_send(MON_KM_USRREQ, KM_SET_LEDS(0, 3));
#endif	EVENTMETER
	s = spldma();
	*scr2 |= SCR2_EKG_LED;
	splx(s);
}

light_off()
{
	register int s;

#if	DEBUG
	if (light_acquired)
		return;
#endif	DEBUG
#if	EVENTMETER
	if (em.flags & EMF_LEDS)
		km_send(MON_KM_USRREQ, KM_SET_LEDS(0, 0));
#endif	EVENTMETER
	s = spldma();
	*scr2 &= ~SCR2_EKG_LED;
	splx(s);
}

/* plan 600 (D134, D024): the 1997 addupc (chained buffers), as 07 machdep/i386/machdep.c:162-186 */
addupc(pc, pr, ticks)
	register int pc;
	register struct uuprof *pr;
{
	register struct uuprof *p;
	register short *cell;
	short count;
	long off;

	for (p = pr; p; p = p->pr_next) {
		off = (((pc - p->pr_off)&0xffff0000) >> 16)*p->pr_scale +
			((((pc - p->pr_off)&0xffff)*p->pr_scale)>>16);
		cell = p->pr_base + off / (sizeof *cell);
		if (cell >= p->pr_base &&
		    cell < (short*) (p->pr_size + (int) p->pr_base)) {
			if (copyin (cell, (caddr_t) &count, sizeof(count))) {
				pr->pr_scale = 0;
			} else {
				count += ticks;
				copyout((caddr_t) &count, cell, sizeof(count));
			}
			return;
		}
	}
}


