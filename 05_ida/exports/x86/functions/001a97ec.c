/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a97ec. */
void __cdecl -[IONetwork incrementInputErrors](IONetwork *self, SEL a2)
{
  int v2; // eax

  v2 = if_ierrors((int)self->_netif); /*0x1a97f7*/
  if_ierrors_set((int)self->_netif, v2 + 1); /*0x1a9802*/
}
