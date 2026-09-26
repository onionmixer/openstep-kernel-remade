/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1e70. */
int __cdecl sub_1A1E70(int a1, int a2, __int16 a3)
{
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  unsigned int v11; // [esp+10h] [ebp-4h]

  v3 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a1e82*/
  v4 = 0; /*0x1a1e88*/
  if ( v3 ) /*0x1a1e8c*/
    v4 = *v3; /*0x1a1e8e*/
  if ( v4 ) /*0x1a1e92*/
  {
    v5 = *(_DWORD *)(v4 + 132); /*0x1a1e94*/
    if ( v5 > 7 ) /*0x1a1e9d*/
      v6 = 0; /*0x1a1eb0*/
    else
      v6 = v4 + 132 * v5 + 136; /*0x1a1ea6*/
    v7 = v6; /*0x1a1eb2*/
  }
  else
  {
    v7 = 0; /*0x1a1eb8*/
  }
  v8 = 16 * *(unsigned __int16 *)(a2 + 72); /*0x1a1ecb*/
  v9 = *(unsigned __int16 *)(a2 + 68); /*0x1a1ece*/
  *(_DWORD *)(a1 + 116) = &loc_1A1EEC; /*0x1a1ed6*/
  v11 = __readfsdword(v9 + v8); /*0x1a1ee0*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a1ee3*/
  if ( (*(_BYTE *)(v7 + 128) & 1) != 0 ) /*0x1a1f03*/
    v11 |= *(_DWORD *)(a2 + 64) & 0x100; /*0x1a1f0d*/
  *(_DWORD *)(a2 + 64) = v11; /*0x1a1f13*/
  *(_DWORD *)(a2 + 64) = v11 & 0x50DD5 | 0x20202; /*0x1a1f22*/
  *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) + a3 + 1); /*0x1a1f34*/
  *(_DWORD *)(a2 + 68) = (unsigned __int16)(*(_WORD *)(a2 + 68) + 4); /*0x1a1f44*/
  *(_WORD *)(v7 + 112) = v11 & 0x7000; /*0x1a1f50*/
  if ( (v11 & 0x200) != 0 ) /*0x1a1f58*/
  {
    if ( !*(_DWORD *)(v7 + 104) ) /*0x1a1f5a*/
      *(_DWORD *)(v7 + 116) |= *(_DWORD *)(v7 + 92) & 1; /*0x1a1f66*/
    *(_DWORD *)(v7 + 104) = 1; /*0x1a1f69*/
  }
  else
  {
    *(_DWORD *)(v7 + 104) = 0; /*0x1a1f74*/
  }
  return 1; /*0x1a1f83*/
}
