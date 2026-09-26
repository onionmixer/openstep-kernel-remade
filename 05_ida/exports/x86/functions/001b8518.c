/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8518. */
void __cdecl -[AudioChannel getPeakLeft:right:](AudioChannel *self, SEL a2, unsigned int *a3, unsigned int *a4)
{
  if ( self->peakEnabled ) /*0x1b8527*/
  {
    *a3 = audio_max_peak(self->peaksLeft, self->peakHistory); /*0x1b853a*/
    *a4 = audio_max_peak(self->peaksRight, self->peakHistory); /*0x1b8549*/
  }
  else
  {
    *a4 = 0; /*0x1b8550*/
    *a3 = 0; /*0x1b8556*/
  }
}
