/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1057f0. */
int __cdecl create_unix_stack(int a1, int a2)
{
  int v2; // edx
  int v4; // [esp+4h] [ebp-4h] BYREF

  *(_DWORD *)(*(_DWORD *)active_u + 132) = a2; /*0x105804*/
  v2 = ~page_mask & (page_mask + *(_DWORD *)(active_u + 636)); /*0x10581f*/
  v4 = ~page_mask & (a2 - v2); /*0x105825*/
  return vm_map_find(a1, 0, 0, (unsigned int *)&v4, v2, 0); /*0x105839*/
}
