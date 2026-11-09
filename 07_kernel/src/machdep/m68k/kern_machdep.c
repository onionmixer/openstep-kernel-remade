/*
 *	Copyright (C) 1990,  NeXT, Inc.
 *
 *	File:	next/kern_machdep.c
 *	Author:	John Seamons
 *
 *	Machine-specific kernel routines.
 *
 * HISTORY
 *  5-Mar-90  John Seamons (jks) at NeXT
 *	Created.
 */

/*
 * m68k: next/kern_machdep.c of the 1997 m68k kernel (plans 527-529, D024, D103,
 * D104, D110, D114).  Head comment from NeXTMach mk-108.1 next/kern_machdep.c.
 * Both function bodies are written from the original bytes (0x40929c6 and
 * 0x40929ec): a subtype is accepted if it is CPU_SUBTYPE_MC680x0_ALL,
 * CPU_SUBTYPE_MULTIPLE or that of machine_slot[0] (0x40b5dd0), compared in that
 * order; grade_cpu_subtype returns 1 for the first two and 2 for the third.
 * NeXTMach (68030/68040 check only), the i386 file and Darwin 0.1 ppc differ.
 * The form (ANSI definitions, separate tests in grade_cpu_subtype) is the
 * user's choice among byte-equivalent forms (plan 528).  Lines marked plan 529
 * differ from NeXTMach.
 */

#import	<sys/types.h>
#import	<mach/machine.h>	/* plan 529 (D104): NeXTMach <sys/machine.h> */
#import	<m68k/cpu.h>	/* plan 529 (D110): NeXTMach <next/cpu.h> */

int
check_cpu_subtype(cpu_subtype_t cpu_subtype)	/* plan 529 (D024): body from the original bytes */
{
	struct machine_slot *ms = &machine_slot[cpu_number()];

	if (cpu_subtype == CPU_SUBTYPE_MC680x0_ALL ||
	    cpu_subtype == CPU_SUBTYPE_MULTIPLE ||
	    cpu_subtype == ms->cpu_subtype)
		return (TRUE);
	return (FALSE);
}

int
grade_cpu_subtype(cpu_subtype_t cpu_subtype)	/* plan 529 (D024): new in the 1997 kernel, from the original bytes */
{
	struct machine_slot *ms = &machine_slot[cpu_number()];

	if (cpu_subtype == CPU_SUBTYPE_MC680x0_ALL)
		return 1;
	if (cpu_subtype == CPU_SUBTYPE_MULTIPLE)
		return 1;
	if (cpu_subtype == ms->cpu_subtype)
		return 2;
	return 0;
}
