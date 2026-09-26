/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ed8c. */
__int32 mfs_cache_clear()
{
  int v0; // edi
  int v1; // ebx
  int *v2; // edx
  int *v3; // eax
  int v4; // esi

  do /*0x15edad*/
  {
    while ( vm_info_lock_data ) /*0x15ed9b*/
      ; /*0x15ed99*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15edad*/
  v0 = vm_info_version; /*0x15edaf*/
  v1 = vm_info_queue; /*0x15edb5*/
  while ( (int *)v1 != &vm_info_queue ) /*0x15edc1*/
  {
    if ( !*(_WORD *)(v1 + 4) ) /*0x15edc7*/
    {
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15edd4*/
      do /*0x15edf5*/
      {
        while ( vm_info_lock_data ) /*0x15ede3*/
          ; /*0x15ede1*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15edf5*/
      if ( (*(_BYTE *)(v1 + 56) & 1) != 0 ) /*0x15edfb*/
      {
        v2 = *(int **)(v1 + 40); /*0x15edfd*/
        v3 = *(int **)(v1 + 44); /*0x15ee00*/
        if ( v2 == &vm_info_queue ) /*0x15ee09*/
          dword_1F64D4 = *(_DWORD *)(v1 + 44); /*0x15ee0b*/
        else
          v2[11] = (int)v3; /*0x15ee14*/
        if ( v3 == &vm_info_queue ) /*0x15ee1c*/
          vm_info_queue = (int)v2; /*0x15eee8*/
        else
          v3[10] = (int)v2; /*0x15ee22*/
        *(_BYTE *)(v1 + 56) &= ~1u; /*0x15ee25*/
        --mfs_files_mapped; /*0x15ee29*/
        ++vm_info_version; /*0x15ee2f*/
      }
      _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ee37*/
      lock_write(v1 + 24); /*0x15ee41*/
      if ( !*(_WORD *)(v1 + 4) ) /*0x15ee49*/
        *(_BYTE *)(v1 + 56) &= ~0x10u; /*0x15ee50*/
      mfs_map_remove(v1, *(_DWORD *)(v1 + 8), *(_DWORD *)(v1 + 12) + *(_DWORD *)(v1 + 8), 1); /*0x15ee61*/
      *(_DWORD *)(v1 + 12) = 0; /*0x15ee66*/
      *(_DWORD *)(v1 + 8) = 0; /*0x15ee6d*/
      v4 = 0; /*0x15ee74*/
      if ( !*(_WORD *)(v1 + 4) ) /*0x15ee79*/
      {
        v4 = *(_DWORD *)(v1 + 36); /*0x15ee80*/
        *(_DWORD *)(v1 + 36) = 0; /*0x15ee83*/
        if ( *(_DWORD *)(v1 + 48) ) /*0x15ee8a*/
        {
          crfree(*(_WORD **)(v1 + 48)); /*0x15ee92*/
          *(_DWORD *)(v1 + 48) = 0; /*0x15ee97*/
        }
      }
      lock_done(v1 + 24); /*0x15eea5*/
      if ( v4 ) /*0x15eeaf*/
        vm_object_deallocate(v4); /*0x15eeb2*/
      do /*0x15eed5*/
      {
        while ( vm_info_lock_data ) /*0x15eec3*/
          ; /*0x15eec1*/
      }
      while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15eed5*/
    }
    if ( v0 == vm_info_version ) /*0x15eede*/
    {
      v1 = *(_DWORD *)(v1 + 40); /*0x15eee0*/
    }
    else
    {
      v1 = vm_info_queue; /*0x15eef4*/
      v0 = vm_info_version; /*0x15eefa*/
    }
  }
  return _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ef0f*/
}
