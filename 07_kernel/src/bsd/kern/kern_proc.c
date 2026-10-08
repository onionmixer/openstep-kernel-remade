/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 *
 * HISTORY
 * Revision 2.4  89/01/30  22:02:51  rpd
 * 	Added declarations of pidhash, freeproc, zombproc, allproc, qs,
 *	and mpid. (The declarations in .h files are "extern" now.)
 * 	[89/01/25  14:51:34  rpd]
 * 
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: removed dir.h.
 *
 * 13-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Removed dependencies on proc table.
 *
 * 19-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Changed inode.h to vnode.h.  The question is, why is
 *		 this in here at all?
 */

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_proc.c	7.1 (Berkeley) 6/5/86
 */

/*	@(#)kern_mman.c	2.2 88/06/17 4.0NFSSRC SMI */

#import <machine/reg.h>
#import <machine/psl.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/kernel.h>
#import <sys/proc.h>
#import <sys/buf.h>
#import <sys/acct.h>
#import <sys/wait.h>
#import <sys/file.h>
#import <sys/uio.h>
#import <sys/mbuf.h>
#import <kern/zalloc.h>	/* plan 211: zone_t */
#import <kern/kalloc.h>	/* plan 211.1: kalloc/kfree prototypes */
#import <sys/tty.h>		/* plan 211: struct nty, ttynty */
#import <kern/thread.h>	/* plan 211: thread->task, _uthread */
#import <kern/task.h>		/* plan 211: task->u_address */

#if	NeXT
struct	proc *pidhash[PIDHSZ];
struct	pgrp *pgrphash[PIDHSZ];			/* plan 400: type from the SDK sys/proc.h:250 extern (Darwin 0.1 kern_proc.c:95 is a different u_long pgrphash; plan 404 correction) */
struct	posix_proc *posix_proc_hash[PIDHSZ];	/* plan 400 (D059; D024, no evidence for the place) */
struct	proc *kernel_proc, *init_proc;
#else	NeXT
short	pidhash[PIDHSZ];
#endif	NeXT
struct	proc *freeproc, *zombproc, *allproc;
			/* lists of procs in various states */
struct	prochd qs[NQS];
int	mpid;			/* generic for unique process id's */

/*
 * Clear any pending stops for top and all descendents.
 */
spgrp(top)
	struct proc *top;
{
	register struct proc *p;
	int f = 0;

	p = top;
	for (;;) {
		p->p_sig &=
			  ~(sigmask(SIGTSTP)|sigmask(SIGTTIN)|sigmask(SIGTTOU));
		f++;
		/*
		 * If this process has children, descend to them next,
		 * otherwise do any siblings, and if done with this level,
		 * follow back up the tree (but not past top).
		 */
		if (p->p_cptr)
			p = p->p_cptr;
		else if (p == top)
			return (f);
		else if (p->p_osptr)
			p = p->p_osptr;
		else for (;;) {
			p = p->p_pptr;
			if (p == top)
				return (f);
			if (p->p_osptr) {
				p = p->p_osptr;
				break;
			}
		}
	}
}

/*
 * Is p an inferior of the current process?
 */
inferior(p)
	register struct proc *p;
{

	for (; p != u.u_procp; p = p->p_pptr)
		if (p->p_ppid == 0)
			return (0);
	return (1);
}

struct proc *
pfind(pid)
	int pid;
{
	register struct proc *p;

	for (p = pidhash[PIDHASH(pid)]; p != (struct proc *) 0; p = p->p_hash)
		if (p->p_pid == pid)
			return (p);
	return ((struct proc *)0);
}

#if	NeXT
pidhash_enter(struct proc *p)
{
	int	n;

	n = PIDHASH(p->p_pid);
	p->p_hash = pidhash[n];
	pidhash[n] = p;
}

zone_t		proc_zone;	/* plan 211: has a symbol in the original (0x1e94f8) */
static int	proc_count;

struct proc *getproc()
{
	if (proc_count >= max_proc)
		return((struct proc *)0);
	proc_count++;
	return((struct proc *)zalloc(proc_zone));
}

#if	NeXT
/* plan 211 (authored, D024; original _proc_cache_clear 0x107400) */
proc_cache_clear()
{
	register struct proc *p;

	while (freeproc) {
		proc_count--;
		p = freeproc;
		freeproc = p->p_nxt;
		zfree(proc_zone, (vm_offset_t)p);
	}
}
#endif	NeXT

pqinit()
{
	register struct proc *p;
	int	size;

	size = sizeof(struct proc);
	proc_zone = zinit(size, 100*max_proc*size, 0, FALSE, "proc structures");
	proc_count = 0;

	freeproc = NULL;
	p = getproc();
	bzero((caddr_t)p, sizeof (struct proc));	/* plan 211 (original 0x1074a7) */
	allproc = p;
	p->p_nxt = NULL;
	p->p_prev = &allproc;
	kernel_proc = p;

	zombproc = NULL;
}

