/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ec00. */
__int32 mfs_cache_trim()
{
  int v1; // ebx
  int *v2; // edx
  int *v3; // eax
  int *v4; // edx
  int *v5; // eax
  int v6; // esi

  while ( 1 ) /*0x15ec24*/
  {
    do /*0x15ec24*/
    {
      while ( vm_info_lock_data ) /*0x15ec12*/
        ; /*0x15ec10*/
    }
    while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15ec24*/
    if ( mfs_files_mapped <= mfs_files_max ) /*0x15ec31*/
      break; /*0x15ec31*/
    v1 = vm_info_queue; /*0x15ec54*/
    v2 = *(int **)(vm_info_queue + 40); /*0x15ec5a*/
    v3 = *(int **)(vm_info_queue + 44); /*0x15ec5d*/
    if ( v2 == &vm_info_queue ) /*0x15ec66*/
      dword_1F64D4 = *(_DWORD *)(vm_info_queue + 44); /*0x15ec68*/
    else
      v2[11] = (int)v3; /*0x15ec70*/
    if ( v3 == &vm_info_queue ) /*0x15ec78*/
      vm_info_queue = (int)v2; /*0x15ec40*/
    else
      v3[10] = (int)v2; /*0x15ec7a*/
    *(_BYTE *)(v1 + 56) &= ~1u; /*0x15ec7d*/
    --mfs_files_mapped; /*0x15ec81*/
    ++vm_info_version; /*0x15ec87*/
    _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ec8f*/
    do /*0x15ecb1*/
    {
      while ( vm_info_lock_data ) /*0x15ec9f*/
        ; /*0x15ec9d*/
    }
    while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15ecb1*/
    if ( (*(_BYTE *)(v1 + 56) & 1) != 0 ) /*0x15ecb7*/
    {
      v4 = *(int **)(v1 + 40); /*0x15ecb9*/
      v5 = *(int **)(v1 + 44); /*0x15ecbc*/
      if ( v4 == &vm_info_queue ) /*0x15ecc5*/
        dword_1F64D4 = *(_DWORD *)(v1 + 44); /*0x15ecc7*/
      else
        v4[11] = (int)v5; /*0x15ecd0*/
      if ( v5 == &vm_info_queue ) /*0x15ecd8*/
        vm_info_queue = (int)v4; /*0x15ec48*/
      else
        v5[10] = (int)v4; /*0x15ecde*/
      *(_BYTE *)(v1 + 56) &= ~1u; /*0x15ece1*/
      --mfs_files_mapped; /*0x15ece5*/
      ++vm_info_version; /*0x15eceb*/
    }
    _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ecf3*/
    lock_write(v1 + 24); /*0x15ecfd*/
    if ( !*(_WORD *)(v1 + 4) ) /*0x15ed05*/
      *(_BYTE *)(v1 + 56) &= ~0x10u; /*0x15ed0c*/
    mfs_map_remove(v1, *(_DWORD *)(v1 + 8), *(_DWORD *)(v1 + 12) + *(_DWORD *)(v1 + 8), 1); /*0x15ed1d*/
    *(_DWORD *)(v1 + 12) = 0; /*0x15ed22*/
    *(_DWORD *)(v1 + 8) = 0; /*0x15ed29*/
    v6 = 0; /*0x15ed30*/
    if ( !*(_WORD *)(v1 + 4) ) /*0x15ed35*/
    {
      v6 = *(_DWORD *)(v1 + 36); /*0x15ed3c*/
      *(_DWORD *)(v1 + 36) = 0; /*0x15ed3f*/
      if ( *(_DWORD *)(v1 + 48) ) /*0x15ed46*/
      {
        crfree(*(_WORD **)(v1 + 48)); /*0x15ed4e*/
        *(_DWORD *)(v1 + 48) = 0; /*0x15ed53*/
      }
    }
    lock_done(v1 + 24); /*0x15ed61*/
    if ( v6 ) /*0x15ed6b*/
      vm_object_deallocate(v6); /*0x15ed72*/
  }
  return _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ed83*/
}
