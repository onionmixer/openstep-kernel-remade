/* Module mach */

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

/* Routine task_create */
mig_internal void _Xtask_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t inherit_memoryType;
		boolean_t inherit_memory;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t child_taskType;
		ipc_port_t child_task;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_create
		(task_t target_task, boolean_t inherit_memory, task_t *child_task);

	static mach_msg_type_t inherit_memoryCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t child_taskType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;
	task_t child_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->inherit_memoryType != * (int *) &inherit_memoryCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_create(target_task, In0P->inherit_memory, &child_task);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->child_taskType = child_taskType;

	OutP->child_task = convert_task_to_port(child_task);
}

/* Routine task_terminate */
mig_internal void _Xtask_terminate
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
	mig_external kern_return_t task_terminate
		(task_t target_task);

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_terminate(target_task);
	task_deallocate(target_task);
}

/* Routine task_threads */
mig_internal void _Xtask_threads
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
	mig_external kern_return_t task_threads
		(task_t target_task, thread_array_t *thread_list, mach_msg_type_number_t *thread_listCnt);

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

	task_t target_task;
	mach_msg_type_number_t thread_listCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_threads(target_task, &OutP->thread_list, &thread_listCnt);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->thread_listType = thread_listType;

	OutP->thread_listType.msgtl_number = thread_listCnt;
}

/* Routine thread_terminate */
mig_internal void _Xthread_terminate
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
	mig_external kern_return_t thread_terminate
		(thread_t target_thread);

	thread_t target_thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_terminate(target_thread);
	thread_deallocate(target_thread);
}

/* Routine vm_allocate */
mig_internal void _Xvm_allocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t anywhereType;
		boolean_t anywhere;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t addressType;
		vm_address_t address;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_allocate
		(vm_map_t target_task, vm_address_t *address, vm_size_t size, boolean_t anywhere);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t anywhereCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t addressType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->anywhereType != * (int *) &anywhereCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_allocate(target_task, &In0P->address, In0P->size, In0P->anywhere);
	vm_map_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->addressType = addressType;

	OutP->address = In0P->address;
}

/* Routine vm_deallocate */
mig_internal void _Xvm_deallocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_deallocate
		(vm_map_t target_task, vm_address_t address, vm_size_t size);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_deallocate(target_task, In0P->address, In0P->size);
	vm_map_deallocate(target_task);
}

/* Routine vm_protect */
mig_internal void _Xvm_protect
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t set_maximumType;
		boolean_t set_maximum;
		mach_msg_type_t new_protectionType;
		vm_prot_t new_protection;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_protect
		(vm_map_t target_task, vm_address_t address, vm_size_t size, boolean_t set_maximum, vm_prot_t new_protection);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t set_maximumCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t new_protectionCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 56) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->set_maximumType != * (int *) &set_maximumCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->new_protectionType != * (int *) &new_protectionCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_protect(target_task, In0P->address, In0P->size, In0P->set_maximum, In0P->new_protection);
	vm_map_deallocate(target_task);
}

/* Routine vm_inherit */
mig_internal void _Xvm_inherit
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t new_inheritanceType;
		vm_inherit_t new_inheritance;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_inherit
		(vm_map_t target_task, vm_address_t address, vm_size_t size, vm_inherit_t new_inheritance);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t new_inheritanceCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->new_inheritanceType != * (int *) &new_inheritanceCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_inherit(target_task, In0P->address, In0P->size, In0P->new_inheritance);
	vm_map_deallocate(target_task);
}

/* Routine vm_read */
mig_internal void _Xvm_read
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t dataType;
		vm_offset_t data;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_read
		(vm_map_t target_task, vm_address_t address, vm_size_t size, vm_offset_t *data, mach_msg_type_number_t *dataCnt);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t dataType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	9,
		/* msgtl_size = */	8,
		/* msgtl_number = */	0,
	};

	vm_map_t target_task;
	mach_msg_type_number_t dataCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_read(target_task, In0P->address, In0P->size, &OutP->data, &dataCnt);
	vm_map_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->dataType = dataType;

	OutP->dataType.msgtl_number = dataCnt;
}

