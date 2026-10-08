/*
 * driverkit/KernBusInterruptPrivate.h - kernel-private header (plan 346, D030).
 *
 * Needed by driverkit objects recorded earlier (plan 346 self-containment), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernBusInterruptPrivate.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

typedef struct KernBusInterrupt_ {
    @defs(KernBusInterrupt)
} KernBusInterrupt_;

#endif
