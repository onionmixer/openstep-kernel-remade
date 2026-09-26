/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6518. */
char __cdecl -[IOAudio _attemptToStopDMAForChannel:](IOAudio *self, SEL a2, id a3)
{
  id v4; // [esp+8h] [ebp-Ch] BYREF
  unsigned int dataEncoding; // [esp+Ch] [ebp-8h] BYREF
  id v6; // [esp+10h] [ebp-4h] BYREF

  v6 = -[IOAudio sampleRate](self, sel_sampleRate); /*0x1b6533*/
  dataEncoding = self->_dataEncoding; /*0x1b653c*/
  v4 = -[IOAudio channelCount](self, sel_channelCount); /*0x1b654c*/
  if ( objc_msgSend(a3, sel_enqueueCount) ) /*0x1b6557*/
    objc_msgSend(a3, sel_dequeueDescriptor); /*0x1b656b*/
  if ( (unsigned __int8)objc_msgSend(a3, sel_enqueueDescriptor_dataFormat_channelCount_, &v6, &dataEncoding, &v4) /*0x1b659b*/
    || objc_msgSend(a3, sel_enqueueCount) )
  {
    return 0; /*0x1b65e0*/
  }
  -[IOAudio _stopDMAForChannel:](self, sel__stopDMAForChannel_, a3); /*0x1b65b0*/
  -[IOAudio _setOutputStartTime:](self, sel__setOutputStartTime_, 0, 0); /*0x1b65c1*/
  -[IOAudio _setLastInterruptTimeStamp:](self, sel__setLastInterruptTimeStamp_, 0, 0); /*0x1b65d2*/
  return 1; /*0x1b65e5*/
}
