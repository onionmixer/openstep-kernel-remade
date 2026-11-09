/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 18-Aug-90  John Seamons (jks) at NeXT
 *	Use splvm() in pt_alloc() and pt_free().
 *
 * 31-Jul-90  John Seamons (jks) at NeXT
 *	Removed all the old 030-specific code.
 *
 *  5-Jul-90  Mike Paquette (mpaque) at NeXT
 *	Modified tt_lmask for the kernel transparent address register to also grant
 *	access to a built-in color frame buffer at 0x82xxxxxx, for the low end color 
 *	system.
 *
 *  1-Jul-90  John Seamons (jks) at NeXT
 *	Removed concept of "shadow page tables" that hold virtual page
 *	addresses since a private page table allocator is used.
 *	Saves 50% of level 1 and 2 page table space.
 *	Also removes the code to support 030-specific page tables -- saves space.
 *	Added low-overhead garbage collector in pt_free() to free complete pages
 *	via kmem_free() when possible.
 *
 *  8-Mar-90  John Seamons (jks) at NeXT
 *	Moved updates of pmap->stats.resident_count inside if check of return
 *	value from pmap_phys_to_index().  Resident count will only be maintained for
 *	pages which are in a region (and hence a pv_list).
 *
 *  8-Mar-90  John Seamons (jks) at NeXT
 *	An UNLOCK_PMAP_U() was in the wrong place in pmap_expand().
 *
 * 28-Feb-90  John Seamons (jks) at NeXT
 *	Added thread agrument to pmap_tt() routine.
 *
 * 22-Nov-89  John Seamons (jks) at NeXT
 *	Rewrite to support both 68030 and 68040 MMU stratigies.
 */ 

/*
 *	Manages physical address maps.
 *
 *	In addition to hardware address maps, this
 *	module is called upon to provide software-use-only
 *	maps which may or may not be stored in the same
 *	form as hardware maps.  These pseudo-maps are
 *	used to store intermediate results from copy
 *	operations to and from address spaces.
 *
 *	Since the information managed by this module is
 *	also stored by the logical address mapping module,
 *	this module may throw away valid virtual-to-physical
 *	mappings at almost any time.  However, invalidations
 *	of virtual-to-physical mappings must be done as
 *	requested.
 *
 *	In order to cope with hardware architectures which
 *	make virtual-to-physical map invalidates expensive,
 *	this module may delay invalidate or reduced protection
 *	operations until such time as they are actually
 *	necessary.  This module is given full information as
 *	to which processors are currently using which maps,
 *	and to when physical maps must be made correct.
 */
/*
 * plan 687 (D160, D013, D024, D104, D110, D154): the 1997 m68k pmap.c.
 * NeXTMach mk-108.1 next/pmap.c with the include lines in OPENSTEP paths, the
 * NeXT_ names renamed m68k_ (the 1997 names, as in the SDK mach/m68k/
 * vm_param.h) and these changes, from the original bytes [0x4096e20, 0x40990ba):
 *	data		page_table_alloc_size, page_table_memory_size and
 *			managed_page_count without initializer; no map_size, no
 *			pv_lock_table; m68k_cache_inhibit_serial and _nonserial
 *	pt_alloc	kmem_alloc_wired()
 *	pt_free		the page scan only when pmap_phys_to_index() != -1
 *	pmap_set_page_size	the two cache inhibit modes
 *	pmap_size	max_virtual_size when the argument is 0 (signed)
 *	pmap_map, pmap_enter, pmap_enter_mapping	a serial argument that
 *			selects the cache inhibit mode
 *	pmap_bootstrap	rewritten (see its comment)
 *	pmap_init	kmem_alloc_wired(), no pv_lock_table
 *	pmap_extract, pmap_resident_extract	a pte that is not DT_PTE also
 *			takes the transparent translation test
 *	pmap_expand_kernel	clears the new page table
 *	pmap_tt		no cache unless cache is set; PCB_TT1 0x80000000
 *	pmap_attribute, compress_data_from_phys, uncompress_data_to_phys	new
 * The machine pmap definitions are in this file (see below).  These spellings
 * are this project's choices (the bytes do not show them; D160): the in-file
 * definitions, MSG_BSIZE, the vidGetFBAddrAndSize declaration, the argument
 * and local names, numbers for addresses without a NeXTMach name.  The
 * SET_CACHE lines outside pmap_bootstrap are not compiled and only renamed
 * (pmap_bootstrap's SET_CACHE and !BMAP_TBI lines went with its rewrite).
 * Lines marked plan 687 differ from NeXTMach (a marked BEGIN/END region as a
 * whole).
 */

/* get around a current BMAP chip bug */
#define	BMAP_TBI 1

#if	SET_CACHE
extern int debug;
#endif	SET_CACHE

#import <cpus.h>
#import <show_space.h>
/*
 * plan 687 (D160, D013, D104): BEGIN the machine pmap definitions this file
 * uses.  The shared 07 machdep/m68k/pmap.h (struct pmap with the offsets
 * that other objects use, no page table types) is skipped by defining its
 * guard here; the lines below are NeXTMach mk-108.1 next/pmap.h lines 25-235
 * with the NeXT_ names renamed m68k_ and without pv_lock_table.  Its notice:
 */
/* 
 * Copyright (c) 1987, 1988, 1989, 1990 NeXT, Inc.
 */
#define _MACHDEP_M68K_PMAP_H_
#import <sys/types.h>
#import <kern/zalloc.h>
#import <kern/lock.h>
#import <mach/m68k/vm_param.h>
#import <m68k/mmu.h>
#import <mach/vm_statistics.h>
/* first level page table entry */
struct pt1_030_entry {
u_long		lower:1,
		limit:15,
		:7,
		super:1,
		:4,
		refer:1,		/* entry has been used */
		write_prot:1,		/* write protection */
		desctype:2;		/* descriptor type */
u_long		l2ptr:28,		/* pointer to level 2 table */
		:4;
};

#define	PT1_030_SHIFT	3
#define	PT1_030_L2PTR	4

struct pt1_040_entry {
u_long		l2ptr:23,		/* pointer to level 2 table */
		: 5,
		refer:1,		/* entry has been used */
		write_prot:1,		/* write protection */
		desctype:2;		/* descriptor type */
};

#define	PT1_040_SHIFT	2
#define	PT1_040_L2PTR	9

union pt1 {
	struct pt1_030_entry	pt1_030;
	struct pt1_040_entry	pt1_040;
};
typedef	union pt1	pt1_t;

/* fields that occupy similar bit positions in both page table types */
#define	pt1_lower	pt1_030.lower
#define	pt1_limit	pt1_030.limit
#define	pt1_refer	pt1_030.refer
#define	pt1_write_prot	pt1_030.write_prot
#define	pt1_desctype	pt1_030.desctype

#define	phys_to_l2ptr(p)	((int)(p) >> m68k_pt1_l2ptr)
#define	l2ptr_to_phys(p)	((int)(p) << m68k_pt1_l2ptr)

/* second level page table entry (68040 only) */
struct pt2_040_entry {
u_long		pt2_l3ptr:25,		/* pointer to level 3 table */
		: 3,
		pt2_refer:1,		/* entry has been used */
		pt2_write_prot:1,	/* write protection */
		pt2_desctype:2;		/* descriptor type */
};
typedef struct pt2_040_entry pt2_t;

#define	PT2_040_SHIFT	2
#define	PT2_040_L3PTR	7

#define	phys_to_l3ptr(p)	((int)(p) >> m68k_pt2_l3ptr)
#define	l3ptr_to_phys(p)	((int)(p) << m68k_pt2_l3ptr)

/* highest level page table entry */
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

#define	PT2_030_SHIFT	2
#define	PT2_030_PFN	8

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

#define	PT3_040_SHIFT	2
#define	PT3_040_PFN	12

/* note: significant assumption that pte is same size for both processors */
union pte {
	struct pt2_030_entry	pte_030;
	struct pt3_040_entry	pte_040;
	u_long			bits;
};
typedef	union pte	pte_t;

/* fields that occupy the same bit positions in both pte types */
#define	pte_wired	pte_030.wired
#define	pte_modify	pte_030.modify
#define	pte_refer	pte_030.refer
#define	pte_write_prot	pte_030.write_prot
#define	pte_desctype	pte_030.desctype

#define	phys_to_pfn(p)	((int)(p) >> m68k_pte_pfn)
#define	pfn_to_phys(p)	((int)(p) << m68k_pte_pfn)

/* residency codes */
#define	PT1_UPPER_NULL		-5	/* order sensitive */
#define	PT1_ENTRY_NULL		-4
#define	PT2_ENTRY_NULL		-3
#define	PTE_UPPER_NULL		-2
#define	PTE_LOWER_NULL		-1
#define	PTE_ENTRY_NULL		0

/* Descriptor type */
#define	DT_INVALID	0		/* out-of-bounds or not resident */
#define	DT_PTE		1		/* valid page table entry */
#define	DT_SHORT	2		/* valid short format page table */
#define	DT_LONG		3		/* valid long format page table */

struct pmap {
	struct mmu_rp	rp;		/* root pointer of pte map */
	pt1_t		*pt1;		/* address of level 1 page table */
	int		ref_count;	/* reference count */
	decl_simple_lock_data(, lock)	/* lock on map */
	struct pmap_statistics stats;	/* map statistics */
};

typedef struct pmap	*pmap_t;
#define	PMAP_NULL	((pmap_t) 0)

/*
 *	Machine dependent routines that are used only for NeXT.
 */
pte_t		*pmap_pte(), *pmap_pte_valid();
vm_offset_t	pmap_resident_extract();

/*
 *	For each vm_page_t, there is a list of all currently
 *	valid virtual mappings of that page.  An entry is
 *	a pv_entry_t; the list is the pv_table.  [Indexing on the
 *	pv_table is identical to the vm_page_array.]
 */
typedef struct pv_entry {
	struct pv_entry	*next;		/* next pv_entry */
	pmap_t		pmap;		/* pmap where mapping lies */
	vm_offset_t	va;		/* virtual address for mapping */
} *pv_entry_t;

#define	PV_ENTRY_NULL	((pv_entry_t) 0)

#ifdef	KERNEL
pv_entry_t	pv_head_table;		/* array of entries, one per page */
zone_t		pv_list_zone;		/* zone of pv_entry structures */

/*
 *	Each entry in the pv_head_table is locked by a bit in the 
 *	pv_lock_table.  The lock bits are accessed by the physical
 *	address of the page they lock.
 */
#define	pai_to_pvh(pai)		(&pv_head_table[pai])

/* plan 687 (D024, D160): char *pv_lock_table removed (not in the original) */
#define	pv_lock_table_size(n)	(((n)+BYTE_SIZE-1)/BYTE_SIZE)
#if	!defined(KERNEL_FEATURES)
#import <cpus.h>
#else	!defined(KERNEL_FEATURES)
#import <sys/features.h>
#endif	!defined(KERNEL_FEATURES)
#if	NCPUS > 1
/* FIXME: replace while loop with something better? */
#define LOCK_PVH(pai) { while (bbssi (pai, pv_lock_table)); }
#define UNLOCK_PVH(pai) { bbcci (pai, pv_lock_table); }
#else	NCPUS > 1
#define LOCK_PVH(pai)
#define UNLOCK_PVH(pai)
#endif	NCPUS > 1
#endif	KERNEL

/*
 *	Macros for speed.
 */
#define	PMAP_ACTIVATE(pmap, th, cpu) \
	pmove_crp (&pmap->rp);

#define	PMAP_DEACTIVATE(pmap, th, cpu)

/*
 *	PMAP_CONTEXT: update any thread-specific hardware context that
 *		is managed by pmap module.
 */

#define PMAP_CONTEXT(pmap, thread)

#define	pmap_resident_count(pmap)	((pmap)->stats.resident_count)

