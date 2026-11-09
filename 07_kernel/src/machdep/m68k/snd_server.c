/* 
 * Copyright (c) 1988 NeXT, Inc.
 */
/*
 * HISTORY
 *  7-Oct-90  Gregg Kellogg (gk) at NeXT
 *	Change assertion to error return if doing a stream operation on a
 *	channel that hasn't been initialized yet (bug 5567).
 *
 * 28-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Take out hack to deallocate our remaining VM space when shutting down.
 *	(It's left in for debugging purposes).
 *
 * 22-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Change protocol to not pass owner port in msg_remote_port field.
 *
 *  1-Aug-90  Gregg Kellogg (gk) at NeXT
 *	Added stream_ndma message to set the number of dma descriptors
 *	used on a stream.
 *
 * 20-Jul-90  Matt Christiano (mchristo) at NeXT
 *	Added set ramp message
 *
 *  9-May-90  Matt Christiano (mchristo) at NeXT
 *	Miscellaneous changes for DMA out to DSP and user initiated DMA.
 *
 * 28-Aug-89  Gregg Kellogg (gk) at NeXT
 *	In snd_port_gone, when all of the owner ports have been deallocated,
 *	and all resources _should_ be freed the remaining portion of the
 *	task virtual memory space is deleted.  This should never happen,
 *	and hardly ever does.
 *
 * 25-Jun-89  Gregg Kellogg (gk) at NeXT, Inc.
 *	fixed a bug in which snd_stream_abort was returning a multiple
 *	reply to this RPC.
 *
 * 10-Dec-88  Gregg Kellogg (gk) at NeXT
 *	Created.
 *
 */ 

#import <sound.h>
#if	NSOUND > 0

/*
 * Kernel Sound server.
 *
 * This implements the server interface to the sound driver (DSP DAC/ADC).
 *
 * The server is accessed using several different ports
 *	Device port - used to gain further access to sound facilities
 *		and control other sound-related parameters.
 *
 *	Stream port - used for playing/recording data for a specific
 *		destination.  There are several ports for access to
 *		the DSP, one for sound input from the CODEC and two for
 *		each output rate to the DAC's.
 *
 *	DSP command port - used for sending command streams to the DSP.
 *
 * To access these services one or more ownership rights must be established:
 * to access the DAC's a port must be registered as the "sound out owner".
 * This port is used to allocate the sound out stream ports.  When this port
 * is destroyed internal resources are deallocated and the device is reset.
 * There also exist ownership ports for the DSP and sound in.
 */
/*
 * plan 759 (D170, D013, D024, D104): the 1997 m68k snd_server.c.
 * NeXTMach mk-108.1 nextdev/snd_server.c with its notice and HISTORY kept and the
 * 1997 changes, written from the original bytes [0x4085920, 0x4087272) (plans
 * 757-759):
 *	functions that differ from NeXTMach: snd_port_alloc, snd_server_loop, snd_device_port_msg, snd_stream_port_msg, snd_port_gone
 *	new functions: snd_audio_not_loaded, snd_owner_add, snd_get_owner, snd_owner_remove, snd_get_stream_formats, snd_nx_encoding, snd_set_stream_format
 *	The owners of sound in and sound out are queues of struct snd_owner entries
 *	(snd_var.sndin_owners, snd_var.sndout_owners; snd_get_owner() finds one by its
 *	port) instead of one port each; the streams of sound in and sound out and the
 *	device parameters are reached through the audio layer, the twenty function
 *	pointers __NXAudio* (defined here, all snd_audio_not_loaded() until the audio
 *	driver is loaded; declared in <nextdev/snd_audio.h>, this project's header),
 *	and only the dsp streams use the NeXTMach region queues; the ports are
 *	allocated in snd_var.task_space.  The functions snd_get_stream_formats,
 *	snd_nx_encoding and snd_set_stream_format and the structure of the message
 *	handlers were written from the bytes with the structure of Darwin 0.1
 *	driverkit-1/libDriver/Kernel/snd_server.m as a reference (no text of it is
 *	included; the forms are nearly the same as that file's).
 * The original has no symbols for its static functions and static data: the
 * NeXTMach statics keep their names; snd_owner_add, snd_owner_remove,
 * snd_get_stream_formats, snd_nx_encoding, snd_set_stream_format, the field names
 * of struct snd_owner and the local names added in the marked regions are given by
 * this project (D170).  The loops of NEW_DEVICE_PORT that do not advance their
 * variable, the empty-queue tests and the order of the statements are forms that
 * give the original bytes, not evidence of the original source.  The file compiles
 * with the known warnings of the acceptance record (kfree and thread_wakeup
 * argument types, as NeXTMach).  Lines marked plan 759, and the lines of a plan
 * 759 BEGIN/END region (which may include unchanged lines), differ from NeXTMach.
 */

#import <mach/notify.h>	/* plan 759 (D104): NeXTMach <sys/notify.h> */
#import <kern/kern_port.h>
/* plan 759 (D024): NeXTMach lines 69-70 removed (not in the 1997 kernel) */
#import <nextdev/snd_var.h>
#import <nextdev/snd_snd.h>
#import <nextdev/snd_dsp.h>
#import <kern/host.h>
#import <kern/xpr.h>
#import <nextdev/snd_audio.h>	/* plan 759 (D170): this project's audio layer declarations (07 nextdev/snd_audio.h) */

#if	XPR_DEBUG
extern int sdbgflag;
#define snd_dbug(f) {if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#define snd_dbug2(f) if (sdbgflag&2){if (sdbgflag&1)printf f; else XPR(XPR_SOUND, f);}
#else	XPR_DEBUG
#define snd_dbug(f)
#define snd_dbug2(f)
#endif	XPR_DEBUG

snd_var_t snd_var;	/* plan 759 (D170): a COMMON definition, as NeXTMach */
extern dsp_var_t dsp_var;
/* plan 759 (D024, D170) BEGIN: declarations and data */
extern void panic();
extern int snd_dsp_cmd_port_msg();

extern int snd_link_abort();	/* plan 759 (D024): K&R declaration; snd_link_abort() is not in the 1997 snd_var.h */

int snd_audio_not_loaded();
caddr_t _NXAudioSndoutDevice = 0;
caddr_t _NXAudioSndinDevice = 0;
int (*__NXAudioGetBufferOptions)() = snd_audio_not_loaded;
int (*__NXAudioSetBufferOptions)() = snd_audio_not_loaded;
int (*__NXAudioAddStream)() = snd_audio_not_loaded;
int (*__NXAudioGetSndoutOptions)() = snd_audio_not_loaded;
int (*__NXAudioSetSndoutOptions)() = snd_audio_not_loaded;
int (*__NXAudioGetSpeaker)() = snd_audio_not_loaded;
int (*__NXAudioSetSpeaker)() = snd_audio_not_loaded;
int (*__NXAudioStreamControl)() = snd_audio_not_loaded;
int (*__NXAudioStreamInfo)() = snd_audio_not_loaded;
int (*__NXAudioRemoveStream)() = snd_audio_not_loaded;
int (*__NXAudioPlayStream)() = snd_audio_not_loaded;
int (*__NXAudioRecordStream)() = snd_audio_not_loaded;
int (*__NXAudioPlayStreamData)() = snd_audio_not_loaded;
int (*__NXAudioRecordStreamData)() = snd_audio_not_loaded;
int (*__NXAudioSetStreamParameters)() = snd_audio_not_loaded;
int (*__NXAudioGetSamplingRates)() = snd_audio_not_loaded;
int (*__NXAudioGetDataEncodings)() = snd_audio_not_loaded;
int (*__NXAudioGetChannelCountLimit)() = snd_audio_not_loaded;
int (*__NXAudioInitLinkedStream)() = snd_audio_not_loaded;
int (*__NXAudioPortToStream)() = snd_audio_not_loaded;
/* plan 759 END */

