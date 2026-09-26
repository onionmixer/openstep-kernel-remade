/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b19c. */
int __cdecl swapoutStack(int a1)
{
  int v1; // edx
  int v2; // eax
  int **v3; // esi
  int v4; // ebx
  int **v5; // ecx
  int *v6; // edx
  int *v7; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int **v11; // [esp+14h] [ebp-4h]

  ++dword_1F63BC; /*0x15b1ab*/
  lock_write((int)&stack_queue_lock); /*0x15b1b6*/
  *(_DWORD *)(a1 - 12 + 8) = 1; /*0x15b1bb*/
  v1 = ~page_mask & (a1 - 12); /*0x15b1ce*/
  v2 = 0; /*0x15b1d0*/
  if ( dword_1E5BA4 <= 0 ) /*0x15b1d8*/
  {
LABEL_4:
    v11 = (int **)(~page_mask & (a1 - 12)); /*0x15b1f5*/
    v3 = v11; /*0x15b201*/
    v4 = 0; /*0x15b204*/
    if ( dword_1E5BA4 > 0 ) /*0x15b20d*/
    {
      v9 = dword_1E5BA0; /*0x15b215*/
      v10 = dword_1E5BA4; /*0x15b218*/
      v5 = v11 + 1; /*0x15b21d*/
      do /*0x15b268*/
      {
        if ( !v5[1] ) /*0x15b220*/
        {
          v6 = *v3; /*0x15b226*/
          v7 = *v5; /*0x15b228*/
          if ( *v3 == &dword_1E5B98 ) /*0x15b230*/
            dword_1E5B9C = (int)*v5; /*0x15b232*/
          else
            v6[1] = (int)v7; /*0x15b23c*/
          if ( v7 == &dword_1E5B98 ) /*0x15b244*/
            dword_1E5B98 = (int)v6; /*0x15b246*/
          else
            *v7 = (int)v6; /*0x15b250*/
          --dword_1DED68; /*0x15b252*/
          --dword_1F63B8; /*0x15b258*/
        }
        v5 = (int **)((char *)v5 + v9); /*0x15b25e*/
        v3 = (int **)((char *)v3 + v9); /*0x15b261*/
        ++v4; /*0x15b264*/
      }
      while ( v10 > v4 ); /*0x15b268*/
    }
    *v11 = (int *)-17958194; /*0x15b26d*/
    vm_map_pageable(kernel_map, v11, ~page_mask & ((unsigned int)v11 + dword_1E5BA0 + page_mask), 1); /*0x15b292*/
    ++dword_1F63C0; /*0x15b297*/
  }
  else
  {
    while ( *(_DWORD *)(v1 + 8) != 2 ) /*0x15b1e0*/
    {
      v1 += dword_1E5BA0; /*0x15b1e6*/
      if ( dword_1E5BA4 <= ++v2 ) /*0x15b1f3*/
        goto LABEL_4; /*0x15b1f3*/
    }
  }
  return lock_done(&stack_queue_lock); /*0x15b2ad*/
}
