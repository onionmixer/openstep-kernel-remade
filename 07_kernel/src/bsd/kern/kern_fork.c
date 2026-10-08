/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * 14-Feb-90  Gregg Kellogg (gk) at NeXT
 *	Changes for new scheduler:
 *		Remove process lock initialization.
 *
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: removed #include dir.h, Change SPAGI to SPAGV
 *
 * 05-Jan-89  Avadis Tevanian (avie) at NeXT
 *	Removed unused references to proc table.
 *
 * 13-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Removed dependencies on proc table.
 *
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	Set p_stat to SRUN before resuming child.
 *
 * 29-Mar-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Remove references to multprog.
 *
 * 30-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Delinted.
 *
 * 15-Dec-87  Richard Sanzi (sanzi) at Carnegie-Mellon University
 *	Deleted #ifdef romp call to float_fork().
 *
 * 21-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Cleaned up some conditionals.  Deleted old history.
 */
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_fork.c	7.1 (Berkeley) 6/5/86
 */

/*
 * The u_thread_zone part of the line marked "plan 400 (Darwin)" is the
 * same as Darwin 0.1 kernel/bsd/kern/kern_fork.c:346 (kernel-1), whose notice is:
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * "Portions Copyright (c) 1999 Apple Computer, Inc.  All Rights
 * Reserved.  This file contains Original Code and/or Modifications of
 * Original Code as defined in and that are subject to the Apple Public
 * Source License Version 1.0 (the 'License').  You may not use this file
 * except in compliance with the License.  Please obtain a copy of the
 * License at http://www.apple.com/publicsource and read it before using
 * this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License."
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#import <machine/reg.h>
#import <machine/psl.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/proc.h>
#import <sys/vnode.h>
#import <sys/file.h>
#import <sys/acct.h>

#import <kern/thread.h>

#import <machine/spl.h>

thread_t	newproc(), procdup();
#if	POSIX_KERN
extern struct posix_proc *alloc_posix_proc();	/* plan 202 */
#endif	POSIX_KERN
/*
 * fork system call.
 */
fork()
{
	fork1(0);
}

vfork()
{

	fork1(1);
}

