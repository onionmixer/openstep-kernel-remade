/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5890. */
void __cdecl -[IODisk setWriteProtected:](IODisk *self, SEL a2, char a3)
{
  self->_writeProtected = a3 != 0; /*0x1a589d*/
}
