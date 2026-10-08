/*
 * NXSpinLock.m - kernel NXSpinLock (plan 297).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/NXSpinLock.m", methods 0x1a8cf8-0x1a8dd8).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/NXSpinLock.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define KERNEL		1
#define KERNEL_PRIVATE	1
#define ARCH_PRIVATE	1 

#import <machkit/NXLock.h>
#import <kernserv/lock.h>

/*
 * _priv instance variable points to one of these.
 */
struct _priv {
    simple_lock_t		spin_lock;
};

@implementation NXSpinLock 

- init
{
	struct _priv	*p = _priv;
	
	[super init];

	if (p == 0) {	
	    p = (struct _priv *)kalloc(sizeof (struct _priv));
	    p->spin_lock = simple_lock_alloc();
	
	    _priv = p;
	}

	simple_lock_init(p->spin_lock);

	return self;
}

- free
{
	struct _priv	*p = _priv;

	if (p) {
	    simple_lock_free(p->spin_lock);
	    kfree(p, sizeof (struct _priv));
	}

	return [super free];
}


- lock
{
	struct _priv	*p = _priv;

	simple_lock(p->spin_lock);

	return self;
}

- unlock
{
	struct _priv	*p = _priv;

	simple_unlock(p->spin_lock);

	return self;
}

@end
