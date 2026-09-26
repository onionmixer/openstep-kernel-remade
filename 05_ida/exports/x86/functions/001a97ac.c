/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a97ac. */
void __cdecl -[IONetwork incrementInputPacketsBy:](IONetwork *self, SEL a2, unsigned int a3)
{
  int v3; // eax

  v3 = if_ipackets((int)self->_netif); /*0x1a97bb*/
  if_ipackets_set((int)self->_netif, v3 + a3); /*0x1a97c7*/
}
