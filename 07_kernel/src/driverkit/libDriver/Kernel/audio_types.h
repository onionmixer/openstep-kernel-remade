/*
 * libDriver/Kernel/audio_types.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_types.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <bsd/dev/audioTypes.h>


#define	ZERO_GAIN		0
#define UNITY_GAIN		32768
#define MULAW8_SILENCE		0x7f
#define UNARY8_SILENCE		0x80
#define MAX_PEAK_HISTORY	16

/*
 * These must match the ones in the mig interface to avoid a translation.
 */

/*
 * Data formats
 */
typedef enum {
    IOAudioDataFormatUnset		= _NXAUDIO_FORMAT_UNSET,
    IOAudioDataFormatLinear16	= _NXAUDIO_FORMAT_LINEAR_16,
    IOAudioDataFormatMulaw8	= _NXAUDIO_FORMAT_MULAW_8,
    IOAudioDataFormatAlaw8	= _NXAUDIO_FORMAT_ALAW_8,
    IOAudioDataFormatLinear8,
    IOAudioDataFormatAES
} IOAudioDataFormat;

/*
 * Soundout option bits - may be OR'ed.
 */
enum {
    AO_OptionZeroFill	= _NXAUDIO_SNDOUT_ZEROFILL,	/* not used */
    AO_OptionRampUp	= _NXAUDIO_SNDOUT_RAMPUP,
    AO_OptionRampDown	= _NXAUDIO_SNDOUT_RAMPDOWN,
    AO_OptionDeemphasis	= _NXAUDIO_SNDOUT_DEEMPHASIS,
    AO_OptionSpeakerOn	= _NXAUDIO_SNDOUT_SPEAKER_ON
};
typedef u_int AOOptions;

/*
 * Soundin options bits
 */
enum {
    AI_OptionMicrophoneOn
};
typedef u_int AIOptions;

/*
 * Stream control actions.
 */
typedef enum {
    AC_ControlPause		= _NXAUDIO_STREAM_PAUSE,
    AC_ControlResume		= _NXAUDIO_STREAM_RESUME,
    AC_ControlAbort		= _NXAUDIO_STREAM_ABORT,
    AC_ControlReturnData	= _NXAUDIO_STREAM_RETURN_DATA,
    AC_ControlExclude
} ACStreamControl;

/*
 * Messages requested to be returned on a stream - may be OR'ed.
 */
enum {
    AS_RequestStarted	= _NXAUDIO_MSG_STARTED,
    AS_RequestCompleted	= _NXAUDIO_MSG_COMPLETED,
    AS_RequestPaused	= _NXAUDIO_MSG_PAUSED,
    AS_RequestResumed	= _NXAUDIO_MSG_RESUMED,
    AS_RequestAborted	= _NXAUDIO_MSG_ABORTED,
    AS_RequestUnderrun	= _NXAUDIO_MSG_UNDERRUN
};
typedef u_int ASMsgRequest;

/*
 * Stream status replies.
 */
typedef enum {
    AS_ReplyStarted	= _NXAUDIO_STATUS_STARTED,
    AS_ReplyCompleted	= _NXAUDIO_STATUS_COMPLETED,
    AS_ReplyPaused	= _NXAUDIO_STATUS_PAUSED,
    AS_ReplyResumed	= _NXAUDIO_STATUS_RESUMED,
    AS_ReplyAborted	= _NXAUDIO_STATUS_ABORTED,
    AS_ReplyUnderrun	= _NXAUDIO_STATUS_UNDERRUN,
    AS_ReplyExcluded	= _NXAUDIO_STATUS_EXCLUDED
} ASReplyMsg;

/*
 * Stream types.
 */
typedef enum {
    AS_TypeUser		= _NXAUDIO_STREAM_TYPE_USER,
    AS_TypeSnd		= _NXAUDIO_STREAM_TYPE_SND,
    AS_TypeSndLink	= _NXAUDIO_STREAM_TYPE_SND_LINK, /* not used */
    AS_TypeSnd22	= _NXAUDIO_STREAM_TYPE_SND_22,
    AS_TypeSnd44	= _NXAUDIO_STREAM_TYPE_SND_44,
    AS_TypeSndCodec	= _NXAUDIO_STREAM_TYPE_SND_CODEC,
    AS_TypeSndMono22	= _NXAUDIO_STREAM_TYPE_SND_MONO_22,
    AS_TypeSndMono44	= _NXAUDIO_STREAM_TYPE_SND_MONO_44
} ASType;
