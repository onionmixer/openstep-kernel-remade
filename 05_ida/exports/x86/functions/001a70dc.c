/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a70dc. */
void __cdecl -[IODiskPartition setRawDeviceOpen:](IODiskPartition *self, SEL a2, char a3)
{
  self->_rawDeviceOpen = a3 != 0; /*0x1a70e9*/
  -[IOLogicalDisk setInstanceOpen:](self, sel_setInstanceOpen_, (*(_DWORD *)&self->_labelValid & 0xFFFF00) != 0); /*0x1a710a*/
}