#define		PMAP_TT_DISABLE		0
#define		PMAP_TT_ENABLE		1
#define		PMAP_TT_NON_CACHEABLE	0
#define		PMAP_TT_CACHEABLE	1
void		pmap_tt();
/* plan 687 (D160): END of the machine pmap definitions */

#import <sys/types.h>
#import <kern/thread.h>
#import <kern/zalloc.h>
#import <kern/lock.h>
#import <sys/systm.h>
#import <sys/param.h>
#import <kern/kalloc.h>
#import <vm/pmap.h>
#import <vm/vm_map.h>
#import <vm/vm_kern.h>
#import <mach/vm_param.h>	/* plan 687 (D104): NeXTMach <vm/vm_param.h> */
#import <mach/vm_prot.h>	/* plan 687 (D104): NeXTMach <vm/vm_prot.h> */
#import <mach/vm_attributes.h>	/* plan 687 (D160): vm_machine_attribute_t for pmap_attribute */
#import <vm/vm_page.h>
#import <mach/m68k/vm_param.h>	/* plan 687 (D104): NeXTMach <next/vm_param.h> */
/* plan 687 (D104, D024, D160): NeXTMach #import <next/pcb.h> left out; its PCB_TT1 (next/pcb.h:34)
   with the 1997 value, bit 7 of byte +0x54 of the int pcb_flags (as TRACE_PENDING in trap.c, D144) */
#define	PCB_TT1		0x80000000
#import <m68k/mmu.h>	/* plan 687 (D104): NeXTMach <next/mmu.h> */
#import <m68k/cpu.h>	/* plan 687 (D110): NeXTMach <next/cpu.h> */
/* plan 687 (D110, D160): BEGIN NeXTMach next/cpu.h names used here (next/cpu.h:95-128, 188) */
extern int	slot_id;
#define	SLOT_ID		slot_id
#define	P_EPROM		(SLOT_ID+0x00000000)
#define P_EPROM_BMAP	(SLOT_ID+0x01000000)
#define	P_EPROM_SIZE	(128 * 1024)
#define	P_DEV_SPACE	(SLOT_ID+0x02000000)
#define	P_DEV_BMAP	(SLOT_ID+0x02100000)
#define	P_MAINMEM	(SLOT_ID+0x04000000)
/* plan 687 (D110, D160): NeXTMach #import <next/scr.h> left out; its names used here (next/scr.h:34-37) */
#define	NeXT_CUBE	0
#define	NeXT_WARP9	1
#define	NeXT_X15	2
#define	NeXT_WARP9C	3
/* plan 687 (D110, D160): END */
#import <machine/spl.h>
#import <sys/msgbuf.h>	/* plan 687 (D160): MSG_BSIZE */

struct pmap	kernel_pmap_store;	/* the kernel pmap structure */
pmap_t		kernel_pmap;		/* pointer to above */
struct zone	*pmap_zone;		/* zone of pmap structures */
lock_data_t	pmap_lock;		/* read/write lock for pmap system */
/* plan 687 (D024, D160): long map_size removed (a local of pmap_bootstrap) */

/*
 *	Macros to extract page table index bits from a virtual address.
 */
#define	PT1_INDEX(va) \
	(((va) & m68k_pt1_mask) >> m68k_pt1_shift)
#define	PT2_INDEX(va) \
	(((va) & m68k_pt2_mask) >> m68k_pt2_shift)
#define	PTE_INDEX(va) \
	(((va) & m68k_pte_mask) >> m68k_pte_shift)
#define	VA_INDEX(va) \
	((va) & m68k_page_mask)

#define	PT1(pt1, index) \
	((pt1_t*) ((int)(pt1) + ((index) << PT1_040_SHIFT)))
#define	PTE(pte, field) \
	((cpu_type != MC68030)? ((struct pt3_040_entry*)(pte))->field : \
	((struct pt2_030_entry*)(pte))->field)

/*
 *	Physical address of the next available upper level kernel map area and
 *	the maximum address of the kernel map.  Used by pmap_expand_kernel to
 *	assign upper level kernel maps to level one entries.
 */
vm_offset_t	avail_kernel_map;
vm_offset_t	max_kernel_map;

vm_offset_t	phys_map_vaddr1;
vm_offset_t	phys_map_vaddr2;
pte_t		*phys_map_pte1;
pte_t		*phys_map_pte2;

/*
 *	Locking Protocols:
 *
 *	There are two structures in the pmap module that need locking:
 *	the pmap's themselves, and the per-page pv_lists (which are locked
 *	by locking the pv_lock_table entry that corresponds the to pv_head
 *	for the list in question.)  Most routines want to lock a pmap and
 *	then do operations in it that require pv_list locking -- however
 *	pmap_remove_all and pmap_copy_on_write operate on a physical page
 *	basis and want to do the locking in the reverse order, i.e. lock
 *	a pv_list and then go through all the pmaps referenced by that list.
 *	To protect against deadlock between these two cases, the pmap_lock
 *	is used.  There are three different locking protocols as a result:
 *
 *  1.  pmap operations only (pmap_extract, pmap_access, ...)  Lock only
 *		the pmap.
 *
 *  2.  pmap-based operations (pmap_enter, pmap_remove, ...)  Get a read
 *		lock on the pmap_lock (shared read), then lock the pmap
 *		and finally the pv_lists as needed [i.e. pmap lock before
 *		pv_list lock.]
 *
 *  3.  pv_list-based operations (pmap_remove_all, pmap_copy_on_write, ...)
 *		Get a write lock on the pmap_lock (exclusive write); this
 *		also guaranteees exclusive access to the pv_lists.  Lock the
 *		pmaps as needed.
 *
 *	At no time may any routine hold more than one pmap lock or more than
 *	one pv_list lock.  Because interrupt level routines can allocate
 *	mbufs and cause pmap_enter's, the pmap_lock and the lock on the
 *	kernel_pmap can only be held at splvm.
 */

/*
 *	Lock and unlock macros for the pmap system.  Interrupts must be locked
 *	out because mbufs can be allocated at interrupt level and cause
 *	a pmap_enter.
 */
#if	NCPUS > 1
#define READ_LOCK(s)		s = splvm(); lock_read(&pmap_lock);
#define READ_UNLOCK(s)		lock_read_done(&pmap_lock); splx(s);
#define WRITE_LOCK(s)		s = splvm(); lock_write(&pmap_lock);
#define WRITE_UNLOCK(s)		lock_write_done(&pmap_lock); splx(s);
#else	NCPUS > 1
#define READ_LOCK(s)		s = splvm();
#define READ_UNLOCK(s)		splx(s);
#define WRITE_LOCK(s)		s = splvm();
#define WRITE_UNLOCK(s)		splx(s);
#endif	NCPUS > 1

/*
 *	Lock and unlock macros for pmaps.  Interrupts must be locked out for
 *	the kernel pmap because device must read (and therefore lock) it.
 */
#define	LOCK_PMAP_U(map) \
	simple_lock(&(map)->lock);
#define	LOCK_PMAP(map,s) \
	if (map == kernel_pmap) \
		s = splvm(); \
	LOCK_PMAP_U(map);
#define	UNLOCK_PMAP_U(map) \
	simple_unlock(&(map)->lock);
#define UNLOCK_PMAP(map,s) \
	UNLOCK_PMAP_U(map); \
	if (map == kernel_pmap) \
		splx(s);

/*
 *	Macros to invalidate translation buffer.  Use map to figure out
 *	which buffer to invalidate.  Names blatently stolen from VAX.
 */
#define TBIA_K \
	pflush_super();

#define TBIA_U \
	if (current_thread() != THREAD_NULL) \
		pflush_user();

#define	TBIA(map) \
	if ((map) == kernel_pmap) \
		pflush_super(); \
	else \
	if (current_thread() != THREAD_NULL) \
		pflush_user();

#define	current_pmap()		(vm_map_pmap(current_thread()->task->map))

/*
 *	Calculate page_shift and page_mask from the page size.
 *
 *	We decide on the size of the kernel page tables given this
 *	crucial constraint: a single page table should fit entirely within
 *	one physical page so we don't have to allocate physically
 *	contiguous pages from the kernel_map (which kmem_alloc() is NOT
 *	prepared to do).  Map pointers are all
 *	physical addresses (unlike the VAX) and so each map must
 *	be physically contiguous.  If the page tables always fit in a
 *	single page the problem goes away.  For a 32 bit virtual address
 *	space using 2 page table levels then the tables will always fit
 *	in a single page if the page size is >= 4KB.
 *
 *	When there is a shortage of bits the highest level page table is
 *	sized to completely fill a physical page.
 */
int	m68k_page_size,		/* bytes per NeXT page */
	m68k_page_mask,		/* mask for page offset */
	m68k_page_shift,	/* number of bits to shift for pages */
	m68k_tia,		/* table index a */
	m68k_tib,		/* table index b */
	m68k_tic,		/* table index c */
	m68k_pt1_desctype,	/* page table descriptor types */
	m68k_pt2_desctype,
	m68k_pt1_elemsize,	/* size of an individual level 1 pte element */
	m68k_pte_elemsize,
	m68k_pt1_entries,	/* number of entries per level 1 page table */
	m68k_pt2_entries,
	m68k_pte_entries,
	m68k_pt1_size,		/* size of a single level 1 page table */
	m68k_pt2_size,
	m68k_pte_size,
	m68k_pt1_shift,		/* bits to shift for pt1 index */
	m68k_pt2_shift,
	m68k_pte_shift,
	m68k_pt1_mask,		/* mask to apply for pt1 index */
	m68k_pt2_mask,
	m68k_pte_mask,
	m68k_pt2_maps,		/* a single pt2 maps this much VA space */
	m68k_pte_maps,
	m68k_pt1_l2ptr,		/* phys <-> page table pointer shift factors */
	m68k_pt2_l3ptr,
	m68k_pte_pfn,
	m68k_ptes_per_page,	/* number of ptes in a MI page */
#if	SET_CACHE
	m68k_cache_k,
#endif	SET_CACHE
	m68k_cache,		/* cache mode values */
	m68k_cache_inhibit_serial,	/* plan 687 (D024, D160) */
	m68k_cache_inhibit_nonserial;

struct mmu_rp m68k_kernel_mmu_rp;	/* kernel mode MMU registers */
struct mmu_030_tc m68k_kernel_mmu_030_tc;
struct mmu_030_tt m68k_kernel_mmu_030_tt;
struct mmu_040_tc m68k_kernel_mmu_040_tc;
struct mmu_040_tt m68k_kernel_mmu_040_tt;

vm_size_t	page_table_alloc_size;	/* plan 687 (D024, D160) */
int		pmap_gc = 1;
vm_size_t	page_table_memory_size;	/* plan 687 (D024, D160) */
long		managed_page_count;	/* plan 687 (D024, D160) */
extern int	cache;

/*
 *	Given an offset and a map, return the address of the pte.
 *	If any level table entry is invalid then return
 *	a special code that indicates how the table must grow.
 */
pte_t *pmap_pte(pmap_t pmap, vm_offset_t va)
{
	pt1_t	*pt1;
	pt2_t	*pt2;
	int	pt1_index = PT1_INDEX(va), pt2_index = PT2_INDEX(va),
			pte_index = PTE_INDEX(va);

	pt1 = PT1(pmap->pt1, pt1_index);
	if (pt1->pt1_desctype != m68k_pt1_desctype)
		return((pte_t*) PT1_ENTRY_NULL);
	pt2 = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr) + pt2_index;
	if (pt2->pt2_desctype != m68k_pt2_desctype)
		return((pte_t*) PT2_ENTRY_NULL);
	return((pte_t*) l3ptr_to_phys(pt2->pt2_l3ptr) + pte_index);
}

/*
 *	Perform a pmap_pte operation on a va we know has a proper mapping
 *	(and do less checking as a result).
 */
