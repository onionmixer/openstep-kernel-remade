/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/*
 *	File:	vm/vm_kern.c
 *	Author:	Avadis Tevanian, Jr., Michael Wayne Young
 *
 *	Copyright (C) 1985, Avadis Tevanian, Jr., Michael Wayne Young
 *
 *	Kernel memory management.
 *
 * HISTORY
 * $Log:	vm_kern.c,v $
 * Revision 2.7  88/10/18  03:44:37  mwyoung
 * 	Give up in kmem_alloc_wait if the request is larger than the
 * 	(sub)map can ever accomodate.
 * 	[88/09/13            mwyoung]
 * 
 * Revision 2.6  88/10/11  10:26:37  rpd
 * 	Added special check for zero size to vm_move.
 * 	[88/10/07  14:26:34  rpd]
 * 
 * Revision 2.5  88/10/01  21:59:58  rpd
 * 	Changed FAST_PAGER_DATA to MACH_XP_FPD.
 * 	[88/09/29  01:11:09  rpd]
 * 
 * Revision 2.4  88/09/25  22:17:08  rpd
 * 	Changed vm_move; dst_map can no longer be VM_MAP_NULL.
 * 	[88/09/24  18:16:39  rpd]
 * 	
 * 	Changed vm_move to return an explicit error indication,
 * 	and pass back the destination address in an argument.
 * 	[88/09/20  16:14:13  rpd]
 * 
 * Revision 2.3  88/08/25  18:27:05  mwyoung
 * 	Include files for FAST_PAGER_DATA.
 * 	[88/08/16  00:36:39  mwyoung]
 * 
 * 06-Aug-88  Avadis Tevanian (avie) at NeXT
 *	Call vm_page_wire for pages in kmem_mb_alloc.  (Keeps total
 *	page count sane).
 *
 * 16-Apr-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	FAST_PAGER_DATA: De-linted.
 *
 * 28-Jan-88  David Golub (dbg) at Carnegie-Mellon University
 *	In kmem_alloc, preallocate pages for non-XP configurations as
 *	well, to prevent getting non-zero pages that had previously been
 *	paged out.
 *
 * 23-Jan-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Make v_to_p_zone non-pageable, as it is commonly used by the
 *	inode pager.
 *
 * 11-Jan-88  Michael Young (mwyoung) at Carnegie-Mellon University
 *	Moved copy_user_to_physical here.  Eliminated old history.
 *
 * 30-Dec-87  David Golub (dbg) at Carnegie-Mellon University
 *	Changed kmem_free to use vm_offset_t for address.
 *
 */

/*
 * The line marked "plan 400 (Mach4)" is the same as Mach4
 * kernel/vm/vm_kern.c:55, whose notice is:
 */
/*
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988,1987 Carnegie Mellon University.
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

#import <kern/assert.h>
#import <mach/kern_return.h>	/* plan 243: was sys/kern_return.h */
#import <sys/types.h>

#import <vm/vm_kern.h>
#import <vm/vm_map.h>
#import <vm/vm_object.h>	/* plan 243 */
#import <vm/vm_page.h>
#import <vm/vm_pageout.h>
#import <mach/vm_param.h>	/* plan 243: was vm/vm_param.h */
#import <kern/thread.h>		/* plan 243: current_map() */

vm_map_t	kernel_map;	/* plan 400 (Mach4): Mach4 kernel/vm/vm_kern.c:55 */

/* plan 243: page allocation helper, defined after kmem_free */
static boolean_t	kmem_alloc_pages();

extern vm_map_t		swapfs_bit_map, swapfs_rem_map;	/* plan 243 */

/*
 *	Allocate wired-down memory in the kernel's address map
 *	or a submap (plan 243: common body of kmem_alloc,
 *	kmem_alloc_wired and kmem_alloc_zone).
 */
