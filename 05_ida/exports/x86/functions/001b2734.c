/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2734. */
id __cdecl -[EventDriver doAutoDim](EventDriver *self, SEL a2)
{
  self->autoDimmed = 1; /*0x1b273b*/
  -[EventDriver setBrightness](self, sel_setBrightness); /*0x1b274a*/
  return self; /*0x1b2751*/
}
