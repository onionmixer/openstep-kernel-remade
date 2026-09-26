/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e534. */
int __cdecl mfs_trunc(__int32 *a1, unsigned int a2)
{
  __int32 v2; // edi
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax
  size_t v8; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // ebx
  int *v12; // edx
  int *v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-1Ch]
  int v15; // [esp+Ch] [ebp-1Ch]
  int v16; // [esp+14h] [ebp-14h]
  _DWORD *v17; // [esp+18h] [ebp-10h]
  unsigned int v18; // [esp+1Ch] [ebp-Ch]
  size_t v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h] BYREF

  v2 = *a1; /*0x15e540*/
  if ( (*(_BYTE *)(*a1 + 56) & 0x10) != 0 ) /*0x15e546*/
  {
    vmp_get(*a1); /*0x15e559*/
    v4 = ~page_mask & (page_mask + a2); /*0x15e56c*/
    v5 = *(_DWORD *)(v2 + 16); /*0x15e56e*/
    v14 = 0; /*0x15e574*/
    if ( v4 >= v5 ) /*0x15e57d*/
      v14 = v4 - v5; /*0x15e583*/
    v6 = *(_DWORD *)(v2 + 12); /*0x15e586*/
    if ( v14 < v6 ) /*0x15e58c*/
    {
      mfs_map_remove(v2, v14 + *(_DWORD *)(v2 + 8), *(_DWORD *)(v2 + 8) + v6, 0); /*0x15e59b*/
      *(_DWORD *)(v2 + 12) = v14; /*0x15e5a3*/
    }
    v7 = *(_DWORD *)(v2 + 20); /*0x15e5a9*/
    if ( v7 > v4 ) /*0x15e5ae*/
      vno_flush(a1, v4, v7 - v4); /*0x15e5b8*/
    *(_DWORD *)(v2 + 20) = a2; /*0x15e5c3*/
    if ( a2 != v4 ) /*0x15e5c8*/
    {
      v8 = v4 - a2; /*0x15e5ce*/
      v19 = v8; /*0x15e5d0*/
      v9 = *(_DWORD *)(v2 + 16); /*0x15e5d3*/
      if ( a2 < v9 || v8 + a2 > *(_DWORD *)(v2 + 12) + v9 ) /*0x15e5e4*/
      {
        v17 = (_DWORD *)*a1; /*0x15e5ef*/
        v10 = *(_DWORD *)(*a1 + 12); /*0x15e5f2*/
        if ( v10 ) /*0x15e5f7*/
          mfs_map_remove(*a1, *(_DWORD *)(*a1 + 8), *(_DWORD *)(*a1 + 8) + v10, 1); /*0x15e603*/
        v16 = ~page_mask & a2; /*0x15e619*/
        v18 = (~page_mask & (page_mask + v8 + a2)) - v16; /*0x15e628*/
        if ( v18 <= 0xFFFF ) /*0x15e631*/
          v18 = 0x10000; /*0x15e633*/
        do /*0x15e776*/
        {
          v20 = *(_DWORD *)(mfs_map + 20); /*0x15e644*/
          lock_write((int)mfs_alloc_lock_data); /*0x15e64c*/
          v15 = vm_allocate_with_pager(mfs_map, &v20, v18, 1, *v17, v16); /*0x15e671*/
          if ( v15 == 3 ) /*0x15e67a*/
          {
            do /*0x15e699*/
            {
              while ( vm_info_lock_data ) /*0x15e687*/
                ; /*0x15e685*/
            }
            while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15e699*/
            v11 = 0; /*0x15e69b*/
            if ( (int *)vm_info_queue != &vm_info_queue ) /*0x15e6a7*/
            {
              v11 = vm_info_queue; /*0x15e6a9*/
              v12 = *(int **)(vm_info_queue + 40); /*0x15e6ab*/
              v13 = *(int **)(vm_info_queue + 44); /*0x15e6ae*/
              if ( v12 == &vm_info_queue ) /*0x15e6b7*/
                dword_1F64D4 = *(_DWORD *)(vm_info_queue + 44); /*0x15e6b9*/
              else
                v12[11] = (int)v13; /*0x15e6c0*/
              if ( v13 == &vm_info_queue ) /*0x15e6c8*/
                vm_info_queue = (int)v12; /*0x15e700*/
              else
                v13[10] = (int)v12; /*0x15e6ca*/
              *(_BYTE *)(v11 + 56) &= ~1u; /*0x15e6cd*/
              --mfs_files_mapped; /*0x15e6d1*/
              ++vm_info_version; /*0x15e6d7*/
            }
            _InterlockedExchange(&vm_info_lock_data, 0); /*0x15e6df*/
            if ( v11 ) /*0x15e6e7*/
            {
              lock_done((int)mfs_alloc_lock_data); /*0x15e6ee*/
              mfs_memfree(v11, 1); /*0x15e6f6*/
            }
            else
            {
              mfs_alloc_wanted = 1; /*0x15e708*/
              assert_wait(&mfs_map, 0); /*0x15e719*/
              ++mfs_alloc_blocks; /*0x15e71e*/
              lock_done((int)mfs_alloc_lock_data); /*0x15e729*/
              thread_block(); /*0x15e72e*/
            }
            lock_write((int)mfs_alloc_lock_data); /*0x15e738*/
          }
          else if ( v15 ) /*0x15e748*/
          {
            printf("Unexpected error on file map, ret = %d.\n", v15); /*0x15e753*/
            panic(aRemapVnode); /*0x15e75d*/
          }
          lock_done((int)mfs_alloc_lock_data); /*0x15e76a*/
        }
        while ( v15 ); /*0x15e776*/
        v17[2] = v20; /*0x15e782*/
        v17[3] = v18; /*0x15e788*/
        v17[4] = v16; /*0x15e78e*/
      }
      bzero((void *)(*(_DWORD *)(v2 + 8) + a2 - *(_DWORD *)(v2 + 16)), v19); /*0x15e79f*/
      ++*(_WORD *)(v2 + 4); /*0x15e7a4*/
      *(_BYTE *)(v2 + 56) |= 2u; /*0x15e7a8*/
      vmp_push(v2); /*0x15e7ad*/
      --*(_WORD *)(v2 + 4); /*0x15e7b2*/
    }
    vmp_put(v2); /*0x15e7ba*/
    return 1; /*0x15e7bf*/
  }
  else
  {
    *(_DWORD *)(v2 + 20) = a2; /*0x15e54b*/
    return 0; /*0x15e54e*/
  }
}
