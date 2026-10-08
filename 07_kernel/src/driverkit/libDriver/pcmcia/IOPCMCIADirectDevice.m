/*
 * IOPCMCIADirectDevice.m (plan 345).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "pcmcia/IOPCMCIADirectDevice.m", 0x1c1cb8-0x1c2081).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/pcmcia/IOPCMCIADirectDevice.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define KERNEL_PRIVATE	1

#import <driverkit/i386/IOPCMCIADirectDevice.h>
#import <driverkit/IODirectDevicePrivate.h>

#import <driverkit/KernDeviceDescription.h>
/*
 * plan 345: driverkit/i386/PCMCIAKernBus.h is in no reference tree; the two
 * keys this file uses are defined here (the original strings are the key names).
 */
#define PCMCIA_SOCKET_LIST	"PCMCIA_SOCKET_LIST"
#define PCMCIA_WINDOW_LIST	"PCMCIA_WINDOW_LIST"
#import <driverkit/KernBusMemory.h>
#import <driverkit/KernDevice.h>
#import <driverkit/KernDeviceDescription.h>
/* plan 345: no driverkit/i386/PCMCIAPool.h (in no reference tree); build adaptation verified against the original */
#import <objc/List.h>
/* plan 345: declarations reconstructed from the original bytes (BOOL returns: test al,al) */
@interface Object(PCMCIAWindowDecl)
- (BOOL)memoryInterface;
- (BOOL)attributeMemory;
@end

#define ATTRIBUTE_MAPPING_KEY	"PCMCIA_DEVICE_ATTR_MAPPING"

@implementation IODirectDevice(IOPCMCIADirectDevice)

- (IOReturn) mapAttributeMemoryTo:(vm_address_t *) destAddr
			findSpace:(BOOL) findSpace
{
	struct _eisa_private		*private = _busPrivate;
	id				mapping, mappingList;
	id				resource;
	id				socketElement;
	id				memWindowElement, memWindow;
	id				windowList;
	Range				memRange;
	id				thePCMCIABus;
					
	thePCMCIABus = [KernBus lookupBusInstanceWithName:"PCMCIA" busId:0];
	
	if ([_deviceDescriptionDelegate
	    resourcesForKey:ATTRIBUTE_MAPPING_KEY]) {
		return IO_R_BUSY;
	}
	/* Get memory window */
	socketElement = [[_deviceDescriptionDelegate
	    resourcesForKey:PCMCIA_SOCKET_LIST] objectAt:0];
	if (socketElement == nil)
		return IO_R_RESOURCE;
	memWindowElement = [thePCMCIABus allocMemoryWindowForSocket:
	    [socketElement object]];
	if (memWindowElement == nil)
		return IO_R_RESOURCE;
	windowList = [_deviceDescriptionDelegate
	    resourcesForKey:PCMCIA_WINDOW_LIST];
	
	resource = [thePCMCIABus memoryRangeResource];
	
	if (findSpace)
		mapping =
		    [resource mapInTarget:current_task_EXTERNAL()
			      cache:NO];
	else
		mapping =
		    [resource mapToAddress:*destAddr
			      inTarget:current_task_EXTERNAL()
			      cache:NO];

	if (mapping == nil) {
		[memWindowElement free];
		return IO_R_NO_MEMORY;
	}
		
	*destAddr = [mapping address];

	mappingList = [[List alloc] initCount:1];
	[mappingList addObject:mapping];
	[_deviceDescriptionDelegate
	    setResources:mappingList forKey:ATTRIBUTE_MAPPING_KEY];

	memWindow = [memWindowElement object];
	memRange = [resource range];
	[memWindow setEnabled:NO];
	[memWindow setMemoryInterface:YES];
	[memWindow setAttributeMemory:YES];
	[memWindow setMapWithSize:memRange.length
		systemAddress:memRange.base cardAddress:0];
	[memWindow setEnabled:YES];
	[[memWindow socket] setMemoryInterface:YES];

	[windowList addObject:memWindowElement];

	return IO_R_SUCCESS;
}

- (void) unmapAttributeMemory
{
	struct _eisa_private		*private = _busPrivate;
	id				windowList;
	int				i;

	if ([_deviceDescriptionDelegate
	    resourcesForKey:ATTRIBUTE_MAPPING_KEY] == nil)
		return;

	/* Find the memory window */
	windowList = [_deviceDescriptionDelegate
	    resourcesForKey:PCMCIA_WINDOW_LIST];
	
	for (i=0; i < [windowList count]; i++) {
	    id window, windowElement;
	    
	    windowElement = [windowList objectAt:i];
	    window = [windowElement object];
	    if ([window memoryInterface] && [window attributeMemory]) {
		/* Right now there is only one attribute memory window allowed,
		 * so assume this is the right one.
		 */
		[window setAttributeMemory:NO];
		[window setEnabled:NO];
		[[window socket] setMemoryInterface:NO];
		[windowList removeObject:windowElement];
		[windowElement free];
		break;
	    }
	}
	
	/* This will free the mapping */
	[_deviceDescriptionDelegate
	    removeResourcesForKey:ATTRIBUTE_MAPPING_KEY];
}

@end