/*
 * Locally used functions
 */
static int snd_device_port_msg(msg_header_t *msg);
static int snd_stream_port_msg(snd_stream_msg_t *msg);
static void snd_port_gone(port_name_t port);

/* plan 759 (D024, D170) BEGIN: snd_audio_not_loaded, snd_port_alloc */
int snd_audio_not_loaded()
{
	static int warned = 0;

	if (!warned) {
		printf("SoundDSP: audio driver not loaded!\n");
		warned = 1;
	}
	return 5;
}

static void snd_port_alloc(port_name)
{
	port_name_t new_port;

	if (port_allocate(snd_var.task_space, &new_port) != KERN_SUCCESS)
		panic("sound: can't allocate port");

	if (new_port != port_name)
	    if (port_rename(snd_var.task_space, new_port, port_name) != KERN_SUCCESS)
		panic("sound: can't rename port");

	if (port_set_add(snd_var.task_space, snd_var.portset, port_name))
		panic("sound: can't add port to port_set");
}
/* plan 759 END */


void snd_server_loop(void)
{
#if	DEBUG
	int foo[100];
	snd_server_loop1();
}
snd_server_loop1()
{
	int foo[100];
	snd_server_loop2();
}
snd_server_loop2()
{
#endif	DEBUG
/* plan 759 (D024, D170) BEGIN: snd_device_port_msg, snd_get_owner, snd_get_stream_formats, snd_nx_encoding, snd_owner_add, snd_owner_remove, snd_port_gone, snd_server_loop, snd_set_stream_format, snd_stream_port_msg */
	msg_return_t	r;
	port_name_t	my_notify;
	port_name_t	new_port;
	kern_port_t	kport;
	vm_offset_t	messages;
	register
	msg_header_t	*in_msg;
	int		in_msg_size;
	int		error;
	register int	i;

	/*
	 *	Find out who we are.
	 */

	snd_var.task = current_task();
	snd_var.task->kernel_vm_space = TRUE;
	snd_var.task_space = snd_var.task->itk_space;

	snd_var.task_port = task_self();
	snd_var.task_map = current_task()->map;

	queue_init(&snd_var.sndout_owners);
	queue_init(&snd_var.sndin_owners);

	r = port_set_allocate(snd_var.task_space, &snd_var.portset);
	if (r != KERN_SUCCESS)
		panic("sound: can't allocate port set");

	r = port_allocate(snd_var.task_space, &my_notify);
	if (r != KERN_SUCCESS)
		panic("sound: can't allocate port notify port");

	if (!object_copyin(snd_var.task, my_notify,
			   MSG_TYPE_PORT, FALSE,
			   &kport))
		panic("sound: object_copyin(notify) failed");

	r = task_set_special_port(snd_var.task, TASK_NOTIFY_PORT,
		(port_t)kport);
	if (r != KERN_SUCCESS)
		panic("sound: task_set_special_port(notify)");

	r = port_set_add(snd_var.task_space, snd_var.portset, my_notify);
	if (r != KERN_SUCCESS)
		panic("sound: port_set_add(notify)");

	kport = (kern_port_t)ipc_port_copy_send(realhost.host_priv_self);
	object_copyout(snd_var.task, kport,
			MSG_TYPE_PORT, &snd_var.host_priv_self);

	/*
	 * Allocate Device port.
	 */
	if (   port_allocate(snd_var.task_space, &snd_var.dev_port) != KERN_SUCCESS
	    ||    port_set_add(snd_var.task_space, snd_var.portset, snd_var.dev_port)
	       != KERN_SUCCESS)
		panic("sound: can't allocate device port\n");

	/*
	 *	Release kernel to continue.
	 */
	thread_wakeup((int) &snd_var.task_port);

	task_name("sound-device");

	/*
	 * Initialize lower levels.
	 */
	snd_device_init(SND_DIR_PLAY);
	dsp_dev_init();
	dsp_dev_reset_hard();
	snd_stream_init();

	/*
	 *	Service loop... receive messages and process them.
	 */

	in_msg = snd_rcv_alloc_msg_frame();
	in_msg_size = in_msg->msg_size;
	for (;;) {
		/*
		 * Check for asynchronous activity requested by
		 * lower levels.
		 */

		/*
		 * Wait for the next request.
		 */
		in_msg->msg_local_port = snd_var.portset;
		in_msg->msg_size = in_msg_size;
		if (   (r = msg_receive(in_msg, MSG_OPTION_NONE, 0))
		    != RCV_SUCCESS)
		{
			if (r != RCV_INTERRUPTED) {
				printf("sound: receive failed, 0x%x.\n", r);
			}
			continue;
		}
		
		/*
		 * Dispatch the message based on it's port.
		 */
		if (in_msg->msg_local_port == snd_var.dev_port)
			error = snd_device_port_msg(in_msg);
		else if (in_msg->msg_local_port == snd_dsp_cmd_port_name())
			error = snd_dsp_cmd_port_msg(in_msg);
		else if (in_msg->msg_local_port == task_notify()) {
			notification_t	*n = (notification_t *) in_msg;
			switch(in_msg->msg_id) {
			case NOTIFY_PORT_DELETED:
				snd_port_gone(n->notify_port);
				break;
			default:
				printf("sound: wierd notification"
					" (%d) port = 0x%x.\n",
					in_msg->msg_id,
					n->notify_port);
				break;
			}
			continue;
		} else
			error =snd_stream_port_msg((snd_stream_msg_t *)in_msg);
		
		if (error)
			/*
			 * Always send a reply.
			 */
			(void) snd_reply_illegal_msg(PORT_NULL,
						in_msg->msg_remote_port,
						in_msg->msg_id, error);
	}
}

static void snd_owner_add(queue_t q, port_name_t port)
{
	struct snd_owner *o = (struct snd_owner *)kalloc(sizeof(struct snd_owner));

	o->port = port;
	o->stream = 0;
	queue_enter(q, o, struct snd_owner *, link);
}

struct snd_owner *snd_get_owner(queue_t q, port_name_t port)
{
	struct snd_owner *o;

	if (queue_empty(q))
		return 0;
	o = (struct snd_owner *)queue_first(q);
	for (;;) {
		if (o->port != port) {
			o = (struct snd_owner *)queue_next(&o->link);
			if (queue_end(q, (queue_t)o))
				return 0;
		} else
			return o;
	}
}

static void snd_owner_remove(queue_t q, struct snd_owner *o)
{
	queue_remove(q, o, struct snd_owner *, link);
	kfree(o, sizeof(struct snd_owner));
}

