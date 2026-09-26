/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b65ec. */
void __cdecl -[IOAudio _stopDMAForChannel:](IOAudio *self, SEL a2, id a3)
{
  id v3; // eax

  objc_msgSend(a3, sel_isRead); /*0x1b65ff*/
  v3 = objc_msgSend(a3, sel_localChannel); /*0x1b6610*/
  -[IOAudio stopDMAForChannel:read:](self, sel_stopDMAForChannel_read_, v3); /*0x1b6621*/
  objc_msgSend(a3, sel_freeDescriptors); /*0x1b662e*/
  if ( (unsigned __int8)objc_msgSend(a3, sel_isRead) ) /*0x1b663e*/
    -[IOAudio _setInputActive:](self, sel__setInputActive_, 0); /*0x1b6652*/
  else
    -[IOAudio _setOutputActive:](self, sel__setOutputActive_, 0); /*0x1b665e*/
  if ( !-[IOAudio isInputActive](self, sel_isInputActive) && !-[IOAudio isOutputActive](self, sel_isOutputActive) ) /*0x1b6682*/
    -[IOAudio _setTimeout:](self, sel__setTimeout_, -1); /*0x1b6698*/
}
