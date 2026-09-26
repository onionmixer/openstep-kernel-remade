/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1baa6c. */
id __cdecl -[OutputStream free](OutputStream *self, SEL a2)
{
  unsigned int *peaksRight; // eax
  unsigned int *peaksLeft; // eax
  queue_entry *p_xferQueue; // ebx
  int v5; // ecx
  int v6; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v7; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v8; // eax
  char *mixBuffer1; // edx
  char *mixBuffer2; // edx
  queue_entry *next; // [esp+Ch] [ebp-Ch]
  objc_super v13; // [esp+10h] [ebp-8h] BYREF

  peaksRight = self->peaksRight; /*0x1baa78*/
  if ( peaksRight ) /*0x1baa80*/
    IOFree((int)peaksRight, 64); /*0x1baa85*/
  peaksLeft = self->peaksLeft; /*0x1baa8d*/
  if ( peaksLeft ) /*0x1baa95*/
    IOFree((int)peaksLeft, 64); /*0x1baa9a*/
  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->xferQueue.next != &self->xferQueue ) /*0x1baaae*/
  {
    p_xferQueue = (queue_entry *)&self->xferQueue; /*0x1baab0*/
    do /*0x1baaf5*/
    {
      next = self->xferQueue.next; /*0x1baaba*/
      v5 = *((_DWORD *)next + 5); /*0x1baabd*/
      v6 = *((_DWORD *)next + 6); /*0x1baac0*/
      if ( p_xferQueue == (queue_entry *)v5 ) /*0x1baac5*/
        v7 = &self->xferQueue; /*0x1baac7*/
      else
        v7 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v5 + 20); /*0x1baacc*/
      v7->prev = (queue_entry *)v6; /*0x1baacf*/
      if ( p_xferQueue == (queue_entry *)v6 ) /*0x1baad4*/
        v8 = &self->xferQueue; /*0x1baad6*/
      else
        v8 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v6 + 20); /*0x1baadc*/
      v8->next = (queue_entry *)v5; /*0x1baadf*/
      IOFree((int)next, 28); /*0x1baae7*/
    }
    while ( self->xferQueue.next != p_xferQueue ); /*0x1baaf5*/
  }
  mixBuffer1 = self->super.mixBuffer1; /*0x1baaf7*/
  if ( mixBuffer1 ) /*0x1baafc*/
    IOFree((int)mixBuffer1, 8 * page_size); /*0x1bab0d*/
  mixBuffer2 = self->super.mixBuffer2; /*0x1bab15*/
  if ( mixBuffer2 ) /*0x1bab1a*/
    IOFree((int)mixBuffer2, 4 * page_size); /*0x1bab2b*/
  v13.receiver = self; /*0x1bab3a*/
  v13.super_class = (Class)stru_1FA514.super_class; /*0x1bab43*/
  return -[AudioStream free](&v13, sel_free); /*0x1bab52*/
}