fork1(isvfork)
	int isvfork;
{
	register struct proc *p1, *p2;
	register a;
	thread_t	th;
#if	POSIX_KERN
	struct posix_proc *pp;

	pp = alloc_posix_proc();	/* plan 202 (authored; original 0x106841) */
#endif	POSIX_KERN

	a = 0;
	if (u.u_uid != 0) {
		for (p1 = allproc; p1; p1 = p1->p_nxt)
			if (p1->p_uid == u.u_uid)
				a++;
		for (p1 = zombproc; p1; p1 = p1->p_nxt)
			if (p1->p_uid == u.u_uid)
				a++;
	}
	/*
	 * Disallow if
	 *  No processes at all;
	 *  not su and too many procs owned; or
	 *  not su and would take last slot.
	 */
	p2 = freeproc;
#if	NeXT
	if (p2 == NULL) {
		p2 = getproc();
		if (p2 == NULL)
			tablefull("proc");
		else {
			p2->p_nxt = freeproc;	/* put on freeproc for cloneproc */
			freeproc = p2;
		}
	}
	if (p2==NULL || (u.u_uid!=0 && a>MAXUPRC)) {
#else	NeXT
	if (p2==NULL)
		tablefull("proc");
	if (p2==NULL || (u.u_uid!=0 && (p2->p_nxt == NULL || a>MAXUPRC))) {
#endif	NeXT
#if	POSIX_KERN
		free_posix_proc(pp);	/* plan 202 (original 0x1068eb) */
#endif	POSIX_KERN
		u.u_error = EAGAIN;
		goto out;
	}
	p1 = u.u_procp;
#if	POSIX_KERN
	th = cloneproc(p1, isvfork, pp);	/* plan 202 (original 0x10690c) */
#else	POSIX_KERN
	th = newproc(isvfork);
#endif	POSIX_KERN
	thread_dup(current_thread(), th);
#if	NeXT
	/* plan 202: uthread/utask of this kern/thread.h and kern/task.h */
	th->_uthread->uu_r.r_val1 = p1->p_pid;
	th->_uthread->uu_r.r_val2 = 1;	/* child */
	microtime(&th->task->u_address->uu_start);
	th->task->u_address->uu_acflag = AFORK;
#else	NeXT
	th->u_address.uthread->uu_r.r_val1 = p1->p_pid;
	th->u_address.uthread->uu_r.r_val2 = 1;	/* child */
	th->u_address.utask->uu_start = time;
	th->u_address.utask->uu_acflag = AFORK;
#endif	NeXT
	u.u_r.r_val1 = p2->p_pid;

	(void) thread_resume(th);
out:
	u.u_r.r_val2 = 0;

}

thread_t cloneproc();

/*
 * Create a new process-- the internal version of
 * sys fork.
 * It returns 1 in the new process, 0 in the old.
 */
thread_t newproc(isvfork)
	int isvfork;
{
#if	POSIX_KERN
	return (cloneproc(u.u_procp, isvfork, alloc_posix_proc()));	/* plan 202 */
#else	POSIX_KERN
	return (cloneproc(u.u_procp, isvfork));
#endif	POSIX_KERN
}

/*
 * Create a new process from a specified process.
 */
thread_t
#if	POSIX_KERN
cloneproc(rip, isvfork, pp)	/* plan 202: posix_proc of the child */
	register struct proc *rip;
	int isvfork;
	struct posix_proc *pp;
#else	POSIX_KERN
cloneproc(rip, isvfork)
	register struct proc *rip;
	int isvfork;
#endif	POSIX_KERN
{
	register struct proc *rpp;
	register struct utask *utask = rip->task->u_address;
	register int n;
	register struct file *fp;
	static int pidchecked = 0;
	thread_t	th;
#if	POSIX_KERN
	struct posix_proc *px;
#endif	POSIX_KERN

	/*
	 * First, just locate a slot for a process
	 * and copy the useful info from this process into it.
	 * The panic "cannot happen" because fork has already
	 * checked for the existence of a slot.
	 */
newpid:
	mpid++;
retry:
	if (mpid >= 30000) {
		mpid = 100;
		pidchecked = 0;
	}
	if (mpid >= pidchecked) {
		int doingzomb = 0;

		pidchecked = 30000;
		/*
		 * Scan the proc table to check whether this pid
		 * is in use.  Remember the lowest pid that's greater
		 * than mpid, so we can avoid checking for a while.
		 */
		rpp = allproc;
again:
		for (; rpp != NULL; rpp = rpp->p_nxt) {
			if (rpp->p_pid == mpid || rpp->p_pgrp == mpid) {
				mpid++;
				if (mpid >= pidchecked)
					goto retry;
			}
			if (rpp->p_pid > mpid && pidchecked > rpp->p_pid)
				pidchecked = rpp->p_pid;
			if (rpp->p_pgrp > mpid && pidchecked > rpp->p_pgrp)
				pidchecked = rpp->p_pgrp;
		}
		if (!doingzomb) {
			doingzomb = 1;
			rpp = zombproc;
			goto again;
		}
	}
#if	POSIX_KERN
	/* plan 202 (authored; original 0x106a84-0x106a99) */
	if (!insert_posix_proc(pp, mpid))
		goto newpid;
#endif	POSIX_KERN
#if	NeXT
	if ((rpp = freeproc) == NULL) {
		rpp = getproc();
		if (rpp == NULL)
			panic("no procs");
		rpp->p_nxt = freeproc;		/* put on freeproc for below */
		freeproc = rpp;
	}
#else	NeXT
	if ((rpp = freeproc) == NULL)
		panic("no procs");
#endif	NeXT

	freeproc = rpp->p_nxt;			/* off freeproc */

	/*
	 * Make a proc table entry for the new process.
	 */
	rpp->p_stat = SIDL;
	timerclear(&rpp->p_realtimer.it_value);
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SOUSIG|SXONLY));
	rpp->p_uid = rip->p_uid;
