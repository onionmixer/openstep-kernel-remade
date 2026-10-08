/* 
 *
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 *
 * 20-Apr-90  Doug Mitchell at NeXT
 *	Started up reaper_thread() before mounting root.
 *
 * 19-Mar-90  Gregg Kellogg (gk) at NeXT
 *	NeXT doesn't use schedcpu.
 *	Move kallocinit() to vm/vm_init.c
 *
 * 14-Feb-90  Gregg Kellogg (gk) at NeXT
 *	Changes for new scheduler:
 *		Initialize scheduler
 *		use newproc() to start ux_handler.
 *		Remove process lock initialization.
 *		Remove obsolete service_timers() kickoff
 *		do callout_lock initialization in kern_synch.c/rqinit.
 *
 * 17-Jan-90  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: Minimal cleanup.  Removed ihinit.
 *
 * 07-Nov-88  Avadis Tevanian (avie) at NeXT
 *	Removed code to use transparent addresses since it only works
 *	when we have fully populated buffers (which is a bad assumption).
 *
 * 13-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Removed dependencies on proc table.
 *
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	MACH_TIME_NEW is now standard.
 *
 * 21-Apr-88  David Black (dlb) at Carnegie-Mellon University
 *	Set kernel_only for kernel task.
 *
 * 10-Apr-88  John Seamons (jks) at NeXT
 *	NeXT: Improve TLB performance for buffers by using the
 *	transparently translated virtual address for single page sized bufs.
 *
 * 07-Apr-88  John Seamons (jks) at NeXT
 *	NeXT: reduced the allocation size of various zones to save space.
 *
 *  3-Apr-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Force the vm_map for the inode_ and device_ pager tasks to
 *	be the kernel map.
 *
 * 25-Jan-88  Richard Sanzi (sanzi) at Carnegie-Mellon University
 *	Moved float_init() call to configure() in autoconf.c
 *
 * 21-Jan-88  David Golub (dbg) at Carnegie-Mellon University
 *	Neither task_create nor thread_create return the data port
 *	any longer.
 *
 * 29-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Removed code to shuffle initial processes for idle threads;
 *	MACH doesn't need to make extra processes for them.
 *	Delinted.
 *
 * 12-Dec-87  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Added device_pager startup.  Moved setting of ipc_kernel and
 *	kernel_only flags here.
 *
 *  9-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Follow thread_terminate with thread_halt_self for new thread
 *	termination logic; extra reference no longer necessary.
 *
 *  9-Dec-87  David Black (dlb) at Carnegie-Mellon University
 *	Grab extra reference to first thread before terminating it.
 *
 *  4-Dec-87  David Black (dlb) at Carnegie-Mellon University
 *	Name changes for exc interface.  set ipc_kernel in first thread
 *	for paranoia purposes.
 *
 * 19-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Eliminated MACH conditionals, purged history.
 *
 *  5-Nov-87  David Golub (dbg) at Carnegie-Mellon University
 *	start up network service thread.
 *
 *  9-Sep-87  Peter King (king) at NeXT
 *	SUN_VFS:  Add a call to vfs_init() in setup_main().
 *
 * 17-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS:  Support credentials record in u.
 *	      Convert to Sun quota system.
 *	      Add call to dnlc_init().  Remove nchinit() call.
 *	      Call swapconf() in binit().
 */
 
#import <mach_xp.h>
#import <quota.h>
#import <cpus.h>

#import <cputypes.h>
#import <mach_old_vm_copy.h>

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)init_main.c	7.1 (Berkeley) 6/5/86
 */

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/vfs.h>
#import <sys/proc.h>
#import <sys/vnode.h>
#import <sys/conf.h>
#import <sys/buf.h>
#import <sys/clist.h>
#import <sys/dk.h>
#import <ufs/quotas.h>
#import <sys/bootconf.h>
#import <machine/reg.h>
#import <machine/cpu.h>

#import <machine/spl.h>

