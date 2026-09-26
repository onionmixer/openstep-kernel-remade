/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15f638. */
int __cdecl mfs_fsync(__int32 *a1)
{
  __int32 v1; // ebx
  int *v2; // edx
  int *v3; // eax
  __int16 v4; // ax
  int v5; // eax
  char v6; // al

  v1 = *a1; /*0x15f63f*/
  if ( !*a1 || (*(_BYTE *)(v1 + 56) & 0x10) == 0 ) /*0x15f64d*/
    return 0; /*0x15f780*/
  do /*0x15f66d*/
  {
    while ( vm_info_lock_data ) /*0x15f65b*/
      ; /*0x15f659*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f66d*/
  if ( (*(_BYTE *)(v1 + 56) & 1) != 0 ) /*0x15f673*/
  {
    v2 = *(int **)(v1 + 40); /*0x15f675*/
    v3 = *(int **)(v1 + 44); /*0x15f678*/
    if ( v2 == &vm_info_queue ) /*0x15f681*/
      dword_1F64D4 = *(_DWORD *)(v1 + 44); /*0x15f683*/
    else
      v2[11] = (int)v3; /*0x15f68c*/
    if ( v3 == &vm_info_queue ) /*0x15f694*/
      vm_info_queue = (int)v2; /*0x15f774*/
    else
      v3[10] = (int)v2; /*0x15f69a*/
    *(_BYTE *)(v1 + 56) &= ~1u; /*0x15f69d*/
    --mfs_files_mapped; /*0x15f6a1*/
    ++vm_info_version; /*0x15f6a7*/
  }
  ++*(_WORD *)(v1 + 6); /*0x15f6ad*/
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f6b3*/
  lock_write(v1 + 24); /*0x15f6bd*/
  vmp_push(v1); /*0x15f6c6*/
  do /*0x15f6e9*/
  {
    while ( vm_info_lock_data ) /*0x15f6d7*/
      ; /*0x15f6d5*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15f6e9*/
  v4 = *(_WORD *)(v1 + 6); /*0x15f6eb*/
  *(_WORD *)(v1 + 6) = v4 - 1; /*0x15f6f3*/
  if ( v4 == 1 ) /*0x15f6fb*/
  {
    v5 = dword_1F64D4; /*0x15f6fd*/
    if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15f707*/
      vm_info_queue = v1; /*0x15f709*/
    else
      *(_DWORD *)(dword_1F64D4 + 40) = v1; /*0x15f714*/
    *(_DWORD *)(v1 + 44) = v5; /*0x15f717*/
    *(_DWORD *)(v1 + 40) = &vm_info_queue; /*0x15f71a*/
    dword_1F64D4 = v1; /*0x15f721*/
    *(_BYTE *)(v1 + 56) |= 1u; /*0x15f727*/
    ++mfs_files_mapped; /*0x15f72b*/
    ++vm_info_version; /*0x15f731*/
  }
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15f739*/
  lock_done(v1 + 24); /*0x15f743*/
  if ( mfs_files_mapped > mfs_files_max ) /*0x15f756*/
    mfs_cache_trim(); /*0x15f758*/
  v6 = *(_BYTE *)(v1 + 56); /*0x15f75d*/
  if ( (v6 & 8) != 0 ) /*0x15f762*/
  {
    *(_BYTE *)(v1 + 56) = v6 & 0xF7; /*0x15f766*/
    vmp_invalidate(v1); /*0x15f76a*/
  }
  return *(_DWORD *)(v1 + 52); /*0x15f782*/
}