#if	POSIX_KERN
/*
 * plan 211 (authored, D024; original 0x1074d8-0x107a22): POSIX process
 * groups and sessions on posix_proc records.
 */

/*
 * Locate a process group by number
 */
struct pgrp *
pgfind(pgid)
	register pid_t pgid;
{
	register struct pgrp *pgrp;

	for (pgrp = pgrphash[PIDHASH(pgid)]; pgrp != NULL;
	     pgrp = pgrp->pg_hforw)
		if (pgrp->pg_id == pgid)
			return (pgrp);
	return (NULL);
}

static void orphanpg();

/*
 * Move p to a new or existing process group (and session)
 */
enterpgrp(p, pgid, mksess)
	register struct proc *p;
	pid_t pgid;
	int mksess;
{
	register struct pgrp *pgrp = pgfind(pgid);
	register struct posix_proc *px;
	register struct proc **pp;
	int n;

	px = get_posix_proc(p->p_pid);
	if (pgrp == NULL) {
		/*
		 * new process group
		 */
		pgrp = (struct pgrp *)kalloc(sizeof (struct pgrp));
		if (mksess) {
			register struct session *sess;

			/*
			 * new session
			 */
			sess = (struct session *)kalloc(sizeof (struct session));
			sess->s_leader = p;
			sess->s_count = 1;
			sess->s_ttyp = NULL;
			sess->s_ttyd = 0;
			p->p_flag &= ~SCTTY;
			pgrp->pg_session = sess;
		} else {
			pgrp->pg_session = px->p_posix_pgrp->pg_session;
			pgrp->pg_session->s_count++;
		}
		pgrp->pg_id = pgid;
		pgrp->pg_hforw = pgrphash[n = PIDHASH(pgid)];
		pgrphash[n] = pgrp;
		pgrp->pg_jobc = 0;
		pgrp->pg_mem = NULL;
	} else if (pgrp->pg_id == px->p_pgid)
		return;

	/*
	 * Adjust eligibility of affected pgrps to participate in job control.
	 */
	if (p->p_posix) {
		fixjobc(p, pgrp, 1);
		fixjobc(p, px->p_posix_pgrp, 0);
	}

	/*
	 * unlink p from old process group
	 */
	for (pp = &px->p_posix_pgrp->pg_mem; pp;
	     pp = &get_posix_proc((*pp)->p_pid)->p_pgrpnxt)
		if (*pp == p) {
			*pp = px->p_pgrpnxt;
			goto done;
		}
	panic("enterpgrp: can't find p on old pgrp");
done:
	/*
	 * delete old if empty
	 */
	if (px->p_posix_pgrp->pg_mem == 0)
		pgdelete(px->p_posix_pgrp);
	/*
	 * link into new one
	 */
	px->p_posix_pgrp = pgrp;
	px->p_pgrpnxt = pgrp->pg_mem;
	pgrp->pg_mem = p;
	p->p_pgrp = px->p_posix_pgrp->pg_id;
}

/*
 * remove process from process group
 */
leavepgrp(p)
	register struct proc *p;
{
	register struct posix_proc *px = get_posix_proc(p->p_pid);
	register struct proc **pp = &px->p_posix_pgrp->pg_mem;

	for (; *pp; pp = &get_posix_proc((*pp)->p_pid)->p_pgrpnxt)
		if (*pp == p) {
			*pp = px->p_pgrpnxt;
			goto done;
		}
	panic("leavepgrp(): can't find p in pgrp");
done:
	if (px->p_posix_pgrp->pg_mem == 0)
		pgdelete(px->p_posix_pgrp);
	px->p_posix_pgrp = 0;
	p->p_pgrp = 0;
}

/*
 * delete a process group
 */
pgdelete(pgrp)
	register struct pgrp *pgrp;
{
	register struct pgrp **pgp = &pgrphash[PIDHASH(pgrp->pg_id)];
	register struct nty *np;

	if (pgrp->pg_session->s_ttyp != NULL &&
	    (np = ttynty(pgrp->pg_session->s_ttyp))->t_posix_pgrp == pgrp) {
		np->t_posix_pgrp = NULL;
		np->t->t_pgrp = 0;
	}
	for (; *pgp; pgp = &(*pgp)->pg_hforw)
		if (*pgp == pgrp) {
			*pgp = pgrp->pg_hforw;
			goto done;
		}
	panic("pgdelete: can't find pgrp on hash chain");
done:
	if (--pgrp->pg_session->s_count == 0) {
		if (pgrp->pg_session->s_ttyp != NULL)
			ttynty(pgrp->pg_session->s_ttyp)->t_session = NULL;
		kfree((caddr_t)pgrp->pg_session, sizeof (struct session));
	}
	kfree((caddr_t)pgrp, sizeof (struct pgrp));
}

/*
 * Adjust pgrp jobc counters when specified process changes process group.
 */
