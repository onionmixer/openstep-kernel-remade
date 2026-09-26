/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c0ac. */
int __cdecl blkpref(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // edi
  signed __int32 v11; // esi
  int v12; // edi
  signed __int32 v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+10h] [ebp-1Ch]
  int v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-1Ch]
  unsigned __int32 v17; // [esp+10h] [ebp-1Ch]
  int v18; // [esp+14h] [ebp-18h]

  v4 = *(_DWORD **)(a1 + 80); /*0x13c0bb*/
  if ( a4 && a3 > 0 ) /*0x13c0c6*/
  {
    if ( a4 == a1 + 140 ) /*0x13c0d3*/
      v13 = *(_DWORD *)(a4 + 4 * a3 - 4); /*0x13c0eb*/
    else
      v13 = _byteswap_ulong(*(_DWORD *)(a4 + 4 * a3 - 4)); /*0x13c0de*/
  }
  v5 = v4[23]; /*0x13c0ee*/
  if ( a3 % v5 && v13 )
  {
    v11 = v4[14] + v13; /*0x13c20f*/
    v16 = v4[22]; /*0x13c215*/
    if ( a3 <= v16
      || (a4 == a1 + 140
        ? (v17 = *(_DWORD *)(a4 + 4 * (a3 - v16)))
        : (v17 = _byteswap_ulong(*(_DWORD *)(a4 + 4 * (a3 - v16)))),
          (v4[22] << v4[24]) + v17 == v11) )
    {
      v12 = v4[16]; /*0x13c298*/
      if ( v12 ) /*0x13c29d*/
        v11 += v4[14] * ((v4[14] + v4[42] * v4[17] * v12 / (1000 * v4[31]) - 1) / v4[14]); /*0x13c2e7*/
    }
    return v11; /*0x13c2e9*/
  }
  else
  {
    if ( a2 <= 11 ) /*0x13c108*/
    {
      v6 = *(_DWORD *)(a1 + 72) / v4[46]; /*0x13c114*/
      return v4[14] + v4[47] * v6; /*0x13c295*/
    }
    if ( a3 && v13 ) /*0x13c12c*/
      v7 = v13 / v4[47] + 1; /*0x13c156*/
    else
      v7 = *(_DWORD *)(a1 + 72) / v4[46] + a2 / v5; /*0x13c148*/
    v18 = v4[11]; /*0x13c15c*/
    v8 = v7 % v18; /*0x13c164*/
    v9 = v4[49] / v18; /*0x13c171*/
    v14 = v8; /*0x13c173*/
    if ( v8 >= v18 ) /*0x13c178*/
    {
LABEL_17:
      v15 = 0; /*0x13c1bd*/
      if ( v8 < 0 ) /*0x13c1c7*/
        return 0; /*0x13c204*/
      while ( *(_DWORD *)(v4[(v15 >> v4[28]) + 182] + 16 * (v15 & ~v4[27]) + 4) < v9 ) /*0x13c1f4*/
      {
        if ( ++v15 > v8 ) /*0x13c200*/
          return 0; /*0x13c200*/
      }
      v6 = v15; /*0x13c280*/
      v4[181] = v15; /*0x13c283*/
      return v4[14] + v4[47] * v6; /*0x13c283*/
    }
    while ( *(_DWORD *)(v4[(v14 >> v4[28]) + 182] + 16 * (v14 & ~v4[27]) + 4) < v9 ) /*0x13c1ac*/
    {
      if ( ++v14 >= v18 ) /*0x13c1bb*/
        goto LABEL_17; /*0x13c1bb*/
    }
    v4[181] = v14; /*0x13c267*/
    return v4[14] + v4[47] * v14; /*0x13c279*/
  }
}
