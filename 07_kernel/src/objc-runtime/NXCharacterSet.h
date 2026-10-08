/*
 * NXCharacterSet.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 NXCharacterSet.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_NXCHARACTERSET_H_
#define _OBJC_NXCHARACTERSET_H_

#import "Object.h"
#import <objc/zone.h>
#import "unichar.h"

// The NXCharacterSet class... This object stores a set of
// Unicode characters with an O(1) membership test.

@interface NXCharacterSet : Object {
    unsigned int *_bits;
    unsigned int _reserved;
}

- init;

- (BOOL)characterIsMember:(unichar)ch;

- addCharacters:(const unichar *)chars length:(unsigned)len;
- removeCharacters:(const unichar *)chars length:(unsigned)len;
- addRange:(unichar)from :(unichar)to;
- removeRange:(unichar)from :(unichar)to;

- unionWith:(const NXCharacterSet *)otherSet;
- intersectWith:(const NXCharacterSet *)otherSet;

- invert;

- copyFromZone:(NXZone *)zone;
- free;

- write:(NXTypedStream *)s;
- read:(NXTypedStream *)s;

@end

#endif /* _OBJC_NXCHARACTERSET_H_ */
