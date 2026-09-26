/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6c4c. */
int __cdecl -[IODiskPartition NeXTpartitionOffset](IODiskPartition *self, SEL a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // edx
  int i; // ecx
  char v8; // [esp+Ch] [ebp-Ch]
  id v9; // [esp+10h] [ebp-8h]
  _BYTE v10[4]; // [esp+14h] [ebp-4h] BYREF

  v2 = 0; /*0x1a6c55*/
  v9 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a6c67*/
  v3 = IOMalloc(page_size); /*0x1a6c76*/
  v8 = 0; /*0x1a6c78*/
  if ( -[IOLogicalDisk physicalBlockSize](self, sel_physicalBlockSize) == 512 ) /*0x1a6c94*/
  {
    v4 = IOVmTaskSelf(); /*0x1a6c96*/
    if ( objc_msgSend(v9, sel_readAt_length_buffer_actualLength_client_, 0, 512, v3, v10, v4) ) /*0x1a6cb3*/
    {
      v2 = -1103; /*0x1a6cbf*/
    }
    else if ( *(_WORD *)(v3 + 510) == 0xAA55 ) /*0x1a6cd9*/
    {
      v5 = v3 + 446; /*0x1a6cdb*/
      for ( i = 0; i <= 3; ++i ) /*0x1a6ce1*/
      {
        if ( *(_BYTE *)(v5 + 4) ) /*0x1a6ce4*/
        {
          if ( *(unsigned __int8 *)(v5 + 4) == 167 ) /*0x1a6cf1*/
          {
            v2 = *(_DWORD *)(v5 + 8); /*0x1a6cc8*/
            goto LABEL_13; /*0x1a6ccb*/
          }
          v8 = 1; /*0x1a6cf3*/
        }
        v5 += 16; /*0x1a6cf8*/
      }
      if ( v8 ) /*0x1a6d04*/
        v2 = -1104; /*0x1a6d06*/
    }
  }
LABEL_13:
  IOFree(v3, page_size); /*0x1a6d0b*/
  return v2; /*0x1a6d1d*/
}