static kern_return_t
kmem_alloc_prim(map, addrp, size, object, canblock)
	register vm_map_t	map;
	vm_offset_t		*addrp;
	register vm_size_t	size;
	vm_object_t		object;
	boolean_t		canblock;
{
	vm_offset_t		addr;
	kern_return_t		result;
	vm_offset_t		offset = 0;

	addr = vm_map_min(map);
	size = round_page(size);

	if (result = vm_map_find(map,
				 (object != kernel_object) ?
					object : VM_OBJECT_NULL,
				 (vm_offset_t) 0, &addr, size, TRUE)
			!= KERN_SUCCESS) {
		if (object != kernel_object)
			vm_object_deallocate(object);
		return(result);
	}

	if (object == kernel_object) {
		/*
		 *	Since we didn't know where the new region would
		 *	start, we couldn't supply the correct offset into
		 *	the kernel object.  Re-allocate that address
		 *	region with the correct offset.
		 */
		offset = addr - VM_MIN_KERNEL_ADDRESS;
		vm_object_reference(kernel_object);

		vm_map_lock(map);
		vm_map_delete(map, addr, addr + size);
		vm_map_insert(map, object, offset, addr, addr + size);
		vm_map_unlock(map);
	}

	if (!kmem_alloc_pages(object, offset, size, canblock)) {
		vm_map_lock(map);
		vm_map_delete(map, addr, addr + size);
		vm_map_unlock(map);
		return(KERN_RESOURCE_SHORTAGE);
	}

	/*
	 *	And finally, mark the data as non-pageable.
	 */

	(void) vm_map_pageable(map, (vm_offset_t) addr, addr + size, FALSE);

	*addrp = addr;
	return(KERN_SUCCESS);
}

kern_return_t
kmem_alloc(map, addrp, size)		/* plan 243 */
	vm_map_t	map;
	vm_offset_t	*addrp;
	vm_size_t	size;
{
	vm_object_t	object = vm_object_allocate(size);

	return(kmem_alloc_prim(map, addrp, size, object, TRUE));
}

/*
 *	kmem_realloc (plan 243):
 *
 *	Reallocate wired-down memory in the kernel's address map
 *	or a submap.
 */
kern_return_t
kmem_realloc(map, oldaddr, oldsize, newaddrp, newsize)
	vm_map_t	map;
	vm_offset_t	oldaddr;
	vm_size_t	oldsize;
	vm_offset_t	*newaddrp;
	vm_size_t	newsize;
{
	vm_offset_t	oldmin, oldmax;
	vm_offset_t	newaddr;
	vm_object_t	object;
	vm_map_entry_t	oldentry, newentry;
	kern_return_t	kr;

	oldmin = trunc_page(oldaddr);
	oldmax = round_page(oldaddr + oldsize);
	oldsize = oldmax - oldmin;
	newsize = round_page(newsize);

	if (kr = vm_map_find(map, VM_OBJECT_NULL, (vm_offset_t) 0,
			     &newaddr, newsize, TRUE) != KERN_SUCCESS)
		return(kr);

	(void) vm_map_lookup_entry(map, newaddr, &newentry);
	if (!vm_map_lookup_entry(map, oldmin, &oldentry))
		panic("kmem_realloc");
	object = oldentry->object.vm_object;

	vm_object_reference(object);
	vm_object_lock(object);
	if (object->size != oldsize)
		panic("kmem_realloc");
	object->size = newsize;
	vm_object_unlock(object);

	newentry->object.vm_object = object;
	newentry->offset = 0;

	vm_map_unlock(map);

	(void) kmem_alloc_pages(object, oldsize, newsize, TRUE);
	(void) vm_map_pageable(map, newaddr, newaddr + newsize, FALSE);

	*newaddrp = newaddr;
	return(KERN_SUCCESS);
}

kern_return_t
kmem_alloc_wired(map, addrp, size)	/* plan 243 */
	vm_map_t	map;
	vm_offset_t	*addrp;
	vm_size_t	size;
{
	return(kmem_alloc_prim(map, addrp, size, kernel_object, TRUE));
}

/*
 *	kmem_alloc_pageable:
 *
 *	Allocate pageable memory to the kernel's address map.
 *	map must be "kernel_map" below.
 */

