/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 * HISTORY
 * Revision 2.24  89/12/22  15:38:25  rpd
 * 	Obscure bug fix: always send SIGMSG and SIGEMSG to traced
 * 	processes to avoid dropping SIGUSR1 and SIGUSR2 on the floor.
 * 	Found by Chia Chao at HP Labs.
 * 	[89/12/01            dlb]
 * 
 * Revision 2.18  89/05/30  10:34:04  rvb
 * 	Fixed the SWITCH_INT thing: only the object you
 * 	switch on needs to be recasted, NOT the individual "case foo"
 * 	entries. [Next time make sure you test your code, tx]
 * 
 * Revision 2.16  89/04/18  16:42:12  mwyoung
 * 	Pick up issig() fix from dlb/avie to avoid signal action on
 * 	system processes, as the comment said.
 * 	[89/04/16            mwyoung]
 * 
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	Removed <sys/dir.h>
 *
 * 24-Oct-88  Steve Stone (steve) at NeXT
 *	Added Attach trace support.
 *
 * 25-Mar-88  Avadis Tevanian, Jr. (avie) at NeXT.
 *	Really be sure task/thread is resumed upon SIGKILL.
 *
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	MACH: No more SSLEEP.
 *
 * 20-Apr-88  David Black (dlb) at Carnegie-Mellon University
 *	Allow exception signals to be used as back-door ipc.  (XXX)
 *
 * 29-Mar-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	MACH: Include "machine/vmparam.h" rather than "sys/vm.h" to get
 *	USRSTACK declaration.
 *
 * 15-Jan-88  David Golub (dbg) at Carnegie-Mellon University
 *	Call task_suspend_nowait from interrupt level.
 *
 * 29-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	issig() and psig() no longer need to switch to/from master; they
 *	are always called when already on master CPU.  (Besides that, there
 *	is no unix_release() in the return path of sig_lock!)
 *
 * 21-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Better sig_lock; and completely set signal state before calling
 *	sendsig().
 *
 * 21-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Cleaned up conditionals (whew!).  Purged history.  Conditionals
 *	could probably be further reduced.
 *
 * 19-Aug-87  Peter King (king) at NeXT
 *	SUN_VFS: Changed inodes to vnodes.
 */
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)kern_sig.c	7.1 (Berkeley) 6/5/86
 */

#import <cputypes.h>
#import <mach_host.h>

#import <machine/reg.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/vfs.h>
#import <sys/vnode.h>
#import <sys/proc.h>
#import <sys/timeb.h>
#import <sys/times.h>
#import <sys/buf.h>
#import <machine/vmparam.h>	/* Get USRSTACK */
#import <sys/acct.h>
#import <sys/uio.h>
#import <sys/kernel.h>

#import <machine/spl.h>

#import <kern/sched.h>
#import <mach/vm_param.h>	/* plan 230: NeXTMach vm/vm_param.h */
#import <kern/thread.h>
#import <kern/parallel.h>
#import <machine/cpu.h>
#import <kern/sched_prim.h>
#import <kern/task.h>
#import <mach-o/loader.h>	/* plan 230: NeXTMach sys/loader.h */
#import <vm/vm_kern.h>


/*
 * Create a core image on the file "core"
 * If you are looking for protection glitches,
 * there are probably a wealth of them here
 * when this occurs to a suid command.
 *
 * It writes UPAGES block of the
 * user.h area followed by the entire
 * data+stack segments.
 */
