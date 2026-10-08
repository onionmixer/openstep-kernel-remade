/*
 * libDriver/Kernel/snd_server.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/snd_server.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>

extern boolean_t snd_server(msg_header_t *InHeadP, msg_header_t *OutHeadP);
