/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5ff0. */
int __cdecl -[IOLogicalDisk updateReadyState](IOLogicalDisk *self, SEL a2)
{
  return (int)objc_msgSend(self->_physicalDisk, sel_updateReadyState); /*0x1a600b*/
}