fixjobc(p, pgrp, entering)
	register struct proc *p;
	register struct pgrp *pgrp;
	int entering;
{
	register struct pgrp *hispgrp;
	register struct session *mysession = pgrp->pg_session;

	/*
	 * Check p's parent to see whether p qualifies its own process
	 * group; if so, adjust count for p's process group.
	 */
	if ((hispgrp = get_posix_proc(p->p_pptr->p_pid)->p_posix_pgrp) != pgrp &&
	    hispgrp->pg_session == mysession)
		if (entering)
			pgrp->pg_jobc++;
		else if (--pgrp->pg_jobc == 0)
			orphanpg(pgrp);

	/*
	 * Check this process' children to see whether they qualify
	 * their process groups; if so, adjust counts for children's
	 * process groups.
	 */
	for (p = p->p_cptr; p; p = p->p_osptr)
		if ((hispgrp = get_posix_proc(p->p_pid)->p_posix_pgrp) != pgrp &&
		    hispgrp->pg_session == mysession &&
		    p->p_stat != SZOMB)
			if (entering)
				hispgrp->pg_jobc++;
			else if (--hispgrp->pg_jobc == 0)
				orphanpg(hispgrp);
}

/*
 * A process group has become orphaned; if there are any stopped
 * processes in the group, hang-up all process in that group.
 */
static void
orphanpg(pg)
	struct pgrp *pg;
{
	register struct proc *p;

	for (p = pg->pg_mem; p; p = get_posix_proc(p->p_pid)->p_pgrpnxt) {
		if (p->p_stat == SSTOP) {
			for (p = pg->pg_mem; p;
			     p = get_posix_proc(p->p_pid)->p_pgrpnxt) {
				psignal(p, SIGHUP);
				psignal(p, SIGCONT);
			}
			return;
		}
	}
}

struct posix_proc *
get_posix_proc(pid)
	pid_t pid;
{
	register struct posix_proc *px;
	char buf[80];

	for (px = posix_proc_hash[PIDHASH(pid)]; px != NULL;
	     px = px->p_next_posix_proc)
		if (px->p_pid == pid)
			return (px);
	sprintf(buf, "get_posix_proc(): no posix proc struct for pid %d", pid);
	panic(buf);
}

static const struct posix_proc posix_proc_zero = { 0 };

struct posix_proc *
alloc_posix_proc()
{
	register struct posix_proc *px;

	px = (struct posix_proc *)kalloc(sizeof (struct posix_proc));
	*px = posix_proc_zero;
	return (px);
}

void
free_posix_proc(px)		/* plan 211.1: void (register choice at 0x107905) */
	struct posix_proc *px;
{
	kfree((caddr_t)px, sizeof (struct posix_proc));
}

insert_posix_proc(px, pid)
	register struct posix_proc *px;
	pid_t pid;
{
	register struct posix_proc *qx;

	for (qx = posix_proc_hash[PIDHASH(pid)]; qx != NULL;
	     qx = qx->p_next_posix_proc)
		if (qx->p_pid == pid)
			return (0);
	px->p_pid = pid;
	px->p_next_posix_proc = posix_proc_hash[PIDHASH(pid)];
	posix_proc_hash[PIDHASH(pid)] = px;
	return (1);
}

struct posix_proc *
new_posix_proc(pid)
	pid_t pid;
{
	register struct posix_proc *px;

	for (px = posix_proc_hash[PIDHASH(pid)]; px != NULL;
	     px = px->p_next_posix_proc)
		if (px->p_pid == pid)
			return (NULL);
	px = (struct posix_proc *)kalloc(sizeof (struct posix_proc));
	px->p_pid = pid;
	px->p_next_posix_proc = posix_proc_hash[PIDHASH(pid)];
	posix_proc_hash[PIDHASH(pid)] = px;
	return (px);
}

void
delete_posix_proc(p)
	register struct proc *p;
{
	register struct posix_proc **pxp;
	register struct posix_proc *px;
	char buf[80];

	for (pxp = &posix_proc_hash[PIDHASH(p->p_pid)]; *pxp;
	     pxp = &(*pxp)->p_next_posix_proc)
		if ((*pxp)->p_pid == p->p_pid) {
			px = *pxp;
			*pxp = px->p_next_posix_proc;
			kfree((caddr_t)px, sizeof (struct posix_proc));
			return;
		}
	sprintf(buf, "delete_posix_proc(): no posix proc struct for pid %d",
		p->p_pid);
	panic(buf);
}
#endif	POSIX_KERN

#else	NeXT
/*
 * init the process queues
 */
pqinit()
{
	register struct proc *p;

	/*
	 * most procs are initially on freequeue
	 *	nb: we place them there in their "natural" order.
	 */

	freeproc = NULL;
	for (p = procNPROC; --p > proc; freeproc = p)
		p->p_nxt = freeproc;

	/*
	 * but proc[0] is special ...
	 */

	allproc = p;
	p->p_nxt = NULL;
	p->p_prev = &allproc;

	zombproc = NULL;
}
#endif	NeXT


