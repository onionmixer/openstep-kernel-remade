/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e7d0. */
__int32 __cdecl mfs_get(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v4; // esi
  __int32 result; // eax
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // ebx
  int *v11; // edx
  int *v12; // eax
  int v13; // [esp+10h] [ebp-Ch]
  unsigned int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h] BYREF

  v3 = a3; /*0x15e7dc*/
  v4 = *a1; /*0x15e7df*/
  vmp_get(*a1); /*0x15e7e2*/
  result = mfs_max_window; /*0x15e7e7*/
  if ( a3 > mfs_max_window ) /*0x15e7f1*/
    v3 = mfs_max_window; /*0x15e7f3*/
  if ( *(_DWORD *)(v4 + 12) < v3 ) /*0x15e7f8*/
  {
    v6 = (_DWORD *)*a1; /*0x15e801*/
    v7 = *(_DWORD *)(*a1 + 12); /*0x15e803*/
    if ( v7 ) /*0x15e808*/
      mfs_map_remove(v6, v6[2], v6[2] + v7, 1); /*0x15e814*/
    v13 = ~page_mask & a2; /*0x15e82e*/
    v14 = (~page_mask & (page_mask + v3 + a2)) - v13; /*0x15e83e*/
    if ( v14 <= 0xFFFF ) /*0x15e847*/
      v14 = 0x10000; /*0x15e849*/
    do /*0x15e97f*/
    {
      v15 = *(_DWORD *)(mfs_map + 20); /*0x15e858*/
      lock_write((int)mfs_alloc_lock_data); /*0x15e860*/
      v8 = vm_allocate_with_pager(mfs_map, &v15, v14, 1, *v6, v13); /*0x15e87d*/
      v9 = v8; /*0x15e882*/
      if ( v8 == 3 ) /*0x15e88a*/
      {
        do /*0x15e8a9*/
        {
          while ( vm_info_lock_data ) /*0x15e897*/
            ; /*0x15e895*/
        }
        while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15e8a9*/
        v10 = 0; /*0x15e8ab*/
        if ( (int *)vm_info_queue != &vm_info_queue ) /*0x15e8b7*/
        {
          v10 = vm_info_queue; /*0x15e8b9*/
          v11 = *(int **)(vm_info_queue + 40); /*0x15e8bb*/
          v12 = *(int **)(vm_info_queue + 44); /*0x15e8be*/
          if ( v11 == &vm_info_queue ) /*0x15e8c7*/
            dword_1F64D4 = *(_DWORD *)(vm_info_queue + 44); /*0x15e8c9*/
          else
            v11[11] = (int)v12; /*0x15e8d0*/
          if ( v12 == &vm_info_queue ) /*0x15e8d8*/
            vm_info_queue = (int)v11; /*0x15e910*/
          else
            v12[10] = (int)v11; /*0x15e8da*/
          *(_BYTE *)(v10 + 56) &= ~1u; /*0x15e8dd*/
          --mfs_files_mapped; /*0x15e8e1*/
          ++vm_info_version; /*0x15e8e7*/
        }
        _InterlockedExchange(&vm_info_lock_data, 0); /*0x15e8ef*/
        if ( v10 ) /*0x15e8f7*/
        {
          lock_done((int)mfs_alloc_lock_data); /*0x15e8fe*/
          mfs_memfree(v10, 1); /*0x15e906*/
        }
        else
        {
          mfs_alloc_wanted = 1; /*0x15e918*/
          assert_wait(&mfs_map, 0); /*0x15e929*/
          ++mfs_alloc_blocks; /*0x15e92e*/
          lock_done((int)mfs_alloc_lock_data); /*0x15e939*/
          thread_block(); /*0x15e93e*/
        }
        lock_write((int)mfs_alloc_lock_data); /*0x15e948*/
      }
      else if ( v8 ) /*0x15e956*/
      {
        printf("Unexpected error on file map, ret = %d.\n", v8); /*0x15e95e*/
        panic(aRemapVnode); /*0x15e968*/
      }
      result = lock_done((int)mfs_alloc_lock_data); /*0x15e975*/
    }
    while ( v9 ); /*0x15e97f*/
    v6[2] = v15; /*0x15e988*/
    v6[3] = v14; /*0x15e98e*/
    v6[4] = v13; /*0x15e994*/
  }
  return result; /*0x15e99a*/
}
