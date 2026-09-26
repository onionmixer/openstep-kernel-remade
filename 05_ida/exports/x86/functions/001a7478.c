/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7478. */
char __cdecl -[IODiskPartition isAnyBlockDevOpen](IODiskPartition *self, SEL a2)
{
  id i; // eax
  void *v4; // ebx
  id v5; // [esp-8h] [ebp-Ch]

  v5 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a7496*/
  for ( i = objc_msgSend(v5, sel_nextLogicalDisk); ; i = objc_msgSend(v4, sel_nextLogicalDisk) ) /*0x1a7497*/
  {
    v4 = i; /*0x1a74c5*/
    if ( !i ) /*0x1a74cc*/
      break; /*0x1a74cc*/
    if ( (unsigned __int8)objc_msgSend(i, sel_isBlockDeviceOpen) ) /*0x1a74a4*/
      return 1; /*0x1a74b5*/
  }
  return 0; /*0x1a74d0*/
}
