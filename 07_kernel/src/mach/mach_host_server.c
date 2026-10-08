/* Module mach_host */

#define EXPORT_BOOLEAN
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/mig_support.h>
#include <ipc/ipc_port.h>

#ifndef	mig_internal
#define	mig_internal	static
#endif

#ifndef	mig_external
#define mig_external
#endif

#ifndef	TypeCheck
#define	TypeCheck 1
#endif

#ifndef	UseExternRCSId
#define	UseExternRCSId		1
#endif

#define msgh_request_port	msgh_remote_port
#define MACH_MSGH_BITS_REQUEST(bits)	MACH_MSGH_BITS_REMOTE(bits)
#define msgh_reply_port		msgh_local_port
#define MACH_MSGH_BITS_REPLY(bits)	MACH_MSGH_BITS_LOCAL(bits)

#include <mach/std_types.h>
#include <kern/ipc_kobject.h>
#include <kern/ipc_tt.h>
#include <kern/ipc_host.h>
#include <kern/task.h>
#include <kern/thread.h>
#include <kern/host.h>
#include <kern/processor.h>
#include <vm/vm_object.h>
#include <vm/vm_map.h>
#include <ipc/ipc_space.h>
#include <mach/mach_types.h>

/* Routine host_processors */
mig_internal void _Xhost_processors
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t processor_listType;
		processor_array_t processor_list;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_processors
		(host_t host_priv, processor_array_t *processor_list, mach_msg_type_number_t *processor_listCnt);

	static mach_msg_type_long_t processor_listType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	MACH_MSG_TYPE_PORT_SEND,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	mach_msg_type_number_t processor_listCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_processors(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), &OutP->processor_list, &processor_listCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->processor_listType = processor_listType;

	OutP->processor_listType.msgtl_number = processor_listCnt;
}

/* Routine host_info */
mig_internal void _Xhost_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t flavorType;
		int flavor;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t host_info_outType;
		natural_t host_info_out[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_info
		(host_t host, int flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t host_info_outType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	1024,
	};

	mach_msg_type_number_t host_info_outCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	host_info_outCnt = 1024;

	OutP->RetCode = host_info(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->flavor, OutP->host_info_out, &host_info_outCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->host_info_outType = host_info_outType;

	OutP->host_info_outType.msgtl_number = host_info_outCnt;
	OutP->Head.msgh_size = 44 + (4 * host_info_outCnt);
}

/* Routine processor_info */
mig_internal void _Xprocessor_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t flavorType;
		int flavor;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t hostType;
		ipc_port_t host;
		mach_msg_type_long_t processor_info_outType;
		natural_t processor_info_out[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_info
		(processor_t processor, int flavor, host_t *host, processor_info_t processor_info_out, mach_msg_type_number_t *processor_info_outCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t hostType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t processor_info_outType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	1024,
	};

	host_t host;
	mach_msg_type_number_t processor_info_outCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_info_outCnt = 1024;

	OutP->RetCode = processor_info(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port), In0P->flavor, &host, OutP->processor_info_out, &processor_info_outCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;

	OutP->hostType = hostType;

	OutP->host = convert_host_to_port(host);

	OutP->processor_info_outType = processor_info_outType;

	OutP->processor_info_outType.msgtl_number = processor_info_outCnt;
	OutP->Head.msgh_size = 52 + (4 * processor_info_outCnt);
}

/* Routine processor_start */
mig_internal void _Xprocessor_start
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_start
		(processor_t processor);

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_start(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port));
}

/* Routine processor_exit */
mig_internal void _Xprocessor_exit
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_exit
		(processor_t processor);

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_exit(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port));
}

/* Routine processor_control */
mig_internal void _Xprocessor_control
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_long_t processor_cmdType;
		natural_t processor_cmd[1024];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_control
		(processor_t processor, processor_info_t processor_cmd, mach_msg_type_number_t processor_cmdCnt);

	unsigned int msgh_size;

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 36) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->processor_cmdType.msgtl_header.msgt_inline != TRUE) ||
	    (In0P->processor_cmdType.msgtl_header.msgt_longform != TRUE) ||
	    (In0P->processor_cmdType.msgtl_name != 2) ||
	    (In0P->processor_cmdType.msgtl_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 36 + (4 * In0P->processor_cmdType.msgtl_number))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_control(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port), In0P->processor_cmd, In0P->processor_cmdType.msgtl_number);
}

