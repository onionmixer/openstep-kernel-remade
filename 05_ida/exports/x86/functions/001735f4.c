/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1735f4. */
int __cdecl vm_fault_unwire(int a1, int a2)
{
  int v2; // edi
  unsigned int i; // ebx
  unsigned int v4; // esi
  int v5; // eax
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v7 = *(_DWORD *)(a2 + 12); /*0x173606*/
  v2 = *(_DWORD *)(a1 + 36); /*0x173609*/
  do /*0x173625*/
  {
    while ( vm_page_queue_lock ) /*0x173613*/
      ; /*0x173611*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173625*/
  for ( i = *(_DWORD *)(a2 + 8); v7 > i; i += page_size ) /*0x173630*/
  {
    v4 = pmap_extract(v2, i); /*0x17363b*/
    if ( !v4 ) /*0x173642*/
      panic(aUnwirePageNotI); /*0x173649*/
    pmap_change_wiring(v2, i, 0); /*0x173655*/
    v5 = vm_phys_to_vm_page(v4); /*0x17365b*/
    vm_page_unwire(v5); /*0x173661*/
  }
  _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173676*/
  return pmap_pageable(v2, *(_DWORD *)(a2 + 8), v7, 1); /*0x173692*/
}
