/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad548. */
int __cdecl -[SCSIDisk scsiStartStop:inhibitRetry:](SCSIDisk *self, SEL a2, int a3, char a4)
{
  $BB0ECD142E749ABD0946980FC80D177E *v4; // esi
  id v5; // ebx
  _BYTE v7[3]; // [esp+10h] [ebp-54h] BYREF
  char v8; // [esp+13h] [ebp-51h]
  char v9; // [esp+16h] [ebp-4Eh]
  int v10; // [esp+24h] [ebp-40h]
  char v11; // [esp+28h] [ebp-3Ch]

  bzero(v7, 0x54u); /*0x1ad560*/
  v7[0] = self->_target; /*0x1ad56b*/
  v7[1] = self->_lun; /*0x1ad574*/
  v10 = 20; /*0x1ad577*/
  v11 |= 1u; /*0x1ad57e*/
  v4 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad591*/
  v4->var5 = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v7; /*0x1ad593*/
  *((_BYTE *)v4 + 32) = (2 * (a4 != 0)) | *((_BYTE *)v4 + 32) & 0xFD | 1; /*0x1ad5ab*/
  v7[2] = 27; /*0x1ad5ae*/
  v8 = (32 * self->_lun) | v8 & 0x1F; /*0x1ad5c2*/
  switch ( a3 ) /*0x1ad5c9*/
  {
    case 1: /*0x1ad5c9*/
      v9 = 0; /*0x1ad5e0*/
LABEL_7:
      v4->var0 = 3; /*0x1ad5ec*/
      break; /*0x1ad5ec*/
    case 0: /*0x1ad5c9*/
      v9 = 1; /*0x1ad5e8*/
      goto LABEL_7; /*0x1ad5e8*/
    case 2: /*0x1ad5c9*/
      v9 = 2; /*0x1ad5d3*/
      v4->var0 = 4; /*0x1ad5d7*/
      break;
  }
  v5 = -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v4); /*0x1ad5f2*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v4); /*0x1ad60b*/
  return (int)v5; /*0x1ad615*/
}
