/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104568. */
int __cdecl close(int a1)
{
  unsigned int v1; // ebx
  int v2; // eax
  int v3; // esi
  int result; // eax
  _BYTE *v5; // edi
  int v6; // edx

  v1 = **(_DWORD **)(dword_1E875C + 36); /*0x104576*/
  if ( *(_DWORD *)(active_u + 348) > v1 /*0x104598*/
    && (v2 = *(_DWORD *)(active_u + 336), (v3 = *(_DWORD *)(v2 + 4 * v1)) != 0)
    && v3 != -65536 )
  {
    vno_lockrelease(*(_DWORD *)(v2 + 4 * v1)); /*0x1045a9*/
    v5 = (_BYTE *)(v1 + *(_DWORD *)(active_u + 340)); /*0x1045b9*/
    if ( (*v5 & 2) != 0 ) /*0x1045c1*/
      munmapfd(v1); /*0x1045c4*/
    *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v1) = 0; /*0x1045d7*/
    while ( 1 ) /*0x1045ec*/
    {
      v6 = *(_DWORD *)(active_u + 344); /*0x1045ec*/
      if ( v6 < 0 || *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v6) ) /*0x1045fc*/
        break; /*0x1045fc*/
      --*(_DWORD *)(active_u + 344); /*0x1045e0*/
    }
    *v5 = 0; /*0x104602*/
    closef(v3); /*0x104606*/
    result = *(_DWORD *)active_u; /*0x104610*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x104616*/
    {
      result = dword_1E875C; /*0x104618*/
      if ( *(_BYTE *)(dword_1E875C + 104) == 28 && (*(_BYTE *)(v3 + 9) & 0x10) != 0 ) /*0x104627*/
        *(_BYTE *)(dword_1E875C + 104) = 0; /*0x104629*/
    }
  }
  else
  {
    result = dword_1E875C; /*0x10459a*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10459f*/
  }
  return result; /*0x104630*/
}