kern_return_t
kmem_alloc_pageable(map, addrp, size)	/* plan 243 */
	vm_map_t		map;
	vm_offset_t		*addrp;
	vm_size_t		size;
{
	vm_offset_t		addr;
	register kern_return_t	result;

	addr = vm_map_min(map);
	result = vm_map_find(map, VM_OBJECT_NULL, (vm_offset_t) 0,
				&addr, round_page(size), TRUE);
	if (result != KERN_SUCCESS)
		return(result);

	*addrp = addr;
	return(KERN_SUCCESS);
}

/*
 *	kmem_free:
 *
 *	Release a region of kernel virtual memory allocated
 *	with kmem_alloc, and return the physical pages
 *	associated with that region.
 */
void kmem_free(map, addr, size)
	vm_map_t		map;
	register vm_offset_t	addr;
	vm_size_t		size;
{
	(void) vm_map_remove(map, trunc_page(addr), round_page(addr + size));
}

/*
 *	kmem_alloc_pages (plan 243):
 *
 *	Allocate zero-filled pages for [offset, offset + size) of object.
 *	If canblock is FALSE, give up instead of waiting for memory.
 *
 *	We're intentionally not activating the pages we allocate
 *	to prevent a race with page-out.  vm_map_pageable will wire
 *	the pages.
 */
static boolean_t
kmem_alloc_pages(object, offset, size, canblock)
	register vm_object_t	object;
	register vm_offset_t	offset;
	register vm_size_t	size;
	boolean_t		canblock;
{
	register vm_page_t	mem;

	while (size) {
		vm_object_lock(object);
		while ((mem = vm_page_alloc(object, offset))
			    == VM_PAGE_NULL) {
			vm_object_unlock(object);
			if (!canblock)
				return(FALSE);
			VM_WAIT;
			vm_object_lock(object);
		}
		vm_object_unlock(object);

		vm_page_zero_fill(mem);
		mem->busy = FALSE;

		size -= PAGE_SIZE;
		offset += PAGE_SIZE;
	}
	return(TRUE);
}

/*
 *	kmem_suballoc:
 *
 *	Allocates a map to manage a subrange
 *	of the kernel virtual address space.
 *
 *	Arguments are as follows:
 *
 *	parent		Map to take range from
 *	size		Size of range to find
 *	min, max	Returned endpoints of map
 *	pageable	Can the region be paged
 */
vm_map_t kmem_suballoc(parent, min, max, size, pageable)
	register vm_map_t	parent;
	vm_offset_t		*min, *max;
	register vm_size_t	size;
	boolean_t		pageable;
{
	vm_map_t	result;
	vm_offset_t	addr;		/* plan 243 */

	size = round_page(size);

	vm_object_reference(vm_submap_object);		/* plan 243 */
	addr = (vm_offset_t) vm_map_min(parent);
	if (vm_map_find(parent, vm_submap_object, (vm_offset_t) 0,
				&addr, size, TRUE) != KERN_SUCCESS)
		panic("kmem_suballoc 1");
	pmap_reference(vm_map_pmap(parent));
	result = vm_map_create(vm_map_pmap(parent), addr, addr + size, pageable);
	if (result == VM_MAP_NULL)
		panic("kmem_suballoc 2");
	if (vm_map_submap(parent, addr, addr + size, result) != KERN_SUCCESS)
		panic("kmem_suballoc 3");
	*min = addr;
	*max = addr + size;
	return(result);
}

/*
 *	kmem_init:
 *
 *	Initialize the kernel's virtual memory map, taking
 *	into account all memory allocated up to this time.
 */
void kmem_init(start, end)
	vm_offset_t	start;
	vm_offset_t	end;
{
	vm_offset_t	addr;
	extern vm_map_t	kernel_map;

	kernel_map = vm_map_create(pmap_kernel(), VM_MIN_KERNEL_ADDRESS, end,
				FALSE);

	addr = VM_MIN_KERNEL_ADDRESS;
	(void) vm_map_find(kernel_map, VM_OBJECT_NULL, (vm_offset_t) 0,
				&addr, (start - VM_MIN_KERNEL_ADDRESS),
				FALSE);
}

