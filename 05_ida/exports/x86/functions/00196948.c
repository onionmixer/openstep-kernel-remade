/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196948. */
int __cdecl -[kmDevice disableCons](kmDevice *self, SEL a2)
{
  if ( self->fbMode == 1 ) /*0x196955*/
    self->fbMode = 4; /*0x196957*/
  return 0; /*0x196965*/
}
