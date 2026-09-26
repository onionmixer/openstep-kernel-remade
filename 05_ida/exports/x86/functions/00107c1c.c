/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107c1c. */
int __cdecl getgroups(int a1, gid_t a2[])
{
  unsigned int *v2; // esi
  int v3; // eax
  unsigned int v4; // edx
  unsigned int i; // eax
  unsigned int v6; // ebx
  int result; // eax
  char v8; // al
  _DWORD *v9; // ecx
  __int16 *v10; // edx
  _DWORD v11[16]; // [esp+10h] [ebp-40h] BYREF

  v2 = *(unsigned int **)(dword_1E875C + 36); /*0x107c2a*/
  v3 = *(_DWORD *)(active_u + 28); /*0x107c32*/
  v4 = v3 + 42; /*0x107c35*/
  for ( i = v3 + 10; v4 > i; v4 -= 2 ) /*0x107c3d*/
  {
    if ( *(_WORD *)(v4 - 2) != 0xFFFF ) /*0x107c45*/
      break; /*0x107c45*/
  }
  v6 = (int)(v4 - 10 - *(_DWORD *)(active_u + 28)) >> 1; /*0x107c5c*/
  if ( *v2 >= v6 ) /*0x107c60*/
  {
    *v2 = v6; /*0x107c70*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x107c7e*/
    {
      v8 = copyout(*(_DWORD *)(active_u + 28) + 10, v2[1], 2 * v6); /*0x107c8e*/
    }
    else
    {
      v9 = v11; /*0x107c90*/
      v10 = (__int16 *)(*(_DWORD *)(active_u + 28) + 10); /*0x107c99*/
      if ( v11 < &v11[v6] ) /*0x107ca1*/
      {
        do /*0x107cbd*/
          *v9++ = *v10++; /*0x107ca7*/
        while ( v9 < &v11[*v2] ); /*0x107cbd*/
      }
      v8 = copyout(v11, v2[1], 4 * *v2); /*0x107cd1*/
    }
    *(_BYTE *)(dword_1E875C + 104) = v8; /*0x107cdd*/
    result = dword_1E875C; /*0x107ce0*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x107ce5*/
      *(_DWORD *)(dword_1E875C + 96) = *v2; /*0x107ced*/
  }
  else
  {
    result = dword_1E875C; /*0x107c62*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x107c67*/
  }
  return result; /*0x107cf3*/
}
