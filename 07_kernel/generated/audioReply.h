#ifndef	__NXAudioReplyaudioReply
#define	__NXAudioReplyaudioReply

/* Module audioReply */

#include <mach/kern_return.h>
#include <mach/port.h>
#include <mach/message.h>

#ifndef	mig_external
#define mig_external extern
#endif

#include <mach/std_types.h>
#include <bsd/dev/audioTypes.h>

/* SimpleRoutine _NXAudioReplyStreamStatus */
mig_external kern_return_t _NXAudioReplyStreamStatus (
	port_t port,
	port_t streamPort,
	port_t streamReply,
	int streamId,
	int tag,
	int status);

/* SimpleRoutine _NXAudioReplyRecordedData */
mig_external kern_return_t _NXAudioReplyRecordedData (
	port_t port,
	port_t streamPort,
	port_t streamReply,
	int streamId,
	int tag,
	dealloc_ptr data,
	unsigned int dataCnt);

#endif	__NXAudioReplyaudioReply
