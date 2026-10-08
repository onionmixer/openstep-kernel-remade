/*
 * machdepFuncs.c - IOBreakToDebugger for i386 (plan 293).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original 0x1c88ec-0x1c88f3).  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/i386/machdepFuncs.m (the original has no
 * Objective-C module record for it, so it is built as C here); kept as
 * project-authored under D027/D030, without Darwin's notices (license
 * judgement: D017).
 */

#import <driverkit/return.h>
#import <driverkit/generalFuncs.h> 

void IOBreakToDebugger(void)
{
    asm volatile ("int3");
}

