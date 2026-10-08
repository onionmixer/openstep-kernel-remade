#ifndef	_kern_serv_handler
#define	_kern_serv_handler

/* Module kern_serv */

#include <mach/kern_return.h>
#include <mach/port.h>
#include <mach/message.h>

#ifndef	mig_external
#define mig_external extern
#endif

#include <mach/std_types.h>
#include <kernserv/kern_server_types.h>

/*
 * Functions to call for handling returned messages.
 */
typedef struct kern_serv {
	void		*arg;		/* argument to pass to function */
	int		timeout;	/* timeout for RPC return msg_send */

	/* Routine instance_loc */
	kern_return_t (*instance_loc) (
		void *server_port,
		vm_address_t instance_loc);

	/* Routine boot_port */
	kern_return_t (*boot_port) (
		void *server_port,
		port_t boot_port);

	/* Routine wire_range */
	kern_return_t (*wire_range) (
		void *server_port,
		vm_address_t addr,
		vm_size_t size);

	/* Routine unwire_range */
	kern_return_t (*unwire_range) (
		void *server_port,
		vm_address_t addr,
		vm_size_t size);

	/* Routine port_proc */
	kern_return_t (*port_proc) (
		void *server_port,
		port_all_t port,
		port_map_proc_t proc,
		int argument);

	/* SimpleRoutine port_death_proc */
	kern_return_t (*port_death_proc) (
		void *server_port,
		port_death_proc_t proc);

	/* Routine call_proc */
	kern_return_t (*call_proc) (
		void *server_port,
		call_proc_t proc,
		int argument);

	/* SimpleRoutine shutdown */
	kern_return_t (*shutdown) (
		void *server_port);

	/* SimpleRoutine log_level */
	kern_return_t (*log_level) (
		void *server_port,
		int log_level);

	/* SimpleRoutine get_log */
	kern_return_t (*get_log) (
		void *server_port,
		port_t reply_port);

	/* Routine port_serv */
	kern_return_t (*port_serv) (
		void *server_port,
		port_all_t port,
		port_map_proc_t proc,
		int argument);

	/* Routine version */
	kern_return_t (*version) (
		void *server_port,
		int version);

	/* Routine load_objc */
	kern_return_t (*load_objc) (
		void *server_port,
		vm_address_t addr);
} kern_serv_t;


#define	kern_servMaxRequestSize	48
#define	kern_servMaxReplySize	32

/* Handler kern_serv_handler */
mig_external kern_return_t kern_serv_handler (
	msg_header_t *InHeadP,
	kern_serv_t *kern_serv);

#endif	_kern_serv_handler
