/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa678. */
int __cdecl -[IOEthernet outputPacket:address:](
        IOEthernet *self,
        SEL a2,
        $199DFB5D1DF31DC82E78091AC4DEC886 *a3,
        void *a4)
{
  int v4; // eax
  int v5; // eax

  if ( self->_isRunning ) /*0x1aa687*/
  {
    v4 = nb_map((int)a3); /*0x1aa699*/
    *(_DWORD *)v4 = *(_DWORD *)a4; /*0x1aa6a0*/
    *(_WORD *)(v4 + 4) = *((_WORD *)a4 + 2); /*0x1aa6a6*/
    *($0F52D4C2E1E8F22E8199E6D21C589DA7 *)(v4 + 6) = self->_ethernetAddress; /*0x1aa6b0*/
    v5 = nb_size((int)a3); /*0x1aa6bf*/
    if ( v5 <= 59 ) /*0x1aa6ca*/
      nb_grow_bot((int)a3, 60 - v5); /*0x1aa6d7*/
    -[IOEthernet transmit:](self, sel_transmit_, a3); /*0x1aa6e8*/
  }
  else
  {
    nb_free((int)a3); /*0x1aa691*/
  }
  return 0; /*0x1aa6f2*/
}
