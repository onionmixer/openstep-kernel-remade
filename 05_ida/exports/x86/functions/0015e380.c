/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e380. */
int __cdecl remap_vnode(int a1, int a2, int a3)
{
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int *v8; // edx
  int *v9; // eax
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h] BYREF
  unsigned int v13; // [esp+28h] [ebp+10h]

  v3 = *(_DWORD **)a1; /*0x15e38f*/
  v4 = *(_DWORD *)(*(_DWORD *)a1 + 12); /*0x15e391*/
  if ( v4 ) /*0x15e396*/
    mfs_map_remove(v3, v3[2], v3[2] + v4, 1); /*0x15e3a2*/
  v11 = a2 & ~page_mask; /*0x15e3b8*/
  v13 = (~page_mask & (page_mask + a2 + a3)) - v11; /*0x15e3c7*/
  if ( v13 <= 0xFFFF ) /*0x15e3d0*/
    v13 = 0x10000; /*0x15e3d2*/
  do /*0x15e50b*/
  {
    v12 = *(_DWORD *)(mfs_map + 20); /*0x15e3e4*/
    lock_write((int)mfs_alloc_lock_data); /*0x15e3ec*/
    v5 = vm_allocate_with_pager(mfs_map, &v12, v13, 1, *v3, v11); /*0x15e409*/
    v6 = v5; /*0x15e40e*/
    if ( v5 == 3 ) /*0x15e416*/
    {
      do /*0x15e435*/
      {
        while ( vm_info_lock_data ) /*0x15e423*/
          ; /*0x15e421*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15e435*/
      v7 = 0; /*0x15e437*/
      if ( (int *)vm_info_queue != &vm_info_queue ) /*0x15e443*/
      {
        v7 = vm_info_queue; /*0x15e445*/
        v8 = *(int **)(vm_info_queue + 40); /*0x15e447*/
        v9 = *(int **)(vm_info_queue + 44); /*0x15e44a*/
        if ( v8 == &vm_info_queue ) /*0x15e453*/
          dword_1F64D4 = *(_DWORD *)(vm_info_queue + 44); /*0x15e455*/
        else
          v8[11] = (int)v9; /*0x15e45c*/
        if ( v9 == &vm_info_queue ) /*0x15e464*/
          vm_info_queue = (int)v8; /*0x15e49c*/
        else
          v9[10] = (int)v8; /*0x15e466*/
        *(_BYTE *)(v7 + 56) &= ~1u; /*0x15e469*/
        --mfs_files_mapped; /*0x15e46d*/
        ++vm_info_version; /*0x15e473*/
      }
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15e47b*/
      if ( v7 ) /*0x15e483*/
      {
        lock_done((int)mfs_alloc_lock_data); /*0x15e48a*/
        mfs_memfree(v7, 1); /*0x15e492*/
      }
      else
      {
        mfs_alloc_wanted = 1; /*0x15e4a4*/
        assert_wait(&mfs_map, 0); /*0x15e4b5*/
        ++mfs_alloc_blocks; /*0x15e4ba*/
        lock_done((int)mfs_alloc_lock_data); /*0x15e4c5*/
        thread_block(); /*0x15e4ca*/
      }
      lock_write((int)mfs_alloc_lock_data); /*0x15e4d4*/
    }
    else if ( v5 ) /*0x15e4e2*/
    {
      printf("Unexpected error on file map, ret = %d.\n", v5); /*0x15e4ea*/
      panic(aRemapVnode); /*0x15e4f4*/
    }
    lock_done((int)mfs_alloc_lock_data); /*0x15e501*/
  }
  while ( v6 ); /*0x15e50b*/
  v3[2] = v12; /*0x15e514*/
  v3[3] = v13; /*0x15e51a*/
  v3[4] = v11; /*0x15e520*/
  return 1; /*0x15e52b*/
}