/*
 * plan 243: copyinmap and copyoutmap below are from Mach4
 * (https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff,
 * kernel/vm/vm_kern.c:1022-1072), which carries this notice:
 */
/*
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988,1987 Carnegie Mellon University.
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
 *	Routine:	copyinmap
 *	Purpose:
 *		Like copyin, except that fromaddr is an address
 *		in the specified VM map.  This implementation
 *		is incomplete; it handles the current user map
 *		and the kernel map/submaps.
 */

int copyinmap(map, fromaddr, toaddr, length)
	vm_map_t map;
	char *fromaddr, *toaddr;
	int length;
{
	if (vm_map_pmap(map) == kernel_pmap) {
		/* assume a correct copy */
		bcopy(fromaddr, toaddr, length);
		return 0;
	}

	if (current_map() == map)
		return copyin( fromaddr, toaddr, length);

	return 1;
}

/*
 *	Routine:	copyoutmap
 *	Purpose:
 *		Like copyout, except that toaddr is an address
 *		in the specified VM map.  This implementation
 *		is incomplete; it handles the current user map
 *		and the kernel map/submaps.
 */

int copyoutmap(map, fromaddr, toaddr, length)
	vm_map_t map;
	char *fromaddr, *toaddr;
	int length;
{
	if (vm_map_pmap(map) == kernel_pmap) {
		/* assume a correct copy */
		bcopy(fromaddr, toaddr, length);
		return 0;
	}

	if (current_map() == map)
		return copyout(fromaddr, toaddr, length);

	return 1;
}

kern_return_t
kmem_alloc_zone(map, addrp, size, canblock)	/* plan 243 */
	vm_map_t	map;
	vm_offset_t	*addrp;
	vm_size_t	size;
	boolean_t	canblock;
{
	return(kmem_alloc_prim(map, addrp, size, kernel_object, canblock));
}

/*
 *	Special hack for allocation in mb_map.  Can never wait for pages
 *	(or anything else) in mb_map.
 */
