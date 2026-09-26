/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9774. */
unsigned int __cdecl -[IONetwork inputPackets](IONetwork *self, SEL a2)
{
  return if_ipackets((int)self->_netif); /*0x1a9785*/
}
