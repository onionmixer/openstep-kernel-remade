/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * 26-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: removed dir.h
 *
 * 13-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Removed dependencies on proc table.
 *
 * 27-Oct-87  Robert Baron (rvb) at Carnegie-Mellon University
 *	Syscall now does read/write readv/writev in parallel and rwuio
 *	does unix_master call.
 *
 * 30-Sep-87  David Golub (dbg) at Carnegie-Mellon University
 *	New scheduling state machine.
 *
 * 31-Jan-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Support for multiple threads.
 *
 * 27-Jan-87  Mike Accetta (mja) at Carnegie-Mellon University
 *	Modified to allow new FNOSPC flag bit in file table to prohibit
 *	any disk space resource pauses on a per-file basis.
 *	[ V5.1(F1) ]
 *
 * 25-Jan-86  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Upgraded to 4.3.
 *
 * 10-Oct-85  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Apply bug fix for selwakeup.
 *
 * 03-Aug-85  Mike Accetta (mja) at Carnegie-Mellon University
 *	CS_RPAUSE:  added resource pause hook in rwuio() for
 *	disk space exhaustion.
 *
 */
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)sys_generic.c	7.1 (Berkeley) 6/5/86
 */

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/ioctl.h>
#import <sys/file.h>
#import <sys/proc.h>
#import <sys/uio.h>
#import <sys/kernel.h>
#import <sys/stat.h>
#import <machine/spl.h>

#import <kern/thread.h>
#import <kern/sched_prim.h>

#import <kern/parallel.h>

/*
 * Read system call.
 */
