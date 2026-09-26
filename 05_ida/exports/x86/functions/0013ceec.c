/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13ceec. */
int __cdecl free_block(int a1, int a2, unsigned int a3)
{
  int v3; // esi
  unsigned int v4; // ebx
  int result; // eax
  int *v6; // eax
  int v7; // ebx
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // [esp+10h] [ebp-80h]
  int v13; // [esp+10h] [ebp-80h]
  int v14; // [esp+10h] [ebp-80h]
  int v15; // [esp+10h] [ebp-80h]
  int v16; // [esp+1Ch] [ebp-74h]
  int v17; // [esp+24h] [ebp-6Ch]
  int v18; // [esp+34h] [ebp-5Ch]
  unsigned int v19; // [esp+40h] [ebp-50h]
  int v20; // [esp+58h] [ebp-38h]
  int v21; // [esp+70h] [ebp-20h]
  int i; // [esp+70h] [ebp-20h]
  int v23; // [esp+70h] [ebp-20h]
  int v24; // [esp+74h] [ebp-1Ch]
  signed int v25; // [esp+78h] [ebp-18h]
  int v26; // [esp+7Ch] [ebp-14h]
  int v27; // [esp+80h] [ebp-10h]
  _DWORD *v28; // [esp+84h] [ebp-Ch]
  int v29; // [esp+88h] [ebp-8h] BYREF
  int v30; // [esp+9Ch] [ebp+Ch]

  v3 = *(_DWORD *)(a1 + 80); /*0x13cefe*/
  v4 = *(_DWORD *)(v3 + 48); /*0x13cf01*/
  if ( a3 > v4 || (a3 & ~*(_DWORD *)(v3 + 76)) != 0 ) /*0x13cf0f*/
  {
    printf("dev = 0x%x, bsize = %d, size = %d, fs = %s\n", *(__int16 *)(a1 + 70), v4, a3, (const char *)(v3 + 212)); /*0x13cf27*/
    panic(aFreeBlockBadSi); /*0x13cf31*/
  }
  v26 = a2 / *(_DWORD *)(v3 + 188); /*0x13cf43*/
  if ( badblock(v3, a2) ) /*0x13cf4b*/
    return printf("bad block %d, ino %d\n", a2, *(_DWORD *)(a1 + 72)); /*0x13cf69*/
  v6 = bread( /*0x13cfa5*/
         *(_DWORD *)(a1 + 64),
         (*(_DWORD *)(v3 + 12) + *(_DWORD *)(v3 + 188) * v26 + *(_DWORD *)(v3 + 24) * (v26 & ~*(_DWORD *)(v3 + 28))) << *(_DWORD *)(v3 + 100),
         *(_DWORD *)(v3 + 160));
  v27 = (int)v6; /*0x13cfaa*/
  v28 = (_DWORD *)v6[8]; /*0x13cfb0*/
  if ( (*(_BYTE *)v6 & 4) != 0 ) /*0x13cfb9*/
  {
    result = brelse((int)v6); /*0x13cfbc*/
    v7 = 0; /*0x13cfc1*/
  }
  else
  {
    byte_swap_cylgroup(v28); /*0x13cfcc*/
    result = (int)v28; /*0x13cfd4*/
    if ( v28[245] == 590421 ) /*0x13cfe1*/
    {
      v7 = 1; /*0x13cffc*/
    }
    else
    {
      byte_swap_cylgroup(v28); /*0x13cfe4*/
      result = brelse(v27); /*0x13cfed*/
      v7 = 0; /*0x13cff2*/
    }
  }
  if ( v7 ) /*0x13d003*/
  {
    getthetime(&v29); /*0x13d00d*/
    v28[2] = v29; /*0x13d018*/
    v8 = a2 % *(_DWORD *)(v3 + 188); /*0x13d01f*/
    v30 = v8; /*0x13d025*/
    if ( *(_DWORD *)(v3 + 48) == a3 ) /*0x13d02e*/
    {
      if ( isblock(v3, v28 + 246, v8 >> *(_DWORD *)(v3 + 96)) ) /*0x13d047*/
      {
        printf("dev = 0x%x, block = %d, fs = %s\n", *(__int16 *)(a1 + 70), v30, (const char *)(v3 + 212)); /*0x13d06b*/
        panic(aFreeBlockFreei); /*0x13d075*/
      }
      setblock(v3, v28 + 246, v30 >> *(_DWORD *)(v3 + 96)); /*0x13d08a*/
      ++v28[7]; /*0x13d092*/
      ++*(_DWORD *)(v3 + 196); /*0x13d095*/
      v20 = *(_DWORD *)(v3 + 4 * (v26 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d0b4*/
      v12 = 16 * (v26 & ~*(_DWORD *)(v3 + 108)); /*0x13d0ba*/
      ++*(_DWORD *)(v20 + v12 + 4); /*0x13d0bd*/
      v21 = *(_DWORD *)(v3 + 124) * v30 / *(_DWORD *)(v3 + 172); /*0x13d0d3*/
      v9 = 8 * (*(_DWORD *)(v3 + 124) * v30 % *(_DWORD *)(v3 + 172) % *(_DWORD *)(v3 + 168)) / *(_DWORD *)(v3 + 168); /*0x13d0fd*/
      ++*((_WORD *)&v28[4 * v21 + 53] + v9); /*0x13d0ff*/
      ++v28[v21 + 21]; /*0x13d109*/
    }
    else
    {
      v24 = v8 & -*(_DWORD *)(v3 + 56); /*0x13d122*/
      fragacct( /*0x13d181*/
        v3,
        (255 >> (8 - *(_DWORD *)(v3 + 56))) & ((int)*((unsigned __int8 *)v28 + v24 / 8 + 984) >> (v24 % 8)),
        v28 + 13,
        -1);
      v25 = a3 >> *(_DWORD *)(v3 + 84); /*0x13d18d*/
      for ( i = 0; i < v25; ++i ) /*0x13d19d*/
      {
        v10 = *((char *)v28 + (i + v30) / 8 + 984); /*0x13d1b3*/
        v19 = (i + v30) % 8; /*0x13d1c6*/
        if ( _bittest(&v10, v19) ) /*0x13d1c9*/
        {
          printf("dev = 0x%x, block = %d, fs = %s\n", *(__int16 *)(a1 + 70), i + v30, (const char *)(v3 + 212)); /*0x13d1e3*/
          panic(aFreeBlockFreei_0); /*0x13d1ed*/
        }
        *((_BYTE *)v28 + (i + v30) / 8 + 984) |= 1 << v19; /*0x13d208*/
      }
      v28[9] += i; /*0x13d220*/
      *(_DWORD *)(v3 + 204) += i; /*0x13d223*/
      v13 = *(_DWORD *)(v3 + 4 * (v26 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d244*/
      v18 = 16 * (~*(_DWORD *)(v3 + 108) & v26); /*0x13d24a*/
      *(_DWORD *)(v13 + v18 + 12) += i; /*0x13d250*/
      fragacct( /*0x13d2a9*/
        v3,
        (255 >> (8 - *(_BYTE *)(v3 + 56))) & ((int)*((unsigned __int8 *)v28 + v24 / 8 + 984) >> (v24 % 8)),
        v28 + 13,
        1);
      if ( isblock(v3, v28 + 246, v24 >> *(_DWORD *)(v3 + 96)) ) /*0x13d2c4*/
      {
        v28[9] -= *(_DWORD *)(v3 + 56); /*0x13d2dc*/
        *(_DWORD *)(v3 + 204) -= *(_DWORD *)(v3 + 56); /*0x13d2e2*/
        v17 = *(_DWORD *)(v3 + 4 * (v26 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d301*/
        v14 = 16 * (v26 & ~*(_DWORD *)(v3 + 108)); /*0x13d307*/
        *(_DWORD *)(v17 + v14 + 12) -= *(_DWORD *)(v3 + 56); /*0x13d30d*/
        ++v28[7]; /*0x13d314*/
        ++*(_DWORD *)(v3 + 196); /*0x13d317*/
        v16 = *(_DWORD *)(v3 + 4 * (v26 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d336*/
        v15 = 16 * (v26 & ~*(_DWORD *)(v3 + 108)); /*0x13d33c*/
        ++*(_DWORD *)(v16 + v15 + 4); /*0x13d33f*/
        v23 = *(_DWORD *)(v3 + 124) * v24 / *(_DWORD *)(v3 + 172); /*0x13d355*/
        v11 = *(_DWORD *)(v3 + 124) * v24 % *(_DWORD *)(v3 + 172) % *(_DWORD *)(v3 + 168); /*0x13d371*/
        ++*((_WORD *)&v28[4 * v23 + 53] + 8 * v11 / *(_DWORD *)(v3 + 168)); /*0x13d385*/
        ++v28[v23 + 21]; /*0x13d38f*/
      }
    }
    ++*(_BYTE *)(v3 + 208); /*0x13d393*/
    byte_swap_cylgroup(v28); /*0x13d39d*/
    result = bdwrite(v27); /*0x13d3a6*/
    if ( (*(_BYTE *)(v3 + 211) & 1) != 0 ) /*0x13d3b5*/
    {
      result = *(_DWORD *)(v3 + 204) + (*(_DWORD *)(v3 + 196) << *(_DWORD *)(v3 + 96)); /*0x13d3c2*/
      if ( *(_DWORD *)(v3 + 136) < result ) /*0x13d3ce*/
      {
        result = wakeup(v3 + 204); /*0x13d3d7*/
        *(_BYTE *)(v3 + 211) &= ~1u; /*0x13d3dc*/
      }
    }
  }
  return result; /*0x13d3e9*/
}
