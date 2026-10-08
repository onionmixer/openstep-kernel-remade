/*
 * driverkit/KernDeviceDescription.h - kernel-private header (plan 345, D030).
 *
 * Needed by the libDriver bus and display modules (plan 345) and earlier driverkit objects, whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernDeviceDescription.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <objc/Object.h>
#import <objc/HashTable.h>
#import <driverkit/KernBus.h>

@interface KernDeviceDescription : Object
{
@private
    id		_configTable;
    id		_device;
    id		_resourceTable;
    id		_stringTable;
    id		_interruptList;
    id		_busClass;
    id		_bus;
    int		_busId;
}

- initFromConfigTable: configTable;
- configTable;

- setDevice: device;
- device;

- busClass;

- setBus: bus;
- bus;

- interrupts;

- allocateResourcesForKey:(const char *)aKey;

- allocateItems:(unsigned int *)aList numItems:(unsigned int)num
    forKey:(const char *)aKey;
- allocateRanges:(Range *)aList numRanges:(unsigned int)num
    forKey:(const char *)aKey;

- (const char *)stringForKey:(const char *)aKey;
- resourcesForKey:(const char *)aKey;

- setString:(const char *)aString forKey:(const char *)aKey;
- setResources:resources forKey:(const char *)aKey;

- (BOOL)removeStringForKey:(const char *)aKey;
- (BOOL)removeResourcesForKey:(const char *)aKey;

- (NXHashState)initStringState;
- (BOOL)nextStringState:(NXHashState *)aState key:(const char **)aKey 
	value:(char **)stringPtr;

- (NXHashState)initResourcesState;
- (BOOL)nextResourcesState:(NXHashState *)aState key:(const char **)aKey 
	value:(id *)resourcesPtr;

@end

#endif