pte_t *pmap_pte_valid(pmap_t pmap, vm_offset_t va)
{
	pt1_t	*pt1;
	pt2_t	*pt2;
	int	pt1_index = PT1_INDEX(va), pt2_index = PT2_INDEX(va),
			pte_index = PTE_INDEX(va);

	pt1 = PT1(pmap->pt1, pt1_index);
	pt2 = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr) + pt2_index;
	return((pte_t*) l3ptr_to_phys(pt2->pt2_l3ptr) + pte_index);
}

#if	DEBUG

check_pv_list()
{
	pv_entry_t	pv_h, pv_e;
	int		i;

	pv_h = pv_head_table;
	for (i = 0; i < managed_page_count; i++) {
		if (pv_h->pmap != PMAP_NULL) {
			pv_e = pv_h;
			do {
				if ((int)pmap_pte(pv_e->pmap, pv_e->va) <
					PTE_ENTRY_NULL) {
					panic("check pv list");
				}
				pv_e = pv_e->next;
			} while (pv_e != PV_ENTRY_NULL);
		}
		pv_h++;
	}
}

int	should_check_pv_list = 0;

#define CHECK_PV	{ if (should_check_pv_list) check_pv_list(); }
#else	DEBUG
#define	CHECK_PV
#endif	DEBUG

/*
 *	Assume that there are three protection codes, all using low bits.
 *	(A true assumption for the Mach VM code).
 */
int	protection_codes[8];

/*
 *	Given a machine independent protection code, convert to an
 *	MMU protection code.  Note that write access implies
 *	full access.  There are no write only pages.  Also note that
 *	the kernel always has at least read access.
 */
int m68k_protection_init()
{
	int	*p, prot;

	p = protection_codes;

	for (prot = 0; prot < 8; prot++) {
		switch (prot) {
		case VM_PROT_NONE | VM_PROT_NONE | VM_PROT_NONE:
			*p++ = 0;
			break;
		case VM_PROT_READ | VM_PROT_NONE | VM_PROT_NONE:
		case VM_PROT_READ | VM_PROT_NONE | VM_PROT_EXECUTE:
		case VM_PROT_NONE | VM_PROT_NONE | VM_PROT_EXECUTE:
			*p++ = TRUE;
			break;
		case VM_PROT_NONE | VM_PROT_WRITE | VM_PROT_NONE:
		case VM_PROT_NONE | VM_PROT_WRITE | VM_PROT_EXECUTE:
		case VM_PROT_READ | VM_PROT_WRITE | VM_PROT_NONE:
		case VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE:
			*p++ = FALSE;
			break;
		}
	}
}

#define m68k_protection(pmap, prot) (protection_codes[prot])

/*
 *	pt_alloc() will return page table zone memory aligned to the correct boundary
 *	depending on the processor being used.  The 68040 requires all page tables
 *	be aligned to their sizes so address concatination (instead of addition)
 *	can be used in the hardware.  This is why memory is managed locally in this
 *	case.  The zone package cannot align to such large boundaries itself.
 *
 *	pt_free() never gives the memory back directly, so the virtual address
 *	it was allocated from doesn't need to be kept around.  This means the shadow
 *	table mentioned below doesn't need to be maintained.  Always extract the
 *	physical address and pass it back to the caller.  The garbage collector uses
 *	the pv_list to determine the original virtual address when freeing.
 */
 
typedef	struct	pt_hdr {
	u_int		magic;
#define	PT_HDR_MAGIC	0x2a6a6b73		/* never a possible page table entry */
	struct pt_hdr	*next, *prev;
} pt_hdr_t;

struct pt_zone {
	decl_simple_lock_data(,	lock)
	pt_hdr_t		*next, *prev;
	vm_size_t		elem_size;
	vm_size_t		memory, alloc;
	int			free_count;
	int			elems_per_page;
} ptzone, ptezone,
	*pt_zone = &ptzone, *pte_zone = &ptezone;
	
static pt_init (zone, size)
	struct pt_zone *zone;
	vm_size_t	size;
{
	bzero (zone, sizeof *zone);
	simple_lock_init (&zone->lock);
	zone->elem_size = size;
	zone->elems_per_page = PAGE_SIZE/size;
}

static vm_offset_t pt_alloc(zone)
	struct pt_zone	*zone;
{
	vm_offset_t	addr, newmem, pt_base, pt;
	vm_size_t	newsize;
	int		s;

	s = splvm();
	simple_lock (&zone->lock);
again:
	if (addr = (vm_offset_t) zone->prev) {
		zone->prev = ((pt_hdr_t*)addr)->prev;
		if (zone->prev)
			zone->prev->next = 0;
		else
			zone->next = 0;
		zone->free_count--;
	} else {
		newsize = PAGE_SIZE;
		page_table_alloc_size += PAGE_SIZE;
		zone->alloc += PAGE_SIZE;
		simple_unlock (&zone->lock);
		splx(s);
		kmem_alloc_wired (kernel_map, &newmem, newsize);	/* plan 687 (D024, D160) */
		newmem = pmap_resident_extract (kernel_pmap, newmem);
		s = splvm();
		simple_lock (&zone->lock);
		while (newsize) {
			((pt_hdr_t*)newmem)->magic = PT_HDR_MAGIC;
			((pt_hdr_t*)newmem)->next = zone->next;
			((pt_hdr_t*)newmem)->prev = 0;
			if (zone->next)
				zone->next->prev = (pt_hdr_t*)newmem;
			else
				zone->prev = (pt_hdr_t*)newmem;
			zone->next = (pt_hdr_t*)newmem;
			newmem += zone->elem_size;
			newsize -= zone->elem_size;
			zone->free_count++;
		}
		goto again;
	}
	page_table_memory_size += zone->elem_size;
	zone->memory += zone->elem_size;
	simple_unlock (&zone->lock);
	splx(s);
	ASSERT((addr & (zone->elem_size - 1)) == 0);
	bzero (addr, zone->elem_size);
	return (addr);
}

static void pt_free(zone, addr)
	struct pt_zone	*zone;
	vm_offset_t	addr;
{
	pt_hdr_t	*ptp;
	vm_offset_t	pt_base, pt, va, free_page = 0;
	int		free_count, found, s;
	pv_entry_t	pv_h;
	
	s = splvm();
	simple_lock (&zone->lock);
	
	/* see if we can free an entire page */
	/* plan 687 (D024, D160): no ASSERT(pmap_phys_to_index (addr) != -1); the test is below */
	((pt_hdr_t*)addr)->magic = PT_HDR_MAGIC;
	free_count = 0;
	/*
	 * Only scan if we are guaranteed to leave some memory in the zone.
	 */
	if (pmap_phys_to_index (addr) != -1 &&	/* plan 687 (D024, D160) */
	    zone->free_count > zone->elems_per_page) {
		pt_base = trunc_page (addr);
		for (pt = pt_base; pt < pt_base + PAGE_SIZE;
				pt += zone->elem_size) {
			if (((pt_hdr_t*)pt)->magic != PT_HDR_MAGIC)
				break;
			free_count++;
		}
	}
	((pt_hdr_t*)addr)->magic = 0;
	
	/* scan the entire free list looking for pieces of the page */
	if (pmap_gc && free_count == zone->elems_per_page) {
		found = 0;
		for (ptp = zone->next; ptp; ptp = ptp->next) {
			if (trunc_page(ptp) == pt_base) {
				ASSERT(ptp->magic == PT_HDR_MAGIC);
				if (ptp->prev)
					ptp->prev->next = ptp->next;
				else
					zone->next = ptp->next;
				if (ptp->next)
					ptp->next->prev = ptp->prev;
				else
					zone->prev = ptp->prev;
				found++;
			}
		}
		ASSERT(found == free_count - 1);
		pv_h = pai_to_pvh (pmap_phys_to_index (addr));
		ASSERT(pv_h != 0);
		ASSERT(pv_h->next == 0);
		ASSERT(pv_h->pmap == kernel_pmap);
		page_table_alloc_size -= PAGE_SIZE;
		zone->alloc -= PAGE_SIZE;
		zone->free_count -= zone->elems_per_page;
		free_page = pv_h->va;
	} else {
		if (zone->next)
			zone->next->prev = (pt_hdr_t*)addr;
		((pt_hdr_t*)addr)->magic = PT_HDR_MAGIC;
		((pt_hdr_t*)addr)->next = zone->next;
		((pt_hdr_t*)addr)->prev = 0;
		if (zone->next)
			zone->next->prev = (pt_hdr_t*)addr;
		else
			zone->prev = (pt_hdr_t*)addr;
		zone->next = (pt_hdr_t*)addr;
		zone->free_count++;
	}
	page_table_memory_size -= zone->elem_size;
	zone->memory -= zone->elem_size;
	simple_unlock (&zone->lock);
	splx(s);
	if (free_page)
		kmem_free (kernel_map, free_page, PAGE_SIZE);
}

void pmap_set_page_size()
{
	int i;

	m68k_page_mask = m68k_page_size - 1;
	for (m68k_page_shift = 0, i = 1; i != m68k_page_size; i <<= 1)
		m68k_page_shift++;

	if (m68k_page_size == 4096)
		m68k_tic = 6;
	else
		m68k_tic = 5;
	m68k_pte_elemsize = 1 << PT3_040_SHIFT;
	m68k_pte_entries = 1 << m68k_tic;
	m68k_pte_size = m68k_pte_entries << PT3_040_SHIFT;
	m68k_pte_shift = m68k_page_shift;
	m68k_pte_mask = (m68k_pte_entries - 1) << m68k_pte_shift;
	m68k_pte_maps = m68k_pte_entries << m68k_pte_shift;
	if (cpu_type == MC68030)
		m68k_pte_pfn = PT2_030_PFN;
	else
		m68k_pte_pfn = PT3_040_PFN;

	m68k_tib = 7;
	m68k_pt2_entries = 1 << m68k_tib;
	m68k_pt2_size = m68k_pt2_entries << PT2_040_SHIFT;
	m68k_pt2_shift = m68k_pte_shift + m68k_tic;
	m68k_pt2_mask = (m68k_pt2_entries - 1) << m68k_pt2_shift;
	m68k_pt2_maps = m68k_pt2_entries << m68k_pt2_shift;
	m68k_pt2_desctype = DT_SHORT;
	m68k_pt2_l3ptr = PT2_040_L3PTR;

	m68k_tia = 7;
	m68k_pt1_elemsize = 1 << PT1_040_SHIFT;
	m68k_pt1_entries = 1 << m68k_tia;
	m68k_pt1_size = m68k_pt1_entries << PT1_040_SHIFT;
	m68k_pt1_shift = m68k_pt2_shift + m68k_tib;
	m68k_pt1_mask = (m68k_pt1_entries - 1) << m68k_pt1_shift;
	m68k_pt1_desctype = DT_SHORT;
	m68k_pt1_l2ptr = PT1_040_L2PTR;
#if	SET_CACHE
	m68k_cache = cache? CM_040_COPYBACK: CM_040_INH_NONSERIAL;
	m68k_cache_k = cache? CM_040_COPYBACK : CM_040_INH_NONSERIAL;
#else	SET_CACHE
	m68k_cache = cache? CM_040_COPYBACK : CM_040_INH_NONSERIAL;
#endif	SET_CACHE
	m68k_cache_inhibit_serial = CM_040_INH_SERIAL;	/* plan 687 (D024, D160) */
	m68k_cache_inhibit_nonserial = CM_040_INH_NONSERIAL;
	m68k_kernel_mmu_040_tc.tc_enable = TRUE;
	if (m68k_page_size == 8192)
		m68k_kernel_mmu_040_tc.tc_8k_pagesize = TRUE;

	if (cpu_type == MC68030) {
		m68k_cache = cache? CM_030_CACHED : CM_030_CACHE_INH;
		m68k_cache_inhibit_serial = CM_030_CACHE_INH;	/* plan 687 (D024, D160) */
		m68k_cache_inhibit_nonserial = CM_030_CACHE_INH;
#if	SET_CACHE
		m68k_cache_k = m68k_cache;
#endif	SET_CACHE
		m68k_kernel_mmu_030_tc.tc_enable = TRUE;
		m68k_kernel_mmu_030_tc.tc_sre = TRUE;
		m68k_kernel_mmu_030_tc.tc_ps = m68k_page_shift;
		m68k_kernel_mmu_030_tc.tc_is = 0;
		m68k_kernel_mmu_030_tc.tc_tia = m68k_tia;
		m68k_kernel_mmu_030_tc.tc_tib = m68k_tib;
		m68k_kernel_mmu_030_tc.tc_tic = m68k_tic;
	}
}

