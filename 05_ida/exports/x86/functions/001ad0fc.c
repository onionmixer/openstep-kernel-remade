/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad0fc. */
int __cdecl -[SCSIDisk sdInquiry:](SCSIDisk *self, SEL a2, $0A9FCFA3D4DB35C0C6B455691B389FC3 *a3)
{
  $BB0ECD142E749ABD0946980FC80D177E *v3; // ebx
  const char *v4; // eax
  int v5; // ebx
  unsigned int v7; // [esp-4h] [ebp-80h]
  char *v8; // [esp+Ch] [ebp-70h]
  int v9; // [esp+10h] [ebp-6Ch] BYREF
  int v10; // [esp+14h] [ebp-68h] BYREF
  _BYTE v11[8]; // [esp+18h] [ebp-64h] BYREF
  unsigned int v12; // [esp+20h] [ebp-5Ch]
  _BYTE v13[3]; // [esp+28h] [ebp-54h] BYREF
  char v14; // [esp+2Bh] [ebp-51h]
  char v15; // [esp+2Eh] [ebp-4Eh]
  char v16; // [esp+36h] [ebp-46h]
  int v17; // [esp+38h] [ebp-44h]
  int v18; // [esp+3Ch] [ebp-40h]
  char v19; // [esp+40h] [ebp-3Ch]
  int v20; // [esp+44h] [ebp-38h]
  unsigned int v21; // [esp+4Ch] [ebp-30h]

  v8 = (char *)objc_msgSend(self->_controller, sel_allocateBufferOfLength_actualStart_actualLength_, 65, &v10, &v9); /*0x1ad12b*/
  bzero(v8, 0x41u); /*0x1ad134*/
  bzero(v13, 0x54u); /*0x1ad13c*/
  v13[0] = self->_target; /*0x1ad147*/
  v13[1] = self->_lun; /*0x1ad150*/
  v16 = 1; /*0x1ad153*/
  objc_msgSend(self->_controller, sel_getDMAAlignment_, v11); /*0x1ad16c*/
  if ( v12 <= 1 ) /*0x1ad17a*/
    v17 = 65; /*0x1ad188*/
  else
    v17 = -v12 & (v12 + 64); /*0x1ad183*/
  v18 = 20; /*0x1ad18f*/
  v19 |= 1u; /*0x1ad196*/
  v3 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad1a9*/
  v3->var0 = 2; /*0x1ad1ab*/
  v3->var5 = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v13; /*0x1ad1b4*/
  v3->var3 = v8; /*0x1ad1ba*/
  v3->var4 = IOVmTaskSelf(); /*0x1ad1c2*/
  v13[2] = 18; /*0x1ad1c5*/
  v14 = (32 * self->_lun) | v14 & 0x1F; /*0x1ad1d9*/
  v15 = 65; /*0x1ad1dc*/
  *((_BYTE *)v3 + 32) = *((_BYTE *)v3 + 32) & 0xFC | 2; /*0x1ad1e7*/
  -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v3); /*0x1ad1f3*/
  if ( v20 )
  {
    v5 = v20; /*0x1ad25c*/
  }
  else if ( v21 >= 5 )
  {
    if ( v21 != 65 ) /*0x1ad237*/
      bzero(&v8[v21], 65 - v21); /*0x1ad23e*/
    qmemcpy(a3, v8, sizeof($0A9FCFA3D4DB35C0C6B455691B389FC3)); /*0x1ad252*/
    v5 = v20; /*0x1ad255*/
  }
  else
  {
    v7 = v21; /*0x1ad20a*/
    v4 = -[IODevice name](self, sel_name); /*0x1ad213*/
    IOLog((int)"%s: bad DMA Transfer count (%d) on Inquiry\n", v4, v7);
    v5 = 22; /*0x1ad226*/
  }
  IOFree(v10, v9); /*0x1ad266*/
  return v5; /*0x1ad270*/
}
