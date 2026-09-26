/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15eb0c. */
int __cdecl mfs_memfree(int a1, int a2)
{
  int *v2; // edx
  int *v3; // eax
  int v4; // esi
  int result; // eax

  do /*0x15eb2d*/
  {
    while ( vm_info_lock_data ) /*0x15eb1b*/
      ; /*0x15eb19*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15eb2d*/
  if ( (*(_BYTE *)(a1 + 56) & 1) != 0 ) /*0x15eb33*/
  {
    v2 = *(int **)(a1 + 40); /*0x15eb35*/
    v3 = *(int **)(a1 + 44); /*0x15eb38*/
    if ( v2 == &vm_info_queue ) /*0x15eb41*/
      dword_1F64D4 = *(_DWORD *)(a1 + 44); /*0x15eb43*/
    else
      v2[11] = (int)v3; /*0x15eb4c*/
    if ( v3 == &vm_info_queue ) /*0x15eb54*/
      vm_info_queue = (int)v2; /*0x15eb56*/
    else
      v3[10] = (int)v2; /*0x15eb60*/
    *(_BYTE *)(a1 + 56) &= ~1u; /*0x15eb63*/
    --mfs_files_mapped; /*0x15eb67*/
    ++vm_info_version; /*0x15eb6d*/
  }
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15eb75*/
  lock_write(a1 + 24); /*0x15eb7f*/
  if ( !*(_WORD *)(a1 + 4) ) /*0x15eb87*/
    *(_BYTE *)(a1 + 56) &= ~0x10u; /*0x15eb8e*/
  mfs_map_remove(a1, *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12) + *(_DWORD *)(a1 + 8), a2); /*0x15eba1*/
  *(_DWORD *)(a1 + 12) = 0; /*0x15eba6*/
  *(_DWORD *)(a1 + 8) = 0; /*0x15ebad*/
  v4 = 0; /*0x15ebb4*/
  if ( !*(_WORD *)(a1 + 4) ) /*0x15ebb9*/
  {
    v4 = *(_DWORD *)(a1 + 36); /*0x15ebc0*/
    *(_DWORD *)(a1 + 36) = 0; /*0x15ebc3*/
    if ( *(_DWORD *)(a1 + 48) ) /*0x15ebca*/
    {
      crfree(*(_DWORD *)(a1 + 48)); /*0x15ebd2*/
      *(_DWORD *)(a1 + 48) = 0; /*0x15ebd7*/
    }
  }
  result = lock_done(a1 + 24); /*0x15ebe5*/
  if ( v4 ) /*0x15ebef*/
    return vm_object_deallocate(v4); /*0x15ebf2*/
  return result; /*0x15ebfa*/
}