#import <kern/thread.h>
#import <kern/task.h>
#import <mach/machine.h>	/* plan 232: NeXTMach sys/machine.h */
#import <kern/timer.h>
#import <sys/version.h>
#import <machine/pmap.h>
#import <mach/vm_param.h>	/* plan 232: NeXTMach vm/vm_param.h */
#import <vm/vm_page.h>
#import <vm/vm_map.h>
#import <vm/vm_kern.h>
#import <vm/vm_object.h>
#import <mach/boolean.h>	/* plan 232: NeXTMach sys/boolean.h */
#import <kern/sched_prim.h>
#import <kern/zalloc.h>

#import <mach/task_special_ports.h>	/* plan 232: NeXTMach sys/task_special_ports.h */
#import <sys/ux_exception.h>

extern void	ux_handler();

long	cp_time[CPUSTATES];
int	dk_ndrive = DK_NDRIVE;
int	dk_busy;
long	dk_time[DK_NDRIVE];
long	dk_seek[DK_NDRIVE];
long	dk_xfer[DK_NDRIVE];
long	dk_wds[DK_NDRIVE];
#ifdef	mips
long	dk_mspw[DK_NDRIVE];
#else	mips
float	dk_mspw[DK_NDRIVE];
#endif	mips
#if	NeXT
long	dk_bps[DK_NDRIVE];
#endif	NeXT

long	tk_nin;
long	tk_nout;

#if	NeXT
thread_t	pageoutThread;
#endif	NeXT

dev_t	rootdev;		/* device of the root */
dev_t	dumpdev;		/* device to take dumps on */
long	dumplo;			/* offset into dumpdev */
int	show_space;
long	hostid;
char	hostname[MAXHOSTNAMELEN];
int	hostnamelen;
char	domainname[MAXDOMNAMELEN];
int	domainnamelen;

extern struct	timeval boottime;	/* plan 401 (D060): defined in kern_time.c; the original init_main does not mention it */
struct	timeval time;
int	hz;
int	tick;
int	lbolt;				/* awoken once a second */

vm_map_t	kernel_pageable_map;
vm_map_t	mb_map;

int	cmask = CMASK;

#if	POSIX_KERN
/* plan 232: process 0 POSIX state (commons in the original) */
struct posix_proc	*px;
struct pgrp	pgrp0;
struct session	session0;
#endif	POSIX_KERN
/*
 * Initialization code.
 * Called from cold start routine as
 * soon as a stack and segmentation
 * have been established.
 * Functions:
 *	clear and free user core
 *	turn on clock
 *	hand craft 0th process
 *	call all initialization routines
 *	fork - process 0 to schedule
 *	     - process 1 execute bootstrap
 *	     - process 2 to page out
 */

/*
 *	Sets the name for the given task.
 */
void task_name(s)
	char		*s;
{
	int		length = strlen(s);

	bcopy(s, u.u_comm,
		length >= sizeof(u.u_comm) ? sizeof(u.u_comm) :
			length + 1);
}

/* To allow these values to be patched, they're globals here */
#import <machine/vmparam.h>
struct rlimit vm_initial_limit_stack = { DFLSSIZ, MAXSSIZ };
struct rlimit vm_initial_limit_data = { DFLDSIZ, MAXDSIZ };
struct rlimit vm_initial_limit_core = { DFLCSIZ, MAXCSIZ };

extern thread_t first_thread;

/*
 * plan 232 (authored, D024; original _main 0x102974-0x102e2c): the
 * NeXTMach main() shape with the OPENSTEP 4.2 start-up sequence.
 */
