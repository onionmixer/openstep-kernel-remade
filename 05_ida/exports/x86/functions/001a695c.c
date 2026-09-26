/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a695c. */
int __cdecl -[IODiskPartition writeLabel:](IODiskPartition *self, SEL a2, $8CBD0DAB9EB64966FFA875B94553E7ED *a3)
{
  unsigned int v3; // esi
  int result; // eax
  int v5; // ecx
  char *v6; // ebx
  const char *v7; // eax
  int v8; // edi
  const char *v9; // eax
  const char *v10; // eax
  id v11; // eax
  int v12; // esi
  unsigned int v13; // ebx
  int v14; // eax
  const char *v15; // [esp-4h] [ebp-4Ch]
  int v16; // [esp+1Ch] [ebp-2Ch]
  int v17; // [esp+20h] [ebp-28h]
  int v18; // [esp+24h] [ebp-24h]
  id v19; // [esp+28h] [ebp-20h]
  int v20; // [esp+2Ch] [ebp-1Ch]
  unsigned int v21; // [esp+30h] [ebp-18h]
  int v22; // [esp+34h] [ebp-14h]
  unsigned int v23; // [esp+38h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-Ch] BYREF
  int v25; // [esp+40h] [ebp-8h] BYREF

  v22 = 0; /*0x1a6965*/
  v19 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a697b*/
  v3 = -[IOLogicalDisk physicalBlockSize](self, sel_physicalBlockSize); /*0x1a698d*/
  v18 = 0; /*0x1a698f*/
  v17 = 0; /*0x1a6996*/
  result = -[IODiskPartition checkSafeConfig:](self, sel_checkSafeConfig_, "writeLabel"); /*0x1a69ac*/
  if ( result ) /*0x1a69b8*/
    return result; /*0x1a69b8*/
  objc_msgSend(v19, sel_lockLogicalDisks); /*0x1a69c8*/
  if ( !(unsigned __int8)objc_msgSend(v19, sel_isFormatted) ) /*0x1a69e3*/
    goto LABEL_21; /*0x1a69e3*/
  -[IODiskPartition _freePartitions](self, sel__freePartitions); /*0x1a69f3*/
  self->_labelValid = 0; /*0x1a69fb*/
  v5 = *(_DWORD *)a3; /*0x1a6a05*/
  if ( *(_DWORD *)a3 == 1315264596 || v5 == 1684821554 )
  {
    v23 = 7240; /*0x1a6a1a*/
    v6 = (char *)a3 + 7256; /*0x1a6a24*/
    v16 = 7238; /*0x1a6a2a*/
  }
  else
  {
    if ( v5 != 1684821555 )
    {
      v7 = -[IODevice name](self, sel_name); /*0x1a6a46*/
      IOLog((int)"%s writeLabel: BAD LABEL\n", v7);
      v8 = -706; /*0x1a6a58*/
      goto LABEL_23; /*0x1a6a60*/
    }
    v23 = 560; /*0x1a6a68*/
    v6 = (char *)a3 + 576; /*0x1a6a72*/
    v16 = 558; /*0x1a6a78*/
  }
  IOGetTimestamp(&v25); /*0x1a6a83*/
  *((_DWORD *)a3 + 10) = v25; /*0x1a6a8e*/
  *((_DWORD *)a3 + 1) = 0; /*0x1a6a91*/
  *(_WORD *)v6 = 0; /*0x1a6a98*/
  v21 = (v3 + 7239) / v3; /*0x1a6aa9*/
  v20 = v21 * v3; /*0x1a6aaf*/
  v17 = (page_mask + v21 * v3) & ~page_mask; /*0x1a6ac4*/
  v18 = IOMalloc(v17); /*0x1a6acd*/
  put_disk_label(a3, v18); /*0x1a6ad5*/
  *(_WORD *)(v16 + v18) = __ROR2__(checksum16(v18, v23 >> 1), 8); /*0x1a6afc*/
  v9 = (const char *)check_label(v18, 0); /*0x1a6b05*/
  if ( v9 )
  {
    v15 = v9; /*0x1a6b13*/
    v10 = -[IODevice name](self, sel_name); /*0x1a6b1f*/
    IOLog((int)"%s writeLabel: BAD LABEL : %s\n", v10, v15);
    v8 = -706; /*0x1a6b34*/
    goto LABEL_23; /*0x1a6b39*/
  }
  v11 = -[IODiskPartition NeXTpartitionOffset](self, sel_NeXTpartitionOffset); /*0x1a6b4b*/
  if ( (int)v11 < 0 ) /*0x1a6b57*/
  {
    v8 = (int)v11; /*0x1a6b59*/
    goto LABEL_23; /*0x1a6b5b*/
  }
  v12 = 1; /*0x1a6b60*/
  v13 = (unsigned int)v11 + v21; /*0x1a6b70*/
  do /*0x1a6bc5*/
  {
    *(_DWORD *)(v18 + 4) = _byteswap_ulong(v13); /*0x1a6b7b*/
    v14 = IOVmTaskSelf(); /*0x1a6b7e*/
    v8 = (int)objc_msgSend(v19, sel_writeAt_length_buffer_actualLength_client_, v13, v20, v18, &v24, v14); /*0x1a6ba2*/
    if ( !v8 && v24 == v20 ) /*0x1a6bb1*/
      ++v22; /*0x1a6bb3*/
    if ( v8 == -1102 ) /*0x1a6bbc*/
      break; /*0x1a6bbc*/
    v13 += v21; /*0x1a6bbe*/
    ++v12; /*0x1a6bc1*/
  }
  while ( v12 <= 3 ); /*0x1a6bc5*/
  if ( v22 ) /*0x1a6bcb*/
  {
    self->_labelValid = 1; /*0x1a6bdf*/
    v8 = 0; /*0x1a6be6*/
    -[IODiskPartition _probeLabel:](self, sel__probeLabel_, a3); /*0x1a6bf7*/
    goto LABEL_23; /*0x1a6bf7*/
  }
  if ( v8 != -1102 ) /*0x1a6bd3*/
LABEL_21:
    v8 = -714; /*0x1a6bd5*/
LABEL_23:
  objc_msgSend(v19, sel_unlockLogicalDisks); /*0x1a6bff*/
  if ( v18 ) /*0x1a6c16*/
    IOFree(v18, v17); /*0x1a6c20*/
  return v8; /*0x1a6c2a*/
}
