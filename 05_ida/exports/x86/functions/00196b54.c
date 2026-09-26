/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196b54. */
int __cdecl -[kmDevice getStatus:](kmDevice *self, SEL a2, unsigned int *a3)
{
  *a3 = self->fbMode == 1; /*0x196b69*/
  return 0; /*0x196b6f*/
}
