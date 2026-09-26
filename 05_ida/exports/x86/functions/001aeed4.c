/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aeed4. */
int __cdecl -[SCSIGeneric getSense:](SCSIGeneric *self, SEL a2, $55B996686E2E2C4974FEF7D53845AF12 *a3)
{
  int v3; // eax
  id v4; // ebx
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

  v6 = objc_msgSend(self->_controller, sel_allocateBufferOfLength_actualStart_actualLength_, 26, &v8, &v7); /*0x1aef03*/
  bzero(v11, 0x54u); /*0x1aef09*/
  objc_msgSend(self->_controller, sel_getDMAAlignment_, v9); /*0x1aef20*/
  v11[0] = self->_target; /*0x1aef2b*/
  v11[1] = self->_lun; /*0x1aef34*/
  v14 = 1; /*0x1aef37*/
  if ( v10 <= 1 ) /*0x1aef44*/
    v15 = 26; /*0x1aef54*/
  else
    v15 = -v10 & (v10 + 25); /*0x1aef4d*/
  v16 = 10; /*0x1aef5b*/
  v17 &= ~1u; /*0x1aef62*/
  v11[2] = 3; /*0x1aef66*/
  v12 = (32 * LOBYTE(self->_lun)) | v12 & 0x1F; /*0x1aef7a*/
  v13 = 26; /*0x1aef7d*/
  v3 = IOVmTaskSelf(); /*0x1aef81*/
  v4 = objc_msgSend(self->_controller, sel_executeRequest_buffer_client_, v11, v6, v3); /*0x1aefa2*/
  if ( !v4 ) /*0x1aefa9*/
    qmemcpy(a3, v6, sizeof($55B996686E2E2C4974FEF7D53845AF12)); /*0x1aefb7*/
  IOFree(v8, v7); /*0x1aefc3*/
  return (int)v4; /*0x1aefcd*/
}
