/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * Revision 2.16  89/10/11  13:37:33  dlb
 * 	Fix time calculation in exit() to record time from all threads,
 * 	not just current thread.  Also change caling sequence of task_halt.
 * 	[89/08/30            dlb]
 * 
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: Add wait4() system call.
 *	Cleaned up SUN_VFS stuff
 *
 * 05-Jan-89  Avadis Tevanian (avie) at NeXT
 *	Removed references to p_cpticks and p_pctcpu.
 *
 * 24-Oct-88  Steve Stone (steve) at NeXT
 *	Added Attach trace support.
 *
 * 13-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Removed dependencies on proc table.
 *
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	MACH_TIME_NEW is now standard.
 *	Check p_stat when looking for stopped processes.
 * 
 * 29-Mar-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	MACH: Remove references to multprog.
 *
 * 12-Feb-88  David Black (dlb) at Carnegie-Mellon University
 *	Update MACH_TIME_NEW interface to use time_value_t's.
 *
 *  2-Mar-88  David Black (dlb) at Carnegie-Mellon University
 *	Use thread_read_times to get times.  This replaces and
 *	generalizes the MACH_TIME_NEW code.
 *
 * 29-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Delinted.
 *
 * 23-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Made exit halt all threads in task before cleaning up.
 *
 *  8-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Follow task_terminate with thread_halt_self for new termination
 *	logic.  Check for null p->task for Zombie check in wait.
 *
 * 21-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Condensed some conditionals, purged previous history.
 *
 * 19-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Change inode references to vnode references.
 *	SUN_LOCK: Undo record locking on exit().
 */
 
#import <sun_lock.h>
#if	NeXT
#import <od.h>
#endif	NeXT

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_exit.c	7.1 (Berkeley) 6/5/86
 */

/* @(#)kern_exit.c	2.4 88/07/01 4.0NFSSRC SMI;	from UCB 7.1 6/5/86  */

#import <machine/reg.h>
#import <machine/psl.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/proc.h>
#import <sys/buf.h>
#import <sys/wait.h>
#import <sys/file.h>
#import <sys/mbuf.h>
#import <kern/xpr.h>
#import <sys/vnode.h>		/* SUN_VFS */
#import <sys/syslog.h>
#import <sys/tty.h>		/* plan 213: struct nty, ttynty */

/* plan 213: kern/ipc_globals.h does not exist in this tree */
#import <mach/kern_return.h>	/* plan 213 (was sys/kern_return.h) */

#import <kern/task.h>
#import <vm/vm_map.h>
#import <kern/thread.h>
#import <kern/parallel.h>
#import <kern/sched_prim.h>
/* plan 213: time_value_t comes from mach/time_value.h (sys/time_value.h redefines it) */

/*
 * Exit system call: pass back caller's arg
 */
rexit()
{
	register struct a {
		int	rval;
	} *uap;

	uap = (struct a *)u.u_ap;
	exit((uap->rval & 0377) << 8);
}

/*
 * Release resources.
 * Save u. area for parent to look at.
 * Enter zombie state.
 * Wake up parent and init processes,
 * and dispose of children.
 */
exit(rv)
	int	rv;
{
	do_exit(u.u_procp, rv);
	for (;;)		/* plan 213 (original 0x105af0) */
		thread_halt_self_with_continuation((void (*)())0);
}

