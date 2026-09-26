/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x143e24. */
int __cdecl sub_143E24(int a1, _DWORD *a2, unsigned int a3, char a4)
{
  int v4; // edx
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  unsigned int v9; // ebx
  int v10; // edx
  int v11; // esi
  int *v12; // ecx
  int v13; // ebx
  char v14; // cl
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // ecx
  int *v19; // ebx
  int *v20; // eax
  int v21; // eax
  __int16 v22; // cx
  int v23; // [esp+14h] [ebp-24h]
  int v24; // [esp+18h] [ebp-20h]
  unsigned int v25; // [esp+1Ch] [ebp-1Ch]
  int v26; // [esp+20h] [ebp-18h]
  int v27; // [esp+24h] [ebp-14h]
  int v28; // [esp+28h] [ebp-10h]
  _DWORD *v29; // [esp+2Ch] [ebp-Ch]
  int v30; // [esp+30h] [ebp-8h]
  int v31; // [esp+34h] [ebp-4h] BYREF

  v31 = 0; /*0x143e37*/
  v23 = a2[5]; /*0x143e44*/
  if ( a3 > 1 ) /*0x143e4b*/
    panic(aRwip); /*0x143e52*/
  v4 = *(_WORD *)(a1 + 100) & 0xF000; /*0x143e5e*/
  v26 = v4; /*0x143e64*/
  if ( v4 != 0x8000 && v4 != 0x4000 && v4 != 40960 ) /*0x143e7d*/
    panic(aRwipType); /*0x143e84*/
  v5 = a2[2]; /*0x143e8f*/
  if ( v5 < 0 ) /*0x143e94*/
    return 22; /*0x143e94*/
  v6 = a2[5]; /*0x143e96*/
  v7 = v6 + v5; /*0x143e99*/
  if ( v7 < 0 ) /*0x143e9b*/
    return 22; /*0x143ea2*/
  if ( !v6 ) /*0x143eaa*/
    return 0; /*0x143eae*/
  if ( a3 == 1 ) /*0x143eb8*/
  {
    if ( v4 == 0x8000 && *(_DWORD *)(active_u + 620) < (unsigned int)v7 ) /*0x143ecf*/
    {
      psignal(*(_DWORD *)active_u, (const char *)0x19); /*0x143ed6*/
      return 27; /*0x143ee0*/
    }
  }
  else
  {
    *(_BYTE *)(a1 + 68) |= 4u; /*0x143f14*/
  }
  v30 = *(_DWORD *)(a1 + 64); /*0x143f1b*/
  v29 = *(_DWORD **)(a1 + 80); /*0x143f21*/
  v25 = v29[12]; /*0x143f27*/
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x143f2f*/
  while ( 1 ) /*0x143f37*/
  {
    v9 = a2[2]; /*0x143f37*/
    v10 = v9 % v25; /*0x143f3e*/
    v27 = v9 % v25; /*0x143f41*/
    v28 = v9 / v25; /*0x143f44*/
    v11 = a2[5]; /*0x143f4f*/
    if ( v25 - v9 % v25 < v11 ) /*0x143f54*/
      v11 = v25 - v10; /*0x143f56*/
    if ( !a3 ) /*0x143f5c*/
    {
      if ( (int)(*(_DWORD *)(a1 + 108) - v9) <= 0 ) /*0x143f65*/
        return 0; /*0x143eef*/
      if ( (int)(*(_DWORD *)(a1 + 108) - v9) < v11 ) /*0x143f69*/
        v11 = *(_DWORD *)(a1 + 108) - v9; /*0x143f6b*/
    }
    v12 = nullptr; /*0x143f6d*/
    if ( (a4 & 4) != 0 ) /*0x143f73*/
      v12 = &v31; /*0x143f75*/
    v13 = bmap(a1, v28, a3 != 1, v11 + v10, v12) << v29[25]; /*0x143f9c*/
    if ( *(_BYTE *)(dword_1E875C + 104) == 28 /*0x143fcb*/
      && a3 == 1
      && v23 - a2[5] > 0
      && (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 )
    {
      break; /*0x143fcb*/
    }
    v14 = *(_BYTE *)(dword_1E875C + 104); /*0x143fd6*/
    if ( v14 ) /*0x143fdb*/
      return v14; /*0x143fdb*/
    if ( a3 == 1 ) /*0x143fe1*/
    {
      if ( v13 < 0 ) /*0x143fe5*/
        return v14; /*0x143fed*/
      if ( *(_DWORD *)(a1 + 108) < (unsigned int)(v11 + a2[2]) && (v26 == 0x4000 || v26 == 0x8000 || v26 == 40960) ) /*0x14401a*/
      {
        v15 = v11 + a2[2]; /*0x144022*/
        *(_DWORD *)(a1 + 108) = v15; /*0x144024*/
        v16 = *(_DWORD *)(a1 + 12); /*0x144027*/
        if ( *(_DWORD *)(v16 + 20) < v15 ) /*0x144030*/
          *(_DWORD *)(v16 + 20) = v15; /*0x144032*/
        if ( (a4 & 4) != 0 ) /*0x144039*/
          v31 = 1; /*0x14403b*/
      }
    }
    if ( v28 <= 11 && (v17 = *(_DWORD *)(a1 + 108), v17 < (v28 + 1) << v29[20]) ) /*0x144059*/
      v18 = v29[19] & (v29[13] + (~v29[18] & v17) - 1); /*0x144079*/
    else
      v18 = v29[12]; /*0x14405e*/
    if ( a3 ) /*0x144080*/
    {
      if ( v25 == v11 ) /*0x1440e7*/
        v20 = (int *)getblk(v30, v13, v18); /*0x1440ef*/
      else
        v20 = bread(v30, v13, v18); /*0x1440fe*/
      v19 = v20; /*0x144103*/
    }
    else
    {
      if ( v13 >= 0 ) /*0x144084*/
      {
        if ( v28 == *(_DWORD *)(a1 + 88) + 1 ) /*0x1440ab*/
          v19 = breada(v30, v13, v18, rablock, rasize); /*0x1440c5*/
        else
          v19 = bread(v30, v13, v18); /*0x1440d7*/
      }
      else
      {
        v19 = (int *)geteblk(v18); /*0x14408c*/
        blkclr((void *)v19[8], v19[5]); /*0x144096*/
        v19[10] = 0; /*0x14409b*/
      }
      *(_DWORD *)(a1 + 88) = v28; /*0x1440df*/
    }
    v21 = v19[5]; /*0x144108*/
    if ( v11 > v21 - v19[10] ) /*0x144115*/
      v11 = v21 - v19[10]; /*0x144117*/
    if ( (*(_BYTE *)v19 & 4) != 0 ) /*0x14411c*/
    {
      v24 = 5; /*0x143f00*/
      brelse((int)v19); /*0x143f08*/
      return v24; /*0x143f0d*/
    }
    if ( (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 ) /*0x14412e*/
      byte_swap_dir_block_in(v19[8], v21); /*0x144138*/
    *(_BYTE *)(dword_1E875C + 104) = uiomove(v19[8] + v27, v11, a3, a2); /*0x14415c*/
    if ( (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 ) /*0x144170*/
      byte_swap_dir_block_out(v19); /*0x144173*/
    if ( (a4 & 4) != 0 ) /*0x14417f*/
    {
      v22 = *(_WORD *)(a1 + 100); /*0x144181*/
      if ( (v22 & 0x200) != 0 && stickyhack && (v22 & 0x49) == 0 ) /*0x144196*/
        *v19 |= 0x400000u; /*0x144198*/
    }
    if ( a3 ) /*0x1441a2*/
    {
      if ( (a4 & 4) != 0 || (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 ) /*0x1441da*/
      {
        bwrite(v19); /*0x1441dd*/
      }
      else if ( v25 == v11 + v27 ) /*0x1441ec*/
      {
        *(_BYTE *)v19 |= 0x80u; /*0x1441ee*/
        bawrite((unsigned int *)v19); /*0x1441f2*/
      }
      else
      {
        bdwrite((int)v19); /*0x1441fd*/
      }
      *(_BYTE *)(a1 + 68) |= 0x42u; /*0x144205*/
      if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 6) ) /*0x144211*/
        *(_WORD *)(a1 + 100) &= 0xF3FFu; /*0x144218*/
    }
    else
    {
      if ( v25 == v11 + v27 || a2[2] == *(_DWORD *)(a1 + 108) ) /*0x1441b7*/
        *(_BYTE *)v19 |= 0x80u; /*0x1441b9*/
      brelse((int)v19); /*0x1441bd*/
    }
    if ( *(_BYTE *)(dword_1E875C + 104) || (int)a2[5] <= 0 || !v11 ) /*0x144234*/
      goto LABEL_88; /*0x144234*/
  }
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x143ef4*/
LABEL_88:
  if ( v31 ) /*0x14423e*/
    iupdat(a1, 1); /*0x144243*/
  return *(char *)(dword_1E875C + 104); /*0x144260*/
}
