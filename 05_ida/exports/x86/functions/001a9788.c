/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9788. */
void __cdecl -[IONetwork incrementInputPackets](IONetwork *self, SEL a2)
{
  int v2; // eax

  v2 = if_ipackets((int)self->_netif); /*0x1a9793*/
  if_ipackets_set((int)self->_netif, v2 + 1); /*0x1a979e*/
}
