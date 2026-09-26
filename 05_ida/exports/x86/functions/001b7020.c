/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7020. */
void __cdecl -[IOAudio _getInputChannelBuffer:size:](IOAudio *self, SEL a2, unsigned int *a3, unsigned int *a4)
{
  id v4; // esi

  *a3 = (unsigned int)objc_msgSend(self->_inputChannel, sel_channelBufferAddress); /*0x1b7042*/
  v4 = objc_msgSend(self->_inputChannel, sel_descriptorSize); /*0x1b7057*/
  *a4 = (_DWORD)objc_msgSend(self->_inputChannel, sel_dmaCount) * (_DWORD)v4; /*0x1b706f*/
}
