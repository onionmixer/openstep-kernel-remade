/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a983c. */
unsigned int __cdecl -[IONetwork outputPackets](IONetwork *self, SEL a2)
{
  return if_opackets((int)self->_netif); /*0x1a984d*/
}
