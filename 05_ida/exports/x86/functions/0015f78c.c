/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15f78c. */
int __cdecl mfs_fsync_invalidate(__int32 *a1, char a2)
{
  __int32 v2; // ebx
  int *v3; // edx
  int *v4; // eax
  __int16 v5; // ax
  int v6; // eax

  v2 = *a1; /*0x15f797*/
  if ( !*a1 || (*(_BYTE *)(v2 + 56) & 0x10) == 0 ) /*0x15f7a5*/
    return 0; /*0x15f8b4*/
  do /*0x15f7c5*/
  {
    while ( vm_info_lock_data ) /*0x15f7b3*/
      ; /*0x15f7b1*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f7c5*/
  if ( (*(_BYTE *)(v2 + 56) & 1) != 0 ) /*0x15f7cb*/
  {
    v3 = *(int **)(v2 + 40); /*0x15f7cd*/
    v4 = *(int **)(v2 + 44); /*0x15f7d0*/
    if ( v3 == &vm_info_queue ) /*0x15f7d9*/
      dword_1F64D4 = *(_DWORD *)(v2 + 44); /*0x15f7db*/
    else
      v3[11] = (int)v4; /*0x15f7e4*/
    if ( v4 == &vm_info_queue ) /*0x15f7ec*/
      vm_info_queue = (int)v3; /*0x15f8a8*/
    else
      v4[10] = (int)v3; /*0x15f7f2*/
    *(_BYTE *)(v2 + 56) &= ~1u; /*0x15f7f5*/
    --mfs_files_mapped; /*0x15f7f9*/
    ++vm_info_version; /*0x15f7ff*/
  }
  ++*(_WORD *)(v2 + 6); /*0x15f805*/
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f80b*/
  if ( (a2 & 1) == 0 ) /*0x15f817*/
    vmp_push_all(v2); /*0x15f81a*/
  if ( (a2 & 2) == 0 ) /*0x15f828*/
  {
    *(_BYTE *)(v2 + 56) &= ~8u; /*0x15f82a*/
    vmp_invalidate(v2); /*0x15f82f*/
  }
  do /*0x15f84d*/
  {
    while ( vm_info_lock_data ) /*0x15f83b*/
      ; /*0x15f839*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f84d*/
  v5 = *(_WORD *)(v2 + 6); /*0x15f84f*/
  *(_WORD *)(v2 + 6) = v5 - 1; /*0x15f857*/
  if ( v5 == 1 ) /*0x15f85f*/
  {
    v6 = dword_1F64D4; /*0x15f861*/
    if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15f86b*/
      vm_info_queue = v2; /*0x15f86d*/
    else
      *(_DWORD *)(dword_1F64D4 + 40) = v2; /*0x15f878*/
    *(_DWORD *)(v2 + 44) = v6; /*0x15f87b*/
    *(_DWORD *)(v2 + 40) = &vm_info_queue; /*0x15f87e*/
    dword_1F64D4 = v2; /*0x15f885*/
    *(_BYTE *)(v2 + 56) |= 1u; /*0x15f88b*/
    ++mfs_files_mapped; /*0x15f88f*/
    ++vm_info_version; /*0x15f895*/
  }
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f89d*/
  return *(_DWORD *)(v2 + 52); /*0x15f8b9*/
}
