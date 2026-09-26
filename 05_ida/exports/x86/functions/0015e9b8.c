/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e9b8. */
__int32 __cdecl vmp_get(int a1)
{
  int *v1; // edx
  int *v2; // eax

  do /*0x15e9d9*/
  {
    while ( vm_info_lock_data ) /*0x15e9c7*/
      ; /*0x15e9c5*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15e9d9*/
  if ( (*(_BYTE *)(a1 + 56) & 1) != 0 ) /*0x15e9df*/
  {
    v1 = *(int **)(a1 + 40); /*0x15e9e1*/
    v2 = *(int **)(a1 + 44); /*0x15e9e4*/
    if ( v1 == &vm_info_queue ) /*0x15e9ed*/
      dword_1F64D4 = *(_DWORD *)(a1 + 44); /*0x15e9ef*/
    else
      v1[11] = (int)v2; /*0x15e9f8*/
    if ( v2 == &vm_info_queue ) /*0x15ea00*/
      vm_info_queue = (int)v1; /*0x15ea02*/
    else
      v2[10] = (int)v1; /*0x15ea0c*/
    *(_BYTE *)(a1 + 56) &= ~1u; /*0x15ea0f*/
    --mfs_files_mapped; /*0x15ea13*/
    ++vm_info_version; /*0x15ea19*/
  }
  ++*(_WORD *)(a1 + 6); /*0x15ea1f*/
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15ea25*/
  return lock_write(a1 + 24); /*0x15ea36*/
}
