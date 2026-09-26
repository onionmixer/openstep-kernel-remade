/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8200. */
char __cdecl -[AudioChannel addStreamTag:user:owner:type:](
        AudioChannel *self,
        SEL a2,
        int a3,
        int *a4,
        int a5,
        unsigned int a6)
{
  id v6; // eax
  id v7; // eax
  id v8; // ebx

  if ( !(unsigned __int8)objc_msgSend(self->audioDevice, sel__channelWillAddStream) ) /*0x1b8217*/
    return 0; /*0x1b8217*/
  v6 = -[AudioChannel streamClass](self, sel_streamClass); /*0x1b8247*/
  v7 = objc_msgSend(v6, sel_alloc); /*0x1b8250*/
  v8 = objc_msgSend(v7, sel_initChannel_tag_user_owner_type_); /*0x1b825e*/
  if ( !v8 ) /*0x1b8265*/
    return 0; /*0x1b8267*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b827b*/
  if ( objc_msgSend(self->streamList, sel_count) || -[AudioChannel createChannelBuffer](self, sel_createChannelBuffer) ) /*0x1b829f*/
  {
    objc_msgSend(self->streamList, sel_addObject_, v8); /*0x1b82cc*/
    objc_msgSend(self->streamListLock, sel_unlock); /*0x1b82dc*/
    +[AudioChannel addStream:](aAudiochannel, sel_addStream_, v8); /*0x1b82f0*/
    return audio_enroll_stream_port(*a4, 1); /*0x1b82fd*/
  }
  else
  {
    objc_msgSend(self->streamListLock, sel_unlock); /*0x1b82b6*/
    return 0; /*0x1b82bb*/
  }
}
