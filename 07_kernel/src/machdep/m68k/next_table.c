/* 
 * Copyright (c) 1989 NeXT, Inc.
 **********************************************************************
 * HISTORY
 * 27-Mar-89  Gregg Kellogg (gk) at NeXT, Inc.
 *	Created.
 *
 **********************************************************************
 */

/*
 * m68k: next/next_table.c of the 1997 m68k kernel (plans 507-508, D103, D104,
 * D106).  Base: NeXTMach mk-108.1 next/next_table.c (above notice).
 * machine_table follows the original: TBL_NeXT_CPU_REV returns the global
 * cpu_rev, TBL_NeXT_CPU_REV2 cpu_clk, TBL_NeXT_HAS_NeXTbus nbic_present (names
 * from the SDK m68k/table.h), and table id 16 (no name in the reference
 * headers, D106) returns 32 bytes whose first int tells whether the machine
 * type (upper four bits of cpu_rev) is not 3, 5 or 9.  The include lines use
 * the OPENSTEP paths (D104); next/scr.h is not included (its scr1 is not in
 * the original).  Lines marked plan 508 differ from NeXTMach.
 */

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/dir.h>
#import <sys/user.h>
#import <sys/buf.h>
#import <sys/vnode.h>
#import <sys/file.h>
#import <sys/proc.h>
#import <sys/conf.h>
#import <sys/ioctl.h>
#import <sys/tty.h>
#import <sys/vfs.h>
#import <ufs/mount.h>
#import <ufs/fs.h>
#import <sys/kernel.h>
#import <sys/table.h>
#import <sys/socket.h>
#import <net/if.h>
#import <m68k/cpu.h>	/* plan 508 (D104): NeXTMach <next/cpu.h> */
#import <dev/busvar.h>	/* plan 508 (D104): NeXTMach <nextdev/busvar.h>; <next/scr.h> not included */

extern int nbic_present;	/* plan 508 (D106) */

/*
 * Machine dependent table routines.
 * Override TBL_IOINFO and TBL_DISKINFO.
 * Provide TBL_NeXT_CPU_REV.
 */
#define	MAXLEL	(sizeof(long))	/* maximum element length (for set) */

int machine_table(int id, int index, caddr_t addr, int nel, u_int lel, int set)
{
	caddr_t			data;
	u_int			size;
	struct	tbl_ioinfo	ti;
	struct	tbl_diskinfo	td;
	int			info[8];	/* plan 508 (D106): was u_char cpu_rev */
	struct proc		*p;

	switch (id) {
	case TBL_IOINFO: {
		register int i;
		register struct ifnet *ifp;
		if (index != 0 || nel != 1)
			return TBL_MACHDEP_BAD;
		ti.io_ttin = tk_nin;
		ti.io_ttout = tk_nout;
		ti.io_dkbusy = dk_busy;

		/*
		 * Special code to get drive name out of io structures.
		 */
		ti.io_ndrive = 0;
		for (i = 0; bus_dinit[i].bd_driver; i++)
			if (bus_dinit[i].bd_dk >= 0)
				ti.io_ndrive++;
		for (i = 0, ifp = ifnet; ifp; ifp = ifp->if_next)
			i++;
		ti.io_nif = i;
		data = (caddr_t)&ti;
		size = sizeof (ti);
		break;
	}

	case TBL_DISKINFO: {
		register int i, j;

		/*
		 * Next specific code to get per disk information.
		 */
		for (i = 0; bus_dinit[i].bd_driver; i++)
			if (bus_dinit[i].bd_dk == index)
				break;
		if (!bus_dinit[i].bd_driver)
			return TBL_MACHDEP_BAD;
		strncpy(td.di_name, bus_dinit[i].bd_name,
			sizeof(td.di_name)-2);
		td.di_name[j = strlen(td.di_name)] =
			'0'+ bus_dinit[i].bd_unit;
		td.di_name[j+1] = '\0';

		if (index >= dk_ndrive)
			return TBL_MACHDEP_BAD;
		td.di_time = dk_time[index];
		td.di_seek = dk_seek[index];
		td.di_xfer = dk_xfer[index];
		td.di_wds = dk_wds[index];
		td.di_bps = dk_bps[index];
		data = (caddr_t)&td;
		size = sizeof (td);
		break;
	}
	case TBL_NeXT_CPU_REV:

		/*
		 * Return the cpu revision of the machine.
		 */
		data = (caddr_t)&cpu_rev;	/* plan 508: the global cpu_rev */
		size = sizeof(cpu_rev);
		break;
#ifdef	DEBUG
	case TBL_FP_INFO:
		p = pfind(index);
		if (p == (struct proc *)0) {
			u.u_error = ESRCH;
			return;
		}
		
		data = (caddr_t)&(p->task->u_address->uu_fptrace);
		size = sizeof (struct fptrace_data); 
		break;
#endif	DEBUG
	case TBL_NeXT_CPU_REV2:	/* plan 508 */
		data = (caddr_t)&cpu_clk;
		size = sizeof(cpu_clk);
		break;
	case TBL_NeXT_HAS_NeXTbus:	/* plan 508 */
		data = (caddr_t)&nbic_present;
		size = sizeof(nbic_present);
		break;
	case 16:	/* plan 508 (D106) */
		switch (cpu_rev >> 4) {
		case 3:
		case 5:
		case 9:
			info[0] = 0;
			break;
		default:
			info[0] = 1;
		}
		data = (caddr_t)info;
		size = sizeof(info);
		break;
	default:
		return TBL_MACHDEP_NONE;
	}

	size = MIN(size, lel);
	if (size) {
		if (set) {
			char buff[MAXLEL];

			u.u_error = copyin(addr, buff, size);
			if (u.u_error == 0)
				bcopy(buff, data, size);
		}
		else {
			u.u_error = copyout(data, addr, size);
		}
	}

	if (u.u_error)
		return TBL_MACHDEP_BAD;

	return TBL_MACHDEP_OKAY;
}

/*
 * Should this id be set?
 */
int machine_table_setokay(int id)
{
	return TBL_MACHDEP_BAD;
}
