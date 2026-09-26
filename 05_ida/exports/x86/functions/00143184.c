/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x143184. */
int __cdecl sub_143184(int *a1, int a2, int a3)
{
  int v3; // ecx
  unsigned int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  _DWORD *v8; // ebx
  int v9; // ecx
  int v10; // ebx
  int v11; // ecx
  unsigned int v12; // edi
  int v13; // esi
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ebx
  int v18; // [esp+0h] [ebp-90h]
  unsigned int v19; // [esp+Ch] [ebp-84h]
  int v20; // [esp+30h] [ebp-60h]
  char *v21; // [esp+34h] [ebp-5Ch]
  int v22; // [esp+38h] [ebp-58h]
  int v23; // [esp+3Ch] [ebp-54h]
  int *v24; // [esp+40h] [ebp-50h]
  int v25; // [esp+44h] [ebp-4Ch]
  _DWORD *v26; // [esp+48h] [ebp-48h]
  _DWORD v27[17]; // [esp+4Ch] [ebp-44h] BYREF

  v26 = nullptr; /*0x143190*/
  v25 = 0; /*0x143197*/
  if ( !dword_1DE3F0 ) /*0x1431a5*/
  {
    ihinit(); /*0x1431a7*/
    dword_1DE3F0 = 1; /*0x1431ac*/
  }
  v3 = 3; /*0x1431c8*/
  if ( (*(_BYTE *)(a3 + 12) & 1) != 0 ) /*0x1431d4*/
    v3 = 1; /*0x1431d6*/
  v23 = (**(int (__cdecl ***)(int *, int, _DWORD))(*a1 + 28))(a1, v3, *(_DWORD *)(active_u + 28)); /*0x1431e7*/
  if ( v23 ) /*0x1431ef*/
    return v23; /*0x1431f4*/
  v20 = 1; /*0x1431fc*/
  v5 = (*(int (__cdecl **)(int))(*(_DWORD *)(*a1 + 28) + 128))(*a1); /*0x143214*/
  if ( !v5 ) /*0x14321b*/
  {
    v6 = 3; /*0x143231*/
    if ( (*(_BYTE *)(a3 + 12) & 1) != 0 ) /*0x14323d*/
      v6 = 1; /*0x14323f*/
    (*(void (__stdcall **)(int, int, int, _DWORD, int))(*(_DWORD *)(*a1 + 28) + 4))( /*0x14324c*/
      *a1,
      v6,
      1,
      *(_DWORD *)(active_u + 28),
      v18);
    binval(*a1); /*0x143254*/
    return 15; /*0x14325e*/
  }
  v24 = bread(*a1, 0x2000 / v5, 0x2000); /*0x143282*/
  if ( (*(_BYTE *)v24 & 4) != 0 ) /*0x14328b*/
    goto LABEL_65; /*0x14328b*/
  v26 = (_DWORD *)mounttab; /*0x143296*/
  if ( !mounttab )
  {
LABEL_18:
    vol_notify_cancel(*(_WORD *)(*a1 + 44)); /*0x1432ed*/
    v7 = *(_DWORD *)(a3 + 12); /*0x1432ff*/
    if ( (v7 & 0x40) != 0 )
    {
      LOBYTE(v7) = v7 & 0xBF; /*0x14330a*/
      *(_DWORD *)(a3 + 12) = v7; /*0x14330d*/
      printf("mountfs: illegal remount request\n");
LABEL_42:
      v23 = 22; /*0x1434a3*/
LABEL_65:
      if ( !v23 ) /*0x14370b*/
        v23 = 5; /*0x14370d*/
      goto LABEL_67; /*0x14370d*/
    }
    v26 = (_DWORD *)mounttab; /*0x143321*/
    if ( mounttab ) /*0x143326*/
    {
      while ( v26[3] ) /*0x14332f*/
      {
        v26 = (_DWORD *)v26[8]; /*0x143334*/
        if ( !v26 ) /*0x143339*/
          goto LABEL_23; /*0x143339*/
      }
    }
    else
    {
LABEL_23:
      v26 = (_DWORD *)kalloc(0x24u); /*0x14333b*/
      bzero(v26, 0x24u); /*0x14334b*/
      if ( !v26 ) /*0x143357*/
      {
        v23 = 24; /*0x143359*/
        goto LABEL_67; /*0x143360*/
      }
      v26[8] = mounttab; /*0x143371*/
      mounttab = (int)v26; /*0x143374*/
    }
    *(_DWORD *)(a3 + 296) = v26; /*0x143380*/
    *v26 = a3; /*0x143386*/
    v26[3] = v24; /*0x14338b*/
    *((_WORD *)v26 + 2) = -1; /*0x14338e*/
    v26[2] = *a1; /*0x143399*/
    v8 = (_DWORD *)v24[8]; /*0x14339c*/
    byte_swap_superblock(v8); /*0x1433a0*/
    if ( v8[343] == 72020 ) /*0x1433b2*/
    {
      v9 = v8[12]; /*0x1433b4*/
      if ( v9 <= 0x2000 && (unsigned int)v9 > 0x563 ) /*0x1433c5*/
      {
        v25 = geteblk(v8[26]); /*0x1433f1*/
        v26[3] = v25; /*0x1433f7*/
        bcopy((const void *)v24[8], *(void **)(v25 + 32), v8[26]); /*0x14340c*/
        goto LABEL_32; /*0x14340c*/
      }
    }
    v23 = 22; /*0x1433c7*/
LABEL_67:
    if ( v26 ) /*0x143718*/
      v26[3] = 0; /*0x14371d*/
    if ( v25 ) /*0x143728*/
      brelse(v25); /*0x14372e*/
    if ( v24 ) /*0x14373a*/
      brelse((int)v24); /*0x143740*/
    if ( v20 ) /*0x14374c*/
    {
      v17 = 3; /*0x143762*/
      if ( (*(_BYTE *)(a3 + 12) & 1) != 0 ) /*0x14376e*/
        v17 = 1; /*0x143770*/
      (*(void (__stdcall **)(int, int, int, _DWORD, int))(*(_DWORD *)(*a1 + 28) + 4))( /*0x14377d*/
        *a1,
        v17,
        1,
        *(_DWORD *)(active_u + 28),
        v18);
      binval(*a1); /*0x143785*/
    }
    return v23; /*0x14378a*/
  }
  while ( !v26[3] || *(_WORD *)(*a1 + 44) != *((_WORD *)v26 + 2) ) /*0x1432b7*/
  {
    v26 = (_DWORD *)v26[8]; /*0x1432e6*/
    if ( !v26 ) /*0x1432eb*/
      goto LABEL_18; /*0x1432eb*/
  }
  if ( (*(_BYTE *)(a3 + 12) & 0x40) == 0 ) /*0x1432c0*/
  {
    v26 = nullptr; /*0x1432c6*/
    v23 = 16; /*0x1432cd*/
    v20 = 0; /*0x1432d4*/
    goto LABEL_65; /*0x1432db*/
  }
  v25 = v26[3]; /*0x1433d4*/
  v8 = (_DWORD *)v24[8]; /*0x1433da*/
  byte_swap_superblock(v8); /*0x1433de*/
LABEL_32:
  if ( (*(_BYTE *)(a3 + 12) & 1) != 0 ) /*0x14341b*/
  {
    brelse((int)v24); /*0x143474*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 0; /*0x143422*/
    byte_swap_superblock(v8); /*0x143427*/
    bwrite(v24); /*0x143430*/
    if ( *(_BYTE *)(dword_1E875C + 104) == 30 ) /*0x143442*/
    {
      *(_BYTE *)(dword_1E875C + 104) = 0; /*0x143444*/
      if ( *a1 == rootvp ) /*0x143452*/
        panic(aRootDeviceIsPh); /*0x143459*/
      *(_BYTE *)(a3 + 12) |= 1u; /*0x143464*/
    }
    byte_swap_superblock(v8); /*0x143469*/
  }
  v24 = nullptr; /*0x14347c*/
  v10 = *(_DWORD *)(v25 + 32); /*0x143486*/
  v11 = *(_DWORD *)(a3 + 12); /*0x14348c*/
  if ( (v11 & 1) != 0 )
  {
    if ( (v11 & 0x40) != 0 )
    {
      printf("mountfs: can't remount ro\n");
      goto LABEL_42; /*0x14349e*/
    }
    *(_BYTE *)(v10 + 208) = 0; /*0x1434b4*/
    *(_BYTE *)(v10 + 210) = 1; /*0x1434bb*/
  }
  else
  {
    if ( *(_BYTE *)(v10 + 209) == 1 ) /*0x1434cb*/
      *(_BYTE *)(v10 + 209) = 2; /*0x1434cd*/
    else
      *(_BYTE *)(v10 + 209) = 3; /*0x1434d8*/
    *(_BYTE *)(v10 + 208) = 1; /*0x1434df*/
    *(_BYTE *)(v10 + 210) = 0; /*0x1434e6*/
    if ( (*(_BYTE *)(a3 + 12) & 0x40) != 0 ) /*0x1434f4*/
    {
      *(_DWORD *)(a3 + 12) &= ~0x40u; /*0x14350b*/
      sbupdate(v26); /*0x143513*/
      return 0; /*0x14351a*/
    }
  }
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v10 + 48); /*0x143526*/
  v12 = *(_DWORD *)(v10 + 156); /*0x143529*/
  v22 = (int)(*(_DWORD *)(v10 + 52) + v12 - 1) / *(_DWORD *)(v10 + 52); /*0x14353c*/
  v21 = (char *)kalloc(v12); /*0x143545*/
  if ( !v21 ) /*0x14354d*/
  {
    v23 = 12; /*0x14354f*/
    goto LABEL_67; /*0x143556*/
  }
  v13 = 0; /*0x14355c*/
  if ( v22 > 0 ) /*0x143561*/
  {
    while ( 1 ) /*0x14356b*/
    {
      v19 = *(_DWORD *)(v10 + 48); /*0x14356b*/
      if ( *(_DWORD *)(v10 + 56) + v13 > v22 ) /*0x14357b*/
        v19 = *(_DWORD *)(v10 + 52) * (v22 - v13); /*0x143585*/
      v24 = bread(v26[2], (v13 + *(_DWORD *)(v10 + 152)) << *(_DWORD *)(v10 + 100), v19); /*0x1435ac*/
      if ( (*(_BYTE *)v24 & 4) != 0 ) /*0x1435b5*/
        break; /*0x1435b5*/
      bcopy((const void *)v24[8], v21, v19); /*0x1435c7*/
      byte_swap_ints(v21, v19 >> 2); /*0x1435d7*/
      *(_DWORD *)(v10 + 4 * (v13 >> *(_DWORD *)(v10 + 96)) + 728) = v21; /*0x1435e6*/
      v21 += v19; /*0x1435f5*/
      brelse((int)v24); /*0x1435fc*/
      v13 += *(_DWORD *)(v10 + 56); /*0x143604*/
      if ( v22 <= v13 ) /*0x14360a*/
        goto LABEL_56; /*0x14360a*/
    }
    kfree((int)v21, *(_DWORD *)(v10 + 156)); /*0x1436ff*/
    goto LABEL_65; /*0x1436ff*/
  }
