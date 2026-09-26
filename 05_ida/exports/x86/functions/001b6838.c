/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6838. */
void __cdecl -[IOAudio _setInputGainLeft:](IOAudio *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  self->_inputGainLeft = a3; /*0x1b6841*/
  v3 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b6858*/
  objc_msgSend(v3, sel_send_); /*0x1b6861*/
}
