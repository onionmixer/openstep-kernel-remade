/*
 * libDriver/Kernel/portFuncs.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/portFuncs.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_user_internal.h>
#import <mach/mach_interface.h>

#import <kernserv/prototypes.h>		// task_self
#import <driverkit/generalFuncs.h>

/*
 * Allocate a port.
 */
static inline port_t allocatePort(void)
{
    kern_return_t krtn;
    port_t aPort;
    
    krtn = port_allocate(task_self(), &aPort);
    if (krtn) {
	IOLog("Audio: port_allocate");
	//IOPanic("allocatePort");
    }
    return aPort;
}

/*
 * Deallocate a port.
 */
static inline void deallocatePort(port_t aPort)
{
    kern_return_t krtn;

    krtn = port_deallocate(task_self(), aPort);
    if (krtn) {
	IOLog("Audio: port_deallocate\n" );
	//IOPanic("deallocatePort");
    }
}

/*
 * Add a port to a port set.
 */
static inline void addPort(port_t aPortSet, port_t aPort)
{
    kern_return_t krtn;

    krtn = port_set_add(task_self(), aPortSet, aPort);
    if (krtn) {
	IOLog("Audio: port_set_add\n" );
	//IOPanic("addPort");
    }
}

/*
 * Allocate a port set.
 */
static inline port_t allocatePortSet(void)
{
    kern_return_t krtn;
    port_set_name_t aPortSet;

    krtn = port_set_allocate(task_self(), &aPortSet);
    if (krtn) {
	IOLog("Audio: port_set_allocate: %d\n", krtn);
	//IOPanic("allocatePortSet");
    }
    return aPortSet;
}
