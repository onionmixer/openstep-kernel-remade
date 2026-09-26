/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1742a0. */
unsigned int __cdecl kmem_mb_alloc(_DWORD *a1, int a2)
{
  unsigned int v3; // ebx
  volatile __int32 *v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // esi
  int v12; // ebx
  volatile __int32 *v13; // [esp+10h] [ebp-14h]
  unsigned int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  unsigned int v17; // [esp+20h] [ebp-4h] BYREF
  unsigned int v18; // [esp+30h] [ebp+Ch]

  if ( (_DWORD *)mb_map != a1 && (_DWORD *)swapfs_bit_map != a1 && (_DWORD *)swapfs_rem_map != a1 ) /*0x1742c2*/
    panic(aYouFool); /*0x1742c9*/
  v18 = (page_mask + a2) & ~page_mask; /*0x1742df*/
  lock_write((int)a1); /*0x1742e6*/
  ++a1[19]; /*0x1742ee*/
  v15 = a1[4]; /*0x1742f7*/
  if ( (_DWORD *)v15 == a1 + 3 ) /*0x174302*/
  {
    lock_done((int)a1); /*0x174305*/
    v17 = a1[5]; /*0x174310*/
    if ( vm_map_find((int)a1, 0, 0, &v17, v18, 1) ) /*0x174325*/
    {
      return 0; /*0x174331*/
    }
    else
    {
      vm_map_pageable(a1, v17, v17 + v18, 0); /*0x174348*/
      return v17; /*0x17434d*/
    }
  }
  else
  {
    if ( a1[3] != v15 /*0x174383*/
      || (*(_BYTE *)(v15 + 24) & 1) != 0
      || *(_DWORD *)(v15 + 8) != a1[5]
      || *(_DWORD *)(v15 + 32) != 7
      || *(_DWORD *)(v15 + 28) != 3
      || *(_DWORD *)(v15 + 36) != 1
      || !*(_WORD *)(v15 + 40) )
    {
      panic(aMbMapAbusedEve); /*0x17438f*/
    }
    v3 = *(_DWORD *)(v15 + 12); /*0x1743a3*/
    if ( a1[6] - v18 >= v3 ) /*0x1743a8*/
    {
      v16 = *(_DWORD *)(v15 + 16); /*0x1743be*/
      v14 = *(_DWORD *)(v15 + 20) + v3 - *(_DWORD *)(v15 + 8); /*0x1743cc*/
      v17 = *(_DWORD *)(v15 + 12); /*0x1743cf*/
      *(_DWORD *)(v15 + 12) += v18; /*0x1743d5*/
      v4 = (volatile __int32 *)(v16 + 16); /*0x1743db*/
      do /*0x1743f2*/
      {
        while ( *v4 ) /*0x1743e0*/
          ; /*0x1743e2*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1743f2*/
      v5 = v14; /*0x1743f4*/
      v6 = v18 >> page_shift; /*0x174400*/
      if ( v18 >> page_shift ) /*0x174400*/
      {
        while ( 1 ) /*0x17440f*/
        {
          v7 = vm_page_alloc_sequential(v16, v5, 0); /*0x17440f*/
          v8 = v7; /*0x174414*/
          if ( !v7 ) /*0x17441b*/
            break; /*0x17441b*/
          vm_page_zero_fill(v7); /*0x174469*/
          *(_BYTE *)(v8 + 32) &= ~1u; /*0x17446e*/
          --v6; /*0x174472*/
          v5 += page_size; /*0x174473*/
          if ( !v6 ) /*0x17447e*/
            goto LABEL_28; /*0x17447e*/
        }
        while ( v14 < v5 ) /*0x174420*/
        {
          v5 -= page_size; /*0x174424*/
          v9 = vm_page_lookup(v16, v5); /*0x17442f*/
          vm_page_free(v9); /*0x174437*/
        }
        _InterlockedExchange((volatile __int32 *)(v16 + 16), 0); /*0x174449*/
        *(_DWORD *)(v15 + 12) -= v18; /*0x174452*/
        lock_done((int)a1); /*0x174459*/
        return 0; /*0x17445e*/
      }
      else
      {
LABEL_28:
        _InterlockedExchange((volatile __int32 *)(v16 + 16), 0); /*0x174480*/
        v10 = v17; /*0x174488*/
        v11 = v14; /*0x17448b*/
        if ( *(_DWORD *)(v15 + 12) > v17 ) /*0x174494*/
        {
          v13 = (volatile __int32 *)(v16 + 16); /*0x174499*/
          while ( 1 ) /*0x1744ff*/
          {
            while ( *v13 ) /*0x17449f*/
              ; /*0x1744a1*/
            if ( _InterlockedExchange(v13, 1) != 1 ) /*0x1744af*/
            {
              v12 = vm_page_lookup(v16, v11); /*0x1744c0*/
              vm_page_wire(v12); /*0x1744c3*/
              _InterlockedExchange((volatile __int32 *)(v16 + 16), 0); /*0x1744d0*/
              pmap_enter(a1[9], v10, *(_DWORD *)(v12 + 36), *(_DWORD *)(v15 + 28), 1); /*0x1744e8*/
              v10 += page_size; /*0x1744f2*/
              v11 += page_size; /*0x1744f4*/
              if ( *(_DWORD *)(v15 + 12) <= v10 ) /*0x1744ff*/
                break; /*0x1744ff*/
            }
          }
        }
        lock_done((int)a1); /*0x174505*/
        return v17; /*0x17450a*/
      }
    }
    else
    {
      lock_done((int)a1); /*0x1743ab*/
      return 0; /*0x1743b0*/
    }
  }
}
