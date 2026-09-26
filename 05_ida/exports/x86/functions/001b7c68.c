/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7c68. */
void __cdecl -[AudioChannel initializeFreeQueue](AudioChannel *self, SEL a2)
{
  queue_entry *p_freeQueue; // esi
  queue_entry *next; // ecx
  int v4; // ebx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v5; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v6; // eax
  unsigned int v7; // esi
  queue_entry *v8; // ebx
  int v9; // eax
  int v10; // ecx
  queue_entry *prev; // eax
  int v12; // [esp+Ch] [ebp-8h]
  unsigned int channelBufferPtr; // [esp+Ch] [ebp-8h]

  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->freeQueue.next != &self->freeQueue ) /*0x1b7c7a*/
  {
    p_freeQueue = (queue_entry *)&self->freeQueue; /*0x1b7c7c*/
    do /*0x1b7cbe*/
    {
      next = self->freeQueue.next; /*0x1b7c80*/
      v4 = *((_DWORD *)next + 2); /*0x1b7c83*/
      v12 = *((_DWORD *)next + 3); /*0x1b7c89*/
      if ( p_freeQueue == (queue_entry *)v4 ) /*0x1b7c8e*/
        v5 = &self->freeQueue; /*0x1b7c90*/
      else
        v5 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v4 + 8); /*0x1b7c94*/
      v5->prev = (queue_entry *)v12; /*0x1b7c9a*/
      if ( p_freeQueue == (queue_entry *)v12 ) /*0x1b7c9f*/
        v6 = &self->freeQueue; /*0x1b7ca1*/
      else
        v6 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v12 + 8); /*0x1b7cab*/
      v6->next = (queue_entry *)v4; /*0x1b7cae*/
      IOFree((int)next, 16); /*0x1b7cb3*/
    }
    while ( self->freeQueue.next != p_freeQueue ); /*0x1b7cbe*/
  }
  bzero((void *)self->channelBufferPtr, self->dmaSize); /*0x1b7cc8*/
  channelBufferPtr = self->channelBufferPtr; /*0x1b7cd0*/
  v7 = 0; /*0x1b7cd3*/
  if ( self->dmaCount ) /*0x1b7cd8*/
  {
    v8 = (queue_entry *)&self->freeQueue; /*0x1b7cdd*/
    do /*0x1b7d27*/
    {
      v9 = IOMalloc(0x10u); /*0x1b7ce2*/
      v10 = v9; /*0x1b7ce7*/
      *(_DWORD *)v9 = 0; /*0x1b7ce9*/
      *(_DWORD *)(v9 + 4) = channelBufferPtr; /*0x1b7cf2*/
      channelBufferPtr += self->descriptorSize; /*0x1b7cf8*/
      if ( self->freeQueue.next == v8 ) /*0x1b7d01*/
      {
        self->freeQueue.next = (queue_entry *)v9; /*0x1b7d03*/
        self->freeQueue.prev = (queue_entry *)v9; /*0x1b7d06*/
        *(_DWORD *)(v9 + 8) = v8; /*0x1b7d09*/
        *(_DWORD *)(v9 + 12) = v8; /*0x1b7d0c*/
      }
      else
      {
        prev = self->freeQueue.prev; /*0x1b7d14*/
        *(_DWORD *)(v10 + 12) = prev; /*0x1b7d17*/
        *(_DWORD *)(v10 + 8) = v8; /*0x1b7d1a*/
        self->freeQueue.prev = (queue_entry *)v10; /*0x1b7d1d*/
        *((_DWORD *)prev + 2) = v10; /*0x1b7d20*/
      }
      ++v7; /*0x1b7d23*/
    }
    while ( self->dmaCount > v7 ); /*0x1b7d27*/
  }
}
