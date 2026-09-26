/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac88c. */
int __cdecl -[SCSIDisk updateReadyState](SCSIDisk *self, SEL a2)
{
  $BB0ECD142E749ABD0946980FC80D177E *v2; // esi
  _BOOL4 v3; // ebx
  _BYTE v5[3]; // [esp+28h] [ebp-54h] BYREF
  char v6; // [esp+2Bh] [ebp-51h]
  int v7; // [esp+3Ch] [ebp-40h]
  char v8; // [esp+40h] [ebp-3Ch]
  int v9; // [esp+44h] [ebp-38h]

  bzero(v5, 0x54u); /*0x1ac89e*/
  v5[0] = self->_target; /*0x1ac8a9*/
  v5[1] = self->_lun; /*0x1ac8b2*/
  v7 = 20; /*0x1ac8b5*/
  v8 |= 1u; /*0x1ac8bc*/
  v2 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ac8cf*/
  v2->var0 = 3; /*0x1ac8d1*/
  v2->var5 = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v5; /*0x1ac8d7*/
  *((_BYTE *)v2 + 32) = *((_BYTE *)v2 + 32) & 0xFC | 2; /*0x1ac8e1*/
  v5[2] = 0; /*0x1ac8e4*/
  v6 = (32 * self->_lun) | v6 & 0x1F; /*0x1ac8f8*/
  -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v2); /*0x1ac904*/
  v3 = v9 != 0; /*0x1ac917*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v2); /*0x1ac922*/
  return v3; /*0x1ac92c*/
}