do_exit(p, rv)
	struct proc	*p;
	int		rv;
{
	register int i;
	register struct proc	*q, *nq;
	time_value_t		sys_time, user_time;
	register struct	timeval	*utvp, *stvp;
	register struct proc	*x;
	struct utask		*utask;
	struct task		*task;
	thread_t		thread;
	queue_head_t		*list;
	int			s;
#if	POSIX_KERN
	struct posix_proc	*px = get_posix_proc(p->p_pid);	/* plan 213 (original 0x105b0d) */
#endif	POSIX_KERN

#ifdef PGINPROF
	vmsizmon();
#endif
	/*
	 *	Since exit can be called from psig or syscall, we have
	 *	to worry about the potential race.  sig_lock_to_exit
	 *	causes any thread in this task encountering a sig_lock
	 *	anywhere (including here) to immediately suspend permanently.
	 */
	if (current_thread() != p->exit_thread) {
	    sig_lock(p);
	    sig_lock_to_exit(p);
	}
	/*
	 *	Halt all threads in the task, except for the current
	 *	thread.
	 */
	task = p->task;
	(void) task_halt(task);
	utask = task->u_address;

	/*
	 *	Set SWEXIT just to humor ps.
	 */
	p->p_flag &= ~(STRC|SULOCK);
	p->p_flag |= SWEXIT;
	p->p_sigignore = ~0;
	for (i = 0; i < NSIG; i++)
		utask->uu_signal[i] = SIG_IGN;
	untimeout(realitexpire, (caddr_t)p);
	for (i = 0; i <= utask->uu_lastfile; i++) {
		register struct file *f;

		if ((f = utask->uu_ofile[i]) != NULL && f != FPINPROGRESS) {	/* plan 213 (original 0x105c50) */
#if	SUN_LOCK
			/* Release all System-V style record locks, if any */
			(void) vno_lockrelease(f);
#endif	SUN_LOCK
			utask->uu_ofile[i] = NULL;
			closef(f);
		}
		utask->uu_pofile[i] = 0;
	}
	if (utask->uu_cdir) {	/* NeXT: shutdown may have deleted it on us */
		VN_RELE(utask->uu_cdir);
	}
	if (utask->uu_rdir) {
		VN_RELE(utask->uu_rdir);
	}
	utask->uu_rlimit[RLIMIT_FSIZE].rlim_cur = RLIM_INFINITY;
	acct();
	crfree(utask->uu_cred);
	if (*p->p_prev = p->p_nxt)		/* off allproc queue */
		p->p_nxt->p_prev = p->p_prev;
	if (p->p_nxt = zombproc)		/* onto zombproc */
		p->p_nxt->p_prev = &p->p_nxt;
	p->p_prev = &zombproc;
	zombproc = p;
	/*
	 *	Only use of noproc was in psignal, which should have
	 *	returned after p->p_sigignore = ~0 near the start of exit()
	 */
	p->p_stat = SZOMB;
	i = PIDHASH(p->p_pid);
	x = pidhash[i];
	if (p == x)
		pidhash[i] = p->p_hash;
	else {
		while (x != (struct proc *) 0) {
			if (x->p_hash == p) {
				x->p_hash = p->p_hash;
				goto done;
			}
			x = x->p_hash;
		}
		panic("exit");
	}
	if (p->p_pid == 1) {
		printf("init exited with %d\n", rv>>8);
#if	NeXT
		for (;;)
			;
#else	NeXT
		if (u.u_data_start == 0) {
			printf("Can't exec /etc/init\n");
			for (;;)
				;
		} else
			panic("init died");
#endif	NeXT
	}
done:
	p->p_xstat = rv;
	/*
	 *	The task_halt() above stopped all the threads except this
	 *	one in their tracks, so it's ok to get their times here.
	 */
	utvp = &utask->uu_ru.ru_utime;
	utvp->tv_sec = 0;
	utvp->tv_usec = 0;

	stvp = &utask->uu_ru.ru_stime;
	stvp->tv_sec = 0;
	stvp->tv_usec = 0;

	list = &task->thread_list;
	task_lock(task);
	thread = (thread_t) queue_first(list);
	s = splsched();
	while (!queue_end(list, (queue_entry_t) thread)) {
		
		thread_read_times(thread, &user_time, &sys_time);

		utvp->tv_sec += user_time.seconds;
		utvp->tv_usec += user_time.microseconds;
		stvp->tv_sec += sys_time.seconds;
		stvp->tv_usec += sys_time.microseconds;

		thread = (thread_t) queue_next(&thread->thread_list);
	}
	splx(s);

	/*
	 *  Add in time from terminated threads.
	 */
	utvp->tv_sec += task->total_user_time.seconds;
	utvp->tv_usec += task->total_user_time.microseconds;
	stvp->tv_sec += task->total_system_time.seconds;
	stvp->tv_usec += task->total_system_time.microseconds;

	task_unlock(task);

#if	NeXT
	p->p_ru = (struct rusage *) kalloc(sizeof (*p->p_ru));
#else	NeXT
	p->p_ru = mtod(m, struct rusage *);
#endif	NeXT
	*p->p_ru = u.u_ru;
	ruadd(p->p_ru, &utask->uu_cru);
	if (p->p_cptr)		/* only need this if any child is S_ZOMB */
#if	NeXT
		wakeup((caddr_t)init_proc);
#else	NeXT
		wakeup((caddr_t)&proc[1]);
#endif	NeXT

#if	NeXT
	if (p->p_aptr) {
		q = p->p_aptr;
		q->p_tptr = 0;
		q->p_flag &= ~STRC;
		psignal(q, SIGKILL);
		p->p_aptr = 0;
	}
#endif
#if	POSIX_KERN
	/* plan 213 (authored, D024; original 0x105ef6-0x105f68) */
	if (p->p_posix && SESS_LEADER(p, px)) {
		register struct session *sp = px->p_session;
		register struct nty *np;

		if (sp->s_ttyp && (np = ttynty(sp->s_ttyp))->t_session == sp) {
			if (np->t_posix_pgrp)
				pgsignal(np->t_posix_pgrp, SIGHUP, 1);
			ttywait(sp->s_ttyp);
		}
		sp->s_leader = 0;
	}
	if (p->p_posix)
		fixjobc(p, get_posix_proc(p->p_pid)->p_posix_pgrp, 0);
#endif	POSIX_KERN
	for (q = p->p_cptr; q != NULL; q = nq) {
		nq = q->p_osptr;
		if (nq != NULL)
			nq->p_ysptr = NULL;
#if	NeXT
		if (init_proc->p_cptr)
			init_proc->p_cptr->p_ysptr = q;
		q->p_osptr = init_proc->p_cptr;
		q->p_ysptr = NULL;
		init_proc->p_cptr = q;

		q->p_pptr = init_proc;
#else	NeXT
		if (proc[1].p_cptr)
			proc[1].p_cptr->p_ysptr = q;
		q->p_osptr = proc[1].p_cptr;
		q->p_ysptr = NULL;
		proc[1].p_cptr = q;

		q->p_pptr = &proc[1];
#endif	NeXT
		q->p_ppid = 1;
		/*
		 * Traced processes are killed
		 * since their existence means someone is screwing up.
		 * Stopped processes are sent a hangup and a continue.
		 * This is designed to be ``safe'' for setuid
		 * processes since they must be willing to tolerate
		 * hangups anyways.
		 */
		if (q->p_flag&STRC) {
			q->p_flag &= ~STRC;
			q->p_tptr = 0;
			psignal(q, SIGKILL);
		} else if ((q->task != TASK_NULL) &&
		    (q->task->user_stop_count > 0)) {
			psignal(q, SIGHUP);
			psignal(q, SIGCONT);
		}
		/*
		 * Protect this process from future
		 * tty signals, clear TSTP/TTIN/TTOU if pending.
		 */
		(void) spgrp(q);
	}
	p->p_cptr = NULL;
#if	NeXT
	if (p->p_tptr) {
		psignal(p->p_tptr, SIGCHLD);
		wakeup((caddr_t)p->p_tptr);
		p->p_tptr->p_aptr = 0;		/* plan 213 (original 0x106034) */
	}
#endif
	/* plan 213 (authored, D024; original 0x106047-0x106096) */
	if (u.u_prof.pr_lock) {
		u.u_prof.pr_scale = 0;
		simple_lock_free(u.u_prof.pr_lock);
	}
	{
		register struct uuprof *pr, *npr;

		for (pr = u.u_prof.pr_next; pr; pr = npr) {
			npr = pr->pr_next;
			kfree(pr, sizeof (struct uuprof));
		}
	}
	psignal(p->p_pptr, SIGCHLD);
	wakeup((caddr_t)p->p_pptr);
	p->task = TASK_NULL;
	p->thread = THREAD_NULL;
	(void) task_terminate(task);
	if (current_thread()->task == task)
		thread_halt_self();
	/*NOTREACHED*/
}

