/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba484. */
id __cdecl -[OutputStream initChannel:tag:user:owner:type:](
        OutputStream *self,
        SEL a2,
        id a3,
        int a4,
        int *a5,
        int a6,
        unsigned int a7)
{
  unsigned int v8; // edi
  queue_entry *p_xferQueue; // ebx
  int v10; // eax
  int v11; // edx
  queue_entry *prev; // eax
  objc_super v13; // [esp+Ch] [ebp-8h] BYREF

  v13.receiver = self; /*0x1ba4ab*/
  v13.super_class = (Class)stru_1FA514.super_class; /*0x1ba4b4*/
  if ( !-[AudioStream initChannel:tag:user:owner:type:](&v13, sel_initChannel_tag_user_owner_type_, a3, a4, a5, a6, a7) ) /*0x1ba4bb*/
    return nullptr; /*0x1ba4c7*/
  self->rightGain = 0x8000; /*0x1ba4d0*/
  self->leftGain = 0x8000; /*0x1ba4d7*/
  self->peakHistory = 1; /*0x1ba4de*/
  self->xferQueue.prev = (queue_entry *)&self->xferQueue; /*0x1ba4ee*/
  self->xferQueue.next = (queue_entry *)&self->xferQueue; /*0x1ba4f4*/
  v8 = 0; /*0x1ba4fa*/
  p_xferQueue = (queue_entry *)&self->xferQueue; /*0x1ba4fc*/
  while ( v8 < (unsigned int)objc_msgSend(a3, sel_dmaCount) ) /*0x1ba515*/
  {
    v10 = IOMalloc(0x1Cu); /*0x1ba519*/
    v11 = v10; /*0x1ba51e*/
    *(_DWORD *)v10 = 0; /*0x1ba520*/
    *(_DWORD *)(v10 + 4) = 0; /*0x1ba526*/
    *(_DWORD *)(v10 + 12) = 0; /*0x1ba52d*/
    *(_DWORD *)(v10 + 8) = 0; /*0x1ba534*/
    *(_DWORD *)(v10 + 16) = 0; /*0x1ba53b*/
    if ( self->xferQueue.next == p_xferQueue ) /*0x1ba54b*/
    {
      self->xferQueue.next = (queue_entry *)v10; /*0x1ba568*/
      self->xferQueue.prev = (queue_entry *)v10; /*0x1ba56e*/
      *(_DWORD *)(v10 + 20) = p_xferQueue; /*0x1ba574*/
      *(_DWORD *)(v10 + 24) = p_xferQueue; /*0x1ba577*/
    }
    else
    {
      prev = self->xferQueue.prev; /*0x1ba54d*/
      *(_DWORD *)(v11 + 24) = prev; /*0x1ba553*/
      *(_DWORD *)(v11 + 20) = p_xferQueue; /*0x1ba556*/
      self->xferQueue.prev = (queue_entry *)v11; /*0x1ba559*/
      *((_DWORD *)prev + 5) = v11; /*0x1ba55f*/
    }
    ++v8; /*0x1ba562*/
  }
  self->super.mixBuffer1 = (char *)IOMalloc(8 * page_size); /*0x1ba58f*/
  self->super.mixBuffer2 = (char *)IOMalloc(4 * page_size); /*0x1ba5a5*/
  return self; /*0x1ba5ad*/
}
