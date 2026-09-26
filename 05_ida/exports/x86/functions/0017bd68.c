/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bd68. */
int __cdecl vslock(int a1, int a2)
{
  return vm_map_pageable( /*0x17bd98*/
           *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
           ~page_mask & a1,
           ~page_mask & (page_mask + a2 + a1),
           0);
}
