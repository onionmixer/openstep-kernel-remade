/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ca8c. */
int __cdecl kern_serv_wire_range(int a1, int a2, int a3)
{
  return vm_map_pageable(*(_DWORD *)(kernel_task + 12), ~page_mask & a2, ~page_mask & (page_mask + a3 + a2), 0); /*0x16cab9*/
}