/* Routine vm_write */
mig_internal void _Xvm_write
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_long_t dataType;
		vm_offset_t data;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_write
		(vm_map_t target_task, vm_address_t address, vm_offset_t data, mach_msg_type_number_t dataCnt);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->dataType.msgtl_header.msgt_inline != FALSE) ||
	    (In0P->dataType.msgtl_header.msgt_longform != TRUE) ||
	    (In0P->dataType.msgtl_name != 9) ||
	    (In0P->dataType.msgtl_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_write(target_task, In0P->address, In0P->data, In0P->dataType.msgtl_number);
	vm_map_deallocate(target_task);
}

/* Routine vm_copy */
mig_internal void _Xvm_copy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t source_addressType;
		vm_address_t source_address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t dest_addressType;
		vm_address_t dest_address;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_copy
		(vm_map_t target_task, vm_address_t source_address, vm_size_t size, vm_address_t dest_address);

	static mach_msg_type_t source_addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t dest_addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->source_addressType != * (int *) &source_addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->dest_addressType != * (int *) &dest_addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_copy(target_task, In0P->source_address, In0P->size, In0P->dest_address);
	vm_map_deallocate(target_task);
}

/* Routine vm_region */
mig_internal void _Xvm_region
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t protectionType;
		vm_prot_t protection;
		mach_msg_type_t max_protectionType;
		vm_prot_t max_protection;
		mach_msg_type_t inheritanceType;
		vm_inherit_t inheritance;
		mach_msg_type_t is_sharedType;
		boolean_t is_shared;
		mach_msg_type_t object_nameType;
		ipc_port_t object_name;
		mach_msg_type_t offsetType;
		vm_offset_t offset;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_region
		(vm_map_t target_task, vm_address_t *address, vm_size_t *size, vm_prot_t *protection, vm_prot_t *max_protection, vm_inherit_t *inheritance, boolean_t *is_shared, ipc_port_t *object_name, vm_offset_t *offset);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t addressType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t protectionType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t max_protectionType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t inheritanceType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t is_sharedType = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t object_nameType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t offsetType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_region(target_task, &In0P->address, &OutP->size, &OutP->protection, &OutP->max_protection, &OutP->inheritance, &OutP->is_shared, &OutP->object_name, &OutP->offset);
	vm_map_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 96;

	OutP->addressType = addressType;

	OutP->address = In0P->address;

	OutP->sizeType = sizeType;

	OutP->protectionType = protectionType;

	OutP->max_protectionType = max_protectionType;

	OutP->inheritanceType = inheritanceType;

	OutP->is_sharedType = is_sharedType;

	OutP->object_nameType = object_nameType;

	OutP->offsetType = offsetType;
}

/* Routine vm_statistics */
mig_internal void _Xvm_statistics
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t vm_statsType;
		vm_statistics_data_t vm_stats;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_statistics
		(vm_map_t target_task, vm_statistics_data_t *vm_stats);

	static mach_msg_type_t vm_statsType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		13,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_statistics(target_task, &OutP->vm_stats);
	vm_map_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 88;

	OutP->vm_statsType = vm_statsType;
}

/* Routine task_by_unix_pid */
mig_internal void _Xtask_by_unix_pid
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t process_idType;
		int process_id;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t result_taskType;
		ipc_port_t result_task;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_by_unix_pid
		(task_t target_task, int process_id, task_t *result_task);

	static mach_msg_type_t process_idCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t result_taskType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;
	task_t result_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->process_idType != * (int *) &process_idCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_by_unix_pid(target_task, In0P->process_id, &result_task);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->result_taskType = result_taskType;

	OutP->result_task = convert_task_to_port(result_task);
}

/* Routine unix_pid */
mig_internal void _Xunix_pid
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t process_idType;
		int process_id;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t unix_pid
		(task_t target_task, int *process_id);

	static mach_msg_type_t process_idType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = unix_pid(target_task, &OutP->process_id);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->process_idType = process_idType;
}

