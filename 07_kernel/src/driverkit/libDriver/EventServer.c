/* Module Event */

#define EXPORT_BOOLEAN
#include <mach/boolean.h>
#include <mach/message.h>
#include <mach/mig_errors.h>

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
#include <mach/mach_types.h>
#include <bsd/dev/evio.h>

/* Routine EvOpen */
mig_internal novalue _XEvOpen
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t event_portType;
		port_t event_port;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvOpen (port_t device_master, port_t event_port);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t event_portCheck = {
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
	if (* (int *) &In0P->event_portType != * (int *) &event_portCheck)
#else	UseStaticMsgType
	if ((In0P->event_portType.msg_type_inline != TRUE) ||
	    (In0P->event_portType.msg_type_longform != FALSE) ||
	    (In0P->event_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->event_portType.msg_type_number != 1) ||
	    (In0P->event_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvOpen(In0P->Head.msg_request_port, In0P->event_port);
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

/* Routine EvClose */
mig_internal novalue _XEvClose
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t event_portType;
		port_t event_port;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvClose (port_t device_master, port_t event_port);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t event_portCheck = {
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
	if (* (int *) &In0P->event_portType != * (int *) &event_portCheck)
#else	UseStaticMsgType
	if ((In0P->event_portType.msg_type_inline != TRUE) ||
	    (In0P->event_portType.msg_type_longform != FALSE) ||
	    (In0P->event_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->event_portType.msg_type_number != 1) ||
	    (In0P->event_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvClose(In0P->Head.msg_request_port, In0P->event_port);
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

/* Routine EvMapEventShmem */
mig_internal novalue _XEvMapEventShmem
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t event_portType;
		port_t event_port;
		msg_type_t taskType;
		port_t task;
		msg_type_t sizeType;
		vm_size_t size;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t addrType;
		vm_offset_t addr;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvMapEventShmem (port_t device_master, port_t event_port, port_t task, vm_size_t size, vm_offset_t *addr);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t event_portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t taskCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT,
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

#if	UseStaticMsgType
	static const msg_type_t addrType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
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
	if (* (int *) &In0P->event_portType != * (int *) &event_portCheck)
#else	UseStaticMsgType
	if ((In0P->event_portType.msg_type_inline != TRUE) ||
	    (In0P->event_portType.msg_type_longform != FALSE) ||
	    (In0P->event_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->event_portType.msg_type_number != 1) ||
	    (In0P->event_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->taskType != * (int *) &taskCheck)
#else	UseStaticMsgType
	if ((In0P->taskType.msg_type_inline != TRUE) ||
	    (In0P->taskType.msg_type_longform != FALSE) ||
	    (In0P->taskType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->taskType.msg_type_number != 1) ||
	    (In0P->taskType.msg_type_size != 32))
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

	OutP->RetCode = EvMapEventShmem(In0P->Head.msg_request_port, In0P->event_port, In0P->task, In0P->size, &OutP->addr);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->addrType = addrType;
#else	UseStaticMsgType
	OutP->addrType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->addrType.msg_type_size = 32;
	OutP->addrType.msg_type_number = 1;
	OutP->addrType.msg_type_inline = TRUE;
	OutP->addrType.msg_type_longform = FALSE;
	OutP->addrType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine EvFrameBufferDevicePort */
mig_internal novalue _XEvFrameBufferDevicePort
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t event_portType;
		port_t event_port;
		msg_type_t nameType;
		EVString name;
		msg_type_t classType;
		EVString class;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t nameDevicePortType;
		port_t nameDevicePort;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvFrameBufferDevicePort (port_t device_master, port_t event_port, EVString name, EVString class, port_t *nameDevicePort);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t event_portCheck = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t nameCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t classCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t nameDevicePortType = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 168) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->event_portType != * (int *) &event_portCheck)
#else	UseStaticMsgType
	if ((In0P->event_portType.msg_type_inline != TRUE) ||
	    (In0P->event_portType.msg_type_longform != FALSE) ||
	    (In0P->event_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->event_portType.msg_type_number != 1) ||
	    (In0P->event_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->nameType != * (int *) &nameCheck)
#else	UseStaticMsgType
	if ((In0P->nameType.msg_type_inline != TRUE) ||
	    (In0P->nameType.msg_type_longform != FALSE) ||
	    (In0P->nameType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->nameType.msg_type_number != 64) ||
	    (In0P->nameType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->classType != * (int *) &classCheck)
#else	UseStaticMsgType
	if ((In0P->classType.msg_type_inline != TRUE) ||
	    (In0P->classType.msg_type_longform != FALSE) ||
	    (In0P->classType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->classType.msg_type_number != 64) ||
	    (In0P->classType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvFrameBufferDevicePort(In0P->Head.msg_request_port, In0P->event_port, In0P->name, In0P->class, &OutP->nameDevicePort);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->nameDevicePortType = nameDevicePortType;
#else	UseStaticMsgType
	OutP->nameDevicePortType.msg_type_name = MSG_TYPE_PORT;
	OutP->nameDevicePortType.msg_type_size = 32;
	OutP->nameDevicePortType.msg_type_number = 1;
	OutP->nameDevicePortType.msg_type_inline = TRUE;
	OutP->nameDevicePortType.msg_type_longform = FALSE;
	OutP->nameDevicePortType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = FALSE;
	OutP->Head.msg_size = msg_size;
}

/* Routine EvSetSpecialKeyPort */
mig_internal novalue _XEvSetSpecialKeyPort
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t special_keyType;
		int special_key;
		msg_type_t key_portType;
		port_t key_port;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvSetSpecialKeyPort (port_t device_master, int special_key, port_t key_port);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t special_keyCheck = {
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
	static const msg_type_t key_portCheck = {
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
	if ((msg_size != 40) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->special_keyType != * (int *) &special_keyCheck)
#else	UseStaticMsgType
	if ((In0P->special_keyType.msg_type_inline != TRUE) ||
	    (In0P->special_keyType.msg_type_longform != FALSE) ||
	    (In0P->special_keyType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->special_keyType.msg_type_number != 1) ||
	    (In0P->special_keyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->key_portType != * (int *) &key_portCheck)
#else	UseStaticMsgType
	if ((In0P->key_portType.msg_type_inline != TRUE) ||
	    (In0P->key_portType.msg_type_longform != FALSE) ||
	    (In0P->key_portType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->key_portType.msg_type_number != 1) ||
	    (In0P->key_portType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvSetSpecialKeyPort(In0P->Head.msg_request_port, In0P->special_key, In0P->key_port);
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

/* Routine EvGetParameterInt */
mig_internal novalue _XEvGetParameterInt
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t unitType;
		EVObjectNumber unit;
		msg_type_t parameterNameType;
		EVParameterName parameterName;
		msg_type_t maxCountType;
		unsigned maxCount;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t parameterArrayType;
		int parameterArray[64];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvGetParameterInt (port_t device_master, EVObjectNumber unit, EVParameterName parameterName, unsigned maxCount, EVIntParameter parameterArray, unsigned int *parameterArrayCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t unitCheck = {
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
	static const msg_type_t parameterNameCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t maxCountCheck = {
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
	static const msg_type_t parameterArrayType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int parameterArrayCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 108) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->unitType != * (int *) &unitCheck)
#else	UseStaticMsgType
	if ((In0P->unitType.msg_type_inline != TRUE) ||
	    (In0P->unitType.msg_type_longform != FALSE) ||
	    (In0P->unitType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->unitType.msg_type_number != 1) ||
	    (In0P->unitType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
#else	UseStaticMsgType
	if ((In0P->parameterNameType.msg_type_inline != TRUE) ||
	    (In0P->parameterNameType.msg_type_longform != FALSE) ||
	    (In0P->parameterNameType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->parameterNameType.msg_type_number != 64) ||
	    (In0P->parameterNameType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->maxCountType != * (int *) &maxCountCheck)
#else	UseStaticMsgType
	if ((In0P->maxCountType.msg_type_inline != TRUE) ||
	    (In0P->maxCountType.msg_type_longform != FALSE) ||
	    (In0P->maxCountType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->maxCountType.msg_type_number != 1) ||
	    (In0P->maxCountType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	parameterArrayCnt = 64;

	OutP->RetCode = EvGetParameterInt(In0P->Head.msg_request_port, In0P->unit, In0P->parameterName, In0P->maxCount, OutP->parameterArray, &parameterArrayCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 292 */

#if	UseStaticMsgType
	OutP->parameterArrayType = parameterArrayType;
#else	UseStaticMsgType
	OutP->parameterArrayType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->parameterArrayType.msg_type_size = 32;
	OutP->parameterArrayType.msg_type_inline = TRUE;
	OutP->parameterArrayType.msg_type_longform = FALSE;
	OutP->parameterArrayType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->parameterArrayType.msg_type_number /* parameterArrayCnt */ = /* parameterArrayType.msg_type_number */ parameterArrayCnt;

	msg_size_delta = 4 * parameterArrayCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine EvGetParameterChar */
mig_internal novalue _XEvGetParameterChar
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t unitType;
		EVObjectNumber unit;
		msg_type_t parameterNameType;
		EVParameterName parameterName;
		msg_type_t maxCountType;
		unsigned maxCount;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_long_t parameterArrayType;
		char parameterArray[4096];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvGetParameterChar (port_t device_master, EVObjectNumber unit, EVParameterName parameterName, unsigned maxCount, EVCharParameter parameterArray, unsigned int *parameterArrayCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t unitCheck = {
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
	static const msg_type_t parameterNameCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t maxCountCheck = {
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
	static const msg_type_long_t parameterArrayType = {
	{
		/* msg_type_name = */		0,
		/* msg_type_size = */		0,
		/* msg_type_number = */		0,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	TRUE,
		/* msg_type_deallocate = */	FALSE,
	},
		/* msg_type_long_name = */	MSG_TYPE_CHAR,
		/* msg_type_long_size = */	8,
		/* msg_type_long_number = */	4096,
	};
#endif	UseStaticMsgType

	unsigned int parameterArrayCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 108) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->unitType != * (int *) &unitCheck)
#else	UseStaticMsgType
	if ((In0P->unitType.msg_type_inline != TRUE) ||
	    (In0P->unitType.msg_type_longform != FALSE) ||
	    (In0P->unitType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->unitType.msg_type_number != 1) ||
	    (In0P->unitType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
#else	UseStaticMsgType
	if ((In0P->parameterNameType.msg_type_inline != TRUE) ||
	    (In0P->parameterNameType.msg_type_longform != FALSE) ||
	    (In0P->parameterNameType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->parameterNameType.msg_type_number != 64) ||
	    (In0P->parameterNameType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->maxCountType != * (int *) &maxCountCheck)
#else	UseStaticMsgType
	if ((In0P->maxCountType.msg_type_inline != TRUE) ||
	    (In0P->maxCountType.msg_type_longform != FALSE) ||
	    (In0P->maxCountType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->maxCountType.msg_type_number != 1) ||
	    (In0P->maxCountType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	parameterArrayCnt = 4096;

	OutP->RetCode = EvGetParameterChar(In0P->Head.msg_request_port, In0P->unit, In0P->parameterName, In0P->maxCount, OutP->parameterArray, &parameterArrayCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 44;	
	/* Maximum reply size 4140 */

#if	UseStaticMsgType
	OutP->parameterArrayType = parameterArrayType;
#else	UseStaticMsgType
	OutP->parameterArrayType.msg_type_long_name = MSG_TYPE_CHAR;
	OutP->parameterArrayType.msg_type_long_size = 8;
	OutP->parameterArrayType.msg_type_header.msg_type_inline = TRUE;
	OutP->parameterArrayType.msg_type_header.msg_type_longform = TRUE;
	OutP->parameterArrayType.msg_type_header.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->parameterArrayType.msg_type_long_number /* parameterArrayCnt */ = /* parameterArrayType.msg_type_long_number */ parameterArrayCnt;

	msg_size_delta = (1 * parameterArrayCnt + 3) & ~3;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine EvSetParameterInt */
mig_internal novalue _XEvSetParameterInt
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t unitType;
		EVObjectNumber unit;
		msg_type_t parameterNameType;
		EVParameterName parameterName;
		msg_type_t parameterArrayType;
		int parameterArray[64];
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvSetParameterInt (port_t device_master, EVObjectNumber unit, EVParameterName parameterName, EVIntParameter parameterArray, unsigned int parameterArrayCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t unitCheck = {
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
	static const msg_type_t parameterNameCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 104) || (msg_size > 360) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->unitType != * (int *) &unitCheck)
#else	UseStaticMsgType
	if ((In0P->unitType.msg_type_inline != TRUE) ||
	    (In0P->unitType.msg_type_longform != FALSE) ||
	    (In0P->unitType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->unitType.msg_type_number != 1) ||
	    (In0P->unitType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
#else	UseStaticMsgType
	if ((In0P->parameterNameType.msg_type_inline != TRUE) ||
	    (In0P->parameterNameType.msg_type_longform != FALSE) ||
	    (In0P->parameterNameType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->parameterNameType.msg_type_number != 64) ||
	    (In0P->parameterNameType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->parameterArrayType.msg_type_inline != TRUE) ||
	    (In0P->parameterArrayType.msg_type_longform != FALSE) ||
	    (In0P->parameterArrayType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->parameterArrayType.msg_type_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	msg_size_delta = 4 * In0P->parameterArrayType.msg_type_number;
	if (msg_size != 104 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvSetParameterInt(In0P->Head.msg_request_port, In0P->unit, In0P->parameterName, In0P->parameterArray, In0P->parameterArrayType.msg_type_number);
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

/* Routine EvSetParameterChar */
mig_internal novalue _XEvSetParameterChar
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t unitType;
		EVObjectNumber unit;
		msg_type_t parameterNameType;
		EVParameterName parameterName;
		msg_type_long_t parameterArrayType;
		char parameterArray[4096];
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t EvSetParameterChar (port_t device_master, EVObjectNumber unit, EVParameterName parameterName, EVCharParameter parameterArray, unsigned int parameterArrayCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t unitCheck = {
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
	static const msg_type_t parameterNameCheck = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		64,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 112) || (msg_size > 4208) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->unitType != * (int *) &unitCheck)
#else	UseStaticMsgType
	if ((In0P->unitType.msg_type_inline != TRUE) ||
	    (In0P->unitType.msg_type_longform != FALSE) ||
	    (In0P->unitType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->unitType.msg_type_number != 1) ||
	    (In0P->unitType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
#else	UseStaticMsgType
	if ((In0P->parameterNameType.msg_type_inline != TRUE) ||
	    (In0P->parameterNameType.msg_type_longform != FALSE) ||
	    (In0P->parameterNameType.msg_type_name != MSG_TYPE_CHAR) ||
	    (In0P->parameterNameType.msg_type_number != 64) ||
	    (In0P->parameterNameType.msg_type_size != 8))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->parameterArrayType.msg_type_header.msg_type_inline != TRUE) ||
	    (In0P->parameterArrayType.msg_type_header.msg_type_longform != TRUE) ||
	    (In0P->parameterArrayType.msg_type_long_name != MSG_TYPE_CHAR) ||
	    (In0P->parameterArrayType.msg_type_long_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	msg_size_delta = (1 * In0P->parameterArrayType.msg_type_long_number + 3) & ~3;
	if (msg_size != 112 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = EvSetParameterChar(In0P->Head.msg_request_port, In0P->unit, In0P->parameterName, In0P->parameterArray, In0P->parameterArrayType.msg_type_long_number);
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

boolean_t Event_server
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	register msg_header_t *InP =  InHeadP;
	register death_pill_t *OutP = (death_pill_t *) OutHeadP;

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

	if ((InP->msg_id > 31008) || (InP->msg_id < 31000))
		return FALSE;
	else {
		typedef novalue (*SERVER_STUB_PROC)
			(msg_header_t *, msg_header_t *);
		static const SERVER_STUB_PROC routines[] = {
			_XEvOpen,
			_XEvClose,
			_XEvMapEventShmem,
			_XEvFrameBufferDevicePort,
			_XEvSetSpecialKeyPort,
			_XEvGetParameterInt,
			_XEvGetParameterChar,
			_XEvSetParameterInt,
			_XEvSetParameterChar,
		};

		if (routines[InP->msg_id - 31000])
			(routines[InP->msg_id - 31000]) (InP, &OutP->Head);
		 else
			return FALSE;
	}
	return TRUE;
}
