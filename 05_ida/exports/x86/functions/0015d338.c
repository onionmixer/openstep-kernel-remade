/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d338. */
int __cdecl sub_15D338(_DWORD *a1, int a2, int a3)
{
  _BYTE *v3; // edx
  int result; // eax
  int v6; // ebx
  unsigned int v7; // [esp+Ch] [ebp-40h] BYREF
  int v8; // [esp+10h] [ebp-3Ch] BYREF
  unsigned int v9; // [esp+14h] [ebp-38h] BYREF
  int v10; // [esp+18h] [ebp-34h] BYREF
  _DWORD __b[5]; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD v12[7]; // [esp+30h] [ebp-1Ch] BYREF

  v3 = (char *)a1 + a1[2]; /*0x15d349*/
  do /*0x15d35d*/
  {
    if ( v3 >= (_BYTE *)a1 + a1[1] ) /*0x15d352*/
      return 2; /*0x15d3d8*/
  }
  while ( *v3++ ); /*0x15d35d*/
  result = sub_15D57C((int)a1 + a1[2], v12, &v10, &v9, &v8); /*0x15d370*/
  if ( !result ) /*0x15d37c*/
  {
    memset(__b, 0, sizeof(__b)); /*0x15d386*/
    __b[0] = 0; /*0x15d38e*/
    v6 = sub_15CB1C(v8, a2, v12, v10, v9, a3, (int)&v7, (int)__b); /*0x15d3b4*/
    if ( !v6 && v7 < a1[3] ) /*0x15d3c3*/
      v6 = 3; /*0x15d3c5*/
    vn_rele(v8); /*0x15d3ce*/
    return v6; /*0x15d3d3*/
  }
  return result; /*0x15d3e0*/
}
