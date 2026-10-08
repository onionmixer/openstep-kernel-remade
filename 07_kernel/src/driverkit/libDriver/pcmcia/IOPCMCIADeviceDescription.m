/*
 * IOPCMCIADeviceDescription.m (plan 345).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "pcmcia/IOPCMCIADeviceDescription.m", 0x1c2084-0x1c2233).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/pcmcia/IOPCMCIADeviceDescription.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define KERNEL_PRIVATE	1

#import <driverkit/KernDeviceDescription.h>
#import <driverkit/i386/IOPCMCIADeviceDescription.h>
#import <driverkit/i386/IOPCMCIADeviceDescriptionPrivate.h>
#import <driverkit/IODeviceDescriptionPrivate.h>
#import <driverkit/i386/IOEISADeviceDescriptionPrivate.h>
#import <driverkit/i386/directDevice.h>
#import <driverkit/i386/IOPCMCIATuple.h>
#import <driverkit/i386/IOPCMCIATuplePrivate.h>
/*
 * plan 345: driverkit/i386/PCMCIAKernBus.h is in no reference tree; the key
 * this file uses is defined here (the original string is the key name).
 */
#define PCMCIA_TUPLE_LIST	"PCMCIA_TUPLE_LIST"

struct _pcmcia_private {
    unsigned	tupleCount;
    id		*tupleList;
};

@implementation IOPCMCIADeviceDescription(Private)

- _initWithDelegate: delegate
{
    struct _pcmcia_private *private;

    [super _initWithDelegate:delegate];
    private = _pcmcia_private = 
	(struct _pcmcia_private *)IOMalloc(sizeof(struct _pcmcia_private));
    private->tupleCount = 0;
    private->tupleList = NULL;
    return self;	
}

@end

@implementation IOPCMCIADeviceDescription

- free
{
    struct _pcmcia_private *private =
	(struct _pcmcia_private *)_pcmcia_private;

    if 	(private->tupleList) {
	int i;
	for (i=0; i < private->tupleCount; i++) {
	    [private->tupleList[i] free];
	}
	IOFree(private->tupleList, private->tupleCount * sizeof(id));
    }
    IOFree(private, sizeof(struct _pcmcia_private));
    return [super free];
}

- (unsigned) numTuples
{
    struct _pcmcia_private *private =
	(struct _pcmcia_private *)_pcmcia_private;

    if (private->tupleCount == 0) {
	(void)[self tupleList];
    }
    return private->tupleCount;
}

- (id *) tupleList
{
    struct _pcmcia_private *private = 
	(struct _pcmcia_private *)_pcmcia_private;
    id 	list;
    int i;

    if (private->tupleList == NULL) {
	list = [[self _delegate] resourcesForKey:PCMCIA_TUPLE_LIST];
	if (list) {
	    private->tupleCount = [list count];
	    private->tupleList = 
		(id *)IOMalloc(private->tupleCount * sizeof(id));
	    for (i=0; i<private->tupleCount; i++) {
		id ioTuple, tuple;

		tuple = [list objectAt:i];
		ioTuple = [[IOPCMCIATuple alloc] initWithKernTuple:tuple];
		private->tupleList[i] = ioTuple;
	    }
	}
    }
    return private->tupleList;
}

@end
