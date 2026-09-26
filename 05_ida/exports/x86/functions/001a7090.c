/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7090. */
void __cdecl -[IODiskPartition setBlockDeviceOpen:](IODiskPartition *self, SEL a2, char a3)
{
  self->_blockDeviceOpen = a3 != 0; /*0x1a709d*/
  -[IOLogicalDisk setInstanceOpen:](self, sel_setInstanceOpen_, (*(_DWORD *)&self->_labelValid & 0xFFFF00) != 0); /*0x1a70be*/
}
