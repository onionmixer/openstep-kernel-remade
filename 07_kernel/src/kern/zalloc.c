/*
 * Mach Operating System
 * Copyright (c) 1993-1987 Carnegie Mellon University.
 * Copyright (c) 1993,1994 The University of Utah and
 * the Computer Systems Laboratory (CSL).
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON, THE UNIVERSITY OF UTAH AND CSL ALLOW FREE USE OF
 * THIS SOFTWARE IN ITS "AS IS" CONDITION, AND DISCLAIM ANY LIABILITY
 * OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF
 * THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 *	File:	kern/zalloc.c
 *	Author:	Avadis Tevanian, Jr.
 *
 *	Zone-based memory allocator.  A zone is a collection of fixed size
 *	data blocks for which quick allocation/deallocation is possible.
 */
/*
 * plan 350 (D044): Mach4 kernel/kern/zalloc.c is the base text.  The
 * OPENSTEP 4.2 zone allocator takes zone memory from free-space pools
 * (zone_free_space_*) instead of the Mach4 zone page table, and keeps
 * each zone free list sorted by address.  Every line marked "plan 350"
 * was changed or authored from the original kernel bytes (D024); the
 * structure of the authored parts follows Darwin 0.1 kernel/kern/zalloc.c.
 */

#include <kern/macro_help.h>
#include <kern/sched.h>
#include <kern/time_out.h>
#include <kern/zalloc.h>
#include <mach/vm_param.h>
#include <vm/vm_kern.h>
#include <machine/machspl.h>

#include <mach_debug.h>
#include <mach_old_vm_copy.h>	/* plan 350 */
#if	MACH_DEBUG
#include <mach/kern_return.h>
#include <mach/machine/vm_types.h>
#include <mach_debug/zone_info.h>
#include <kern/host.h>
#include <vm/vm_map.h>
#include <vm/vm_user.h>
#include <vm/vm_kern.h>
#endif

/*
 * plan 350 (authored): the free list is kept in ascending address
 * order; last_insert remembers the last element put back so that a
 * run of frees in increasing order does not rescan the list.
 */
#define ADD_TO_ZONE(zone, element)					\
MACRO_BEGIN								\
	vm_offset_t	cur, *last;					\
		if (		(zone)->last_insert != 0 	&&	\
				(element) > (zone)->last_insert	)	\
			(vm_offset_t)last = (zone)->last_insert;	\
		else							\
			last = &(zone)->free_elements;			\
		while (		(cur = *last) != 0	&&		\
				(element) > cur		)		\
			(vm_offset_t)last = cur;			\
		*(vm_offset_t *)(element) = cur;			\
		*last = (element);					\
		(zone)->last_insert = (element);			\
		(zone)->count--;					\
MACRO_END

#define REMOVE_FROM_ZONE(zone, ret, type)				\
MACRO_BEGIN								\
	(ret) = (type) (zone)->free_elements;				\
	if ((ret) != (type) 0) {					\
		(zone)->count++;	/* plan 350 */			\
		(zone)->free_elements = *((vm_offset_t *)(ret));	\
		if ((zone)->last_insert == (vm_offset_t)(ret))	/* plan 350 */	\
			(zone)->last_insert = 0;	/* plan 350 */	\
	}								\
MACRO_END

/* plan 350: no zone page table (Mach4 garbage collection support removed) */

zone_t		zone_zone;	/* this is the zone containing other zones */

boolean_t	zone_ignore_overflow = TRUE;

vm_map_t	zone_map = VM_MAP_NULL;
vm_size_t	zone_map_size = 12 * 1024 * 1024;
vm_offset_t	zone_min, zone_max;	/* plan 350: bounds of zone_map */

/*
 *	The VM system gives us an initial chunk of memory.
 *	It has to be big enough to allocate the zone_zone
 *	and some initial kernel data structures, like kernel maps.
 *	It is advantageous to make it bigger than really necessary,
 *	because this memory is more efficient than normal kernel
 *	virtual memory.  (It doesn't have vm_page structures backing it
 *	and it may have other machine-dependent advantages.)
 *	So for best performance, zdata_size should approximate
 *	the amount of memory you expect the zone system to consume.
 */

vm_offset_t	zdata;
vm_size_t	zdata_size = 420 * 1024;

/*
 * plan 350: a pageable zone uses its complex lock; any other zone takes
 * its simple lock at splhigh and keeps the old level in lock_ipl.
 */
#define zone_lock(zone)					\
MACRO_BEGIN						\
	if ((zone)->pageable) {				\
		lock_write(&(zone)->complex_lock);	\
	} else {					\
		spl_t s = splhigh();			\
		simple_lock(&(zone)->lock);		\
		(zone)->lock_ipl = s;			\
	}						\
MACRO_END

#define zone_unlock(zone)				\
MACRO_BEGIN						\
	if ((zone)->pageable) {				\
		lock_done(&(zone)->complex_lock);	\
	} else {					\
		spl_t s = (zone)->lock_ipl;		\
		simple_unlock(&(zone)->lock);		\
		splx(s);				\
	}						\
MACRO_END

#define zone_lock_init(zone)				\
MACRO_BEGIN						\
	if ((zone)->pageable) {				\
		lock_init(&(zone)->complex_lock, TRUE);	\
	} else {					\
		simple_lock_init(&(zone)->lock);	\
	}						\
MACRO_END

vm_offset_t zget_space(	/* plan 350: global, takes a pool and canblock */
	struct zone_free_space	*free_space,
	vm_size_t		size,
	boolean_t		canblock);

decl_simple_lock_data(,zget_space_lock)

/*
 * plan 350 (authored): free-space pools.
 *
 * A free region starts with a zone_free_space_entry.  Entries are
 * doubly linked in ascending address order; pred points at the link
 * that points at the entry.
 */
struct zone_free_space_entry {
	struct zone_free_space_entry	*next;
	vm_size_t			length;
	struct zone_free_space_entry	**pred;
	int				_pad[1];
};
#define ZONE_MIN_ALLOC		16	/* a power of two, and no smaller
					   than a zone_free_space_entry */

/*
 * One hint per size class: the lowest addressed entry of that size.
 * The last hint holds the lowest addressed entry of at least alloc_max.
 */
