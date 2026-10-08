/*
 * libDriver/Kernel/InputStream.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/InputStream.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import "AudioStream.h"

@interface InputStream: AudioStream
{
    BOOL wantsRecordedData;
}

- (BOOL)recordSize:(u_int)byteCount tag:(int)aTag
                          replyTo:(port_t)replyPort
                        replyMsgs:(ASMsgRequest)messages;
- (u_int)mixRegion:(region_t *)region descriptor:(dma_desc_t *)ddp
            buffer:(vm_address_t)data maxCount:(u_int)max
            virgin:(BOOL)isVirgin rate:(u_int)srate format:(IOAudioDataFormat)format 
	    channelCount:(u_int)count;
- completeRegion:(region_t *)region descriptor:(dma_desc_t *)ddp
            size:(u_int)xfer used:(u_int *)used;
- returnRecordedData;
- dmaCompleteDescriptor:(dma_desc_t *)ddp transfered:(u_int)count;
- freeRegion:(region_t *)region;

@end