core()
{
	struct vnode	*vp;
	struct vattr	vattr;
	vm_map_t	map;
	int		thread_count, segment_count;
	int		command_size, header_size, tstate_size;	/* plan 230.1: tstate_size before hoffset (stack slots) */
	int		hoffset, foffset, vmoffset;
	vm_offset_t	header;
	struct machine_slot	*ms;
	struct mach_header	*mh;
	struct segment_command	*sc;
	struct thread_command	*tc;
	vm_size_t	size;
	vm_prot_t	prot;
	vm_prot_t	maxprot;
	vm_inherit_t	inherit;
	boolean_t	is_shared;
	port_t		name;
	vm_offset_t	offset;
	int		error;
	task_t		task;
	thread_t	thread;
	char		core_name[32];	/* plan 230: 32 B in the original frame */
	/* plan 230 (authored): flavor list (original 0x103a09-0x103ab1) */
	struct thread_state_flavor flavors[10];
	vm_size_t	nflavors;
	int		i;

	if (u.u_procp->p_flag&SXONLY)
		return (0);
	u.u_uid = u.u_ruid;
	u.u_procp->p_uid = u.u_ruid;
	u.u_gid = u.u_rgid;

	/*
	 *	Don't want to resource-pause while core-dumping.
	 */
	u.u_rpause = 0;

	task = current_task();
	map = task->map;
	if (map->size >= u.u_rlimit[RLIMIT_CORE].rlim_cur)
		return (0);
	(void) task_halt(task);	/* stop this task, except for current thread */
	/*
	 *	Make sure all registers, etc. are in pcb so they get
	 *	into core file.
	 */
	pcb_synch(current_thread());
	u.u_error = 0;
	vattr_null(&vattr);
	vattr.va_type = VREG;
	vattr.va_mode = 0644;
	sprintf(core_name, "/cores/core.%d", u.u_procp->p_pid);
	u.u_error =
	    vn_create(core_name, UIO_SYSSPACE, &vattr, NONEXCL, VWRITE, &vp,
		      u.u_cred);
	if (u.u_error) {
		u.u_error = 0;
		vattr_null(&vattr);
		vattr.va_type = VREG;
		vattr.va_mode = 0644;
		u.u_error =
		    vn_create("core", UIO_SYSSPACE, &vattr, NONEXCL,
		    	VWRITE, &vp, u.u_cred);
		if (u.u_error)
			return (0);
	}
	if (vattr.va_nlink != 1) {
		error = EFAULT;			/* plan 230 (0x1039a7) */
		goto out;
	}
	vattr_null(&vattr);
	vattr.va_size = 0;
	(void) VOP_SETATTR(vp, &vattr, u.u_cred);
	u.u_acflag |= ACORE;

	/*
	 *	If the task is modified while dumping the file
	 *	(e.g., changes in threads or VM, the resulting
	 *	file will not necessarily be correct.
	 */

	thread_count = task->thread_count;
	segment_count = map->hdr.nentries;	/* plan 230: 07 vm_map.h (map + 0x1c, 0x103a00) */

	/*
	 * plan 230 (authored): the thread states are the flavors the
	 * current thread reports (original 0x103a09-0x103aed).
	 */
	nflavors = sizeof(flavors)/sizeof(int);
	if (thread_getstatus(current_thread(), THREAD_STATE_FLAVOR_LIST,
			     (thread_state_t)flavors, &nflavors) != KERN_SUCCESS)
		panic("core flavor list");
	nflavors /= sizeof(struct thread_state_flavor)/sizeof(int);
	tstate_size = 0;
	for (i = 0; i < nflavors; i++)
		tstate_size += sizeof(struct thread_state_flavor) +
			flavors[i].count*sizeof(int);

	command_size = segment_count*sizeof(struct segment_command) +
		thread_count*sizeof(struct thread_command) +
		tstate_size*thread_count;

	header_size = command_size + sizeof(struct mach_header);

	(void) kmem_alloc_wired(kernel_map, &header, header_size);

	/*
	 *	Set up Mach-O header.
	 */
	mh = (struct mach_header *) header;
	ms = &machine_slot[cpu_number()];
	mh->magic = MH_MAGIC;
	mh->cputype = ms->cpu_type;
	mh->cpusubtype = ms->cpu_subtype;
	mh->filetype = MH_CORE;
	mh->ncmds = segment_count + thread_count;
	mh->sizeofcmds = command_size;

	hoffset = sizeof(struct mach_header);	/* offset into header */
	foffset = round_page(header_size);	/* offset into file */
	vmoffset = VM_MIN_ADDRESS;		/* offset into VM */
	error = 0;
	while (segment_count > 0) {		/* plan 230 (0x103b54) */
		/*
		 *	Get region information for next region.
		 */
		if (vm_region(map, &vmoffset, &size, &prot, &maxprot,
			  &inherit, &is_shared, &name, &offset)
					== KERN_NO_SPACE)
			break;

		/*
		 *	Fill in segment command structure.
		 */
		sc = (struct segment_command *) (header + hoffset);
		sc->cmd = LC_SEGMENT;
		sc->cmdsize = sizeof(struct segment_command);
		/* segment name is zerod by kmem_alloc */
		sc->vmaddr = vmoffset;
		sc->vmsize = size;
		sc->fileoff = foffset;
		sc->filesize = size;
		sc->maxprot = maxprot;
		sc->initprot = prot;
		sc->nsects = 0;

		/*
		 *	Write segment out.  Try as hard as possible to
		 *	get read access to the data.
		 */
		if ((prot & VM_PROT_READ) == 0) {
			vm_protect(map, vmoffset, size, FALSE,
				   prot|VM_PROT_READ);
		}
		/*
		 *	Only actually perform write if we can read.
		 *	Note: if we can't read, then we end up with
		 *	a hole in the file.
		 */
		if ((maxprot & VM_PROT_READ) == VM_PROT_READ) {
			error = vn_rdwr(UIO_WRITE, vp, vmoffset, size, foffset,
				UIO_USERSPACE, IO_UNIT, (int *) 0);
		}

		hoffset += sizeof(struct segment_command);
		foffset += size;
		vmoffset += size;
		segment_count--;
	}
	task_lock(task);
	thread = (thread_t) queue_first(&task->thread_list);
	while (thread_count > 0) {
		/*
		 *	Fill in thread command structure.
		 */
		tc = (struct thread_command *) (header + hoffset);
		tc->cmd = LC_THREAD;
		/* plan 230 (authored; original 0x103cd0-0x103d9f) */
		tc->cmdsize = sizeof(struct thread_command) + tstate_size;
		hoffset += sizeof(struct thread_command);

		for (i = 0; i < nflavors; i++) {
			*(struct thread_state_flavor *)(header+hoffset) =
				flavors[i];
			hoffset += sizeof(struct thread_state_flavor);
			thread_getstatus(thread, flavors[i].flavor,
					 (thread_state_t)(header+hoffset),
					 &flavors[i].count);
			hoffset += flavors[i].count*sizeof(int);
		}
		thread = (thread_t) queue_next(&thread->thread_list);
		thread_count--;
	}
	task_unlock(task);

	/*
	 *	Write out the Mach header at the beginning of the
	 *	file.
	 */
	error = vn_rdwr(UIO_WRITE, vp, header, header_size, (off_t)0,
			UIO_SYSSPACE, IO_UNIT, (int *) 0);
	kmem_free(kernel_map, header, header_size);
out:
	VN_RELE(vp);
	u.u_error = error;
	return(error == 0);
}