/*
 * NXConditionLock.m - kernel NXConditionLock (plan 298).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/NXConditionLock.m", methods 0x1a8ddc-0x1a8fd4).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/NXConditionLock.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define KERNEL		1
#define KERNEL_PRIVATE	1
#define ARCH_PRIVATE	1 
#undef	MACH_USER_API

#import <machkit/NXLock.h>
#import <kern/sched_prim.h>
#import <kernserv/lock.h>

/*
 * _priv instance variable points to one of these.
 */
struct _priv {
    simple_lock_t	spin_lock;
    lock_t		sleep_lock;
    int			conditionVar;
};

@implementation NXConditionLock

- init
{
    return [self initWith:0];
}

- initWith : (int)condition
{
	struct _priv	*p = _priv;
	
	[super init];
	
	if (p == 0) {
	    p = (struct _priv *)kalloc(sizeof (struct _priv));
	    p->spin_lock = simple_lock_alloc();
	    p->sleep_lock = lock_alloc();

	    _priv = p;
	}

	simple_lock_init(p->spin_lock);
	lock_init(p->sleep_lock, TRUE);
	p->conditionVar = condition;

	return self;
}

- (int) condition
{
	struct _priv	*p = _priv;

	return (p->conditionVar);
}

- free
{
	struct _priv	*p = _priv;

	if (p) {
	    lock_free(p->sleep_lock);
	    simple_lock_free(p->spin_lock);
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

	thread_wakeup_one(&p->conditionVar);
	lock_done(p->sleep_lock);

	return self;
}

- lockWhen : (int)condition
{
	struct _priv	*p = _priv;
		
	/*
	 * First acquire ownership of the entire object.
	 */
	lock_write(p->sleep_lock); 
	while (condition != p->conditionVar) {
	
		/*
		 * Need to hold a simple_lock when we call thread_sleep().
		 * Both _spin_lock and sleep_lock must be held to 
		 * change _conditionVar.
		 */
		simple_lock(p->spin_lock);
		lock_done(p->sleep_lock);
		
		/*
		 * this is the critical section on a multi in which
		 * another thread could hold _sleep_lock, but they 
		 * can't change _conditionVar. Holding _spin_lock here
		 * (until after assert_wait() is called from 
		 * thread_sleep()) ensures that we'll be notified
		 * of changes in _conditionVar.
		 */
		thread_sleep((void *)&p->conditionVar, p->spin_lock, FALSE); 
		lock_write(p->sleep_lock);
	}

	return self;
}

- unlockWith : (int)condition
{
	struct _priv	*p = _priv;

	/*
	 * _sleep_lock held, but not _spin_lock.
	 */
	simple_lock(p->spin_lock);
	p->conditionVar = condition;
	simple_unlock(p->spin_lock);
	thread_wakeup_one(&p->conditionVar);
	lock_done(p->sleep_lock);

	return self;
}

@end
