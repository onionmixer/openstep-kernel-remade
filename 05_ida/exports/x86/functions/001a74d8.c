/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a74d8. */
int __cdecl -[IODiskPartition checkSafeConfig:](IODiskPartition *self, SEL a2, const char *a3)
{
  if ( self->_partition )
  {
    -[IODevice name](self, sel_name); /*0x1a74f5*/
    IOLog("%s: %s on partition != 0\n");
    return -725; /*0x1a7508*/
  }
  else if ( -[IODiskPartition isAnyBlockDevOpen](self, sel_isAnyBlockDevOpen) )
  {
    -[IODevice name](self, sel_name); /*0x1a752d*/
    IOLog("%s: %s with open block devices\n");
    return -725; /*0x1a7540*/
  }
  else if ( -[IOLogicalDisk isAnyOtherOpen](self, sel_isAnyOtherOpen) )
  {
    -[IODevice name](self, sel_name); /*0x1a7565*/
    IOLog("%s: %s with other partitions open\n");
    return -725; /*0x1a7578*/
  }
  else
  {
    return 0; /*0x1a7580*/
  }
}
