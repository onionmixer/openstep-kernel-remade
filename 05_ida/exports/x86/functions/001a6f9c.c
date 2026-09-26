/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6f9c. */
int __cdecl -[IODiskPartition setFormatted:](IODiskPartition *self, SEL a2, char a3)
{
  int result; // eax
  id v4; // ebx

  result = -[IODiskPartition checkSafeConfig:](self, sel_checkSafeConfig_, "setFormatted"); /*0x1a6fbb*/
  if ( !result ) /*0x1a6fc5*/
  {
    v4 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a6fd4*/
    objc_msgSend(v4, sel_setFormattedInternal_, a3); /*0x1a6fe3*/
    if ( a3 ) /*0x1a6fef*/
      objc_msgSend(v4, sel_updatePhysicalParameters); /*0x1a6ff9*/
    objc_msgSend(v4, sel_setFormattedInternal_, a3); /*0x1a700a*/
    -[IODiskPartition setFormattedInternal:](self, sel_setFormattedInternal_, a3); /*0x1a7018*/
    return 0; /*0x1a701d*/
  }
  return result; /*0x1a7022*/
}
