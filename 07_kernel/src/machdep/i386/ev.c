/*
 * ev.c - machine dependent support for the Event Driver
 * (plan 283).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original 0x19554c-0x195757).  The text is nearly the same as Darwin 0.1
 * bsd/dev/ev.c (identifiers and structure follow it; every instruction
 * checked against the original bytes); kept as project-authored under
 * D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>
#import <mach/kern_return.h>
#import <kern/kern_port.h>
#import <vm/vm_kern.h>
#import <driverkit/return.h>

#ifndef	NULL
#define NULL ((void *)0)
#endif

/*
 * NULL terminated list of event source classes attached to the Event
 * Driver when the Window Server starts up (original __data 0x1e36dc).
 */
static const char *defaultEventSrc[] =
{
	"EventSrcPCPointer",
	"EventSrcPCKeyboard",
	NULL
};

const char **
defaultEventSources()
{
	return defaultEventSrc;
}

/*
 * Set up the memory shared between the Window Server and the kernel:
 * wired kernel memory, a region of the same size in the task's map, and
 * the kernel pages entered into the task's pmap.
 */
kern_return_t
createEventShmem(task, size, owner, owner_addr, shmem_addr)
	port_t		task;
	vm_size_t	size;
	struct vm_map	**owner;
	vm_offset_t	*owner_addr;
	vm_offset_t	*shmem_addr;
{
	vm_offset_t	off;
	vm_offset_t	phys_addr;
	kern_return_t	krtn;
	vm_map_t	task_map;
	kern_port_t	task_port;
	vm_size_t	shmem_size;
	extern vm_map_t convert_port_to_map();

	*owner = VM_MAP_NULL;
	if ((task_port = (kern_port_t)IOGetKernPort(task)) == KERN_PORT_NULL)
		return KERN_INVALID_ARGUMENT;
	if ((task_map = convert_port_to_map(task_port)) == VM_MAP_NULL) {
		port_release(task_port);
		return KERN_INVALID_ARGUMENT;
	}
	port_release(task_port);

	shmem_size = round_page(size);

	if (kmem_alloc_wired(kernel_map, shmem_addr, shmem_size)) {
		vm_map_deallocate(task_map);
		return KERN_NO_SPACE;
	}
	*owner_addr = vm_map_min(task_map);
	krtn = vm_map_find(task_map, VM_OBJECT_NULL, 0, owner_addr,
	    shmem_size, TRUE);
	if (krtn) {
		IOLog("createEventShmem: vm_map_find() returned %d\n", krtn);
		vm_map_deallocate(task_map);
		return KERN_NO_SPACE;
	}
	for (off = 0; off < shmem_size; off += PAGE_SIZE) {
		phys_addr = pmap_extract(kernel_pmap, (*shmem_addr) + off);
		if (phys_addr == 0) {
			IOLog("createEventShmem: no paddr for vaddr 0x%x\n",
			    (*shmem_addr) + off);
			kmem_free(kernel_map, *shmem_addr, size);
			vm_map_deallocate(task_map);
			return KERN_NO_SPACE;
		}
		pmap_enter(task_map->pmap, *owner_addr + off, phys_addr,
		    VM_PROT_READ|VM_PROT_WRITE, TRUE);
	}
	*owner = task_map;

	return KERN_SUCCESS;
}

/*
 * Unmap the shared memory area and release the wired memory.
 */
kern_return_t
destroyEventShmem(task, owner, size, owner_addr, shmem_addr)
	port_t		task;
	struct vm_map	*owner;
	vm_size_t	size;
	vm_offset_t	owner_addr;
	vm_offset_t	shmem_addr;
{
	vm_offset_t	off;
	kern_return_t	krtn;
	vm_size_t	shmem_size;

	if (owner == VM_MAP_NULL)
		return KERN_INVALID_ARGUMENT;
	shmem_size = round_page(size);

	for (off = 0; off < shmem_size; off += PAGE_SIZE) {
		pmap_remove(owner->pmap, owner_addr + off,
		    owner_addr + off + PAGE_SIZE);
	}
	krtn = vm_map_remove(owner, owner_addr, owner_addr + shmem_size);
	if (krtn) {
		IOLog("destroyEventShmem: vm_map_remove() returned %d\n",
		    krtn);
	}
	kmem_free(kernel_map, shmem_addr, shmem_size);

	vm_map_deallocate(owner);
	return krtn;
}
