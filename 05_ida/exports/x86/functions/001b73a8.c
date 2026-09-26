/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b73a8. */
void __cdecl -[IOAudio getInputChannelBuffer:size:](IOAudio *self, SEL a2, void *a3, unsigned int *a4)
{
  id v4; // esi

  *(_DWORD *)a3 = objc_msgSend(self->_inputChannel, sel_channelBufferAddress); /*0x1b73ca*/
  v4 = objc_msgSend(self->_inputChannel, sel_descriptorSize); /*0x1b73df*/
  *a4 = (_DWORD)objc_msgSend(self->_inputChannel, sel_dmaCount) * (_DWORD)v4; /*0x1b73f7*/
}
