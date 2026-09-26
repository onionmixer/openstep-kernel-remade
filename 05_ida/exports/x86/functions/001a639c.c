/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a639c. */
char __cdecl +[IODiskPartition probe:](id a1, SEL a2, id a3)
{
  IODiskPartition *v4; // eax
  IODiskPartition *v5; // edi
  int i; // ebx
  id v7; // eax
  id v8; // esi
  id v9; // eax
  id v10; // [esp+Ch] [ebp-40h]
  char v11; // [esp+10h] [ebp-3Ch]
  char v12; // [esp+14h] [ebp-38h]
  unsigned int v13; // [esp+18h] [ebp-34h]
  id v14; // [esp+1Ch] [ebp-30h]
  const char *v15; // [esp+20h] [ebp-2Ch]
  int v16; // [esp+24h] [ebp-28h]
  id v17; // [esp+28h] [ebp-24h]
  char v18[32]; // [esp+2Ch] [ebp-20h] BYREF

  v17 = objc_msgSend(a3, sel_directDevice); /*0x1a63b5*/
  v16 = 0; /*0x1a63b8*/
  v15 = (const char *)objc_msgSend(v17, sel_name); /*0x1a63cf*/
  v14 = nullptr; /*0x1a63d2*/
  v13 = 0; /*0x1a63d9*/
  v12 = 0; /*0x1a63e0*/
  v11 = 0; /*0x1a63e4*/
  if ( !(unsigned __int8)objc_msgSend(v17, sel_isPhysical) ) /*0x1a63f3*/
    return 0; /*0x1a63ff*/
  v4 = (IODiskPartition *)objc_msgSend(v17, sel_nextLogicalDisk); /*0x1a6413*/
  if ( v4 ) /*0x1a641d*/
  {
    v5 = v4; /*0x1a641f*/
    -[IOLogicalDisk connectToPhysicalDisk:](v4, sel_connectToPhysicalDisk_, v17); /*0x1a642d*/
    v5->_labelValid = 0; /*0x1a6432*/
    v5->_blockDeviceOpen = 0; /*0x1a6439*/
    v5->_rawDeviceOpen = 0; /*0x1a6440*/
  }
  else
  {
    v5 = +[Object new](aIodiskpartitio_1, sel_new); /*0x1a6463*/
    sprintf(v18, "%sa", v15); /*0x1a6472*/
    -[IODevice setName:](v5, sel_setName_, v18); /*0x1a6480*/
    -[IODevice setDeviceKind:](v5, sel_setDeviceKind_, "IODiskPartition"); /*0x1a6495*/
    -[IODisk setDriveName:](v5, sel_setDriveName_, "IODiskPartition Partition"); /*0x1a64a7*/
    -[IODevice setLocation:](v5, sel_setLocation_, 0); /*0x1a64b6*/
    -[IODevice init](v5, sel_init); /*0x1a64c6*/
    -[IODisk registerDevice](v5, sel_registerDevice); /*0x1a64d3*/
    -[IOLogicalDisk connectToPhysicalDisk:](v5, sel_connectToPhysicalDisk_, v17); /*0x1a64e4*/
    objc_msgSend(v17, sel_setLogicalDisk_, v5); /*0x1a64f5*/
    v5->_labelValid = 0; /*0x1a64fa*/
    v5->_blockDeviceOpen = 0; /*0x1a6501*/
    v5->_rawDeviceOpen = 0; /*0x1a6508*/
    objc_msgSend(v17, sel_registerUnixDisk_, 0); /*0x1a651f*/
    -[IODiskPartition registerUnixDisk:](v5, sel_registerUnixDisk_, 0); /*0x1a652e*/
  }
  v10 = objc_msgSend(v17, sel_lastReadyState); /*0x1a6546*/
  for ( i = 0; i <= 14; ++i )
  {
    v7 = objc_msgSend(v17, sel_updateReadyState); /*0x1a655b*/
    v8 = v7; /*0x1a6560*/
    if ( v7 != (id)1 ) /*0x1a6568*/
    {
      if ( !v7 ) /*0x1a656a*/
        break; /*0x1a656a*/
      if ( v7 == (id)2 ) /*0x1a656f*/
      {
        if ( i > 0 ) /*0x1a6573*/
          IOLog("\n"); /*0x1a657e*/
        goto LABEL_28; /*0x1a6586*/
      }
    }
    if ( i )
      IOLog("."); /*0x1a65a9*/
    else
      IOLog("%s: Waiting for drive to come ready");
    IOSleep(1000); /*0x1a65b6*/
  }
  if ( i > 0 ) /*0x1a65c6*/
    IOLog("\n"); /*0x1a65cd*/
  objc_msgSend(v17, sel_setLastReadyState_, v8); /*0x1a65e1*/
  if ( v8 )
  {
    IOLog("%s: Disk Not Ready\n");
  }
  else
  {
    if ( v10 ) /*0x1a65fc*/
      objc_msgSend(v17, sel_updatePhysicalParameters); /*0x1a6609*/
    if ( (unsigned __int8)objc_msgSend(v17, sel_isFormatted) )
    {
      v14 = objc_msgSend(v17, sel_blockSize); /*0x1a6650*/
      -[IOLogicalDisk setPhysicalBlockSize:](v5, sel_setPhysicalBlockSize_, v14); /*0x1a665c*/
      v13 = (unsigned int)objc_msgSend(v17, sel_diskSize); /*0x1a6671*/
      v12 = 1; /*0x1a6674*/
      v16 = IOMalloc(7260); /*0x1a6682*/
      if ( -[IODiskPartition readLabel:](v5, sel_readLabel_, v16) )
      {
        IOLog("%s: No Valid Disk Label\n");
        -[IODisk setBlockSize:](v5, sel_setBlockSize_, v14); /*0x1a66b7*/
        v9 = objc_msgSend(v17, sel_diskSize); /*0x1a66c7*/
        -[IODisk setDiskSize:](v5, sel_setDiskSize_, v9); /*0x1a66d5*/
      }
      else
      {
        v11 = 1; /*0x1a66e0*/
        -[IODiskPartition _probeLabel:](v5, sel__probeLabel_, v16); /*0x1a66f0*/
      }
    }
    else
    {
      IOLog("%s: Disk Unformatted\n");
    }
  }
LABEL_28:
  if ( v12 )
  {
    IOLog("%s: Device Block Size: %u bytes\n");
    if ( (unsigned int)v14 * (v13 >> 10) <= 0x2800 )
      IOLog("%s: Device Capacity:   %u KB\n");
    else
      IOLog("%s: Device Capacity:   %u MB\n");
  }
  if ( v11 )
    IOLog("%s: Disk Label:        %s\n");
  if ( v16 ) /*0x1a6772*/
    IOFree(v16, 7260); /*0x1a677d*/
  return 1; /*0x1a678a*/
}
