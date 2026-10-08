/*
 * libDriver/Kernel/audio_kern_server.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_kern_server.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>
#import <kernserv/kern_server_types.h>
#import <driverkit/IOAudioPrivate.h>

extern void audioKernServInit(kern_server_t *instance_var);
extern boolean_t audio_enroll_stream_port(port_t stream_port,
					  boolean_t enroll);
extern port_t audio_reset_snd_dev_port(IOAudio *dev, port_t priv_port);
