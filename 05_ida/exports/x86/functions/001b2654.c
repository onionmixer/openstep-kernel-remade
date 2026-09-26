/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2654. */
id __cdecl -[EventDriver setBrightness:](EventDriver *self, SEL a2, int a3)
{
  id result; // eax
  int v4; // edx

  result = self; /*0x1b2657*/
  v4 = a3; /*0x1b265a*/
  if ( a3 >= 0 ) /*0x1b265f*/
  {
    if ( a3 > 64 ) /*0x1b266b*/
      v4 = 64; /*0x1b266d*/
  }
  else
  {
    v4 = 0; /*0x1b2661*/
  }
  if ( self->curBright != v4 ) /*0x1b2678*/
  {
    self->curBright = v4; /*0x1b267a*/
    if ( !self->autoDimmed ) /*0x1b2680*/
      return -[EventDriver setBrightness](self, sel_setBrightness); /*0x1b2691*/
  }
  return result; /*0x1b2698*/
}