main()
{
	register int i;
	register struct proc *p;
	extern struct ucred *rootcred;
	int s;
	thread_t	th;
	extern void	idle_thread(), init_task(), vm_pageout();
	extern void	reaper_thread(), swapin_thread();
	extern void	netisr_thread(), sched_thread();
	extern void	lightning_bolt();
	extern thread_t	newproc();
	static int	classHandler();

	/*
	 * set up system process 0 (swapper)
	 */
	pqinit();
	p = kernel_proc;
	kernel_task->proc = kernel_proc;
	p->p_pid = 0;
	pidhash_enter(p);
	p->task = kernel_task;
	s = splhigh();
	splx(s);
	calloutInitialize();
	switch_unix_context(current_thread());

	p->p_stat = SRUN;
	p->p_flag |= SLOAD|SSYS;
	p->p_nice = NZERO;
	simple_lock_init(&p->siglock);
	p->sigwait = FALSE;
	p->exit_thread = THREAD_NULL;
	u.u_procp = p;
	/*
	 * Setup credentials
	 */
	u.u_cred = crget();
	u.u_cmask = cmask;
	u.u_lastfile = -1;
	for (i = 0; i < sizeof(u.u_rlimit)/sizeof(u.u_rlimit[0]); i++)
		u.u_rlimit[i].rlim_cur = u.u_rlimit[i].rlim_max = 
		    RLIM_INFINITY;
	u.u_rlimit[RLIMIT_STACK] = vm_initial_limit_stack;
	u.u_rlimit[RLIMIT_DATA] = vm_initial_limit_data;
	u.u_rlimit[RLIMIT_CORE] = vm_initial_limit_core;

#if	POSIX_KERN
	/*
	 * POSIX process group and session of process 0
	 * (original 0x102aa4-0x102b6e).
	 */
	for (i = 0; i < 64; i++) {
		pgrphash[i] = 0;
		posix_proc_hash[i] = 0;
	}
	px = new_posix_proc(0);
	px->p_posix_pgrp = &pgrp0;
	px->p_pgrpnxt = 0;
	px->p_ruid = u.u_ruid;
	px->p_svuid = u.u_uid;
	px->p_svgid = u.u_gid;
	px->p_lockf_chan = 0;
	px->p_posix_utime = 0;
	px->p_posix_noctty = 0;
	pgrphash[0] = &pgrp0;
	pgrp0.pg_mem = p;
	pgrp0.pg_session = &session0;
	pgrp0.pg_hforw = 0;
	pgrp0.pg_jobc = 0;
	session0.s_count = 1;
	session0.s_leader = p;
	session0.s_ttyp = 0;
	session0.s_ttyd = 0;
#endif	/* POSIX_KERN */

	gc_init();
	/*
	 *	Allocate a kernel submap for pageable memory
	 *	for temporary copying (table(), execve()).
	 */
	{
	    vm_offset_t	min, max;

	    kernel_pageable_map = kmem_suballoc(kernel_map,
						&min, &max,
						512*1024,
						TRUE);
	}
	ns_hardclock_init();

	mfs_init();
	u_cred_lock_init(&u.utask->uu_cred_lock);
	crhold(u.u_cred);
	rootcred = u.u_cred;
	for (i = 1; i < NGROUPS; i++)
		u.u_groups[i] = NOGROUP;

	/*
	 * Initialize tables, protocols, and set up well-known inodes.
	 */
	mbinit();
	cinit();
	/*
	 * Block reception of incoming packets
	 * until protocols have been initialized.
	 */
	s = splnet();
	ifinit();
	domaininit();
	splx(s);
	bhinit();
	dnlc_init();
	/*
	 *	Create kernel idle cpu processes.  This must be done
 	 *	before a context switch can occur (and hence I/O can
	 *	happen in the binit() call).
	 */
	u.u_rdir = NULL;
	u.u_cdir = NULL;

	for (i = 0; i < NCPUS; i++) {
		if (machine_slot[i].is_cpu == FALSE)
			continue;
		(void) thread_create(kernel_task, &th);
		thread_bind(th, cpu_to_processor(i));
		thread_start(th, idle_thread);
		thread_doswapin(th);
		(void) thread_resume(th);
	}

	binit();

/* kick off timeout driven events by calling first time */
	recompute_priorities();
	lightning_bolt(0, 0);

	(void) kernel_thread(kernel_task, reaper_thread, 0);
	(void) kernel_thread(kernel_task, swapin_thread, 0);
	(void) kernel_thread(kernel_task, sched_thread, 0);
	(void) kernel_thread(kernel_task, netisr_thread, 0);

	_objcInit();
	objc_setClassHandler(classHandler);
	kmEnableAnimation();
	autoconf();
	setconf();
	loattach();

	/*
	 * mount the root, gets rootdir
	 */
	u.u_error = 0;
	vfs_mountroot();

	/*
	 *  Default to pausing process on these errors.
	 */
	u.u_rpause = (URPS_AGAIN|URPS_NOMEM|URPS_NFILE|URPS_NOSPC);

	file_init();

	/*
	 * make init process
	 */
	th = newproc(0);
	th->task->kernel_privilege = FALSE;
	init_proc = pfind(1);			/* now that it is set */

	/*
	 *	Default exception server
	 */
	ux_handler_init();
	port_reference(ux_exception_port);
	(void) task_set_special_port(th->task, TASK_EXCEPTION_PORT,
				     ux_exception_port);

	thread_start(th, init_task);
	(void) thread_resume(th);

	power_init();
	pageoutThread = kernel_thread(kernel_task, vm_pageout, 0);

	/*
	 * 	vol driver and notification server startup
	 */
	vol_start_thread();
	pnotify_start();

	u.u_procp->p_flag |= SLOAD|SSYS;
	task_name("kernel idle");
	(void) thread_terminate(current_thread());
	thread_halt_self();
	/*NOTREACHED*/
}