/*
 * Wait4 system call.
 * Search for a specific terminated (zombie) child (pid of zero means any),
 * finally lay it to rest, and collect its status.
 */
/* plan 213 (authored, D024; original _wait4 0x1060ec): continuation form */
wait4()
{
	struct rusage ru;
	int status;
	struct wait4_args *ap = (struct wait4_args *)u.u_ap;
	int error;

	error = wait1(ap->options, &ru, &status, ap->pid, wait4);
	if (error)
		unix_syscall_return(error);
	if (ap->rusage != (struct rusage *)0)
		error = copyout((caddr_t)&ru, (caddr_t)ap->rusage,
		    sizeof (struct rusage));
	if (ap->status != (union wait *)0)
		error = copyout((caddr_t)&status, (caddr_t)ap->status,
		    sizeof (union wait));
	unix_syscall_return(error);
}

/* plan 213 (authored, D024; original _wait 0x106168) */
wait()
{
	int error, status;

	error = wait1(0, (struct rusage *)0, &status, 0, wait);
	u.u_r.r_val2 = status;
	unix_syscall_return(error);
}

/* plan 213 (authored, D024; original _wait3 0x10619c) */
wait3()
{
	register struct a {
		int	status;
		int	options;
		struct rusage *rup;
	} *uap;
	struct rusage ru, *rup;
	int error;

	uap = (struct a *)u.u_ap;
	rup = uap->rup;

	error = wait1(uap->options, &ru, &u.u_r.r_val2, 0, wait3);
	if (error)
		unix_syscall_return(error);

	if (rup != (struct rusage *) 0)
		error = copyout((caddr_t)&ru, (caddr_t)rup,
		    sizeof (struct rusage));
	unix_syscall_return(error);
}