struct zone_free_space_hint {
	struct zone_free_space_entry	*entry;
	int				_pad[3];
};

/*
 * A pool: requests are rounded to alloc_unit (a power of two) and
 * should not exceed alloc_max; hash_shift is log2(alloc_unit) and
 * num_hints is alloc_max >> hash_shift.
 */
struct zone_free_space {
	vm_size_t			alloc_unit;
	vm_size_t			alloc_max;
	struct zone_free_space_entry	*entries;
	integer_t			num_entries;
	integer_t			hash_shift;
	struct zone_free_space_hint	*hints;
	integer_t			num_hints;
};

struct zone_free_space		*zone_free_space[8];
integer_t			zone_free_space_count;

/*
 * Pool 0 is the default pool: static, one hint, never reclaimed.  It
 * serves zones that are not collectable and bootstrap allocations.
 */
struct zone_free_space_hint	_zone_default_space_hint;
struct zone_free_space		_zone_default_space;
#define	zone_default_space	(&_zone_default_space)

static void zone_free_space_select(zone_t	zone);

#define zone_collectable(z)	((z)->free_space != 0 && \
					(z)->free_space != zone_default_space)

/*
 * Size class of a request; anything past the last class goes to it.
 */
static __inline__
integer_t
zone_free_space_hash(
	struct zone_free_space		*freespace,
	vm_size_t			size
)
{
	integer_t		hash;

	if ((hash = size >> freespace->hash_shift) >
					freespace->num_hints)
		return (freespace->num_hints);
	else
		return (hash);
}
#define	zone_free_space_hint_from_hash(freespace, hash)	\
					((freespace)->hints + (hash) - 1)

static __inline__
struct zone_free_space_hint *
zone_free_space_hint(
	struct zone_free_space		*freespace,
	vm_size_t			size
)
{
	return zone_free_space_hint_from_hash(freespace,
					zone_free_space_hash(freespace, size));
}

/*
 * Make the entry the hint of its class if it is the lowest addressed.
 */
static __inline__
void
zone_free_space_hint_insert(
	struct zone_free_space		*freespace,
	struct zone_free_space_entry	*entry
)
{
	struct zone_free_space_hint	*hint;

	hint = zone_free_space_hint(freespace, entry->length);
	if (hint->entry == 0 || entry < hint->entry)
		hint->entry = entry;
}

/*
 * If the entry is the hint of its class, move the hint forward to the
 * next entry of the same class.
 */
static
void
zone_free_space_hint_delete(
	struct zone_free_space		*freespace,
	struct zone_free_space_entry	*entry
)
{
	integer_t			hash;
	struct zone_free_space_hint	*hint;

	hash = zone_free_space_hash(freespace, entry->length);
	hint = zone_free_space_hint_from_hash(freespace, hash);

	if (entry == hint->entry) {
		if (hash < freespace->num_hints) {
			struct zone_free_space_entry
					*cur, **last = &entry->next;

			while ((cur = *last) != 0 &&
					cur->length != entry->length)
				last = &cur->next;

			hint->entry = cur;
		}
		else {
			struct zone_free_space_entry
					*cur, **last = &entry->next;

			while ((cur = *last) != 0 &&
					cur->length < freespace->alloc_max)
				last = &cur->next;

			hint->entry = cur;
		}
	}
}

/*
 * The entry grew at its front: its header moved from old_entry, and
 * its length was old_length.
 */
static
void
zone_free_space_hint_prepend(
	struct zone_free_space		*freespace,
	struct zone_free_space_entry	*entry,
	vm_size_t			old_length,
	void				*old_entry
)
{
	integer_t			old_hash, new_hash;
	struct zone_free_space_hint	*hint;

	new_hash = zone_free_space_hash(freespace, entry->length);
	old_hash = zone_free_space_hash(freespace, old_length);
	hint = zone_free_space_hint_from_hash(freespace, old_hash);

	if (old_hash != new_hash) {
		if (old_entry == hint->entry) {
			if (old_hash < freespace->num_hints) {
				struct zone_free_space_entry
						*cur, **last = &entry->next;

				while ((cur = *last) != 0 &&
						cur->length != old_length)
					last = &cur->next;

				hint->entry = cur;
			}
			else {
				struct zone_free_space_entry
						*cur, **last = &entry->next;

				while ((cur = *last) != 0 &&
						cur->length < 
							freespace->alloc_max)
					last = &cur->next;

				hint->entry = cur;
			}
		}

		hint = zone_free_space_hint_from_hash(freespace, new_hash);
		if (hint->entry == 0 || entry < hint->entry)
			hint->entry = entry;
	}
	else if (old_entry == hint->entry)
		hint->entry = entry;
}

/*
 * The entry grew at its end; its length was old_length.
 */
static
void
zone_free_space_hint_append(
	struct zone_free_space		*freespace,
	struct zone_free_space_entry	*entry,
	vm_size_t			old_length
)
{
	integer_t			old_hash, new_hash;
	struct zone_free_space_hint	*hint;

	new_hash = zone_free_space_hash(freespace, entry->length);
	old_hash = zone_free_space_hash(freespace, old_length);

	if (old_hash != new_hash) {
		hint = zone_free_space_hint_from_hash(freespace, old_hash);
		if (entry == hint->entry) {
			if (old_hash < freespace->num_hints) {
				struct zone_free_space_entry
						*cur, **last = &entry->next;

				while ((cur = *last) != 0 &&
						cur->length != old_length)
					last = &cur->next;

				hint->entry = cur;
			}
			else {
				struct zone_free_space_entry
						*cur, **last = &entry->next;

				while ((cur = *last) != 0 &&
						cur->length < 
							freespace->alloc_max)
					last = &cur->next;

				hint->entry = cur;
			}
		}

		hint = zone_free_space_hint_from_hash(freespace, new_hash);
		if (hint->entry == 0 || entry < hint->entry)
			hint->entry = entry;
	}
}

/*
 * Find an entry of at least size bytes.  The entry leaves the hint
 * table (whose hint moves on) but stays on the free list.
 * (original 0x16a360)
 */
