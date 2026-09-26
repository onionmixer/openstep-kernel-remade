/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a73d0. */
int __cdecl -[IODiskPartition _freePartitions](IODiskPartition *self, SEL a2)
{
  id v2; // eax
  void *v3; // ebx

  v2 = -[IODisk nextLogicalDisk](self, sel_nextLogicalDisk); /*0x1a73e0*/
  v3 = v2; /*0x1a73e5*/
  if ( self->_partition )
  {
    -[IODevice name](self, sel_name); /*0x1a73fb*/
    IOLog("%s: _freePartitions on partition != 0\n");
    return -725; /*0x1a740b*/
  }
  else if ( v2 )
  {
    if ( (unsigned __int8)objc_msgSend(v2, sel_isOpen) )
    {
      -[IODevice name](self, sel_name); /*0x1a7438*/
      IOLog("%s: _freePartitions with open partitions\n");
      return -725; /*0x1a7448*/
    }
    else
    {
      objc_msgSend(v3, sel_free); /*0x1a7458*/
      -[IODisk setLogicalDisk:](self, sel_setLogicalDisk_, 0); /*0x1a7467*/
      return 0; /*0x1a746c*/
    }
  }
  else
  {
    return 0; /*0x1a7418*/
  }
}
