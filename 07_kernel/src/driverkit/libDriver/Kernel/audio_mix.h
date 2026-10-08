/*
 * libDriver/Kernel/audio_mix.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_mix.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import "audio_types.h"
#import <bsd/sys/types.h>

extern void audio_swapSamples(short *src, short *dest, u_int count);
extern void audio_twosComp8ToUnary(char *src, char *dest, u_int count);
extern u_int audio_scaleSamples(char *src, char *dest, u_int count,
				IOAudioDataFormat format, u_int chanCount,
				int leftGain, int rightGain);
extern void audio_resample22To44(char *src, char *dest, u_int count,
				 IOAudioDataFormat format);	/* plan 342: no channelCount (OutputStream calls in the original bytes) */
extern void audio_resample44To22(char *src, char *dest, u_int count,
				 IOAudioDataFormat format, u_int *phase);
extern void audio_convertMonoToStereo(char *src, char *dest, u_int count,
				      IOAudioDataFormat format);
extern void audio_convertStereoToMono(char *src, char *dest, u_int count,
				      IOAudioDataFormat format, u_int *phase);
extern void audio_convertLinear8ToLinear16(char *src, short *dest,
					   u_int count);
extern void audio_convertLinear8ToMulaw8(char *src, char *dest, u_int count);
extern void audio_convertLinear16ToLinear8(short *src, char *dest, u_int count,
					   u_int *phase);
extern void audio_convertLinear16ToMulaw8(short *src, char *dest, u_int count,
					  u_int *phase);
extern void audio_convertMulaw8ToLinear16(char *src, short *dest, u_int count);
extern void audio_convertMulaw8ToLinear8(char *src, char *dest, u_int count);
extern u_int audio_mix(char *src, char *dest, u_int count,
		       IOAudioDataFormat format, boolean_t virgin);