static void snd_get_stream_formats(void *dev, int *rates,
				   int *low_rate, int *high_rate,
				   int *encodings, int *chans)
{
	int parms[_NXAUDIO_PARAM_MAX];
	int count, continuous, i;

	(*__NXAudioGetSamplingRates)(dev, &continuous, low_rate,
				     high_rate, parms, &count);

	*rates = 0;
	if (continuous)
		*rates |= SND_STREAM_FORMAT_RATE_CONTINUOUS;
	for (i = 0; i < count; i++) {
		if (parms[i] >= 8000 && parms[i] <= 8013)
			*rates |= SND_STREAM_FORMAT_RATE_8000;
		else switch (parms[i]) {
		case 11025:
			*rates |= SND_STREAM_FORMAT_RATE_11025;
			break;
		case 16000:
			*rates |= SND_STREAM_FORMAT_RATE_16000;
			break;
		case 22050:
			*rates |= SND_STREAM_FORMAT_RATE_22050;
			break;
		case 32000:
			*rates |= SND_STREAM_FORMAT_RATE_32000;
			break;
		case 44100:
			*rates |= SND_STREAM_FORMAT_RATE_44100;
			break;
		case 48000:
			*rates |= SND_STREAM_FORMAT_RATE_48000;
			break;
		default:
			break;
		}
	}

	(*__NXAudioGetDataEncodings)(dev, parms, &count);

	*encodings = 0;
	for (i = 0; i < count; i++)
		switch (parms[i]) {
		case NX_SoundStreamDataEncoding_Mulaw8:
			*encodings |= SND_STREAM_FORMAT_ENCODING_MULAW_8;
			break;
		case NX_SoundStreamDataEncoding_Linear8:
			*encodings |= SND_STREAM_FORMAT_ENCODING_LINEAR_8;
			break;
		case NX_SoundStreamDataEncoding_Linear16:
			*encodings |= SND_STREAM_FORMAT_ENCODING_LINEAR_16;
			break;
		default:
			break;
		}
	(*__NXAudioGetChannelCountLimit)(dev, chans);
}

