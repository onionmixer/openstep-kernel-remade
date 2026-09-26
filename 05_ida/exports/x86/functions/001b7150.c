/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7150. */
void __cdecl -[IOAudio _runExclusiveInputDMA:](IOAudio *self, SEL a2, char a3)
{
  id v3; // eax
  id v4; // eax

  if ( byte_1E5380 != a3 ) /*0x1b7166*/
  {
    if ( a3 ) /*0x1b716e*/
    {
      dword_1E5384 = 0; /*0x1b7170*/
      dword_1E5388 = (int)objc_msgSend(self->_inputChannel, sel_descriptorSize); /*0x1b718d*/
      dword_1E538C = -[IOAudio interruptClearFunc](self, sel_interruptClearFunc); /*0x1b719f*/
      objc_msgSend(self->_inputChannel, sel_channelBuffer); /*0x1b71b9*/
      v3 = objc_msgSend(self->_inputChannel, sel_localChannel); /*0x1b71d2*/
      -[IOAudio startDMAForChannel:read:buffer:bufferSizeForInterrupts:]( /*0x1b71e3*/
        self,
        sel_startDMAForChannel_read_buffer_bufferSizeForInterrupts_,
        v3);
    }
    else
    {
      v4 = objc_msgSend(self->_inputChannel, sel_localChannel); /*0x1b71fc*/
      -[IOAudio stopDMAForChannel:read:](self, sel_stopDMAForChannel_read_, v4); /*0x1b720d*/
    }
    byte_1E5380 = a3; /*0x1b7215*/
  }
}