/* Routine netipc_listen */
mig_internal void _Xnetipc_listen
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t src_addrType;
		int src_addr;
		mach_msg_type_t dst_addrType;
		int dst_addr;
		mach_msg_type_t src_portType;
		int src_port;
		mach_msg_type_t dst_portType;
		int dst_port;
		mach_msg_type_t protocolType;
		int protocol;
		mach_msg_type_t ipc_portType;
		ipc_port_t ipc_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t netipc_listen
		(ipc_port_t request_port, int src_addr, int dst_addr, int src_port, int dst_port, int protocol, ipc_port_t ipc_port);

	static mach_msg_type_t src_addrCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t dst_addrCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t src_portCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t dst_portCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t protocolCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 72) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->src_addrType != * (int *) &src_addrCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->dst_addrType != * (int *) &dst_addrCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->src_portType != * (int *) &src_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->dst_portType != * (int *) &dst_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->protocolType != * (int *) &protocolCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->ipc_portType.msgt_inline != TRUE) ||
	    (In0P->ipc_portType.msgt_longform != FALSE) ||
	    (In0P->ipc_portType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->ipc_portType.msgt_number != 1) ||
	    (In0P->ipc_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = netipc_listen((ipc_port_t) In0P->Head.msgh_request_port, In0P->src_addr, In0P->dst_addr, In0P->src_port, In0P->dst_port, In0P->protocol, In0P->ipc_port);
}

/* Routine netipc_ignore */
mig_internal void _Xnetipc_ignore
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t ipc_portType;
		ipc_port_t ipc_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t netipc_ignore
		(ipc_port_t request_port, ipc_port_t ipc_port);

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->ipc_portType.msgt_inline != TRUE) ||
	    (In0P->ipc_portType.msgt_longform != FALSE) ||
	    (In0P->ipc_portType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->ipc_portType.msgt_number != 1) ||
	    (In0P->ipc_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = netipc_ignore((ipc_port_t) In0P->Head.msgh_request_port, In0P->ipc_port);
}

/* Routine xxx_host_info */
mig_internal void _Xxxx_host_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t infoType;
		machine_info_data_t info;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t xxx_host_info
		(ipc_port_t target_task, machine_info_data_t *info);

	static mach_msg_type_t infoType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		5,
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

	OutP->RetCode = xxx_host_info((ipc_port_t) In0P->Head.msgh_request_port, &OutP->info);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 56;

	OutP->infoType = infoType;
}

/* Routine xxx_slot_info */
mig_internal void _Xxxx_slot_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t slotType;
		int slot;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t infoType;
		machine_slot_data_t info;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t xxx_slot_info
		(task_t target_task, int slot, machine_slot_data_t *info);

	static mach_msg_type_t slotCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t infoType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		8,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->slotType != * (int *) &slotCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = xxx_slot_info(target_task, In0P->slot, &OutP->info);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 68;

	OutP->infoType = infoType;
}

/* Routine xxx_cpu_control */
mig_internal void _Xxxx_cpu_control
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t cpuType;
		int cpu;
		mach_msg_type_t runningType;
		boolean_t running;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t xxx_cpu_control
		(task_t target_task, int cpu, boolean_t running);

	static mach_msg_type_t cpuCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t runningCheck = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->cpuType != * (int *) &cpuCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->runningType != * (int *) &runningCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = xxx_cpu_control(target_task, In0P->cpu, In0P->running);
	task_deallocate(target_task);
}

/* Routine task_suspend */
mig_internal void _Xtask_suspend
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
	mig_external kern_return_t task_suspend
		(task_t target_task);

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_suspend(target_task);
	task_deallocate(target_task);
}

/* Routine task_resume */
mig_internal void _Xtask_resume
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
	mig_external kern_return_t task_resume
		(task_t target_task);

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_resume(target_task);
	task_deallocate(target_task);
}

/* Routine task_get_special_port */
mig_internal void _Xtask_get_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t which_portType;
		int which_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t special_portType;
		ipc_port_t special_port;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_get_special_port
		(task_t task, int which_port, ipc_port_t *special_port);

	static mach_msg_type_t which_portCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t special_portType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
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
	if (* (int *) &In0P->which_portType != * (int *) &which_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_get_special_port(task, In0P->which_port, &OutP->special_port);
	task_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->special_portType = special_portType;
}

