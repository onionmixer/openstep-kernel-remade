/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba850. */
id __cdecl -[OutputStream completeRegion:descriptor:size:used:](
        OutputStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a4,
        unsigned int a5,
        unsigned int *a6)
{
  queue_entry *next; // edx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  if ( &self->xferQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->xferQueue.next ) /*0x1ba86d*/
  {
LABEL_6:
    v7 = 0; /*0x1ba89f*/
  }
  else
  {
    next = self->xferQueue.next; /*0x1ba86f*/
    while ( *($2D87D4CA0FCCD4E0D80DDC4A8D8F85EA **)next != a4 ) /*0x1ba876*/
    {
      next = *((queue_entry **)next + 5); /*0x1ba898*/
      if ( &self->xferQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1ba89d*/
        goto LABEL_6; /*0x1ba89d*/
    }
    v7 = *((_DWORD *)next + 1); /*0x1ba878*/
    *((_DWORD *)next + 1) = 0; /*0x1ba87b*/
    v11 = *((_DWORD *)next + 2); /*0x1ba885*/
    v10 = *((_DWORD *)next + 3); /*0x1ba88b*/
    v9 = *((_DWORD *)next + 4); /*0x1ba891*/
  }
  self->super.bytesProcessed += v7; /*0x1ba8a1*/
  objc_msgSend(self->super.channel, sel_incrementClipCount_, v9); /*0x1ba8b3*/
  if ( self->peakEnabled ) /*0x1ba8bb*/
  {
    audio_add_peak(self->peaksLeft, v11, &self->currentPeak, self->peakHistory); /*0x1ba8dd*/
    audio_add_peak(self->peaksRight, v10, &self->currentPeak, self->peakHistory); /*0x1ba8f5*/
  }
  return self; /*0x1ba8ff*/
}
