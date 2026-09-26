/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c3b8. */
int __cdecl fragextend(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // ebx
  int *v7; // eax
  _DWORD *v8; // edi
  int v9; // eax
  int v11; // ebx
  int v12; // ecx
  int i; // ebx
  int v14; // edx
  int v15; // eax
  int j; // ebx
  int v17; // edx
  int v18; // eax
  int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+18h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-14h]
  int v22; // [esp+20h] [ebp-10h]
  int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h] BYREF

  v5 = *(_DWORD *)(a1 + 80); /*0x13c3c7*/
  v6 = *(_DWORD *)(v5 + 84); /*0x13c3f3*/
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 4 * (a2 >> *(_DWORD *)(v5 + 112)) + 728) + 16 * (a2 & ~*(_DWORD *)(v5 + 108)) + 12) < (a5 - a4) >> v6 ) /*0x13c404*/
    return 0; /*0x13c404*/
  v21 = a5 >> v6; /*0x13c40e*/
  v19 = *(_DWORD *)(v5 + 56) - 1; /*0x13c415*/
  v20 = v19 & a3; /*0x13c41d*/
  if ( (v19 & a3) > (v19 & ((a5 >> v6) + a3 - 1)) ) /*0x13c42c*/
    return 0; /*0x13c42c*/
  v7 = bread( /*0x13c46b*/
         *(_DWORD *)(a1 + 64),
         (*(_DWORD *)(v5 + 12) + *(_DWORD *)(v5 + 188) * a2 + *(_DWORD *)(v5 + 24) * (a2 & ~*(_DWORD *)(v5 + 28))) << *(_DWORD *)(v5 + 100),
         *(_DWORD *)(v5 + 160));
  v23 = (int)v7; /*0x13c470*/
  v8 = (_DWORD *)v7[8]; /*0x13c473*/
  if ( (*(_BYTE *)v7 & 4) != 0 ) /*0x13c47c*/
  {
    brelse((int)v7); /*0x13c47f*/
    v9 = 0; /*0x13c484*/
  }
  else
  {
    byte_swap_cylgroup(v7[8]); /*0x13c48d*/
    if ( v8[245] == 590421 ) /*0x13c49f*/
    {
      v9 = 1; /*0x13c4b8*/
    }
    else
    {
      byte_swap_cylgroup(v8); /*0x13c4a2*/
      brelse(v23); /*0x13c4ab*/
      v9 = 0; /*0x13c4b0*/
    }
  }
  if ( !v9 ) /*0x13c4bf*/
    return 0; /*0x13c4c1*/
  getthetime(&v24); /*0x13c4cc*/
  v8[2] = v24; /*0x13c4d4*/
  v22 = a3 % *(_DWORD *)(v5 + 188); /*0x13c4e1*/
  v11 = a4 >> *(_DWORD *)(v5 + 84); /*0x13c4ec*/
  if ( v21 <= v11 ) /*0x13c4f4*/
  {
LABEL_13:
    for ( i = v21; *(_DWORD *)(v5 + 56) - v20 > i; ++i ) /*0x13c537*/
    {
      v14 = *((char *)v8 + (i + v22) / 8 + 984); /*0x13c54f*/
      if ( !_bittest(&v14, (i + v22) % 8) ) /*0x13c561*/
        break; /*0x13c564*/
    }
    v15 = i - (a4 >> *(_DWORD *)(v5 + 84)); /*0x13c57c*/
    --v8[v15 + 13]; /*0x13c57e*/
    if ( v21 != i ) /*0x13c585*/
      ++v8[i - v21 + 13]; /*0x13c58c*/
    for ( j = a4 >> *(_DWORD *)(v5 + 84); v21 > j; ++j ) /*0x13c59b*/
    {
      *((_BYTE *)v8 + (j + v22) / 8 + 984) &= __ROL4__(-2, (j + v22) % 8); /*0x13c5c8*/
      --v8[9]; /*0x13c5cf*/
      --*(_DWORD *)(v5 + 204); /*0x13c5d2*/
      v17 = *(_DWORD *)(v5 + 4 * (a2 >> *(_DWORD *)(v5 + 112)) + 728); /*0x13c5e8*/
      v18 = 16 * (a2 & ~*(_DWORD *)(v5 + 108)); /*0x13c5ef*/
      --*(_DWORD *)(v17 + v18 + 12); /*0x13c5f2*/
    }
    ++*(_BYTE *)(v5 + 208); /*0x13c5fc*/
    byte_swap_cylgroup(*(_DWORD *)(v23 + 32)); /*0x13c609*/
    bdwrite(v23); /*0x13c612*/
    return a3; /*0x13c617*/
  }
  else
  {
    while ( 1 ) /*0x13c50b*/
    {
      v12 = *((char *)v8 + (v11 + v22) / 8 + 984); /*0x13c50b*/
      if ( !_bittest(&v12, (v11 + v22) % 8) ) /*0x13c51d*/
        break; /*0x13c51d*/
      if ( v21 <= ++v11 ) /*0x13c52a*/
        goto LABEL_13; /*0x13c52a*/
    }
    byte_swap_cylgroup(*(_DWORD *)(v23 + 32)); /*0x13c623*/
    brelse(v23); /*0x13c62c*/
    return 0; /*0x13c631*/
  }
}
