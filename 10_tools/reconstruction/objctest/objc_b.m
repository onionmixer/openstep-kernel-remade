/* objc_b.m -- T-ObjC material: class reference to KRBase, the same selectors
 * as objc_a.m (x, make), and a category. */
#import <objc/Object.h>

@interface KRBase : Object
{
    int kr_x;
}
- (int)x;
- setX:(int)v;
+ make;
@end

@interface KROther : Object
- (int)useBase;
@end

@implementation KROther
- (int)useBase
{
    id b = [KRBase make];
    return [b x];
}
@end

@interface KROther (KRCat2)
- (int)catMethod;
@end

@implementation KROther (KRCat2)
- (int)catMethod
{
    return [self useBase];
}
@end
