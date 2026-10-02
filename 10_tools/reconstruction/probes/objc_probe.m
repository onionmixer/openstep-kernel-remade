/* objc_probe.m -- probe: class, ivars, class/instance methods, a category. */
#import <objc/Object.h>

@interface KRProbe : Object
{
    int kr_a;
    char *kr_b;
}
+ new;
- (int)a;
- setA:(int)v;
@end

@implementation KRProbe
+ new
{
    return [super new];
}
- (int)a
{
    return kr_a;
}
- setA:(int)v
{
    kr_a = v;
    return self;
}
@end

@interface KRProbe (KRCat)
- (int)twice;
@end

@implementation KRProbe (KRCat)
- (int)twice
{
    return kr_a * 2;
}
@end