/*
 *	Pmap_size returns the number of map table bytes required to map
 *	max_virtual_size bytes.  It is assumed that all level 1 ptes are allocated,
 *	regardless of the number of upper level ptes required.
 *	min_virtual_size is the minimum amount of kernel address space that
 *	we want.  It is declared global so that it can easily be patched.
 */
long	max_virtual_size = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;

vm_size_t pmap_size(memsize)
	vm_size_t	memsize;
{
	long	l2_tables, num_ptes;
	long	size = memsize ? memsize : max_virtual_size;	/* plan 687 (D024, D160) */

	l2_tables = howmany (size, m68k_pt2_maps);	/* plan 687 (D024, D160) */
	return (m68k_pt1_size +
		l2_tables * m68k_pt2_size +
		l2_tables * (m68k_pt2_entries * m68k_pte_size));
}

#if	BMAP_TBI
/*
 *	Map memory at initialization.  The physical addresses being
 *	mapped are not managed and are never unmapped.
 */
vm_offset_t pmap_map(virt, start, end, prot, cacheable, serial)	/* plan 687 (D024, D160) */
	register vm_offset_t	virt;
	register vm_offset_t	start;
	register vm_offset_t	end;
	register int		prot;
{
	register int		ps;
	void			pmap_enter_mapping();

	ps = PAGE_SIZE;
	while (start < end) {
		pmap_enter_mapping(kernel_pmap, virt, start, prot, FALSE, cacheable, serial);	/* plan 687 (D024, D160) */
		virt += ps;
		start += ps;
	}
	return(virt);
}
#endif	BMAP_TBI

/*
 *	Bootstrap the system enough to run with virtual memory.
 *	Map the kernel's code and data, and allocate the system page table.
 *	Called with mapping OFF.
 *
 *	Parameters:
 *	avail_start	PA of first available physical page
 *	avail_end	PA of last available physical page
 *	virtual_avail	VA of first available page (after kernel bss)
 *	virtual_end	VA of last avail page (end of kernel address space)
 */
/*
 * plan 687 (D024, D160): BEGIN the 1997 pmap_bootstrap, written from the original
 * bytes [0x40974a0, 0x40979c0) up to the 68030 branch: five arguments (as
 * m68k_init calls it), no zone_alignment, the kernel page table from
 * mem_region[0], map_size a local (also the size in the region loop), the
 * 68040 mappings by machine type (vidGetFBAddrAndSize, the regions above
 * SLOT_ID + 0x08000000, the message buffer) and tt0 from lbase/lmask.
 * Addresses without a NeXTMach name are numbers.
 */
