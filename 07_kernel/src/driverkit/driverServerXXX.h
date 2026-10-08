/*
 * driverkit/driverServerXXX.h - kernel-private header (plan 344, D030).
 *
 * Needed by the kernel-tree MIG server driverkit/driverServerServer.c and earlier driverkit objects, whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * kernel/driverkit/driverServerXXX.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#ifdef	DRIVER_PRIVATE

#import <mach/mach_types.h>

typedef struct KernDevice *	kernDevice_p;

kernDevice_p	convert_port_to_dev(port_t	port);

#endif	/* DRIVER_PRIVATE */
