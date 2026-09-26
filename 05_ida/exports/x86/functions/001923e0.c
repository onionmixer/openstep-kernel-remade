/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1923e0. */
int __cdecl sub_1923E0(int a1, _BYTE *a2)
{
  int v2; // ecx
  int v3; // eax

  if ( !active_threads || (v2 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), *(_DWORD *)(v2 + 36) != kernel_pmap) ) /*0x1923fd*/
    v2 = kernel_map; /*0x1923ff*/
  v3 = 1; /*0x192409*/
  if ( (*a2 & 2) != 0 ) /*0x192411*/
    v3 = 3; /*0x192413*/
  return vm_fault(v2, ~page_mask & (a1 + 0x40000000), v3, 0, nullptr); /*0x192434*/
}