static
struct zone_free_space_entry *
zone_free_space_lookup(
	struct zone_free_space		*freespace,
	vm_size_t			size
)
{
	integer_t			hash;
	struct zone_free_space_hint	*hint;
	struct zone_free_space_entry	*entry;

	if ((entry = freespace->entries) == 0)
		return (entry);
	else if (entry->length >= size) {
		zone_free_space_hint_delete(freespace, entry);
		
		return (entry);
	}

	hash = zone_free_space_hash(freespace, size); 
	hint = zone_free_space_hint_from_hash(freespace, hash);

	/* exact size classes, from the request upwards */
	while (hash < freespace->num_hints) {
		if ((entry = hint->entry) != 0) {
			struct zone_free_space_entry
					*cur, **last = &entry->next;

			while ((cur = *last) != 0 &&
					cur->length != entry->length)
				last = &cur->next;

			hint->entry = cur;
			
			return (entry);
		}
		
		hash++; hint++;
	}

	/* the last class: its hint may still be too small */
	if ((entry = hint->entry) != 0) {
		struct zone_free_space_entry
				*cur, **last = &entry->next;

		if (entry->length < size) {
			while ((cur = *last) != 0 &&
					cur->length < size)
				last = &cur->next;
				
			return (cur);
		}

		while ((cur = *last) != 0 &&
				cur->length < freespace->alloc_max)
			last = &cur->next;

		hint->entry = cur;
	}
	
	return (entry);
}

/*
 *	Protects first_zone, last_zone, num_zones,
 *	and the next_zone field of zones.
 */
decl_simple_lock_data(,all_zones_lock)
zone_t			first_zone;
zone_t			*last_zone;
int			num_zones;

/*
 *	zinit initializes a new zone.  The zone data structures themselves
 *	are stored in a zone, which is initially a static structure that
 *	is initialized by zone_init.
 */
zone_t zinit(size, max, alloc, pageable, name)	/* plan 350: pageable */
	vm_size_t	size;		/* the size of an element */
	vm_size_t	max;		/* maximum memory to use */
	vm_size_t	alloc;		/* allocation size */
	boolean_t	pageable;	/* plan 350: is this zone pageable? */
	char		*name;		/* a name for the zone */
{
	register zone_t		z;

	if (zone_zone == ZONE_NULL)
		z = (zone_t) zget_space(zone_default_space,	/* plan 350 */
					sizeof(struct zone), FALSE);	/* plan 350 */
	else
		z = (zone_t) zalloc(zone_zone);
	if (z == ZONE_NULL)
		panic("zinit");

 	if (alloc == 0)
		alloc = PAGE_SIZE;

	if (size == 0)
		size = sizeof(z->free_elements);
	size = ((size + (ZONE_MIN_ALLOC - 1)) & ~(ZONE_MIN_ALLOC - 1));	/* plan 350 */
	/*
	 *	Round off all the parameters appropriately.
	 */

	if ((max = round_page(max)) < (alloc = round_page(alloc)))
		max = alloc;

	z->last_insert = z->free_elements = 0;	/* plan 350 */
	z->cur_size = 0;
	z->max_size = max;
	z->elem_size = size;	/* plan 350 */

	z->alloc_size = alloc;
	z->pageable = pageable;	/* plan 350 */
	z->zone_name = name;
	z->count = 0;	/* plan 350 */
	z->doing_alloc = FALSE;
	z->exhaustible = z->sleepable = FALSE;	/* plan 350 */
	z->expandable  = TRUE;	/* plan 350 */
	zone_lock_init(z);
	zone_free_space_select(z);	/* plan 350 */

	/*
	 *	Add the zone to the all-zones list.
	 */

	z->next_zone = ZONE_NULL;
	simple_lock(&all_zones_lock);
	*last_zone = z;
	last_zone = &z->next_zone;
	num_zones++;
	simple_unlock(&all_zones_lock);

	return(z);
}

/*
 *	Cram the given memory into the specified zone.
 */
void zcram(zone_t zone, vm_offset_t newmem, vm_size_t size)
{
	register vm_size_t	elem_size;

	if (newmem == (vm_offset_t) 0) {
		panic("zcram - memory at zero");
	}
	elem_size = zone->elem_size;

	zone_lock(zone);
	while (size >= elem_size) {
		ADD_TO_ZONE(zone, newmem);
		zone->count++;	/* compensate for ADD_TO_ZONE */	/* plan 350 */
		size -= elem_size;
		newmem += elem_size;
		zone->cur_size += elem_size;
	}
	zone_unlock(zone);
}

/*
 * plan 350 (authored): carve an element of size bytes from the front of
 * a new region [new_space, new_space + space_to_add) and put the rest
 * on the pool's free list, merging with an entry that ends at
 * new_space.  Returns the element.  (original 0x16a694)
 */
vm_offset_t zone_free_space_add(freespace, size, new_space, space_to_add)
	struct zone_free_space *freespace;
	vm_size_t size;
	vm_offset_t new_space;
	vm_size_t space_to_add;
{
	struct zone_free_space_entry	*cur, **last;

	if (freespace == 0)
		freespace = zone_default_space;

	last = &freespace->entries;
	while ((cur = *last) != 0 &&
			(vm_offset_t)cur < new_space &&
			((vm_offset_t)cur + cur->length) != new_space)
		last = &cur->next;
			
	if (cur == 0 || ((vm_offset_t)cur + cur->length) < new_space) {
		/* nothing to merge with: link the remainder as a new entry */
		if ((space_to_add - size) >= ZONE_MIN_ALLOC) {
			if (cur != 0)
				last = &cur->next;
			(vm_offset_t)cur = new_space + size;
			cur->length = space_to_add - size;
			if (cur->next = *last)
				cur->next->pred = &cur->next;
			cur->pred = last;
			*last = cur;
			freespace->num_entries++;

			zone_free_space_hint_insert(freespace, cur);
		}
	}
	else
	if (((vm_offset_t)cur + cur->length) == new_space) {
		struct zone_free_space_entry	*new;

		/* merge: the element comes from the front of cur */
		zone_free_space_hint_delete(freespace, cur);

		new_space = (vm_offset_t)cur;
		(vm_offset_t)new = (vm_offset_t)cur + size;
		new->length = cur->length + space_to_add - size;
		if (new->next = cur->next)
			new->next->pred = &new->next;
		new->pred = last;
		*last = new;

		zone_free_space_hint_insert(freespace, new);
	}
	
	return (new_space);
}

