/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */ 

/*
 * HISTORY
 * 26-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: Removed dir.h.  Cleaned up casting of uid_t and
 *			 gid_t.  Changed crfree to run at splhigh.
 *
 * 19-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Changed inodes to vnodes.  Add support for credentials
 *		 record - crget(), crfree(), crcopy(), and crdup().
 *
 * 25-Jun-87  William Bolosky (bolosky) at Carnegie-Mellon University
 *	Made QUOTA a #if-type option.
 *
 */
#import <quota.h>
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_prot.c	7.1 (Berkeley) 6/5/86
 */

/*
 * System calls related to processes and protection
 */

#import <machine/reg.h>
#import <machine/spl.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/vfs.h>
#import <sys/vnode.h>
#import <sys/proc.h>
#import <sys/timeb.h>
#import <sys/times.h>
#import <sys/reboot.h>
#import <sys/buf.h>
#import <sys/acct.h>

#import <kern/kalloc.h>
#import <kern/thread.h>		/* plan 212: current_thread(), _uthread */
#import <kern/task.h>		/* plan 212: task->u_address */


void crfree();

/*
 * plan 212 (authored, D024; original 0x107a24-0x107a76): these three
 * start the kern_prot object (0x00 linker fill before 0x107a24, plan 211.1).
 */
struct proc *
proc_from_thread(th)
	thread_t th;
{
	if (th)			/* plan 211.1 (variant v2) */
		return (th->task->u_address->uu_procp);
	return (NULL);
}

struct utask *
utask_from_thread(th)
	thread_t th;
{
	if (th)			/* plan 211.1 (variant v2) */
		return (th->task->u_address);
	return (NULL);
}

struct uthread *
uthread_from_thread(th)
	thread_t th;
{
	if (th)			/* plan 211.1 (variant v2) */
		return (th->_uthread);
	return (NULL);
}

/* plan 212 (authored, D024; original _setprivexec 0x107a78) */
setprivexec()
{
	register struct a {
		int	flag;
	} *uap = (struct a *)u.u_ap;

	current_thread()->_uthread->uu_r.r_val1 = u.u_procp->p_debugger;
	u.u_procp->p_debugger = (uap->flag != 0);
	return (0);
}
getpid()
{
	register struct uthread *uth = current_thread()->_uthread;	/* plan 212 */
	register struct proc *p = u.u_procp;

	uth->uu_r.r_val1 = p->p_pid;
	uth->uu_r.r_val2 = p->p_ppid;
}

