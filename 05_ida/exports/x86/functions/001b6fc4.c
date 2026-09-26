/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6fc4. */
void __cdecl -[IOAudio _getOutputChannelBuffer:size:](IOAudio *self, SEL a2, unsigned int *a3, unsigned int *a4)
{
  id v4; // esi

  *a3 = (unsigned int)objc_msgSend(self->_outputChannel, sel_channelBufferAddress); /*0x1b6fe6*/
  v4 = objc_msgSend(self->_outputChannel, sel_descriptorSize); /*0x1b6ffb*/
  *a4 = (_DWORD)objc_msgSend(self->_outputChannel, sel_dmaCount) * (_DWORD)v4; /*0x1b7013*/
}
