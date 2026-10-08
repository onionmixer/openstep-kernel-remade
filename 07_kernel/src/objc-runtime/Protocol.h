/*
 * Protocol.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 Protocol.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_PROTOCOL_H_
#define _OBJC_PROTOCOL_H_

#import "Object.h"

struct objc_method_description {
	SEL name;
	char *types;
};
struct objc_method_description_list {
        int count;
        struct objc_method_description list[1];
};

@interface Protocol : Object
{
@private
	char *protocol_name;
 	struct objc_protocol_list *protocol_list;
  	struct objc_method_description_list *instance_methods, *class_methods; 
}

/* Obtaining attributes intrinsic to the protocol */

- (const char *)name;

/* Testing protocol conformance */

- (BOOL) conformsTo: (Protocol *)aProtocolObject;

/* Looking up information specific to a protocol */

- (struct objc_method_description *) descriptionForInstanceMethod:(SEL)aSel;
- (struct objc_method_description *) descriptionForClassMethod:(SEL)aSel;

@end

#endif /* _OBJC_PROTOCOL_H_ */
