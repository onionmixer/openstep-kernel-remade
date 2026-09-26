/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa5d0. */
void __cdecl -[IOEthernet performLoopback:](IOEthernet *self, SEL a2, $199DFB5D1DF31DC82E78091AC4DEC886 *a3)
{
  _BYTE *v3; // ebx
  int v4; // esi
  size_t v5; // esi
  $199DFB5D1DF31DC82E78091AC4DEC886 *v6; // ebx
  void *v7; // eax

  v3 = (_BYTE *)nb_map((int)a3); /*0x1aa5df*/
  v4 = nb_size((int)a3); /*0x1aa5e7*/
  if ( (*v3 & 1) != 0 && !-[IOEthernet isUnwantedMulticastPacket:](self, sel_isUnwantedMulticastPacket_, v3) ) /*0x1aa5fd*/
  {
    v5 = v4 + 14; /*0x1aa609*/
    v6 = -[IOEthernet allocateNetbuf](self, sel_allocateNetbuf); /*0x1aa61c*/
    if ( v6 ) /*0x1aa623*/
    {
      v7 = (void *)nb_map((int)a3); /*0x1aa626*/
      nb_write((int)v6, 0, v5, v7); /*0x1aa630*/
      -[IONetwork handleInputPacket:extra:](self->_netif, sel_handleInputPacket_extra_, v6, 0); /*0x1aa649*/
    }
  }
}
