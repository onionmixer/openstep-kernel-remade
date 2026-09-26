/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8dec. */
id __cdecl -[HashTable copyFromZone:](HashTable *self, SEL a2, $3D27A55567FB06BC0E416B979767FD15 *a3)
{
  id v3; // eax
  id v4; // eax
  id v5; // ebx
  int v6; // edx
  int v8; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-Ch] BYREF
  _DWORD v10[2]; // [esp+10h] [ebp-8h] BYREF

  v3 = -[Object class](self, sel_class); /*0x1c8e1d*/
  v4 = objc_msgSend(v3, sel_allocFromZone_); /*0x1c8e26*/
  v5 = objc_msgSend(v4, sel_initKeyDesc_valueDesc_capacity_); /*0x1c8e34*/
  v10[0] = -[HashTable initState](self, sel_initState); /*0x1c8e43*/
  v10[1] = v6; /*0x1c8e46*/
  while ( -[HashTable nextState:key:value:](self, sel_nextState_key_value_, v10, &v9, &v8) ) /*0x1c8e6a*/
    objc_msgSend(v5, sel_insertKey_value_, v9, v8); /*0x1c8e7c*/
  return v5; /*0x1c8e8d*/
}
