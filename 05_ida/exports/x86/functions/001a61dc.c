/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a61dc. */
int __cdecl -[IOLogicalDisk isDiskReady:](IOLogicalDisk *self, SEL a2, char a3)
{
  return (int)objc_msgSend(self->_physicalDisk, sel_isDiskReady_, a3); /*0x1a61fc*/
}
