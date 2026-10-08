/*
 * driverkit/KernBus.h - kernel-private header (plan 345, D030).
 *
 * Needed by the libDriver bus and display modules (plan 345) and earlier driverkit objects, whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernBus.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <objc/Object.h>

#import <mach/mach_types.h>

/*
 * The item object can be used to
 * allocate a small number (max 1024)
 * of items { base, base + count },
 * individually.  The only
 * constraint placed upon this
 * range is that it may not
 * wrap around.
 */

@interface KernBusItemResource : Object
{
@private
    id			_owner;
    unsigned int	_count;
    unsigned int	_base;
    id			_kind;
    int			_itemCount;
    void		*_items;
}

- initWithItemCount: (unsigned int)count
	    itemBase: (unsigned int)base
	    itemKind: kind
	    owner: owner;
- initWithItemCount: (unsigned int)count
	    itemKind: kind
	    owner: owner;

- reserveItem: (unsigned int)item;
- shareItem: (unsigned int)item;

- (unsigned int)findFreeItem;

@end

@interface KernBusItem : Object
{
@private
    id			_resource;
    unsigned int	_item;
    int			_useCount;
    BOOL		_shareable;
}

- initForResource: resource
	    item: (unsigned int)item
	    shareable: (BOOL)shareable;
- dealloc;

- share;
- (unsigned int)item;

@end

/*
 * The range object is used to allocate
 * ranges of values in a large,
 * potentially sparse address space.
 * It does support the full range
 * of address values, where a full
 * range {0, maxunsigned int + 1} is
 * denoted as (Range) { 0, 0 }.
 */

typedef struct _Range {
    unsigned int	base;
    unsigned int	length;
} Range;

#define	RangeMAX	((Range) { 0, 0 })

static __inline__
BOOL
rangeIsValid(
    Range	range
)
{
    unsigned int	end = range.base + range.length;
    
    if (end > 0 && end <= range.base)
    	return NO;
	
    return YES;
}

@interface KernBusRangeResource : Object
{
@private
    id			_owner;
    unsigned int	_base;
    unsigned int	_end;
    id			_kind;
    int			_rangeCount;
    void		*_ranges;
}

- initWithExtent: (Range)extent
	    kind: kind
	    owner: owner;

- reserveRange: (Range)range;
- shareRange: (Range)range;

- (Range)findFreeRangeWithSize:(unsigned int)size
	 alignment:(unsigned int)align;

@end

@interface KernBusRange : Object
{
@private
    void		*_next;
    id			_resource;
    unsigned int	_base;
    unsigned int	_end;
    int			_useCount;
    BOOL		_shareable;    
    int			_mappingCount;
}

- initForResource: resource
	    range: (Range)range
	    shareable: (BOOL)shareable;    
- dealloc;

- share;
- (Range)range;

@end

/*
 * A mapping is basically an
 * an alias for a range.
 * Multiple mappings for a
 * particular range can be
 * created, and each one
 * can refer either to the
 * entire range, or only a
 * portion of it.
 */

@interface KernBusRangeMapping : Object
{
@private
    id			_range;
    Range		_mappedRange;
}

- initWithRange: range
	subRange: (Range)subRange;
	
- (Range)mappedRange;
	
@end

/*
 * The generic bus object is
 * available for subclassing by
 * specific bus architectures.
 * The bus object defines the
 * system resources (interrupt
 * sources, dma channels,
 * physical memory regions,
 * io port ranges), which
 * need to be allocated among
 * the device drivers.
 */

@interface KernBus : Object
{
@private
    void		*_resources;
    int			_activeResourceCount;
    int			_busId;
}

- (BOOL)areResourcesActive;

/*
 * Returns a NULL-terminated array of the names of resources
 * defined by this bus.
 */
- (const char **)resourceNames;

/*
 * Creates a KernDeviceDescription from an IOConfigTable.
 */
+ deviceDescriptionFromConfigTable:table;

/*
 * Allocates resource objects for a device description.
 * Returns the device description.
 */
- allocateResourcesForDeviceDescription:descr;

- _insertResource: object withKey: (const char *)key;
- _deleteResourceWithKey: (const char *)key;
- _lookupResourceWithKey: (const char *)key;

+ registerBusClass:busClass name:(char *)name;
+ registerBusInstance:busInstance name:(char *)busName  busId:(int)index;
+ lookupBusClassWithName:(char *)name;
+ lookupBusInstanceWithName:(char *)busName busId:(int)index;

/*
 * Returns NO if the bus does not want to configure the driver.
 */
+ (BOOL)configureDriverWithTable:configTable;

- (int)busId;
- (void)setBusId:(int)busId;

/*
 * Called when bus is detected, before drivers are probed
 */
+ (BOOL)probeBus:configTable;

@end

/*
 * Classes which implement
 * hardware bus interrupts
 * must adopt this protocol.
 */

@protocol KernBusInterrupt

- attachDeviceInterrupt: deviceInterrupt;
- attachDeviceInterrupt: deviceInterrupt
		atLevel: (int)level;
- detachDeviceInterrupt: deviceInterrupt;

- suspend;
- resume;

@end

#endif	/* DRIVER_PRIVATE */