read()
{
	register struct a {
		int	fdes;
		char	*cbuf;
		unsigned count;
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov;

	aiov.iov_base = (caddr_t)uap->cbuf;
	aiov.iov_len = uap->count;
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	rwuio(&auio, UIO_READ);
}

readv()
{
	register struct a {
		int	fdes;
		struct	iovec *iovp;
		unsigned iovcnt;
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov[16];		/* XXX */

	if (uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
		u.u_error = EINVAL;
		return;
	}
	auio.uio_iov = aiov;
	auio.uio_iovcnt = uap->iovcnt;
	u.u_error = copyin((caddr_t)uap->iovp, (caddr_t)aiov,
	    uap->iovcnt * sizeof (struct iovec));
	if (u.u_error)
		return;
	rwuio(&auio, UIO_READ);
}

/*
 * Write system call
 */
write()
{
	register struct a {
		int	fdes;
		char	*cbuf;
		unsigned count;
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov;

	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	aiov.iov_base = uap->cbuf;
	aiov.iov_len = uap->count;
	rwuio(&auio, UIO_WRITE);
}

writev()
{
	register struct a {
		int	fdes;
		struct	iovec *iovp;
		unsigned iovcnt;
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov[16];		/* XXX */

	if (uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
		u.u_error = EINVAL;
		return;
	}
	auio.uio_iov = aiov;
	auio.uio_iovcnt = uap->iovcnt;
	u.u_error = copyin((caddr_t)uap->iovp, (caddr_t)aiov,
	    uap->iovcnt * sizeof (struct iovec));
	if (u.u_error)
		return;
	rwuio(&auio, UIO_WRITE);
}

rwuio(uio, rw)
	register struct uio *uio;
	enum uio_rw rw;
{
	struct a {
		int	fdes;
	};
	register struct file *fp;
	register struct iovec *iov;
	int i, count;
	volatile int on_master = 0;	/* plan 182 (variant r1): kept on the stack in the original (0x10ceb4) */
	int rcount;	/* resume count */

	GETF(fp, ((struct a *)u.u_ap)->fdes);
	if ((fp->f_flag&(rw==UIO_READ ? FREAD : FWRITE)) == 0) {
		u.u_error = EBADF;
		return;
	}
	uio->uio_resid = 0;
	uio->uio_segflg = UIO_USERSPACE;
	iov = uio->uio_iov;
	for (i = 0; i < uio->uio_iovcnt; i++) {
		if (iov->iov_len < 0) {
			u.u_error = EINVAL;
			return;
		}
		uio->uio_resid += iov->iov_len;
		if (uio->uio_resid < 0) {
			u.u_error = EINVAL;
			return;
		}
		iov++;
	}
	count = uio->uio_resid;
resume:
	rcount = uio->uio_resid;
	uio->uio_offset = fp->f_offset;
	if (setjmp(&u.u_qsave)) {
		unix_reset();
		if (uio->uio_resid == count) {
			if ((u.u_sigintr & sigmask(u.u_procp->p_cursig)) != 0)
				u.u_error = EINTR;
			else
				u.u_eosys = RESTARTSYS;
		}
	} else
	{
		if (on_master++ == 0) unix_master();
		u.u_error = (*fp->f_ops->fo_rw)(fp, rw, uio);
	}
	u.u_r.r_val1 = count - uio->uio_resid;
	fp->f_offset += (rcount - uio->uio_resid);
	if (u.u_error && fspause(fp->f_flag&FNOSPC)) goto resume;
	unix_release();
}

/*
 * Ioctl system call
 */
ioctl()
{
	register struct file *fp;
	struct a {
		int	fdes;
		int	cmd;
		caddr_t	cmarg;
	} *uap;
	register int com;
	register u_int size;
	char data[IOCPARM_MASK+1];

	uap = (struct a *)u.u_ap;
	GETF(fp, uap->fdes);
	if ((fp->f_flag & (FREAD|FWRITE)) == 0) {
		u.u_error = EBADF;
		return;
	}
	com = uap->cmd;

#if defined(vax) && defined(COMPAT)
	/*
	 * Map old style ioctl's into new for the
	 * sake of backwards compatibility (sigh).
	 */
	if ((com&~0xffff) == 0) {
		com = mapioctl(com);
		if (com == 0) {
			u.u_error = EINVAL;
			return;
		}
	}
#endif
	if (com == FIOCLEX) {
		u.u_pofile[uap->fdes] |= UF_EXCLOSE;
		return;
	}
	if (com == FIONCLEX) {
		u.u_pofile[uap->fdes] &= ~UF_EXCLOSE;
		return;
	}

	/*
	 * Interpret high order word to find
	 * amount of data to be copied to/from the
	 * user's address space.
	 */
	size = (com &~ (IOC_INOUT|IOC_VOID)) >> 16;
	if (size > sizeof (data)) {
		u.u_error = EFAULT;
		return;
	}
	if (com&IOC_IN) {
		if (size) {
			u.u_error =
			    copyin(uap->cmarg, (caddr_t)data, (u_int)size);
			if (u.u_error)
				return;
		} else
			*(caddr_t *)data = uap->cmarg;
	} else if ((com&IOC_OUT) && size)
		/*
		 * Zero the buffer on the stack so the user
		 * always gets back something deterministic.
		 */
		bzero((caddr_t)data, size);
	else if (com&IOC_VOID)
		*(caddr_t *)data = uap->cmarg;

	switch (com) {

	case FIONBIO:
		u.u_error = fset(fp, FNDELAY, *(int *)data);
		return;

	case FIOASYNC:
		u.u_error = fset(fp, FASYNC, *(int *)data);
		return;

	case FIOSETOWN:
		u.u_error = fsetown(fp, *(int *)data);
		return;

	case FIOGETOWN:
		u.u_error = fgetown(fp, (int *)data);
		return;
	}
	u.u_error = (*fp->f_ops->fo_ioctl)(fp, com, data);
	/*
	 * Copy any data to user, size was
	 * already set and checked above.
	 */
	if (u.u_error == 0 && (com&IOC_OUT) && size)
		u.u_error = copyout(data, uap->cmarg, (u_int)size);
}

int	nselcoll;

/*
 * plan 182 (authored, D024; original _select 0x10d290, _selcont 0x10d3f0,
 * _selscan 0x10d614, _selthreadcache 0x10d740, _selthreadclear 0x10d7b0,
 * _selwakeup 0x10d7e4): select() with a continuation; its state lives
 * in u.u_select so that selcont() can be restarted after the sleep.
 */
struct uap {
	int	nd;
	fd_set	*in, *ou, *ex;
	struct	timeval *tv;
};

static const struct _select select_zero = { 0 };	/* __TEXT,__const in the original (0x1d10dc) */

int selcont();

/*
 * Select system call.
 */
select()
{
	register struct uap *uap = (struct uap *)u.u_ap;
	register struct _select *sel = &u.u_select;
	struct timeval now;
	int ni;

	*sel = select_zero;
	if (uap->nd > NOFILE)
		uap->nd = NOFILE;	/* forgiving, if slightly wrong */
	ni = howmany(uap->nd, NFDBITS);

#define	getbits(name, x) \
	if (uap->name) { \
		sel->error = copyin((caddr_t)uap->name, (caddr_t)&sel->ibits[x], \
		    (unsigned)(ni * sizeof(fd_mask))); \
		if (sel->error) \
			goto cont; \
	}
	getbits(in, 0);
	getbits(ou, 1);
	getbits(ex, 2);
#undef	getbits

	if (uap->tv) {
		sel->error = copyin((caddr_t)uap->tv, (caddr_t)&sel->atv,
			sizeof (sel->atv));
		if (sel->error)
			goto cont;
		if (itimerfix(&sel->atv)) {
			sel->error = EINVAL;
			goto cont;
		}
		if ((sel->atv.tv_sec == 0) && (sel->atv.tv_usec == 0))
			sel->poll = 1;
		else {
			getthetime(&now);
			timevaladd(&sel->atv, &now);
		}
	}
cont:
	selcont();
}

int
selcont()
{
	register struct uap *uap = (struct uap *)u.u_ap;
	register struct _select *sel = &u.u_select;
	register struct proc *p;
	struct timeval now;
	int s, ncoll, ni;

	if (sel->error < 0) {
		/*
		 * Back from the sleep: see why.
		 */
		register int wr = thread_wait_result();	/* plan 182.1 (variant t3) */

		if (wr == THREAD_INTERRUPTED || wr == THREAD_SHOULD_TERMINATE)
			sel->error = EINTR;
		else
			sel->error = 0;
	}
	if (sel->error > 0)
		goto done;
retry:
	ncoll = nselcoll;
	p = u.u_procp;
	p->p_flag |= SSEL;
	u.u_r.r_val1 = selscan(sel->ibits, sel->obits, uap->nd);
	sel->error = u.u_error;	/* selscan may set u.u_error - UGH! */
	if (sel->error || u.u_r.r_val1 || sel->poll)
		goto done;
	s = splhigh();
	if (uap->tv) {
		getthetime(&now);
		/* this should be timercmp(&now, &sel->atv, >=) */
		if (now.tv_sec > sel->atv.tv_sec ||
		    now.tv_sec == sel->atv.tv_sec &&
		    now.tv_usec >= sel->atv.tv_usec) {
			splx(s);
			goto done;
		}
	}
	if ((p->p_flag & SSEL) == 0 || nselcoll != ncoll) {
		p->p_flag &= ~SSEL;
		splx(s);
		goto retry;
	}
	p->p_flag &= ~SSEL;
	sel->error = -1;	/* sleeping */
	if (uap->tv)
		sleep_with_continuation_and_deadline((caddr_t)&selwait,
		    PZERO+1, selcont, &sel->atv);
	else
		sleep_with_continuation((caddr_t)&selwait, PZERO+1, selcont);
done:
	ni = howmany(uap->nd, NFDBITS);
#define	putbits(name, x) \
	if (uap->name) { \
		sel->error = copyout((caddr_t)&sel->obits[x], (caddr_t)uap->name, \
		    (unsigned)(ni * sizeof(fd_mask))); \
	}
	if (sel->error == 0) {
		putbits(in, 0);
		putbits(ou, 1);
		putbits(ex, 2);
#undef putbits
	}
	if (sel->error)
		u.u_error = sel->error;
	unix_syscall_return(sel->error);
}

selscan(ibits, obits, nfd)
	fd_set *ibits, *obits;
{
	register int which, i, j;
	register fd_mask bits;
	int flag;
	struct file *fp;
	int n = 0;
	static int flags[3] = { FREAD, FWRITE, 0 };

	for (which = 0; which < 3; which++) {
		flag = flags[which];
		for (i = 0; i < nfd; i += NFDBITS) {
			bits = ibits[which].fds_bits[i/NFDBITS];
			if (bits == 0)
				continue;
			for (j = 0; j < NFDBITS; j++) {
				if ((bits & 1) == 0) {
					bits >>= 1;
					continue;
				}
				if ((i + j) >= nfd)
					break;
				if ((i + j) >= u.u_ofile_cnt)
					break;
				fp = u.u_ofile[i + j];
				if (fp == NULL) {
					u.u_error = EBADF;
					break;
				}
				if ((*fp->f_ops->fo_select)(fp, flag)) {
					FD_SET(i + j, &obits[which]);
					n++;
				}
				bits >>= 1;
				if (bits == 0)
					break;
			}
		}
	}
	return (n);
}

/*ARGSUSED*/
seltrue(dev, flag)
	dev_t dev;
	int flag;
{

	return (1);
}

/*
 * Remember the current thread as the one selecting on an object; returns
 * 1 if another thread is already waiting (a collision).
 */
int
selthreadcache(threadp)
	thread_t *threadp;
{
	register thread_t thread;
	int s = splhigh();

	if (thread = *threadp) {
		if (thread->active && thread->wait_event == (event_t)&selwait) {
			splx(s);
			return (1);
		}
		*threadp = THREAD_NULL;
		splx(s);
		thread_deallocate(thread);
	} else
		splx(s);
	thread = current_thread();
	thread_reference(thread);
	*threadp = thread;
	return (0);
}

void
selthreadclear(threadp)
	thread_t *threadp;
{
	if (threadp == 0)
		panic("selthreadclear not passed an address\n");
	if (*threadp)
		thread_deallocate_interrupt(*threadp);
	*threadp = THREAD_NULL;
}

selwakeup(thread, coll)
	register thread_t thread;
	int coll;
{

	if (coll) {
		nselcoll++;
		wakeup((caddr_t)&selwait);
	}
	if (thread && thread->active) {
		int s = splhigh();

		if (thread->wait_event == (event_t)&selwait)
			clear_wait(thread, THREAD_AWAKENED, TRUE);
		if (thread->task->proc)
			thread->task->proc->p_flag &= ~SSEL;
		splx(s);
	}
}
