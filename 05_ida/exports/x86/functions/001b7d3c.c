/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7d3c. */
char __cdecl -[AudioChannel enqueueDescriptor:dataFormat:channelCount:](
        AudioChannel *self,
        SEL a2,
        unsigned int *a3,
        int *a4,
        unsigned int *a5)
{
  queue_entry *v5; // eax
  queue_entry *next; // ebx
  AudioChannel *v8; // edx
  id *p_streamClass; // eax
  _DWORD *p_isa; // eax
  unsigned int i; // esi
  id v12; // eax
  id v13; // eax
  queue_entry *v14; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_dmaQueue; // edx
  queue_entry *prev; // eax
  AudioChannel *v17; // [esp+Ch] [ebp-Ch]
  id v18; // [esp+10h] [ebp-8h]
  id v19; // [esp+14h] [ebp-4h]

  v19 = nullptr; /*0x1b7d48*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b7d5a*/
  v18 = objc_msgSend(self->streamList, sel_count); /*0x1b7d6f*/
  if ( v18 && (v5 = self->freeQueue.next, &self->freeQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)v5) ) /*0x1b7d81*/
  {
    next = self->freeQueue.next; /*0x1b7db0*/
    v17 = *((AudioChannel **)v5 + 2); /*0x1b7db5*/
    v8 = *((AudioChannel **)v5 + 3); /*0x1b7db8*/
    if ( &self->freeQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v17 ) /*0x1b7dbd*/
      p_streamClass = *((id **)v5 + 2); /*0x1b7dbf*/
    else
      p_streamClass = &v17->streamClass; /*0x1b7dc7*/
    p_streamClass[1] = v8; /*0x1b7dca*/
    if ( &self->freeQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v8 ) /*0x1b7dd2*/
      p_isa = &v8->super.isa; /*0x1b7dd4*/
    else
      p_isa = &v8->streamClass; /*0x1b7dd8*/
    *p_isa = v17; /*0x1b7dde*/
    for ( i = 0; i < (unsigned int)v18; ++i ) /*0x1b7de0*/
    {
      v12 = objc_msgSend(self->streamList, sel_objectAt_, i); /*0x1b7df4*/
      v13 = objc_msgSend( /*0x1b7e29*/
              v12,
              sel_mixBuffer_maxCount_rate_format_channelCount_descriptor_virgin_streamCount_,
              *((_DWORD *)next + 1),
              self->descriptorSize,
              a3,
              a4,
              a5,
              next,
              v19 == nullptr,
              v18);
      if ( v19 < v13 ) /*0x1b7e34*/
        v19 = v13; /*0x1b7e36*/
    }
    objc_msgSend(self->streamListLock, sel_unlock); /*0x1b7e4a*/
    if ( v19 ) /*0x1b7e53*/
    {
      *(_DWORD *)next = v19; /*0x1b7e87*/
      p_dmaQueue = &self->dmaQueue; /*0x1b7e89*/
      if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->dmaQueue.next == &self->dmaQueue ) /*0x1b7e8f*/
      {
        self->dmaQueue.next = next; /*0x1b7e74*/
        self->dmaQueue.prev = next; /*0x1b7e77*/
        *((_DWORD *)next + 2) = p_dmaQueue; /*0x1b7e7a*/
        *((_DWORD *)next + 3) = p_dmaQueue; /*0x1b7e7d*/
      }
      else
      {
        prev = self->dmaQueue.prev; /*0x1b7e91*/
        *((_DWORD *)next + 3) = prev; /*0x1b7e94*/
        *((_DWORD *)next + 2) = p_dmaQueue; /*0x1b7e97*/
        self->dmaQueue.prev = next; /*0x1b7e9a*/
        *((_DWORD *)prev + 2) = next; /*0x1b7e9d*/
      }
      ++self->enqueueCount; /*0x1b7ea0*/
      return 1; /*0x1b7ea3*/
    }
    else
    {
      v14 = self->freeQueue.next; /*0x1b7e58*/
      if ( &self->freeQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v14 ) /*0x1b7e5d*/
      {
        self->freeQueue.next = next; /*0x1b7d9c*/
        self->freeQueue.prev = next; /*0x1b7d9f*/
        *((_DWORD *)next + 2) = v14; /*0x1b7da2*/
        *((_DWORD *)next + 3) = v14; /*0x1b7da5*/
      }
      else
      {
        *((_DWORD *)next + 3) = &self->freeQueue; /*0x1b7e63*/
        *((_DWORD *)next + 2) = v14; /*0x1b7e66*/
        self->freeQueue.next = next; /*0x1b7e69*/
        *((_DWORD *)v14 + 3) = next; /*0x1b7e6c*/
      }
      return 0; /*0x1b7e6f*/
    }
  }
  else
  {
    objc_msgSend(self->streamListLock, sel_unlock); /*0x1b7d8e*/
    return 0; /*0x1b7d93*/
  }
}
