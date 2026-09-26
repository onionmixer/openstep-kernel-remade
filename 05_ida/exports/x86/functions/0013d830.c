/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13d830. */
int __cdecl bmap(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // edx
  unsigned int v6; // ebx
  char v7; // cl
  int v8; // esi
  size_t v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  int v16; // edx
  unsigned int v17; // edi
  int v18; // eax
  int v19; // ebx
  int v20; // edi
  int v21; // eax
  unsigned int v22; // ebx
  int v23; // ebx
  int i; // edi
  int v25; // eax
  unsigned int v26; // esi
  int v27; // eax
  int v28; // eax
  int v29; // ebx
  int v30; // eax
  size_t v31; // [esp-8h] [ebp-58h]
  int v32; // [esp-4h] [ebp-54h]
  int v33; // [esp+18h] [ebp-38h]
  int v34; // [esp+2Ch] [ebp-24h]
  int v35; // [esp+30h] [ebp-20h]
  int v36; // [esp+38h] [ebp-18h]
  int v37; // [esp+3Ch] [ebp-14h]
  int v39; // [esp+44h] [ebp-Ch]
  _DWORD *v40; // [esp+48h] [ebp-8h]
  int v41; // [esp+4Ch] [ebp-4h]
  int v42; // [esp+5Ch] [ebp+Ch]

  v41 = 0; /*0x13d83c*/
  v37 = 0; /*0x13d843*/
  if ( a2 < 0 ) /*0x13d84e*/
    goto LABEL_47; /*0x13d84e*/
  v40 = *(_DWORD **)(a1 + 80); /*0x13d85a*/
  rablock = 0; /*0x13d85d*/
  rasize = 0; /*0x13d867*/
  v5 = a3; /*0x13d871*/
  if ( (a3 & 0x20) != 0 ) /*0x13d877*/
  {
    LOBYTE(v5) = a3 & 0xDF; /*0x13d879*/
    a3 = v5; /*0x13d87c*/
  }
  v6 = *(_DWORD *)(a1 + 108); /*0x13d882*/
  v7 = v40[20]; /*0x13d890*/
  v8 = v6 >> v7; /*0x13d892*/
  if ( !a3 && v8 <= 11 && a2 > v8 && *(_DWORD *)(a1 + 4 * v8 + 140) )
  {
    v9 = v6 < (v8 + 1) << v7 ? v40[19] & (v40[13] + (~v40[18] & v6) - 1) : v40[12];
    if ( v9 < v40[12] && v9 ) /*0x13d903*/
    {
      v32 = v40[12]; /*0x13d909*/
      v10 = blkpref(a1, v8, v8, a1 + 140); /*0x13d91a*/
      v11 = realloccg(a1, *(_DWORD *)(a1 + 4 * v8 + 140), v10, v9, v32); /*0x13d934*/
      if ( !v11 ) /*0x13d940*/
        return -1; /*0x13d9bf*/
      *(_DWORD *)(a1 + 108) = v40[12] * (v8 + 1); /*0x13d94f*/
      *(_DWORD *)(a1 + 4 * v8 + 140) = *(int *)(v11 + 36) >> v40[25]; /*0x13d962*/
      *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13d969*/
      if ( a5 ) /*0x13d971*/
      {
        bwrite(v11); /*0x13d974*/
        iupdat(a1, 1); /*0x13d97f*/
      }
      else
      {
        bdwrite(v11); /*0x13d98d*/
      }
    }
  }
  if ( a2 <= 11 ) /*0x13d999*/
  {
    v12 = *(_DWORD *)(a1 + 4 * a2 + 140); /*0x13d9a5*/
    if ( a3 == 1 ) /*0x13d9b0*/
    {
      if ( !v12 ) /*0x13d9b4*/
        return -1; /*0x13d9b4*/
      goto LABEL_36; /*0x13d9b4*/
    }
    if ( v12 ) /*0x13d9c6*/
    {
      v14 = *(_DWORD *)(a1 + 108); /*0x13d9d6*/
      if ( v14 >= v40[12] * (a2 + 1) /*0x13da04*/
        || (v35 = ~v40[18] & v14,
            v15 = v40[13],
            v16 = v40[19],
            v17 = v16 & (v15 + a4 - 1),
            v17 <= (v16 & (unsigned int)(v15 + v35 - 1))) )
      {
LABEL_36:
        if ( a2 <= 10 ) /*0x13daeb*/
        {
          rablock = *(_DWORD *)(a1 + 4 * a2 + 144) << v40[25]; /*0x13db04*/
          if ( a2 + 1 <= 11 && (v22 = *(_DWORD *)(a1 + 108), v22 < (a2 + 2) << v40[20]) ) /*0x13db30*/
            v23 = v40[19] & (v40[13] + (~v40[18] & v22) - 1); /*0x13db51*/
          else
            v23 = v40[12]; /*0x13db35*/
          rasize = v23; /*0x13db54*/
        }
        return v12; /*0x13db5c*/
      }
      v31 = v16 & (v15 + v35 - 1); /*0x13da0b*/
      v18 = blkpref(a1, a2, a2, a1 + 140); /*0x13da1f*/
      v19 = realloccg(a1, v12, v18, v31, v17); /*0x13da34*/
    }
    else
    {
      if ( *(_DWORD *)(a1 + 108) >= (unsigned int)(v40[12] * (a2 + 1)) ) /*0x13da4f*/
        v20 = v40[12]; /*0x13da60*/
      else
        v20 = v40[19] & (v40[13] + a4 - 1); /*0x13da59*/
      v21 = blkpref(a1, a2, a2, a1 + 140); /*0x13da76*/
      v19 = alloc(a1, v21, v20); /*0x13da8a*/
    }
    if ( !v19 ) /*0x13da91*/
      return -1; /*0x13da91*/
    v12 = *(int *)(v19 + 36) >> v40[25]; /*0x13daa4*/
    if ( a5 ) /*0x13daaa*/
      *a5 = 1; /*0x13daaf*/
    if ( (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 ) /*0x13dac6*/
      bwrite(v19); /*0x13dac9*/
    else
      bdwrite(v19); /*0x13dad1*/
    *(_DWORD *)(a1 + 4 * a2 + 140) = v12; /*0x13dadc*/
    *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13dae3*/
    goto LABEL_36; /*0x13dae3*/
  }
  v36 = 0; /*0x13db64*/
  v39 = 1; /*0x13db6b*/
  v42 = a2 - 12; /*0x13db7d*/
  for ( i = 3; i > 0; --i ) /*0x13db80*/
  {
    v25 = v40[29] * v39; /*0x13db8f*/
    v39 = v25; /*0x13db92*/
    if ( v42 < v25 ) /*0x13db98*/
      break; /*0x13db98*/
    v42 -= v25; /*0x13db9a*/
  }
  if ( !i ) /*0x13dba4*/
  {
LABEL_47:
    *(_BYTE *)(dword_1E875C + 104) = 27; /*0x13dbab*/
    return 0; /*0x13dbb1*/
  }
  v26 = *(_DWORD *)(a1 + 4 * (3 - i) + 188); /*0x13dbc5*/
  if ( v26 ) /*0x13dbce*/
    goto LABEL_76; /*0x13dbce*/
  if ( a3 == 1 ) /*0x13dbd8*/
    return -1; /*0x13dbd8*/
  v36 = blkpref(a1, a2, 0, 0); /*0x13dbef*/
  v27 = alloc(a1, v36, v40[12]); /*0x13dc01*/
  if ( !v27 ) /*0x13dc0d*/
    return -1; /*0x13dc0d*/
  v26 = *(int *)(v27 + 36) >> v40[25]; /*0x13dc51*/
  bwrite(v27); /*0x13dc54*/
  *(_DWORD *)(a1 + 4 * (3 - i) + 188) = v26; /*0x13dc5f*/
  *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13dc66*/
  if ( a5 ) /*0x13dc71*/
    *a5 = 1; /*0x13dc7a*/
LABEL_76:
  while ( i <= 3 ) /*0x13ddc9*/
  {
    v28 = bread(*(_DWORD *)(a1 + 64), v26 << v40[25], v40[12]); /*0x13dca4*/
    v29 = v28; /*0x13dca9*/
    if ( (*(_BYTE *)v28 & 4) != 0 ) /*0x13dcb1*/
    {
      brelse(v28); /*0x13dc15*/
      return 0; /*0x13dc1c*/
    }
    v37 = *(_DWORD *)(v28 + 32); /*0x13dcba*/
    v33 = v40[29]; /*0x13dcc3*/
    v39 /= v33; /*0x13dccc*/
    v41 = v42 / v39 % v33; /*0x13dcdb*/
    v26 = _byteswap_ulong(*(_DWORD *)(v37 + 4 * v41)); /*0x13dce6*/
    if ( v26 ) /*0x13dcea*/
    {
      brelse(v28); /*0x13ddbd*/
    }
    else
    {
      if ( a3 == 1 ) /*0x13dcf4*/
      {
        brelse(v28); /*0x13dc25*/
        return -1; /*0x13dc2f*/
      }
      if ( !v36 ) /*0x13dcfe*/
      {
        if ( i > 2 ) /*0x13dd03*/
          v30 = blkpref(a1, a2, v41, v37); /*0x13dd24*/
        else
          v30 = blkpref(a1, a2, 0, 0); /*0x13dd11*/
        v36 = v30; /*0x13dd29*/
      }
      v34 = alloc(a1, v36, v40[12]); /*0x13dd43*/
      if ( !v34 ) /*0x13dd4b*/
      {
        brelse(v29); /*0x13dc35*/
        return -1; /*0x13dc3f*/
      }
      v26 = *(int *)(v34 + 36) >> v40[25]; /*0x13dd61*/
      if ( i <= 2 || (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 || a5 ) /*0x13dd7f*/
        bwrite(v34); /*0x13dd85*/
      else
        bdwrite(v34); /*0x13dd90*/
      *(_DWORD *)(v37 + 4 * v41) = _byteswap_ulong(v26); /*0x13dda2*/
      if ( a5 ) /*0x13dda9*/
        bwrite(v29); /*0x13ddac*/
      else
        bdwrite(v29); /*0x13ddb5*/
    }
    ++i; /*0x13ddc5*/
  }
  if ( v41 < v40[29] - 1 ) /*0x13ddd9*/
  {
    rablock = _byteswap_ulong(*(_DWORD *)(v37 + 4 * v41 + 4)) << v40[25]; /*0x13ddf7*/
    rasize = v40[12]; /*0x13de02*/
  }
  return v26; /*0x13de0d*/
}
