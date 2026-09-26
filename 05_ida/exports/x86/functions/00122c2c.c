/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122c2c. */
char *__cdecl arptnew(int a1, _DWORD *a2)
{
  char *v2; // esi
  char *v3; // ebx
  char *v4; // edx
  char v5; // al
  int v7; // esi
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v9 = -1; /*0x122c35*/
  v2 = nullptr; /*0x122c3c*/
  if ( dword_1DBA20 ) /*0x122c45*/
  {
    dword_1DBA20 = 0; /*0x122c47*/
    timeout((int)arptimer); /*0x122c5f*/
  }
  v3 = (char *)&arptab + 180 * (*a2 % 0x13u); /*0x122c7e*/
  v8 = 0; /*0x122c85*/
  v4 = v3; /*0x122c8c*/
  while ( 1 ) /*0x122c90*/
  {
    v5 = v4[11]; /*0x122c90*/
    if ( !v5 ) /*0x122c95*/
      break; /*0x122c95*/
    if ( (v5 & 4) == 0 && (!v2 || v9 < (unsigned __int8)v4[10]) ) /*0x122ca6*/
    {
      v9 = (unsigned __int8)v4[10]; /*0x122cac*/
      v2 = v4; /*0x122caf*/
    }
    ++v8; /*0x122cb1*/
    v4 += 20; /*0x122cb4*/
    v3 += 20; /*0x122cb7*/
    if ( v8 > 8 ) /*0x122cbe*/
    {
      if ( !v2 ) /*0x122cc2*/
        return nullptr; /*0x122cc6*/
      v3 = v2; /*0x122cc8*/
      v7 = splimp(); /*0x122ccf*/
      if ( *((_DWORD *)v3 + 3) ) /*0x122cd1*/
        m_freem(*((_DWORD *)v3 + 3)); /*0x122cd9*/
      *((_DWORD *)v3 + 3) = 0; /*0x122ce1*/
      v3[11] = 0; /*0x122ce8*/
      v3[10] = 0; /*0x122cec*/
      *(_DWORD *)v3 = 0; /*0x122cf0*/
      splx(v7); /*0x122cf7*/
      break; /*0x122cf7*/
    }
  }
  *(_DWORD *)v3 = *a2; /*0x122cfc*/
  v3[11] = 1; /*0x122d03*/
  *((_DWORD *)v3 + 4) = a1; /*0x122d0a*/
  return v3; /*0x122d12*/
}
