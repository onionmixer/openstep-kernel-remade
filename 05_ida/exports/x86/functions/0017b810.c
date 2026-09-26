/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b810. */
void __cdecl vm_page_deactivate(int a1)
{
  int *v1; // edx
  int *v2; // eax
  int v3; // eax

  if ( (*(_BYTE *)(a1 + 30) & 2) != 0 ) /*0x17b81b*/
  {
    pmap_clear_reference(*(_DWORD *)(a1 + 36)); /*0x17b825*/
    v1 = *(int **)a1; /*0x17b82d*/
    v2 = *(int **)(a1 + 4); /*0x17b82f*/
    if ( *(int **)a1 == &vm_page_queue_active ) /*0x17b838*/
      dword_1F6E44 = *(_DWORD *)(a1 + 4); /*0x17b83a*/
    else
      v1[1] = (int)v2; /*0x17b844*/
    if ( v2 == &vm_page_queue_active ) /*0x17b84c*/
      vm_page_queue_active = (int)v1; /*0x17b84e*/
    else
      *v2 = (int)v1; /*0x17b858*/
    v3 = dword_1F64E4; /*0x17b85a*/
    if ( (int *)dword_1F64E4 == &vm_page_queue_inactive ) /*0x17b864*/
      vm_page_queue_inactive = a1; /*0x17b866*/
    else
      *(_DWORD *)dword_1F64E4 = a1; /*0x17b870*/
    *(_DWORD *)(a1 + 4) = v3; /*0x17b872*/
    *(_DWORD *)a1 = &vm_page_queue_inactive; /*0x17b875*/
    dword_1F64E4 = a1; /*0x17b87b*/
    *(_BYTE *)(a1 + 30) = *(_BYTE *)(a1 + 30) & 0xFC | 1; /*0x17b888*/
    --vm_page_active_count; /*0x17b88b*/
    ++vm_page_inactive_count; /*0x17b891*/
    if ( (*(_BYTE *)(a1 + 30) & 0x20) != 0 ) /*0x17b89b*/
    {
      if ( pmap_is_modified(*(_DWORD *)(a1 + 36)) ) /*0x17b8a1*/
        *(_BYTE *)(a1 + 30) &= ~0x20u; /*0x17b8aa*/
    }
    *(_BYTE *)(a1 + 30) = (4 * ((*(_BYTE *)(a1 + 30) & 0x20) == 0)) | *(_BYTE *)(a1 + 30) & 0xFB; /*0x17b8c2*/
  }
}
