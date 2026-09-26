/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7404. */
void __cdecl -[IOAudio getOutputChannelBuffer:size:](IOAudio *self, SEL a2, void *a3, unsigned int *a4)
{
  id v4; // esi

  *(_DWORD *)a3 = objc_msgSend(self->_outputChannel, sel_channelBufferAddress); /*0x1b7426*/
  v4 = objc_msgSend(self->_outputChannel, sel_descriptorSize); /*0x1b743b*/
  *a4 = (_DWORD)objc_msgSend(self->_outputChannel, sel_dmaCount) * (_DWORD)v4; /*0x1b7453*/
}
