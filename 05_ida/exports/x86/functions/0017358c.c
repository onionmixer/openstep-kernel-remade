/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17358c. */
int __cdecl vm_fault_wire(int a1, int a2)
{
  unsigned int v2; // esi
  int result; // eax
  unsigned int i; // ebx

  v2 = *(_DWORD *)(a2 + 12); /*0x173595*/
  result = pmap_pageable(*(_DWORD *)(a1 + 36), *(_DWORD *)(a2 + 8), v2, 0); /*0x1735a6*/
  for ( i = *(_DWORD *)(a2 + 8); i < v2; i += page_size ) /*0x1735b3*/
  {
    result = vm_fault_wire_fast(a1, i, a2); /*0x1735be*/
    if ( result ) /*0x1735c8*/
      result = vm_fault(a1, i, 0, 1, nullptr); /*0x1735d5*/
  }
  return result; /*0x1735ea*/
}
