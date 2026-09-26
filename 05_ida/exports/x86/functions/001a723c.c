/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a723c. */
void __cdecl -[IODiskPartition _initPartition:disktab:](IODiskPartition *self, SEL a2, int a3, disktab *a4)
{
  id v4; // esi
  const char *v5; // eax
  id v6; // eax
  signed __int8 v7; // al
  int v8; // ebx
  unsigned int v9; // edi
  objc_super v10; // [esp+Ch] [ebp-28h] BYREF
  char v11[32]; // [esp+14h] [ebp-20h] BYREF

  v4 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a7268*/
  v5 = (const char *)objc_msgSend(v4, sel_name); /*0x1a7279*/
  sprintf(v11, "%s%c", v5, a3 + 97); /*0x1a728b*/
  -[IODevice setName:](self, sel_setName_, v11); /*0x1a729c*/
  -[IODisk setDriveName:](self, sel_setDriveName_, "IODiskPartition Partition"); /*0x1a72b4*/
  -[IODevice setLocation:](self, sel_setLocation_, 0); /*0x1a72c6*/
  -[IODisk setDiskSize:](self, sel_setDiskSize_, a4[1].d_partitions[6 * a3 + 2].p_size); /*0x1a72da*/
  -[IODisk setBlockSize:](self, sel_setBlockSize_, *(_DWORD *)&a4->d_partitions[1].p_bsize); /*0x1a72f4*/
  v6 = objc_msgSend(v4, sel_unit); /*0x1a7301*/
  -[IODevice setUnit:](self, sel_setUnit_, v6); /*0x1a7312*/
  v7 = (unsigned __int8)objc_msgSend(v4, sel_isWriteProtected); /*0x1a7322*/
  -[IODisk setWriteProtected:](self, sel_setWriteProtected_, v7); /*0x1a7336*/
  v8 = *(_DWORD *)&a4[1].d_partitions[6 * a3 + 1].p_bsize + SLOWORD(a4->d_partitions[4].p_size); /*0x1a7342*/
  v9 = -[IOLogicalDisk physicalBlockSize](self, sel_physicalBlockSize); /*0x1a7354*/
  -[IOLogicalDisk setPartitionBase:](self, sel_setPartitionBase_, *(_DWORD *)&a4->d_partitions[1].p_bsize / v9 * v8); /*0x1a736f*/
  self->_partition = a3; /*0x1a737a*/
  v10.receiver = self; /*0x1a738c*/
  v10.super_class = objc_getOrigClass("IOLogicalDisk"); /*0x1a739c*/
  -[IODisk setFormattedInternal:](&v10, sel_setFormattedInternal_, 1); /*0x1a73a3*/
  self->_labelValid = 1; /*0x1a73ab*/
  -[IODiskPartition registerUnixDisk:](self, sel_registerUnixDisk_, a3); /*0x1a73c1*/
}
