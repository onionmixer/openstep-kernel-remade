/*
 * List.h (plan 358).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 List.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_LIST_H_
#define _OBJC_LIST_H_

#import "Object.h"
#import "typedstream.h"

@interface List : Object
{
@public
    id 		*dataPtr;	/* data of the List object */
    unsigned 	numElements;	/* Actual number of elements */
    unsigned 	maxElements;	/* Total allocated elements */
}

/* Creating, freeing */

- free;
- freeObjects;
- copyFromZone:(NXZone *)zone;
  
/* Initializing */

- init;
- initCount:(unsigned)numSlots;

/* Comparing two lists */

- (BOOL)isEqual: anObject;
  
/* Managing the storage capacity */

- (unsigned)capacity;
- setAvailableCapacity:(unsigned)numSlots;

/* Manipulating objects by index */

- (unsigned)count;
- objectAt:(unsigned)index;
- lastObject;
- addObject:anObject;
- insertObject:anObject at:(unsigned)index;
- removeObjectAt:(unsigned)index;
- removeLastObject;
- replaceObjectAt:(unsigned)index with:newObject;
- appendList: (List *)otherList;

/* Manipulating objects by id */

- (unsigned)indexOf:anObject;
- addObjectIfAbsent:anObject;
- removeObject:anObject;
- replaceObject:anObject with:newObject;

/* Emptying the list */

- empty;

/* Archiving */

- write:(NXTypedStream *)stream;
- read:(NXTypedStream *)stream;

/* Sending messages to elements of the list */

- makeObjectsPerform:(SEL)aSelector;
- makeObjectsPerform:(SEL)aSelector with:anObject;

/*
 * The following new... methods are now obsolete.  They remain in this 
 * interface file for backward compatibility only.  Use Object's alloc method 
 * and the init... methods defined in this class instead.
 */

+ new;
+ newCount:(unsigned)numSlots;

@end

typedef struct {
    @defs(List)
} NXListId;

#define NX_ADDRESS(x) (((NXListId *)(x))->dataPtr)

#define NX_NOT_IN_LIST	0xffffffff

#endif /* _OBJC_LIST_H_ */
