/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b75d0. */
void __cdecl -[AudioChannel dequeueDescriptor](AudioChannel *self, SEL a2)
{
  queue_entry *next; // esi
  AudioChannel *v3; // ecx
  AudioChannel *v4; // edx
  id *p_streamClass; // eax
  _DWORD *p_isa; // eax
  id v7; // eax
  id v8; // eax
  id v9; // eax
  id v10; // eax
  int v11; // edx
  id v12; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_freeQueue; // edx
  queue_entry *prev; // eax
  int v15; // [esp-10h] [ebp-30h]
  int v16; // [esp-10h] [ebp-30h]
  int v17; // [esp-10h] [ebp-30h]
  int v18; // [esp-Ch] [ebp-2Ch]
  int v19; // [esp-Ch] [ebp-2Ch]
  int v20; // [esp-Ch] [ebp-2Ch]
  int v21; // [esp+Ch] [ebp-14h]
  id v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h] BYREF
  int v24; // [esp+1Ch] [ebp-4h] BYREF

  v24 = 0; /*0x1b75dc*/
  v23 = 0; /*0x1b75e3*/
  next = self->dmaQueue.next; /*0x1b75ea*/
  v3 = *((AudioChannel **)next + 2); /*0x1b75ed*/
  v4 = *((AudioChannel **)next + 3); /*0x1b75f0*/
  if ( &self->dmaQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v3 ) /*0x1b75f8*/
    p_streamClass = *((id **)next + 2); /*0x1b75fa*/
  else
    p_streamClass = &v3->streamClass; /*0x1b7600*/
  p_streamClass[1] = v4; /*0x1b7603*/
  if ( &self->dmaQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v4 ) /*0x1b760b*/
    p_isa = &v4->super.isa; /*0x1b760d*/
  else
    p_isa = &v4->streamClass; /*0x1b7614*/
  *p_isa = v3; /*0x1b7617*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b7624*/
  v22 = objc_msgSend(self->streamList, sel_count); /*0x1b7639*/
  if ( v22 ) /*0x1b7641*/
  {
    if ( self->peakEnabled ) /*0x1b7647*/
    {
      v7 = objc_msgSend(self->audioDevice, sel_dataEncoding); /*0x1b765c*/
      if ( v7 == (id)601 ) /*0x1b7669*/
      {
        v19 = *(_DWORD *)next; /*0x1b76be*/
        v16 = *((_DWORD *)next + 1); /*0x1b76c2*/
        v9 = objc_msgSend(self->audioDevice, sel_channelCount); /*0x1b76ce*/
        audio_linear8_peak(v9, v16, v19, &v24, &v23); /*0x1b76d7*/
      }
      else if ( (unsigned int)v7 > 0x259 ) /*0x1b766b*/
      {
        if ( v7 == (id)602 ) /*0x1b7681*/
        {
          v20 = *(_DWORD *)next; /*0x1b76fe*/
          v17 = *((_DWORD *)next + 1); /*0x1b7702*/
          v10 = objc_msgSend(self->audioDevice, sel_channelCount); /*0x1b770e*/
          audio_mulaw8_peak(v10, v17, v20, &v24, &v23); /*0x1b7717*/
        }
      }
      else if ( v7 == (id)600 ) /*0x1b7672*/
      {
        v18 = *(_DWORD *)next >> 1; /*0x1b7694*/
        v15 = *((_DWORD *)next + 1); /*0x1b7698*/
        v8 = objc_msgSend(self->audioDevice, sel_channelCount); /*0x1b76a4*/
        audio_linear16_peak(v8, v15, v18, &v24, &v23); /*0x1b76ad*/
      }
      audio_add_peak(self->peaksLeft, v24, &self->currentPeak, self->peakHistory); /*0x1b7732*/
      audio_add_peak(self->peaksRight, v23, &self->currentPeak, self->peakHistory); /*0x1b7747*/
    }
    v11 = 0; /*0x1b774f*/
    do /*0x1b7787*/
    {
      v21 = v11; /*0x1b7764*/
      v12 = objc_msgSend(self->streamList, sel_objectAt_, v11); /*0x1b7767*/
      objc_msgSend(v12, sel_dmaCompleteDescriptor_transfered_, next, *(_DWORD *)next); /*0x1b7778*/
      v11 = v21 + 1; /*0x1b7783*/
    }
    while ( (unsigned int)v22 > v21 + 1 ); /*0x1b7787*/
  }
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b7794*/
  bzero(*((void **)next + 1), self->descriptorSize); /*0x1b77a1*/
  p_freeQueue = &self->freeQueue; /*0x1b77a6*/
  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->freeQueue.next == &self->freeQueue ) /*0x1b77ac*/
  {
    self->freeQueue.next = next; /*0x1b76e0*/
    self->freeQueue.prev = next; /*0x1b76e3*/
    *((_DWORD *)next + 2) = p_freeQueue; /*0x1b76e6*/
    *((_DWORD *)next + 3) = p_freeQueue; /*0x1b76e9*/
  }
  else
  {
    prev = self->freeQueue.prev; /*0x1b77b2*/
    *((_DWORD *)next + 3) = prev; /*0x1b77b5*/
    *((_DWORD *)next + 2) = p_freeQueue; /*0x1b77b8*/
    self->freeQueue.prev = next; /*0x1b77bb*/
    *((_DWORD *)prev + 2) = next; /*0x1b77be*/
  }
  --self->enqueueCount; /*0x1b77c1*/
}
