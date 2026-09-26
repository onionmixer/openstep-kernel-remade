/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2868. */
id __cdecl -[EventDriver setBrightness](EventDriver *self, SEL a2)
{
  int i; // ebx

  for ( i = 0; self->screens > i; ++i ) /*0x1b2878*/
    -[EventDriver evDispatch:command:](self, sel_evDispatch_command_, i, 4); /*0x1b2887*/
  return self; /*0x1b289d*/
}
