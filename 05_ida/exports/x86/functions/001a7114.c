/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7114. */
void __cdecl -[IODiskPartition _probeLabel:](IODiskPartition *self, SEL a2, $8CBD0DAB9EB64966FFA875B94553E7ED *a3)
{
  IODiskPartition *v3; // edi
  const char *v4; // eax
  int v5; // esi
  IODiskPartition *v6; // ebx
  id v7; // eax
  int v8; // [esp+Ch] [ebp-8h]
  id v9; // [esp+10h] [ebp-4h]

  v9 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a712d*/
  v3 = self; /*0x1a7130*/
  if ( self->_partition )
  {
    v4 = -[IODevice name](self, sel_name); /*0x1a7147*/
    IOLog((int)"%s:  _probeLabel on partition != 0\n", v4);
  }
  else
  {
    -[IODiskPartition _initPartition:disktab:](self, sel__initPartition_disktab_, 0, (char *)a3 + 44); /*0x1a716d*/
    v5 = 1; /*0x1a7172*/
    v8 = 240; /*0x1a717a*/
    do /*0x1a7229*/
    {
      if ( *(int *)((char *)a3 + v8 + 4) > 0 ) /*0x1a718f*/
      {
        v6 = +[Object new](aIodiskpartitio_1, sel_new); /*0x1a71a8*/
        -[IOLogicalDisk connectToPhysicalDisk:](v6, sel_connectToPhysicalDisk_, v9); /*0x1a71b6*/
        -[IODiskPartition _initPartition:disktab:](v6, sel__initPartition_disktab_, v5, (char *)a3 + 44); /*0x1a71cb*/
        -[IODevice init](v6, sel_init); /*0x1a71db*/
        -[IODisk registerDevice](v6, sel_registerDevice); /*0x1a71e8*/
        -[IODisk setLogicalDisk:](v3, sel_setLogicalDisk_, v6); /*0x1a71f6*/
        v7 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a720e*/
        objc_msgSend(v7, sel_setLogicalDisk_); /*0x1a7217*/
        v3 = v6; /*0x1a721c*/
      }
      v8 += 48; /*0x1a7221*/
      ++v5; /*0x1a7225*/
    }
    while ( v5 <= 6 ); /*0x1a7229*/
  }
}