/* Routine processor_set_default */
mig_internal void _Xprocessor_set_default
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t default_setType;
		ipc_port_t default_set;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_default
		(host_t host, processor_set_t *default_set);

	static mach_msg_type_t default_setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t default_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_set_default(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &default_set);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->default_setType = default_setType;

	OutP->default_set = convert_pset_name_to_port(default_set);
}

/* Routine processor_set_create */
mig_internal void _Xprocessor_set_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t new_setType;
		ipc_port_t new_set;
		mach_msg_type_t new_nameType;
		ipc_port_t new_name;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_create
		(host_t host, processor_set_t *new_set, processor_set_t *new_name);

	static mach_msg_type_t new_setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t new_nameType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t new_set;
	processor_set_t new_name;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_set_create(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &new_set, &new_name);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->new_setType = new_setType;

	OutP->new_set = convert_pset_to_port(new_set);

	OutP->new_nameType = new_nameType;

	OutP->new_name = convert_pset_name_to_port(new_name);
}

/* Routine processor_set_destroy */
mig_internal void _Xprocessor_set_destroy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_destroy
		(processor_set_t set);

	processor_set_t set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_destroy(set);
	pset_deallocate(set);
}

/* Routine processor_set_info */
mig_internal void _Xprocessor_set_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t flavorType;
		int flavor;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t hostType;
		ipc_port_t host;
		mach_msg_type_long_t info_outType;
		natural_t info_out[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_info
		(processor_set_t set_name, int flavor, host_t *host, processor_set_info_t info_out, mach_msg_type_number_t *info_outCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t hostType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t info_outType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	1024,
	};

	processor_set_t set_name;
	host_t host;
	mach_msg_type_number_t info_outCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	set_name = convert_port_to_pset_name((ipc_port_t) In0P->Head.msgh_request_port);

	info_outCnt = 1024;

	OutP->RetCode = processor_set_info(set_name, In0P->flavor, &host, OutP->info_out, &info_outCnt);
	pset_deallocate(set_name);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;

	OutP->hostType = hostType;

	OutP->host = convert_host_to_port(host);

	OutP->info_outType = info_outType;

	OutP->info_outType.msgtl_number = info_outCnt;
	OutP->Head.msgh_size = 52 + (4 * info_outCnt);
}

/* Routine processor_assign */
mig_internal void _Xprocessor_assign
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t new_setType;
		ipc_port_t new_set;
		mach_msg_type_t waitType;
		boolean_t wait;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_assign
		(processor_t processor, processor_set_t new_set, boolean_t wait);

	static mach_msg_type_t waitCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t new_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->new_setType.msgt_inline != TRUE) ||
	    (In0P->new_setType.msgt_longform != FALSE) ||
	    (In0P->new_setType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->new_setType.msgt_number != 1) ||
	    (In0P->new_setType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->waitType != * (int *) &waitCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	new_set = convert_port_to_pset(In0P->new_set);

	OutP->RetCode = processor_assign(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port), new_set, In0P->wait);
	pset_deallocate(new_set);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->new_set))
		ipc_port_release_send(In0P->new_set);
}

/* Routine processor_get_assignment */
mig_internal void _Xprocessor_get_assignment
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t assigned_setType;
		ipc_port_t assigned_set;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_get_assignment
		(processor_t processor, processor_set_t *assigned_set);

	static mach_msg_type_t assigned_setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t assigned_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = processor_get_assignment(convert_port_to_processor((ipc_port_t) In0P->Head.msgh_request_port), &assigned_set);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->assigned_setType = assigned_setType;

	OutP->assigned_set = convert_pset_name_to_port(assigned_set);
}

/* Routine thread_assign */
mig_internal void _Xthread_assign
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t new_setType;
		ipc_port_t new_set;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_assign
		(thread_t thread, processor_set_t new_set);

	thread_t thread;
	processor_set_t new_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->new_setType.msgt_inline != TRUE) ||
	    (In0P->new_setType.msgt_longform != FALSE) ||
	    (In0P->new_setType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->new_setType.msgt_number != 1) ||
	    (In0P->new_setType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	new_set = convert_port_to_pset(In0P->new_set);

	OutP->RetCode = thread_assign(thread, new_set);
	pset_deallocate(new_set);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->new_set))
		ipc_port_release_send(In0P->new_set);
}

/* Routine thread_assign_default */
mig_internal void _Xthread_assign_default
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_assign_default
		(thread_t thread);

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_assign_default(thread);
	thread_deallocate(thread);
}

