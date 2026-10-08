/* Module audio */

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
#include <bsd/dev/audioTypes.h>

/* Routine GetExclusiveUser */
mig_internal novalue _XGetExclusiveUser
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t streamOwnerType;
		port_t streamOwner;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetExclusiveUser (audio_device_t devicePort, port_t *streamOwner);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetExclusiveUser(audio_port_to_device(In0P->Head.msg_request_port), &OutP->streamOwner);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->streamOwnerType = streamOwnerType;
#else	UseStaticMsgType
	OutP->streamOwnerType.msg_type_name = MSG_TYPE_PORT;
	OutP->streamOwnerType.msg_type_size = 32;
	OutP->streamOwnerType.msg_type_number = 1;
	OutP->streamOwnerType.msg_type_inline = TRUE;
	OutP->streamOwnerType.msg_type_longform = FALSE;
	OutP->streamOwnerType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = FALSE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetExclusiveUser */
mig_internal novalue _XSetExclusiveUser
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetExclusiveUser (audio_device_t devicePort, port_t streamOwner);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetExclusiveUser(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner);
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

/* Routine GetBufferOptions */
mig_internal novalue _XGetBufferOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t dmaSizeType;
		u_int dmaSize;
		msg_type_t dmaCountType;
		u_int dmaCount;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetBufferOptions (audio_device_t devicePort, u_int *dmaSize, u_int *dmaCount);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t dmaSizeType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t dmaCountType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetBufferOptions(audio_port_to_device(In0P->Head.msg_request_port), &OutP->dmaSize, &OutP->dmaCount);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->dmaSizeType = dmaSizeType;
#else	UseStaticMsgType
	OutP->dmaSizeType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->dmaSizeType.msg_type_size = 32;
	OutP->dmaSizeType.msg_type_number = 1;
	OutP->dmaSizeType.msg_type_inline = TRUE;
	OutP->dmaSizeType.msg_type_longform = FALSE;
	OutP->dmaSizeType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->dmaCountType = dmaCountType;
#else	UseStaticMsgType
	OutP->dmaCountType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->dmaCountType.msg_type_size = 32;
	OutP->dmaCountType.msg_type_number = 1;
	OutP->dmaCountType.msg_type_inline = TRUE;
	OutP->dmaCountType.msg_type_longform = FALSE;
	OutP->dmaCountType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetBufferOptions */
mig_internal novalue _XSetBufferOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t dmaSizeType;
		u_int dmaSize;
		msg_type_t dmaCountType;
		u_int dmaCount;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetBufferOptions (audio_device_t devicePort, port_t streamOwner, u_int dmaSize, u_int dmaCount);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t dmaSizeCheck = {
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
	static const msg_type_t dmaCountCheck = {
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
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->dmaSizeType != * (int *) &dmaSizeCheck)
#else	UseStaticMsgType
	if ((In0P->dmaSizeType.msg_type_inline != TRUE) ||
	    (In0P->dmaSizeType.msg_type_longform != FALSE) ||
	    (In0P->dmaSizeType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->dmaSizeType.msg_type_number != 1) ||
	    (In0P->dmaSizeType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->dmaCountType != * (int *) &dmaCountCheck)
#else	UseStaticMsgType
	if ((In0P->dmaCountType.msg_type_inline != TRUE) ||
	    (In0P->dmaCountType.msg_type_longform != FALSE) ||
	    (In0P->dmaCountType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->dmaCountType.msg_type_number != 1) ||
	    (In0P->dmaCountType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetBufferOptions(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->dmaSize, In0P->dmaCount);
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

/* Routine ControlStreams */
mig_internal novalue _XControlStreams
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t actionType;
		int action;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioControlStreams (audio_device_t devicePort, port_t streamOwner, int action);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t actionCheck = {
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
	if ((msg_size != 40) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->actionType != * (int *) &actionCheck)
#else	UseStaticMsgType
	if ((In0P->actionType.msg_type_inline != TRUE) ||
	    (In0P->actionType.msg_type_longform != FALSE) ||
	    (In0P->actionType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->actionType.msg_type_number != 1) ||
	    (In0P->actionType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioControlStreams(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->action);
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

/* Routine AddStream */
mig_internal novalue _XAddStream
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t streamIdType;
		int streamId;
		msg_type_t streamTypeType;
		u_int streamType;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t streamPortType;
		port_t streamPort;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioAddStream (audio_device_t devicePort, port_t *streamPort, port_t streamOwner, int streamId, u_int streamType);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t streamIdCheck = {
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
	static const msg_type_t streamTypeCheck = {
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
	static const msg_type_t streamPortType = {
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
	if ((msg_size != 48) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamIdType != * (int *) &streamIdCheck)
#else	UseStaticMsgType
	if ((In0P->streamIdType.msg_type_inline != TRUE) ||
	    (In0P->streamIdType.msg_type_longform != FALSE) ||
	    (In0P->streamIdType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->streamIdType.msg_type_number != 1) ||
	    (In0P->streamIdType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamTypeType != * (int *) &streamTypeCheck)
#else	UseStaticMsgType
	if ((In0P->streamTypeType.msg_type_inline != TRUE) ||
	    (In0P->streamTypeType.msg_type_longform != FALSE) ||
	    (In0P->streamTypeType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->streamTypeType.msg_type_number != 1) ||
	    (In0P->streamTypeType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioAddStream(audio_port_to_device(In0P->Head.msg_request_port), &OutP->streamPort, In0P->streamOwner, In0P->streamId, In0P->streamType);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->streamPortType = streamPortType;
#else	UseStaticMsgType
	OutP->streamPortType.msg_type_name = MSG_TYPE_PORT;
	OutP->streamPortType.msg_type_size = 32;
	OutP->streamPortType.msg_type_number = 1;
	OutP->streamPortType.msg_type_inline = TRUE;
	OutP->streamPortType.msg_type_longform = FALSE;
	OutP->streamPortType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = FALSE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetDevicePeakOptions */
mig_internal novalue _XGetDevicePeakOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t enabledType;
		u_int enabled;
		msg_type_t historyType;
		u_int history;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDevicePeakOptions (audio_device_t devicePort, u_int *enabled, u_int *history);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t enabledType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t historyType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetDevicePeakOptions(audio_port_to_device(In0P->Head.msg_request_port), &OutP->enabled, &OutP->history);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->enabledType = enabledType;
#else	UseStaticMsgType
	OutP->enabledType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->enabledType.msg_type_size = 32;
	OutP->enabledType.msg_type_number = 1;
	OutP->enabledType.msg_type_inline = TRUE;
	OutP->enabledType.msg_type_longform = FALSE;
	OutP->enabledType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->historyType = historyType;
#else	UseStaticMsgType
	OutP->historyType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->historyType.msg_type_size = 32;
	OutP->historyType.msg_type_number = 1;
	OutP->historyType.msg_type_inline = TRUE;
	OutP->historyType.msg_type_longform = FALSE;
	OutP->historyType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetDevicePeakOptions */
mig_internal novalue _XSetDevicePeakOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t enabledType;
		u_int enabled;
		msg_type_t historyType;
		u_int history;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetDevicePeakOptions (audio_device_t devicePort, port_t streamOwner, u_int enabled, u_int history);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t enabledCheck = {
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
	static const msg_type_t historyCheck = {
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
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->enabledType != * (int *) &enabledCheck)
#else	UseStaticMsgType
	if ((In0P->enabledType.msg_type_inline != TRUE) ||
	    (In0P->enabledType.msg_type_longform != FALSE) ||
	    (In0P->enabledType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->enabledType.msg_type_number != 1) ||
	    (In0P->enabledType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->historyType != * (int *) &historyCheck)
#else	UseStaticMsgType
	if ((In0P->historyType.msg_type_inline != TRUE) ||
	    (In0P->historyType.msg_type_longform != FALSE) ||
	    (In0P->historyType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->historyType.msg_type_number != 1) ||
	    (In0P->historyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetDevicePeakOptions(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->enabled, In0P->history);
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

/* Routine GetDevicePeak */
mig_internal novalue _XGetDevicePeak
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t peakLeftType;
		u_int peakLeft;
		msg_type_t peakRightType;
		u_int peakRight;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDevicePeak (audio_device_t devicePort, u_int *peakLeft, u_int *peakRight);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t peakLeftType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t peakRightType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetDevicePeak(audio_port_to_device(In0P->Head.msg_request_port), &OutP->peakLeft, &OutP->peakRight);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->peakLeftType = peakLeftType;
#else	UseStaticMsgType
	OutP->peakLeftType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->peakLeftType.msg_type_size = 32;
	OutP->peakLeftType.msg_type_number = 1;
	OutP->peakLeftType.msg_type_inline = TRUE;
	OutP->peakLeftType.msg_type_longform = FALSE;
	OutP->peakLeftType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->peakRightType = peakRightType;
#else	UseStaticMsgType
	OutP->peakRightType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->peakRightType.msg_type_size = 32;
	OutP->peakRightType.msg_type_number = 1;
	OutP->peakRightType.msg_type_inline = TRUE;
	OutP->peakRightType.msg_type_longform = FALSE;
	OutP->peakRightType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetClipCount */
mig_internal novalue _XGetClipCount
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t countType;
		u_int count;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetClipCount (audio_device_t devicePort, u_int *count);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t countType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetClipCount(audio_port_to_device(In0P->Head.msg_request_port), &OutP->count);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->countType = countType;
#else	UseStaticMsgType
	OutP->countType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->countType.msg_type_size = 32;
	OutP->countType.msg_type_number = 1;
	OutP->countType.msg_type_inline = TRUE;
	OutP->countType.msg_type_longform = FALSE;
	OutP->countType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetSndoutOptions */
mig_internal novalue _XGetSndoutOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t bitsType;
		u_int bits;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetSndoutOptions (audio_device_t devicePort, u_int *bits);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t bitsType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetSndoutOptions(audio_port_to_device(In0P->Head.msg_request_port), &OutP->bits);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->bitsType = bitsType;
#else	UseStaticMsgType
	OutP->bitsType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->bitsType.msg_type_size = 32;
	OutP->bitsType.msg_type_number = 1;
	OutP->bitsType.msg_type_inline = TRUE;
	OutP->bitsType.msg_type_longform = FALSE;
	OutP->bitsType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetSndoutOptions */
mig_internal novalue _XSetSndoutOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t bitsType;
		u_int bits;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetSndoutOptions (audio_device_t devicePort, port_t streamOwner, u_int bits);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t bitsCheck = {
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
	if ((msg_size != 40) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->bitsType != * (int *) &bitsCheck)
#else	UseStaticMsgType
	if ((In0P->bitsType.msg_type_inline != TRUE) ||
	    (In0P->bitsType.msg_type_longform != FALSE) ||
	    (In0P->bitsType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->bitsType.msg_type_number != 1) ||
	    (In0P->bitsType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetSndoutOptions(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->bits);
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

/* Routine GetSpeaker */
mig_internal novalue _XGetSpeaker
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t leftType;
		int left;
		msg_type_t rightType;
		int right;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetSpeaker (audio_device_t devicePort, int *left, int *right);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t leftType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t rightType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetSpeaker(audio_port_to_device(In0P->Head.msg_request_port), &OutP->left, &OutP->right);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->leftType = leftType;
#else	UseStaticMsgType
	OutP->leftType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->leftType.msg_type_size = 32;
	OutP->leftType.msg_type_number = 1;
	OutP->leftType.msg_type_inline = TRUE;
	OutP->leftType.msg_type_longform = FALSE;
	OutP->leftType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->rightType = rightType;
#else	UseStaticMsgType
	OutP->rightType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->rightType.msg_type_size = 32;
	OutP->rightType.msg_type_number = 1;
	OutP->rightType.msg_type_inline = TRUE;
	OutP->rightType.msg_type_longform = FALSE;
	OutP->rightType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetSpeaker */
mig_internal novalue _XSetSpeaker
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t leftType;
		int left;
		msg_type_t rightType;
		int right;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetSpeaker (audio_device_t devicePort, port_t streamOwner, int left, int right);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t leftCheck = {
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
	static const msg_type_t rightCheck = {
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
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->leftType != * (int *) &leftCheck)
#else	UseStaticMsgType
	if ((In0P->leftType.msg_type_inline != TRUE) ||
	    (In0P->leftType.msg_type_longform != FALSE) ||
	    (In0P->leftType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->leftType.msg_type_number != 1) ||
	    (In0P->leftType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->rightType != * (int *) &rightCheck)
#else	UseStaticMsgType
	if ((In0P->rightType.msg_type_inline != TRUE) ||
	    (In0P->rightType.msg_type_longform != FALSE) ||
	    (In0P->rightType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->rightType.msg_type_number != 1) ||
	    (In0P->rightType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetSpeaker(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->left, In0P->right);
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

/* Routine SetStreamGain */
mig_internal novalue _XSetStreamGain
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t leftType;
		int left;
		msg_type_t rightType;
		int right;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetStreamGain (audio_stream_t streamPort, int left, int right);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t leftCheck = {
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
	static const msg_type_t rightCheck = {
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
	if (* (int *) &In0P->leftType != * (int *) &leftCheck)
#else	UseStaticMsgType
	if ((In0P->leftType.msg_type_inline != TRUE) ||
	    (In0P->leftType.msg_type_longform != FALSE) ||
	    (In0P->leftType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->leftType.msg_type_number != 1) ||
	    (In0P->leftType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->rightType != * (int *) &rightCheck)
#else	UseStaticMsgType
	if ((In0P->rightType.msg_type_inline != TRUE) ||
	    (In0P->rightType.msg_type_longform != FALSE) ||
	    (In0P->rightType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->rightType.msg_type_number != 1) ||
	    (In0P->rightType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetStreamGain(audio_port_to_stream(In0P->Head.msg_request_port), In0P->left, In0P->right);
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

/* Routine ChangeStreamOwner */
mig_internal novalue _XChangeStreamOwner
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioChangeStreamOwner (audio_stream_t streamPort, port_t streamOwner);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioChangeStreamOwner(audio_port_to_stream(In0P->Head.msg_request_port), In0P->streamOwner);
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

/* Routine StreamControl */
mig_internal novalue _XStreamControl
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t actionType;
		int action;
		msg_type_t actionTimeType;
		audio_time_t actionTime;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioStreamControl (audio_stream_t streamPort, int action, audio_time_t actionTime);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t actionCheck = {
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
	static const msg_type_t actionTimeCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		2,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 44) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->actionType != * (int *) &actionCheck)
#else	UseStaticMsgType
	if ((In0P->actionType.msg_type_inline != TRUE) ||
	    (In0P->actionType.msg_type_longform != FALSE) ||
	    (In0P->actionType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->actionType.msg_type_number != 1) ||
	    (In0P->actionType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->actionTimeType != * (int *) &actionTimeCheck)
#else	UseStaticMsgType
	if ((In0P->actionTimeType.msg_type_inline != TRUE) ||
	    (In0P->actionTimeType.msg_type_longform != FALSE) ||
	    (In0P->actionTimeType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->actionTimeType.msg_type_number != 2) ||
	    (In0P->actionTimeType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioStreamControl(audio_port_to_stream(In0P->Head.msg_request_port), In0P->action, In0P->actionTime);
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

/* Routine StreamInfo */
mig_internal novalue _XStreamInfo
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t bytesProcessedType;
		u_int bytesProcessed;
		msg_type_t timeStampType;
		u_int timeStamp;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioStreamInfo (audio_stream_t streamPort, u_int *bytesProcessed, u_int *timeStamp);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t bytesProcessedType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t timeStampType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioStreamInfo(audio_port_to_stream(In0P->Head.msg_request_port), &OutP->bytesProcessed, &OutP->timeStamp);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->bytesProcessedType = bytesProcessedType;
#else	UseStaticMsgType
	OutP->bytesProcessedType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->bytesProcessedType.msg_type_size = 32;
	OutP->bytesProcessedType.msg_type_number = 1;
	OutP->bytesProcessedType.msg_type_inline = TRUE;
	OutP->bytesProcessedType.msg_type_longform = FALSE;
	OutP->bytesProcessedType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->timeStampType = timeStampType;
#else	UseStaticMsgType
	OutP->timeStampType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->timeStampType.msg_type_size = 32;
	OutP->timeStampType.msg_type_number = 1;
	OutP->timeStampType.msg_type_inline = TRUE;
	OutP->timeStampType.msg_type_longform = FALSE;
	OutP->timeStampType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine RemoveStream */
mig_internal novalue _XRemoveStream
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
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
	extern kern_return_t _NXAudioRemoveStream (audio_stream_t streamPort);

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

	OutP->RetCode = _NXAudioRemoveStream(audio_port_to_stream(In0P->Head.msg_request_port));
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

/* Routine PlayStream */
mig_internal novalue _XPlayStream
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_long_t dataType;
		pointer_t data;
		msg_type_t tagType;
		int tag;
		msg_type_t channelCountType;
		u_int channelCount;
		msg_type_t sampleRateType;
		int sampleRate;
		msg_type_t leftGainType;
		u_int leftGain;
		msg_type_t rightGainType;
		u_int rightGain;
		msg_type_t lowWaterType;
		u_int lowWater;
		msg_type_t highWaterType;
		u_int highWater;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t messagesType;
		u_int messages;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioPlayStream (audio_stream_t streamPort, pointer_t data, unsigned int dataCnt, int tag, u_int channelCount, int sampleRate, u_int leftGain, u_int rightGain, u_int lowWater, u_int highWater, port_t streamReply, u_int messages);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t tagCheck = {
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
	static const msg_type_t channelCountCheck = {
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
	static const msg_type_t sampleRateCheck = {
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
	static const msg_type_t leftGainCheck = {
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
	static const msg_type_t rightGainCheck = {
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
	static const msg_type_t lowWaterCheck = {
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
	static const msg_type_t highWaterCheck = {
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
	static const msg_type_t streamReplyCheck = {
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
	static const msg_type_t messagesCheck = {
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
	if ((msg_size != 112) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->dataType.msg_type_header.msg_type_inline != FALSE) ||
	    (In0P->dataType.msg_type_header.msg_type_longform != TRUE) ||
	    (In0P->dataType.msg_type_long_name != MSG_TYPE_BYTE) ||
	    (In0P->dataType.msg_type_long_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->tagType != * (int *) &tagCheck)
#else	UseStaticMsgType
	if ((In0P->tagType.msg_type_inline != TRUE) ||
	    (In0P->tagType.msg_type_longform != FALSE) ||
	    (In0P->tagType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->tagType.msg_type_number != 1) ||
	    (In0P->tagType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->channelCountType != * (int *) &channelCountCheck)
#else	UseStaticMsgType
	if ((In0P->channelCountType.msg_type_inline != TRUE) ||
	    (In0P->channelCountType.msg_type_longform != FALSE) ||
	    (In0P->channelCountType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->channelCountType.msg_type_number != 1) ||
	    (In0P->channelCountType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->sampleRateType != * (int *) &sampleRateCheck)
#else	UseStaticMsgType
	if ((In0P->sampleRateType.msg_type_inline != TRUE) ||
	    (In0P->sampleRateType.msg_type_longform != FALSE) ||
	    (In0P->sampleRateType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->sampleRateType.msg_type_number != 1) ||
	    (In0P->sampleRateType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->leftGainType != * (int *) &leftGainCheck)
#else	UseStaticMsgType
	if ((In0P->leftGainType.msg_type_inline != TRUE) ||
	    (In0P->leftGainType.msg_type_longform != FALSE) ||
	    (In0P->leftGainType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->leftGainType.msg_type_number != 1) ||
	    (In0P->leftGainType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->rightGainType != * (int *) &rightGainCheck)
#else	UseStaticMsgType
	if ((In0P->rightGainType.msg_type_inline != TRUE) ||
	    (In0P->rightGainType.msg_type_longform != FALSE) ||
	    (In0P->rightGainType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->rightGainType.msg_type_number != 1) ||
	    (In0P->rightGainType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->lowWaterType != * (int *) &lowWaterCheck)
#else	UseStaticMsgType
	if ((In0P->lowWaterType.msg_type_inline != TRUE) ||
	    (In0P->lowWaterType.msg_type_longform != FALSE) ||
	    (In0P->lowWaterType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->lowWaterType.msg_type_number != 1) ||
	    (In0P->lowWaterType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->highWaterType != * (int *) &highWaterCheck)
#else	UseStaticMsgType
	if ((In0P->highWaterType.msg_type_inline != TRUE) ||
	    (In0P->highWaterType.msg_type_longform != FALSE) ||
	    (In0P->highWaterType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->highWaterType.msg_type_number != 1) ||
	    (In0P->highWaterType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamReplyType != * (int *) &streamReplyCheck)
#else	UseStaticMsgType
	if ((In0P->streamReplyType.msg_type_inline != TRUE) ||
	    (In0P->streamReplyType.msg_type_longform != FALSE) ||
	    (In0P->streamReplyType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamReplyType.msg_type_number != 1) ||
	    (In0P->streamReplyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->messagesType != * (int *) &messagesCheck)
#else	UseStaticMsgType
	if ((In0P->messagesType.msg_type_inline != TRUE) ||
	    (In0P->messagesType.msg_type_longform != FALSE) ||
	    (In0P->messagesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->messagesType.msg_type_number != 1) ||
	    (In0P->messagesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioPlayStream(audio_port_to_stream(In0P->Head.msg_request_port), In0P->data, In0P->dataType.msg_type_long_number, In0P->tag, In0P->channelCount, In0P->sampleRate, In0P->leftGain, In0P->rightGain, In0P->lowWater, In0P->highWater, In0P->streamReply, In0P->messages);
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

/* Routine SetStreamPeakOptions */
mig_internal novalue _XSetStreamPeakOptions
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t enabledType;
		u_int enabled;
		msg_type_t historyType;
		u_int history;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetStreamPeakOptions (audio_stream_t streamPort, u_int enabled, u_int history);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t enabledCheck = {
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
	static const msg_type_t historyCheck = {
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
	if (* (int *) &In0P->enabledType != * (int *) &enabledCheck)
#else	UseStaticMsgType
	if ((In0P->enabledType.msg_type_inline != TRUE) ||
	    (In0P->enabledType.msg_type_longform != FALSE) ||
	    (In0P->enabledType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->enabledType.msg_type_number != 1) ||
	    (In0P->enabledType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->historyType != * (int *) &historyCheck)
#else	UseStaticMsgType
	if ((In0P->historyType.msg_type_inline != TRUE) ||
	    (In0P->historyType.msg_type_longform != FALSE) ||
	    (In0P->historyType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->historyType.msg_type_number != 1) ||
	    (In0P->historyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetStreamPeakOptions(audio_port_to_stream(In0P->Head.msg_request_port), In0P->enabled, In0P->history);
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

/* Routine GetStreamPeak */
mig_internal novalue _XGetStreamPeak
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t peakLeftType;
		u_int peakLeft;
		msg_type_t peakRightType;
		u_int peakRight;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetStreamPeak (audio_stream_t streamPort, u_int *peakLeft, u_int *peakRight);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t peakLeftType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t peakRightType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetStreamPeak(audio_port_to_stream(In0P->Head.msg_request_port), &OutP->peakLeft, &OutP->peakRight);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 48;	

#if	UseStaticMsgType
	OutP->peakLeftType = peakLeftType;
#else	UseStaticMsgType
	OutP->peakLeftType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->peakLeftType.msg_type_size = 32;
	OutP->peakLeftType.msg_type_number = 1;
	OutP->peakLeftType.msg_type_inline = TRUE;
	OutP->peakLeftType.msg_type_longform = FALSE;
	OutP->peakLeftType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->peakRightType = peakRightType;
#else	UseStaticMsgType
	OutP->peakRightType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->peakRightType.msg_type_size = 32;
	OutP->peakRightType.msg_type_number = 1;
	OutP->peakRightType.msg_type_inline = TRUE;
	OutP->peakRightType.msg_type_longform = FALSE;
	OutP->peakRightType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine RecordStream */
mig_internal novalue _XRecordStream
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t countType;
		u_int count;
		msg_type_t tagType;
		int tag;
		msg_type_t lowWaterType;
		u_int lowWater;
		msg_type_t highWaterType;
		u_int highWater;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t messagesType;
		u_int messages;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioRecordStream (audio_stream_t streamPort, u_int count, int tag, u_int lowWater, u_int highWater, port_t streamReply, u_int messages);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t countCheck = {
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
	static const msg_type_t tagCheck = {
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
	static const msg_type_t lowWaterCheck = {
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
	static const msg_type_t highWaterCheck = {
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
	static const msg_type_t streamReplyCheck = {
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
	static const msg_type_t messagesCheck = {
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
	if ((msg_size != 72) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->countType != * (int *) &countCheck)
#else	UseStaticMsgType
	if ((In0P->countType.msg_type_inline != TRUE) ||
	    (In0P->countType.msg_type_longform != FALSE) ||
	    (In0P->countType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->countType.msg_type_number != 1) ||
	    (In0P->countType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->tagType != * (int *) &tagCheck)
#else	UseStaticMsgType
	if ((In0P->tagType.msg_type_inline != TRUE) ||
	    (In0P->tagType.msg_type_longform != FALSE) ||
	    (In0P->tagType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->tagType.msg_type_number != 1) ||
	    (In0P->tagType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->lowWaterType != * (int *) &lowWaterCheck)
#else	UseStaticMsgType
	if ((In0P->lowWaterType.msg_type_inline != TRUE) ||
	    (In0P->lowWaterType.msg_type_longform != FALSE) ||
	    (In0P->lowWaterType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->lowWaterType.msg_type_number != 1) ||
	    (In0P->lowWaterType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->highWaterType != * (int *) &highWaterCheck)
#else	UseStaticMsgType
	if ((In0P->highWaterType.msg_type_inline != TRUE) ||
	    (In0P->highWaterType.msg_type_longform != FALSE) ||
	    (In0P->highWaterType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->highWaterType.msg_type_number != 1) ||
	    (In0P->highWaterType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamReplyType != * (int *) &streamReplyCheck)
#else	UseStaticMsgType
	if ((In0P->streamReplyType.msg_type_inline != TRUE) ||
	    (In0P->streamReplyType.msg_type_longform != FALSE) ||
	    (In0P->streamReplyType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamReplyType.msg_type_number != 1) ||
	    (In0P->streamReplyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->messagesType != * (int *) &messagesCheck)
#else	UseStaticMsgType
	if ((In0P->messagesType.msg_type_inline != TRUE) ||
	    (In0P->messagesType.msg_type_longform != FALSE) ||
	    (In0P->messagesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->messagesType.msg_type_number != 1) ||
	    (In0P->messagesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioRecordStream(audio_port_to_stream(In0P->Head.msg_request_port), In0P->count, In0P->tag, In0P->lowWater, In0P->highWater, In0P->streamReply, In0P->messages);
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

/* Routine PlayStreamData */
mig_internal novalue _XPlayStreamData
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_long_t dataType;
		pointer_t data;
		msg_type_t tagType;
		int tag;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t messagesType;
		u_int messages;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioPlayStreamData (audio_stream_t streamPort, pointer_t data, unsigned int dataCnt, int tag, port_t streamReply, u_int messages);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t tagCheck = {
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
	static const msg_type_t streamReplyCheck = {
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
	static const msg_type_t messagesCheck = {
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
	if ((msg_size != 64) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->dataType.msg_type_header.msg_type_inline != FALSE) ||
	    (In0P->dataType.msg_type_header.msg_type_longform != TRUE) ||
	    (In0P->dataType.msg_type_long_name != MSG_TYPE_BYTE) ||
	    (In0P->dataType.msg_type_long_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->tagType != * (int *) &tagCheck)
#else	UseStaticMsgType
	if ((In0P->tagType.msg_type_inline != TRUE) ||
	    (In0P->tagType.msg_type_longform != FALSE) ||
	    (In0P->tagType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->tagType.msg_type_number != 1) ||
	    (In0P->tagType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamReplyType != * (int *) &streamReplyCheck)
#else	UseStaticMsgType
	if ((In0P->streamReplyType.msg_type_inline != TRUE) ||
	    (In0P->streamReplyType.msg_type_longform != FALSE) ||
	    (In0P->streamReplyType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamReplyType.msg_type_number != 1) ||
	    (In0P->streamReplyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->messagesType != * (int *) &messagesCheck)
#else	UseStaticMsgType
	if ((In0P->messagesType.msg_type_inline != TRUE) ||
	    (In0P->messagesType.msg_type_longform != FALSE) ||
	    (In0P->messagesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->messagesType.msg_type_number != 1) ||
	    (In0P->messagesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioPlayStreamData(audio_port_to_stream(In0P->Head.msg_request_port), In0P->data, In0P->dataType.msg_type_long_number, In0P->tag, In0P->streamReply, In0P->messages);
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

/* Routine RecordStreamData */
mig_internal novalue _XRecordStreamData
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t countType;
		u_int count;
		msg_type_t tagType;
		int tag;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t messagesType;
		u_int messages;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioRecordStreamData (audio_stream_t streamPort, u_int count, int tag, port_t streamReply, u_int messages);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t countCheck = {
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
	static const msg_type_t tagCheck = {
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
	static const msg_type_t streamReplyCheck = {
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
	static const msg_type_t messagesCheck = {
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
	if ((msg_size != 56) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->countType != * (int *) &countCheck)
#else	UseStaticMsgType
	if ((In0P->countType.msg_type_inline != TRUE) ||
	    (In0P->countType.msg_type_longform != FALSE) ||
	    (In0P->countType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->countType.msg_type_number != 1) ||
	    (In0P->countType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->tagType != * (int *) &tagCheck)
#else	UseStaticMsgType
	if ((In0P->tagType.msg_type_inline != TRUE) ||
	    (In0P->tagType.msg_type_longform != FALSE) ||
	    (In0P->tagType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->tagType.msg_type_number != 1) ||
	    (In0P->tagType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamReplyType != * (int *) &streamReplyCheck)
#else	UseStaticMsgType
	if ((In0P->streamReplyType.msg_type_inline != TRUE) ||
	    (In0P->streamReplyType.msg_type_longform != FALSE) ||
	    (In0P->streamReplyType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamReplyType.msg_type_number != 1) ||
	    (In0P->streamReplyType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->messagesType != * (int *) &messagesCheck)
#else	UseStaticMsgType
	if ((In0P->messagesType.msg_type_inline != TRUE) ||
	    (In0P->messagesType.msg_type_longform != FALSE) ||
	    (In0P->messagesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->messagesType.msg_type_number != 1) ||
	    (In0P->messagesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioRecordStreamData(audio_port_to_stream(In0P->Head.msg_request_port), In0P->count, In0P->tag, In0P->streamReply, In0P->messages);
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

/* Routine GetDeviceName */
mig_internal novalue _XGetDeviceName
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t nameType;
		char name[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDeviceName (audio_device_t devicePort, audio_name_t name, unsigned int *nameCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t nameType = {
		/* msg_type_name = */		MSG_TYPE_CHAR,
		/* msg_type_size = */		8,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int nameCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	nameCnt = 256;

	OutP->RetCode = _NXAudioGetDeviceName(audio_port_to_device(In0P->Head.msg_request_port), OutP->name, &nameCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 292 */

#if	UseStaticMsgType
	OutP->nameType = nameType;
#else	UseStaticMsgType
	OutP->nameType.msg_type_name = MSG_TYPE_CHAR;
	OutP->nameType.msg_type_size = 8;
	OutP->nameType.msg_type_inline = TRUE;
	OutP->nameType.msg_type_longform = FALSE;
	OutP->nameType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->nameType.msg_type_number /* nameCnt */ = /* nameType.msg_type_number */ nameCnt;

	msg_size_delta = (1 * nameCnt + 3) & ~3;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetDeviceParameters */
mig_internal novalue _XSetDeviceParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamOwnerType;
		port_t streamOwner;
		msg_type_t paramsType;
		int params[256];
		msg_type_t valuesType;
		audio_array_t values;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Request *In1P;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetDeviceParameters (audio_device_t devicePort, port_t streamOwner, audio_var_array_t params, unsigned int paramsCnt, audio_array_t values);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t streamOwnerCheck = {
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
	static const msg_type_t valuesCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 1064) || (msg_size > 2088) || (msg_simple != FALSE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->streamOwnerType != * (int *) &streamOwnerCheck)
#else	UseStaticMsgType
	if ((In0P->streamOwnerType.msg_type_inline != TRUE) ||
	    (In0P->streamOwnerType.msg_type_longform != FALSE) ||
	    (In0P->streamOwnerType.msg_type_name != MSG_TYPE_PORT) ||
	    (In0P->streamOwnerType.msg_type_number != 1) ||
	    (In0P->streamOwnerType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->paramsType.msg_type_inline != TRUE) ||
	    (In0P->paramsType.msg_type_longform != FALSE) ||
	    (In0P->paramsType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramsType.msg_type_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	msg_size_delta = 4 * In0P->paramsType.msg_type_number;
#if	TypeCheck
	if (msg_size != 1064 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	In1P = (Request *) ((char *) In0P + msg_size_delta - 1024);

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In1P->valuesType != * (int *) &valuesCheck)
#else	UseStaticMsgType
	if ((In1P->valuesType.msg_type_inline != TRUE) ||
	    (In1P->valuesType.msg_type_longform != FALSE) ||
	    (In1P->valuesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In1P->valuesType.msg_type_number != 256) ||
	    (In1P->valuesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetDeviceParameters(audio_port_to_device(In0P->Head.msg_request_port), In0P->streamOwner, In0P->params, In0P->paramsType.msg_type_number, In1P->values);
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

/* Routine GetDeviceParameters */
mig_internal novalue _XGetDeviceParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t paramsType;
		int params[256];
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t valuesType;
		audio_array_t values;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDeviceParameters (audio_device_t devicePort, audio_var_array_t params, unsigned int paramsCnt, audio_array_t values);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t valuesType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 28) || (msg_size > 1052) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->paramsType.msg_type_inline != TRUE) ||
	    (In0P->paramsType.msg_type_longform != FALSE) ||
	    (In0P->paramsType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramsType.msg_type_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	msg_size_delta = 4 * In0P->paramsType.msg_type_number;
	if (msg_size != 28 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetDeviceParameters(audio_port_to_device(In0P->Head.msg_request_port), In0P->params, In0P->paramsType.msg_type_number, OutP->values);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 1060;	

#if	UseStaticMsgType
	OutP->valuesType = valuesType;
#else	UseStaticMsgType
	OutP->valuesType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->valuesType.msg_type_size = 32;
	OutP->valuesType.msg_type_number = 256;
	OutP->valuesType.msg_type_inline = TRUE;
	OutP->valuesType.msg_type_longform = FALSE;
	OutP->valuesType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetDeviceSupportedParameters */
mig_internal novalue _XGetDeviceSupportedParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t paramsType;
		int params[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDeviceSupportedParameters (audio_device_t devicePort, audio_var_array_t params, unsigned int *paramsCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t paramsType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int paramsCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	paramsCnt = 256;

	OutP->RetCode = _NXAudioGetDeviceSupportedParameters(audio_port_to_device(In0P->Head.msg_request_port), OutP->params, &paramsCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 1060 */

#if	UseStaticMsgType
	OutP->paramsType = paramsType;
#else	UseStaticMsgType
	OutP->paramsType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->paramsType.msg_type_size = 32;
	OutP->paramsType.msg_type_inline = TRUE;
	OutP->paramsType.msg_type_longform = FALSE;
	OutP->paramsType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->paramsType.msg_type_number /* paramsCnt */ = /* paramsType.msg_type_number */ paramsCnt;

	msg_size_delta = 4 * paramsCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetDeviceParameterValues */
mig_internal novalue _XGetDeviceParameterValues
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t paramType;
		int param;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t valuesType;
		int values[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDeviceParameterValues (audio_device_t devicePort, int param, audio_var_array_t values, unsigned int *valuesCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t paramCheck = {
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
	static const msg_type_t valuesType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int valuesCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->paramType != * (int *) &paramCheck)
#else	UseStaticMsgType
	if ((In0P->paramType.msg_type_inline != TRUE) ||
	    (In0P->paramType.msg_type_longform != FALSE) ||
	    (In0P->paramType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramType.msg_type_number != 1) ||
	    (In0P->paramType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	valuesCnt = 256;

	OutP->RetCode = _NXAudioGetDeviceParameterValues(audio_port_to_device(In0P->Head.msg_request_port), In0P->param, OutP->values, &valuesCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 1060 */

#if	UseStaticMsgType
	OutP->valuesType = valuesType;
#else	UseStaticMsgType
	OutP->valuesType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->valuesType.msg_type_size = 32;
	OutP->valuesType.msg_type_inline = TRUE;
	OutP->valuesType.msg_type_longform = FALSE;
	OutP->valuesType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->valuesType.msg_type_number /* valuesCnt */ = /* valuesType.msg_type_number */ valuesCnt;

	msg_size_delta = 4 * valuesCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetSamplingRates */
mig_internal novalue _XGetSamplingRates
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t continuousType;
		int continuous;
		msg_type_t lowType;
		int low;
		msg_type_t highType;
		int high;
		msg_type_t ratesType;
		int rates[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetSamplingRates (audio_device_t devicePort, int *continuous, int *low, int *high, audio_var_array_t rates, unsigned int *ratesCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t continuousType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t lowType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t highType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t ratesType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int ratesCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	ratesCnt = 256;

	OutP->RetCode = _NXAudioGetSamplingRates(audio_port_to_device(In0P->Head.msg_request_port), &OutP->continuous, &OutP->low, &OutP->high, OutP->rates, &ratesCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 60;	
	/* Maximum reply size 1084 */

#if	UseStaticMsgType
	OutP->continuousType = continuousType;
#else	UseStaticMsgType
	OutP->continuousType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->continuousType.msg_type_size = 32;
	OutP->continuousType.msg_type_number = 1;
	OutP->continuousType.msg_type_inline = TRUE;
	OutP->continuousType.msg_type_longform = FALSE;
	OutP->continuousType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->lowType = lowType;
#else	UseStaticMsgType
	OutP->lowType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->lowType.msg_type_size = 32;
	OutP->lowType.msg_type_number = 1;
	OutP->lowType.msg_type_inline = TRUE;
	OutP->lowType.msg_type_longform = FALSE;
	OutP->lowType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->highType = highType;
#else	UseStaticMsgType
	OutP->highType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->highType.msg_type_size = 32;
	OutP->highType.msg_type_number = 1;
	OutP->highType.msg_type_inline = TRUE;
	OutP->highType.msg_type_longform = FALSE;
	OutP->highType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

#if	UseStaticMsgType
	OutP->ratesType = ratesType;
#else	UseStaticMsgType
	OutP->ratesType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->ratesType.msg_type_size = 32;
	OutP->ratesType.msg_type_inline = TRUE;
	OutP->ratesType.msg_type_longform = FALSE;
	OutP->ratesType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->ratesType.msg_type_number /* ratesCnt */ = /* ratesType.msg_type_number */ ratesCnt;

	msg_size_delta = 4 * ratesCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetDataEncodings */
mig_internal novalue _XGetDataEncodings
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t encodingsType;
		int encodings[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetDataEncodings (audio_device_t devicePort, audio_var_array_t encodings, unsigned int *encodingsCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t encodingsType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int encodingsCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	encodingsCnt = 256;

	OutP->RetCode = _NXAudioGetDataEncodings(audio_port_to_device(In0P->Head.msg_request_port), OutP->encodings, &encodingsCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 1060 */

#if	UseStaticMsgType
	OutP->encodingsType = encodingsType;
#else	UseStaticMsgType
	OutP->encodingsType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->encodingsType.msg_type_size = 32;
	OutP->encodingsType.msg_type_inline = TRUE;
	OutP->encodingsType.msg_type_longform = FALSE;
	OutP->encodingsType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->encodingsType.msg_type_number /* encodingsCnt */ = /* encodingsType.msg_type_number */ encodingsCnt;

	msg_size_delta = 4 * encodingsCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetChannelCountLimit */
mig_internal novalue _XGetChannelCountLimit
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t countType;
		u_int count;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetChannelCountLimit (audio_device_t devicePort, u_int *count);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;

#if	UseStaticMsgType
	static const msg_type_t countType = {
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
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetChannelCountLimit(audio_port_to_device(In0P->Head.msg_request_port), &OutP->count);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 40;	

#if	UseStaticMsgType
	OutP->countType = countType;
#else	UseStaticMsgType
	OutP->countType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->countType.msg_type_size = 32;
	OutP->countType.msg_type_number = 1;
	OutP->countType.msg_type_inline = TRUE;
	OutP->countType.msg_type_longform = FALSE;
	OutP->countType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine SetStreamParameters */
mig_internal novalue _XSetStreamParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t paramsType;
		int params[256];
		msg_type_t valuesType;
		audio_array_t values;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Request *In1P;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioSetStreamParameters (audio_stream_t streamPort, audio_var_array_t params, unsigned int paramsCnt, audio_array_t values);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t valuesCheck = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 1056) || (msg_size > 2080) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->paramsType.msg_type_inline != TRUE) ||
	    (In0P->paramsType.msg_type_longform != FALSE) ||
	    (In0P->paramsType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramsType.msg_type_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	msg_size_delta = 4 * In0P->paramsType.msg_type_number;
#if	TypeCheck
	if (msg_size != 1056 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	In1P = (Request *) ((char *) In0P + msg_size_delta - 1024);

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In1P->valuesType != * (int *) &valuesCheck)
#else	UseStaticMsgType
	if ((In1P->valuesType.msg_type_inline != TRUE) ||
	    (In1P->valuesType.msg_type_longform != FALSE) ||
	    (In1P->valuesType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In1P->valuesType.msg_type_number != 256) ||
	    (In1P->valuesType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioSetStreamParameters(audio_port_to_stream(In0P->Head.msg_request_port), In0P->params, In0P->paramsType.msg_type_number, In1P->values);
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

/* Routine GetStreamParameters */
mig_internal novalue _XGetStreamParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t paramsType;
		int params[256];
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t valuesType;
		audio_array_t values;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetStreamParameters (audio_stream_t streamPort, audio_var_array_t params, unsigned int paramsCnt, audio_array_t values);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t valuesType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size < 28) || (msg_size > 1052) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
	if ((In0P->paramsType.msg_type_inline != TRUE) ||
	    (In0P->paramsType.msg_type_longform != FALSE) ||
	    (In0P->paramsType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramsType.msg_type_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

#if	TypeCheck
	msg_size_delta = 4 * In0P->paramsType.msg_type_number;
	if (msg_size != 28 + msg_size_delta)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	OutP->RetCode = _NXAudioGetStreamParameters(audio_port_to_stream(In0P->Head.msg_request_port), In0P->params, In0P->paramsType.msg_type_number, OutP->values);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 1060;	

#if	UseStaticMsgType
	OutP->valuesType = valuesType;
#else	UseStaticMsgType
	OutP->valuesType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->valuesType.msg_type_size = 32;
	OutP->valuesType.msg_type_number = 256;
	OutP->valuesType.msg_type_inline = TRUE;
	OutP->valuesType.msg_type_longform = FALSE;
	OutP->valuesType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetStreamSupportedParameters */
mig_internal novalue _XGetStreamSupportedParameters
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t paramsType;
		int params[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetStreamSupportedParameters (audio_stream_t streamPort, audio_var_array_t params, unsigned int *paramsCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t paramsType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int paramsCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 24) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

	paramsCnt = 256;

	OutP->RetCode = _NXAudioGetStreamSupportedParameters(audio_port_to_stream(In0P->Head.msg_request_port), OutP->params, &paramsCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 1060 */

#if	UseStaticMsgType
	OutP->paramsType = paramsType;
#else	UseStaticMsgType
	OutP->paramsType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->paramsType.msg_type_size = 32;
	OutP->paramsType.msg_type_inline = TRUE;
	OutP->paramsType.msg_type_longform = FALSE;
	OutP->paramsType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->paramsType.msg_type_number /* paramsCnt */ = /* paramsType.msg_type_number */ paramsCnt;

	msg_size_delta = 4 * paramsCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

/* Routine GetStreamParameterValues */
mig_internal novalue _XGetStreamParameterValues
	(msg_header_t *InHeadP, msg_header_t *OutHeadP)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t paramType;
		int param;
	} Request;

	typedef struct {
		msg_header_t Head;
		msg_type_t RetCodeType;
		kern_return_t RetCode;
		msg_type_t valuesType;
		int values[256];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	extern kern_return_t _NXAudioGetStreamParameterValues (audio_stream_t streamPort, int param, audio_var_array_t values, unsigned int *valuesCnt);

#if	TypeCheck
	boolean_t msg_simple;
#endif	TypeCheck

	unsigned int msg_size;
	unsigned int msg_size_delta;

#if	UseStaticMsgType
	static const msg_type_t paramCheck = {
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
	static const msg_type_t valuesType = {
		/* msg_type_name = */		MSG_TYPE_INTEGER_32,
		/* msg_type_size = */		32,
		/* msg_type_number = */		256,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

	unsigned int valuesCnt;

#if	TypeCheck
	msg_size = In0P->Head.msg_size;
	msg_simple = In0P->Head.msg_simple;
	if ((msg_size != 32) || (msg_simple != TRUE))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	TypeCheck

#if	TypeCheck
#if	UseStaticMsgType
	if (* (int *) &In0P->paramType != * (int *) &paramCheck)
#else	UseStaticMsgType
	if ((In0P->paramType.msg_type_inline != TRUE) ||
	    (In0P->paramType.msg_type_longform != FALSE) ||
	    (In0P->paramType.msg_type_name != MSG_TYPE_INTEGER_32) ||
	    (In0P->paramType.msg_type_number != 1) ||
	    (In0P->paramType.msg_type_size != 32))
#endif	UseStaticMsgType
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; goto punt0; }
#define	label_punt0
#endif	TypeCheck

	valuesCnt = 256;

	OutP->RetCode = _NXAudioGetStreamParameterValues(audio_port_to_stream(In0P->Head.msg_request_port), In0P->param, OutP->values, &valuesCnt);
#ifdef	label_punt0
#undef	label_punt0
punt0:
#endif	label_punt0
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	msg_size = 36;	
	/* Maximum reply size 1060 */

#if	UseStaticMsgType
	OutP->valuesType = valuesType;
#else	UseStaticMsgType
	OutP->valuesType.msg_type_name = MSG_TYPE_INTEGER_32;
	OutP->valuesType.msg_type_size = 32;
	OutP->valuesType.msg_type_inline = TRUE;
	OutP->valuesType.msg_type_longform = FALSE;
	OutP->valuesType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	OutP->valuesType.msg_type_number /* valuesCnt */ = /* valuesType.msg_type_number */ valuesCnt;

	msg_size_delta = 4 * valuesCnt;
	msg_size += msg_size_delta;

	OutP->Head.msg_simple = TRUE;
	OutP->Head.msg_size = msg_size;
}

boolean_t audio_server
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

	if ((InP->msg_id > 736) || (InP->msg_id < 700))
		return FALSE;
	else {
		typedef novalue (*SERVER_STUB_PROC)
			(msg_header_t *, msg_header_t *);
		static const SERVER_STUB_PROC routines[] = {
			_XGetExclusiveUser,
			_XSetExclusiveUser,
			_XGetBufferOptions,
			_XSetBufferOptions,
			_XControlStreams,
			_XAddStream,
			_XGetDevicePeakOptions,
			_XSetDevicePeakOptions,
			_XGetDevicePeak,
			_XGetClipCount,
			_XGetSndoutOptions,
			_XSetSndoutOptions,
			_XGetSpeaker,
			_XSetSpeaker,
			_XSetStreamGain,
			_XChangeStreamOwner,
			_XStreamControl,
			_XStreamInfo,
			_XRemoveStream,
			_XPlayStream,
			_XSetStreamPeakOptions,
			_XGetStreamPeak,
			_XRecordStream,
			_XPlayStreamData,
			_XRecordStreamData,
			_XGetDeviceName,
			_XSetDeviceParameters,
			_XGetDeviceParameters,
			_XGetDeviceSupportedParameters,
			_XGetDeviceParameterValues,
			_XGetSamplingRates,
			_XGetDataEncodings,
			_XGetChannelCountLimit,
			_XSetStreamParameters,
			_XGetStreamParameters,
			_XGetStreamSupportedParameters,
			_XGetStreamParameterValues,
		};

		if (routines[InP->msg_id - 700])
			(routines[InP->msg_id - 700]) (InP, &OutP->Head);
		 else
			return FALSE;
	}
	return TRUE;
}