/* Routine task_set_special_port */
mig_internal void _Xtask_set_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t which_portType;
		int which_port;
		mach_msg_type_t special_portType;
		ipc_port_t special_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_set_special_port
		(task_t task, int which_port, ipc_port_t special_port);

	static mach_msg_type_t which_portCheck = {
		/* msgt_name = */		2,
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
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->which_portType != * (int *) &which_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->special_portType.msgt_inline != TRUE) ||
	    (In0P->special_portType.msgt_longform != FALSE) ||
	    (In0P->special_portType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->special_portType.msgt_number != 1) ||
	    (In0P->special_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = task_set_special_port(task, In0P->which_port, In0P->special_port);
	task_deallocate(task);
}

/* Routine task_info */
mig_internal void _Xtask_info
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
		mach_msg_type_long_t task_info_outType;
		natural_t task_info_out[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t task_info
		(task_t target_task, int flavor, task_info_t task_info_out, mach_msg_type_number_t *task_info_outCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t task_info_outType = {
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

	task_t target_task;
	mach_msg_type_number_t task_info_outCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	task_info_outCnt = 1024;

	OutP->RetCode = task_info(target_task, In0P->flavor, OutP->task_info_out, &task_info_outCnt);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->task_info_outType = task_info_outType;

	OutP->task_info_outType.msgtl_number = task_info_outCnt;
	OutP->Head.msgh_size = 44 + (4 * task_info_outCnt);
}

/* Routine thread_create */
mig_internal void _Xthread_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t child_threadType;
		ipc_port_t child_thread;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_create
		(task_t parent_task, thread_t *child_thread);

	static mach_msg_type_t child_threadType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t parent_task;
	thread_t child_thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	parent_task = convert_port_to_task((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_create(parent_task, &child_thread);
	task_deallocate(parent_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->child_threadType = child_threadType;

	OutP->child_thread = convert_thread_to_port(child_thread);
}

/* Routine thread_suspend */
mig_internal void _Xthread_suspend
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
	mig_external kern_return_t thread_suspend
		(thread_t target_thread);

	thread_t target_thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_suspend(target_thread);
	thread_deallocate(target_thread);
}

/* Routine thread_resume */
mig_internal void _Xthread_resume
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
	mig_external kern_return_t thread_resume
		(thread_t target_thread);

	thread_t target_thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_resume(target_thread);
	thread_deallocate(target_thread);
}

/* Routine thread_abort */
mig_internal void _Xthread_abort
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
	mig_external kern_return_t thread_abort
		(thread_t target_thread);

	thread_t target_thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_abort(target_thread);
	thread_deallocate(target_thread);
}

/* Routine thread_get_state */
mig_internal void _Xthread_get_state
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
		mach_msg_type_long_t old_stateType;
		natural_t old_state[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_get_state
		(thread_t target_thread, int flavor, thread_state_t old_state, mach_msg_type_number_t *old_stateCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t old_stateType = {
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

	thread_t target_thread;
	mach_msg_type_number_t old_stateCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	old_stateCnt = 1024;

	OutP->RetCode = thread_get_state(target_thread, In0P->flavor, OutP->old_state, &old_stateCnt);
	thread_deallocate(target_thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->old_stateType = old_stateType;

	OutP->old_stateType.msgtl_number = old_stateCnt;
	OutP->Head.msgh_size = 44 + (4 * old_stateCnt);
}

/* Routine thread_set_state */
mig_internal void _Xthread_set_state
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t flavorType;
		int flavor;
		mach_msg_type_long_t new_stateType;
		natural_t new_state[1024];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_set_state
		(thread_t target_thread, int flavor, thread_state_t new_state, mach_msg_type_number_t new_stateCnt);

	unsigned int msgh_size;

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t target_thread;

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 44) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->new_stateType.msgtl_header.msgt_inline != TRUE) ||
	    (In0P->new_stateType.msgtl_header.msgt_longform != TRUE) ||
	    (In0P->new_stateType.msgtl_name != 2) ||
	    (In0P->new_stateType.msgtl_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 44 + (4 * In0P->new_stateType.msgtl_number))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_set_state(target_thread, In0P->flavor, In0P->new_state, In0P->new_stateType.msgtl_number);
	thread_deallocate(target_thread);
}

/* Routine thread_get_special_port */
mig_internal void _Xthread_get_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t which_portType;
		int which_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t special_portType;
		ipc_port_t special_port;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_get_special_port
		(thread_t thread, int which_port, ipc_port_t *special_port);

	static mach_msg_type_t which_portCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t special_portType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->which_portType != * (int *) &which_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_get_special_port(thread, In0P->which_port, &OutP->special_port);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->special_portType = special_portType;
}

