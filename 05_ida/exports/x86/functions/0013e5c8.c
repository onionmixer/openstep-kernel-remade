/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13e5c8. */
int __cdecl sub_13E5C8(int a1, _BYTE *a2, size_t a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // edi
  size_t v6; // eax
  unsigned int v7; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // [esp+10h] [ebp-14h]
  unsigned int v16; // [esp+14h] [ebp-10h]
  int v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  unsigned int v19; // [esp+20h] [ebp-4h]

  v17 = 0; /*0x13e5d1*/
  v18 = 0; /*0x13e5d8*/
  v5 = 0; /*0x13e5df*/
  v6 = a3 + 4; /*0x13e5e4*/
  LOBYTE(v6) = (a3 + 4) & 0xFC; /*0x13e5e7*/
  v15 = v6 + 8; /*0x13e5ec*/
  v19 = (*(_DWORD *)(a1 + 108) + 1023) & 0xFFFFFC00; /*0x13e5ff*/
  v16 = 0; /*0x13e602*/
  v7 = 0; /*0x13e609*/
  if ( !v19 ) /*0x13e60e*/
  {
LABEL_36:
    if ( v18 ) /*0x13e7f8*/
    {
      byte_swap_dir_block_out(v18); /*0x13e7fe*/
      brelse(v18); /*0x13e807*/
    }
    if ( !*a4 ) /*0x13e80f*/
    {
      a4[1] = v19; /*0x13e817*/
      a4[2] = 1024; /*0x13e81a*/
    }
    *a5 = 0; /*0x13e824*/
    return 0; /*0x13e82a*/
  }
  while ( 1 ) /*0x13e614*/
  {
    if ( (v7 & ~*(_DWORD *)(*(_DWORD *)(a1 + 80) + 72)) == 0 ) /*0x13e621*/
    {
      if ( v18 ) /*0x13e627*/
      {
        byte_swap_dir_block_out(v18); /*0x13e62d*/
        brelse(v18); /*0x13e636*/
      }
      v18 = blkatoff(a1, v7, 0); /*0x13e64a*/
      if ( !v18 ) /*0x13e652*/
        return *(char *)(dword_1E875C + 104); /*0x13e65d*/
      v5 = 0; /*0x13e664*/
    }
    if ( !*a4 && (v5 & 0x3FF) == 0 ) /*0x13e674*/
    {
      a4[1] = -1; /*0x13e676*/
      v17 = 0; /*0x13e67d*/
    }
    v9 = v5 + *(_DWORD *)(v18 + 32); /*0x13e68a*/
    if ( *(_WORD *)(v9 + 4) ) /*0x13e68c*/
    {
      if ( !sub_13F52C(a1, v9, v5, v7) ) /*0x13e69a*/
        break; /*0x13e69a*/
    }
    v10 = 1024 - (v5 & 0x3FF); /*0x13e6b4*/
LABEL_35:
    v7 += v10; /*0x13e7e7*/
    v5 += v10; /*0x13e7e9*/
    if ( v19 <= v7 ) /*0x13e7ee*/
      goto LABEL_36; /*0x13e7ee*/
  }
  if ( *a4 != 2 ) /*0x13e6c7*/
  {
    v11 = *(unsigned __int16 *)(v9 + 4); /*0x13e6c9*/
    if ( *(_DWORD *)v9 ) /*0x13e6cd*/
    {
      v12 = v11 - 8; /*0x13e6d2*/
      v13 = *(unsigned __int16 *)(v9 + 6) + 4; /*0x13e6d9*/
      LOBYTE(v13) = v13 & 0xFC; /*0x13e6dc*/
      v11 = v12 - v13; /*0x13e6e0*/
    }
    if ( v11 > 0 ) /*0x13e6e4*/
    {
      if ( v15 > v11 ) /*0x13e6e9*/
      {
        if ( !*a4 ) /*0x13e6c1*/
        {
          v17 += v11; /*0x13e706*/
          if ( a4[1] == -1 ) /*0x13e710*/
            a4[1] = v7; /*0x13e712*/
          if ( v17 >= v15 ) /*0x13e71b*/
          {
            *a4 = 1; /*0x13e720*/
            a4[2] = v7 + *(unsigned __int16 *)(v9 + 4) - a4[1]; /*0x13e732*/
          }
        }
      }
      else
      {
        *a4 = 2; /*0x13e6ee*/
        a4[1] = v7; /*0x13e6f4*/
        a4[2] = *(unsigned __int16 *)(v9 + 4); /*0x13e6fb*/
      }
    }
  }
  if ( !*(_DWORD *)v9 /*0x13e762*/
    || a3 != *(unsigned __int16 *)(v9 + 6)
    || *a2 != *(_BYTE *)(v9 + 8)
    || bcmp(a2, (const void *)(v9 + 8), a3) )
  {
    v16 = v7; /*0x13e7e0*/
    v10 = *(unsigned __int16 *)(v9 + 4); /*0x13e7e3*/
    goto LABEL_35; /*0x13e7e3*/
  }
  *(_DWORD *)(a1 + 76) = v7; /*0x13e771*/
  if ( *(_DWORD *)(a1 + 72) == *(_DWORD *)v9 ) /*0x13e779*/
  {
    *a5 = a1; /*0x13e7ba*/
    ++*(_WORD *)(a1 + 18); /*0x13e7bc*/
  }
  else
  {
    v14 = iget(*(_WORD *)(a1 + 70), *(_DWORD *)(a1 + 80), *(_DWORD *)v9); /*0x13e785*/
    *a5 = v14; /*0x13e78d*/
    if ( !v14 ) /*0x13e794*/
    {
      byte_swap_dir_block_out(v18); /*0x13e79a*/
      brelse(v18); /*0x13e7a3*/
      return *(char *)(dword_1E875C + 104); /*0x13e7b1*/
    }
  }
  *a4 = 3; /*0x13e7c3*/
  a4[1] = v7; /*0x13e7c9*/
  a4[2] = v7 - v16; /*0x13e7cf*/
  a4[3] = v18; /*0x13e7d5*/
  a4[4] = v9; /*0x13e7d8*/
  return 0; /*0x13e82f*/
}
