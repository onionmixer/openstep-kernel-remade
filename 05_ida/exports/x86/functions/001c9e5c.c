/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9e5c. */
id __cdecl -[Object copy](Object *self, SEL a2)
{
  $3D27A55567FB06BC0E416B979767FD15 *v2; // eax

  v2 = -[Object zone](self, sel_zone); /*0x1c9e6b*/
  return -[Object copyFromZone:](self, sel_copyFromZone_, v2); /*0x1c9e7e*/
}
