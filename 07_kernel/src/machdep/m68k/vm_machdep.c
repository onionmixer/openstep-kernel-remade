/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 05-Dec-88  Avadis Tevanian (avie) at NeXT
 *	Cleaned up cruft.
 *
 *  2-Apr-88  John Seamons (jks) at NeXT
 *	Fixed to work right -- was completely wrong before.
 *
 * 15-Nov-86  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 */ 

/*
 * m68k: pagemove of the 1997 m68k kernel (plans 617-618, D103, D140, D141),
 * the original range [0x409aaf6, 0x409ab9c).  Notice and HISTORY above from
 * NeXTMach mk-108.1 next/vm_machdep.c:1-13; the function below is that file's
 * lines 19-46 with NeXT_page_size renamed m68k_page_size (the 1997 name) and
 * a void return type (user decision D141).  The imports are the 1997 stage
 * paths (NeXTMach vm/vm_param.h and next/pmap.h are not in it), and the pte
 * declarations below, with their notice, are NeXTMach next/pmap.h lines
 * (the shared m68k pmap.h has no pte_t).  The i386 vm_machdep.c kernacc is
 * not in the m68k original.  The marks give the changed lines.
 */
#import <sys/types.h>	/* plan 618 (D141): imported by NeXTMach next/pmap.h */
#import <mach/vm_param.h>	/* plan 618 (D141): NeXTMach <vm/vm_param.h> */
#import <vm/vm_kern.h>
#import <vm/pmap.h>	/* plan 618 (D141): NeXTMach <next/pmap.h> */

/* 
 * Copyright (c) 1987, 1988, 1989, 1990 NeXT, Inc.
 */
/* plan 618 (D141): NeXTMach mk-108.1 next/pmap.h:86-97, 102-118, 123-129, 147, 169 */
struct pt2_030_entry {
u_long		pfn:24,			/* page frame number */
		reserved:1,		/* reserved */
		cm:1,			/* cache mode */
#define	CM_030_CACHED		0
#define	CM_030_CACHE_INH	1
		wired:1,		/* wired down (software-only field) */
		modify:1,		/* page has been modified */
		refer:1,		/* page has been referenced (used) */
		write_prot:1,		/* write protection */
		desctype:2;		/* descriptor type */
};

struct pt3_040_entry {
u_long		pfn:20,			/* page frame number */
		wired:1,		/* wired down (software-only field) */
		global:1,		/* global (kernel) pte */
		u1:1,			/* user pte attribute */
		reserved:1,		/* reserved */
		super:1,		/* super mode access only */
		cm:2,			/* cache mode */
#define	CM_040_WRITETHRU	0
#define	CM_040_COPYBACK		1	/* copyback mode */
#define	CM_040_INH_SERIAL	2	/* serialized mode so devices will work */
#define	CM_040_INH_NONSERIAL	3
		modify:1,		/* page has been modified */
		refer:1,		/* page has been referenced (used) */
		write_prot:1,		/* write protection */
		desctype:2;		/* descriptor type */
};

/* note: significant assumption that pte is same size for both processors */
union pte {
	struct pt2_030_entry	pte_030;
	struct pt3_040_entry	pte_040;
	u_long			bits;
};
typedef	union pte	pte_t;

#define	PTE_ENTRY_NULL		0

pte_t		*pmap_pte(), *pmap_pte_valid();

/*
 * Move pages from one kernel virtual address to another.
 * Both addresses are assumed to reside in the kernel map.
 */
void	/* plan 618 (D141): user decision; NeXTMach has no return type */
pagemove(from, to, size)
	register caddr_t from, to;
	int size;
{
	pmap_t pmap;
	register pte_t *fpte, *tpte;

	if (size % PAGE_SIZE)
		panic("pagemove");
	pmap = vm_map_pmap(kernel_map);
	while (size > 0) {
		while ((int)(fpte = pmap_pte(pmap, from)) < PTE_ENTRY_NULL)
			pmap_expand_kernel(from, fpte);
		while ((int)(tpte = pmap_pte(pmap, to)) < PTE_ENTRY_NULL)
			pmap_expand_kernel(to, tpte);
		*tpte = *fpte;
		fpte->bits = 0;
		pflush_user();
		pflush_user();
		from += m68k_page_size;	/* plan 618 (D141): NeXTMach NeXT_page_size */
		to += m68k_page_size;	/* plan 618 (D141): NeXTMach NeXT_page_size */
		size -= m68k_page_size;	/* plan 618 (D141): NeXTMach NeXT_page_size */
	}
}
