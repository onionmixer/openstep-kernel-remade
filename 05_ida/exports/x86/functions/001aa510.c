/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa510. */
void __cdecl -[IOEthernet clearTimeout](IOEthernet *self, SEL a2)
{
  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1aa520*/
  {
    ns_untimeout((int)sub_1A9F1C, (int)self); /*0x1aa52f*/
    self->_absTimeout = 0; /*0x1aa534*/
  }
}