/*
 * Wait system call.
 * Search for a terminated (zombie) child,
 * finally lay it to rest, and collect its status.
 * Look also for stopped (traced) children,
 * and pass back status from them.
 */
wait1(options,ru,status,pid,cont)
	register int options;
	struct rusage *ru;
	register int *status;
	register int pid;
	void (*cont)();		/* plan 213: continuation (original 0x1064e8) */
{
	register struct proc *p, *q;
	register struct proc *curproc;

	/*
	 * plan 213 (authored, D024; original 0x10620b-0x106268): re-entered
	 * from the continuation with u_error < 0; f lives in u.u_wait.f.
	 */
	if (u.u_error < 0) {
		register int r = thread_wait_result();	/* plan 213.1: variant w1 (s5p187-v1) */

		if (r == THREAD_INTERRUPTED || r == THREAD_SHOULD_TERMINATE) {
			p = u.u_procp;
			if ((u.u_sigintr & sigmask(p->p_cursig)) != 0)
				unix_syscall_return(EINTR);
			u.u_eosys = RESTARTSYS;
			unix_syscall_return(0);
		} else
			u.u_error = 0;
	} else
		u.u_wait.f = 0;
	q = u.u_procp;
	curproc = q;
	for (p = q->p_cptr; p; p = p->p_osptr) {
		/*
		 *	Should save our place in the queue !!!!
		 *	For now we will take the in-efficient route...
		 */
		if(pid != 0 && pid != p->p_pid)
			continue;
		u.u_wait.f++;
		if (p->task == TASK_NULL)
		{
			if (p->p_tptr && (p->p_tptr != curproc))
			  /* Wait until the traced process clears tptr. */
			  continue;
			u.u_r.r_val1 = p->p_pid;
			*status = p->p_xstat;
			p->p_xstat = 0;
			if (ru && p->p_ru)
				*ru = *p->p_ru;
			if (p->p_ru) {
				ruadd(&u.u_cru, p->p_ru);
#if	NeXT
				kfree(p->p_ru, sizeof (*p->p_ru));
#else	NeXT
				(void) m_free(dtom(p->p_ru));
#endif	NeXT
				p->p_ru = 0;
			}
#if	POSIX_KERN
			leavepgrp(p);		/* plan 213 (original 0x10631b) */
			delete_posix_proc(p);
#endif	POSIX_KERN
			p->p_stat = NULL;
			p->p_pid = 0;
			p->p_ppid = 0;
			if (*p->p_prev = p->p_nxt)	/* off zombproc */
				p->p_nxt->p_prev = p->p_prev;
			p->p_nxt = freeproc;		/* onto freeproc */
			freeproc = p;
			if (q = p->p_ysptr)
				q->p_osptr = p->p_osptr;
			if (q = p->p_osptr)
				q->p_ysptr = p->p_ysptr;
			if ((q = p->p_pptr)->p_cptr == p)
				q->p_cptr = p->p_osptr;
			p->p_pptr = 0;
			p->p_ysptr = 0;
			p->p_osptr = 0;
			p->p_cptr = 0;
			p->p_sig = 0;
			p->p_sigcatch = 0;
			p->p_sigignore = 0;
			p->p_sigmask = 0;
			p->p_pgrp = 0;
			p->p_flag = 0;
			p->p_cursig = 0;
			return (0);
		}
		if (p->task->user_stop_count > 0 && p->p_stat == SSTOP &&
		    (p->p_flag&SWTED)==0 &&
		    (((p->p_flag&STRC) || options&WUNTRACED) &&
		     (p->p_tptr == 0 || p->p_tptr == curproc)))
		{
			p->p_flag |= SWTED;
			u.u_r.r_val1 = p->p_pid;
			/*
			 *	Stop-class signals are in p_stopsig instead
			 *	of p_cursig under some circumstances.
			 */
			if (p->p_cursig == 0)
				*status = (p->p_stopsig<<8) | WSTOPPED;
			else
				*status = (p->p_cursig<<8) | WSTOPPED;
			return (0);
		}
	}
	/* If we are monitoring an attached process. Only handle signals.  Let
	   the parent clean up the zombie. */
	if (curproc->p_aptr) {
		p = curproc->p_aptr;
		u.u_wait.f++;
		if (p->task == TASK_NULL)
		{
			p->p_tptr = 0;
			p->p_flag &= ~STRC;
			wakeup(p->p_pptr);
			return(0);
		}
		if (p->task->user_stop_count > 0 && p->p_stat == SSTOP &&
		    (p->p_flag&SWTED)==0 &&
		    (p->p_flag&STRC || options&WUNTRACED)) {
			p->p_flag |= SWTED;
			u.u_r.r_val1 = p->p_pid;
			/*
			 *	Stop-class signals are in p_stopsig instead
			 *	of p_cursig under some circumstances.
			 */
			if (p->p_cursig == 0)
				*status = (p->p_stopsig<<8) | WSTOPPED;
			else
				*status = (p->p_cursig<<8) | WSTOPPED;
			return (0);
		}
	}
	if (u.u_wait.f == 0)
		return (ECHILD);
	if (options&WNOHANG) {
		u.u_r.r_val1 = 0;
		return (0);
	}
	u.u_error = -1;		/* plan 213 (original 0x1064e4) */
	sleep_with_continuation((caddr_t)u.u_procp, PWAIT, cont);
}