getpgrp()
{
	register struct a {
		int	pid;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p;

	if (uap->pid == 0)
		uap->pid = u.u_procp->p_pid;
	p = pfind(uap->pid);
	if (p == 0) {
		u.u_error = ESRCH;
		return;
	}
	u.u_r.r_val1 = p->p_pgrp;
}

getuid()
{

	u.u_r.r_val1 = (int) u.u_ruid;
	u.u_r.r_val2 = (int) u.u_uid;
}

getgid()
{

	u.u_r.r_val1 = (int) u.u_rgid;
	u.u_r.r_val2 = (int) u.u_gid;
}

/* plan 212 (authored, D024; original _getposix 0x107ba0) */
getposix()
{

	u.u_r.r_val1 = (u.u_procp->p_posix != 0);
}

/* plan 212 (authored, D024; original _setposix 0x107bc4) */
/* plan 212.1: variant p4 (s5p186-v2) */
setposix()
{
	register struct a {
		int	flag;
	} *uap = (struct a *)u.u_ap;
	register int flag = uap->flag;

	if (flag == 0 || flag == 1) {
		u.u_r.r_val1 = u.u_procp->p_posix;
		u.u_procp->p_posix = flag;
	} else {
		u.u_r.r_val1 = -1;
		u.u_error = EINVAL;
	}
}

getgroups()
{
	register struct	a {
		u_int	gidsetsize;
		int	*gidset;
	} *uap = (struct a *)u.u_ap;
	register gid_t *gp;
	register int *lp;
	int groups[NGROUPS];

	for (gp = &u.u_groups[NGROUPS]; gp > u.u_groups; gp--)
		if (gp[-1] != NOGROUP)
			break;
	if (uap->gidsetsize < gp - u.u_groups) {
		u.u_error = EINVAL;
		return;
	}
	uap->gidsetsize = gp - u.u_groups;
	if (u.u_procp->p_posix)		/* plan 212 (original 0x107c7a) */
		u.u_error = copyout((caddr_t)u.u_groups, (caddr_t)uap->gidset,
		    uap->gidsetsize * sizeof (gid_t));
	else {
		for (lp = groups, gp = u.u_groups; lp < &groups[uap->gidsetsize]; )
			*lp++ = (int) *gp++;
		u.u_error = copyout((caddr_t)groups, (caddr_t)uap->gidset,
		    uap->gidsetsize * sizeof (groups[0]));
	}
	if (u.u_error)
		return;
	u.u_r.r_val1 = uap->gidsetsize;
}

setpgrp()
{
	register struct proc *p;
	register struct a {
		int	pid;
		int	pgrp;
	} *uap = (struct a *)u.u_ap;

	if (uap->pid == 0)
		uap->pid = u.u_procp->p_pid;
	p = pfind(uap->pid);
	if (p == 0) {
		u.u_error = ESRCH;
		return;
	}
/* need better control mechanisms for process groups */
	if (p->p_uid != u.u_uid && u.u_uid && !inferior(p)) {
		u.u_error = EPERM;
		return;
	}
#if	POSIX_KERN
	enterpgrp(p, uap->pgrp, 0);	/* plan 212 (original 0x107d68) */
#else	POSIX_KERN
	p->p_pgrp = uap->pgrp;
#endif	POSIX_KERN
}

setreuid()
{
	struct a {
		int	ruid;
		int	euid;
	} *uap;
	register uid_t ruid,euid;

	uap = (struct a *)u.u_ap;
	if (uap->ruid == -1)
		ruid = u.u_ruid;
	else
		ruid = (uid_t)uap->ruid;
	if (u.u_ruid != ruid && u.u_uid != ruid && !suser())
		return;
	if (uap->euid == -1)
		euid = u.u_uid;
	else
		euid = (uid_t)uap->euid;
	if (u.u_ruid != euid && u.u_uid != euid && !suser())
		return;
	/*
	 * Everything's okay, do it.
	 */
#if	NeXT
	u_cred_lock();
#endif	NeXT
	u.u_cred = crcopy(u.u_cred);
	u.u_procp->p_uid = euid;
	u.u_ruid = ruid;
	u.u_uid = euid;
#if	NeXT
	u_cred_unlock();
#endif	NeXT
}

#if	POSIX_KERN
/* plan 212 (authored, D024; original __setuid 0x107e60) */
_setuid()
{
	struct a {
		int	uid;
	} *uap = (struct a *)u.u_ap;
	register uid_t uid, svuid, ruid;
	struct posix_proc *px;

	ruid = u.u_ruid;
	uid = (uid_t)uap->uid;
	px = get_posix_proc(u.u_procp->p_pid);
	if (uid < 0) {
		u.u_error = EINVAL;
		return;
	}
	svuid = px->p_svuid;
	if (!suser()) {
		if (uid != ruid && uid != svuid) {
			u.u_error = EPERM;
			return;
		}
	} else
		ruid = svuid = uid;
	u.u_error = 0;
	u_cred_lock();
	u.u_cred = crcopy(u.u_cred);
	u.u_ruid = px->p_ruid = ruid;	/* plan 212.1: variant s1 (s5p186-v1) */
	u.u_procp->p_uid = u.u_uid = uid;
	u_cred_unlock();
	px->p_svuid = svuid;
}

/* plan 212 (authored, D024; original __setgid 0x107f48) */
_setgid()
{
	struct a {
		int	gid;
	} *uap = (struct a *)u.u_ap;
	register gid_t gid, rgid, svgid;
	struct posix_proc *px;

	rgid = u.u_rgid;
	gid = (gid_t)uap->gid;
	px = get_posix_proc(u.u_procp->p_pid);
	if (gid < 0) {
		u.u_error = EINVAL;
		return;
	}
	svgid = px->p_svgid;
	if (!suser()) {
		if (gid != rgid && gid != svgid) {
			u.u_error = EPERM;
			return;
		}
	} else
		rgid = svgid = gid;
	u.u_error = 0;
	u_cred_lock();
	u.u_cred = crcopy(u.u_cred);
	u.u_rgid = rgid;
	u.u_gid = gid;
	u_cred_unlock();
	px->p_svgid = svgid;
}
#endif	POSIX_KERN

setregid()
{
	register struct a {
		int	rgid;
		int	egid;
	} *uap;
	register gid_t rgid, egid;

	uap = (struct a *)u.u_ap;
	if (uap->rgid == -1)
		rgid = u.u_rgid;
	else
		rgid = (gid_t)uap->rgid;
	if (u.u_rgid != rgid && u.u_gid != rgid && !suser())
		return;
	if (uap->egid == -1)
		egid = u.u_gid;
	else
		egid = (gid_t)uap->egid;
	if (u.u_rgid != egid && u.u_gid != egid && !suser())
		return;
#if	NeXT
	u_cred_lock();
#endif	NeXT
	u.u_cred = crcopy(u.u_cred);
	if (u.u_rgid != rgid) {
		leavegroup(u.u_rgid);
		(void) entergroup(rgid);
		u.u_rgid = rgid;
	}
	u.u_gid = egid;
#if	NeXT
	u_cred_unlock();
#endif	NeXT
}

setgroups()
{
	register struct	a {
		u_int	gidsetsize;
		int	*gidset;
	} *uap = (struct a *)u.u_ap;
	register gid_t *gp;
	register int *lp;
	int groups[NGROUPS];
	struct ucred *newcr, *tmpcr;

	if (!suser())
		return;
	if (uap->gidsetsize > sizeof (u.u_groups) / sizeof (u.u_groups[0])) {
		u.u_error = EINVAL;
		return;
	}
	newcr = crdup(u.u_cred);
	/*
	 *	Can't copy gid array directly, we still have to cast
	 *	them to a gid_t !
	 */
	u.u_error = copyin((caddr_t)uap->gidset, (caddr_t)groups,
	    uap->gidsetsize * sizeof (uap->gidset[0]));
	if (u.u_error) {
		crfree(newcr);
		return;
	}
	for(lp = groups,gp = newcr->cr_groups;
		lp < &groups[uap->gidsetsize];lp++,gp++) 
		*gp = (gid_t) *lp;
	tmpcr = u.u_cred;
	u.u_cred = newcr;
	crfree(tmpcr);
	for (gp = &u.u_groups[uap->gidsetsize]; gp < &u.u_groups[NGROUPS]; gp++)
		*gp = NOGROUP;
}

/*
 * Group utility functions.
 */

/*
 * Delete gid from the group set and compress.
 */
leavegroup(gid)
	gid_t gid;
{
	register gid_t *gp;

	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
		if (*gp == gid)
			goto found;
	return;
found:
	for (; gp < &u.u_groups[NGROUPS-1]; gp++)
		*gp = *(gp+1);
	*gp = NOGROUP;
}

/*
 * Add gid to the group set.
 */
entergroup(gid)
	gid_t gid;
{
	register gid_t *gp;

	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++) {
		if (*gp == gid)
			return (0);
		if (*gp == NOGROUP) {
			*gp = gid;
			return (0);
		}
	}
	return (-1);
}

