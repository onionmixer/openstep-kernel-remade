/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b92e0. */
id __cdecl -[AudioStream freeRegions](AudioStream *self, SEL a2)
{
  queue_entry *p_regionQueue; // ebx
  queue_entry *next; // esi
  int v4; // ecx
  int v5; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v6; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v7; // eax

  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->regionQueue.next != &self->regionQueue ) /*0x1b92f2*/
  {
    p_regionQueue = (queue_entry *)&self->regionQueue; /*0x1b92f4*/
    do /*0x1b9338*/
    {
      next = self->regionQueue.next; /*0x1b92fb*/
      v4 = *((_DWORD *)next + 15); /*0x1b92fe*/
      v5 = *((_DWORD *)next + 16); /*0x1b9301*/
      if ( p_regionQueue == (queue_entry *)v4 ) /*0x1b9306*/
        v6 = &self->regionQueue; /*0x1b9308*/
      else
        v6 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v4 + 60); /*0x1b930c*/
      v6->prev = (queue_entry *)v5; /*0x1b930f*/
      if ( p_regionQueue == (queue_entry *)v5 ) /*0x1b9314*/
        v7 = &self->regionQueue; /*0x1b9316*/
      else
        v7 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v5 + 60); /*0x1b931c*/
      v7->next = (queue_entry *)v4; /*0x1b931f*/
      -[AudioStream freeRegion:](self, sel_freeRegion_, next); /*0x1b932d*/
    }
    while ( self->regionQueue.next != p_regionQueue ); /*0x1b9338*/
  }
  return self; /*0x1b9340*/
}
