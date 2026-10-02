/* objc_a.m -- T-ObjC material: a class, a subclass of it, shared selectors. */
#import <objc/Object.h>

@interface KRBase : Object
{
    int kr_x;
}
- (int)x;
- setX:(int)v;
+ make;
@end

@implementation KRBase
- (int)x
{
    return kr_x;
}
- setX:(int)v
{
    kr_x = v;
    return self;
}
+ make
{
    return [[self new] setX:1];
}
@end

@interface KRSub : KRBase
{
    char *kr_name;
}
- (int)twiceX;
@end

@implementation KRSub
- (int)twiceX
{
    return [self x] * 2;
}
@end
