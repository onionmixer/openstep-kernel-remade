/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad3a8. */
int __cdecl -[SCSIDisk sdModeSense:](SCSIDisk *self, SEL a2, $F578ED3057E37945D41387235BAFAD6B *a3)
{
  $BB0ECD142E749ABD0946980FC80D177E *v3; // ebx
  int v4; // ebx
  id v6; // [esp+Ch] [ebp-70h]
  int v7; // [esp+10h] [ebp-6Ch] BYREF
  int v8; // [esp+14h] [ebp-68h] BYREF
  _BYTE v9[8]; // [esp+18h] [ebp-64h] BYREF
  unsigned int v10; // [esp+20h] [ebp-5Ch]
  _BYTE v11[3]; // [esp+28h] [ebp-54h] BYREF
  char v12; // [esp+2Bh] [ebp-51h]
  char v13; // [esp+2Eh] [ebp-4Eh]
  char v14; // [esp+36h] [ebp-46h]
  int v15; // [esp+38h] [ebp-44h]
  int v16; // [esp+3Ch] [ebp-40h]
  char v17; // [esp+40h] [ebp-3Ch]
  int v18; // [esp+44h] [ebp-38h]

  v6 = objc_msgSend(self->_controller, sel_allocateBufferOfLength_actualStart_actualLength_, 60, &v8, &v7); /*0x1ad3d7*/
  bzero(v11, 0x54u); /*0x1ad3dd*/
  v11[0] = self->_target; /*0x1ad3e8*/
  v11[1] = self->_lun; /*0x1ad3f1*/
  v14 = 1; /*0x1ad3f4*/
  objc_msgSend(self->_controller, sel_getDMAAlignment_, v9); /*0x1ad40a*/
  if ( v10 <= 1 ) /*0x1ad418*/
    v15 = 60; /*0x1ad428*/
  else
    v15 = -v10 & (v10 + 59); /*0x1ad421*/
  v16 = 20; /*0x1ad42f*/
  v17 |= 1u; /*0x1ad436*/
  v3 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad449*/
  v3->var0 = 2; /*0x1ad44b*/
  v3->var5 = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v11; /*0x1ad454*/
  v3->var3 = v6; /*0x1ad45a*/
  v3->var4 = IOVmTaskSelf(); /*0x1ad462*/
  v11[2] = 26; /*0x1ad465*/
  v12 = (32 * self->_lun) | v12 & 0x1F; /*0x1ad478*/
  v13 = 60; /*0x1ad47b*/
  *((_BYTE *)v3 + 32) |= 1u; /*0x1ad47f*/
  -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v3); /*0x1ad48c*/
  if ( !v18 ) /*0x1ad499*/
    qmemcpy(a3, v6, sizeof($F578ED3057E37945D41387235BAFAD6B)); /*0x1ad4a7*/
  v4 = v18; /*0x1ad4a9*/
  IOFree(v8, v7); /*0x1ad4ba*/
  return v4; /*0x1ad4c4*/
}
