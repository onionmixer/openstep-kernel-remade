/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b84cc. */
void __cdecl -[AudioChannel setDetectPeaks:](AudioChannel *self, SEL a2, char a3)
{
  self->peakEnabled = a3; /*0x1b84d7*/
  if ( a3 ) /*0x1b84dc*/
  {
    if ( !self->peaksLeft ) /*0x1b84de*/
    {
      self->peaksLeft = (unsigned int *)IOMalloc(0x40u); /*0x1b84eb*/
      self->peaksRight = (unsigned int *)IOMalloc(0x40u); /*0x1b84f5*/
      audio_clear_peaks(self->peaksLeft, 16); /*0x1b84fe*/
      audio_clear_peaks(self->peaksRight, 16); /*0x1b8509*/
    }
  }
}
