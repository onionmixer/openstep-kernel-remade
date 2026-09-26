/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b27f4. */
id __cdecl -[EventDriver setAudioVolume:](EventDriver *self, SEL a2, int a3)
{
  id result; // eax
  int v4; // edx

  result = self; /*0x1b27f7*/
  v4 = a3; /*0x1b27fa*/
  if ( a3 >= 0 ) /*0x1b27ff*/
  {
    if ( a3 > 64 ) /*0x1b280b*/
      v4 = 64; /*0x1b280d*/
  }
  else
  {
    v4 = 0; /*0x1b2801*/
  }
  self->curVolume = v4; /*0x1b2812*/
  return result; /*0x1b281a*/
}
