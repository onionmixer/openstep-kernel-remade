/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6288. */
int __cdecl -[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:](
        IOLogicalDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int *a6)
{
  id v6; // eax
  int v7; // ebx
  unsigned int v9; // ebx
  id v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // [esp+10h] [ebp-8h]

  -[IODevice name](self, sel_name); /*0x1a629f*/
  v6 = objc_msgSend(self->_physicalDisk, sel_isDiskReady_, 1); /*0x1a62b7*/
  v7 = (int)v6; /*0x1a62bc*/
  if ( v6 == (id)-1102 ) /*0x1a62c7*/
    return -1102; /*0x1a62d5*/
  if ( v6 )
  {
    -[IODisk stringFromReturn:](self, sel_stringFromReturn_, v6); /*0x1a62e5*/
    IOLog("%s deviceRwCommon: bogus return from isDiskReady (%s)\n");
    return v7; /*0x1a62fb*/
  }
  v9 = -[IODisk blockSize](self, sel_blockSize); /*0x1a630d*/
  v10 = -[IODisk diskSize](self, sel_diskSize); /*0x1a6317*/
  if ( a4 % v9 )
  {
    IOLog("%s: Bytes requested not multiple of block size\n");
    return -706; /*0x1a6340*/
  }
  v12 = a4 / v9; /*0x1a6344*/
  if ( (unsigned int)v10 < a3 + a4 / v9 ) /*0x1a634c*/
  {
    if ( (unsigned int)v10 <= a3 ) /*0x1a6351*/
      return -706; /*0x1a6358*/
    v12 = (unsigned int)v10 - a3; /*0x1a6361*/
  }
  v11 = v9 / self->_physicalBlockSize; /*0x1a6368*/
  *a5 = self->_partitionBase + a3 * v11; /*0x1a6380*/
  *a6 = self->_physicalBlockSize * v11 * v12; /*0x1a638c*/
  return 0; /*0x1a6393*/
}
