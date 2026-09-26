/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15f468. */
__int32 mfs_sync()
{
  int v0; // esi
  __int32 v1; // ebx
  __int32 v2; // edi
  int *v3; // edx
  int *v4; // eax
  __int16 v5; // ax
  int v6; // eax
  char v7; // al

  do /*0x15f489*/
  {
    while ( vm_info_lock_data ) /*0x15f477*/
      ; /*0x15f475*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f489*/
  v0 = vm_info_version; /*0x15f48b*/
  v1 = vm_info_queue; /*0x15f491*/
  while ( (int *)v1 != &vm_info_queue ) /*0x15f49d*/
  {
    v2 = *(_DWORD *)(v1 + 40); /*0x15f4a3*/
    if ( (*(_BYTE *)(v1 + 56) & 2) != 0 ) /*0x15f4aa*/
    {
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f4b2*/
      do /*0x15f4d1*/
      {
        while ( vm_info_lock_data ) /*0x15f4bf*/
          ; /*0x15f4bd*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f4d1*/
      if ( (*(_BYTE *)(v1 + 56) & 1) != 0 ) /*0x15f4d7*/
      {
        v3 = *(int **)(v1 + 40); /*0x15f4d9*/
        v4 = *(int **)(v1 + 44); /*0x15f4dc*/
        if ( v3 == &vm_info_queue ) /*0x15f4e5*/
          dword_1F64D4 = *(_DWORD *)(v1 + 44); /*0x15f4e7*/
        else
          v3[11] = (int)v4; /*0x15f4f0*/
        if ( v4 == &vm_info_queue ) /*0x15f4f8*/
          vm_info_queue = (int)v3; /*0x15f608*/
        else
          v4[10] = (int)v3; /*0x15f4fe*/
        *(_BYTE *)(v1 + 56) &= ~1u; /*0x15f501*/
        --mfs_files_mapped; /*0x15f505*/
        ++vm_info_version; /*0x15f50b*/
      }
      ++*(_WORD *)(v1 + 6); /*0x15f511*/
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f517*/
      lock_write(v1 + 24); /*0x15f521*/
      vmp_push(v1); /*0x15f52a*/
      do /*0x15f54d*/
      {
        while ( vm_info_lock_data ) /*0x15f53b*/
          ; /*0x15f539*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f54d*/
      v5 = *(_WORD *)(v1 + 6); /*0x15f54f*/
      *(_WORD *)(v1 + 6) = v5 - 1; /*0x15f557*/
      if ( v5 == 1 ) /*0x15f55f*/
      {
        v6 = dword_1F64D4; /*0x15f561*/
        if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15f56b*/
          vm_info_queue = v1; /*0x15f56d*/
        else
          *(_DWORD *)(dword_1F64D4 + 40) = v1; /*0x15f578*/
        *(_DWORD *)(v1 + 44) = v6; /*0x15f57b*/
        *(_DWORD *)(v1 + 40) = &vm_info_queue; /*0x15f57e*/
        dword_1F64D4 = v1; /*0x15f585*/
        *(_BYTE *)(v1 + 56) |= 1u; /*0x15f58b*/
        ++mfs_files_mapped; /*0x15f58f*/
        ++vm_info_version; /*0x15f595*/
      }
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f59d*/
      lock_done(v1 + 24); /*0x15f5a7*/
      if ( mfs_files_mapped > mfs_files_max ) /*0x15f5ba*/
        mfs_cache_trim(); /*0x15f5bc*/
      v7 = *(_BYTE *)(v1 + 56); /*0x15f5c1*/
      if ( (v7 & 8) != 0 ) /*0x15f5c6*/
      {
        *(_BYTE *)(v1 + 56) = v7 & 0xF7; /*0x15f5ca*/
        vmp_invalidate(v1); /*0x15f5ce*/
      }
      do /*0x15f5f1*/
      {
        while ( vm_info_lock_data ) /*0x15f5df*/
          ; /*0x15f5dd*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f5f1*/
      v0 += 2; /*0x15f5f3*/
    }
    if ( v0 == vm_info_version ) /*0x15f5fd*/
    {
      v1 = v2; /*0x15f5ff*/
    }
    else
    {
      v1 = vm_info_queue; /*0x15f614*/
      v0 = vm_info_version; /*0x15f61a*/
    }
  }
  return _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f62f*/
}
