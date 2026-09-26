/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b707c. */
void __cdecl -[IOAudio _runExclusiveOutputDMA:](IOAudio *self, SEL a2, char a3)
{
  id v3; // eax
  id v4; // eax

  if ( byte_1E5380 != a3 ) /*0x1b7092*/
  {
    if ( a3 ) /*0x1b709a*/
    {
      dword_1E5384 = 0; /*0x1b709c*/
      dword_1E5388 = (int)objc_msgSend(self->_outputChannel, sel_descriptorSize); /*0x1b70b9*/
      dword_1E538C = -[IOAudio interruptClearFunc](self, sel_interruptClearFunc); /*0x1b70cb*/
      objc_msgSend(self->_outputChannel, sel_channelBuffer); /*0x1b70e5*/
      v3 = objc_msgSend(self->_outputChannel, sel_localChannel); /*0x1b70fe*/
      -[IOAudio startDMAForChannel:read:buffer:bufferSizeForInterrupts:]( /*0x1b710f*/
        self,
        sel_startDMAForChannel_read_buffer_bufferSizeForInterrupts_,
        v3);
    }
    else
    {
      v4 = objc_msgSend(self->_outputChannel, sel_localChannel); /*0x1b7128*/
      -[IOAudio stopDMAForChannel:read:](self, sel_stopDMAForChannel_read_, v4); /*0x1b7139*/
    }
    byte_1E5380 = a3; /*0x1b7141*/
  }
}