void init_task()
{
	task_name("init");
	/* plan 232 (authored, D024; original 0x102e6b-0x102e98) */
	u.u_ar0 = (int *) USER_REGS(current_thread());
	load_init_program();
	thread_exception_return();
}

/*
 * plan 232 (authored, D024; original _lightning_bolt 0x102ea4):
 * wake lbolt sleepers once a second.
 */
void
lightning_bolt(arg, entry)
	void	*arg;
	void	*entry;
{
	extern void	*calloutEntryAllocate();
	extern unsigned long long	calloutDeadlineFromInterval();

	thread_wakeup((event_t)&lbolt);
	if (entry == 0)
		entry = calloutEntryAllocate(lightning_bolt, 0);
	calloutEntryDispatchDelayed(entry,
	    calloutDeadlineFromInterval(1000000000LL));
}

/*
 * Initialize hash links for buffers.
 */
bhinit()
{
	register int i;
	register struct bufhd *bp;

	for (bp = bufhash, i = 0; i < BUFHSZ; i++, bp++)
		bp->b_forw = bp->b_back = (struct buf *)bp;
}

/*
 * Initialize the buffer I/O system by freeing
 * all buffers and setting all device buffer lists to empty.
 */
binit()
{
	register struct buf *bp, *dp;
	register int i;
	int base, residual;

	for (dp = bfreelist; dp < &bfreelist[BQUEUES]; dp++) {
		dp->b_forw = dp->b_back = dp->av_forw = dp->av_back = dp;
		dp->b_flags = B_HEAD;
	}
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
	for (i = 0; i < nbuf; i++) {
		bp = &buf[i];
		bp->b_dev = NODEV;
		bp->b_bcount = 0;
		bp->b_un.b_addr = buffers + i * MAXBSIZE;
 		if (i < residual)
			bp->b_bufsize = (base + 1) * page_size;
		else
			bp->b_bufsize = base * page_size;
#if	NeXT
		bp->b_rtpri = RTPRI_NONE;
#endif	NeXT
		if (bp->b_bufsize) {
			binshash(bp, &bfreelist[BQ_AGE]);
		} else {
			binshash(bp, &bfreelist[BQ_EMPTY]);
		}
		bp->b_vp = NULL;
		bp->b_flags = B_BUSY|B_INVAL;
		brelse(bp);
	}
	/*
	 * Count swap devices, and adjust total swap space available.
	 * Some of this space will not be available until a vswapon()
	 * system is issued, usually when the system goes multi-user.
	 */
}


/*
 * Initialize clist by freeing all character blocks, then count
 * number of character devices. (Once-only routine)
 */
cinit()
{
	register int ccp;
	register struct cblock *cp;

	ccp = (int)cfree;
	ccp = (ccp+CROUND) & ~CROUND;
	for(cp=(struct cblock *)ccp; cp < &cfree[nclist-1]; cp++) {
		cp->c_next = cfreelist;
		cfreelist = cp;
		cfreecount += CBSIZE;
	}
}

/*
 * plan 232 (authored, D024; original 0x10307c, no symbol): the
 * Objective-C class handler installed by main(); it accepts nothing.
 */
static int
classHandler()
{
	return (0);
}
