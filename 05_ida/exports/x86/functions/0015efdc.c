/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15efdc. */
int __cdecl mfs_io(_DWORD *a1, _DWORD *a2, int a3, char a4, _WORD *a5)
{
  int v5; // esi
  int v7; // edx
  int v8; // esi
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edi
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int *v16; // edx
  int v17; // edi
  int i; // ebx
  unsigned int v19; // eax
  unsigned int j; // ebx
  unsigned int v21; // eax
  int *v22; // [esp+18h] [ebp-38h]
  int v23; // [esp+24h] [ebp-2Ch]
  _DWORD *v24; // [esp+28h] [ebp-28h]
  unsigned int v25; // [esp+2Ch] [ebp-24h]
  int v26; // [esp+30h] [ebp-20h]
  int v27; // [esp+34h] [ebp-1Ch]
  unsigned int v28; // [esp+38h] [ebp-18h]
  unsigned int v29; // [esp+3Ch] [ebp-14h]
  int v30; // [esp+40h] [ebp-10h]
  unsigned int v31; // [esp+44h] [ebp-Ch]
  int v32; // [esp+48h] [ebp-8h]
  int v33; // [esp+4Ch] [ebp-4h] BYREF

  v5 = a2[5]; /*0x15efeb*/
  if ( !v5 ) /*0x15eff0*/
    return 0; /*0x15eff2*/
  v7 = a2[2]; /*0x15efff*/
  if ( v7 < 0 || v5 + v7 < 0 ) /*0x15f00b*/
    return 22; /*0x15f00d*/
  mfs_get(a1, v7, a2[5]); /*0x15f032*/
  v8 = *a1; /*0x15f03a*/
  v30 = *(_DWORD *)(*a1 + 20); /*0x15f03f*/
  if ( a3 == 1 && (a4 & 2) != 0 ) /*0x15f050*/
    a2[2] = *(_DWORD *)(*a1 + 20); /*0x15f055*/
  v29 = a2[2]; /*0x15f05e*/
  v27 = a2[5]; /*0x15f067*/
  v31 = *(_DWORD *)(a1[9] + 16); /*0x15f073*/
  if ( a3 == 1 || !a3 && !*(_DWORD *)(v8 + 48) ) /*0x15f082*/
  {
    ++*a5; /*0x15f088*/
    if ( *(_DWORD *)(v8 + 48) ) /*0x15f08b*/
      crfree(*(_DWORD *)(v8 + 48)); /*0x15f093*/
    *(_DWORD *)(v8 + 48) = a5; /*0x15f09b*/
  }
  *(_DWORD *)(v8 + 52) = 0; /*0x15f09e*/
  v28 = a2[2]; /*0x15f0ab*/
  v26 = 0; /*0x15f0ae*/
  while ( 1 ) /*0x15f0c1*/
  {
    v32 = v31; /*0x15f0c1*/
    if ( v31 >= a2[5] ) /*0x15f0c6*/
      v32 = a2[5]; /*0x15f0c8*/
    if ( !a3 ) /*0x15f0cf*/
    {
      if ( v30 - a2[2] <= 0 ) /*0x15f0dc*/
      {
        vmp_put(*a1); /*0x15f01e*/
        return 0; /*0x15f025*/
      }
      if ( v32 > v30 - a2[2] ) /*0x15f0e5*/
        v32 = v30 - a2[2]; /*0x15f0e7*/
    }
    if ( a3 == 1 ) /*0x15f0ee*/
    {
      v9 = a2[2] + v32; /*0x15f0f6*/
      if ( *(_DWORD *)(v8 + 20) < v9 ) /*0x15f0fc*/
        *(_DWORD *)(v8 + 20) = v9; /*0x15f0fe*/
    }
    v10 = a2[2]; /*0x15f104*/
    v11 = *(_DWORD *)(v8 + 16); /*0x15f107*/
    if ( v10 < v11 || v10 + v32 > *(_DWORD *)(v8 + 12) + v11 ) /*0x15f11a*/
    {
      v24 = (_DWORD *)*a1; /*0x15f125*/
      v12 = *(_DWORD *)(*a1 + 12); /*0x15f128*/
      if ( v12 ) /*0x15f12d*/
        mfs_map_remove(*a1, *(_DWORD *)(*a1 + 8), *(_DWORD *)(*a1 + 8) + v12, 1); /*0x15f13c*/
      v23 = v10 & ~page_mask; /*0x15f150*/
      v25 = (~page_mask & (page_mask + v10 + v32)) - v23; /*0x15f163*/
      if ( v25 <= 0xFFFF ) /*0x15f16c*/
        v25 = 0x10000; /*0x15f16e*/
      do /*0x15f2bb*/
      {
        v33 = *(_DWORD *)(mfs_map + 20); /*0x15f181*/
        lock_write(&mfs_alloc_lock_data); /*0x15f189*/
        v13 = vm_allocate_with_pager(mfs_map, &v33, v25, 1, *v24, v23); /*0x15f1a8*/
        v14 = v13; /*0x15f1ad*/
        if ( v13 == 3 ) /*0x15f1b5*/
        {
          do /*0x15f1d6*/
          {
            while ( vm_info_lock_data ) /*0x15f1c4*/
              ; /*0x15f1c2*/
          }
          while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f1d6*/
          v15 = 0; /*0x15f1d8*/
          if ( (int *)vm_info_queue != &vm_info_queue ) /*0x15f1e6*/
          {
            v15 = vm_info_queue; /*0x15f1e8*/
            v16 = *(int **)(vm_info_queue + 40); /*0x15f1ea*/
            v22 = *(int **)(vm_info_queue + 44); /*0x15f1f0*/
            if ( v16 == &vm_info_queue ) /*0x15f1f9*/
              dword_1F64D4 = *(_DWORD *)(vm_info_queue + 44); /*0x15f1fb*/
            else
              v16[11] = (int)v22; /*0x15f207*/
            if ( v22 == &vm_info_queue ) /*0x15f211*/
              vm_info_queue = (int)v16; /*0x15f24c*/
            else
              v22[10] = (int)v16; /*0x15f216*/
            *(_BYTE *)(v15 + 56) &= ~1u; /*0x15f219*/
            --mfs_files_mapped; /*0x15f21d*/
            ++vm_info_version; /*0x15f223*/
          }
          _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f22b*/
          if ( v15 ) /*0x15f233*/
          {
            lock_done(&mfs_alloc_lock_data); /*0x15f23a*/
            mfs_memfree(v15, 1); /*0x15f242*/
          }
          else
          {
            mfs_alloc_wanted = 1; /*0x15f254*/
            assert_wait(&mfs_map, 0); /*0x15f265*/
            ++mfs_alloc_blocks; /*0x15f26a*/
            lock_done(&mfs_alloc_lock_data); /*0x15f275*/
            thread_block(); /*0x15f27a*/
          }
          lock_write(&mfs_alloc_lock_data); /*0x15f284*/
        }
        else if ( v13 ) /*0x15f292*/
        {
          printf("Unexpected error on file map, ret = %d.\n", v13); /*0x15f29a*/
          panic(aRemapVnode); /*0x15f2a4*/
        }
        lock_done(&mfs_alloc_lock_data); /*0x15f2b1*/
      }
      while ( v14 ); /*0x15f2bb*/
      v24[2] = v33; /*0x15f2c7*/
      v24[3] = v25; /*0x15f2cd*/
      v24[4] = v23; /*0x15f2d3*/
    }
    v17 = uiomove(a2[2] + *(_DWORD *)(v8 + 8) - *(_DWORD *)(v8 + 16), v32, a3, a2); /*0x15f2f7*/
    if ( a3 == 1 ) /*0x15f300*/
      *(_BYTE *)(v8 + 56) |= 2u; /*0x15f302*/
    if ( *(_DWORD *)(v8 + 52) ) /*0x15f306*/
    {
      v17 = *(_DWORD *)(v8 + 52); /*0x15f30d*/
      *(_DWORD *)(v8 + 52) = 0; /*0x15f30f*/
      crfree(*(_DWORD *)(v8 + 48)); /*0x15f31a*/
      *(_DWORD *)(v8 + 48) = 0; /*0x15f31f*/
    }
    if ( a3 == 1 && (*(_BYTE *)(a1[9] + 13) & 1) != 0 && nmfsbuf <= ++v26 ) /*0x15f34b*/
    {
      if ( !v17 ) /*0x15f34f*/
      {
        vmp_push(v8); /*0x15f352*/
        for ( i = 0; v26 > i; ++i ) /*0x15f35f*/
        {
          v19 = (*(int (__cdecl **)(_DWORD *))(a1[7] + 128))(a1); /*0x15f378*/
          blkflush(a1, v28 / v19, v31); /*0x15f38d*/
          v28 += v31; /*0x15f395*/
        }
        if ( *(_DWORD *)(v8 + 52) ) /*0x15f3a1*/
        {
          v17 = *(_DWORD *)(v8 + 52); /*0x15f3a8*/
          *(_DWORD *)(v8 + 52) = 0; /*0x15f3aa*/
        }
      }
      v26 = 0; /*0x15f3b1*/
    }
    if ( v17 ) /*0x15f3ba*/
      break; /*0x15f3ba*/
    if ( (int)a2[5] <= 0 || !v32 ) /*0x15f3cd*/
    {
      if ( a3 == 1 && ((a4 & 4) != 0 || (*(_BYTE *)(a1[9] + 13) & 1) != 0) ) /*0x15f3eb*/
      {
        vmp_push(v8); /*0x15f3ee*/
        for ( j = v29; v29 + v27 > j; j += v31 ) /*0x15f400*/
        {
          v21 = (*(int (__cdecl **)(_DWORD *))(a1[7] + 128))(a1); /*0x15f41c*/
          blkflush(a1, j / v21, v31); /*0x15f430*/
        }
        if ( *(_DWORD *)(v8 + 52) ) /*0x15f440*/
        {
          v17 = *(_DWORD *)(v8 + 52); /*0x15f447*/
          *(_DWORD *)(v8 + 52) = 0; /*0x15f449*/
        }
      }
      break; /*0x15f449*/
    }
  }
  vmp_put(*a1); /*0x15f450*/
  return v17; /*0x15f460*/
}