/*
 * plan 350 (authored): give the free elements of a collectable zone
 * back to its pool, merging with neighbouring entries.  The caller
 * holds zget_space_lock and the zone lock.  (original 0x16a7f4)
 */
void zone_collect(zone)
	struct zone	*zone;
{
	struct zone_free_space_entry	*cur, **last, *new;
	vm_offset_t			*free, *elem, next;
	vm_size_t			elem_size = zone->elem_size;
	struct zone_free_space		*freespace = zone->free_space;

	if (!zone_collectable(zone))
		return;

	last = &freespace->entries;

	free = &zone->free_elements;
	while (((vm_offset_t)elem = *free) != 0) {
		zone->cur_size -= elem_size;
		next = *elem;
		
		while ((cur = *last) != 0 &&
				((vm_offset_t)cur +
					cur->length) < (vm_offset_t)elem)
			last = &cur->next;

		if (cur == 0 || ((vm_offset_t)elem + elem_size) <
							(vm_offset_t)cur) {
			/* a new entry before cur (or at the end) */
			(vm_offset_t)new = (vm_offset_t)elem;
			new->length = elem_size;
			if (new->next = cur)
				cur->pred = &new->next;
			new->pred = last;
			*last = new;
			freespace->num_entries++;

			zone_free_space_hint_insert(freespace, new);
		}
		else
		if (((vm_offset_t)elem + elem_size) == (vm_offset_t)cur) {
			/* the element ends where cur starts */
			vm_size_t		old_length = cur->length;

			(vm_offset_t)new = (vm_offset_t)elem;
			new->length = cur->length + elem_size;
			if (new->next = cur->next)
				new->next->pred = &new->next;
			new->pred = last;
			*last = new;

			zone_free_space_hint_prepend(freespace,
							new, old_length, cur);
		}
		else
		if (((vm_offset_t)cur + cur->length) == (vm_offset_t)elem) {
			/* the element starts where cur ends */
			vm_size_t		old_length = cur->length;

			cur->length += elem_size;
			if (((vm_offset_t)cur + cur->length) ==
						(vm_offset_t)cur->next) {
				/* and fills the gap to the next entry */
				zone_free_space_hint_delete(
							freespace, cur->next);

				cur->length += cur->next->length;
				if (cur->next = cur->next->next)
					cur->next->pred = &cur->next;
				freespace->num_entries--;
			}

			zone_free_space_hint_append(freespace,
							cur, old_length);
		}
		
		*free = next;
	}
	
	zone->last_insert = 0;
}

/*
 * plan 350 (authored): take every whole page inside zone_map out of the
 * collectable pools (pool 0 is skipped), then drop zget_space_lock,
 * which the caller took, and free the pages.  (original 0x16ab34)
 */
void
zone_free_space_reclaim(void)
{
	struct zone_free_space_entry	**last, *cur, *pages = 0;
	struct zone_free_space		**f = &zone_free_space[0];
	int				i;

	for (i = 1; i < zone_free_space_count; i++) {
		last = &(*++f)->entries;
		while ((cur = *last) != 0) {
			if (cur->length >= PAGE_SIZE) {
			    vm_offset_t		start, end;
		    
			    start = round_page((vm_offset_t)cur);
			    end = trunc_page(
				    (vm_offset_t)cur + cur->length);
			    if (start < end &&
					start >= zone_min &&
					end <= zone_max) {
				struct zone_free_space_entry	*tmp;

				zone_free_space_hint_delete(*f, cur);

				if (((vm_offset_t)cur + cur->length) != end) {
					/* keep the tail after end */
					(vm_offset_t)tmp = end;
					tmp->length = (vm_offset_t)cur +
						    	cur->length - end;
					if (tmp->next = cur->next)
						tmp->next->pred = &tmp->next;

					if ((vm_offset_t)cur == start) {
						*last = tmp;
						tmp->pred = last;
					}
					else {
						/* and the head before start */
						cur->length = start -
					    		(vm_offset_t)cur;
					    	cur->next = tmp;
					    	tmp->pred = &cur->next;
					    	(*f)->num_entries++;

					    	zone_free_space_hint_insert(
								*f, cur);
					}

					zone_free_space_hint_insert(*f, tmp);
				}
				else if ((vm_offset_t)cur != start) {
					/* keep the head before start */
					cur->length = start - (vm_offset_t)cur;

					zone_free_space_hint_insert(*f, cur);
				}
				else {
					if (*last = cur->next)
						cur->next->pred = last;
					(*f)->num_entries--;
				}

				/* queue [start, end) for freeing */
				(vm_offset_t)tmp = start;
				tmp->length = end - start;
				tmp->next = pages;
				pages = tmp;
				continue;
			    }
			}

			last = &cur->next;
		}
	}

	simple_unlock(&zget_space_lock);

	while ((cur = pages) != 0) {
		pages = cur->next;
		kmem_free(zone_map, (vm_offset_t)cur, cur->length);
	}
}

/*
 * Contiguous space allocator for non-paged zones. Allocates "size" amount
 * of memory from zone_map.
 * plan 350: from the given pool (0 = default pool); falls back to the
 * end of zdata, then to new zone_map memory.  (original 0x16ada4)
 */

