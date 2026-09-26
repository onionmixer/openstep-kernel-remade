/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9850. */
void __cdecl -[IONetwork incrementOutputPackets](IONetwork *self, SEL a2)
{
  int v2; // eax

  v2 = if_opackets((int)self->_netif); /*0x1a985b*/
  if_opackets_set((int)self->_netif, v2 + 1); /*0x1a9866*/
}
