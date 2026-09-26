/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17cd58. */
int __cdecl sub_17CD58(int *a1, unsigned int a2, int a3, unsigned __int8 *a4)
{
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v11; // edx
  int v12; // ebx
  unsigned int v13; // edx
  int *v14; // eax
  int *v15; // ebx
  int *v16; // eax
  int *v17; // eax
  int v18; // eax
  int k; // ecx
  int v20; // eax
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // ecx
  int v24; // esi
  _DWORD *v25; // [esp+10h] [ebp-14h]
  size_t v26; // [esp+10h] [ebp-14h]
  size_t v27; // [esp+10h] [ebp-14h]
  unsigned int v28; // [esp+14h] [ebp-10h]
  int m; // [esp+14h] [ebp-10h]
  unsigned int n; // [esp+14h] [ebp-10h]
  int j; // [esp+14h] [ebp-10h]
  unsigned int i; // [esp+14h] [ebp-10h]
  int v33; // [esp+18h] [ebp-Ch]
  unsigned int v34; // [esp+20h] [ebp-4h]

  v34 = a2 >> page_shift; /*0x17cd70*/
  v4 = a1[4]; /*0x17cd73*/
  if ( a2 >> page_shift >= v4 ) /*0x17cd78*/
    goto LABEL_7; /*0x17cd78*/
  if ( 4 * v4 <= 0x40 ) /*0x17cd80*/
  {
    v7 = a1[2]; /*0x17cda8*/
    if ( *(_BYTE *)(v7 + 4 * v34) ) /*0x17cdae*/
    {
      *(_DWORD *)a4 = *(_DWORD *)(v7 + 4 * v34); /*0x17cdc1*/
      goto LABEL_9; /*0x17cdc1*/
    }
LABEL_7:
    v8 = 0; /*0x17cdb4*/
    goto LABEL_10; /*0x17cdb6*/
  }
  v5 = (a2 >> page_shift) & 0xF; /*0x17cd8b*/
  v6 = *(_DWORD *)(a1[2] + 4 * (v34 >> 4)); /*0x17cd91*/
  if ( !v6 || !*(_BYTE *)(v6 + 4 * v5) ) /*0x17cd98*/
    goto LABEL_7; /*0x17cd9c*/
  *(_DWORD *)a4 = *(_DWORD *)(v6 + 4 * v5); /*0x17cda4*/
LABEL_9:
  v8 = 1; /*0x17cdc3*/
LABEL_10:
  if ( a3 != 1 ) /*0x17cdcc*/
  {
    if ( v8 ) /*0x17cde2*/
    {
      v11 = *(_DWORD *)a4; /*0x17cdf5*/
      v12 = *(_DWORD *)a4 >> 8; /*0x17cdf9*/
      if ( *(_DWORD *)(dword_1E7294[*a4] + 36) >= v12 ) /*0x17cdff*/
        return 0; /*0x17ce96*/
      if ( (_BYTE)v11 ) /*0x17ce07*/
      {
        v25 = (_DWORD *)dword_1E7294[(unsigned __int8)v11]; /*0x17ce17*/
        lock_write((int)(v25 + 13)); /*0x17ce23*/
        if ( v25[5] <= v12 ) /*0x17ce31*/
          panic(aVnodePagerDeal); /*0x17ce38*/
        if ( v25[9] > v12 ) /*0x17ce46*/
          v25[9] = v12; /*0x17ce48*/
        *(_BYTE *)(v12 / 8 + v25[4]) &= __ROL4__(-2, v12 % 8); /*0x17ce7b*/
        ++v25[6]; /*0x17ce81*/
        lock_done((int)(v25 + 13)); /*0x17ce88*/
      }
    }
    v13 = a1[4]; /*0x17cea0*/
    if ( v34 + 1 <= v13 ) /*0x17cea5*/
    {
LABEL_52:
      if ( (unsigned int)(4 * a1[4]) <= 0x40 ) /*0x17d0bb*/
      {
        if ( vnode_pager_findpage(a1[1], a4) != 5 ) /*0x17d140*/
        {
          v22 = a1[2]; /*0x17d14c*/
          v23 = *(_DWORD *)a4; /*0x17d152*/
          v24 = v34; /*0x17d154*/
          goto LABEL_62; /*0x17d154*/
        }
      }
      else
      {
        v21 = v34 >> 4; /*0x17d0c0*/
        if ( !*(_DWORD *)(a1[2] + 4 * (v34 >> 4)) ) /*0x17d0cf*/
        {
          *(_DWORD *)(a1[2] + 4 * v21) = kalloc_noblock(0x40u); /*0x17d0e1*/
          if ( !*(_DWORD *)(a1[2] + 4 * v21) ) /*0x17d0ee*/
            return 5; /*0x17d0ee*/
          for ( i = 0; i <= 0xF; ++i ) /*0x17d0f0*/
            *(_BYTE *)(*(_DWORD *)(a1[2] + 4 * v21) + 4 * i) = 0; /*0x17d101*/
        }
        if ( vnode_pager_findpage(a1[1], a4) != 5 ) /*0x17d11e*/
        {
          v22 = *(_DWORD *)(a1[2] + 4 * v21); /*0x17d123*/
          v23 = *(_DWORD *)a4; /*0x17d129*/
          v24 = v34 & 0xF; /*0x17d12b*/
LABEL_62:
          *(_DWORD *)(v22 + 4 * v24) = v23; /*0x17d157*/
          return 0; /*0x17d15a*/
        }
      }
      return 5; /*0x17d147*/
    }
    v33 = v34 + 1; /*0x17ceab*/
    if ( 4 * (v34 + 1) <= 0x40 ) /*0x17ceb4*/
    {
      v15 = (int *)kalloc_noblock(4 * (v34 + 1)); /*0x17d042*/
      if ( !v15 ) /*0x17d049*/
        return 5; /*0x17d049*/
      for ( j = 0; a1[4] > j; ++j ) /*0x17d05c*/
        v15[j] = *(_DWORD *)(a1[2] + 4 * j); /*0x17d069*/
      for ( k = a1[4]; k < v33; ++k ) /*0x17d075*/
        LOBYTE(v15[k]) = 0; /*0x17d07f*/
      v20 = a1[4]; /*0x17d08e*/
      if ( v20 > 0 ) /*0x17d093*/
        kfree(a1[2], 4 * v20); /*0x17d09d*/
    }
    else if ( v13 ) /*0x17cebc*/
    {
      if ( 4 * v13 <= 0x40 ) /*0x17cefa*/
      {
        v27 = 4 * (v34 >> 4) + 4; /*0x17cf9d*/
        v17 = (int *)kalloc_noblock(v27); /*0x17cfa1*/
        v15 = v17; /*0x17cfa6*/
        if ( !v17 ) /*0x17cfad*/
          return 5; /*0x17cfad*/
        bzero(v17, v27); /*0x17cfb8*/
        v18 = kalloc_noblock(0x40u); /*0x17cfbf*/
        *v15 = v18; /*0x17cfc4*/
        if ( !v18 ) /*0x17cfcb*/
        {
          kfree((int)v15, v27); /*0x17cfd2*/
          return 5; /*0x17cfdc*/
        }
        for ( m = 0; a1[4] > m; ++m ) /*0x17cff1*/
          *(_DWORD *)(*v15 + 4 * m) = *(_DWORD *)(a1[2] + 4 * m); /*0x17cfff*/
        for ( n = a1[4]; n <= 0xF; ++n ) /*0x17d014*/
          *(_BYTE *)(*v15 + 4 * n) = 0; /*0x17d01d*/
        kfree(a1[2], 4 * a1[4]); /*0x17d039*/
      }
      else
      {
        v26 = 4 * (v34 >> 4) + 4; /*0x17cf0d*/
        if ( v26 == 4 * ((v13 - 1) >> 4) + 4 ) /*0x17cf20*/
        {
LABEL_51:
          a1[4] = v33; /*0x17d0a8*/
          goto LABEL_52; /*0x17d0ab*/
        }
        v16 = (int *)kalloc_noblock(v26); /*0x17cf2a*/
        v15 = v16; /*0x17cf2f*/
        if ( !v16 ) /*0x17cf36*/
          return 5; /*0x17cf36*/
        bzero(v16, v26); /*0x17cf41*/
        v28 = 0; /*0x17cf50*/
        if ( (unsigned int)(a1[4] - 1) >> 4 != -1 ) /*0x17cf5a*/
        {
          do /*0x17cf76*/
          {
            v15[v28] = *(_DWORD *)(a1[2] + 4 * v28); /*0x17cf65*/
            ++v28; /*0x17cf69*/
          }
          while ( v28 < ((unsigned int)(a1[4] - 1) >> 4) + 1 ); /*0x17cf76*/
        }
        kfree(a1[2], 4 * ((unsigned int)(a1[4] - 1) >> 4) + 4); /*0x17cf8b*/
      }
    }
    else
    {
      v14 = (int *)kalloc_noblock(4 * (v34 >> 4) + 4); /*0x17cecf*/
      v15 = v14; /*0x17ced4*/
      if ( !v14 ) /*0x17cedb*/
        return 5; /*0x17cedb*/
      bzero(v14, 4 * (v34 >> 4) + 4); /*0x17cee6*/
    }
    a1[2] = (int)v15; /*0x17d0a5*/
    goto LABEL_51; /*0x17d0a5*/
  }
  v9 = 0; /*0x17cdce*/
  if ( !v8 ) /*0x17cdd2*/
    return 5; /*0x17cdd4*/
  return v9; /*0x17d15f*/
}