#if	POSIX_KERN
	/* plan 202 (authored, D024; original 0x106b00-0x106b5f) */
	rpp->p_flag |= rip->p_flag & SCTTY;
	rpp->p_posix = rip->p_posix;
	px = get_posix_proc(rip->p_pid);
	pp->p_ruid = px->p_ruid;
	pp->p_svuid = px->p_svuid;
	pp->p_svgid = px->p_svgid;
	pp->p_posix_pgrp = px->p_posix_pgrp;
	pp->p_posix_utime = 0;
	pp->p_posix_noctty = 0;
	pp->p_lockf_chan = 0;
#endif	POSIX_KERN
	rpp->p_pgrp = rip->p_pgrp;
	rpp->p_nice = rip->p_nice;
#if	POSIX_KERN
	rpp->p_pid = pp->p_pid;
#else	POSIX_KERN
	rpp->p_pid = mpid;
#endif	POSIX_KERN
	rpp->p_ppid = rip->p_pid;
	rpp->p_pptr = rip;
	rpp->p_osptr = rip->p_cptr;
	if (rip->p_cptr)
		rip->p_cptr->p_ysptr = rpp;
	rpp->p_ysptr = NULL;
	rpp->p_cptr = NULL;
	rip->p_cptr = rpp;
	rpp->p_time = 0;
	rpp->p_cpu = 0;
	rpp->p_sigmask = rip->p_sigmask;
	rpp->p_sigcatch = rip->p_sigcatch;
	rpp->p_sigignore = rip->p_sigignore;
	/* take along any pending signals like stops? */
	rpp->p_tptr = 0;
	rpp->p_aptr = 0;
#if	NeXT
	/* plan 202 (authored; original 0x106bd8-0x106be9) */
	rpp->p_xstat = 0;
	rpp->p_sig = 0;
	rpp->p_cursig = 0;
	rpp->p_debugger = 0;
#endif	NeXT
#if	NeXT
	pidhash_enter(rpp);
#else	NeXT
	n = PIDHASH(rpp->p_pid);
	rpp->p_hash = pidhash[n];
	pidhash[n] = rpp;
#endif	NeXT

	/*
	 * Increase reference counts on shared objects.
	 */
#if	NeXT
	/* plan 202: open files are counted on the child after procdup */
#else	NeXT
	for (n = 0; n <= utask->uu_lastfile; n++) {
		fp = utask->uu_ofile[n];
		if (fp == NULL)
			continue;
		fp->f_count++;
	}
#endif	NeXT
	if (utask->uu_cdir)
		VN_HOLD(utask->uu_cdir);
	if (utask->uu_rdir)
		VN_HOLD(utask->uu_rdir);
	crhold(utask->uu_cred);
#if	NeXT
#else	NeXT
	u_cred_lock_init(&utask->uu_cred_lock);
#endif	NeXT

	/*
	 * This begins the section where we must prevent the parent
	 * from being swapped.
	 */
	rip->p_flag |= SKEEP;
	simple_lock_init(&rpp->siglock);
	rpp->sigwait = FALSE;
	rpp->exit_thread = THREAD_NULL;
	th = procdup(rpp, rip);	/* child, parent */
#if	NeXT
	/*
	 * plan 202 (authored, D024; original 0x106c47-0x106ca5): count the
	 * child's open files (0xffff0000 marks a slot to drop; name not
	 * recovered) and initialize the child's credential lock.
	 */
	for (n = 0; n <= rpp->task->u_address->uu_lastfile; n++) {
		fp = rpp->task->u_address->uu_ofile[n];
		if (fp == NULL)
			continue;
		if (fp == (struct file *)0xffff0000)
			rpp->task->u_address->uu_ofile[n] = NULL;
		else
			fp->f_count++;
	}
	u_cred_lock_init(&rpp->task->u_address->uu_cred_lock);
#endif	NeXT
	uarea_init(th);		/* this shouldn't be necessary here XXX */
