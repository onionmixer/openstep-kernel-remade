/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13baa0. */
unsigned int *__cdecl realloccg(int a1, int a2, int a3, size_t a4, int a5)
{
  int v5; // esi
  int v6; // ebx
  unsigned int v7; // edx
  int v8; // ecx
  unsigned int *v9; // eax
  unsigned int *v10; // esi
  int v12; // ecx
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  long double v16; // [esp-Ch] [ebp-30h]
  int v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+Ch] [ebp-18h]
  int v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  v5 = a3; /*0x13baa9*/
  v6 = *(_DWORD *)(a1 + 80); /*0x13baaf*/
  v7 = *(_DWORD *)(v6 + 48); /*0x13bab2*/
  if ( a4 > v7 || (v8 = ~*(_DWORD *)(v6 + 76), (v8 & a4) != 0) || a5 > v7 || (v8 & a5) != 0 ) /*0x13bacf*/
  {
    printf( /*0x13baf1*/
      "dev = 0x%x, bsize = %d, osize = %d, nsize = %d, fs = %s\n",
      *(__int16 *)(a1 + 70),
      *(_DWORD *)(v6 + 48),
      a4,
      a5,
      (const char *)(v6 + 212));
    panic(aRealloccgBadSi); /*0x13bafb*/
  }
  if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) /*0x13bb3e*/
    && *(_DWORD *)(v6 + 204)
     + (*(_DWORD *)(v6 + 196) << *(_DWORD *)(v6 + 96))
     - *(_DWORD *)(v6 + 60) * *(_DWORD *)(v6 + 40) / 100 <= 0 )
  {
    goto LABEL_33; /*0x13bb3e*/
  }
  if ( !a2 ) /*0x13bb48*/
  {
    printf( /*0x13bb64*/
      "dev = 0x%x, bsize = %d, bprev = %d, fs = %s\n",
      *(__int16 *)(a1 + 70),
      *(_DWORD *)(v6 + 48),
      0,
      (const char *)(v6 + 212));
    panic(aRealloccgBadBp); /*0x13bb6e*/
  }
  v17 = a2 / *(_DWORD *)(v6 + 188); /*0x13bb80*/
  v19 = fragextend(a1, v17, a2, a4, a5); /*0x13bb9c*/
  if ( v19 ) /*0x13bba4*/
  {
    while ( 1 ) /*0x13bbc0*/
    {
      v9 = (unsigned int *)bread(*(_DWORD *)(a1 + 64), v19 << *(_DWORD *)(v6 + 100), a4); /*0x13bbc0*/
      v10 = v9; /*0x13bbc5*/
      if ( (*(_BYTE *)v9 & 4) != 0 ) /*0x13bbcd*/
        break; /*0x13bbcd*/
      if ( brealloc(v9, a5) ) /*0x13bbd8*/
      {
        *(_BYTE *)v10 |= 2u; /*0x13bbe6*/
        bzero((void *)(v10[8] + a4), a5 - a4); /*0x13bbf7*/
        *(_DWORD *)(a1 + 204) += (int)(a5 - a4) / (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 40) + 128))(a1 + 12); /*0x13bc1d*/
        *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13bc23*/
        return v10; /*0x13bc29*/
      }
    }
    goto LABEL_26; /*0x13bbcd*/
  }
  if ( *(_DWORD *)(v6 + 36) <= a3 ) /*0x13bc33*/
    v5 = 0; /*0x13bc35*/
  v12 = *(_DWORD *)(v6 + 128); /*0x13bc37*/
  if ( v12 ) /*0x13bc3f*/
  {
    if ( v12 == 1 ) /*0x13bc44*/
    {
      v21 = a5; /*0x13bc4d*/
      v13 = *(_DWORD *)(v6 + 60); /*0x13bc50*/
      if ( v13 > 4 && *(_DWORD *)(v6 + 204) <= *(_DWORD *)(v6 + 40) * v13 / 200 ) /*0x13bc72*/
      {
        DWORD2(v16) = v6 + 212; /*0x13bc7a*/
        DWORD1(v16) = aSOptimizationC; /*0x13bc7b*/
        LODWORD(v16) = 5; /*0x13bc80*/
        log(v16); /*0x13bc82*/
        *(_DWORD *)(v6 + 128) = 0; /*0x13bc87*/
      }
    }
    else
    {
      *(_DWORD *)(v6 + 128) = 1; /*0x13bce0*/
      v21 = a5; /*0x13bced*/
    }
  }
  else
  {
    v21 = *(_DWORD *)(v6 + 48); /*0x13bc9b*/
    if ( *(_DWORD *)(v6 + 204) >= *(_DWORD *)(v6 + 40) * (*(_DWORD *)(v6 + 60) - 2) / 100 ) /*0x13bcbc*/
    {
      DWORD2(v16) = v6 + 212; /*0x13bcc4*/
      DWORD1(v16) = aSOptimizationC_0; /*0x13bcc5*/
      LODWORD(v16) = 5; /*0x13bcca*/
      log(v16); /*0x13bccc*/
      *(_DWORD *)(v6 + 128) = 1; /*0x13bcd1*/
    }
  }
  v20 = hashalloc(a1, v17, v5, v21, alloccg); /*0x13bd07*/
  if ( v20 <= 0 )
  {
LABEL_33:
    if ( (*(_BYTE *)(v6 + 211) & 1) == 0 ) /*0x13be27*/
      fserr(v6, aFileSystemFull); /*0x13be2f*/
    *(_BYTE *)(v6 + 211) |= 1u; /*0x13be37*/
    if ( (*(_BYTE *)(active_u + 608) & 8) == 0 )
      uprintf("\n%s: %s\n", (const char *)(v6 + 212), aWriteFailedFil);
    if ( !*(_DWORD *)(dword_1E875C + 108) ) /*0x13be68*/
    {
      *(_DWORD *)(dword_1E875C + 108) = v6; /*0x13be6e*/
      *(_BYTE *)(dword_1E875C + 112) = 1; /*0x13be76*/
    }
    *(_BYTE *)(dword_1E875C + 104) = 28; /*0x13be7f*/
    return nullptr; /*0x13be7f*/
  }
  v9 = (unsigned int *)bread(*(_DWORD *)(a1 + 64), a2 << *(_DWORD *)(v6 + 100), a4); /*0x13bd29*/
  v18 = (int)v9; /*0x13bd2e*/
  if ( (*(_BYTE *)v9 & 4) != 0 ) /*0x13bd37*/
  {
LABEL_26:
    brelse((int)v9); /*0x13bd39*/
    return nullptr; /*0x13be83*/
  }
  v14 = getblk(*(_DWORD *)(a1 + 64), v20 << *(_DWORD *)(v6 + 100), a5); /*0x13bd5d*/
  bcopy(*(const void **)(v18 + 32), *(void **)(v14 + 32), a4); /*0x13bd6e*/
  bzero((void *)(*(_DWORD *)(v14 + 32) + a4), a5 - a4); /*0x13bd84*/
  v15 = *(_DWORD *)v18; /*0x13bd8c*/
  if ( (*(_DWORD *)v18 & 0x200) != 0 ) /*0x13bd94*/
  {
    BYTE1(v15) &= ~2u; /*0x13bd96*/
    *(_DWORD *)v18 = v15; /*0x13bd99*/
    --*(_DWORD *)(active_u + 416); /*0x13bda1*/
  }
  brelse(v18); /*0x13bdab*/
  free_block(a1, a2, a4); /*0x13bdbc*/
  if ( a5 < v21 ) /*0x13bdca*/
    free_block(a1, v20 + (a5 >> *(_DWORD *)(v6 + 84)), v21 - a5); /*0x13bddd*/
  *(_DWORD *)(a1 + 204) += (int)(a5 - a4) / (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 40) + 128))(a1 + 12); /*0x13be07*/
  *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13be0d*/
  return (unsigned int *)v14; /*0x13be88*/
}
