/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b68a0. */
void __cdecl -[IOAudio _setOutputMute:](IOAudio *self, SEL a2, char a3)
{
  id v3; // eax

  self->_isOutputMuted = a3; /*0x1b68a9*/
  v3 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b68c0*/
  objc_msgSend(v3, sel_send_); /*0x1b68c9*/
}
