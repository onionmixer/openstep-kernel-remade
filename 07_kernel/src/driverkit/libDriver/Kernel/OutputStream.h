/*
 * libDriver/Kernel/OutputStream.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/OutputStream.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import "AudioStream.h"
#import "audio_types.h"

typedef struct xfer_record {
    dma_desc_t		*ddp;
    u_int		size;
    u_int		peak_left;
    u_int		peak_right;
    u_int		clips;
    queue_chain_t	link;
} xfer_record_t;

@interface OutputStream: AudioStream
{
    u_int		leftGain;
    u_int		rightGain;
    int			resamplePhase;
    int			channelPhase;
    int			formatPhase;
    queue_head_t	xferQueue;
    BOOL		peakEnabled;
    u_int		peakHistory;
    u_int		*peaksLeft;
    u_int		*peaksRight;
    u_int		currentPeak;
}

- (BOOL)playBuffer:(void *)data size:(u_int)byteCount
                           tag:(int)tag
                       replyTo:(port_t)replyPort
                     replyMsgs:(ASMsgRequest)messages;
- (BOOL)canConvertRegion:(region_t *)region rate:(u_int)srate
    format:(IOAudioDataFormat)format channelCount:(u_int)chans;
- clearForMix:(char *)buf size:(u_int)count format:(IOAudioDataFormat)format;
- (u_int)mixRegion:(region_t *)region descriptor:(dma_desc_t *)ddp
            buffer:(vm_address_t)data maxCount:(u_int)max
            virgin:(BOOL)isVirgin rate:(u_int)srate format:(IOAudioDataFormat)format
	    channelCount:(u_int)chans;
- completeRegion:(region_t *)region descriptor:(dma_desc_t *)ddp
            size:(u_int)xfer used:(u_int *)used;

- (BOOL)isDetectingPeaks;
- (void)setDetectPeaks:(BOOL)flag;
- getPeakLeft:(u_int *)leftPeak right:(u_int *)rightPeak;
- (unsigned int)gainLeft;
- (unsigned int)gainRight;
- (void)setGainLeft:(unsigned int)gain;
- (void)setGainRight:(unsigned int)gain;
- freeRegion:(region_t *)region;
- free;

@end
