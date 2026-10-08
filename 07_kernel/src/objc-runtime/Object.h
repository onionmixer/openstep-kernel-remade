/*
 * Object.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 Object.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_OBJECT_H_
#define _OBJC_OBJECT_H_

#import "objc.h"
#import "objc-class.h"
#import "typedstream.h"
#import <objc/zone.h>
@class Protocol;

@interface Object
{
	Class isa;	/* A pointer to the instance's class structure */
}

/* Initializing classes and instances */

+ initialize;
- init;

/* Creating, copying, and freeing instances */

+ new;
+ free;
- free;
+ alloc;
- copy;
+ allocFromZone:(NXZone *)zone;
- copyFromZone:(NXZone *)zone;
- (NXZone *)zone;

/* Identifying classes */

+ class;
+ superclass;
+ (const char *) name;
- class;
- superclass;
- (const char *) name;

/* Identifying and comparing instances */

- self;
- (unsigned int) hash;
- (BOOL) isEqual:anObject;

/* Testing inheritance relationships */

- (BOOL) isKindOf: aClassObject;
- (BOOL) isMemberOf: aClassObject;
- (BOOL) isKindOfClassNamed: (const char *)aClassName;
- (BOOL) isMemberOfClassNamed: (const char *)aClassName;

/* Testing class functionality */

+ (BOOL) instancesRespondTo:(SEL)aSelector;
- (BOOL) respondsTo:(SEL)aSelector;

/* Testing protocol conformance */

- (BOOL) conformsTo: (Protocol *)aProtocolObject;
+ (BOOL) conformsTo: (Protocol *)aProtocolObject;

/* Obtaining method descriptors from protocols */

- (struct objc_method_description *) descriptionForMethod:(SEL)aSel;
+ (struct objc_method_description *) descriptionForInstanceMethod:(SEL)aSel;

/* Obtaining method handles */

- (IMP) methodFor:(SEL)aSelector;
+ (IMP) instanceMethodFor:(SEL)aSelector;

/* Sending messages determined at run time */

- perform:(SEL)aSelector;
- perform:(SEL)aSelector with:anObject;
- perform:(SEL)aSelector with:object1 with:object2;

/* Posing */

+ poseAs: aClassObject;

/* Enforcing intentions */
 
- subclassResponsibility:(SEL)aSelector;
- notImplemented:(SEL)aSelector;

/* Error handling */

- doesNotRecognize:(SEL)aSelector;
- error:(const char *)aString, ...;

/* Debugging */

- (void) printForDebugger:(NXStream *)stream;

/* Archiving */

- awake;
- write:(NXTypedStream *)stream;
- read:(NXTypedStream *)stream;
+ (int) version;
+ setVersion: (int) aVersion;

/* Forwarding */

- forward: (SEL)sel : (marg_list)args;
- performv: (SEL)sel : (marg_list)args;

@end

/* Abstract Protocol for Archiving */

@interface Object (Archiving)

- startArchiving: (NXTypedStream *)stream;
- finishUnarchiving;

@end

/* Abstract Protocol for Dynamic Loading */

@interface Object (DynamicLoading)

+ finishLoading:(struct mach_header *)header;
+ startUnloading;

@end

extern id object_dispose(Object *anObject);
extern id object_copy(Object *anObject, unsigned nBytes);
extern id object_copyFromZone(Object *anObject, unsigned nBytes, NXZone *);
extern id object_realloc(Object *anObject, unsigned nBytes);
extern id object_reallocFromZone(Object *anObject, unsigned nBytes, NXZone *);

extern Ivar object_setInstanceVariable(id, const char *name, void *);
extern Ivar object_getInstanceVariable(id, const char *name, void **);

#endif /* _OBJC_OBJECT_H_ */
