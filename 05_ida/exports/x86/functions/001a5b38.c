/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5b38. */
void __cdecl -[IODisk setLogicalDisk:](IODisk *self, SEL a2, id a3)
{
  if ( !self->_nextLogicalDisk || !a3 ) /*0x1a5b4c*/
    self->_nextLogicalDisk = a3; /*0x1a5b4e*/
}