static int snd_device_port_msg(msg_header_t *msg)
{
	register int r = SND_NO_ERROR;

	switch (msg->msg_id) {
	case SND_MSG_GET_STREAM: {
		snd_get_stream_t *get_stream = (snd_get_stream_t *)msg;
		int local_port;
		port_t new_stream;
		struct snd_owner *o;
		if (msg->msg_size != sizeof(snd_get_stream_t))
			return SND_BAD_PARM;
		
		/*
		 * Make sure the message makes sense.
		 */
		if (   (  get_stream->stream
		        & ~(SND_GD_CHAN_MASK|SND_GD_DEVICE_MASK))
		    || (   snd_gd_isdevice(get_stream->stream)
			&&   snd_gd_chan(get_stream->stream)
			   > snd_gd_chan(SND_GD_SIN))
		    || (   !snd_gd_isdevice(get_stream->stream)
			&& snd_gd_chan(get_stream->stream) < DSP_SO_CHAN))
			return SND_BAD_PARM;

		/*
		 * Reply port must be owner port to get this guy.
		 */
		if (get_stream->stream == SND_GD_SIN) {
			o = snd_get_owner(&snd_var.sndin_owners,
					  get_stream->owner);
			if (o == 0)
				return SND_NOT_OWNER;
			if (o->stream == 0) {
				(*__NXAudioAddStream)(_NXAudioSndinDevice,
					&new_stream, o->port, 0, 1);
				o->stream = (caddr_t)
					(*__NXAudioPortToStream)(new_stream);
			}
		} else if (snd_gd_isdevice(get_stream->stream)) {
			o = snd_get_owner(&snd_var.sndout_owners,
					  get_stream->owner);
			if (o == 0)
				return SND_NOT_OWNER;
			if (o->stream == 0) {
				(*__NXAudioAddStream)(_NXAudioSndoutDevice,
					&new_stream, o->port, 0, 1);
				o->stream = (caddr_t)
					(*__NXAudioPortToStream)(new_stream);
			}
		} else {
			if (get_stream->owner != snd_var.dspowner)
				return SND_NOT_OWNER;
			if (!dsp_var.chan[snd_gd_chan(get_stream->stream)])
				return SND_BAD_CHAN;
		}
		
		local_port = (get_stream->stream | SND_PN_ASSIGNED);

		/*
		 * Return the port.
		 */
		(void) snd_reply_ret_stream(msg->msg_remote_port, local_port);
		r = 0;
		break;
	}
	case SND_MSG_SET_PARMS: {
		snd_set_parms_t *set_parms = (snd_set_parms_t *)msg;
		u_int new_parms = 0;

		if (msg->msg_size != sizeof(snd_set_parms_t))
			return SND_BAD_PARM;

		(*__NXAudioGetSndoutOptions)(_NXAudioSndoutDevice,
					     &new_parms);
		if (set_parms->parms&SND_PARM_ZEROFILL)
			new_parms |= _NXAUDIO_SNDOUT_ZEROFILL;
		else
			new_parms &= ~_NXAUDIO_SNDOUT_ZEROFILL;
		if (set_parms->parms&SND_PARM_SPEAKER)
			new_parms |= _NXAUDIO_SNDOUT_SPEAKER_ON;
		else
			new_parms &= ~_NXAUDIO_SNDOUT_SPEAKER_ON;
		if (set_parms->parms&SND_PARM_LOWPASS)
			new_parms |= _NXAUDIO_SNDOUT_DEEMPHASIS;
		else
			new_parms &= ~_NXAUDIO_SNDOUT_DEEMPHASIS;
		(*__NXAudioSetSndoutOptions)(_NXAudioSndoutDevice, 0,
					     new_parms);
		break;
	}
	case SND_MSG_GET_PARMS: {
		snd_get_parms_t *get_parms = (snd_get_parms_t *)msg;
		u_int new_parms;
		u_int parms = 0;

		if (msg->msg_size != sizeof(snd_get_parms_t))
			return SND_BAD_PARM;

		(*__NXAudioGetSndoutOptions)(_NXAudioSndoutDevice,
					     &new_parms);
		if (new_parms&_NXAUDIO_SNDOUT_ZEROFILL)
			parms |= SND_PARM_ZEROFILL;
		if (new_parms&_NXAUDIO_SNDOUT_SPEAKER_ON)
			parms |= SND_PARM_SPEAKER;
		if (new_parms&_NXAUDIO_SNDOUT_DEEMPHASIS)
			parms |= SND_PARM_LOWPASS;

		(void) snd_reply_ret_parms(msg->msg_remote_port, parms);
		r = 0;
		break;
	}
	case SND_MSG_SET_VOLUME: {
		snd_set_volume_t *set_volume = (snd_set_volume_t *)msg;

		if (msg->msg_size != sizeof(snd_set_volume_t))
			return SND_BAD_PARM;

		snd_device_set_volume(set_volume->volume);
		break;
	}
	case SND_MSG_GET_VOLUME: {
		snd_get_volume_t *get_volume = (snd_get_volume_t *)msg;

		if (msg->msg_size != sizeof(snd_get_volume_t))
			return SND_BAD_PARM;

		(void) snd_reply_ret_volume(msg->msg_remote_port,
				   snd_device_get_volume());
		r = 0;
		break;
	}
	case SND_MSG_GET_SNDOUT_FORMATS: {
		snd_get_stream_formats_t *get_formats =
			(snd_get_stream_formats_t *)msg;
		int rates, low, high, encodings, chans;

		if (msg->msg_size != sizeof(snd_get_stream_formats_t))
			return SND_BAD_PARM;

		snd_get_stream_formats(_NXAudioSndoutDevice, &rates, &low,
				       &high, &encodings, &chans);
		(void) snd_reply_ret_formats(msg->msg_remote_port, rates,
				low, high, encodings, chans);
		r = 0;
		break;
	}
	case SND_MSG_GET_SNDIN_FORMATS: {
		snd_get_stream_formats_t *get_formats =
			(snd_get_stream_formats_t *)msg;
		int rates, low, high, encodings, chans;

		if (msg->msg_size != sizeof(snd_get_stream_formats_t))
			return SND_BAD_PARM;

		snd_get_stream_formats(_NXAudioSndinDevice, &rates, &low,
				       &high, &encodings, &chans);
		(void) snd_reply_ret_formats(msg->msg_remote_port, rates,
				low, high, encodings, chans);
		r = 0;
		break;
	}
	case SND_MSG_SET_RAMP: {
		snd_set_parms_t *set_parms = (snd_set_parms_t *)msg;
		u_int new_parms = 0;

		if (msg->msg_size != sizeof(snd_set_parms_t))
			return SND_BAD_PARM;

		(*__NXAudioGetSndoutOptions)(_NXAudioSndoutDevice,
					     &new_parms);
		if (set_parms->parms&SND_PARM_RAMPUP)
			new_parms |= _NXAUDIO_SNDOUT_RAMPUP;
		else
			new_parms &= ~_NXAUDIO_SNDOUT_RAMPUP;
		if (set_parms->parms&SND_PARM_RAMPDOWN)
			new_parms |= _NXAUDIO_SNDOUT_RAMPDOWN;
		else
			new_parms &= ~_NXAUDIO_SNDOUT_RAMPDOWN;
		(*__NXAudioSetSndoutOptions)(_NXAudioSndoutDevice, 0,
					     new_parms);
		break;
	}
	case SND_MSG_SET_DSPOWNER: {
		snd_set_owner_t *set_owner = (snd_set_owner_t *)msg;
		register int i;
		if (msg->msg_size != sizeof(snd_set_owner_t))
			return SND_BAD_PARM;

		snd_dbug(("snd_device_port_msg: dsp owner 0x%x\n",
			set_owner->owner));
		if (snd_var.dspowner == set_owner->owner)
			dsp_dev_reset_hard();		// reset DSP
		else if (snd_var.dspowner != PORT_NULL) {
			/*
			 * Return the negotiation port to the user.
			 */
			(void) snd_reply_illegal_msg(snd_var.dspnegotiation,
						msg->msg_remote_port,
						msg->msg_id, SND_PORT_BUSY);
			return 0;
		} else {
			dsp_var.msgbuf = (u_int *)kalloc(
				DSP_DEF_BUFSIZE*sizeof(int));
			dsp_var.emsgbuf = dsp_var.msgbuf+DSP_DEF_BUFSIZE;
			/*
			 * Allocate stream ports.
			 */
			for (i = DSP_N_CHAN-1; i >= 0; i--)
				snd_port_alloc(snd_stream_port_name(i, 0));
			snd_port_alloc(snd_dsp_cmd_port_name());
		}

		snd_var.dspowner = set_owner->owner;
		snd_var.dspnegotiation = set_owner->negotiation;
		dsp_dev_init();
		dsp_var.msgp = dsp_var.msgbuf;
		break;
	}
	case SND_MSG_SET_SNDINOWNER: {
		snd_set_owner_t *set_owner = (snd_set_owner_t *)msg;
		struct snd_owner *o;
		struct timeval time_now;
		if (msg->msg_size != sizeof(snd_set_owner_t))
			return SND_BAD_PARM;

		if (_NXAudioSndinDevice == 0) {
			(void) snd_reply_illegal_msg(PORT_NULL,
						msg->msg_remote_port,
						msg->msg_id, SND_PORT_BUSY);
			return 0;
		}
		if (queue_empty(&snd_var.sndin_owners)) {
			snd_port_alloc(snd_stream_port_name(SND_GD_SIN, 1));
			snd_owner_add(&snd_var.sndin_owners, set_owner->owner);
		} else if ((o = snd_get_owner(&snd_var.sndin_owners,
					      set_owner->owner)) == 0) {
			snd_owner_add(&snd_var.sndin_owners, set_owner->owner);
		} else {
			/*
			 * Abort (reset) stream if asserting same owner port.
			 */
			timerclear(&time_now);
			(*__NXAudioStreamControl)(o->stream,
						  _NXAUDIO_STREAM_ABORT,
						  time_now);
		}

		break;
	}
	case SND_MSG_SET_SNDOUTOWNER: {
		snd_set_owner_t *set_owner = (snd_set_owner_t *)msg;
		struct snd_owner *o;
		struct timeval time_now;
		if (msg->msg_size != sizeof(snd_set_owner_t))
			return SND_BAD_PARM;

		if (_NXAudioSndoutDevice == 0) {
			(void) snd_reply_illegal_msg(PORT_NULL,
						msg->msg_remote_port,
						msg->msg_id, SND_PORT_BUSY);
			return 0;
		}
		if (queue_empty(&snd_var.sndout_owners)) {
			snd_port_alloc(snd_stream_port_name(SND_GD_SOUT_44,1));
			snd_port_alloc(snd_stream_port_name(SND_GD_SOUT_22,1));
			snd_owner_add(&snd_var.sndout_owners, set_owner->owner);
		} else if ((o = snd_get_owner(&snd_var.sndout_owners,
					      set_owner->owner)) == 0) {
			snd_owner_add(&snd_var.sndout_owners, set_owner->owner);
		} else {
			timerclear(&time_now);
			(*__NXAudioStreamControl)(o->stream,
						  _NXAUDIO_STREAM_ABORT,
						  time_now);
		}


		break;
	}
	case SND_MSG_DSP_PROTO: {
		snd_dsp_proto_t *dsp_proto = (snd_dsp_proto_t *)msg;
		if (msg->msg_size != sizeof(snd_dsp_proto_t))
			return SND_BAD_PARM;
		
		/*
		 * (Unused) reply port must be owner port to set protocol level
		 */
		if (dsp_proto->owner != snd_var.dspowner)
			return SND_NOT_OWNER;

		if (dsp_proto->proto&SND_DSP_PROTO_LINKOUT) {
			if (!snd_get_owner(&snd_var.sndout_owners,
					   snd_var.dspowner))
				return SND_NOT_OWNER;
			if (!dsp_var.chan[DSP_SO_CHAN])
				return SND_BAD_CHAN;
		}

		if (dsp_proto->proto&SND_DSP_PROTO_LINKIN) {
			if (!snd_get_owner(&snd_var.sndin_owners,
					   snd_var.dspowner))
				return SND_NOT_OWNER;
			if (!dsp_var.chan[DSP_SI_CHAN])
				return SND_BAD_CHAN;
		}

		/*
		 * Make things easy on ourselves when switching from one
		 * dma mode to another.
		 */
		if (   (   (dsp_var.flags&F_MODE_C_DMA)
			&& (dsp_proto->proto&SND_DSP_PROTO_S_DMA))
		    || (   (dsp_var.flags&F_MODE_S_DMA)
			&& (dsp_proto->proto&SND_DSP_PROTO_C_DMA)))
		{
			dsp_dev_new_proto(0);
		}
		dsp_dev_new_proto(dsp_proto->proto);
		break;
	}
	case SND_MSG_GET_DSP_CMD_PORT: {
		snd_get_dsp_cmd_port_t *get_dsp_cmd_port =
			(snd_get_dsp_cmd_port_t *)msg;
		if (msg->msg_size != sizeof(snd_get_dsp_cmd_port_t))
			return SND_BAD_PARM;

		if (get_dsp_cmd_port->owner != snd_var.dspowner)
			return SND_NOT_OWNER;

		snd_reply_dsp_cmd_port(snd_dsp_cmd_port_name(),
			msg->msg_remote_port);
		r = 0;
		break;
	}
	case SND_MSG_NEW_DEVICE_PORT: {
		snd_new_device_t *new_device = (snd_new_device_t *)msg;
		struct snd_owner *o;
		register queue_t q;

		/*
		 * Re-allocate the device port.  All connections are
		 * terminated.
		 */
		if (msg->msg_size != sizeof(snd_new_device_t))
			return SND_BAD_PARM;

		/*
		 * User must pass the host privilege port for this
		 * host in order to re-allocate the device port.
		 */
		if (new_device->priv != snd_var.host_priv_self)
			return SND_BAD_HOST_PRIV;

		q = &snd_var.sndout_owners;
		if (!queue_empty(q)) {
			o = (struct snd_owner *)queue_first(q);
			do {
				snd_port_gone(o->port);
				(void) port_deallocate(snd_var.task_space, o->port);
			} while (!queue_end(q, (queue_t)o));
		}
		q = &snd_var.sndin_owners;
		if (!queue_empty(q)) {
			o = (struct snd_owner *)queue_first(q);
			do {
				snd_port_gone(o->port);
				(void) port_deallocate(snd_var.task_space, o->port);
			} while (!queue_end(q, (queue_t)o));
		}
		if (snd_var.dspowner) {
			snd_port_gone(snd_var.dspowner);
			(void) port_deallocate(snd_var.task_space, snd_var.dspowner);
			snd_var.dspowner = PORT_NULL;
		}
		(void) port_deallocate(snd_var.task_space, snd_var.dev_port);
		(void) port_allocate(snd_var.task_space, &snd_var.dev_port);
		(void )port_set_add(snd_var.task_space, snd_var.portset,
			snd_var.dev_port);
		(void) snd_reply_ret_device(msg->msg_remote_port,
				   snd_var.dev_port);
		r = 0;
		break;
	}

	case SND_MSG_RESET_DSPOWNER: {
		snd_reset_owner_t *reset_owner = (snd_reset_owner_t *)msg;
		
		/*
		 * Change the owner of this port from old_owner to
		 * new_owner;
		 */
		if (msg->msg_size != sizeof(snd_reset_owner_t))
			return SND_BAD_PARM;

		if (reset_owner->old_owner != snd_var.dspowner)
			return SND_NOT_OWNER;

		port_deallocate(snd_var.task_space, snd_var.dspowner);
		snd_var.dspowner = reset_owner->new_owner;
		
		port_deallocate(snd_var.task_space, snd_var.dspnegotiation);
		snd_var.dspnegotiation = reset_owner->new_negotiation;
		r = 0;
		break;
	}

	case SND_MSG_RESET_SNDINOWNER: {
		snd_reset_owner_t *reset_owner = (snd_reset_owner_t *)msg;
		struct snd_owner *o;
		
		/*
		 * Change the owner of this port from old_owner to
		 * new_owner;
		 */
		if (msg->msg_size != sizeof(snd_reset_owner_t))
			return SND_BAD_PARM;

		if ((o = snd_get_owner(&snd_var.sndin_owners,
				       reset_owner->old_owner)) == 0)
			return SND_NOT_OWNER;

		port_deallocate(snd_var.task_space, o->port);
		o->port = reset_owner->new_owner;
		r = 0;
		break;
	}

	case SND_MSG_RESET_SNDOUTOWNER: {
		snd_reset_owner_t *reset_owner = (snd_reset_owner_t *)msg;
		struct snd_owner *o;
		
		/*
		 * Change the owner of this port from old_owner to
		 * new_owner;
		 */
		if (msg->msg_size != sizeof(snd_reset_owner_t))
			return SND_BAD_PARM;

		if ((o = snd_get_owner(&snd_var.sndout_owners,
				       reset_owner->old_owner)) == 0)
			return SND_NOT_OWNER;

		port_deallocate(snd_var.task_space, o->port);
		o->port = reset_owner->new_owner;
		r = 0;
		break;
	}

	default:
		r = SND_BAD_MSG;
		break;
	}

	return r;
}