vm_offset_t zget_space(freespace, size, canblock)	/* plan 350 */
	struct zone_free_space *freespace;	/* plan 350 */
	vm_size_t size;
	boolean_t canblock;	/* plan 350 */
{
	vm_offset_t	new_space = 0;
	vm_offset_t	result;
	vm_size_t	space_to_add;	/* plan 350: no '= 0' (the original has no store) */
	struct zone_free_space_entry	/* plan 350 */
			*cur, **last;	/* plan 350 */

	/* plan 350 (authored) */
	if (freespace == 0)
		freespace = zone_default_space;

	if (size > ZONE_MIN_ALLOC)
		size = ((size + (ZONE_MIN_ALLOC - 1)) & ~(ZONE_MIN_ALLOC - 1));
	else
		size = ZONE_MIN_ALLOC;

	simple_lock(&zget_space_lock);
	for (;;) {	/* plan 350 */
		/* plan 350 (authored): an existing free entry */
		if ((cur = zone_free_space_lookup(freespace, size)) != 0) {
			last = cur->pred;

			if ((cur->length - size) < ZONE_MIN_ALLOC) {
				/* use all of it */
				if (*last = cur->next)
					cur->next->pred = last;
				freespace->num_entries--;
			}
			else {
				struct zone_free_space_entry	*new;

				/* the rest stays in its place on the list */
				(vm_offset_t)new = (vm_offset_t)cur + size;
				new->length = cur->length - size;
				if (new->next = cur->next)
					new->next->pred = &new->next;
				new->pred = last;
				*last = new;

				zone_free_space_hint_insert(freespace, new);
			}
			result = (vm_offset_t)cur;
			break;
		}
		else if (new_space == 0) {	/* plan 350 */
		/*
		 *	Add at least one page to allocation area.
		 */

		space_to_add = round_page(size);

		/* plan 350 (authored): take it from the end of zdata */
		if (zdata_size >= space_to_add) {
			zdata_size -= space_to_add;
			result = zone_free_space_add(
						freespace,
						size,
						zdata + zdata_size,
						space_to_add);
			break;
		}

			/*
			 *	Memory cannot be wired down while holding
			 *	any locks that the pageout daemon might
			 *	need to free up pages.  [Making the zget_space
			 *	lock a complex lock does not help in this
			 *	regard.]
			 *
			 *	Unlock and allocate memory.  Because several
			 *	threads might try to do this at once, don't
			 *	use the memory before checking for available
			 *	space again.
			 */

			simple_unlock(&zget_space_lock);

			if (kmem_alloc_zone(zone_map,	/* plan 350 */
					     &new_space, space_to_add,
					     canblock)	/* plan 350 */
							!= KERN_SUCCESS)
				return(0);
			simple_lock(&zget_space_lock);
			continue;
		}
		else {	/* plan 350 */
		/*
	  	 *	Memory was allocated in a previous iteration.
		 *	plan 350: carve the element from it.
		 */

			result = zone_free_space_add(	/* plan 350 */
						freespace,
						size,
						new_space,
						space_to_add);
			new_space = 0;
			break;	/* plan 350 */
		}
	}
	simple_unlock(&zget_space_lock);

	if (new_space != 0)
		kmem_free(zone_map, new_space, space_to_add);

	return(result);
}

/*
 * plan 350 (authored): make a pool with the given unit and maximum,
 * its header and hint table taken from the default pool.
 */
static
struct zone_free_space *
zone_free_space_alloc(alloc_unit, alloc_max)
	vm_size_t	alloc_unit;
	vm_size_t	alloc_max;
{
	struct zone_free_space	*freespace, **f;
	
	if (zone_free_space_count >=
			(sizeof (zone_free_space) / sizeof (freespace)))
		return (0);
	
	f = &zone_free_space[zone_free_space_count++];

	(vm_offset_t)freespace = zget_space(
					zone_default_space,
					sizeof (struct zone_free_space), 
					FALSE);
	freespace->alloc_unit = alloc_unit;
	freespace->alloc_max = alloc_max;

	freespace->entries = 0;
	freespace->num_entries = 0;
	
	freespace->hash_shift = 0;
	while (!(alloc_unit & 01)) {
		freespace->hash_shift++; alloc_unit >>= 1;
	}

	freespace->num_hints = freespace->alloc_max >> freespace->hash_shift;
	(vm_offset_t)freespace->hints =
			zget_space(
				zone_default_space,
				freespace->num_hints *
					sizeof (struct zone_free_space_hint),
				FALSE);
	bzero(freespace->hints, freespace->num_hints *
					sizeof (struct zone_free_space_hint));

	*f = freespace;
	
	return (freespace);
}

/*
 * plan 350 (authored): an empty zone goes to the first collectable pool
 * whose maximum holds its element size rounded to the pool unit.
 * (original 0x16af6c)
 */
static
void
zone_free_space_select(zone)
	zone_t		zone;
{
	struct zone_free_space	**f = &zone_free_space[1];
	vm_size_t	elem_size;
	int		i;
	
	if (zone->cur_size > 0)
		return;
	
	for (i = 1; i < zone_free_space_count; i++) {
		elem_size = ((zone->elem_size + ((*f)->alloc_unit - 1))
				& ~((*f)->alloc_unit - 1));
		if (elem_size <= (*f)->alloc_max) {
			zone->elem_size = elem_size;				
			zone->free_space = *f;
			break;
		}
		
		f++;
	}
}

/*
 *	Initialize the "zone of zones" which uses fixed memory allocated
 *	earlier in memory initialization.  zone_bootstrap is called
 *	before zone_init.
 */
void zone_bootstrap()
{
	simple_lock_init(&all_zones_lock);
	first_zone = ZONE_NULL;
	last_zone = &first_zone;
	num_zones = 0;

	/* plan 350 (authored) */
	if (sizeof (struct zone_free_space_entry) > ZONE_MIN_ALLOC)
		panic("zone_bootstrap");

	simple_lock_init(&zget_space_lock);

	/* plan 350 (authored): the default pool */
	_zone_default_space.hints = &_zone_default_space_hint;
	_zone_default_space.num_hints = 1;
	
	zone_free_space[0] = &_zone_default_space;
	zone_free_space_count = 1;

	zone_zone = ZONE_NULL;
	zone_zone = zinit(sizeof(struct zone), 128 * sizeof(struct zone),
			  sizeof(struct zone), FALSE, "zones");	/* plan 350 */

	/* plan 350 (authored): the collectable pools */
	zone_free_space_alloc(16,	96);
	zone_free_space_alloc(128,	768);
	zone_free_space_alloc(1024,	PAGE_SIZE);
}

void zone_init()
{
	/* plan 350: zone_min/zone_max are globals; no page table */
	zone_map = kmem_suballoc(kernel_map, &zone_min, &zone_max,
				 zone_map_size, FALSE);
}


