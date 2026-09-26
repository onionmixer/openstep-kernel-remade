/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e138. */
int __cdecl vm_info_enqueue(int a1)
{
  int result; // eax

  result = dword_1F64D4; /*0x15e13e*/
  if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15e148*/
    vm_info_queue = a1; /*0x15e14a*/
  else
    *(_DWORD *)(dword_1F64D4 + 40) = a1; /*0x15e154*/
  *(_DWORD *)(a1 + 44) = result; /*0x15e157*/
  *(_DWORD *)(a1 + 40) = &vm_info_queue; /*0x15e15a*/
  dword_1F64D4 = a1; /*0x15e161*/
  *(_BYTE *)(a1 + 56) |= 1u; /*0x15e167*/
  ++mfs_files_mapped; /*0x15e16b*/
  ++vm_info_version; /*0x15e171*/
  return result; /*0x15e179*/
}
