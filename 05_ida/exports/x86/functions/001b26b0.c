/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b26b0. */
id __cdecl -[EventDriver setAutoDimBrightness:](EventDriver *self, SEL a2, int a3)
{
  id result; // eax
  int v4; // edx

  result = self; /*0x1b26b3*/
  v4 = a3; /*0x1b26b6*/
  if ( a3 >= 0 ) /*0x1b26bb*/
  {
    if ( a3 > 64 ) /*0x1b26c7*/
      v4 = 64; /*0x1b26c9*/
  }
  else
  {
    v4 = 0; /*0x1b26bd*/
  }
  if ( self->dimmedBrightness != v4 ) /*0x1b26d4*/
  {
    self->dimmedBrightness = v4; /*0x1b26d6*/
    if ( self->autoDimmed == 1 ) /*0x1b26e3*/
      return -[EventDriver setBrightness](self, sel_setBrightness); /*0x1b26ed*/
  }
  return result; /*0x1b26f4*/
}