/* Routine thread_set_special_port */
mig_internal void _Xthread_set_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t which_portType;
		int which_port;
		mach_msg_type_t special_portType;
		ipc_port_t special_port;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_set_special_port
		(thread_t thread, int which_port, ipc_port_t special_port);

	static mach_msg_type_t which_portCheck = {
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
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->which_portType != * (int *) &which_portCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->special_portType.msgt_inline != TRUE) ||
	    (In0P->special_portType.msgt_longform != FALSE) ||
	    (In0P->special_portType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->special_portType.msgt_number != 1) ||
	    (In0P->special_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = thread_set_special_port(thread, In0P->which_port, In0P->special_port);
	thread_deallocate(thread);
}

/* Routine thread_info */
mig_internal void _Xthread_info
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
		mach_msg_type_long_t thread_info_outType;
		natural_t thread_info_out[1024];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t thread_info
		(thread_t target_thread, int flavor, thread_info_t thread_info_out, mach_msg_type_number_t *thread_info_outCnt);

	static mach_msg_type_t flavorCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t thread_info_outType = {
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

	thread_t target_thread;
	mach_msg_type_number_t thread_info_outCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->flavorType != * (int *) &flavorCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_thread = convert_port_to_thread((ipc_port_t) In0P->Head.msgh_request_port);

	thread_info_outCnt = 1024;

	OutP->RetCode = thread_info(target_thread, In0P->flavor, OutP->thread_info_out, &thread_info_outCnt);
	thread_deallocate(target_thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->thread_info_outType = thread_info_outType;

	OutP->thread_info_outType.msgtl_number = thread_info_outCnt;
	OutP->Head.msgh_size = 44 + (4 * thread_info_outCnt);
}

/* Routine port_names */
mig_internal void _Xport_names
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t port_names_pType;
		mach_port_array_t port_names_p;
		mach_msg_type_long_t port_typesType;
		mach_port_type_array_t port_types;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_names
		(ipc_space_t task, mach_port_array_t *port_names_p, mach_msg_type_number_t *port_names_pCnt, mach_port_type_array_t *port_types, mach_msg_type_number_t *port_typesCnt);

	static mach_msg_type_long_t port_names_pType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	static mach_msg_type_long_t port_typesType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	ipc_space_t task;
	mach_msg_type_number_t port_names_pCnt;
	mach_msg_type_number_t port_typesCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_names(task, &OutP->port_names_p, &port_names_pCnt, &OutP->port_types, &port_typesCnt);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 64;

	OutP->port_names_pType = port_names_pType;

	OutP->port_names_pType.msgtl_number = port_names_pCnt;

	OutP->port_typesType = port_typesType;

	OutP->port_typesType.msgtl_number = port_typesCnt;
}

/* Routine port_type */
mig_internal void _Xport_type
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t port_type_pType;
		mach_port_type_t port_type_p;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_type
		(ipc_space_t task, mach_port_t port_name, mach_port_type_t *port_type_p);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t port_type_pType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_type(task, In0P->port_name, &OutP->port_type_p);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->port_type_pType = port_type_pType;
}

/* Routine port_rename */
mig_internal void _Xport_rename
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t old_nameType;
		mach_port_t old_name;
		mach_msg_type_t new_nameType;
		mach_port_t new_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_rename
		(ipc_space_t task, mach_port_t old_name, mach_port_t new_name);

	static mach_msg_type_t old_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t new_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->old_nameType != * (int *) &old_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->new_nameType != * (int *) &new_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_rename(task, In0P->old_name, In0P->new_name);
	space_deallocate(task);
}

