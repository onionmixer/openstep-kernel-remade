/*
 * libDriver/Kernel/AudioStream.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/AudioStream.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <kern/lock.h>
#import <objc/Object.h>
#import <mach/mach_types.h>
#import <bsd/sys/types.h>
#import <kernserv/queue.h>
#import <machkit/NXLock.h>
#import <sys/time.h>
#import <SoundKit/NXSoundParameterTags.h>	/* plan 342, D042: was driverkit/NXSoundParameterTags.h */
#import "audio_types.h"
#import "AudioChannel.h"

/*
 * For user message sends.
 */
#define STREAM_SEND_OPTIONS	(SEND_TIMEOUT|SEND_SWITCH)
#define STREAM_SEND_TIMEOUT	1000

/*
 * Timed control thread messages.
 */
#define AC_CONTROL_THREAD_MSG	0
typedef struct control_msg {
    msg_header_t	header;
    msg_type_t		args_type;
    id			obj;
    ACStreamControl	action;
    struct timeval	*when;
} control_msg_t;
    
/*
 * Playback or record memory region queue structure.
 */
typedef struct region_flags {
    u_int	started;
    u_int	ended;
    u_int	split;
    u_int	aborted;
    u_int	excluded;
} region_flags_t;

typedef struct region {
    vm_address_t	data;
    vm_address_t	end;
    vm_address_t	enq_ptr;
    vm_address_t	record_ptr;
    u_int		count;
    int			tag;
    u_int      		messages;
    port_t		reply_port;
    dma_desc_t		*start_ddp;
    dma_desc_t		*end_ddp;
    region_flags_t	flags;
#if 0
    boolean_t		marks_bumped;	/* touched water marks */
    vm_address_t	wire_head;	/* wire pointer */
    vm_address_t	wire_tail;	/* unwire pointer */
    boolean_t		active;		/* doing dma */
    boolean_t		underrun;	/* overflow/underrun occured */
    boolean_t		low_reached;	/* reached low water first time */
#endif
    queue_chain_t	link;
} region_t;

@interface AudioStream: Object
{
    id			channel;
    id			device;
    port_t		userPort;
    port_t		kernUserPort;
    port_t		ownerPort;
    int			tag;
    ASType		type;
    u_int		bytesProcessed;
    BOOL		isPaused;
    id			regionQueueLock;
    queue_head_t	regionQueue;
    msg_header_t	*sndReplyMsg;
    port_t		pausePort;
    port_t		resumePort;
    port_t		abortPort;
    struct timeval	pauseTime;
    struct timeval	resumeTime;
    struct timeval	abortTime;
    port_t		userReplyPort;
    ASMsgRequest	userReplyMessages;
    u_int		samplingRate;
    IOAudioDataFormat	dataFormat;
    u_int		channelCount;
    char		*mixBuffer1;
    char		*mixBuffer2;
}

- initChannel:chan tag:(int)aTag user:(port_t *)user
        owner:(port_t)owner type:(u_int)aType;
- (port_t)userPort;
- (port_t)ownerPort;
- channel;
- (ASType)type;
- dmaCompleteDescriptor:(dma_desc_t *)tag transfered:(u_int)count;
- (BOOL)canConvertRegion:(region_t *)region rate:(u_int)srate
    format:(IOAudioDataFormat)format channelCount:(u_int)chans;
- clearForMix:(char *)buf size:(u_int)count format:(IOAudioDataFormat)format;
- (u_int)mixBuffer:(vm_address_t)data maxCount:(u_int)max
              rate:(u_int *)srate format:(IOAudioDataFormat *)format
      channelCount:(u_int *)chans descriptor:(dma_desc_t *)ddp
            virgin:(BOOL)isVirgin streamCount:(u_int)streams;
	    
- (u_int)mixRegion:(region_t *)region descriptor:(dma_desc_t *)ddp
            buffer:(vm_address_t)data maxCount:(u_int)max
            virgin:(BOOL)isVirgin rate:(u_int)srate format:(IOAudioDataFormat)format
	    channelCount:(u_int)chans;

- freeRegion:(region_t *)region;
- (region_t *)newRegion;
- free;
- control:(ACStreamControl)action atTime:(struct timeval)when;
- control:(ACStreamControl)action;
- returnRecordedData;
- setOwner:(port_t)newOwner;
- (BOOL)bytesProcessed:(u_int *)num atTime:(unsigned int *)ts;

- (NXSoundParameterTag)dataEncoding;
- (void)setDataEncoding:(NXSoundParameterTag)encoding;
- (u_int)samplingRate;
- (void)setSamplingRate:(u_int)rate;
- (u_int)channelCount;
- (void)setChannelCount:(u_int)count;
- (u_int)lowWaterMark;
- (void)setLowWaterMark:(u_int)count;
- (u_int)highWaterMark;
- (void)setHighWaterMark:(u_int)count;

@end