/* Routine thread_get_assignment */
mig_internal void _Xthread_get_assignment
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t assigned_setType;
		ipc_port_t assigned_set;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_get_assignment
		(thread_t thread, processor_set_t *assigned_set);

	static mach_msg_type_t assigned_setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t thread;
	processor_set_t assigned_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_get_assignment(thread, &assigned_set);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->assigned_setType = assigned_setType;

	OutP->assigned_set = convert_pset_name_to_port(assigned_set);
}

/* Routine task_assign */
mig_internal void _Xtask_assign
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t new_setType;
		ipc_port_t new_set;
		mach_msg_type_t assign_threadsType;
		boolean_t assign_threads;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_assign
		(task_t task, processor_set_t new_set, boolean_t assign_threads);

	static mach_msg_type_t assign_threadsCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t task;
	processor_set_t new_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->new_setType.msgt_inline != TRUE) ||
	    (In0P->new_setType.msgt_longform != FALSE) ||
	    (In0P->new_setType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->new_setType.msgt_number != 1) ||
	    (In0P->new_setType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->assign_threadsType != * (int *) &assign_threadsCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	new_set = convert_port_to_pset(In0P->new_set);

	OutP->RetCode = task_assign(task, new_set, In0P->assign_threads);
	pset_deallocate(new_set);
	task_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->new_set))
		ipc_port_release_send(In0P->new_set);
}

/* Routine task_assign_default */
mig_internal void _Xtask_assign_default
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t assign_threadsType;
		boolean_t assign_threads;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_assign_default
		(task_t task, boolean_t assign_threads);

	static mach_msg_type_t assign_threadsCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->assign_threadsType != * (int *) &assign_threadsCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_assign_default(task, In0P->assign_threads);
	task_deallocate(task);
}

/* Routine task_get_assignment */
mig_internal void _Xtask_get_assignment
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t assigned_setType;
		ipc_port_t assigned_set;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_get_assignment
		(task_t task, processor_set_t *assigned_set);

	static mach_msg_type_t assigned_setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t task;
	processor_set_t assigned_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_get_assignment(task, &assigned_set);
	task_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->assigned_setType = assigned_setType;

	OutP->assigned_set = convert_pset_name_to_port(assigned_set);
}

/* Routine host_kernel_version */
mig_internal void _Xhost_kernel_version
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t kernel_versionType;
		kernel_version_t kernel_version;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_kernel_version
		(host_t host, kernel_version_t kernel_version);

	static mach_msg_type_long_t kernel_versionType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	12,
		/* msgtl_size = */	4096,
		/* msgtl_number = */	1,
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_kernel_version(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), OutP->kernel_version);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 556;

	OutP->kernel_versionType = kernel_versionType;
}

/* Routine thread_priority */
mig_internal void _Xthread_priority
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t priorityType;
		int priority;
		mach_msg_type_t set_maxType;
		boolean_t set_max;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_priority
		(thread_t thread, int priority, boolean_t set_max);

	static mach_msg_type_t priorityCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t set_maxCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->priorityType != * (int *) &priorityCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->set_maxType != * (int *) &set_maxCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_priority(thread, In0P->priority, In0P->set_max);
	thread_deallocate(thread);
}

/* Routine thread_max_priority */
mig_internal void _Xthread_max_priority
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t processor_setType;
		ipc_port_t processor_set;
		mach_msg_type_t max_priorityType;
		int max_priority;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_max_priority
		(thread_t thread, processor_set_t processor_set, int max_priority);

	static mach_msg_type_t max_priorityCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t thread;
	processor_set_t processor_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->processor_setType.msgt_inline != TRUE) ||
	    (In0P->processor_setType.msgt_longform != FALSE) ||
	    (In0P->processor_setType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->processor_setType.msgt_number != 1) ||
	    (In0P->processor_setType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->max_priorityType != * (int *) &max_priorityCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	processor_set = convert_port_to_pset(In0P->processor_set);

	OutP->RetCode = thread_max_priority(thread, processor_set, In0P->max_priority);
	pset_deallocate(processor_set);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->processor_set))
		ipc_port_release_send(In0P->processor_set);
}

/* Routine task_priority */
mig_internal void _Xtask_priority
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t priorityType;
		int priority;
		mach_msg_type_t change_threadsType;
		boolean_t change_threads;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_priority
		(task_t task, int priority, boolean_t change_threads);

	static mach_msg_type_t priorityCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t change_threadsCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->priorityType != * (int *) &priorityCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->change_threadsType != * (int *) &change_threadsCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_priority(task, In0P->priority, In0P->change_threads);
	task_deallocate(task);
}