/* Routine port_allocate */
mig_internal void _Xport_allocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_allocate
		(ipc_space_t task, mach_port_t *port_name);

	static mach_msg_type_t port_nameType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_allocate(task, &OutP->port_name);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->port_nameType = port_nameType;
}

/* Routine port_deallocate */
mig_internal void _Xport_deallocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_deallocate
		(ipc_space_t task, mach_port_t port_name);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_deallocate(task, In0P->port_name);
	space_deallocate(task);
}

/* Routine port_set_backlog */
mig_internal void _Xport_set_backlog
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
		mach_msg_type_t backlogType;
		int backlog;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_backlog
		(ipc_space_t task, mach_port_t port_name, int backlog);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t backlogCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->backlogType != * (int *) &backlogCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_backlog(task, In0P->port_name, In0P->backlog);
	space_deallocate(task);
}

/* Routine port_status */
mig_internal void _Xport_status
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t enabledType;
		mach_port_t enabled;
		mach_msg_type_t num_msgsType;
		int num_msgs;
		mach_msg_type_t backlogType;
		int backlog;
		mach_msg_type_t ownershipType;
		boolean_t ownership;
		mach_msg_type_t receive_rightsType;
		boolean_t receive_rights;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_status
		(ipc_space_t task, mach_port_t port_name, mach_port_t *enabled, int *num_msgs, int *backlog, boolean_t *ownership, boolean_t *receive_rights);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t enabledType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t num_msgsType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t backlogType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t ownershipType = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t receive_rightsType = {
		/* msgt_name = */		0,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_status(task, In0P->port_name, &OutP->enabled, &OutP->num_msgs, &OutP->backlog, &OutP->ownership, &OutP->receive_rights);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 72;

	OutP->enabledType = enabledType;

	OutP->num_msgsType = num_msgsType;

	OutP->backlogType = backlogType;

	OutP->ownershipType = ownershipType;

	OutP->receive_rightsType = receive_rightsType;
}

/* Routine port_set_allocate */
mig_internal void _Xport_set_allocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t set_nameType;
		mach_port_t set_name;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_allocate
		(ipc_space_t task, mach_port_t *set_name);

	static mach_msg_type_t set_nameType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_allocate(task, &OutP->set_name);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->set_nameType = set_nameType;
}

/* Routine port_set_deallocate */
mig_internal void _Xport_set_deallocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t set_nameType;
		mach_port_t set_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_deallocate
		(ipc_space_t task, mach_port_t set_name);

	static mach_msg_type_t set_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->set_nameType != * (int *) &set_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_deallocate(task, In0P->set_name);
	space_deallocate(task);
}

/* Routine port_set_add */
mig_internal void _Xport_set_add
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t set_nameType;
		mach_port_t set_name;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_add
		(ipc_space_t task, mach_port_t set_name, mach_port_t port_name);

	static mach_msg_type_t set_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->set_nameType != * (int *) &set_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_add(task, In0P->set_name, In0P->port_name);
	space_deallocate(task);
}

/* Routine port_set_remove */
mig_internal void _Xport_set_remove
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_remove
		(ipc_space_t task, mach_port_t port_name);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_remove(task, In0P->port_name);
	space_deallocate(task);
}

/* Routine port_set_status */
mig_internal void _Xport_set_status
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t set_nameType;
		mach_port_t set_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t membersType;
		mach_port_array_t members;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_status
		(ipc_space_t task, mach_port_t set_name, mach_port_array_t *members, mach_msg_type_number_t *membersCnt);

	static mach_msg_type_t set_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t membersType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		FALSE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	2,
		/* msgtl_size = */	32,
		/* msgtl_number = */	0,
	};

	ipc_space_t task;
	mach_msg_type_number_t membersCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->set_nameType != * (int *) &set_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_status(task, In0P->set_name, &OutP->members, &membersCnt);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 48;

	OutP->membersType = membersType;

	OutP->membersType.msgtl_number = membersCnt;
}

