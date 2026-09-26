/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b68d4. */
void __cdecl -[IOAudio _setLoudnessEnhanced:](IOAudio *self, SEL a2, char a3)
{
  id v3; // eax

  self->_isLoudnessEnhanced = a3; /*0x1b68dd*/
  v3 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b68f4*/
  objc_msgSend(v3, sel_send_); /*0x1b68fd*/
}
