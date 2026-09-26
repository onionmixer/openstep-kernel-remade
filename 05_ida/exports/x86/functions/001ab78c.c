/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab78c. */
void __cdecl -[IOTokenRing clearTimeout](IOTokenRing *self, SEL a2)
{
  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1ab79c*/
  {
    ns_untimeout((int)sub_1AAEA0, (int)self); /*0x1ab7ab*/
    self->_absTimeout = 0; /*0x1ab7b0*/
  }
}
