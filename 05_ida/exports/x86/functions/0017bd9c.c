/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bd9c. */
int __cdecl vsunlock(int a1, int a2, int a3)
{
  unsigned int i; // ebx
  unsigned int v4; // eax
  int v5; // eax
  int v7; // [esp+Ch] [ebp-4h]

  if ( a3 ) /*0x17bdac*/
  {
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12) + 36); /*0x17bdbc*/
    for ( i = ~page_mask & a1; i < (~page_mask & (unsigned int)(page_mask + a1 + a2)); i += page_size ) /*0x17bdd7*/
    {
      v4 = pmap_extract(v7, i); /*0x17bde1*/
      v5 = vm_phys_to_vm_page(v4); /*0x17bde7*/
      *(_BYTE *)(v5 + 30) &= ~0x20u; /*0x17bdec*/
    }
  }
  return vm_map_pageable( /*0x17be33*/
           *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
           a1 & ~page_mask,
           ~page_mask & (page_mask + a1 + a2),
           1);
}