/* Routine port_insert_send */
mig_internal void _Xport_insert_send
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t my_portType;
		ipc_port_t my_port;
		mach_msg_type_t his_nameType;
		mach_port_t his_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_insert_send
		(ipc_space_t task, ipc_port_t my_port, mach_port_t his_name);

	static mach_msg_type_t his_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->my_portType.msgt_inline != TRUE) ||
	    (In0P->my_portType.msgt_longform != FALSE) ||
	    (In0P->my_portType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->my_portType.msgt_number != 1) ||
	    (In0P->my_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->his_nameType != * (int *) &his_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_insert_send(task, In0P->my_port, In0P->his_name);
	space_deallocate(task);
}

/* Routine port_extract_send */
mig_internal void _Xport_extract_send
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t his_nameType;
		mach_port_t his_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t his_portType;
		ipc_port_t his_port;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_extract_send
		(ipc_space_t task, mach_port_t his_name, ipc_port_t *his_port);

	static mach_msg_type_t his_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t his_portType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->his_nameType != * (int *) &his_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_extract_send(task, In0P->his_name, &OutP->his_port);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->his_portType = his_portType;
}

/* Routine port_insert_receive */
mig_internal void _Xport_insert_receive
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t my_portType;
		ipc_port_t my_port;
		mach_msg_type_t his_nameType;
		mach_port_t his_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_insert_receive
		(ipc_space_t task, ipc_port_t my_port, mach_port_t his_name);

	static mach_msg_type_t his_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->my_portType.msgt_inline != TRUE) ||
	    (In0P->my_portType.msgt_longform != FALSE) ||
	    (In0P->my_portType.msgt_name != MACH_MSG_TYPE_PORT_RECEIVE) ||
	    (In0P->my_portType.msgt_number != 1) ||
	    (In0P->my_portType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->his_nameType != * (int *) &his_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_insert_receive(task, In0P->my_port, In0P->his_name);
	space_deallocate(task);
}

/* Routine port_extract_receive */
mig_internal void _Xport_extract_receive
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t his_nameType;
		mach_port_t his_name;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t his_portType;
		ipc_port_t his_port;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_extract_receive
		(ipc_space_t task, mach_port_t his_name, ipc_port_t *his_port);

	static mach_msg_type_t his_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t his_portType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_RECEIVE,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->his_nameType != * (int *) &his_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_extract_receive(task, In0P->his_name, &OutP->his_port);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->his_portType = his_portType;

	if (IP_VALID((ipc_port_t) InHeadP->msgh_reply_port) &&
	    IP_VALID((ipc_port_t) OutP->his_port) &&
	    ipc_port_check_circularity((ipc_port_t) OutP->his_port, (ipc_port_t) InHeadP->msgh_reply_port))
		OutHeadP->msgh_bits |= MACH_MSGH_BITS_CIRCULAR;
}

/* Routine port_set_backup */
mig_internal void _Xport_set_backup
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t port_nameType;
		mach_port_t port_name;
		mach_msg_type_t backupType;
		ipc_port_t backup;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t previousType;
		ipc_port_t previous;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t port_set_backup
		(ipc_space_t task, mach_port_t port_name, ipc_port_t backup, ipc_port_t *previous);

	static mach_msg_type_t port_nameCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t previousType = {
		/* msgt_name = */		MACH_MSG_TYPE_PORT_SEND,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	ipc_space_t task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->port_nameType != * (int *) &port_nameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->backupType.msgt_inline != TRUE) ||
	    (In0P->backupType.msgt_longform != FALSE) ||
	    (In0P->backupType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->backupType.msgt_number != 1) ||
	    (In0P->backupType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	task = convert_port_to_space((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = port_set_backup(task, In0P->port_name, In0P->backup, &OutP->previous);
	space_deallocate(task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = 40;

	OutP->previousType = previousType;
}

/* Routine vm_machine_attribute */
mig_internal void _Xvm_machine_attribute
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t attributeType;
		vm_machine_attribute_t attribute;
		mach_msg_type_t valueType;
		vm_machine_attribute_val_t value;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t valueType;
		vm_machine_attribute_val_t value;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_machine_attribute
		(vm_map_t target_task, vm_address_t address, vm_size_t size, vm_machine_attribute_t attribute, vm_machine_attribute_val_t *value);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t attributeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t valueCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t valueType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 56) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->attributeType != * (int *) &attributeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->valueType != * (int *) &valueCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_machine_attribute(target_task, In0P->address, In0P->size, In0P->attribute, &In0P->value);
	vm_map_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->valueType = valueType;

	OutP->value = In0P->value;
}

/* Routine vm_synchronize */
mig_internal void _Xvm_synchronize
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_synchronize
		(vm_map_t target_task, vm_address_t address, vm_size_t size);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_synchronize(target_task, In0P->address, In0P->size);
	vm_map_deallocate(target_task);
}