void pmap_bootstrap(mem_region, num_regions, virtual_avail, virtual_end, msgbuf)
	mem_region_t	mem_region;	/* IN/OUT */
	int		num_regions;
	vm_offset_t	*virtual_avail;	/* OUT */
	vm_offset_t	*virtual_end;	/* OUT */
	vm_offset_t	msgbuf;
{
	int		i, align;
	vm_offset_t	ptbr, avail, first;
	vm_size_t	map_size;
	pte_t		*pte;
	int		lbase, lmask;
	vm_offset_t	fbaddr;
	vm_size_t	fbsize;
	extern void	vidGetFBAddrAndSize();	/* plan 687 (D160): no header declares it */

	pt_init (pt_zone, m68k_pt1_size);
	pt_init (pte_zone, m68k_pte_size);
	m68k_protection_init();
	m68k_ptes_per_page = m68k_btop(PAGE_SIZE);
	kernel_pmap = &kernel_pmap_store;
	lock_init(&pmap_lock, FALSE);
	simple_lock_init(&kernel_pmap->lock);
	if (cpu_type != MC68030) {
		align = m68k_pt1_entries * m68k_pt1_elemsize;
	} else {
		align = l1ptr_to_phys(1);
	}
	avail = roundup(mem_region[0].first_phys_addr, align);
	ptbr = avail;
	kernel_pmap->pt1 = (pt1_t*) ptbr;
	map_size = pmap_size(0);
	avail_kernel_map = ptbr + m68k_pt1_size;
	max_kernel_map = ptbr + map_size;
	avail += map_size;
	mem_region[0].first_phys_addr = avail;
	kernel_pmap->ref_count = 1;
	kernel_pmap->rp.rp_desc_type = DT_SHORT;	/* ignored by 68040 */
	kernel_pmap->rp.rp_limit = m68k_pt1_entries - 1;
	kernel_pmap->rp.rp_ptbr = phys_to_l1ptr(ptbr);
	m68k_kernel_mmu_rp = kernel_pmap->rp;
	bzero(ptbr, map_size);
	pmap_map(trunc_page(0xf0fffff0), trunc_page(0xf0fffff0), round_page(0xf0fffff0 + 4),
		VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
	if (cpu_type != MC68030) {
		pmap_map(P_EPROM, P_EPROM, P_EPROM + P_EPROM_SIZE,
			VM_PROT_READ, TRUE, FALSE);
		pmap_map(P_EPROM_BMAP, P_EPROM_BMAP, P_EPROM_BMAP + P_EPROM_SIZE,
			VM_PROT_READ, TRUE, FALSE);
		pmap_map(P_DEV_SPACE, P_DEV_SPACE, P_DEV_SPACE + 0xc0040,
			VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
		pmap_map(P_DEV_BMAP, P_DEV_BMAP, P_DEV_BMAP + 0x1e000,
			VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
		switch (machine_type) {
		    case NeXT_WARP9C:
			lbase = P_MAINMEM >> 24;
			lmask = ~0xd4;
			break;
		    case NeXT_WARP9:
		    case NeXT_X15:
			lbase = P_MAINMEM >> 24;
			lmask = ~0xfc;
			vidGetFBAddrAndSize(&fbaddr, &fbsize);
			pmap_map(fbaddr, fbaddr, fbaddr + fbsize,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
			break;
		    case 4:
		    case 5:
		    default:
			lbase = P_MAINMEM >> 24;
			lmask = ~0xfc;
			vidGetFBAddrAndSize(&fbaddr, &fbsize);
			pmap_map(SLOT_ID + 0x02200000, SLOT_ID + 0x02200000, SLOT_ID + 0x02209000,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
			pmap_map(SLOT_ID + 0x02210000, SLOT_ID + 0x02210000, SLOT_ID + 0x02210004,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
			pmap_map(SLOT_ID + 0x03e00000, SLOT_ID + 0x03e00000, SLOT_ID + 0x03e80000,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, FALSE);
			pmap_map(fbaddr, fbaddr, fbaddr + fbsize,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
			for (i = 0; i < num_regions; i++) {
				first = mem_region[i].first_phys_addr;
				if (first >= SLOT_ID + 0x08000000) {
					map_size = pmap_size(mem_region[i].last_phys_addr - first);
					max_kernel_map += map_size;
					avail += map_size;
					mem_region[0].first_phys_addr = avail;
					pmap_map(first, first, mem_region[i].last_phys_addr,
						VM_PROT_WRITE|VM_PROT_READ, TRUE, FALSE);
				}
			}
			pmap_map(msgbuf, msgbuf, msgbuf + MSG_BSIZE,
				VM_PROT_WRITE|VM_PROT_READ, FALSE, TRUE);
			break;
		}
		m68k_kernel_mmu_040_tt.tt_lbase = lbase;
		m68k_kernel_mmu_040_tt.tt_lmask = lmask;
		m68k_kernel_mmu_040_tt.tt_e = 1;
		m68k_kernel_mmu_040_tt.tt_super = TT_040_SUPER;
		m68k_kernel_mmu_040_tt.tt_cm =
			cache? TT_040_CM_COPYBACK : TT_040_CM_INH_NONSERIAL;
/* plan 687 (D024, D160): END; the rest of pmap_bootstrap is the NeXTMach text */
	} else {
		m68k_kernel_mmu_030_tt.tt_lbase = P_EPROM >> 24;
		m68k_kernel_mmu_030_tt.tt_lmask = ~0xf0;
		m68k_kernel_mmu_030_tt.tt_e = 1;
		m68k_kernel_mmu_030_tt.tt_rwmask = 1;
		m68k_kernel_mmu_030_tt.tt_fcbase = ~(FC_SUPERI ^ FC_SUPERD);
		m68k_kernel_mmu_030_tt.tt_fcmask = FC_SUPERI ^ FC_SUPERD;
		m68k_kernel_mmu_030_tt.tt_ci = cache? 0 : 1;
	}

	/*
	 *	Allocate virtual space in the system map to be used for
	 *	manipulating physical memory.  (Two VM pages are allocated
	 *	per CPU.)  Then make sure that level two maps are allocated
	 *	for this space and remember the pte address.
	 */
	*virtual_avail = VM_MIN_KERNEL_ADDRESS;
	*virtual_end = VM_MAX_KERNEL_ADDRESS;
	phys_map_vaddr1 = *virtual_avail;
	*virtual_avail += PAGE_SIZE*NCPUS;
	phys_map_vaddr2 = *virtual_avail;
	*virtual_avail += PAGE_SIZE*NCPUS;
	for (i = phys_map_vaddr1 ; i < *virtual_avail ; i += m68k_page_size)
		if ((int) (pte = pmap_pte(kernel_pmap, i)) < PTE_ENTRY_NULL)
			pmap_expand_kernel(i, pte);
	phys_map_pte1 = pmap_pte_valid(kernel_pmap, phys_map_vaddr1);
	phys_map_pte2 = pmap_pte_valid(kernel_pmap, phys_map_vaddr2);
	*virtual_avail = round_page(*virtual_avail);

	/*
	 *	Once mapped mode is turned on, we will need to reference
	 *	the system page tables via virtual addresses.
	 *	Since the system page tables are transparently mapped
	 *	the virtual address is also the physical address.
	 *	So we don't have to fixup anything at this point.
	 */

	/*
	 *	Return to locore which will load the MMU root pointer
	 *	and will then turn on memory management.
	 */
}

/*
 *	Initialize the pmap module.
 *	Called by vm_init, to initialize any structures that the pmap
 *	system needs to map virtual memory.
 */
void pmap_init(mem_region, num_regions)
	mem_region_t	mem_region;
	int			num_regions;
{
	int		i;
	long		npages;
	vm_offset_t	addr;
	vm_size_t	s;
	mem_region_t	rp;

	/*
	 *	Allocate memory for the pv_head_table and its lock bits.
	 *	Since the addressing of pv_head_table and pv_lock_table
	 *	matches that of vm_page_array the number of pages of
	 *	physical memory is computed from mem_region.
	 */
	for (npages = 0, i = 0; i < num_regions; i++) {
		rp = &mem_region[i];
		npages += rp->num_pages;
	}
	s = (vm_size_t) (sizeof(struct pv_entry) * npages);	/* plan 687 (D024, D160) */
	s = round_page(s);
	kmem_alloc_wired(kernel_map, &addr, s);	/* plan 687 (D024, D160) */
	bzero(addr, s);

	/*
	 *	Create the zone of physical maps and
	 *	physical-to-virtual entries.
	 */
	s = (vm_size_t) sizeof(struct pmap);
	pmap_zone = zinit(s, 400*s, 0, FALSE, "pmap"); /* XXX */
	s = (vm_size_t) sizeof(struct pv_entry);
	pv_list_zone = zinit(s, 100000*s, 0, FALSE, "pv_list"); /* XXX */
	pv_head_table = (pv_entry_t) addr;
	/* plan 687 (D024, D160): no pv_lock_table */
	managed_page_count = npages;
}

/*
 *	Create and return a physical map.
 *
 *	If the size specified for the map is zero, the map is an actual 
 *	physical map, and may be referenced by the hardware.
 *
 *	If the size specified is non-zero, the map will be used in software
 *	only, and is bounded by that size.
 */
pmap_t pmap_create(size)
	vm_size_t	size;
{
	pmap_t			pmap;
	pmap_statistics_t	stats;
	int			pt1limit, pt1size;

	/*
	 *	A software use-only map doesn't even need a map.
	 */
	if (size != 0)
		return(PMAP_NULL);

	/*
	 *	Allocate a pmap structure from the pmap_zone.
	 *	Setup a minimal level 1 page table.
	 */
	pmap = (pmap_t) zalloc(pmap_zone);
	ASSERT(pmap != PMAP_NULL);
	bzero(pmap, sizeof *pmap);
	pmap->ref_count = 1;
	simple_lock_init(&pmap->lock);
	pmap->rp.rp_desc_type = DT_SHORT;	/* ignored by 68040 */
	pmap->rp.rp_limit = m68k_pt1_entries - 1;
	pmap->pt1 = (pt1_t*) pt_alloc(pt_zone);
	pmap->rp.rp_ptbr = phys_to_l1ptr(pmap->pt1);
	return(pmap);
}

/*
 *	Retire the given physical map from service.  Should
 *	only be called if the map contains no valid mappings.
 */
void pmap_destroy(pmap)
	pmap_t	pmap;
{
	int			c;
	unsigned		s;

	if (pmap == PMAP_NULL)
		return;

	LOCK_PMAP(pmap,s);
	c = --pmap->ref_count;
	UNLOCK_PMAP(pmap,s);

	if (c != 0)
		return;

	ASSERT(pmap->stats.resident_count == 0);

	/*
	 *	Free the memory maps, then the pmap structure.
	 */
	pmap_free_maps(pmap, pmap->pt1);
	zfree(pmap_zone, pmap);
}

/*
 *	Free all memory maps associated with a pmap.
 */
pmap_free_maps(pmap, pt1_base)
	pmap_t	pmap;
	pt1_t	*pt1_base;
{
	pt1_t	*pt1;
	pt2_t	*pt2, *pt2_base;
	pte_t	*pte;
	int	l1;

	for (l1 = 0; l1 < m68k_pt1_entries; l1++) {
		pt1 = PT1(pt1_base, l1);
		if (pt1->pt1_desctype != m68k_pt1_desctype)
			continue;
		pt2_base = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr);
		for (pt2 = pt2_base; pt2 < pt2_base + m68k_pt2_entries; pt2++) {
			if (pt2->pt2_desctype != m68k_pt2_desctype)
				continue;
			pt_free(pte_zone, (pte_t*) l3ptr_to_phys(pt2->pt2_l3ptr));
		}
		pt_free(pt_zone, pt2_base);
	}
	pt_free(pt_zone, pt1_base);
}

/*
 *	Add a reference to the specified pmap.
 */
void pmap_reference(pmap)
	pmap_t	pmap;
{
	unsigned	s;

	if (pmap != PMAP_NULL) {
		LOCK_PMAP(pmap,s);
		pmap->ref_count++;
		UNLOCK_PMAP(pmap,s);
	}
}

/*
 *	Remove a range of page-table entries.  The given
 *	addresses are the first (inclusive) and last (exclusive)
 *	addresses for the VM pages.
 *
 *	The pmap must be locked.
 */
void pmap_remove_range(pmap, s, e)
	pmap_t		pmap;
	vm_offset_t	s, e;
{
	pt1_t		*pt1;
	pte_t		*spte, *epte, *cpte, *pg_pte;
	pv_entry_t	pv_h, prev, cur;
	vm_offset_t	pa, va, virt, pte_maps;
	int		pai;
	int		i;
	vm_offset_t	v;
	vm_page_t	m;

	va = s;

	/*
	 *	Assume we're going to remove at least one mapping, therefore
	 *	invalidate TLB now.
	 */
	TBIA(pmap);

	while (va < e) {

		/*
		 * Continue if there is no mapping to remove for this pte.
		 * Skip the VA space mapped by an upper level page table.
		 */
		spte = pmap_pte(pmap, va);
		if ((int) spte < PTE_ENTRY_NULL) {
			if ((int) spte == PT2_ENTRY_NULL) {
				va &= ~(m68k_pte_maps - 1);
				va += m68k_pte_maps;
			} else {	/* PT1_ENTRY_NULL */
				va &= ~(m68k_pt2_maps - 1);
				va += m68k_pt2_maps;
			}
			
			/* watch out for wraparound when e is near 2^32! */
			if (va == 0)
				break;
			continue;
		}

		/*
		 * Find the last (non-inclusive) upper level pte, making sure all
		 * of the inclusive ptes are in the same lower level group as the
		 * starting pte.
		 */
		epte = spte + m68k_btop(e - va);
		pg_pte = pmap_pte(pmap, roundup(va+1, m68k_pte_maps) - 1) + 1;
		if (pg_pte < epte)
			epte = pg_pte;

		/*
		 * Get the modify bits for the pager.
		 */
		for (cpte = spte; cpte < epte; cpte++) {
			if (cpte->pte_modify && (cpte->pte_desctype == DT_PTE)) {
				m = PHYS_TO_VM_PAGE(pfn_to_phys(PTE(cpte, pfn)));
				if (m)
					vm_page_set_modified(m);
			}
		}

		/*
		 *	Remove each pte from the PV list.
		 */
		for (cpte = spte; cpte < epte;
		     cpte += m68k_ptes_per_page, va += PAGE_SIZE) {

			/*
			 * Get the physical address, skipping this
			 * page if there is no physical mapping.
			 */
			pa = pfn_to_phys(PTE(cpte, pfn));
			if (cpte->pte_desctype != DT_PTE) {
				cpte->bits = 0;
				continue;
			}

			pai = pmap_phys_to_index(pa);
			if (pai == -1) {
				cpte->bits = 0;
				continue;
			}

			pmap->stats.resident_count--;
			ASSERT(pmap->stats.resident_count >= 0);
			if (PTE(cpte, wired))
				pmap->stats.wired_count--;

			LOCK_PVH(pai);
			pv_h = pai_to_pvh(pai);
			ASSERT(pv_h->pmap != PMAP_NULL);
			if (pv_h->va == va && pv_h->pmap == pmap) {

				/*
				 * Header is the pv_entry.  Copy the next one
				 * to header and free the next one (we can't
				 * free the header).
				 */
				cur = pv_h->next;
				if (cur != PV_ENTRY_NULL) {
					*pv_h = *cur;
					zfree(pv_list_zone, (vm_offset_t) cur);
				}
				else {
					pv_h->pmap = PMAP_NULL;
				}
			}
			else {
				prev = pv_h;
				while ((cur = prev->next) != PV_ENTRY_NULL) {
					if (cur->va == va && cur->pmap == pmap)
					break;
					prev = cur;
				}
				ASSERT(cur);
				prev->next = cur->next;
				zfree(pv_list_zone, (vm_offset_t)cur);
			}
			UNLOCK_PVH(pai);
			cpte->bits = 0;
		}

		/*
		 * Zero the individual ptes if we missed some above.
		 */
		if (m68k_ptes_per_page > 1)
			bzero((caddr_t) spte, (epte-spte) * m68k_pte_elemsize);
	}
	CHECK_PV;
}

/*
 *	Remove the given range of addresses from the specified map.
 *	It is assumed that start and end are rounded to the VM page size.
 */
void pmap_remove(pmap, start, end)
	pmap_t		pmap;
	vm_offset_t	start, end;
{
	unsigned	s;

	if (pmap == PMAP_NULL)
		return;

	READ_LOCK(s);
	LOCK_PMAP_U(pmap);

	/* translation buffer is cleared inside pmap_remove_range */
	pmap_remove_range(pmap, start, end);

	UNLOCK_PMAP_U(pmap);
	READ_UNLOCK(s);
}

/*
 *	Routine:	pmap_remove_all
 *	Function:
 *		Removes this physical page from
 *		all physical maps in which it resides.
 *		Reflects back modify bits to the pager.
 */
void pmap_remove_all(phys)
	vm_offset_t	phys;
{
	pv_entry_t	pv_h, cur;
	pte_t		*pte, *end_pte;
	vm_offset_t	va;
	pmap_t		pmap;
	vm_page_t	m;
	unsigned	s;
	int		pai;
	int		i;

	/*
	 *	Lock the pmap system first, since we will be changing
	 *	several pmaps.
	 */
	CHECK_PV;
	WRITE_LOCK(s);

	/*
	 *	Get the physical page structure since we may be using
	 *	it a lot.
	 */
	m = PHYS_TO_VM_PAGE(phys);

	/*
	 *	Walk down PV list, removing all mappings.
	 *	We have to do the same work as in pmap_remove_range
	 *	since that routine locks the pv_head.  We don't have
	 *	to lock the pv_head, since we have the entire pmap system.
	 */
	pai = pmap_phys_to_index(phys);
	if (pai != -1) {
	pv_h = pai_to_pvh(pai);

	while ((pmap = pv_h->pmap) != PMAP_NULL) {

		LOCK_PMAP_U(pmap);
		TBIA(pmap);	/* XXX */

		va = pv_h->va;
		pte = pmap_pte_valid(pmap, va);

		pmap->stats.resident_count--;
		ASSERT(pmap->stats.resident_count >= 0);
		if (PTE(pte, wired))
			pmap->stats.wired_count--;
		if ((cur = pv_h->next) != PV_ENTRY_NULL) {
			*pv_h = *cur;
			zfree(pv_list_zone, (vm_offset_t) cur);
		} else
			pv_h->pmap = PMAP_NULL;

		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++, va += m68k_page_size) {
			if (pte->pte_modify && pte->pte_desctype == DT_PTE && m)
				vm_page_set_modified(m);

			pte->bits = 0;
			pmap_collapse(pmap, va, pte);
		}

		UNLOCK_PMAP_U(pmap);
	}
	}

	WRITE_UNLOCK(s);
	CHECK_PV;
}

int pmap_coll = 1;

pmap_collapse(pmap, va, pte)
	pmap_t		pmap;
	vm_offset_t	va;
	pte_t		*pte;
{
	pt1_t		*pt1;
	pt2_t		*pt2, *spt2, *ept2, *cpt2;
	pte_t		*spte, *epte, *cpte;

	if (pmap == kernel_pmap || pmap_coll == 0)
		return;
	spte = pte - PTE_INDEX(va);
	epte = spte + m68k_pte_entries;
	for (cpte = spte; cpte < epte; cpte++) {
		if (cpte->pte_desctype == DT_PTE)
			return;
	}
	pt1 = PT1(pmap->pt1, PT1_INDEX(va));
	pt2 = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr) + PT2_INDEX(va);
	pt_free(pte_zone, (pte_t*) l3ptr_to_phys(pt2->pt2_l3ptr));
	pt2->pt2_desctype = DT_INVALID;
	spt2 = pt2 - PT2_INDEX(va);
	ept2 = spt2 + m68k_pt2_entries;
	for (cpt2 = spt2; cpt2 < ept2; cpt2++) {
		if (cpt2->pt2_desctype == m68k_pt2_desctype)
			return;
	}
	pt_free (pt_zone, spt2);
	pt1->pt1_desctype = DT_INVALID;
}

/*
 *	Routine:	pmap_copy_on_write
 *	Function:
 *		Remove write privileges from all
 *		physical maps for this physical page.
 */
void pmap_copy_on_write(phys)
	vm_offset_t	phys;
{
	pv_entry_t	pv_e;
	pmap_t		pmap;
	pte_t		*pte, *end_pte;
	unsigned 	s;
	int		pai;

	/*
	 *	Lock the entire pmap system, since we may be changing
	 *	several maps.
	 */
	CHECK_PV;
	WRITE_LOCK(s);

	/*
	 *	Run down the list of mappings to this physical page,
	 *	disabling write privileges on each one.
	 */
	pai = pmap_phys_to_index(phys);
	if (pai == -1)
		goto out;
	pv_e = pai_to_pvh(pai);

	if (pv_e->pmap == PMAP_NULL)
		goto out;

	do {
		/*
		 *	Lock this pmap and invalidate the TLB.
		 */
		pmap = pv_e->pmap;
		LOCK_PMAP_U(pmap);
		TBIA(pmap);

		/*
		 *	if there is a mapping, change the protections.
		 */
		pte = pmap_pte_valid(pmap, pv_e->va);
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++) {
			if (pte->pte_desctype == DT_PTE) {
				pte->pte_write_prot = TRUE;
			}
		}

		/*
		 *	Done with this one, so drop the lock,
		 *	and get next pv entry.
		 */
		UNLOCK_PMAP_U(pmap);
		pv_e = pv_e->next;
	} while (pv_e != PV_ENTRY_NULL);
out:
	WRITE_UNLOCK(s);
	CHECK_PV;
}

/*
 *	Set the physical protection on the
 *	specified range of this map as requested.
 */
void pmap_protect(pmap, start, end, prot)
	pmap_t		pmap;
	vm_offset_t	start, end;
	vm_prot_t	prot;
{
	pte_t		*pte, *end_pte;
	int 		vp, pte_maps;
	vm_offset_t	next_range;
	unsigned	s;

	CHECK_PV;
	if (pmap == PMAP_NULL)
		return;

	if (prot == VM_PROT_NONE) {
		pmap_remove(pmap, start, end);
		return;
	}

	vp = m68k_protection(pmap, prot);

	LOCK_PMAP(pmap,s);

	/* invalidate translation buffer */
	TBIA(pmap);

	while (start < end) {
		next_range = start & ~(m68k_pte_maps - 1);
		next_range += m68k_pte_maps;
		pte = pmap_pte(pmap, start);
		if ((int)pte > PTE_ENTRY_NULL) {
			if (end < next_range)
				end_pte = pte + m68k_btop(end - start);
			else
				end_pte = pmap_pte(pmap, next_range - 1) + 1;

			while (pte < end_pte) {
				pte->pte_write_prot = vp;
				pte++;
			}
		}
		start = next_range;
	}

	UNLOCK_PMAP(pmap,s);
	CHECK_PV;
}

/*
 *	Insert the given physical page (p) at
 *	the specified virtual address (v) in the
 *	target physical map with the protection requested.
 *
 *	If specified, the page will be wired down, meaning
 *	that the related pte can not be reclaimed.
 *
 *	NB:  This is the only routine which MAY NOT lazy-evaluate
 *	or lose information.  That is, this routine must actually
 *	insert this page into the given map NOW.
 */
void pmap_enter(pmap, v, p, prot, wired)
	pmap_t		pmap;
	vm_offset_t	v;
	vm_offset_t	p;
	vm_prot_t	prot;
	boolean_t	wired;
{
	void		pmap_enter_mapping();

	pmap_enter_mapping(pmap, v, p, prot, wired, TRUE, FALSE);	/* plan 687 (D024, D160) */
}

void pmap_enter_mapping(pmap, v, p, prot, wired, cacheable, serial)	/* plan 687 (D024, D160) */
	pmap_t		pmap;
	vm_offset_t	v;
	vm_offset_t	p;
	vm_prot_t	prot;
	boolean_t	wired;
{
	pte_t		*pte, *end_pte;
	pv_entry_t	pv_h;
	int 		vp, pai;
	pv_entry_t	pv_e;
	vm_offset_t	ptaddr;
	unsigned	s1, s2;
	pte_t		pte_template, *ppte = &pte_template;
	int		i, cache_inhibit = FALSE;
	vm_offset_t	pa;

#if	SET_CACHE
	{
		m68k_cache = cache? ((debug & 0x100)? ((debug >> 4) & 0xf) :
			CM_040_COPYBACK) : CM_040_INH_NONSERIAL;
		m68k_cache_k = cache? ((debug & 0x100)? (debug & 0xf) :
			CM_040_COPYBACK) : CM_040_INH_NONSERIAL;
		if (cpu_type == MC68030) {
			m68k_cache = cache? CM_030_CACHED : CM_030_CACHE_INH;
			m68k_cache_k = m68k_cache;
		}
	}
#endif	SET_CACHE

	if (pmap == PMAP_NULL)
		return;

	if (prot == VM_PROT_NONE) {
		pmap_remove(pmap, v, v + PAGE_SIZE);
		return;
	}

	/*
	 *  Assume that if this is device space (no region index)
	 *  the cache should be disabled.
	 */
	if (!cacheable || (managed_page_count && pmap_phys_to_index(p) == -1))
		cache_inhibit = TRUE;

	vp = m68k_protection(pmap, prot);

	/*
	 *	Must allocate a new pv_list entry while we're unlocked;
	 *	zalloc may cause pageout (which will lock the pmap system).
	 */
	pv_e = PV_ENTRY_NULL;
Retry:
	READ_LOCK(s1);
	LOCK_PMAP(pmap,s2);
	
	/*
	 *	Expand pmap to include this pte.  Assume that
	 *	pmap is always expanded to include enough
	 *	pages to map one VM page.
	 */
	while ((int)(pte = pmap_pte(pmap, v)) < PTE_ENTRY_NULL) {
		if (pmap == kernel_pmap) {
			pmap_expand_kernel(v, pte);
		} else {
			UNLOCK_PMAP_U(pmap);
			READ_UNLOCK(s1);
			pmap_expand(pmap, v, pte);
			READ_LOCK(s1);
			LOCK_PMAP_U(pmap);
		}
	}

	/*
	 *	Don't add anything in the pv_entry table if it's not setup.
	 *	This happens when mapping in kernel space at boot time.
	 */
	if (pv_head_table != PV_ENTRY_NULL) {

	/*
	 *	Enter the mapping in the PV list for this physical page.
	 *	If there is already a mapping, remove the old one first.
	 *	(If it's the same physical page, it's already in the PV list.)
	 */
	ptaddr = pfn_to_phys(PTE(pte, pfn));
	if (pte->pte_desctype != DT_PTE || ptaddr != p) {
		pmap_remove_range(pmap, v, (v + PAGE_SIZE));
		pai = pmap_phys_to_index(p);
		if (pai != -1) {
		LOCK_PVH(pai);
		pv_h = pai_to_pvh(pai);

		if (pv_h->pmap == PMAP_NULL) {

			/*
			 *	No mappings yet.
			 */
			pv_h->va = v;
			pv_h->pmap = pmap;
			pv_h->next = PV_ENTRY_NULL;
		} else {

			/*
			 *	Add new pv_entry after header.
			 */
			if (pv_e == PV_ENTRY_NULL) {
				UNLOCK_PVH(pai);
				UNLOCK_PMAP(pmap,s2);
				READ_UNLOCK(s1);
				pv_e = (pv_entry_t) zalloc(pv_list_zone);
				goto Retry;
			}

			pv_e->va = v;
			pv_e->pmap = pmap;
			pv_e->next = pv_h->next;
			pv_h->next = pv_e;

			/*
			 *	Remember that we used the pv_list entry.
			 */
			pv_e = PV_ENTRY_NULL;
		}
		UNLOCK_PVH(pai);

		ASSERT(pmap->stats.resident_count >= 0);
		pmap->stats.resident_count++;
		if (wired)
			pmap->stats.wired_count++;
		}
	}
	}

	pa = p;

	/*
	 *	Enter the mapping in each pte.
	 */
	if (pte->pte_desctype == DT_PTE) {

		/*
		 *	Replacing a valid mapping - preserve the
		 *	modify and referenced bits.  Could only be changing
		 *	cache mode, protection or wired bits here.
		 *	Invalidate the TLB, assuming it's the currently
		 *	active pmap.
		 */
		TBIA(pmap); /* necessary??? XXX */
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++) {
			pte->pte_write_prot = vp;
			PTE(pte, wired) = wired;
#if	SET_CACHE
			PTE(pte, cm) = cache_inhibit? m68k_cache_inhibit :
				(pmap == kernel_pmap? m68k_cache_k : m68k_cache);
#else	SET_CACHE
			PTE(pte, cm) = cache_inhibit? (serial? m68k_cache_inhibit_serial :	/* plan 687 (D024, D160) */
			m68k_cache_inhibit_nonserial) : m68k_cache;
#endif	SET_CACHE
		}
	} else {

		/*
		 *	Not a valid mapping - don't have to invalidate
		 *	the TLB.  Clear the modify and reference bits.
		 *	Use a template to speed up pte setting operation.
		 *	Depends on pfn field being in low bits of pte.
		 *	Zeroing sets modify, refer and others to false.
		 */
		ppte->bits = 0;
		ppte->pte_write_prot = vp;
		ppte->pte_desctype = DT_PTE;
		if (cpu_type != MC68030 && pmap == kernel_pmap)
			((struct pt3_040_entry*)ppte)->global = 1;
		PTE(ppte, wired) = wired;
#if	SET_CACHE
		PTE(ppte, cm) = cache_inhibit? m68k_cache_inhibit :
			(pmap == kernel_pmap? m68k_cache_k : m68k_cache);
#else	SET_CACHE
		PTE(ppte, cm) = cache_inhibit? (serial? m68k_cache_inhibit_serial :	/* plan 687 (D024, D160) */
			m68k_cache_inhibit_nonserial) : m68k_cache;
#endif	SET_CACHE
		PTE(ppte, pfn) = phys_to_pfn(pa);
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++) {
			*pte = *ppte;
			ppte->bits += m68k_page_size;
		}

	}

	UNLOCK_PMAP(pmap,s2);
	READ_UNLOCK(s1);

	if (pv_e != PV_ENTRY_NULL)
		zfree(pv_list_zone, (vm_offset_t) pv_e);
	CHECK_PV;
}

/*
 *	Routine:	pmap_change_wiring
 *	Function:	Change the wiring attribute for a map/virtual-address
 *			pair.
 *	In/out conditions:
 *			The mapping must already exist in the pmap.
 */
void pmap_change_wiring(pmap, v, wired)
	pmap_t		pmap;
	vm_offset_t	v;
	boolean_t	wired;
{
	pte_t		*pte, *end_pte;
	unsigned	s;

	CHECK_PV;
	LOCK_PMAP(pmap,s);

	pte = pmap_pte_valid(pmap, v);

	TBIA(pmap);
	if (pte->pte_desctype == DT_PTE) {
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++)
			PTE(pte, wired) = wired;
	}

	UNLOCK_PMAP(pmap,s);
	CHECK_PV;
}

