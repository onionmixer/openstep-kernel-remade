/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac5a0. */
int __cdecl -[SCSIDisk updatePhysicalParameters](SCSIDisk *self, SEL a2)
{
  unsigned __int16 v2; // dx
  unsigned __int16 v3; // bx
  int v5; // ebx
  int v6; // ebx
  id v7; // eax
  int v8; // edx
  int v9; // edx
  id v10; // eax
  int v11; // esi
  int i; // ebx
  int v13; // [esp-4h] [ebp-68h]
  id v14; // [esp+Ch] [ebp-58h]
  unsigned __int16 v15; // [esp+10h] [ebp-54h]
  char v16; // [esp+14h] [ebp-50h]
  int v17; // [esp+18h] [ebp-4Ch] BYREF
  int v18; // [esp+1Ch] [ebp-48h] BYREF
  _BYTE v19[8]; // [esp+20h] [ebp-44h] BYREF
  _BYTE v20[60]; // [esp+28h] [ebp-3Ch] BYREF

  v16 = 0; /*0x1ac5a9*/
  v15 = v2; /*0x1ac5b8*/
  if ( -[SCSIDisk updateReadyState](self, sel_updateReadyState) ) /*0x1ac5bb*/
    return -728; /*0x1ac5ca*/
  if ( -[SCSIDisk sdReadCapacity:](self, sel_sdReadCapacity_, v19) ) /*0x1ac5e6*/
    return -714; /*0x1ac5f5*/
  v5 = (v19[1] << 16) | (v19[0] << 24) | v3; /*0x1ac61b*/
  BYTE1(v5) = 0; /*0x1ac624*/
  v6 = (v19[2] << 8) | v5; /*0x1ac626*/
  LOBYTE(v6) = v19[3]; /*0x1ac628*/
  v7 = -[IODisk setDiskSize:](self, sel_setDiskSize_, v6 + 1); /*0x1ac63d*/
  LOBYTE(v7) = v19[4]; /*0x1ac645*/
  v8 = (v19[5] << 16) | ((_DWORD)v7 << 24) | v15; /*0x1ac663*/
  BYTE1(v8) = 0; /*0x1ac66c*/
  v9 = (v19[6] << 8) | v8; /*0x1ac66e*/
  LOBYTE(v9) = v19[7]; /*0x1ac670*/
  -[IODisk setBlockSize:](self, sel_setBlockSize_, v9); /*0x1ac67c*/
  v10 = -[IODisk blockSize](self, sel_blockSize); /*0x1ac68c*/
  v14 = objc_msgSend(self->_controller, sel_allocateBufferOfLength_actualStart_actualLength_, v10, &v18, &v17); /*0x1ac6b2*/
  v11 = 10; /*0x1ac6b5*/
  for ( i = 0; i <= 4; ++i ) /*0x1ac6ba*/
  {
    if ( !-[SCSIDisk sdRawRead:blockCnt:buffer:](self, sel_sdRawRead_blockCnt_buffer_, v11, 1, v14) ) /*0x1ac6d2*/
    {
      v13 = 1; /*0x1ac6de*/
      goto LABEL_10; /*0x1ac6e0*/
    }
    v11 += 10; /*0x1ac6e4*/
  }
  v13 = 0; /*0x1ac6ed*/
LABEL_10:
  -[IODisk setFormattedInternal:](self, sel_setFormattedInternal_, v13); /*0x1ac6ef*/
  IOFree(v18, v17); /*0x1ac70a*/
  if ( self->_inquiryDeviceType == 5 /*0x1ac741*/
    || (bzero(v20, 0x3Cu), -[SCSIDisk sdModeSense:](self, sel_sdModeSense_, v20), v20[2] < 0) )
  {
    v16 = 1; /*0x1ac743*/
  }
  -[IODisk setWriteProtected:](self, sel_setWriteProtected_, v16); /*0x1ac757*/
  return 0; /*0x1ac761*/
}