LABEL_56:
  if ( !*(_BYTE *)(v10 + 210) ) /*0x143610*/
    sbupdate(v26); /*0x14361d*/
  *(_BYTE *)(v10 + 211) &= 0xFCu; /*0x143625*/
  v14 = *(_DWORD *)(v10 + 60) * *(_DWORD *)(v10 + 40) / 100; /*0x14363d*/
  *(_DWORD *)(v10 + 140) = v14; /*0x14363f*/
  *(_DWORD *)(v10 + 136) = v14; /*0x143645*/
  if ( v14 <= 100 ) /*0x14364e*/
    v15 = 2 * v14; /*0x143658*/
  else
    v15 = v14 + 100; /*0x143650*/
  *(_DWORD *)(v10 + 136) = v15; /*0x14365a*/
  v16 = *(_DWORD *)(v10 + 184) * *(_DWORD *)(v10 + 44) / 100; /*0x143674*/
  *(_DWORD *)(v10 + 148) = v16; /*0x143676*/
  if ( v16 > 50 ) /*0x14367f*/
    *(_DWORD *)(v10 + 148) = 50; /*0x143681*/
  *(_DWORD *)(v10 + 144) = *(_DWORD *)(v10 + 148); /*0x143691*/
  *((_WORD *)v26 + 2) = *(_WORD *)(v26[2] + 44); /*0x1436a4*/
  *(_DWORD *)(a3 + 20) = *((__int16 *)v26 + 2); /*0x1436af*/
  *(_DWORD *)(a3 + 24) = 0; /*0x1436b2*/
  copystr(a2, v10 + 212, 511, v27); /*0x1436cd*/
  bzero((void *)(v10 + v27[0] + 212), 512 - v27[0]); /*0x1436e8*/
  return 0; /*0x143793*/
}