/* Routine processor_set_max_priority */
mig_internal void _Xprocessor_set_max_priority
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t max_priorityType;
		int max_priority;
		mach_msg_type_t change_threadsType;
		boolean_t change_threads;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_max_priority
		(processor_set_t processor_set, int max_priority, boolean_t change_threads);

	static mach_msg_type_t max_priorityCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t change_threadsCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t processor_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->max_priorityType != * (int *) &max_priorityCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->change_threadsType != * (int *) &change_threadsCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_max_priority(processor_set, In0P->max_priority, In0P->change_threads);
	pset_deallocate(processor_set);
}

/* Routine thread_policy */
mig_internal void _Xthread_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t policyType;
		int policy;
		mach_msg_type_t dataType;
		int data;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_policy
		(thread_t thread, int policy, int data);

	static mach_msg_type_t policyCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t dataCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->policyType != * (int *) &policyCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->dataType != * (int *) &dataCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_policy(thread, In0P->policy, In0P->data);
	thread_deallocate(thread);
}

/* Routine processor_set_policy_enable */
mig_internal void _Xprocessor_set_policy_enable
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t policyType;
		int policy;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_policy_enable
		(processor_set_t processor_set, int policy);

	static mach_msg_type_t policyCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t processor_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->policyType != * (int *) &policyCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_policy_enable(processor_set, In0P->policy);
	pset_deallocate(processor_set);
}

/* Routine processor_set_policy_disable */
mig_internal void _Xprocessor_set_policy_disable
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t policyType;
		int policy;
		mach_msg_type_t change_threadsType;
		boolean_t change_threads;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_policy_disable
		(processor_set_t processor_set, int policy, boolean_t change_threads);

	static mach_msg_type_t policyCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t change_threadsCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t processor_set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->policyType != * (int *) &policyCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->change_threadsType != * (int *) &change_threadsCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_policy_disable(processor_set, In0P->policy, In0P->change_threads);
	pset_deallocate(processor_set);
}

/* Routine processor_set_tasks */
mig_internal void _Xprocessor_set_tasks
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t task_listType;
		task_array_t task_list;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_tasks
		(processor_set_t processor_set, task_array_t *task_list, mach_msg_type_number_t *task_listCnt);

	static mach_msg_type_long_t task_listType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	MACH_MSG_TYPE_PORT_SEND,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	processor_set_t processor_set;
	mach_msg_type_number_t task_listCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_tasks(processor_set, &OutP->task_list, &task_listCnt);
	pset_deallocate(processor_set);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->task_listType = task_listType;

	OutP->task_listType.msgtl_number = task_listCnt;
}

/* Routine processor_set_threads */
mig_internal void _Xprocessor_set_threads
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t thread_listType;
		thread_array_t thread_list;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t processor_set_threads
		(processor_set_t processor_set, thread_array_t *thread_list, mach_msg_type_number_t *thread_listCnt);

	static mach_msg_type_long_t thread_listType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	MACH_MSG_TYPE_PORT_SEND,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	processor_set_t processor_set;
	mach_msg_type_number_t thread_listCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	processor_set = convert_port_to_pset((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = processor_set_threads(processor_set, &OutP->thread_list, &thread_listCnt);
	pset_deallocate(processor_set);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->thread_listType = thread_listType;

	OutP->thread_listType.msgtl_number = thread_listCnt;
}

/* Routine host_processor_sets */
mig_internal void _Xhost_processor_sets
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t processor_setsType;
		processor_set_name_array_t processor_sets;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_processor_sets
		(host_t host, processor_set_name_array_t *processor_sets, mach_msg_type_number_t *processor_setsCnt);

	static mach_msg_type_long_t processor_setsType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	MACH_MSG_TYPE_PORT_SEND,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	mach_msg_type_number_t processor_setsCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_processor_sets(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &OutP->processor_sets, &processor_setsCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->processor_setsType = processor_setsType;

	OutP->processor_setsType.msgtl_number = processor_setsCnt;
}

/* Routine host_processor_set_priv */
mig_internal void _Xhost_processor_set_priv
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t set_nameType;
		ipc_port_t set_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t setType;
		ipc_port_t set;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_processor_set_priv
		(host_t host_priv, processor_set_t set_name, processor_set_t *set);

	static mach_msg_type_t setType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	processor_set_t set_name;
	processor_set_t set;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->set_nameType.msgt_inline != TRUE) ||
	    (In0P->set_nameType.msgt_longform != FALSE) ||
	    (In0P->set_nameType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->set_nameType.msgt_number != 1) ||
	    (In0P->set_nameType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	set_name = convert_port_to_pset_name(In0P->set_name);

	OutP->RetCode = host_processor_set_priv(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), set_name, &set);
	pset_deallocate(set_name);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->set_name))
		ipc_port_release_send(In0P->set_name);

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->setType = setType;

	OutP->set = convert_pset_to_port(set);
}

