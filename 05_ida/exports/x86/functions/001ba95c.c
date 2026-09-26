/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba95c. */
void __cdecl -[OutputStream setDetectPeaks:](OutputStream *self, SEL a2, char a3)
{
  self->peakEnabled = a3; /*0x1ba966*/
  if ( a3 ) /*0x1ba96e*/
  {
    if ( !self->peaksLeft ) /*0x1ba970*/
    {
      self->peaksLeft = (unsigned int *)IOMalloc(0x40u); /*0x1ba980*/
      self->peaksRight = (unsigned int *)IOMalloc(0x40u); /*0x1ba98d*/
      audio_clear_peaks(self->peaksLeft, 16); /*0x1ba99c*/
      audio_clear_peaks(self->peaksRight, 16); /*0x1ba9aa*/
    }
  }
}
