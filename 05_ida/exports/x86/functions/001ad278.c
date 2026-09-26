/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad278. */
int __cdecl -[SCSIDisk sdReadCapacity:](SCSIDisk *self, SEL a2, $BA838A1BD45D3F0978456B4EB2CEA418 *a3)
{
  $BB0ECD142E749ABD0946980FC80D177E *v3; // ebx
  int v4; // ebx
  $BA838A1BD45D3F0978456B4EB2CEA418 *v6; // [esp+14h] [ebp-70h]
  int v7; // [esp+18h] [ebp-6Ch] BYREF
  int v8; // [esp+1Ch] [ebp-68h] BYREF
  _BYTE v9[8]; // [esp+20h] [ebp-64h] BYREF
  unsigned int v10; // [esp+28h] [ebp-5Ch]
  _BYTE v11[3]; // [esp+30h] [ebp-54h] BYREF
  char v12; // [esp+33h] [ebp-51h]
  char v13; // [esp+3Eh] [ebp-46h]
  int v14; // [esp+40h] [ebp-44h]
  int v15; // [esp+44h] [ebp-40h]
  char v16; // [esp+48h] [ebp-3Ch]
  int v17; // [esp+4Ch] [ebp-38h]

  v6 = ($BA838A1BD45D3F0978456B4EB2CEA418 *)objc_msgSend( /*0x1ad2aa*/
                                              self->_controller,
                                              sel_allocateBufferOfLength_actualStart_actualLength_,
                                              8,
                                              &v8,
                                              &v7);
  bzero(v11, 0x54u); /*0x1ad2b0*/
  v11[0] = self->_target; /*0x1ad2bb*/
  v11[1] = self->_lun; /*0x1ad2c4*/
  v13 = 1; /*0x1ad2c7*/
  objc_msgSend(self->_controller, sel_getDMAAlignment_, v9); /*0x1ad2dd*/
  if ( v10 <= 1 ) /*0x1ad2eb*/
    v14 = 8; /*0x1ad2fc*/
  else
    v14 = -v10 & (v10 + 7); /*0x1ad2f4*/
  v15 = 20; /*0x1ad303*/
  v16 |= 1u; /*0x1ad30a*/
  v3 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad31d*/
  v3->var0 = 2; /*0x1ad31f*/
  v3->var5 = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v11; /*0x1ad328*/
  v3->var3 = v6; /*0x1ad32e*/
  v3->var4 = IOVmTaskSelf(); /*0x1ad336*/
  v11[2] = 37; /*0x1ad33c*/
  v12 = (32 * self->_lun) | v12 & 0x1F; /*0x1ad353*/
  *((_BYTE *)v3 + 32) &= ~1u; /*0x1ad356*/
  -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v3); /*0x1ad363*/
  if ( !v17 ) /*0x1ad370*/
    *a3 = *v6; /*0x1ad37a*/
  v4 = v17; /*0x1ad382*/
  IOFree(v8, v7); /*0x1ad392*/
  return v4; /*0x1ad39f*/
}