#if	POSIX_KERN
	pp->p_pgrpnxt = px->p_pgrpnxt;	/* plan 202 (original 0x106caa) */
	px->p_pgrpnxt = rpp;
#endif	POSIX_KERN
	/*
	 *	It is now safe to link onto allproc
	 */
	rpp->p_nxt = allproc;			/* onto allproc */
	rpp->p_nxt->p_prev = &rpp->p_nxt;	/*   (allproc is never NULL) */
	rpp->p_prev = &allproc;
	allproc = rpp;
	rpp->p_stat = SRUN;			/* XXX */
	(void) spl0();

	/*
	 * Cause child to take a non-local goto as soon as it runs.
	 * On older systems this was done with SSWAP bit in proc
	 * table; on VAX we use u.u_pcb.pcb_sswap so don't need
	 * to do rpp->p_flag |= SSWAP.  Actually do nothing here.
	 */
	/* rpp->p_flag |= SSWAP; */

	/*
	 * Now can be swapped.
	 */
	rip->p_flag &= ~SKEEP;

	return(th);
}

#import <kern/mach_param.h>

#if	NeXT
/* plan 202 (authored, D024; original 0x106cfc): separate utask and uthread zones */
struct zone *u_task_zone, *u_thread_zone;	/* plan 400 (Darwin): u_thread_zone as Darwin 0.1 kern_fork.c:346; u_task_zone D059 (was extern) */
struct _u_address active_u[NCPUS];	/* plan 400 (D059; D024, no evidence for the place) */

uzone_init()
{

	u_task_zone = zinit(sizeof(struct utask),
			TASK_MAX * sizeof(struct utask),
			64 * sizeof(struct utask),
			FALSE, "utasks");
	u_thread_zone = zinit(sizeof(struct uthread),
			THREAD_MAX * sizeof(struct uthread),
			64 * sizeof(struct uthread),
			FALSE, "uthreads");
}
#else	NeXT
extern struct zone *u_zone;

uzone_init()
{

	u_zone = zinit(sizeof(struct utask),
			THREAD_MAX * sizeof(struct utask),
			8 * sizeof(struct utask),
			FALSE, "u-areas");
}
#endif	NeXT

utask_free(utask)
	struct utask	*utask;
{
	int	cnt = utask->uu_ofile_cnt;

	if (cnt) {
		kfree(utask->uu_ofile, cnt * sizeof(struct file *));
		kfree(utask->uu_pofile, cnt * sizeof(char));
		utask->uu_ofile_cnt = 0;
	}
#if	NeXT
	zfree(u_task_zone, (vm_offset_t) utask);	/* plan 202 */
#else	NeXT
	zfree(u_zone, (vm_offset_t) utask);
#endif	NeXT
}

#if	NeXT
/* plan 202 (authored; original 0x106d9c) */
uthread_free(uthread)
	struct uthread	*uthread;
{
	zfree(u_thread_zone, (vm_offset_t) uthread);
}
#endif	NeXT

uarea_init(th)
	register thread_t	th;
{
#if	NeXT
	th->_uthread->uu_ap = th->_uthread->uu_arg;	/* plan 202 */
#else	NeXT
	th->u_address.uthread->uu_ap = th->u_address.uthread->uu_arg;
#endif	NeXT
}

uarea_zero(th)
	thread_t	th;
{
#if	NeXT
	bzero((caddr_t) th->_uthread, sizeof(struct uthread));	/* plan 202 */
#else	NeXT
	bzero((caddr_t) th->u_address.uthread, sizeof(struct uthread));
#endif	NeXT
}

utask_zero(ta)
	task_t		ta;
{
	bzero((caddr_t) ta->u_address, sizeof(struct utask));
	ta->proc = (struct proc *)0;
}

#if	NeXT
/* plan 202 (authored, D024; original 0x106e0c): make th the current u area */
switch_unix_context(th)
	thread_t	th;
{
	active_u[0].uthread = th->_uthread;
	active_u[0].utask = th->task->u_address;
}
#endif	NeXT



