/*
 * driverkit/KernBusPrivate.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernBusPrivate.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	KERNEL_PRIVATE

@interface KernBusItemResource(Private)

- _destroyItem: object;

@end

typedef struct KernBusItem_ {
    @defs(KernBusItem)
} KernBusItem_;

@interface KernBusRangeResource(Private)

- _destroyRange: object;

@end

typedef struct KernBusRange_ {
    @defs(KernBusRange)
} KernBusRange_;

@interface KernBusRange(Private)

- _addMapping;
- _destroyMapping: object;

@end

@interface KernBus(Private)

- (void)_resourceActive;
- (void)_resourceInactive;

@end

#endif