#if	POSIX_KERN
/*
 * plan 213 (authored, D024; original _waitpgrp 0x106508): wait for a
 * child in a given process group.
 */
waitpgrp()
{
	struct a {		/* plan 213.1: not register, variant t2 (s5p187-v3..v6) */
		int	pgrp;
		int	*status;
		int	options;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p, *q;
	register struct proc *curproc;
	int f, status;

	f = 0;
loop:
	curproc = u.u_procp;
	for (p = curproc->p_cptr; p; p = p->p_osptr) {
		if (uap->pgrp != p->p_pgrp)
			continue;
		f++;
		if (p->task == TASK_NULL) {
			u.u_r.r_val1 = p->p_pid;
			u.u_error = copyout((caddr_t)&p->p_xstat,
			    (caddr_t)uap->status, sizeof (int));
			if (u.u_error)
				return (0);
			p->p_xstat = 0;
			if (p->p_ru) {
				ruadd(&u.u_cru, p->p_ru);
				kfree(p->p_ru, sizeof (*p->p_ru));
				p->p_ru = 0;
			}
			leavepgrp(p);
			delete_posix_proc(p);
			p->p_stat = NULL;
			p->p_pid = 0;
			p->p_ppid = 0;
			if (*p->p_prev = p->p_nxt)	/* off zombproc */
				p->p_nxt->p_prev = p->p_prev;
			p->p_nxt = freeproc;		/* onto freeproc */
			freeproc = p;
			if (q = p->p_ysptr)
				q->p_osptr = p->p_osptr;
			if (q = p->p_osptr)
				q->p_ysptr = p->p_ysptr;
			if ((q = p->p_pptr)->p_cptr == p)
				q->p_cptr = p->p_osptr;
			p->p_pptr = 0;
			p->p_ysptr = 0;
			p->p_osptr = 0;
			p->p_cptr = 0;
			p->p_sig = 0;
			p->p_sigcatch = 0;
			p->p_sigignore = 0;
			p->p_sigmask = 0;
			p->p_flag = 0;
			p->p_cursig = 0;
			return (0);
		}
		if (p->task->user_stop_count > 0 && p->p_stat == SSTOP &&
		    (p->p_flag&SWTED)==0 &&
		    (((p->p_flag&STRC) || uap->options&WUNTRACED) &&
		     (p->p_tptr == 0 || p->p_tptr == curproc)))
		{
			p->p_flag |= SWTED;
			u.u_r.r_val1 = p->p_pid;
			if (p->p_cursig == 0)
				status = (p->p_stopsig<<8) | WSTOPPED;
			else
				status = (p->p_cursig<<8) | WSTOPPED;
			u.u_error = copyout((caddr_t)&status,
			    (caddr_t)uap->status, sizeof (int));
			return (0);
		}
	}
	if (f == 0) {
		u.u_error = ECHILD;
		return (0);
	}
	if (uap->options&WNOHANG) {
		u.u_r.r_val1 = status = 0;
		u.u_error = copyout((caddr_t)&status,
		    (caddr_t)uap->status, sizeof (int));
		return (0);
	}
	if (setjmp(&u.u_qsave)) {
		p = u.u_procp;
		if ((u.u_sigintr & sigmask(p->p_cursig)) != 0)
			u.u_error = EINTR;
		else
			u.u_eosys = RESTARTSYS;
		return (0);
	}
	sleep((caddr_t)u.u_procp, PWAIT);
	goto loop;
}
#endif	POSIX_KERN

kern_return_t	init_process()
/*
 *	Make the current process an "init" process, meaning
 *	that it doesn't have a parent, and that it won't be
 *	gunned down by kill(-1, 0).
 */
{
	register struct proc *p;


	if (!suser())
		return(KERN_NO_ACCESS);

	unix_master();
	p = u.u_procp;

	/*
	 *	Take us out of the sibling chain, and
	 *	out of our parent's child chain.
	 */

	if (p->p_osptr)
		p->p_osptr->p_ysptr = p->p_ysptr;
	if (p->p_ysptr)
		p->p_ysptr->p_osptr = p->p_osptr;
	if (p->p_pptr->p_cptr == p)
		p->p_pptr->p_cptr = p->p_osptr;
	p->p_pptr = p;
	p->p_ysptr = p->p_osptr = 0;
#if	POSIX_KERN
	if (p->p_pgrp != p->p_pid)	/* plan 213 (original 0x1067f4) */
		enterpgrp(p, p->p_pid, 0);
#else	POSIX_KERN
	p->p_pgrp = p->p_pid;
#endif	POSIX_KERN
	p->p_ppid = 0;

	unix_release();
	return(KERN_SUCCESS);
}