/* Routine vm_set_policy */
mig_internal void _Xvm_set_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
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
	mig_external kern_return_t vm_set_policy
		(vm_map_t target_task, vm_address_t address, vm_size_t size, int policy);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t policyCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->policyType != * (int *) &policyCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_set_policy(target_task, In0P->address, In0P->size, In0P->policy);
	vm_map_deallocate(target_task);
}

/* Routine vm_deactivate */
mig_internal void _Xvm_deactivate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t addressType;
		vm_address_t address;
		mach_msg_type_t sizeType;
		vm_size_t size;
		mach_msg_type_t whenType;
		int when;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t vm_deactivate
		(vm_map_t target_task, vm_address_t address, vm_size_t size, int when);

	static mach_msg_type_t addressCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t sizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t whenCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	vm_map_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 48) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addressType != * (int *) &addressCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->whenType != * (int *) &whenCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_map((ipc_port_t) In0P->Head.msgh_request_port);

	OutP->RetCode = vm_deactivate(target_task, In0P->address, In0P->size, In0P->when);
	vm_map_deallocate(target_task);
}

static mig_routine_t mach_server_routines[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		_Xtask_create,
		_Xtask_terminate,
		0,
		0,
		_Xtask_threads,
		0,
		0,
		0,
		0,
		_Xthread_terminate,
		0,
		0,
		0,
		0,
		_Xvm_allocate,
		0,
		_Xvm_deallocate,
		_Xvm_protect,
		_Xvm_inherit,
		_Xvm_read,
		_Xvm_write,
		_Xvm_copy,
		_Xvm_region,
		_Xvm_statistics,
		_Xtask_by_unix_pid,
		0,
		0,
		0,
		_Xunix_pid,
		_Xnetipc_listen,
		_Xnetipc_ignore,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		_Xxxx_host_info,
		_Xxxx_slot_info,
		_Xxxx_cpu_control,
		0,
		0,
		0,
		0,
		0,
		0,
		_Xtask_suspend,
		_Xtask_resume,
		_Xtask_get_special_port,
		_Xtask_set_special_port,
		_Xtask_info,
		_Xthread_create,
		_Xthread_suspend,
		_Xthread_resume,
		_Xthread_abort,
		_Xthread_get_state,
		_Xthread_set_state,
		_Xthread_get_special_port,
		_Xthread_set_special_port,
		_Xthread_info,
		0,
		0,
		0,
		_Xport_names,
		_Xport_type,
		_Xport_rename,
		_Xport_allocate,
		_Xport_deallocate,
		_Xport_set_backlog,
		_Xport_status,
		_Xport_set_allocate,
		_Xport_set_deallocate,
		_Xport_set_add,
		_Xport_set_remove,
		_Xport_set_status,
		_Xport_insert_send,
		_Xport_extract_send,
		_Xport_insert_receive,
		_Xport_extract_receive,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		_Xport_set_backup,
		_Xvm_machine_attribute,
		0,
		_Xvm_synchronize,
		_Xvm_set_policy,
		_Xvm_deactivate,
};

mig_external boolean_t mach_server
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

	if ((InP->msgh_id > 2103) || (InP->msgh_id < 2000) ||
	    ((routine = mach_server_routines[InP->msgh_id - 2000]) == 0)) {
		OutP->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InP, &OutP->Head);
	return TRUE;
}

mig_external mig_routine_t mach_server_routine
	(const mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 2000;

	if ((msgh_id > 103) || (msgh_id < 0))
		return 0;

	return mach_server_routines[msgh_id];
}

