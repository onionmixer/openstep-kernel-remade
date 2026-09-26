/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8310. */
void __cdecl -[AudioChannel removeStream:](AudioChannel *self, SEL a2, id a3)
{
  id v3; // eax
  id v4; // eax
  unsigned int *peaksLeft; // eax
  unsigned int *peaksRight; // eax

  v3 = objc_msgSend(a3, sel_userPort); /*0x1b8325*/
  audio_enroll_stream_port(v3, 0); /*0x1b832e*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b833e*/
  if ( objc_msgSend(self->streamList, sel_count) == (id)1 ) /*0x1b8359*/
  {
    objc_msgSend(self->streamListLock, sel_unlock); /*0x1b836a*/
    -[AudioChannel isRead](self, sel_isRead); /*0x1b8377*/
    v4 = objc_msgSend(self->audioDevice, sel__audioCommand); /*0x1b839c*/
    objc_msgSend(v4, sel_send_); /*0x1b83a5*/
    objc_msgSend(self->streamListLock, sel_lock); /*0x1b83b8*/
    peaksLeft = self->peaksLeft; /*0x1b83c0*/
    if ( peaksLeft ) /*0x1b83c5*/
      audio_clear_peaks(peaksLeft, 16); /*0x1b83ca*/
    peaksRight = self->peaksRight; /*0x1b83d2*/
    if ( peaksRight ) /*0x1b83d7*/
      audio_clear_peaks(peaksRight, 16); /*0x1b83dc*/
    self->clipCount = 0; /*0x1b83e4*/
  }
  objc_msgSend(self->streamList, sel_removeObject_, a3); /*0x1b83f7*/
  +[AudioChannel removeStream:](aAudiochannel, sel_removeStream_, a3); /*0x1b840b*/
  objc_msgSend(a3, sel_free); /*0x1b8418*/
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b842b*/
}
