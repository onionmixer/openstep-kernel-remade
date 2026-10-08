/* Module kern_serv */

#define EXPORT_BOOLEAN
#include <mach/boolean.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include "kern_server_handler.h"

#ifndef	mig_internal
#define	mig_internal	static
#endif

#ifndef	TypeCheck
#define	TypeCheck 1
#endif

#ifndef	UseExternRCSId
#ifdef	hc
#define	UseExternRCSId		1
#endif
#endif

#ifndef	UseStaticMsgType
#if	!defined(hc) || defined(__STDC__)
#define	UseStaticMsgType	1
#endif
#endif

#define novalue void

#define msg_request_port	msg_local_port
#define msg_reply_port		msg_remote_port
#include <mach/std_types.h>
#include <kernserv/kern_server_types.h>

/* Routine instance_loc */
mig_internal novalue _Xinstance_loc (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t instance_locType;
		vm_address_t instance_loc;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t instance_locCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->instance_locType != * (int *) &instance_locCheck)
#else	UseStaticMsgType
	if ((In0P->instance_locType.msg_type_inline != TRUE) ||
	    (In0P->instance_locType.msg_type_longform != FALSE) ||
	    (In0P->instance_locType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->instance_locType.msg_type_number != 1) ||
	    (In0P->instance_locType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->instance_loc == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->instance_loc)(kern_serv->arg, In0P->instance_loc);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine boot_port */
mig_internal novalue _Xboot_port (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t boot_portType;
		port_t boot_port;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t boot_portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->boot_portType != * (int *) &boot_portCheck)
#else	UseStaticMsgType
	if ((In0P->boot_portType.msg_type_inline != TRUE) ||
	    (In0P->boot_portType.msg_type_longform != FALSE) ||
	    (In0P->boot_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->boot_portType.msg_type_number != 1) ||
	    (In0P->boot_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->boot_port == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->boot_port)(kern_serv->arg, In0P->boot_port);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine wire_range */
mig_internal novalue _Xwire_range (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t addrType;
		vm_address_t addr;
		msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t addrCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t sizeCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 40) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->addrType != * (int *) &addrCheck)
#else	UseStaticMsgType
	if ((In0P->addrType.msg_type_inline != TRUE) ||
	    (In0P->addrType.msg_type_longform != FALSE) ||
	    (In0P->addrType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->addrType.msg_type_number != 1) ||
	    (In0P->addrType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
#else	UseStaticMsgType
	if ((In0P->sizeType.msg_type_inline != TRUE) ||
	    (In0P->sizeType.msg_type_longform != FALSE) ||
	    (In0P->sizeType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->sizeType.msg_type_number != 1) ||
	    (In0P->sizeType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->wire_range == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->wire_range)(kern_serv->arg, In0P->addr, In0P->size);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine unwire_range */
mig_internal novalue _Xunwire_range (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t addrType;
		vm_address_t addr;
		msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t addrCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t sizeCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 40) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->addrType != * (int *) &addrCheck)
#else	UseStaticMsgType
	if ((In0P->addrType.msg_type_inline != TRUE) ||
	    (In0P->addrType.msg_type_longform != FALSE) ||
	    (In0P->addrType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->addrType.msg_type_number != 1) ||
	    (In0P->addrType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->sizeType != * (int *) &sizeCheck)
#else	UseStaticMsgType
	if ((In0P->sizeType.msg_type_inline != TRUE) ||
	    (In0P->sizeType.msg_type_longform != FALSE) ||
	    (In0P->sizeType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->sizeType.msg_type_number != 1) ||
	    (In0P->sizeType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->unwire_range == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->unwire_range)(kern_serv->arg, In0P->addr, In0P->size);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine port_proc */
mig_internal novalue _Xport_proc (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t portType;
		port_all_t port;
		msg_type_t procType;
		port_map_proc_t proc;
		msg_type_t argumentType;
		int argument;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT_ALL,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t procCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t argumentCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 48) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->portType != * (int *) &portCheck)
#else	UseStaticMsgType
	if ((In0P->portType.msg_type_inline != TRUE) ||
	    (In0P->portType.msg_type_longform != FALSE) ||
	    (In0P->portType.msg_type_name != MSG_TYPE_PORT_ALL) ||
	    (In0P->portType.msg_type_number != 1) ||
	    (In0P->portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->procType != * (int *) &procCheck)
#else	UseStaticMsgType
	if ((In0P->procType.msg_type_inline != TRUE) ||
	    (In0P->procType.msg_type_longform != FALSE) ||
	    (In0P->procType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->procType.msg_type_number != 1) ||
	    (In0P->procType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->argumentType != * (int *) &argumentCheck)
#else	UseStaticMsgType
	if ((In0P->argumentType.msg_type_inline != TRUE) ||
	    (In0P->argumentType.msg_type_longform != FALSE) ||
	    (In0P->argumentType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->argumentType.msg_type_number != 1) ||
	    (In0P->argumentType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->port_proc == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->port_proc)(kern_serv->arg, In0P->port, In0P->proc, In0P->argument);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* SimpleRoutine port_death_proc */
mig_internal novalue _Xport_death_proc (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t procType;
		port_death_proc_t proc;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t procCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->procType != * (int *) &procCheck)
#else	UseStaticMsgType
	if ((In0P->procType.msg_type_inline != TRUE) ||
	    (In0P->procType.msg_type_longform != FALSE) ||
	    (In0P->procType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->procType.msg_type_number != 1) ||
	    (In0P->procType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->port_death_proc == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	(void) (*kern_serv->port_death_proc)(kern_serv->arg, In0P->proc);
	OutP->RetCode = MIG_NO_REPLY;
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	;
}

/* Routine call_proc */
mig_internal novalue _Xcall_proc (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t procType;
		call_proc_t proc;
		msg_type_t argumentType;
		int argument;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t procCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t argumentCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 40) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->procType != * (int *) &procCheck)
#else	UseStaticMsgType
	if ((In0P->procType.msg_type_inline != TRUE) ||
	    (In0P->procType.msg_type_longform != FALSE) ||
	    (In0P->procType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->procType.msg_type_number != 1) ||
	    (In0P->procType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->argumentType != * (int *) &argumentCheck)
#else	UseStaticMsgType
	if ((In0P->argumentType.msg_type_inline != TRUE) ||
	    (In0P->argumentType.msg_type_longform != FALSE) ||
	    (In0P->argumentType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->argumentType.msg_type_number != 1) ||
	    (In0P->argumentType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->call_proc == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->call_proc)(kern_serv->arg, In0P->proc, In0P->argument);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* SimpleRoutine shutdown */
mig_internal novalue _Xshutdown (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	if (kern_serv->shutdown == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	(void) (*kern_serv->shutdown)(kern_serv->arg);
	OutP->RetCode = MIG_NO_REPLY;
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	;
}

/* SimpleRoutine log_level */
mig_internal novalue _Xlog_level (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t log_levelType;
		int log_level;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t log_levelCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->log_levelType != * (int *) &log_levelCheck)
#else	UseStaticMsgType
	if ((In0P->log_levelType.msg_type_inline != TRUE) ||
	    (In0P->log_levelType.msg_type_longform != FALSE) ||
	    (In0P->log_levelType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->log_levelType.msg_type_number != 1) ||
	    (In0P->log_levelType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->log_level == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	(void) (*kern_serv->log_level)(kern_serv->arg, In0P->log_level);
	OutP->RetCode = MIG_NO_REPLY;
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	;
}

/* SimpleRoutine get_log */
mig_internal novalue _Xget_log (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t reply_portType;
		port_t reply_port;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t reply_portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->reply_portType != * (int *) &reply_portCheck)
#else	UseStaticMsgType
	if ((In0P->reply_portType.msg_type_inline != TRUE) ||
	    (In0P->reply_portType.msg_type_longform != FALSE) ||
	    (In0P->reply_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->reply_portType.msg_type_number != 1) ||
	    (In0P->reply_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->get_log == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	(void) (*kern_serv->get_log)(kern_serv->arg, In0P->reply_port);
	OutP->RetCode = MIG_NO_REPLY;
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	;
}

/* Routine port_serv */
mig_internal novalue _Xport_serv (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t portType;
		port_all_t port;
		msg_type_t procType;
		port_map_proc_t proc;
		msg_type_t argumentType;
		int argument;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT_ALL,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t procCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t argumentCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 48) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->portType != * (int *) &portCheck)
#else	UseStaticMsgType
	if ((In0P->portType.msg_type_inline != TRUE) ||
	    (In0P->portType.msg_type_longform != FALSE) ||
	    (In0P->portType.msg_type_name != MSG_TYPE_PORT_ALL) ||
	    (In0P->portType.msg_type_number != 1) ||
	    (In0P->portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->procType != * (int *) &procCheck)
#else	UseStaticMsgType
	if ((In0P->procType.msg_type_inline != TRUE) ||
	    (In0P->procType.msg_type_longform != FALSE) ||
	    (In0P->procType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->procType.msg_type_number != 1) ||
	    (In0P->procType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->argumentType != * (int *) &argumentCheck)
#else	UseStaticMsgType
	if ((In0P->argumentType.msg_type_inline != TRUE) ||
	    (In0P->argumentType.msg_type_longform != FALSE) ||
	    (In0P->argumentType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->argumentType.msg_type_number != 1) ||
	    (In0P->argumentType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->port_serv == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->port_serv)(kern_serv->arg, In0P->port, In0P->proc, In0P->argument);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine version */
mig_internal novalue _Xversion (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t versionType;
		int version;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t versionCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->versionType != * (int *) &versionCheck)
#else	UseStaticMsgType
	if ((In0P->versionType.msg_type_inline != TRUE) ||
	    (In0P->versionType.msg_type_longform != FALSE) ||
	    (In0P->versionType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->versionType.msg_type_number != 1) ||
	    (In0P->versionType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->version == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->version)(kern_serv->arg, In0P->version);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine load_objc */
mig_internal novalue _Xload_objc (
	msg_header_t *InHeadP,
	msg_header_t *OutHeadP,
	kern_serv_t *kern_serv)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t addrType;
		vm_address_t addr;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t addrCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->addrType != * (int *) &addrCheck)
#else	UseStaticMsgType
	if ((In0P->addrType.msg_type_inline != TRUE) ||
	    (In0P->addrType.msg_type_longform != FALSE) ||
	    (In0P->addrType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->addrType.msg_type_number != 1) ||
	    (In0P->addrType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	if (kern_serv->load_objc == 0)
		{ OutP->RetCode = MIG_BAD_ID; return; }
	OutP->RetCode = (*kern_serv->load_objc)(kern_serv->arg, In0P->addr);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 32;	

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

kern_return_t kern_serv_handler (
	msg_header_t *InHeadP,
	kern_serv_t *kern_serv)
{
	char OutBuf[32];
	register msg_header_t *InP =  InHeadP;
	register death_pill_t *OutP = (death_pill_t *) OutBuf;

#if	UseStaticMsgType
	static const msg_type_t RetCodeType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = sizeof *OutP;
	OutP->Head.msg_type = InP->msg_type;
	OutP->Head.msg_local_port = PORT_NULL;
	OutP->Head.msg_remote_port = InP->msg_reply_port;
	OutP->Head.msg_id = InP->msg_id + 100;

#if	UseStaticMsgType
	OutP->RetCodeType = RetCodeType;
#else	UseStaticMsgType
	OutP->RetCodeType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->RetCodeType.msg_type_size = 32;
	OutP->RetCodeType.msg_type_number = 1;
	OutP->RetCodeType.msg_type_inline = TRUE;
	OutP->RetCodeType.msg_type_longform = FALSE;
	OutP->RetCodeType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType
	OutP->RetCode = MIG_BAD_ID;

	if ((InP->msg_id > 112) || (InP->msg_id < 100))
		return OutP->RetCode;
	else {
		typedef novalue (*SERVER_STUB_PROC) (
			msg_header_t *,
			msg_header_t *,
			kern_serv_t *);
		static const SERVER_STUB_PROC routines[] = {
			_Xinstance_loc,
			_Xboot_port,
			_Xwire_range,
			_Xunwire_range,
			_Xport_proc,
			_Xport_death_proc,
			_Xcall_proc,
			_Xshutdown,
			_Xlog_level,
			_Xget_log,
			_Xport_serv,
			_Xversion,
			_Xload_objc,
		};

		if (routines[InP->msg_id - 100])
			(routines[InP->msg_id - 100]) (
				InP, &OutP->Head, kern_serv);
		 else
			return MIG_BAD_ID;
	}
	if (OutP->RetCode == MIG_NO_REPLY)
		return KERN_SUCCESS;
	return msg_send(&OutP->Head,
		kern_serv->timeout >= 0 ? SEND_TIMEOUT : MSG_OPTION_NONE,
		kern_serv->timeout);
}
