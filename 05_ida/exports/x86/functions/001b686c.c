/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b686c. */
void __cdecl -[IOAudio _setInputGainRight:](IOAudio *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  self->_inputGainRight = a3; /*0x1b6875*/
  v3 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b688c*/
  objc_msgSend(v3, sel_send_); /*0x1b6895*/
}