/*
 * Check if gid is a member of the group set.
 */
groupmember(gid)
	gid_t gid;
{
	register gid_t *gp;

	if (u.u_gid == gid)
		return (1);
	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS] && *gp != NOGROUP; gp++)
		if (*gp == gid)
			return (1);
	return (0);
}

/*
 * Test if the current user is the super user.
 */
suser()
{
	if (current_thread()->task->u_address->uu_procp == 0)	/* plan 212 (original 0x108313) */
		return (0);
	if (u.u_uid == 0) {
		u.u_acflag |= ASU;
		return (1);
	}
	u.u_error = EPERM;
	return (0);
}

/*
 * Routines to allocate and free credentials structures
 */

int cractive = 0;

struct ucred *rootcred;

/*
 * Allocate a zeroed cred structure and crhold it.
 */
struct ucred *
crget()
{
	register struct ucred *cr;

	cr = (struct ucred *) kalloc(sizeof(*cr));
	bzero((caddr_t)cr, sizeof(*cr));
	crhold(cr);
	cractive++;
	return(cr);
}

/*
 * Free a cred structure.
 * Throws away space when ref count gets to 0.
 */
void
crfree(cr)
	struct ucred *cr;
{
	int	s = splhigh();

	if (--cr->cr_ref != 0) {
		(void) splx(s);
		return;
	}
	kfree(cr, sizeof(*cr));
	cractive--;
	(void) splx(s);
}