/*
 *	zalloc returns an element from the specified zone.
 *	plan 350: zalloc_canblock with zalloc/zalloc_noblock wrappers;
 *	without canblock it returns 0 instead of waiting or panicking.
 *	(original 0x16b364)
 */
static	/* plan 350 */
vm_offset_t zalloc_canblock(zone_t zone, boolean_t canblock)	/* plan 350 */
{
	vm_offset_t	addr;

	if (zone == ZONE_NULL)
		panic ("zalloc: null zone");

	/* plan 350: no check_simple_locks() (none in the original) */

	zone_lock(zone);
	REMOVE_FROM_ZONE(zone, addr, vm_offset_t);
	while (addr == 0) {
		/*
 		 *	If nothing was there, try to get more
		 */
		if (zone->doing_alloc) {
			/*
			 *	Someone is allocating memory for this zone.
			 *	Wait for it to show up, then try again.
			 */
			if (!canblock) {	/* plan 350 */
				zone_unlock(zone);	/* plan 350 */
				return(0);	/* plan 350 */
			}
			assert_wait((event_t)&zone->doing_alloc, TRUE);
			/* XXX say wakeup needed */
			zone_unlock(zone);
			thread_block_with_continuation((void (*)()) 0);	/* plan 350 */
			zone_lock(zone);
		}
		else {
			if ((zone->cur_size + (zone->pageable ?	/* plan 350 */
				zone->alloc_size : zone->elem_size)) >
			    zone->max_size) {
				if (zone->exhaustible)	/* plan 350 */
					break;
				/*
				 * Printf calls logwakeup, which calls
				 * select_wakeup which will do a zfree
				 * (which tries to take the select_zone
				 * lock... Hang.  Release the lock now
				 * so it can be taken again later.
				 * NOTE: this used to be specific to
				 * the select_zone, but for
				 * cleanliness, we just unlock all
				 * zones before this.
				 */
				if (zone->expandable) {	/* plan 350 */
					/*
					 * We're willing to overflow certain
					 * zones, but not without complaining.
					 *
					 * This is best used in conjunction
					 * with the collecatable flag. What we
					 * want is an assurance we can get the
					 * memory back, assuming there's no
					 * leak. 
					 */
					zone->max_size += (zone->max_size >> 1);
				} else if (!zone_ignore_overflow) {
					zone_unlock(zone);
					if (!canblock)	/* plan 350 */
						return(0);	/* plan 350 */
					printf("zone \"%s\" empty.\n",
						zone->zone_name);
					panic("zalloc");
				}
			}

			if (zone->pageable)	/* plan 350 */
				zone->doing_alloc = TRUE;
			zone_unlock(zone);

			if (zone->pageable) {	/* plan 350 */
				if (kmem_alloc_pageable(zone_map, &addr,
							zone->alloc_size)
							!= KERN_SUCCESS)
					panic("zalloc");
				zcram(zone, addr, zone->alloc_size);
				zone_lock(zone);
				zone->doing_alloc = FALSE; 
				/* XXX check before doing this */
				thread_wakeup((event_t)&zone->doing_alloc);

				REMOVE_FROM_ZONE(zone, addr, vm_offset_t);
			} else {	/* plan 350: no zone page table */
				addr = zget_space(zone->free_space,	/* plan 350 */
						  zone->elem_size, canblock);	/* plan 350 */
				if (addr == 0) {	/* plan 350 */
					if (!canblock)	/* plan 350 */
						return(0);	/* plan 350 */
					panic("zalloc");
				}	/* plan 350 */

				zone_lock(zone);
				zone->count++;	/* plan 350 */
				zone->cur_size += zone->elem_size;
				zone_unlock(zone);
				return(addr);
			}
		}
	}

	zone_unlock(zone);
	return(addr);
}

/* plan 350 (authored): original 0x16b790, 0x16b7a4 */
vm_offset_t zalloc(zone)
	register zone_t zone;
{
	return (zalloc_canblock(zone, TRUE));
}

vm_offset_t zalloc_noblock(zone)
	register zone_t zone;
{
	return (zalloc_canblock(zone, FALSE));
}


/*
 *	zget returns an element from the specified zone
 *	and immediately returns nothing if there is nothing there.
 *
 *	This form should be used when you can not block (like when
 *	processing an interrupt).
 */
vm_offset_t zget(zone_t zone)
{
	register vm_offset_t	addr;

	if (zone == ZONE_NULL)
		panic ("zalloc: null zone");

	zone_lock(zone);
	REMOVE_FROM_ZONE(zone, addr, vm_offset_t);
	zone_unlock(zone);

	return(addr);
}

boolean_t zone_check = FALSE;

void zfree(zone_t zone, vm_offset_t elem)
{
	zone_lock(zone);
	if (zone_check) {
		vm_offset_t this;

		/* check the zone's consistency */

		for (this = zone->free_elements;
		     this != 0;
		     this = * (vm_offset_t *) this)
			if (this == elem)
				panic("zfree");
	}
	ADD_TO_ZONE(zone, elem);
	zone_unlock(zone);
}

/*
 * plan 350 (authored): zones start collectable (zinit picks a pool);
 * zcollectable does nothing, and zchange can only take collectability
 * away by moving the zone to the default pool.  (original 0x16b904,
 * 0x16b90c)
 */
void zcollectable(zone) 
	zone_t		zone;
{
}

void zchange(zone, pageable, sleepable, exhaustible, collectable)
	zone_t		zone;
	boolean_t	pageable;
	boolean_t	sleepable;
	boolean_t	exhaustible;
	boolean_t	collectable;
{
	zone->pageable = pageable;
	zone->sleepable = sleepable;
	zone->exhaustible = exhaustible;
	if (!collectable)
		zone->free_space = zone_default_space;
	zone_lock_init(zone);
}

/*	Zone garbage collection
 *
 *	plan 350: zone_gc returns the free elements of every collectable,
 *	non-pageable zone to its pool and then reclaims whole pages from
 *	the pools (zone_free_space_reclaim drops zget_space_lock).
 *	Global in the original (0x16b970).
 */
