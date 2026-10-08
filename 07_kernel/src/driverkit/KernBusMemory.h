/*
 * driverkit/KernBusMemory.h - kernel-private header (plan 345, D030).
 *
 * Needed by the libDriver bus and display modules (plan 345) and earlier driverkit objects, whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernBusMemory.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <driverkit/KernBus.h>
#import <driverkit/driverTypes.h>

#import <mach/mach_types.h>

@interface KernBusMemoryRange : KernBusRange
{
@private
}

- mapToAddress: (vm_offset_t)destAddr
	inTarget: (task_t)task
	cache: (IOCache)cache;
- mapInTarget: (task_t)task
	cache: (IOCache)cache;

@end

@interface KernBusMemoryRangeMapping : KernBusRangeMapping
{
@private
    task_t		_task;
    vm_offset_t		_address;
}

- initWithRange: range
	subRange: (Range)subRange
	atAddress: (vm_offset_t)destAddr
	inTarget: (task_t)task
	cache: (IOCache)cache;
- initWithRange: range
	subRange: (Range)subRange
	inTarget: (task_t)task
	cache: (IOCache)cache;
	
- (task_t)task;
- (vm_offset_t)address;

@end

/*
 * This primative is used to
 * create wired down mappings
 * in a task pmap.  It bypasses
 * the MACH VM system.
 * It should be totally private,
 * but may be needed by some
 * poorly behaved clients.
 */

kern_return_t	_KernBusMemoryCreateMapping(
		    vm_offset_t		physAddr,
		    vm_size_t		length,
		    vm_offset_t		*destAddr,
		    task_t		task,
		    BOOL		findSpace,
		    IOCache		cache);

#endif	/* DRIVER_PRIVATE */
