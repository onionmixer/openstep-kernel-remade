/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b0dc. */
int __cdecl doSwapout(int a1)
{
  int **v1; // esi
  int v2; // ebx
  int **v3; // ecx
  int *v4; // edx
  int *v5; // eax
  int result; // eax
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  int **v9; // [esp+14h] [ebp-4h]

  v9 = (int **)(a1 & ~page_mask); /*0x15b0ef*/
  v1 = v9; /*0x15b0f2*/
  v2 = 0; /*0x15b0f5*/
  if ( dword_1E5BA4 > 0 ) /*0x15b0fe*/
  {
    v7 = dword_1E5BA0; /*0x15b106*/
    v8 = dword_1E5BA4; /*0x15b109*/
    v3 = v9 + 1; /*0x15b10e*/
    do /*0x15b15c*/
    {
      if ( !v3[1] ) /*0x15b114*/
      {
        v4 = *v1; /*0x15b11a*/
        v5 = *v3; /*0x15b11c*/
        if ( *v1 == &dword_1E5B98 ) /*0x15b124*/
          dword_1E5B9C = (int)*v3; /*0x15b126*/
        else
          v4[1] = (int)v5; /*0x15b130*/
        if ( v5 == &dword_1E5B98 ) /*0x15b138*/
          dword_1E5B98 = (int)v4; /*0x15b13a*/
        else
          *v5 = (int)v4; /*0x15b144*/
        --dword_1DED68; /*0x15b146*/
        --dword_1F63B8; /*0x15b14c*/
      }
      v3 = (int **)((char *)v3 + v7); /*0x15b152*/
      v1 = (int **)((char *)v1 + v7); /*0x15b155*/
      ++v2; /*0x15b158*/
    }
    while ( v8 > v2 ); /*0x15b15c*/
  }
  *v9 = (int *)-17958194; /*0x15b161*/
  result = vm_map_pageable(kernel_map, v9, ~page_mask & ((unsigned int)v9 + dword_1E5BA0 + page_mask), 1); /*0x15b186*/
  ++dword_1F63C0; /*0x15b18b*/
  return result; /*0x15b194*/
}
