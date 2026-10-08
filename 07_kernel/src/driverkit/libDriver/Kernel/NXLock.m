/*
 * NXLock.m - kernel NXLock (plan 298).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/NXLock.m", methods 0x1a8fd8-0x1a90b6).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/NXLock.m; kept as project-authored
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
    lock_t		sleep_lock;
};

@implementation NXLock 

- init
{
	struct _priv	*p = _priv;
	
	[super init];

	if (p == 0) {
	    p = (struct _priv *)kalloc(sizeof (struct _priv));
	    p->sleep_lock = lock_alloc();	

	    _priv = p;
	}
	
	lock_init(p->sleep_lock, TRUE);

	return self;
}

- free
{
	struct _priv	*p = _priv;

	if (p) {
	    lock_free(p->sleep_lock);
	    kfree(p, sizeof (struct _priv));
	}

	return [super free];
}


- lock 
{
	struct _priv	*p = _priv;

	lock_write(p->sleep_lock);

	return self;
}

- unlock 
{
	struct _priv	*p = _priv;

	lock_done(p->sleep_lock); 

	return self;
}

@end
