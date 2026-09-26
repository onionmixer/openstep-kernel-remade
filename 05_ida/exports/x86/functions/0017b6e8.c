/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b6e8. */
void __cdecl vm_page_wire(int a1)
{
  int *v1; // edx
  int *v2; // eax
  int v3; // edx
  int *v4; // eax
  int v5; // edx
  int *v6; // eax

  if ( !*(_WORD *)(a1 + 28) ) /*0x17b6ee*/
  {
    if ( (*(_BYTE *)(a1 + 30) & 2) != 0 ) /*0x17b6fd*/
    {
      v1 = *(int **)a1; /*0x17b6ff*/
      v2 = *(int **)(a1 + 4); /*0x17b701*/
      if ( *(int **)a1 == &vm_page_queue_active ) /*0x17b70a*/
        dword_1F6E44 = *(_DWORD *)(a1 + 4); /*0x17b70c*/
      else
        v1[1] = (int)v2; /*0x17b714*/
      if ( v2 == &vm_page_queue_active ) /*0x17b71c*/
        vm_page_queue_active = (int)v1; /*0x17b71e*/
      else
        *v2 = (int)v1; /*0x17b728*/
      --vm_page_active_count; /*0x17b72a*/
      *(_BYTE *)(a1 + 30) &= ~2u; /*0x17b730*/
    }
    if ( (*(_BYTE *)(a1 + 30) & 1) != 0 ) /*0x17b738*/
    {
      v3 = *(_DWORD *)a1; /*0x17b73a*/
      v4 = *(int **)(a1 + 4); /*0x17b73c*/
      if ( *(int **)a1 == &vm_page_queue_inactive ) /*0x17b745*/
        dword_1F64E4 = *(_DWORD *)(a1 + 4); /*0x17b747*/
      else
        *(_DWORD *)(v3 + 4) = v4; /*0x17b750*/
      if ( v4 == &vm_page_queue_inactive ) /*0x17b758*/
        vm_page_queue_inactive = v3; /*0x17b75a*/
      else
        *v4 = v3; /*0x17b764*/
      --vm_page_inactive_count; /*0x17b766*/
      *(_BYTE *)(a1 + 30) &= ~1u; /*0x17b76c*/
    }
    if ( (*(_BYTE *)(a1 + 30) & 8) != 0 ) /*0x17b774*/
    {
      v5 = *(_DWORD *)a1; /*0x17b776*/
      v6 = *(int **)(a1 + 4); /*0x17b778*/
      if ( *(int **)a1 == &vm_page_queue_free ) /*0x17b781*/
        dword_1F6E4C = *(_DWORD *)(a1 + 4); /*0x17b783*/
      else
        *(_DWORD *)(v5 + 4) = v6; /*0x17b78c*/
      if ( v6 == &vm_page_queue_free ) /*0x17b794*/
        vm_page_queue_free = v5; /*0x17b796*/
      else
        *v6 = v5; /*0x17b7a0*/
      --vm_page_free_count; /*0x17b7a2*/
      *(_BYTE *)(a1 + 30) &= ~8u; /*0x17b7a8*/
    }
    ++vm_page_wire_count; /*0x17b7ac*/
  }
  ++*(_WORD *)(a1 + 28); /*0x17b7b2*/
}
