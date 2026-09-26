/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a973c. */
int __cdecl -[IONetwork handleInputPacket:extra:](
        IONetwork *self,
        SEL a2,
        $199DFB5D1DF31DC82E78091AC4DEC886 *a3,
        void *a4)
{
  int v4; // eax

  v4 = if_ipackets((int)self->_netif); /*0x1a974f*/
  if_ipackets_set((int)self->_netif, v4 + 1); /*0x1a975a*/
  return if_handle_input((int)self->_netif, (int)a3, (int)a4); /*0x1a976d*/
}
