/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6d24. */
id __cdecl -[IODiskPartition free](IODiskPartition *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[IODiskPartition unregisterUnixDisk:](self, sel_unregisterUnixDisk_, self->_partition); /*0x1a6d3d*/
  v3.receiver = self; /*0x1a6d49*/
  v3.super_class = (Class)stru_1FA154.super_class; /*0x1a6d52*/
  return -[IOLogicalDisk free](&v3, sel_free); /*0x1a6d5e*/
}
