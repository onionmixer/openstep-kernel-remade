/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2758. */
id __cdecl -[EventDriver undoAutoDim](EventDriver *self, SEL a2)
{
  self->autoDimmed = 0; /*0x1b275f*/
  -[EventDriver setBrightness](self, sel_setBrightness); /*0x1b276e*/
  return self; /*0x1b2775*/
}
