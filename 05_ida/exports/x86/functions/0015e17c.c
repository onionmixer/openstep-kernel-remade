/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e17c. */
int *__cdecl vm_info_dequeue(int a1)
{
  int *v1; // edx
  int *result; // eax

  v1 = *(int **)(a1 + 40); /*0x15e182*/
  result = *(int **)(a1 + 44); /*0x15e185*/
  if ( v1 == &vm_info_queue ) /*0x15e18e*/
    dword_1F64D4 = *(_DWORD *)(a1 + 44); /*0x15e190*/
  else
    v1[11] = (int)result; /*0x15e198*/
  if ( result == &vm_info_queue ) /*0x15e1a0*/
    vm_info_queue = (int)v1; /*0x15e1a2*/
  else
    result[10] = (int)v1; /*0x15e1ac*/
  *(_BYTE *)(a1 + 56) &= ~1u; /*0x15e1af*/
  --mfs_files_mapped; /*0x15e1b3*/
  ++vm_info_version; /*0x15e1b9*/
  return result; /*0x15e1c1*/
}