vm_offset_t kmem_mb_alloc(map, size)
	register vm_map_t	map;
	vm_size_t		size;
{
	vm_object_t		object;
	register vm_map_entry_t	entry;
	vm_offset_t		addr;
	register int		npgs;
	register vm_page_t	m;
	register vm_offset_t	vaddr, offset, cur_off;

	/*
	 *	Only do this on the mb_map (plan 243: or the swapfs maps).
	 */
	if (map != mb_map && map != swapfs_bit_map && map != swapfs_rem_map)
		panic("You fool!");

	size = round_page(size);

	vm_map_lock(map);
	entry = vm_map_first_entry(map);	/* plan 243: 07 vm_map.h names */
	if (entry == vm_map_to_entry(map)) {
		/*
		 *	Map is empty.  Do things normally the first time...
		 *	this will allocate the entry and the object to use.
		 */
		vm_map_unlock(map);
		addr = vm_map_min(map);
		if (vm_map_find(map, VM_OBJECT_NULL, (vm_offset_t) 0,
			&addr, size, TRUE) != KERN_SUCCESS)
			return (0);
		(void) vm_map_pageable(map, addr, addr + size, FALSE);
		return(addr);
	}
	/*
	 *	Map already has an entry.  We must be extending it.
	 */
	if (!(entry == vm_map_last_entry(map) &&
	      entry->is_a_map == FALSE &&
	      entry->vme_start == vm_map_min(map) &&
	      entry->max_protection == VM_PROT_ALL &&	/* plan 243 */
	      entry->protection == VM_PROT_DEFAULT &&
	      entry->inheritance == VM_INHERIT_DEFAULT &&
	      entry->wired_count != 0)) {
		/*
		 *	Someone's not playing by the rules...
		 */
		panic("mb_map abused even more than usual");
	}

	/*
	 *	Make sure there's enough room in map to extend entry.
	 */

	if (vm_map_max(map) - size < entry->vme_end) {
		vm_map_unlock(map);
		return(0);
	}

	/*
	 *	extend the entry
	 */
	object = entry->object.vm_object;
	offset = (entry->vme_end - entry->vme_start) + entry->offset;
	addr   = entry->vme_end;
	entry->vme_end += size;

	/*
	 *	Since we may not have enough memory, and we may not
	 *	block, we first allocate all the memory up front, pulling
	 *	it off the active queue to prevent pageout.  We then can
	 *	either enter the pages, or free whatever we tried to get.
	 */

	vm_object_lock(object);
	cur_off = offset;
	npgs = atop(size);
	while (npgs) {
		m = vm_page_alloc_sequential(object, cur_off, FALSE); /* plan 243 */
		if (m == VM_PAGE_NULL) {
			/*
			 *	Not enough pages, and we can't
			 *	wait, so free everything up.
			 */
			while (cur_off > offset) {
				cur_off -= PAGE_SIZE;
				m = vm_page_lookup(object, cur_off);
				/*
				 *	Don't have to lock the queues here
				 *	because we know that the pages are
				 *	not on any queues.
				 */
				vm_page_free(m);
			}
			vm_object_unlock(object);

			/*
			 *	Shrink the map entry back to its old size.
			 */
			entry->vme_end -= size;
			vm_map_unlock(map);
			return(0);
		}

		/*
		 *	We want zero-filled memory
		 */

		vm_page_zero_fill(m);

		/*
		 *	Since no other process can see these pages, we don't
		 *	have to bother with the busy bit.
		 */

		m->busy = FALSE;

		npgs--;
		cur_off += PAGE_SIZE;
	}

	vm_object_unlock(object);

	/*
	 *	Map entry is already marked non-pageable.
	 *	Loop thru pages, entering them in the pmap.
	 *	(We can't add them to the wired count without
	 *	wrapping the vm_page_queue_lock in splimp...)
	 */
	vaddr = addr;
	cur_off = offset;
	while (vaddr < entry->vme_end) {
		vm_object_lock(object);
		m = vm_page_lookup(object, cur_off);
		vm_page_wire(m);
		vm_object_unlock(object);
		pmap_enter(map->pmap, vaddr, VM_PAGE_TO_PHYS(m),
			entry->protection, TRUE);
		vaddr += PAGE_SIZE;
		cur_off += PAGE_SIZE;
	}
	vm_map_unlock(map);

	return(addr);
}

/*
 *	kmem_alloc_wait
 *
 *	Allocates pageable memory from a sub-map of the kernel.  If the submap
 *	has no room, the caller sleeps waiting for more memory in the submap.
 *
 */
vm_offset_t kmem_alloc_wait(map, size)
	vm_map_t	map;
	vm_size_t	size;
{
	vm_offset_t	addr;
	kern_return_t	result;

	size = round_page(size);

	do {
		/*
		 *	To make this work for more than one map,
		 *	use the map's lock to lock out sleepers/wakers.
		 *	Unfortunately, vm_map_find also grabs the map lock.
		 */
		vm_map_lock(map);
		lock_set_recursive(&map->lock);

		addr = vm_map_min(map);
		result = vm_map_find(map, VM_OBJECT_NULL, (vm_offset_t) 0,
				&addr, size, TRUE);

		lock_clear_recursive(&map->lock);
		if (result != KERN_SUCCESS) {

			if ( (vm_map_max(map) - vm_map_min(map)) < size ) {
				vm_map_unlock(map);
				return(0);
			}

			assert_wait((int)map, TRUE);
			vm_map_unlock(map);
			thread_block();
		}
		else {
			vm_map_unlock(map);
		}

	} while (result != KERN_SUCCESS);

	return(addr);
}

/*
 *	kmem_free_wakeup
 *
 *	Returns memory to a submap of the kernel, and wakes up any threads
 *	waiting for memory in that map.
 */
void	kmem_free_wakeup(map, addr, size)
	vm_map_t	map;
	vm_offset_t	addr;
	vm_size_t	size;
{
	vm_map_lock(map);
	(void) vm_map_delete(map, trunc_page(addr), round_page(addr + size));
	thread_wakeup((int)map);
	vm_map_unlock(map);
}