/*
 *	Routine:	pmap_extract
 *	Function:
 *		Extract the physical page address associated with the given
 *		map/virtual_address pair.  The address includes the offset
 *		within a page.  This routine may not be called by device
 *		drivers at interrupt level -- use pmap_resident_extract.
 */
vm_offset_t pmap_extract(pmap, va)
	pmap_t		pmap;
	vm_offset_t	va;
{
	pte_t		*pte;
	vm_offset_t	pa;
	int		enable, lbase, lmask;
	unsigned	s;

	LOCK_PMAP(pmap,s);
	if ((int)(pte = pmap_pte(pmap, va)) < PTE_ENTRY_NULL ||	/* plan 687 (D024, D160) */
	    pte->pte_desctype != DT_PTE) {

		/* check for kernel transparent translation */
		if (cpu_type != MC68030) {
			enable = m68k_kernel_mmu_040_tt.tt_e;
			lbase = m68k_kernel_mmu_040_tt.tt_lbase;
			lmask = m68k_kernel_mmu_040_tt.tt_lmask;
		} else {
			enable = m68k_kernel_mmu_030_tt.tt_e;
			lbase = m68k_kernel_mmu_030_tt.tt_lbase;
			lmask = m68k_kernel_mmu_030_tt.tt_lmask;
		}
		if (pmap == kernel_pmap && enable && ((va >> 24)  & ~lmask) == lbase)
			pa = va;
		else
			pa = 0;
	} else
		pa = pfn_to_phys(PTE(pte, pfn)) + VA_INDEX(va);
	UNLOCK_PMAP(pmap,s);

	return(pa);
}

