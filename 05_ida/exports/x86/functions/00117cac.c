/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117cac. */
int __cdecl pipe(int a1[2])
{
  int result; // eax
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // ebx
  char v6; // al
  int v7; // [esp+Ch] [ebp-Ch]
  char *v8; // [esp+10h] [ebp-8h] BYREF
  char *v9; // [esp+14h] [ebp-4h] BYREF

  *(_BYTE *)(dword_1E875C + 104) = socreate(1, &v9, 1, 0); /*0x117ccb*/
  result = dword_1E875C; /*0x117cce*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117cd6*/
  {
    *(_BYTE *)(dword_1E875C + 104) = socreate(1, &v8, 1, 0); /*0x117cf6*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117d01*/
    {
      v2 = falloc(); /*0x117d0b*/
      v3 = v2; /*0x117d10*/
      if ( v2 ) /*0x117d14*/
      {
        v7 = *(_DWORD *)(dword_1E875C + 96); /*0x117d22*/
        *(_DWORD *)(v2 + 8) = 1; /*0x117d25*/
        if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x117d37*/
          *(_DWORD *)(v2 + 8) = 8193; /*0x117d39*/
        *(_WORD *)(v2 + 12) = 2; /*0x117d40*/
        *(_DWORD *)(v2 + 20) = &socketops; /*0x117d46*/
        *(_DWORD *)(v2 + 24) = v9; /*0x117d50*/
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = v2; /*0x117d67*/
        v4 = falloc(); /*0x117d6a*/
        v5 = v4; /*0x117d6f*/
        if ( v4 ) /*0x117d73*/
        {
          *(_DWORD *)(v4 + 8) = 2; /*0x117d79*/
          if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x117d8b*/
            *(_DWORD *)(v4 + 8) = 8194; /*0x117d8d*/
          *(_WORD *)(v4 + 12) = 2; /*0x117d94*/
          *(_DWORD *)(v4 + 20) = &socketops; /*0x117d9a*/
          *(_DWORD *)(v4 + 24) = v8; /*0x117da4*/
          *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = v4; /*0x117dbb*/
          *(_DWORD *)(dword_1E875C + 100) = *(_DWORD *)(dword_1E875C + 96); /*0x117dc6*/
          *(_DWORD *)(dword_1E875C + 96) = v7; /*0x117dd1*/
          v6 = unp_connect2(v8, v9); /*0x117ddc*/
          *(_BYTE *)(dword_1E875C + 104) = v6; /*0x117de8*/
          if ( !v6 ) /*0x117df0*/
          {
            v8[6] |= 0x20u; /*0x117df5*/
            result = (int)v9; /*0x117df9*/
            v9[6] |= 0x10u; /*0x117dfc*/
            return result; /*0x117e00*/
          }
          *(_WORD *)(v5 + 14) = 0; /*0x117e04*/
          *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 100)) = 0; /*0x117e1e*/
        }
        *(_WORD *)(v3 + 14) = 0; /*0x117e25*/
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v7) = 0; /*0x117e39*/
      }
      soclose((int)v8); /*0x117e44*/
    }
    return soclose((int)v9); /*0x117e50*/
  }
  return result; /*0x117e58*/
}
