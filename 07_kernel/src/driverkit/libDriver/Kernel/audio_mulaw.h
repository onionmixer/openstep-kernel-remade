/*
 * libDriver/Kernel/audio_mulaw.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_mulaw.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

extern const short audio_muLaw[];

extern void audio_makeIMuLawTab(void);
extern void audio_freeIMuLawTab(void);
extern unsigned char audio_shortToMulaw(short n);