/*
 * Copy cred structure to a new one and free the old one.
 */
struct ucred *
crcopy(cr)
	struct ucred *cr;
{
	struct ucred *newcr;

	newcr = crget();
	*newcr = *cr;
	crfree(cr);
	newcr->cr_ref = 1;
	return(newcr);
}

/*
 * Dup cred struct to a new held one.
 */
struct ucred *
crdup(cr)
	struct ucred *cr;
{
	struct ucred *newcr;

	newcr = crget();
	*newcr = *cr;
	newcr->cr_ref = 1;
 	return(newcr);
}

#if	POSIX_KERN
/*
 * plan 212 (authored, D024; original _setsid 0x108474, _setpgid 0x1084d0):
 * POSIX sessions and process groups through struct posix_proc.
 */
setsid()
{
	register struct proc *p = u.u_procp;
	register struct posix_proc *px = get_posix_proc(p->p_pid);

	if (px->p_pgid == p->p_pid || pgfind(p->p_pid)) {
		u.u_error = EPERM;
		return;
	}
	enterpgrp(p, p->p_pid, 1);
	u.u_r.r_val1 = p->p_pid;
}

setpgid()
{
	register struct a {
		int	pid;
		int	pgid;
	} *uap = (struct a *)u.u_ap;
	register struct proc *curp = u.u_procp;
	register struct proc *targp;
	register struct posix_proc *curpx, *targpx;
	register struct pgrp *pgrp;

	if (uap->pgid < 0) {
		u.u_error = EINVAL;
		return;
	}
	curpx = get_posix_proc(curp->p_pid);
	if (uap->pid != 0 && uap->pid != curp->p_pid) {
		if ((targp = pfind(uap->pid)) == 0 || !inferior(targp)) {
			u.u_error = ESRCH;
			return;
		}
		targpx = get_posix_proc(targp->p_pid);
		if (targpx->p_session != curpx->p_session) {
			u.u_error = EPERM;
			return;
		}
		if (targp->p_flag & SEXEC) {
			u.u_error = EACCES;
			return;
		}
	} else {
		targp = curp;
		targpx = curpx;
	}
	if (SESS_LEADER(targp, targpx)) {
		u.u_error = EPERM;
		return;
	}
	if (uap->pgid == 0)
		uap->pgid = targp->p_pid;
	else if (uap->pgid != targp->p_pid)
		if ((pgrp = pgfind(uap->pgid)) == 0 ||
		    pgrp->pg_session != curpx->p_session) {
			u.u_error = EPERM;
			return;
		}
	enterpgrp(targp, uap->pgid, 0);
}
#endif	POSIX_KERN
