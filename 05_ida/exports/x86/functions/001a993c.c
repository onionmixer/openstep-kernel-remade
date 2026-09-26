/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a993c. */
void __cdecl -[IONetwork incrementCollisionsBy:](IONetwork *self, SEL a2, unsigned int a3)
{
  int v3; // eax

  v3 = if_collisions((int)self->_netif); /*0x1a994b*/
  if_collisions_set((int)self->_netif, v3 + a3); /*0x1a9957*/
}
