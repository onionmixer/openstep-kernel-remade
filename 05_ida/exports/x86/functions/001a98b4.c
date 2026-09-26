/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a98b4. */
void __cdecl -[IONetwork incrementOutputErrors](IONetwork *self, SEL a2)
{
  int v2; // eax

  v2 = if_oerrors((int)self->_netif); /*0x1a98bf*/
  if_oerrors_set((int)self->_netif, v2 + 1); /*0x1a98ca*/
}
