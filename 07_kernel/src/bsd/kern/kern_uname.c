/*
 * plan 237 (authored, D024): the uname system call, written from the
 * original OPENSTEP 4.2 x86 kernel object [0x10b464, 0x10b600).  No
 * reference text was used.
 */

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <mach/machine.h>

/*
 * The utsname layout of the original (five 32-byte fields:
 * copyoutstr targets +0x00, +0x20, +0x40, +0x60 and +0x80).
 */
#define	SYS_NMLN	32

struct utsname {
	char	sysname[SYS_NMLN];
	char	nodename[SYS_NMLN];
	char	release[SYS_NMLN];
	char	version[SYS_NMLN];
	char	machine[SYS_NMLN];
};

uname()
{
	register struct a {
		struct utsname	*name;
	} *uap = (struct a *)u.u_ap;
	char	buf[SYS_NMLN];
	u_int	len;
	extern char	hostname[];

	u.u_error = copyoutstr("NEXTSTEP", uap->name->sysname,
	    SYS_NMLN, &len);
	if (u.u_error)
		return;
	u.u_error = copyoutstr(hostname, uap->name->nodename,
	    SYS_NMLN, &len);
	if (u.u_error)
		return;
	sprintf(buf, "%d", 0);
	u.u_error = copyoutstr(buf, uap->name->release, SYS_NMLN, &len);
	if (u.u_error)
		return;
	sprintf(buf, "%d", 4);
	u.u_error = copyoutstr(buf, uap->name->version, SYS_NMLN, &len);
	if (u.u_error)
		return;
	switch (machine_slot[0].cpu_subtype) {
	case CPU_SUBTYPE_386:
		u.u_error = copyoutstr("386 AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	case CPU_SUBTYPE_486:
		u.u_error = copyoutstr("486 AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	case CPU_SUBTYPE_486SX:
		u.u_error = copyoutstr("486SX AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	case CPU_SUBTYPE_586:
		u.u_error = copyoutstr("586 AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	case CPU_SUBTYPE_586SX:
		u.u_error = copyoutstr("586SX AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	default:
		u.u_error = copyoutstr("Unknown AT", uap->name->machine,
		    SYS_NMLN, &len);
		break;
	}
}