/*
 *	Routine:	pmap_resident_extract
 *	Function:
 *		Extract the physical page address associated with the given
 *		virtual address in the kernel pmap.  The address includes
 *		the offset within a page.  This routine does not lock the
 *		pmap; it is intended to be called only by device drivers
 *		or copyin/copyout routines that know the buffer whose address
 *		is being translated is memory-resident.
 */
vm_offset_t pmap_resident_extract(pmap, va)
	pmap_t		pmap;
	vm_offset_t	va;
{
	pte_t	*pte;
	int	enable, lbase, lmask;

	if ((int)(pte = pmap_pte(pmap, va)) < PTE_ENTRY_NULL ||	/* plan 687 (D024, D160) */
	    pte->pte_desctype != DT_PTE) {

		/* check for kernel transparent translation */
		if (cpu_type != MC68030) {
			enable = m68k_kernel_mmu_040_tt.tt_e;
			lbase = m68k_kernel_mmu_040_tt.tt_lbase;
			lmask = m68k_kernel_mmu_040_tt.tt_lmask;
		} else {
			enable = m68k_kernel_mmu_030_tt.tt_e;
			lbase = m68k_kernel_mmu_030_tt.tt_lbase;
			lmask = m68k_kernel_mmu_030_tt.tt_lmask;
		}
		if (pmap == kernel_pmap && enable && ((va >> 24)  & ~lmask) == lbase)
			return(va);	/* va is the pa */
		return(0);
	} else
		return(pfn_to_phys(PTE(pte, pfn)) + VA_INDEX(va));
}

/*
 *	Routine:	pmap_expand_kernel
 *
 *	Expands the kernel map to be able to map the specified virtual
 *	address.
 */
pmap_expand_kernel(va, reason)
	vm_offset_t	va;
{
	pt1_t 	*pt1;
	pt2_t	*pt2;
	pte_t	*pte;
	pmap_t	pmap = kernel_pmap;

	/*
	 *	Kernel level two maps are allocated from a fixed area of
	 *	kernel memory.  Once a level two map has been allocated
	 *	the level one entry is never changed.  Allocates a full
	 *	level 2 map.
	 */
	CHECK_PV;
	pt1 = PT1(pmap->pt1, PT1_INDEX(va));
	if (reason == PT1_ENTRY_NULL) {
		avail_kernel_map = roundup(avail_kernel_map, l2ptr_to_phys(1));
		pt2 = (pt2_t*) avail_kernel_map;
		bzero (pt2, m68k_pt2_size);
		avail_kernel_map += m68k_pt2_size;
		pt1->pt1_040.l2ptr = phys_to_l2ptr(pt2);
		pt1->pt1_write_prot = FALSE;
		pt1->pt1_refer = TRUE;
		pt1->pt1_desctype = m68k_pt1_desctype;
	} else
		pt2 = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr);

	/*
	 *	Enter the physical address of the new page table in the
	 *	level two page table entry.
	 *	The reference bit is set here to get a performance
	 *	gain.  The MMU does not have to redo the translation when it
	 *	modifies or refers to the new page tables.
	 */
	avail_kernel_map = roundup(avail_kernel_map, l3ptr_to_phys(1));
	pte = (pte_t*) avail_kernel_map;
	avail_kernel_map += m68k_pte_size;
	if (avail_kernel_map > max_kernel_map)
		panic("No more room in kernel map");
	bzero (pte, m68k_pte_size);	/* plan 687 (D024, D160) */
	pt2 += PT2_INDEX(va);
	pt2->pt2_l3ptr = phys_to_l3ptr(pte);
	pt2->pt2_write_prot = FALSE;
	pt2->pt2_refer = TRUE;
	pt2->pt2_desctype = m68k_pt2_desctype;
	CHECK_PV;
}

/*
 *	Routine:	pmap_expand
 *
 *	Expands a pmap to be able to map the specified virtual address.
 *	Must be called with the pmap module and the pmap unlocked.
 *	This routine must expand the map to handle PAGE_SIZE bytes.
 */
pmap_expand(pmap, va, reason)
	pmap_t		pmap;
	vm_offset_t	va;
{
	pt1_t		*pt1;
	pt2_t		*pt2;
	pte_t		*pte;
	int		pt1_index = PT1_INDEX(va);
	int		pt2_index = PT2_INDEX(va);

	/*
	 *	Allocate space for the new level 2 and/or level 3 maps.
	 */
	CHECK_PV;
	if (reason == PT1_ENTRY_NULL)
		pt2 = (pt2_t*) pt_alloc(pt_zone);
	pte = (pte_t*) pt_alloc(pte_zone);

	/*
	 *	If map expanded during above allocation just get out.
	 */
	LOCK_PMAP_U(pmap);
	if ((int) pmap_pte(pmap, va) > PTE_ENTRY_NULL) {
		UNLOCK_PMAP_U(pmap);
		if (reason == PT1_ENTRY_NULL)
			pt_free(pt_zone, pt2);
		pt_free(pte_zone, pte);
		return;
	}
	pt1 = PT1(pmap->pt1, pt1_index);
	if (reason == PT1_ENTRY_NULL) {
		pt1->pt1_040.l2ptr = phys_to_l2ptr(pt2);
		pt1->pt1_write_prot = FALSE;
		pt1->pt1_refer = TRUE;
		pt1->pt1_desctype = m68k_pt1_desctype;
	} else {
		pt2 = (pt2_t*) l2ptr_to_phys(pt1->pt1_040.l2ptr);
	}
		
	pt2 += pt2_index;
	pt2->pt2_l3ptr = phys_to_l3ptr(pte);
	pt2->pt2_write_prot = FALSE;
	pt2->pt2_refer = TRUE;
	pt2->pt2_desctype = m68k_pt2_desctype;
	UNLOCK_PMAP_U(pmap);
	CHECK_PV;
}

/*
 *	Routine:	pmap_copy
 *	Function:
 *		Copy the range specified by src_addr/len
 *		from the source map to the range dst_addr/len
 *		in the destination map.
 *
 *	This routine is only advisory and need not do anything.
 */
void pmap_copy(dst_pmap, src_pmap, dst_addr, len, src_addr)
	pmap_t		dst_pmap;
	pmap_t		src_pmap;
	vm_offset_t	dst_addr;
	vm_size_t	len;
	vm_offset_t	src_addr;
{
#ifdef lint
	pmap_copy(dst_pmap, src_pmap, dst_addr, len, src_addr);
#endif lint
}

/*
 *	Require that all active physical maps contain no
 *	incorrect entries NOW.  [This update includes
 *	forcing updates of any address map caching.]
 *
 *	Generally used to insure that a thread about
 *	to run will see a semantically correct world.
 */
void pmap_update() {

	/* TBIA both kernel and user spaces */
	TBIA_K;
	TBIA_U;
}

/*
 *	Routine:	pmap_collect
 *	Function:
 *		Garbage collects the physical map system for
 *		pages which are no longer used.
 *		Success need not be guaranteed -- that is, there
 *		may well be pages which are not referenced, but
 *		others may be collected.
 *	Usage:
 *		Called by the pageout daemon when pages are scarce.
 *
 */
void pmap_collect(pmap)
	pmap_t 	pmap;
{
	pt1_t	*newpt1;
	int	pt1size, count;
	u_int	s;

	CHECK_PV;
	if (pmap == PMAP_NULL)
		return;

	if (pmap == kernel_pmap)
		return;

	LOCK_PMAP_U(pmap);
	ASSERT(pmap->stats.resident_count >= 0);
	count = pmap->stats.resident_count;
	UNLOCK_PMAP_U(pmap);

	/*
	 *	FIXME - XXX need to have a way to get rid
	 *	of page tables yet preserve resident count!
	 */
	if (count != 0)
		return;

	/*
	 *	In order to avoid chaos we must swap the level 1 map
	 *	for a new one while we have the pmap system locked, but we
	 *	can't allocate memory under the lock, so allocate
	 *	the new map here.
	 */
	pt1size = m68k_pt1_entries * m68k_pt1_elemsize;
	newpt1 = (pt1_t*) pt_alloc(pt_zone);
	if (newpt1 == 0)
		return;		/* not important to do this now */

	/*
	 *	Garbage collect map.
	 */
	CHECK_PV;
	READ_LOCK(s);
	LOCK_PMAP_U(pmap);
	TBIA_U;		/* just in case */
	pmap_remove_range(pmap, VM_MIN_ADDRESS, VM_MAX_ADDRESS);

	/*
	 *	Save the old map pages, then clear out
	 *	all the level 1 mappings.  Note that pt1 never
	 *	shrinks, so we are guaranteed to always have a level 1
	 *	page table there.
	 */
	CHECK_PV;
	bcopy(pmap->pt1, newpt1, pt1size);
	bzero(pmap->pt1, pt1size);
	UNLOCK_PMAP_U(pmap);
	READ_UNLOCK(s);

	/*
	 *	Free the memory maps.
	 */
	pmap_free_maps(pmap, newpt1);
	CHECK_PV;
}

/*
 *	Routine:	pmap_kernel
 *	Function:
 *		Returns the physical map handle for the kernel.
 */
pmap_t pmap_kernel()
{
	return(kernel_pmap);
}

/*
 *	Routine:	pmap_pageable
 *	Function:
 *		Make the specified pages (by pmap, offset)
 *		pageable (or not) as requested.
 *
 *		A page which is not pageable may not take
 *		a fault; therefore, its page table entry
 *		must remain valid for the duration.
 *
 *		This routine is merely advisory; pmap_enter
 *		will specify that these pages are to be wired
 *		down (or not) as appropriate.
 */
pmap_pageable(pmap, start, end, pageable)
	pmap_t		pmap;
	vm_offset_t	start;
	vm_offset_t	end;
	boolean_t	pageable;
{
}

/* plan 687 (D024, D160): BEGIN the 1997 pmap_attribute (original 0x4098c1e) */
kern_return_t pmap_attribute(pmap, address, size, attribute, value)
	pmap_t				pmap;
	vm_offset_t			address;
	vm_size_t			size;
	vm_machine_attribute_t		attribute;
	vm_machine_attribute_val_t	*value;
{
	return (KERN_INVALID_ARGUMENT);
}
/* plan 687 (D024, D160): END */

/*
 *	Clear the modify bits on the specified physical page.
 */
void pmap_clear_modify(phys)
	vm_offset_t	phys;
{
	pv_entry_t	pv_h;
	pte_t		*pte, *end_pte;
	vm_offset_t	va;
	pmap_t		pmap;
	unsigned	s;
	int		pai;
	int		i;

	/*
	 *	Lock the pmap system first, since we will be changing
	 *	several pmaps.
	 */
	CHECK_PV;
	WRITE_LOCK(s);

	/*
	 *	Walk down PV list, clearing modify bits.
	 *	We have to do the same work as in pmap_remove_range
	 *	since that routine locks the pv_head.  We don't have
	 *	to lock the pv_head, since we have the entire pmap system.
	 */
	pai = pmap_phys_to_index(phys);
	if (pai == -1)
		goto out;
	pv_h = pai_to_pvh(pai);

	while ((pmap = pv_h->pmap) != PMAP_NULL) {

		LOCK_PMAP_U(pmap);

		va = pv_h->va;
		pte = pmap_pte_valid(pmap, va);
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++) {
			pte->pte_modify = 0;
		}

		UNLOCK_PMAP_U(pmap);

		pv_h = pv_h->next;
		if (pv_h == PV_ENTRY_NULL)
			break;
	}
