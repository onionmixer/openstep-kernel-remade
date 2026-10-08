/*
 * driverkit/KernLock.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernLock.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	KERNEL_PRIVATE

#import <objc/Object.h>

@interface KernLock : Object
{
@private
    void		*_slock;
    int			_lockLevel, _savedLevel;
}

- initWithLevel: (int)level;

- (void)acquire;
- (void)release;

- (int)level;

@end

void
KernLockAcquire(
	KernLock	*lock
);
void
KernLockRelease(
	KernLock	*lock
);

#endif
