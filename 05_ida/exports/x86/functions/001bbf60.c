/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbf60. */
void __cdecl audio_port_gone(int a1)
{
  int v1; // ebx
  id v2; // eax
  id v3; // eax
  id v4; // eax

  if ( a1 ) /*0x1bbf6a*/
  {
    do /*0x1bbfe7*/
    {
      v1 = 0; /*0x1bbf6c*/
      v2 = +[IOAudio _channelForExclusivePort:](aIoaudio, sel__channelForExclusivePort_, a1); /*0x1bbf7d*/
      if ( v2 ) /*0x1bbf87*/
      {
        objc_msgSend(v2, sel_setExclusiveUser_, 0); /*0x1bbf93*/
        v1 = 1; /*0x1bbf98*/
      }
      else
      {
        v3 = +[AudioChannel streamForOwnerPort:](aAudiochannel, sel_streamForOwnerPort_, a1); /*0x1bbfb3*/
        if ( v3 ) /*0x1bbfbd*/
        {
          v4 = objc_msgSend(v3, sel_channel); /*0x1bbfcf*/
          objc_msgSend(v4, sel_removeStream_); /*0x1bbfd8*/
          v1 = 1; /*0x1bbfe0*/
        }
      }
    }
    while ( v1 ); /*0x1bbfe7*/
  }
}
