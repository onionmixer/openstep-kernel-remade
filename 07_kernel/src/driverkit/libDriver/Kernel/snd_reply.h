/*
 * libDriver/Kernel/snd_reply.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/snd_reply.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>
#import <mach/message.h>
#import <bsd/sys/types.h>

extern void audio_snd_reply_ret_device (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	port_name_t	device_port);	// returned port.
extern void audio_snd_reply_ret_stream (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	port_name_t	stream_port);	// returned port.
extern void audio_snd_reply_illegal_msg (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	local_port,	// returned port of interest
	port_name_t	remote_port,	// who to send it to.
	int		msg_id,		// message id with illegal syntax
	int		error);		// error code	
extern void audio_snd_reply_recorded_data (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to reply to
	int		data_tag,	// tag from region
	pointer_t	data,		// recorded data
	int		nbytes);	// number of bytes of data to send
extern void audio_snd_reply_timed_out (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// tag from region
extern void audio_snd_reply_ret_samples (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		nsamples,	// number of bytes of data to record
	int		timeStamp);
extern void audio_snd_reply_overflow (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_started (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_completed (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_aborted (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_paused (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_resumed (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	int		data_tag);	// from region
extern void audio_snd_reply_ret_parms (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	u_int		parms);
extern void audio_snd_reply_ret_volume (
	msg_header_t    *out_msg,	// allocated message
	port_name_t	remote_port,	// who to send it to.
	u_int		volume);	
extern void audio_snd_reply_ret_formats(msg_header_t *msg,
				  port_name_t remote_port,
				  u_int rates, u_int low, u_int high,
				  u_int encodings, u_int chans);
