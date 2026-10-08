/*
 * libDriver/Kernel/audio_peak.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_peak.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <bsd/sys/types.h>

extern void audio_mulaw8_peak(u_int chans, unsigned char *buf, u_int count,
			      u_int *peak_left, u_int *peak_right);
extern void audio_linear8_peak(u_int chans, char *buf, u_int count,
			       u_int *peak_left, u_int *peak_right);
extern void audio_linear16_peak(u_int chans, short *buf, u_int count,
				u_int *peak_left, u_int *peak_right);
extern void audio_clear_peaks(u_int *peak_buf, u_int count);
extern u_int audio_max_peak(u_int *peak_buf, u_int count);
extern void audio_add_peak(u_int *peak_buf, u_int peak, u_int *cur,
			   u_int count);
