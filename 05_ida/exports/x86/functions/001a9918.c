/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9918. */
void __cdecl -[IONetwork incrementCollisions](IONetwork *self, SEL a2)
{
  int v2; // eax

  v2 = if_collisions((int)self->_netif); /*0x1a9923*/
  if_collisions_set((int)self->_netif, v2 + 1); /*0x1a992e*/
}