void zone_gc()	/* plan 350 */
{
	int		max_zones;
	zone_t		z;
	int		i;

	simple_lock(&all_zones_lock);
	max_zones = num_zones;
	z = first_zone;
	simple_unlock(&all_zones_lock);

	simple_lock(&zget_space_lock);	/* plan 350 */

	for (i = 0; i < max_zones; i++) {
		zone_lock(z);

		if (!z->pageable && zone_collectable(z))	/* plan 350 */
		    zone_collect(z);	/* plan 350 */

		zone_unlock(z);		
		simple_lock(&all_zones_lock);
		z = z->next_zone;
		simple_unlock(&all_zones_lock);
	}

	zone_free_space_reclaim();	/* plan 350 */
}

boolean_t zone_gc_allowed = TRUE;
unsigned zone_gc_last_tick = 0;
unsigned zone_gc_max_rate = 0;		/* in ticks */

/*
 *	consider_zone_gc:
 *
 *	Called by the pageout daemon when the system needs more free pages.
 */

void
consider_zone_gc()
{
	/*
	 *	By default, don't attempt zone GC more frequently
	 *	than once a second.
	 */

	if (zone_gc_max_rate == 0)
		zone_gc_max_rate = hz;

	if (zone_gc_allowed &&
	    (sched_tick > (zone_gc_last_tick + zone_gc_max_rate))) {
		zone_gc_last_tick = sched_tick;
		zone_gc();
	}
}

/*
 * plan 350 (authored): reclaim pool pages without collecting the zones.
 * (original 0x16bad0)
 */
void
zone_reclaim()
{
	simple_lock(&zget_space_lock);
	zone_free_space_reclaim();
}

#if	MACH_DEBUG
kern_return_t host_zone_info(host, namesp, namesCntp, infop, infoCntp)
	host_t		host;
	zone_name_array_t *namesp;
	unsigned int	*namesCntp;
	zone_info_array_t *infop;
	unsigned int	*infoCntp;
{
	zone_name_t	*names;
	vm_offset_t	names_addr;
	vm_size_t	names_size = 0; /*'=0' to quiet gcc warnings */
	zone_info_t	*info;
	vm_offset_t	info_addr;
	vm_size_t	info_size = 0; /*'=0' to quiet gcc warnings */
	unsigned int	max_zones, i;
	zone_t		z;
	kern_return_t	kr;

	if (host == HOST_NULL)
		return KERN_INVALID_HOST;

	/*
	 *	We assume that zones aren't freed once allocated.
	 *	We won't pick up any zones that are allocated later.
	 */

	simple_lock(&all_zones_lock);
	max_zones = num_zones;
	z = first_zone;
	simple_unlock(&all_zones_lock);

	if (max_zones <= *namesCntp) {
		/* use in-line memory */

		names = *namesp;
	} else {
		names_size = round_page(max_zones * sizeof *names);
		kr = kmem_alloc_pageable(ipc_kernel_map,
					 &names_addr, names_size);
		if (kr != KERN_SUCCESS)
			return kr;

		names = (zone_name_t *) names_addr;
	}

	if (max_zones <= *infoCntp) {
		/* use in-line memory */

		info = *infop;
	} else {
		info_size = round_page(max_zones * sizeof *info);
		kr = kmem_alloc_pageable(ipc_kernel_map,
					 &info_addr, info_size);
		if (kr != KERN_SUCCESS) {
			if (names != *namesp)
				kmem_free(ipc_kernel_map,
					  names_addr, names_size);
			return kr;
		}

		info = (zone_info_t *) info_addr;
	}

	for (i = 0; i < max_zones; i++) {
		zone_name_t *zn = &names[i];
		zone_info_t *zi = &info[i];
		struct zone zcopy;

		assert(z != ZONE_NULL);

		zone_lock(z);
		zcopy = *z;
		zone_unlock(z);

		simple_lock(&all_zones_lock);
		z = z->next_zone;
		simple_unlock(&all_zones_lock);

		/* assuming here the name data is static */
		(void) strncpy(zn->zn_name, zcopy.zone_name,
			       sizeof zn->zn_name);

		zi->zi_count = zcopy.count;	/* plan 350 */
		zi->zi_cur_size = zcopy.cur_size;
		zi->zi_max_size = zcopy.max_size;
		zi->zi_elem_size = zcopy.elem_size;
		zi->zi_alloc_size = zcopy.alloc_size;
		zi->zi_pageable = zcopy.pageable;	/* plan 350 */
		zi->zi_sleepable = zcopy.sleepable;	/* plan 350 */
		zi->zi_exhaustible = zcopy.exhaustible;	/* plan 350 */
		zi->zi_collectable = zone_collectable(&zcopy);	/* plan 350 */
	}

	if (names != *namesp) {
		vm_size_t used;
#if	MACH_OLD_VM_COPY	/* plan 350 */
#else	/* plan 350 */
		vm_map_copy_t copy;
#endif	/* plan 350 */

		used = max_zones * sizeof *names;

		if (used != names_size)
			bzero((char *) (names_addr + used), names_size - used);

#if	MACH_OLD_VM_COPY	/* plan 350 (authored) */
		kr = vm_move(ipc_kernel_map, names_addr,
			     ipc_soft_map, names_size, TRUE, &names_addr);
		assert(kr == KERN_SUCCESS);

		*namesp = (zone_name_t *) names_addr;
#else	/* plan 350 */
		kr = vm_map_copyin(ipc_kernel_map, names_addr, names_size,
				   TRUE, &copy);
		assert(kr == KERN_SUCCESS);

		*namesp = (zone_name_t *) copy;
#endif	/* plan 350 */
	}
	*namesCntp = max_zones;

	if (info != *infop) {
		vm_size_t used;
#if	MACH_OLD_VM_COPY	/* plan 350 */
#else	/* plan 350 */
		vm_map_copy_t copy;
#endif	/* plan 350 */

		used = max_zones * sizeof *info;

		if (used != info_size)
			bzero((char *) (info_addr + used), info_size - used);

#if	MACH_OLD_VM_COPY	/* plan 350 (authored) */
		kr = vm_move(ipc_kernel_map, info_addr,
			     ipc_soft_map, info_size, TRUE, &info_addr);
		assert(kr == KERN_SUCCESS);

		*infop = (zone_info_t *) info_addr;
#else	/* plan 350 */
		kr = vm_map_copyin(ipc_kernel_map, info_addr, info_size,
				   TRUE, &copy);
		assert(kr == KERN_SUCCESS);

		*infop = (zone_info_t *) copy;
#endif	/* plan 350 */
	}
	*infoCntp = max_zones;

	return KERN_SUCCESS;
}

