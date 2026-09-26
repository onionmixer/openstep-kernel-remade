/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab0fc. */
void __cdecl -[IOTokenRing _set8025FrameSizes](IOTokenRing *self, SEL a2)
{
  if ( self->_ringSpeed == 4 ) /*0x1ab109*/
    self->_maxInfoFieldSize = 4472; /*0x1ab10b*/
  if ( self->_ringSpeed == 16 ) /*0x1ab11c*/
    self->_maxInfoFieldSize = 17800; /*0x1ab11e*/
}