/* Routine thread_depress_abort */
mig_internal void _Xthread_depress_abort
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_depress_abort
		(thread_t thread);

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_depress_abort(thread);
	thread_deallocate(thread);
}

/* Routine host_set_time */
mig_internal void _Xhost_set_time
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t new_timeType;
		time_value_t new_time;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_set_time
		(host_t host_priv, time_value_t new_time);

	static mach_msg_type_t new_timeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 36) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->new_timeType != * (int *) &new_timeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_set_time(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), In0P->new_time);
}

/* Routine host_adjust_time */
mig_internal void _Xhost_adjust_time
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t new_adjustmentType;
		time_value_t new_adjustment;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t old_adjustmentType;
		time_value_t old_adjustment;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_adjust_time
		(host_t host_priv, time_value_t new_adjustment, time_value_t *old_adjustment);

	static mach_msg_type_t new_adjustmentCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t old_adjustmentType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 36) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->new_adjustmentType != * (int *) &new_adjustmentCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_adjust_time(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), In0P->new_adjustment, &OutP->old_adjustment);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 44;

	OutP->old_adjustmentType = old_adjustmentType;
}

/* Routine host_get_time */
mig_internal void _Xhost_get_time
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t current_timeType;
		time_value_t current_time;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t host_get_time
		(host_t host, time_value_t *current_time);

	static mach_msg_type_t current_timeType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = host_get_time(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &OutP->current_time);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 44;

	OutP->current_timeType = current_timeType;
}

static mig_routine_t mach_host_server_routines[] = {
		_Xhost_processors,
		_Xhost_info,
		_Xprocessor_info,
		_Xprocessor_start,
		_Xprocessor_exit,
		_Xprocessor_control,
		_Xprocessor_set_default,
		_Xprocessor_set_create,
		_Xprocessor_set_destroy,
		_Xprocessor_set_info,
		_Xprocessor_assign,
		_Xprocessor_get_assignment,
		_Xthread_assign,
		_Xthread_assign_default,
		_Xthread_get_assignment,
		_Xtask_assign,
		_Xtask_assign_default,
		_Xtask_get_assignment,
		_Xhost_kernel_version,
		_Xthread_priority,
		_Xthread_max_priority,
		_Xtask_priority,
		_Xprocessor_set_max_priority,
		_Xthread_policy,
		_Xprocessor_set_policy_enable,
		_Xprocessor_set_policy_disable,
		_Xprocessor_set_tasks,
		_Xprocessor_set_threads,
		_Xhost_processor_sets,
		_Xhost_processor_set_priv,
		_Xthread_depress_abort,
		_Xhost_set_time,
		_Xhost_adjust_time,
		_Xhost_get_time,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
};

mig_external boolean_t mach_host_server
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	register mach_msg_header_t *InP =  InHeadP;
	register mig_reply_header_t *OutP = (mig_reply_header_t *) OutHeadP;

	static mach_msg_type_t RetCodeType = {
		/* msgt_name = */		MACH_MSG_TYPE_INTEGER_32,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	register mig_routine_t routine;

	OutP->Head.msgh_bits = MACH_MSGH_BITS(MACH_MSGH_BITS_REPLY(InP->msgh_bits), 0);
	OutP->Head.msgh_size = sizeof *OutP;
	OutP->Head.msgh_remote_port = InP->msgh_reply_port;
	OutP->Head.msgh_local_port = MACH_PORT_NULL;
	OutP->Head.msgh_seqno = 0;
	OutP->Head.msgh_id = InP->msgh_id + 100;

	OutP->RetCodeType = RetCodeType;

	if ((InP->msgh_id > 2641) || (InP->msgh_id < 2600) ||
	    ((routine = mach_host_server_routines[InP->msgh_id - 2600]) == 0)) {
		OutP->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InP, &OutP->Head);
	return TRUE;
}

mig_external mig_routine_t mach_host_server_routine
	(const mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 2600;

	if ((msgh_id > 41) || (msgh_id < 0))
		return 0;

	return mach_host_server_routines[msgh_id];
}

