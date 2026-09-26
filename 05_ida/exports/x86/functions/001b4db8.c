/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b4db8. */
char __cdecl -[IOAudio _attemptToStartDMAForChannel:channelStatus:](IOAudio *self, SEL a2, id a3, char a4)
{
  unsigned int i; // ebx
  id v5; // eax
  id v6; // eax
  id v8; // [esp-Ch] [ebp-30h]
  int v9; // [esp-Ch] [ebp-30h]
  char v10; // [esp+Ch] [ebp-18h]
  _DWORD v11[2]; // [esp+10h] [ebp-14h] BYREF
  id v12; // [esp+18h] [ebp-Ch] BYREF
  unsigned int dataEncoding; // [esp+1Ch] [ebp-8h] BYREF
  id v14; // [esp+20h] [ebp-4h] BYREF

  v14 = nullptr; /*0x1b4dca*/
  dataEncoding = -1; /*0x1b4dd1*/
  v12 = nullptr; /*0x1b4dd8*/
  v10 = 0; /*0x1b4ddf*/
  if ( a4 ) /*0x1b4de5*/
  {
    v14 = -[IOAudio sampleRate](self, sel_sampleRate); /*0x1b4df4*/
    dataEncoding = self->_dataEncoding; /*0x1b4dfd*/
    v12 = -[IOAudio channelCount](self, sel_channelCount); /*0x1b4e0d*/
  }
  for ( i = 0; /*0x1b4e13*/
        i < (unsigned int)objc_msgSend(a3, sel_dmaCount) >> 1
     && (unsigned __int8)objc_msgSend(a3, sel_enqueueDescriptor_dataFormat_channelCount_, &v14, &dataEncoding, &v12);
        ++i )
  {
    ; /*0x1b4e50*/
  }
  if ( objc_msgSend(a3, sel_enqueueCount) ) /*0x1b4e5c*/
  {
    -[IOAudio _setSampleRate:](self, sel__setSampleRate_, v14); /*0x1b4e78*/
    -[IOAudio _setDataEncoding:](self, sel__setDataEncoding_, dataEncoding); /*0x1b4e89*/
    -[IOAudio _setChannelCount:](self, sel__setChannelCount_, v12); /*0x1b4e9a*/
    objc_msgSend(a3, sel_descriptorSize); /*0x1b4eaa*/
    objc_msgSend(a3, sel_channelBuffer); /*0x1b4eb8*/
    objc_msgSend(a3, sel_isRead); /*0x1b4ec9*/
    v5 = objc_msgSend(a3, sel_localChannel); /*0x1b4edd*/
    v10 = -[IOAudio startDMAForChannel:read:buffer:bufferSizeForInterrupts:]( /*0x1b4ef3*/
            self,
            sel_startDMAForChannel_read_buffer_bufferSizeForInterrupts_,
            v5);
    if ( v10 ) /*0x1b4efb*/
    {
      IOGetTimestamp(v11); /*0x1b4f01*/
      -[IOAudio _setOutputStartTime:](self, sel__setOutputStartTime_, v11[0], v11[1]); /*0x1b4f16*/
      if ( (unsigned __int8)objc_msgSend(a3, sel_isRead) ) /*0x1b4f23*/
        -[IOAudio _setInputActive:](self, sel__setInputActive_, 1); /*0x1b4f37*/
      else
        -[IOAudio _setOutputActive:](self, sel__setOutputActive_, 1); /*0x1b4f46*/
      if ( -[IOAudio _timeout](self, sel__timeout) == -1 ) /*0x1b4f61*/
      {
        v8 = objc_msgSend(a3, sel_descriptorSize); /*0x1b4f74*/
        -[IOAudio _setTimeout:](self, sel__setTimeout_, v8); /*0x1b4f75*/
      }
    }
    else
    {
      while ( objc_msgSend(a3, sel_enqueueCount) ) /*0x1b4f8a*/
        objc_msgSend(a3, sel_dequeueDescriptor); /*0x1b4f94*/
      v9 = (char)objc_msgSend(a3, sel_isRead); /*0x1b4fb0*/
      v6 = objc_msgSend(a3, sel_localChannel); /*0x1b4fb9*/
      -[IOAudio stopDMAForChannel:read:](self, sel_stopDMAForChannel_read_, v6); /*0x1b4fca*/
      objc_msgSend(a3, sel_freeDescriptors); /*0x1b4fd7*/
      -[IOAudio _setTimeout:](self, sel__setTimeout_, v9); /*0x1b4fe9*/
    }
  }
  return v10; /*0x1b4ff5*/
}
