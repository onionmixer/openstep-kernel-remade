/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16be1c. */
int __cdecl host_zone_free_space_info(int a1, int *a2, unsigned int *a3, int *a4, unsigned int *a5)
{
  unsigned int v6; // ebx
  unsigned int i; // esi
  _DWORD *v8; // edx
  unsigned int v9; // ebx
  _DWORD *v10; // eax
  _DWORD *j; // eax
  int v12; // ebx
  int v13; // ebx
  unsigned int v14; // [esp+Ch] [ebp-24h]
  _DWORD *v15; // [esp+Ch] [ebp-24h]
  _DWORD *v16; // [esp+10h] [ebp-20h]
  unsigned int v17; // [esp+14h] [ebp-1Ch]
  unsigned int v18; // [esp+18h] [ebp-18h]
  unsigned int v19; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+20h] [ebp-10h] BYREF
  int v21; // [esp+24h] [ebp-Ch] BYREF
  int v22; // [esp+28h] [ebp-8h] BYREF
  int v23; // [esp+2Ch] [ebp-4h] BYREF

  if ( !a1 ) /*0x16be29*/
    return 22; /*0x16be2b*/
  v18 = 0; /*0x16be38*/
  v19 = 0; /*0x16be3f*/
  while ( 1 ) /*0x16be48*/
  {
    v14 = 0; /*0x16be48*/
    v6 = 0; /*0x16be4f*/
    do /*0x16be6d*/
    {
      while ( zget_space_lock ) /*0x16be5b*/
        ; /*0x16be59*/
    }
    while ( _InterlockedExchange(&zget_space_lock, 1) == 1 ); /*0x16be6d*/
    v17 = 0; /*0x16be6f*/
    for ( i = 0; i < zone_free_space_count; ++i ) /*0x16be81*/
      v17 += *(_DWORD *)(zone_free_space[i] + 12); /*0x16be8e*/
    if ( *a3 > i ) /*0x16be9b*/
      v6 = ~page_mask & (page_mask + 12 * i); /*0x16beac*/
    if ( *a5 < v17 ) /*0x16beb6*/
      v14 = ~page_mask & (page_mask + 8 * v17); /*0x16bec4*/
    if ( v19 >= v6 && v14 <= v18 ) /*0x16bed2*/
      break; /*0x16bed2*/
    _InterlockedExchange(&zget_space_lock, 0); /*0x16beda*/
    if ( v19 < v6 ) /*0x16bee3*/
    {
      if ( v19 ) /*0x16bee9*/
        kmem_free(ipc_kernel_map, v23, v19); /*0x16befa*/
      v19 = v6; /*0x16bf02*/
      if ( kmem_alloc_pageable(ipc_kernel_map, &v23, v6) ) /*0x16bf11*/
      {
        if ( v18 ) /*0x16bf21*/
          kmem_free(ipc_kernel_map, v22, v18); /*0x16bf2e*/
        return 6; /*0x16bfb1*/
      }
      vm_map_pageable(ipc_kernel_map, v23, v23 + v6, 0); /*0x16bf43*/
    }
    if ( v18 < v14 ) /*0x16bf51*/
    {
      if ( v18 ) /*0x16bf5b*/
        kmem_free(ipc_kernel_map, v22, v18); /*0x16bf6c*/
      v18 = v14; /*0x16bf77*/
      if ( kmem_alloc_pageable(ipc_kernel_map, &v22, v14) ) /*0x16bf86*/
      {
        if ( v19 ) /*0x16bf96*/
          kmem_free(ipc_kernel_map, v23, v19); /*0x16bfa7*/
        return 6; /*0x16bfa7*/
      }
      vm_map_pageable(ipc_kernel_map, v22, v22 + v14, 0); /*0x16bfcb*/
    }
  }
  if ( v19 ) /*0x16bfdc*/
    v15 = (_DWORD *)v23; /*0x16bfe1*/
  else
    v15 = (_DWORD *)*a2; /*0x16bfed*/
  if ( v18 ) /*0x16bff4*/
    v8 = (_DWORD *)v22; /*0x16bff6*/
  else
    v8 = (_DWORD *)*a4; /*0x16bfff*/
  v9 = 0; /*0x16c001*/
  if ( i ) /*0x16c005*/
  {
    v16 = v15 + 2; /*0x16c00d*/
    do /*0x16c054*/
    {
      v10 = (_DWORD *)zone_free_space[v9]; /*0x16c010*/
      *v15 = *v10; /*0x16c01c*/
      *(v16 - 1) = v10[1]; /*0x16c024*/
      *v16 = v10[3]; /*0x16c02a*/
      v16 += 3; /*0x16c02f*/
      v15 += 3; /*0x16c032*/
      for ( j = (_DWORD *)v10[2]; j; j = (_DWORD *)*j ) /*0x16c03b*/
      {
        *v8 = j; /*0x16c040*/
        v8[1] = j[1]; /*0x16c045*/
        v8 += 2; /*0x16c048*/
      }
      ++v9; /*0x16c051*/
    }
    while ( v9 < i ); /*0x16c054*/
  }
  _InterlockedExchange(&zget_space_lock, 0); /*0x16c058*/
  if ( i ) /*0x16c060*/
  {
    if ( v19 ) /*0x16c066*/
    {
      v12 = ~page_mask & (page_mask + 12 * i); /*0x16c07b*/
      vm_map_pageable(ipc_kernel_map, v23, v12 + v23, 1); /*0x16c08e*/
      vm_move(ipc_kernel_map, v23, ipc_soft_map, v12, 1, (int)&v21); /*0x16c0ac*/
      if ( v19 != v12 ) /*0x16c0b7*/
        kmem_free(ipc_kernel_map, v12 + v23, v19 - v12); /*0x16c0cc*/
      *a2 = v21; /*0x16c0da*/
    }
  }
  else
  {
    *a2 = 0; /*0x16c0e3*/
    if ( v19 ) /*0x16c0ed*/
      kmem_free(ipc_kernel_map, v23, v19); /*0x16c0fe*/
  }
  *a3 = i; /*0x16c109*/
  if ( v17 ) /*0x16c10f*/
  {
    if ( v18 ) /*0x16c115*/
    {
      v13 = ~page_mask & (page_mask + 8 * v17); /*0x16c12a*/
      vm_map_pageable(ipc_kernel_map, v22, v13 + v22, 1); /*0x16c13d*/
      vm_move(ipc_kernel_map, v22, ipc_soft_map, v13, 1, (int)&v20); /*0x16c15b*/
      if ( v18 != v13 ) /*0x16c166*/
        kmem_free(ipc_kernel_map, v13 + v22, v18 - v13); /*0x16c17b*/
      *a4 = v20; /*0x16c186*/
    }
  }
  else
  {
    *a4 = 0; /*0x16c18f*/
    if ( v18 ) /*0x16c199*/
      kmem_free(ipc_kernel_map, v22, v18); /*0x16c1aa*/
  }
  *a5 = v17; /*0x16c1b5*/
  return 0; /*0x16c1bc*/
}
