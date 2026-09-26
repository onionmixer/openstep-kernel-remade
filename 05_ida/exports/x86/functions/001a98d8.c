/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a98d8. */
void __cdecl -[IONetwork incrementOutputErrorsBy:](IONetwork *self, SEL a2, unsigned int a3)
{
  int v3; // eax

  v3 = if_oerrors((int)self->_netif); /*0x1a98e7*/
  if_oerrors_set((int)self->_netif, v3 + a3); /*0x1a98f3*/
}
