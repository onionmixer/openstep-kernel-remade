/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6908. */
void __cdecl -[IOAudio _setOutputAttenuationLeft:](IOAudio *self, SEL a2, int a3)
{
  id v3; // eax

  self->_outputAttenuationLeft = a3; /*0x1b6911*/
  v3 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b6928*/
  objc_msgSend(v3, sel_send_); /*0x1b6931*/
}