out:
	WRITE_UNLOCK(s);
	CHECK_PV;
}

/*
 *	pmap_clear_reference:
 *
 *	Clear the reference bit on the specified physical page.
 */
void pmap_clear_reference(phys)
	vm_offset_t	phys;
{
	pv_entry_t	pv_h;
	pte_t		*pte, *end_pte;
	vm_offset_t	va;
	pmap_t		pmap;
	unsigned	s;
	int		pai;
	int		i;

	/*
	 *	Lock the pmap system first, since we will be changing
	 *	several pmaps.
	 */
	CHECK_PV;
	WRITE_LOCK(s);

	/*
	 *	Walk down PV list, clearing reference bits.
	 *	We have to do the same work as in pmap_remove_range
	 *	since that routine locks the pv_head.  We don't have
	 *	to lock the pv_head, since we have the entire pmap system.
	 */

	pai = pmap_phys_to_index(phys);
	if (pai == -1)
		goto out;
	pv_h = pai_to_pvh(pai);

	while ((pmap = pv_h->pmap) != PMAP_NULL) {

		LOCK_PMAP_U(pmap);

		va = pv_h->va;
		pte = pmap_pte_valid(pmap, va);
		end_pte = pte + m68k_ptes_per_page;
		for (; pte < end_pte; pte++) {
			pte->pte_refer = 0;
		}

		UNLOCK_PMAP_U(pmap);
		pv_h = pv_h->next;
		if (pv_h == PV_ENTRY_NULL)
			break;
	}
out:
	WRITE_UNLOCK(s);
	CHECK_PV;
}

/*
 *	pmap_is_referenced:
 *
 *	Return whether or not the specified physical page is referenced
 *	by any physical maps.
 */
boolean_t pmap_is_referenced(phys)
	vm_offset_t	phys;
{

	pv_entry_t	pv_h;
	pte_t		*pte, *end_pte;
	vm_offset_t	va;
	pmap_t		pmap;
	unsigned	s;
	int		pai;
	int		i;
	int		is_referenced = FALSE;

	/*
	 *	Lock the pmap system first, since we will be changing
	 *	several pmaps.
	 */
	CHECK_PV;
	READ_LOCK(s);

	/*
	 *	Walk down PV list, checking for references.
	 *	We have to do the same work as in pmap_remove_range
	 *	since that routine locks the pv_head.  We don't have
	 *	to lock the pv_head, since we have the entire pmap system.
	 */
	pai = pmap_phys_to_index(phys);
	if (pai == -1)
		goto out;
	pv_h = pai_to_pvh(pai);

	while (is_referenced == FALSE && (pmap = pv_h->pmap) != PMAP_NULL) {

		LOCK_PMAP_U(pmap);

		va = pv_h->va;
		pte = pmap_pte_valid(pmap, va);

		end_pte = pte + m68k_ptes_per_page;
		for (; is_referenced == FALSE && pte < end_pte; pte++) {
			if (pte->pte_refer)
				is_referenced = TRUE;
		}

		UNLOCK_PMAP_U(pmap);

		pv_h = pv_h->next;
		if (pv_h == PV_ENTRY_NULL)
			break;
	}
out:
	READ_UNLOCK(s);
	CHECK_PV;
	return(is_referenced);
}

/*
 *	pmap_is_modified:
 *
 *	Return whether or not the specified physical page is modified
 *	by any physical maps.
 */
boolean_t pmap_is_modified(phys)
	vm_offset_t	phys;
{
	pv_entry_t	pv_h;
	pte_t		*pte, *end_pte;
	vm_offset_t	va;
	pmap_t		pmap;
	unsigned	s;
	int		pai;
	int		i;
	int		is_modified = FALSE;

	/*
	 *	Lock the pmap system first, since we will be changing
	 *	several pmaps.
	 */
	CHECK_PV;
	READ_LOCK(s);

	/*
	 *	Walk down PV list, checking for modify bits.
	 *	We have to do the same work as in pmap_remove_range
	 *	since that routine locks the pv_head.  We don't have
	 *	to lock the pv_head, since we have the entire pmap system.
	 */
	pai = pmap_phys_to_index(phys);
	if (pai == -1)
		goto out;
	pv_h = pai_to_pvh(pai);

	while ((is_modified == FALSE) && ((pmap = pv_h->pmap) != PMAP_NULL)) {

		LOCK_PMAP_U(pmap);

		va = pv_h->va;
		pte = pmap_pte_valid(pmap, va);

		end_pte = pte + m68k_ptes_per_page;
		for (; is_modified == FALSE && pte < end_pte; pte++) {
			if (pte->pte_modify)
				is_modified = TRUE;
		}

		UNLOCK_PMAP_U(pmap);

		pv_h = pv_h->next;
		if (pv_h == PV_ENTRY_NULL)
			break;
	}
out:
	READ_UNLOCK(s);
	CHECK_PV;
	return(is_modified);
}

/*
 *	pmap_phys_to_index:
 *
 *	Given a physical address, determine the linear page index by looking for
 *	inclusion in a particular physical memory region.  This is used for indexing
 *	into the pv list.  It is possible that no index will be found if the
 *	physical address is within non-managed kernel memory or device space.
 */
pmap_phys_to_index(pa)
	vm_offset_t	pa;
{
	int		i, skip_vm_pages = 0, index;
	mem_region_t	rp;

	for (i = 0; i < num_regions; i++) {
		rp = &mem_region[i];
		if (pa >= rp->first_phys_addr && pa < rp->last_phys_addr)
			break;
		skip_vm_pages += rp->num_pages;
	}
	if (i == num_regions)
		return (-1);
	index = atop(pa) - rp->first_page + skip_vm_pages;
	if (index >= managed_page_count)
		return (-1);
	return(index);
}

/*
 *	pmap_page_protect:
 *
 *	Lower the permission for all mappings to a given page.
 */
void	pmap_page_protect(phys, prot)
	vm_offset_t	phys;
	vm_prot_t	prot;
{
	switch (prot) {
		case VM_PROT_READ:
		case VM_PROT_READ|VM_PROT_EXECUTE:
			pmap_copy_on_write(phys);
			break;
		case VM_PROT_ALL:
			break;
		default:
			pmap_remove_all(phys);
			break;
	}
}

#ifdef	notdef
/* mem-to-mem copy hardware is currently broken */
int	mmcopy = 0;

void pmap_copy_page(src, dst)
	vm_offset_t	src;
	vm_offset_t	dst;
{
	if (mmcopy == 0)
		bcopy(src, dst, PAGE_SIZE);
	else
		pcopy(src, dst, PAGE_SIZE);
}

void pmap_zero_page(phys)
	vm_offset_t	phys;
{
	if (mmcopy == 0)
		bzero(phys, PAGE_SIZE);
	else
		pfill(0, phys, PAGE_SIZE);
}

copy_from_phys(phys, virt, size)
	vm_offset_t	phys;
	vm_offset_t	virt;
	vm_size_t	size;
{
	vm_offset_t	newphys;

	if (((virt & 0xf) == 0) && ((phys & 0xf) == 0)
	    && ((size & 0xf) == 0) && mmcopy) {
	    	newphys = pmap_resident_extract(kernel_pmap, virt);
		pcopy(phys, newphys, size);
	}
	else
		bcopy(phys, virt, size);
}

copy_to_phys(virt, phys, size)
	vm_offset_t	virt;
	vm_offset_t	phys;
	vm_size_t	size;
{
	vm_offset_t	newphys;

	if (((virt & 0xf) == 0) && ((phys & 0xf) == 0)
	    && ((size & 0xf) == 0) && mmcopy) {
	    	newphys = pmap_resident_extract(kernel_pmap, virt);
		pcopy(newphys, phys, size);
	}
	else
		bcopy(virt, phys, size);
}
#else	notdef
void pmap_copy_page(src, dst)
	vm_offset_t	src;
	vm_offset_t	dst;
{
	bcopy(src, dst, PAGE_SIZE);
}

void pmap_zero_page(phys)
	vm_offset_t	phys;
{
	bzero(phys, PAGE_SIZE);
}

copy_from_phys(phys, virt, size)
	vm_offset_t	phys;
	vm_offset_t	virt;
	vm_size_t	size;
{
	bcopy(phys, virt, size);
}

copy_to_phys(virt, phys, size)
	vm_offset_t	virt;
	vm_offset_t	phys;
	vm_size_t	size;
{
	bcopy(virt, phys, size);
}

/* plan 687 (D024, D160): BEGIN the 1997 compressed paging helpers (original 0x4098f64,
   0x4098f7e); the arguments go on unchanged */
int compress_data_from_phys(src, size, dst)
	vm_offset_t	src;
	vm_size_t	size;
	vm_offset_t	dst;
{
	return (compress_data(src, size, dst));
}

int uncompress_data_to_phys(src, srcsize, dst, dstsize, index)
	vm_offset_t	src;
	vm_size_t	srcsize;
	vm_offset_t	dst;
	vm_size_t	dstsize;
	int		index;
{
	return (uncompress_data(src, srcsize, dst, dstsize, index));
}
/* plan 687 (D024, D160): END */
#endif	notdef

/*
 * Setup transparent translation per thread by using TT register #1.
 * This register is timeshared among multiple threads (kernel and user)
 * by code in load_context() which reloads it from pcb->mmu_tt1.
 */
void pmap_tt (th, enable, start, size, cacheable)
	thread_t th;
{
	struct pcb	*pcb = th->pcb;
	
	if (!cache)	/* plan 687 (D024, D160) */
		cacheable = FALSE;
	/* setup MMU tt1 register */
	bzero (&pcb->mmu_tt1, sizeof pcb->mmu_tt1);
	if (cpu_type != MC68030) {
		pcb->mmu_tt1.tt1_040.tt_lbase = start >> 24;
		pcb->mmu_tt1.tt1_040.tt_lmask = (size - 1) >> 24;
		pcb->mmu_tt1.tt1_040.tt_e = enable;
#if	SET_CACHE
		pcb->mmu_tt1.tt1_040.tt_cm = cacheable? ((debug & 0x100)?
			((debug >> 4) & 0xf) : TT_040_CM_COPYBACK) :
			TT_040_CM_INH_SERIAL;
#else	SET_CACHE
		pcb->mmu_tt1.tt1_040.tt_cm =
			cacheable? TT_040_CM_COPYBACK : TT_040_CM_INH_SERIAL;
#endif	SET_CACHE
		if (th->task->kernel_privilege) {
			pcb->mmu_tt1.tt1_040.tt_super = TT_040_SUPER;
		} else {
			pcb->mmu_tt1.tt1_040.tt_super = TT_040_SUPER_USER;
		}
	} else {
		pcb->mmu_tt1.tt1_030.tt_lbase = start >> 24;
		pcb->mmu_tt1.tt1_030.tt_lmask = (size - 1) >> 24;
		pcb->mmu_tt1.tt1_030.tt_e = enable;
		pcb->mmu_tt1.tt1_030.tt_ci = cacheable ? 0 : 1;
		pcb->mmu_tt1.tt1_030.tt_rwmask = 1;
		if (th->task->kernel_privilege) {
			pcb->mmu_tt1.tt1_030.tt_fcbase = ~(FC_SUPERI ^ FC_SUPERD);
			pcb->mmu_tt1.tt1_030.tt_fcmask = FC_SUPERI ^ FC_SUPERD;
		} else {
			pcb->mmu_tt1.tt1_030.tt_fcbase = 0x00;	/* super & user mode */
			pcb->mmu_tt1.tt1_030.tt_fcmask = 0xff;
		}
	}
	pmove_tt1 (&pcb->mmu_tt1);	/* load it now */
	if (enable)
		pcb->pcb_flags |= PCB_TT1;	/* load it every ctx switch */
	else
		pcb->pcb_flags &= ~PCB_TT1;
}

