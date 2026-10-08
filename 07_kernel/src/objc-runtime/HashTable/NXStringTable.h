/*
 * NXStringTable.h (plan 359).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047, D049).
 * The text is nearly the same as Darwin 0.1 objc-1 NXStringTable.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_NXSTRINGTABLE_H_
#define _OBJC_NXSTRINGTABLE_H_

#import "HashTable.h"

#define MAX_NXSTRINGTABLE_LENGTH	1024

@interface NXStringTable: HashTable

- init;
- free;
    
- (const char *)valueForStringKey:(const char *)aString;
    
- readFromStream:(NXStream *)stream;
- readFromFile:(const char *)fileName;

- writeToStream:(NXStream *)stream;
- writeToFile:(const char *)fileName;

/*
 * The following new... methods are now obsolete.  They remain in this 
 * interface file for backward compatibility only.  Use Object's alloc method 
 * and the init method defined in this class to create an NXStringTable and
 * the readFrom... methods to fill it with data.
 */

+ new;
+ newFromStream:(NXStream *)stream;
+ newFromFile:(const char *)fileName;

@end

static inline const char *NXSTR(NXStringTable *table, const char *key) {
    return [table valueForStringKey:key];
}

#endif /* _OBJC_NXSTRINGTABLE_H_ */