static int snd_nx_encoding(int encoding)
{
	switch (encoding) {
	case SND_STREAM_FORMAT_ENCODING_LINEAR_16:
		return NX_SoundStreamDataEncoding_Linear16;
	case SND_STREAM_FORMAT_ENCODING_LINEAR_8:
		return NX_SoundStreamDataEncoding_Linear8;
	case SND_STREAM_FORMAT_ENCODING_MULAW_8:
	default:
		return NX_SoundStreamDataEncoding_Mulaw8;
	}
}

static void snd_set_stream_format(int dir, void *stream,
				  int srate, int encoding, int chans,
				  int low_water, int high_water)
{
	int parray[] = { NX_SoundStreamLowWaterMark,
			 NX_SoundStreamHighWaterMark,
			 NX_SoundStreamSamplingRate,
			 NX_SoundStreamDataEncoding,
			 NX_SoundStreamChannelCount };
	int pcount = sizeof(parray)/sizeof(int);
	int pvalues[pcount];

	pvalues[0] = low_water;
	pvalues[1] = high_water;
	pvalues[2] = srate;
	pvalues[3] = snd_nx_encoding(encoding);
	pvalues[4] = chans;
	(*__NXAudioSetStreamParameters)(stream, parray, pcount, pvalues);
}

static int snd_stream_port_msg(snd_stream_msg_t *msg)
{
	snd_msg_type_t *msg_type;
	vm_address_t snd_data;
	vm_size_t snd_size = 0;
	int high_water = 0;
	int low_water = 0;
	int dma_size = 0;
	register int error = 0;
	register int size;
	register port_name_t lport = msg->header.msg_local_port;
	int data_tag = msg->data_tag;
	register port_name_t owner_port = msg->streamOwner;
	caddr_t stream;
	boolean_t is_dsp = FALSE;
	int snd_control = 0;
	boolean_t deactivate = TRUE;
	int options;
	int direction = -1;
	int chan;
	snd_queue_t *q;
	port_name_t reply_port;		// stored in region for event returns
	int sample_rate = 0, data_encoding = 0, chan_count = 0;
	boolean_t set_format = FALSE;
	struct timeval time_now;
	struct snd_owner *o;
	queue_t oq;

	/*
	 * Figure out which queue we are.
	 */
	if (!snd_gd_isdevice(lport)) {
		if (!dsp_var.chan[snd_gd_chan(lport)])
			return SND_BAD_CHAN;
		q = &dsp_var.chan[snd_gd_chan(lport)]->sndq;
		is_dsp = TRUE;
	}

	chan = snd_gd_chan(lport);
	if (snd_gd_isdevice(lport))
		direction = (chan == snd_gd_chan(SND_GD_SIN))
			? SND_DIR_RECORD
			: SND_DIR_PLAY;

	if (!is_dsp) {
		oq = &snd_var.sndout_owners;
		if (direction == SND_DIR_RECORD)
			oq = &snd_var.sndin_owners;
		o = snd_get_owner(oq, owner_port);
		if (o == 0)
			return SND_BAD_CHAN;
		stream = o->stream;
	}

	switch (msg->header.msg_id) {
	case SND_MSG_STREAM_MSG:
		break;	// handled after this
	case SND_MSG_STREAM_NSAMPLES: {
		u_int bytes_processed, time_stamp;
		/*
		 * Return number of samples played/recorded.
		 */
		if (is_dsp)
			snd_reply_ret_samples(msg->header.msg_remote_port,
					      q->nxfer, 0);
		else {
			(*__NXAudioStreamInfo)(stream, &bytes_processed,
					       &time_stamp);
			snd_reply_ret_samples(msg->header.msg_remote_port,
					      bytes_processed, time_stamp);
		}
		return 0;
	}
	default:
		return SND_BAD_MSG;
	}

	size = msg->header.msg_size - sizeof(*msg);
	msg_type = (snd_msg_type_t *)(msg+1);
	while (size > 0) {
		switch (msg_type->type) {
		case SND_MT_PLAY_DATA: {
			snd_stream_play_data_t *stream_play_data =
				(snd_stream_play_data_t *)msg_type;

			*(int *)&msg_type += sizeof(snd_stream_play_data_t);
			size -= sizeof(snd_stream_play_data_t);

			options = stream_play_data->options;
			snd_data = (vm_address_t)stream_play_data->data;
			snd_size = (vm_size_t)
			    stream_play_data->dataType.msg_type_long_number;
			if (!error && direction == SND_DIR_RECORD)
				error = SND_BAD_PARM;

			snd_dbug(("snd_s_port_msg: play %d bytes at 0x%x\n",
			    snd_size, snd_data));

			/*
			 * DSP data must have initialized channel.
			 */
			if (!snd_gd_isdevice(lport)) {
				if (   chan < 0
				    || chan >= DSP_N_CHAN
				    || !dsp_var.chan[chan])
					error = SND_BAD_CHAN;
				else if (   !(dsp_var.flags&F_SOUNDDATA)
				 	 || snd_gd_chan(lport)!=DSP_SI_CHAN)
					dma_size =
					   dsp_var.chan[chan]->buf_size
					 * mode_size(dsp_var.chan[chan]->mode);
			}

			/*
			 * Data destined for, or coming from the DSP when
			 * it's in complex dma mode must be quad aligned.
			 * In any case data must be aligned to the channel
			 * mode size.
			 */
			if (!error && !snd_gd_isdevice(lport)) {
			    if (   (dsp_var.flags&F_SOUNDDATA)
				&& chan == DSP_SI_CHAN)
			    {
				int m_size = mode_size(
				    	dsp_var.chan[DSP_SI_CHAN]->mode);
				if (m_size == 0)
				    error = SND_BAD_PARM;
				else if (snd_data % m_size)
				    error = SND_NOTALIGNED;
			    } else  if (   (dsp_var.flags&F_MODE_C_DMA)
					&& (   dma_size == 0
					    || snd_data%dma_size
					    || snd_size%dma_size))
			    {
				    error = SND_NOTALIGNED;
			    }
			}

			direction = SND_DIR_PLAY;
			break;
		}
		case SND_MT_RECORD_DATA: {
			int r;
			char *filename;
			int filename_len;
			snd_stream_record_data_t *record_data =
				(snd_stream_record_data_t *)msg_type;

			filename_len=record_data->filenameType.msg_type_number;
			r = sizeof(*record_data) + filename_len;
			*(int *)&msg_type += r;
			size -= r;

			filename = (char *)(record_data+1);
			if (filename_len != 0)
				error = SND_NOPAGER;	// not yet.
			else
				deactivate = FALSE;

			snd_size = (vm_size_t)record_data->nbytes;
			snd_dbug(("snd_s_port_msg: record %d bytes\n",
			    snd_size));
			/*
			 * DSP data must have initialized channel.
			 */
			if (!snd_gd_isdevice(lport)) {
				if (   chan < 0
				    || chan >= DSP_N_CHAN
				    || !dsp_var.chan[chan])
					error = SND_BAD_CHAN;
				else
					dma_size =
					   dsp_var.chan[chan]->buf_size
					 * mode_size(dsp_var.chan[chan]->mode);
			}

			/*
			 * Data destined for, or coming from the DSP when
			 * it's in complex dma mode must be quad aligned.
			 */
			if (   !error
			    && !snd_gd_isdevice(lport)
			    && (dsp_var.flags&F_MODE_C_DMA)
			    && ((dma_size == 0) || (snd_size%dma_size)))
				error = SND_NOTALIGNED;

			if (!error && direction == SND_DIR_PLAY)
				error = SND_BAD_PARM;

			direction = SND_DIR_RECORD;
			break;
		}
		case SND_MT_CONTROL: {
			snd_stream_control_t *stream_control =
				(snd_stream_control_t *)msg_type;
			*(int *)&msg_type += sizeof(snd_stream_control_t);
			size -= sizeof(snd_stream_control_t);

			snd_dbug2(("snd_s_port_msg: control 0x%x\n",
			    stream_control->snd_control));
			snd_control |= stream_control->snd_control;
			break;
		}
		case SND_MT_FORMAT: {
			snd_stream_format_t *stream_format =
				(snd_stream_format_t *)msg_type;
			*(int *)&msg_type += sizeof(snd_stream_format_t);
			size -= sizeof(snd_stream_format_t);

			sample_rate = stream_format->rate;
			data_encoding = stream_format->encoding;
			chan_count = stream_format->chan_count;
			set_format = TRUE;
			break;
		}
		case SND_MT_OPTIONS: {
			snd_stream_options_t *stream_options = 
				(snd_stream_options_t *)msg_type;
			u_int dma_cur, dma_count;
			*(int *)&msg_type += sizeof(snd_stream_options_t);
			size -= sizeof(snd_stream_options_t);

			high_water = stream_options->high_water;
			low_water = stream_options->low_water;
			dma_size = stream_options->dma_size;
			snd_dbug(("snd_s_port_msg: high_water 0x%x, "
				  " low_water 0x%x, dma_size 0x%x\n",
			    high_water, low_water, dma_size));

			if (!high_water)
				high_water = snd_gd_isdevice(lport)
					? snd_device_def_high_water(direction)
					: snd_dspcmd_def_high_water(chan);
			if (!low_water)
				low_water = snd_gd_isdevice(lport)
					? snd_device_def_low_water(direction)
					: snd_dspcmd_def_low_water(chan);
			if (!dma_size)
				dma_size = snd_gd_isdevice(lport)
					? snd_device_def_dmasize(direction)
					: snd_dspcmd_def_dmasize(chan);

			/*
			 * PAGE_SIZE must be a multiple of the dma size.
			 */
			if (   dma_size == 0
			    || PAGE_SIZE%dma_size
			    || PAGE_SIZE < dma_size)
				error = SND_BAD_PARM;
			else if (!snd_gd_isdevice(lport)) {
				int bsize = dsp_var.chan[chan]->buf_size
				    * mode_size(dsp_var.chan[chan]->mode);
				if (dma_size != bsize)
					error = SND_BAD_PARM;
			}

			if (!is_dsp) {
				(*__NXAudioGetBufferOptions)(
					direction == SND_DIR_RECORD
					    ? _NXAudioSndinDevice
					    : _NXAudioSndoutDevice,
					&dma_cur, &dma_count);
				(*__NXAudioSetBufferOptions)(
					direction == SND_DIR_RECORD
					    ? _NXAudioSndinDevice
					    : _NXAudioSndoutDevice,
					0, dma_size, dma_count);
			}
			break;
		}
		case SND_MT_NDMA: {
			snd_stream_ndma_t *stream_ndma = 
				(snd_stream_ndma_t *)msg_type;
			u_int dma_cur, dma_count, ndma;
			*(int *)&msg_type += sizeof(snd_stream_ndma_t);
			size -= sizeof(snd_stream_ndma_t);

			if (is_dsp) {
				if (!stream_ndma->ndma)
					q->ndma = 4;
				else
					q->ndma = stream_ndma->ndma;
			} else {
				ndma = stream_ndma->ndma;
				if (!ndma)
					ndma = 4;
				(*__NXAudioGetBufferOptions)(
					direction == SND_DIR_RECORD
					    ? _NXAudioSndinDevice
					    : _NXAudioSndoutDevice,
					&dma_cur, &dma_count);
				(*__NXAudioSetBufferOptions)(
					direction == SND_DIR_RECORD
					    ? _NXAudioSndinDevice
					    : _NXAudioSndoutDevice,
					0, dma_cur, ndma);
			}
			break;
		}
		default:
			error = SND_BAD_MSG;
			size = 0;
			break;
		}
	}

	/*
	 * If we found any errors, cleanup and return an error.
	 */
	if (error) {
	    error_return:
		size = msg->header.msg_size - sizeof(*msg);
		msg_type = (snd_msg_type_t *)(msg+1);
		while (size > 0) {
			switch (msg_type->type) {
			case SND_MT_PLAY_DATA: {
				snd_stream_play_data_t *stream_play_data =
					(snd_stream_play_data_t *)msg_type;
	
				*(int *)&msg_type +=
					sizeof(snd_stream_play_data_t);
				size -= sizeof(snd_stream_play_data_t);
	
				(void) vm_deallocate(snd_var.task_map,
					(vm_address_t)stream_play_data->data,
					stream_play_data->
						dataType.msg_type_long_number);
				break;
			}
			case SND_MT_RECORD_DATA:
				*(int *)&msg_type +=
					sizeof(snd_stream_record_data_t);
				size -= sizeof(snd_stream_record_data_t);
				break;

			case SND_MT_CONTROL:
				*(int *)&msg_type +=
					sizeof(snd_stream_control_t);
				size -= sizeof(snd_stream_control_t);
				break;
	
			case SND_MT_FORMAT:
				*(int *)&msg_type +=
					sizeof(snd_stream_format_t);
				size -= sizeof(snd_stream_format_t);
				break;
	
			case SND_MT_OPTIONS:
				*(int *)&msg_type +=
					sizeof(snd_stream_options_t);
				size -= sizeof(snd_stream_options_t);
				break;
			case SND_MT_NDMA:
				*(int *)&msg_type +=
					sizeof(snd_stream_ndma_t);
				size -= sizeof(snd_stream_ndma_t);
				break;
			default:
				/*
				 * This shouldn't happen.
				 */
				ASSERT(0);
			}
		}
		return error;
	}

	/*
	 * If an option was sent down without a corresponding region
	 * update the defaults in the stream with the new values.
	 */
	if (is_dsp && !snd_size && dma_size) {
		q->dmasize = dma_size;
		q->def_high_water = high_water;
		q->def_low_water = low_water;
	}

	/*
	 * Process message.
	 *
	 * Abortions first.
	 */
	timerclear(&time_now);
	if (snd_control&SND_DC_ABORT) {
		if (is_dsp) {
			snd_link_abort();
			snd_stream_abort(q, data_tag);
		} else
			(*__NXAudioStreamControl)(stream,
				_NXAUDIO_STREAM_ABORT, time_now);
	}


	/*
	 * AWAIT on record sends back recorded data.
	 */
	if (snd_control&SND_DC_AWAIT) {
		if (is_dsp) {
			error = snd_stream_await(q, data_tag);
			if (error)
				goto error_return;
		} else if ((*__NXAudioStreamControl)(stream,
				_NXAUDIO_STREAM_RETURN_DATA, time_now)) {
			error = SND_SEARCH;
			goto error_return;
		}
	}

	/*
	 * Pause play or record
	 */
	if (snd_control&SND_DC_PAUSE) {
		if (is_dsp)
			snd_stream_pause(q);
		else
			(*__NXAudioStreamControl)(stream,
				_NXAUDIO_STREAM_PAUSE, time_now);
	}

	size = msg->header.msg_size - sizeof(*msg);
	msg_type = (snd_msg_type_t *)(msg+1);
	while (size > 0) {
		snd_size = 0;
		switch (msg_type->type) {
		case SND_MT_PLAY_DATA: {
			snd_stream_play_data_t *stream_play_data =
				(snd_stream_play_data_t *)msg_type;

			*(int *)&msg_type += sizeof(snd_stream_play_data_t);
			size -= sizeof(snd_stream_play_data_t);

			options = stream_play_data->options;
			snd_data = (vm_address_t)stream_play_data->data;
			snd_size = (vm_size_t)
			    stream_play_data->dataType.msg_type_long_number;

			/*
			 * Protect this region read-only so that we
			 * don't end up copying all the pages we play.
			 */
			if (is_dsp)
				(void) vm_map_protect(snd_var.task_map,
					    trunc_page(snd_data),
					    round_page(snd_data+snd_size),
					    VM_PROT_READ,
					    FALSE);
			reply_port = stream_play_data->reg_port;
			break;
		}
		case SND_MT_RECORD_DATA: {
			snd_stream_record_data_t *record_data =
				(snd_stream_record_data_t *)msg_type;

			*(int *)&msg_type += sizeof(*record_data);
			size -= sizeof(*record_data);

			options = record_data->options;
			snd_size = (vm_size_t)record_data->nbytes;

			if (is_dsp)
				(void) vm_allocate(snd_var.task_map, &snd_data,
						snd_size, TRUE);

			reply_port = record_data->reg_port;
			break;
		}
		case SND_MT_CONTROL:
			*(int *)&msg_type += sizeof(snd_stream_control_t);
			size -= sizeof(snd_stream_control_t);
			break;
		case SND_MT_FORMAT:
			*(int *)&msg_type += sizeof(snd_stream_format_t);
			size -= sizeof(snd_stream_format_t);
			break;
		case SND_MT_OPTIONS:
			*(int *)&msg_type += sizeof(snd_stream_options_t);
			size -= sizeof(snd_stream_options_t);
			break;
		case SND_MT_NDMA:
			*(int *)&msg_type += sizeof(snd_stream_ndma_t);
			size -= sizeof(snd_stream_ndma_t);
			break;
		default:
			/*
			 * This shouldn't happen.
			 */
			ASSERT(0);
		}

		/*
		 * Send down a region if we have data, or if we need an await
		 * message sent in the future.
		 */
		if (snd_size) {
			snd_region_t *new_reg;
			u_int messages = 0;
	
			if (is_dsp) {
			new_reg = (snd_region_t *)kalloc(sizeof(snd_region_t));
			new_reg->addr = snd_data;
			new_reg->size = snd_size;
			new_reg->reply_port = reply_port;
			new_reg->reg_id = data_tag;
			new_reg->completed = (options&SND_DM_COMPLETED_MSG)!=0;
			new_reg->started = (options&SND_DM_STARTED_MSG) != 0;
			new_reg->aborted = (options&SND_DM_ABORTED_MSG) != 0;
			new_reg->paused = (options&SND_DM_PAUSED_MSG) != 0;
			new_reg->resumed = (options&SND_DM_RESUMED_MSG) != 0;
			new_reg->overflow = (options&SND_DM_OVERFLOW_MSG) != 0;
			new_reg->high_water = high_water;
			new_reg->low_water = low_water;
			new_reg->dma_size = dma_size;
			new_reg->sound_q = q;
			new_reg->direction = direction;
			new_reg->deactivate = deactivate;
	
			new_reg->rate = lport==(SND_GD_SOUT_44|SND_PN_ASSIGNED)
				? SND_RATE_44
				: SND_RATE_22;
			snd_stream_enqueue_region(new_reg, chan,
						  snd_gd_isdevice(lport),
						  (options&SND_DM_PREEMPT));
			} else {
			if ((options&SND_DM_STARTED_MSG) != 0)
				messages |= _NXAUDIO_MSG_STARTED;
			if ((options&SND_DM_COMPLETED_MSG) != 0)
				messages |= _NXAUDIO_MSG_COMPLETED;
			if ((options&SND_DM_PAUSED_MSG) != 0)
				messages |= _NXAUDIO_MSG_PAUSED;
			if ((options&SND_DM_RESUMED_MSG) != 0)
				messages |= _NXAUDIO_MSG_RESUMED;
			if ((options&SND_DM_ABORTED_MSG) != 0)
				messages |= _NXAUDIO_MSG_ABORTED;
			if ((options&SND_DM_OVERFLOW_MSG) != 0)
				messages |= _NXAUDIO_MSG_UNDERRUN;

			if (direction == SND_DIR_PLAY) {
				if (set_format) {
					snd_set_stream_format(direction, stream,
						sample_rate, data_encoding,
						chan_count, low_water,
						high_water);
					(*__NXAudioPlayStreamData)(stream,
						snd_data, snd_size, data_tag,
						reply_port, messages);
				} else {
					int rate = lport == (SND_GD_SOUT_44|SND_PN_ASSIGNED)
						    ? _NXAUDIO_RATE_44100
						    : _NXAUDIO_RATE_22050;
					(*__NXAudioPlayStream)(stream,
						snd_data, snd_size, data_tag,
						2, rate, 32768, 32768,
						low_water, high_water,
						reply_port, messages);
				}
			} else {
				if (set_format) {
					snd_set_stream_format(direction, stream,
						sample_rate, data_encoding,
						chan_count, low_water,
						high_water);
					(*__NXAudioRecordStreamData)(stream,
						snd_size, data_tag,
						reply_port, messages);
				} else {
					(*__NXAudioRecordStream)(stream,
						snd_size, data_tag,
						low_water, high_water,
						reply_port, messages);
				}
			}
			}
		}
	}

	if (snd_control&SND_DC_RESUME) {
		if (is_dsp)
			snd_stream_resume(q);
		else
			(*__NXAudioStreamControl)(stream,
				_NXAUDIO_STREAM_RESUME, time_now);
	}

	return SND_NO_ERROR;
}

