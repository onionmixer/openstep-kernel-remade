/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15f8c0. */
int __cdecl mfs_invalidate(int *a1)
{
  int v1; // ebx
  char v2; // al
  int *v3; // edx
  int *v4; // eax
  __int16 v5; // ax
  int v6; // eax
  char v7; // al

  v1 = *a1; /*0x15f8c7*/
  if ( *a1 ) /*0x15f8c7*/
  {
    v2 = *(_BYTE *)(v1 + 56); /*0x15f8d1*/
    if ( (v2 & 0x10) != 0 ) /*0x15f8d6*/
    {
      if ( *(__int16 *)(v1 + 6) <= 0 ) /*0x15f8e1*/
      {
        do /*0x15f911*/
        {
          while ( vm_info_lock_data ) /*0x15f8ff*/
            ; /*0x15f8fd*/
        }
        while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f911*/
        if ( (*(_BYTE *)(v1 + 56) & 1) != 0 ) /*0x15f917*/
        {
          v3 = *(int **)(v1 + 40); /*0x15f919*/
          v4 = *(int **)(v1 + 44); /*0x15f91c*/
          if ( v3 == &vm_info_queue ) /*0x15f925*/
            dword_1F64D4 = *(_DWORD *)(v1 + 44); /*0x15f927*/
          else
            v3[11] = (int)v4; /*0x15f930*/
          if ( v4 == &vm_info_queue ) /*0x15f938*/
            vm_info_queue = (int)v3; /*0x15f8f0*/
          else
            v4[10] = (int)v3; /*0x15f93a*/
          *(_BYTE *)(v1 + 56) &= ~1u; /*0x15f93d*/
          --mfs_files_mapped; /*0x15f941*/
          ++vm_info_version; /*0x15f947*/
        }
        ++*(_WORD *)(v1 + 6); /*0x15f94d*/
        _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f953*/
        lock_write(v1 + 24); /*0x15f95d*/
        vmp_invalidate(v1); /*0x15f966*/
        do /*0x15f989*/
        {
          while ( vm_info_lock_data ) /*0x15f977*/
            ; /*0x15f975*/
        }
        while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f989*/
        v5 = *(_WORD *)(v1 + 6); /*0x15f98b*/
        *(_WORD *)(v1 + 6) = v5 - 1; /*0x15f993*/
        if ( v5 == 1 ) /*0x15f99b*/
        {
          v6 = dword_1F64D4; /*0x15f99d*/
          if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15f9a7*/
            vm_info_queue = v1; /*0x15f9a9*/
          else
            *(_DWORD *)(dword_1F64D4 + 40) = v1; /*0x15f9b4*/
          *(_DWORD *)(v1 + 44) = v6; /*0x15f9b7*/
          *(_DWORD *)(v1 + 40) = &vm_info_queue; /*0x15f9ba*/
          dword_1F64D4 = v1; /*0x15f9c1*/
          *(_BYTE *)(v1 + 56) |= 1u; /*0x15f9c7*/
          ++mfs_files_mapped; /*0x15f9cb*/
          ++vm_info_version; /*0x15f9d1*/
        }
        _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f9d9*/
        lock_done(v1 + 24); /*0x15f9e3*/
        if ( mfs_files_mapped > mfs_files_max ) /*0x15f9f6*/
          mfs_cache_trim(); /*0x15f9f8*/
        v7 = *(_BYTE *)(v1 + 56); /*0x15f9fd*/
        if ( (v7 & 8) != 0 ) /*0x15fa02*/
        {
          *(_BYTE *)(v1 + 56) = v7 & 0xF7; /*0x15fa06*/
          vmp_invalidate(v1); /*0x15fa0a*/
        }
      }
      else
      {
        *(_BYTE *)(v1 + 56) = v2 | 8; /*0x15f8e5*/
      }
    }
  }
  return *(_DWORD *)(v1 + 52); /*0x15fa12*/
}