/*
 * plan 350 (authored): report the pools and their free entries.  The
 * buffers are sized with zget_space_lock released and the counts are
 * taken again until they fit.  As in the original, a new info buffer
 * is made when *infoCnt is larger than the pool count.  The 4.2 build
 * has MACH_OLD_VM_COPY set; the results go out with vm_move.
 * (original 0x16be1c)
 */
kern_return_t host_zone_free_space_info(
				host,
				infop, infoCnt,
				chunksp, chunksCnt)
	host_t				host;
	zone_free_space_info_array_t	*infop;
	mach_msg_type_number_t		*infoCnt;
	zone_free_space_chunk_array_t	*chunksp;
	mach_msg_type_number_t		*chunksCnt;
{
	kern_return_t	kr;
	vm_size_t	size1, size2;
	vm_offset_t	addr1, addr2;
	vm_offset_t	memory1, memory2;
	mach_msg_type_number_t
			actual1, actual2;
	zone_free_space_info_t
			*info;
	zone_free_space_chunk_t
			*chunk;
	struct zone_free_space_entry
			**last, *cur;
	struct zone_free_space
			*freespace;
	int		i;

	if (host == HOST_NULL)
		return KERN_INVALID_HOST;

	size1 = size2 = 0;

	for (;;) {
		vm_size_t	size1_needed, size2_needed;

		size1_needed = size2_needed = 0;

		simple_lock(&zget_space_lock);

		actual1 = actual2 = 0;
		
		for (actual1 = 0; actual1 < zone_free_space_count; actual1++)
			actual2 += zone_free_space[actual1]->num_entries;
		
		if (actual1 < *infoCnt)
			size1_needed = round_page(
				actual1 * sizeof (**infop));
		
		if (actual2 > *chunksCnt)
			size2_needed = round_page(
				actual2 * sizeof (**chunksp));

		if (size1_needed <= size1 &&
				size2_needed <= size2)
			break;

		simple_unlock(&zget_space_lock);

		if (size1 < size1_needed) {
			if (size1 != 0)
				kmem_free(ipc_kernel_map, addr1, size1);
			size1 = size1_needed;

			kr = kmem_alloc_pageable(
						ipc_kernel_map, &addr1, size1);
			if (kr != KERN_SUCCESS) {
				if (size2 != 0)
					kmem_free(
						ipc_kernel_map, addr2, size2);
				return KERN_RESOURCE_SHORTAGE;
			}
			kr = vm_map_pageable(
				ipc_kernel_map, addr1, addr1 + size1, FALSE);
			assert(kr == KERN_SUCCESS);
		}

		if (size2 < size2_needed) {
			if (size2 != 0)
				kmem_free(ipc_kernel_map, addr2, size2);
			size2 = size2_needed;

			kr = kmem_alloc_pageable(
						ipc_kernel_map, &addr2, size2);
			if (kr != KERN_SUCCESS) {
				if (size1 != 0)
					kmem_free(
						ipc_kernel_map, addr1, size1);
				return KERN_RESOURCE_SHORTAGE;
			}
			kr = vm_map_pageable(
				ipc_kernel_map, addr2, addr2 + size2, FALSE);
			assert(kr == KERN_SUCCESS);
		}
	}

	if (size1 != 0)
		info = (zone_free_space_info_t *)addr1;
	else
		info = *infop;

	if (size2 != 0)
		chunk = (zone_free_space_chunk_t *)addr2;
	else
		chunk = *chunksp;

	for (i = 0; i < actual1; i++) {
		freespace = zone_free_space[i];

		info->zf_alloc_unit = freespace->alloc_unit;
		info->zf_alloc_max = freespace->alloc_max;
		info->zf_num_chunks = freespace->num_entries;
		info++;

		last = &freespace->entries;
		while ((cur = *last) != 0) {
			chunk->zf_address = (vm_offset_t)cur;
			chunk->zf_length = cur->length;
			chunk++;
			
			last = &cur->next;
		}
	}

	simple_unlock(&zget_space_lock);

	if (actual1 != 0 && size1 != 0) {
		vm_size_t	size_used;
		
		size_used = round_page(actual1 * sizeof (**infop));

		kr = vm_map_pageable(
			ipc_kernel_map, addr1, addr1 + size_used, TRUE);
		assert(kr == KERN_SUCCESS);

		kr = vm_move(
			ipc_kernel_map, addr1,
			ipc_soft_map, size_used,
			TRUE, &memory1);
		assert(kr == KERN_SUCCESS);
	
		if (size_used != size1)
			kmem_free(
				ipc_kernel_map,
				addr1 + size_used, size1 - size_used);

		*infop = (zone_free_space_info_t *)memory1;
	}
	else if (actual1 == 0) {
		*infop = (zone_free_space_info_t *)0;

		if (size1 != 0)
			kmem_free(ipc_kernel_map, addr1, size1);
	}
	
	*infoCnt = actual1;

	if (actual2 != 0 && size2 != 0) {
		vm_size_t	size_used;

		size_used = round_page(actual2 * sizeof (**chunksp));

		kr = vm_map_pageable(
			ipc_kernel_map, addr2, addr2 + size_used, TRUE);
		assert(kr == KERN_SUCCESS);

		kr = vm_move(
			ipc_kernel_map, addr2,
			ipc_soft_map, size_used,
			TRUE, &memory2);
		assert(kr == KERN_SUCCESS);

		if (size_used != size2)
			kmem_free(
				ipc_kernel_map,
				addr2 + size_used, size2 - size_used);

		*chunksp = (zone_free_space_chunk_t *)memory2;
	}
	else if (actual2 == 0) {
		*chunksp = (zone_free_space_chunk_t *)0;

		if (size2 != 0)
			kmem_free(ipc_kernel_map, addr2, size2);
	}

	*chunksCnt = actual2;

	return KERN_SUCCESS;
}
#endif	MACH_DEBUG
