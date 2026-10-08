/*
 * bsd/dev/i386/EventShmemLock.s (plan 363).
 *
 * Kernel event-system shared memory locks (ev_lock, ev_unlock,
 * ev_try_lock) of the OPENSTEP 4.2 kernel, text 0x1a0d4c-0x1a0d8d; the
 * code is in bsd/dev/i386/EventShmemLock.h.  The text is nearly the same
 * as Darwin 0.1 kernel/bsd/dev/i386/EventShmemLock.s (body verbatim, head
 * comment replaced); kept as project-authored under D030, without
 * Darwin's notices (license judgement: D017).
 */

#import	<bsd/dev/i386/EventShmemLock.h>
