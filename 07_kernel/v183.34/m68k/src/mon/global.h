/*
 * mon/global.h (m68k overlay, plan 437, D068) -- partial header authored for
 * this project (D024).  Only the members the kernel common C files use
 * (panic() in bsd/kern/subr_prf.c) are declared; their names and order
 * follow NeXTMach mk-108.1 mon/global.h:99-101, their offsets come from the
 * original m68k _panic (0x400bc66: movew a3@(0x30a), a3@(0x30c), a3@(0x312)).
 * mg_pad0 is a project name for the members not reconstructed;
 * sizeof(struct mon_global) is not the original's.  Candidate for
 * replacement by the full NeXTMach header when the m68k machine-dependent
 * part (M4) stages its closure.
 */
/*
 * NeXTMach mon/global.h:
 * (c) 1986 NeXT
 */
#ifndef _MON_GLOBAL_PARTIAL_H_
#define _MON_GLOBAL_PARTIAL_H_

struct mon_global {
	char	mg_pad0[0x30a];		/* +0x000: not reconstructed */
	short	mg_minor, mg_seq;	/* +0x30a, +0x30c */
	int	(*mg_anim_run)();	/* +0x30e */
	short	mg_major;		/* +0x312 */
};

#endif /* _MON_GLOBAL_PARTIAL_H_ */
