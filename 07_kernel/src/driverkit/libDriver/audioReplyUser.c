#include "audioReply.h"
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/msg_type.h>
#if	!defined(KERNEL) && !defined(MIG_NO_STRINGS)
#include <strings.h>
#endif
/* LINTLIBRARY */

extern port_t mig_get_reply_port();
extern void mig_dealloc_reply_port();

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

#define msg_request_port	msg_remote_port
#define msg_reply_port		msg_local_port


/* SimpleRoutine StreamStatus */
mig_external kern_return_t _NXAudioReplyStreamStatus (
	port_t port,
	port_t streamPort,
	port_t streamReply,
	int streamId,
	int tag,
	int status)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamPortType;
		port_t streamPort;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t streamIdType;
		int streamId;
		msg_type_t tagType;
		int tag;
		msg_type_t statusType;
		int status;
	} Request;

	union {
		Request In;
	} Mess;

	register Request *InP = &Mess.In;

	unsigned int msg_size = 64;

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

#if	UseStaticMsgType
	static const msg_type_t streamReplyType = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t streamIdType = {
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
	static const msg_type_t tagType = {
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
	static const msg_type_t statusType = {
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
	InP->streamPortType = streamPortType;
#else	UseStaticMsgType
	InP->streamPortType.msg_type_name = MSG_TYPE_PORT;
	InP->streamPortType.msg_type_size = 32;
	InP->streamPortType.msg_type_number = 1;
	InP->streamPortType.msg_type_inline = TRUE;
	InP->streamPortType.msg_type_longform = FALSE;
	InP->streamPortType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamPort /* streamPort */ = /* streamPort */ streamPort;

#if	UseStaticMsgType
	InP->streamReplyType = streamReplyType;
#else	UseStaticMsgType
	InP->streamReplyType.msg_type_name = MSG_TYPE_PORT;
	InP->streamReplyType.msg_type_size = 32;
	InP->streamReplyType.msg_type_number = 1;
	InP->streamReplyType.msg_type_inline = TRUE;
	InP->streamReplyType.msg_type_longform = FALSE;
	InP->streamReplyType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamReply /* streamReply */ = /* streamReply */ streamReply;

#if	UseStaticMsgType
	InP->streamIdType = streamIdType;
#else	UseStaticMsgType
	InP->streamIdType.msg_type_name = MSG_TYPE_INTEGER_32;
	InP->streamIdType.msg_type_size = 32;
	InP->streamIdType.msg_type_number = 1;
	InP->streamIdType.msg_type_inline = TRUE;
	InP->streamIdType.msg_type_longform = FALSE;
	InP->streamIdType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamId /* streamId */ = /* streamId */ streamId;

#if	UseStaticMsgType
	InP->tagType = tagType;
#else	UseStaticMsgType
	InP->tagType.msg_type_name = MSG_TYPE_INTEGER_32;
	InP->tagType.msg_type_size = 32;
	InP->tagType.msg_type_number = 1;
	InP->tagType.msg_type_inline = TRUE;
	InP->tagType.msg_type_longform = FALSE;
	InP->tagType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->tag /* tag */ = /* tag */ tag;

#if	UseStaticMsgType
	InP->statusType = statusType;
#else	UseStaticMsgType
	InP->statusType.msg_type_name = MSG_TYPE_INTEGER_32;
	InP->statusType.msg_type_size = 32;
	InP->statusType.msg_type_number = 1;
	InP->statusType.msg_type_inline = TRUE;
	InP->statusType.msg_type_longform = FALSE;
	InP->statusType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->status /* status */ = /* status */ status;

	InP->Head.msg_simple = FALSE;
	InP->Head.msg_size = msg_size;
	InP->Head.msg_type = MSG_TYPE_NORMAL;
	InP->Head.msg_request_port = port;
	InP->Head.msg_reply_port = PORT_NULL;
	InP->Head.msg_id = 1700;

	return msg_send(&InP->Head, SEND_TIMEOUT|SEND_SWITCH, 1000);
}

/* SimpleRoutine RecordedData */
mig_external kern_return_t _NXAudioReplyRecordedData (
	port_t port,
	port_t streamPort,
	port_t streamReply,
	int streamId,
	int tag,
	dealloc_ptr data,
	unsigned int dataCnt)
{
	typedef struct {
		msg_header_t Head;
		msg_type_t streamPortType;
		port_t streamPort;
		msg_type_t streamReplyType;
		port_t streamReply;
		msg_type_t streamIdType;
		int streamId;
		msg_type_t tagType;
		int tag;
		msg_type_long_t dataType;
		dealloc_ptr data;
	} Request;

	union {
		Request In;
	} Mess;

	register Request *InP = &Mess.In;

	unsigned int msg_size = 72;

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

#if	UseStaticMsgType
	static const msg_type_t streamReplyType = {
		/* msg_type_name = */		MSG_TYPE_PORT,
		/* msg_type_size = */		32,
		/* msg_type_number = */		1,
		/* msg_type_inline = */		TRUE,
		/* msg_type_longform = */	FALSE,
		/* msg_type_deallocate = */	FALSE,
		/* msg_type_unused = */		0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	static const msg_type_t streamIdType = {
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
	static const msg_type_t tagType = {
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
	static const msg_type_long_t dataType = {
	{
		/* msg_type_name = */		0,
		/* msg_type_size = */		0,
		/* msg_type_number = */		0,
		/* msg_type_inline = */		FALSE,
		/* msg_type_longform = */	TRUE,
		/* msg_type_deallocate = */	TRUE,
	},
		/* msg_type_long_name = */	MSG_TYPE_BYTE,
		/* msg_type_long_size = */	8,
		/* msg_type_long_number = */	0,
	};
#endif	UseStaticMsgType

#if	UseStaticMsgType
	InP->streamPortType = streamPortType;
#else	UseStaticMsgType
	InP->streamPortType.msg_type_name = MSG_TYPE_PORT;
	InP->streamPortType.msg_type_size = 32;
	InP->streamPortType.msg_type_number = 1;
	InP->streamPortType.msg_type_inline = TRUE;
	InP->streamPortType.msg_type_longform = FALSE;
	InP->streamPortType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamPort /* streamPort */ = /* streamPort */ streamPort;

#if	UseStaticMsgType
	InP->streamReplyType = streamReplyType;
#else	UseStaticMsgType
	InP->streamReplyType.msg_type_name = MSG_TYPE_PORT;
	InP->streamReplyType.msg_type_size = 32;
	InP->streamReplyType.msg_type_number = 1;
	InP->streamReplyType.msg_type_inline = TRUE;
	InP->streamReplyType.msg_type_longform = FALSE;
	InP->streamReplyType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamReply /* streamReply */ = /* streamReply */ streamReply;

#if	UseStaticMsgType
	InP->streamIdType = streamIdType;
#else	UseStaticMsgType
	InP->streamIdType.msg_type_name = MSG_TYPE_INTEGER_32;
	InP->streamIdType.msg_type_size = 32;
	InP->streamIdType.msg_type_number = 1;
	InP->streamIdType.msg_type_inline = TRUE;
	InP->streamIdType.msg_type_longform = FALSE;
	InP->streamIdType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->streamId /* streamId */ = /* streamId */ streamId;

#if	UseStaticMsgType
	InP->tagType = tagType;
#else	UseStaticMsgType
	InP->tagType.msg_type_name = MSG_TYPE_INTEGER_32;
	InP->tagType.msg_type_size = 32;
	InP->tagType.msg_type_number = 1;
	InP->tagType.msg_type_inline = TRUE;
	InP->tagType.msg_type_longform = FALSE;
	InP->tagType.msg_type_deallocate = FALSE;
#endif	UseStaticMsgType

	InP->tag /* tag */ = /* tag */ tag;

#if	UseStaticMsgType
	InP->dataType = dataType;
#else	UseStaticMsgType
	InP->dataType.msg_type_long_name = MSG_TYPE_BYTE;
	InP->dataType.msg_type_long_size = 8;
	InP->dataType.msg_type_header.msg_type_inline = FALSE;
	InP->dataType.msg_type_header.msg_type_longform = TRUE;
	InP->dataType.msg_type_header.msg_type_deallocate = TRUE;
#endif	UseStaticMsgType

	InP->data /* data */ = /* data */ data;

	InP->dataType.msg_type_long_number /* dataCnt */ = /* dataType.msg_type_long_number */ dataCnt;

	InP->Head.msg_simple = FALSE;
	InP->Head.msg_size = msg_size;
	InP->Head.msg_type = MSG_TYPE_NORMAL;
	InP->Head.msg_request_port = port;
	InP->Head.msg_reply_port = PORT_NULL;
	InP->Head.msg_id = 1701;

	return msg_send(&InP->Head, SEND_TIMEOUT|SEND_SWITCH, 1000);
}
