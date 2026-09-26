/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c640. */
int __cdecl alloccg(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int i; // [esp+Ch] [ebp-20h]
  int v13; // [esp+Ch] [ebp-20h]
  int j; // [esp+Ch] [ebp-20h]
  int v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-1Ch]
  int v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+18h] [ebp-14h]
  int v19; // [esp+1Ch] [ebp-10h]
  int v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+20h] [ebp-Ch]
  int v23; // [esp+24h] [ebp-8h] BYREF
  int v24; // [esp+3Ch] [ebp+10h]

  v4 = *(_DWORD *)(a1 + 80); /*0x13c64c*/
  if ( !*(_DWORD *)(*(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728) + 16 * (a2 & ~*(_DWORD *)(v4 + 108)) + 4) /*0x13c676*/
    && *(_DWORD *)(v4 + 48) == a4 )
  {
    return 0; /*0x13c676*/
  }
  v5 = bread( /*0x13c6aa*/
         *(_DWORD *)(a1 + 64),
         (*(_DWORD *)(v4 + 12) + *(_DWORD *)(v4 + 188) * a2 + *(_DWORD *)(v4 + 24) * (a2 & ~*(_DWORD *)(v4 + 28))) << *(_DWORD *)(v4 + 100),
         *(_DWORD *)(v4 + 160));
  v22 = (int)v5; /*0x13c6af*/
  v6 = (_DWORD *)v5[8]; /*0x13c6b2*/
  if ( (*(_BYTE *)v5 & 4) != 0 ) /*0x13c6bb*/
  {
    brelse((int)v5); /*0x13c6be*/
    v7 = 0; /*0x13c6c3*/
  }
  else
  {
    byte_swap_cylgroup(v5[8]); /*0x13c6cd*/
    if ( v6[245] == 590421 ) /*0x13c6df*/
    {
      v7 = 1; /*0x13c6f8*/
    }
    else
    {
      byte_swap_cylgroup(v6); /*0x13c6e2*/
      brelse(v22); /*0x13c6eb*/
      v7 = 0; /*0x13c6f0*/
    }
  }
  if ( !v7 ) /*0x13c6ff*/
    return 0; /*0x13c703*/
  if ( !v6[7] && *(_DWORD *)(v4 + 48) == a4 ) /*0x13c714*/
  {
    byte_swap_cylgroup(v6); /*0x13c717*/
    brelse(v22); /*0x13c720*/
    return 0; /*0x13c727*/
  }
  getthetime(&v23); /*0x13c730*/
  v6[2] = v23; /*0x13c738*/
  if ( *(_DWORD *)(v4 + 48) == a4 ) /*0x13c744*/
  {
    v19 = alloccgblk(v4, v6, a3); /*0x13c751*/
    byte_swap_cylgroup(v6); /*0x13c755*/
    bdwrite(v22); /*0x13c75e*/
    return v19; /*0x13c766*/
  }
  v18 = a4 >> *(_DWORD *)(v4 + 84); /*0x13c774*/
  v17 = v18; /*0x13c777*/
  v9 = *(_DWORD *)(v4 + 56); /*0x13c77a*/
  if ( v18 < v9 ) /*0x13c77f*/
  {
    do /*0x13c794*/
    {
      if ( v6[v17 + 13] ) /*0x13c787*/
        break; /*0x13c78c*/
      ++v17; /*0x13c78f*/
    }
    while ( v17 < v9 ); /*0x13c794*/
  }
  if ( *(_DWORD *)(v4 + 56) == v17 ) /*0x13c79c*/
  {
    if ( !v6[7] ) /*0x13c7a2*/
    {
LABEL_20:
      byte_swap_cylgroup(v6); /*0x13c7a8*/
      brelse(v22); /*0x13c7b2*/
      return 0; /*0x13c7b9*/
    }
    v20 = alloccgblk(v4, v6, a3); /*0x13c7cb*/
    v24 = v20 % *(_DWORD *)(v4 + 188); /*0x13c7d5*/
    for ( i = v18; *(_DWORD *)(v4 + 56) > i; ++i ) /*0x13c7e4*/
      *((_BYTE *)v6 + (i + v24) / 8 + 984) |= 1 << ((i + v24) % 8); /*0x13c80e*/
    v13 = *(_DWORD *)(v4 + 56) - v18; /*0x13c826*/
    v6[9] += v13; /*0x13c829*/
    *(_DWORD *)(v4 + 204) += v13; /*0x13c82c*/
    v10 = *(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728); /*0x13c842*/
    v15 = 16 * (a2 & ~*(_DWORD *)(v4 + 108)); /*0x13c84c*/
    *(_DWORD *)(v10 + v15 + 12) += v13; /*0x13c84f*/
    ++*(_BYTE *)(v4 + 208); /*0x13c853*/
    ++v6[v13 + 13]; /*0x13c859*/
    byte_swap_cylgroup(v6); /*0x13c85e*/
    bdwrite(v22); /*0x13c867*/
    return v20; /*0x13c86c*/
  }
  else
  {
    v21 = mapsearch(v4, v6, a3, v17); /*0x13c883*/
    if ( v21 < 0 ) /*0x13c88b*/
      goto LABEL_20; /*0x13c88b*/
    for ( j = 0; j < v18; ++j ) /*0x13c8b1*/
      *((_BYTE *)v6 + (j + v21) / 8 + 984) &= __ROL4__(-2, (j + v21) % 8); /*0x13c8d4*/
    v6[9] -= v18; /*0x13c8e9*/
    *(_DWORD *)(v4 + 204) -= v18; /*0x13c8ec*/
    v11 = *(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728); /*0x13c902*/
    v16 = 16 * (a2 & ~*(_DWORD *)(v4 + 108)); /*0x13c90c*/
    *(_DWORD *)(v11 + v16 + 12) -= v18; /*0x13c90f*/
    ++*(_BYTE *)(v4 + 208); /*0x13c913*/
    --v6[v17 + 13]; /*0x13c91c*/
    if ( v18 != v17 ) /*0x13c923*/
      ++v6[v17 - v18 + 13]; /*0x13c92b*/
    byte_swap_cylgroup(v6); /*0x13c930*/
    bdwrite(v22); /*0x13c939*/
    return v21 + *(_DWORD *)(v4 + 188) * a2; /*0x13c948*/
  }
}
