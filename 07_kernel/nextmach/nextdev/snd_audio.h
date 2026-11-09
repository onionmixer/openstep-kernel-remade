/*
 * nextdev/snd_audio.h - written by this project (plans 756 and 758, D027, D169, D170).
 *
 * Declarations of the audio layer of the 1997 m68k kernel, used by snd_link.c and
 * snd_server.c, and the definitions of the 1997 sound headers that the shared
 * snd_msgs.h of the 07 tree does not have (D170: they live here, so that the shared
 * header, which the x86 build also reads, is not changed).
 *
 * The identifiers of the audio layer are the original kernel's symbols minus one
 * leading underscore (the symbol ___NXAudioPlayStream is the C identifier
 * __NXAudioPlayStream).  They are defined in snd_server.c: the two device pointers
 * with 0 and the twenty function pointers with snd_audio_not_loaded(), which the
 * audio driver replaces when it is loaded.  The types, the structure snd_owner (its
 * field names port, stream and link are this project's) and the values of the
 * constants are this project's choices that give the original bytes: the bytes fix
 * the widths of the arguments, the layout of the 16-byte owner entry, the sizes and
 * field offsets of the messages and the numeric values.  The names of the
 * NX_SoundStream* and _NXAUDIO_* constants follow the Darwin 0.1 headers
 * (driverkit-1/driverkit/NXSoundParameterTags.h, kernel/bsd/dev/audioTypes.h and
 * snd_msgs.h) for their values; no text of those files is included.
 *
 * Needs <nextdev/snd_var.h> (snd_msgs.h, queue_chain_t, caddr_t) first.
 */
#ifndef _SND_AUDIO_
#define _SND_AUDIO_

/*
 * Messages of the 3.1 sound interface (not in the shared snd_msgs.h)
 */
#define SND_MSG_GET_SNDOUT_FORMATS	(SND_MSG_DEVICE_BASE+15)
#define SND_MSG_GET_SNDIN_FORMATS	(SND_MSG_DEVICE_BASE+16)
typedef msg_header_t snd_get_stream_formats_t;

#define SND_MT_FORMAT			5	// rate, encoding, chan count
typedef struct {
	snd_msg_type_t	msg_type;
	msg_type_t	formatType;
	unsigned int	rate;
#define SND_STREAM_FORMAT_RATE_CONTINUOUS	(1<<0)
#define SND_STREAM_FORMAT_RATE_8000		(1<<1)
#define SND_STREAM_FORMAT_RATE_11025		(1<<2)
#define SND_STREAM_FORMAT_RATE_16000		(1<<3)
#define SND_STREAM_FORMAT_RATE_22050		(1<<4)
#define SND_STREAM_FORMAT_RATE_32000		(1<<5)
#define SND_STREAM_FORMAT_RATE_44100		(1<<6)
#define SND_STREAM_FORMAT_RATE_48000		(1<<7)
	unsigned int	encoding;
#define SND_STREAM_FORMAT_ENCODING_MULAW_8	(1<<0)
#define SND_STREAM_FORMAT_ENCODING_LINEAR_8	(1<<1)
#define SND_STREAM_FORMAT_ENCODING_LINEAR_16	(1<<2)
	unsigned int	chan_count;
} snd_stream_format_t;

/*
 * Stream parameters, sound out options, stream control and messages of the audio layer
 */
#define NX_SoundStreamDataEncoding		400
#define NX_SoundStreamSamplingRate		401
#define NX_SoundStreamChannelCount		402
#define NX_SoundStreamHighWaterMark		403
#define NX_SoundStreamLowWaterMark		404
#define NX_SoundStreamDataEncoding_Linear16	600
#define NX_SoundStreamDataEncoding_Linear8	601
#define NX_SoundStreamDataEncoding_Mulaw8	602
#define _NXAUDIO_PARAM_MAX			256

#define _NXAUDIO_SNDOUT_ZEROFILL		(1<<0)
#define _NXAUDIO_SNDOUT_RAMPUP			(1<<1)
#define _NXAUDIO_SNDOUT_RAMPDOWN		(1<<2)
#define _NXAUDIO_SNDOUT_DEEMPHASIS		(1<<3)
#define _NXAUDIO_SNDOUT_SPEAKER_ON		(1<<4)

#define _NXAUDIO_STREAM_PAUSE			0
#define _NXAUDIO_STREAM_RESUME			1
#define _NXAUDIO_STREAM_ABORT			2
#define _NXAUDIO_STREAM_RETURN_DATA		3

#define _NXAUDIO_RATE_22050			1
#define _NXAUDIO_RATE_44100			2

#define _NXAUDIO_MSG_STARTED			(1<<0)
#define _NXAUDIO_MSG_COMPLETED			(1<<1)
#define _NXAUDIO_MSG_PAUSED			(1<<2)
#define _NXAUDIO_MSG_RESUMED			(1<<3)
#define _NXAUDIO_MSG_ABORTED			(1<<4)
#define _NXAUDIO_MSG_UNDERRUN			(1<<5)

/*
 * Owner entries of the sound in and sound out queues of snd_var (16 bytes)
 */
struct snd_owner {
	port_name_t	port;		// owner port
	caddr_t		stream;		// audio layer stream of the owner, 0 if none yet
	queue_chain_t	link;		// queue of owners
};
extern struct snd_owner *snd_get_owner();

/*
 * The audio layer (defined in snd_server.c)
 */
extern caddr_t _NXAudioSndoutDevice, _NXAudioSndinDevice;
extern int (*__NXAudioGetBufferOptions)();
extern int (*__NXAudioSetBufferOptions)();
extern int (*__NXAudioAddStream)();
extern int (*__NXAudioGetSndoutOptions)();
extern int (*__NXAudioSetSndoutOptions)();
extern int (*__NXAudioGetSpeaker)();
extern int (*__NXAudioSetSpeaker)();
extern int (*__NXAudioStreamControl)();
extern int (*__NXAudioStreamInfo)();
extern int (*__NXAudioRemoveStream)();
extern int (*__NXAudioPlayStream)();
extern int (*__NXAudioRecordStream)();
extern int (*__NXAudioPlayStreamData)();
extern int (*__NXAudioRecordStreamData)();
extern int (*__NXAudioSetStreamParameters)();
extern int (*__NXAudioGetSamplingRates)();
extern int (*__NXAudioGetDataEncodings)();
extern int (*__NXAudioGetChannelCountLimit)();
extern int (*__NXAudioInitLinkedStream)();
extern int (*__NXAudioPortToStream)();

#endif	_SND_AUDIO_