/*
 * Got notification that port we have send rights on has gone away, clean up.
 * FIXME: do something about forgeting completion ports and removing
 * record regions.
 */
static void snd_port_gone(port_name_t port)
{
	register int i;
	struct snd_owner *o;

	if (port == snd_var.dspowner) {
		snd_dbug(("snd_port_gone: dsp owner\n"));
		snd_var.dspowner = PORT_NULL;
		/*
		 * Deallocate stream ports
		 */
		for (i = DSP_N_CHAN-1; i >= 0; i--)
			port_deallocate(snd_var.task_space,
				snd_stream_port_name(i, 0));
		port_deallocate(snd_var.task_space, snd_dsp_cmd_port_name());

		dsp_dev_reset_hard();			// reset DSP
		if (dsp_var.msgbuf) {
			kfree((caddr_t)dsp_var.msgbuf,
			    (dsp_var.emsgbuf-dsp_var.msgbuf)*sizeof(u_int *));
			dsp_var.msgbuf = dsp_var.emsgbuf = dsp_var.msgp = 0;
		}
		if (dsp_var.errbuf) {
			kfree((caddr_t)dsp_var.errbuf,
			    (dsp_var.eerrbuf-dsp_var.errbuf)*sizeof(u_int *));
		    dsp_var.errbuf = dsp_var.eerrbuf = dsp_var.errp = 0;
		}
		
	}
	if (o = snd_get_owner(&snd_var.sndin_owners, port)) {
		if (o->stream)
			(*__NXAudioRemoveStream)(o->stream);
		snd_owner_remove(&snd_var.sndin_owners, o);
		if (queue_empty(&snd_var.sndin_owners))
			port_deallocate(snd_var.task_space,
				snd_stream_port_name(SND_GD_SIN, 1));
	}
	if (o = snd_get_owner(&snd_var.sndout_owners, port)) {
		if (o->stream)
			(*__NXAudioRemoveStream)(o->stream);
		snd_owner_remove(&snd_var.sndout_owners, o);
		if (queue_empty(&snd_var.sndout_owners)) {
			port_deallocate(snd_var.task_space,
				snd_stream_port_name(SND_GD_SOUT_44, 1));
			port_deallocate(snd_var.task_space,
				snd_stream_port_name(SND_GD_SOUT_22, 1));
		}
	}

	if (   queue_empty(&snd_var.sndin_owners)
	    && queue_empty(&snd_var.sndout_owners)
	    && !snd_var.dspowner
	    && snd_var.task_map->size) {
		/*
		 * If all ownership has been revoked then ensure that we don't
		 * have any memory left in our task map (we shouldn't, but
		 * sometimes it doesn't seem to go away.
		 */
		vm_deallocate(snd_var.task_map,
				vm_map_min(snd_var.task_map),
				vm_map_max(snd_var.task_map));
	}
}
/* plan 759 END */
#endif	NSOUND > 0
