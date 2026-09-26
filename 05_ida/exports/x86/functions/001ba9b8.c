/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba9b8. */
id __cdecl -[OutputStream getPeakLeft:right:](OutputStream *self, SEL a2, unsigned int *a3, unsigned int *a4)
{
  if ( self->peakEnabled ) /*0x1ba9c7*/
  {
    *a3 = audio_max_peak(self->peaksLeft, self->peakHistory); /*0x1ba9e3*/
    *a4 = audio_max_peak(self->peaksRight, self->peakHistory); /*0x1ba9f8*/
  }
  else
  {
    *a4 = 0; /*0x1ba9fc*/
    *a3 = 0; /*0x1baa02*/
  }
  return self; /*0x1baa0d*/
}
