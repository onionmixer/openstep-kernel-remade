/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b8cc. */
void __cdecl vm_page_activate(int a1)
{
  int *v1; // edx
  int *v2; // eax
  int v3; // edx
  int *v4; // eax
  int v5; // eax

  if ( (*(_BYTE *)(a1 + 30) & 1) != 0 ) /*0x17b8d7*/
  {
    v1 = *(int **)a1; /*0x17b8d9*/
    v2 = *(int **)(a1 + 4); /*0x17b8db*/
    if ( *(int **)a1 == &vm_page_queue_inactive ) /*0x17b8e4*/
      dword_1F64E4 = *(_DWORD *)(a1 + 4); /*0x17b8e6*/
    else
      v1[1] = (int)v2; /*0x17b8f0*/
    if ( v2 == &vm_page_queue_inactive ) /*0x17b8f8*/
      vm_page_queue_inactive = (int)v1; /*0x17b8fa*/
    else
      *v2 = (int)v1; /*0x17b904*/
    --vm_page_inactive_count; /*0x17b906*/
    *(_BYTE *)(a1 + 30) &= ~1u; /*0x17b90c*/
  }
  if ( (*(_BYTE *)(a1 + 30) & 8) != 0 ) /*0x17b914*/
  {
    v3 = *(_DWORD *)a1; /*0x17b916*/
    v4 = *(int **)(a1 + 4); /*0x17b918*/
    if ( *(int **)a1 == &vm_page_queue_free ) /*0x17b921*/
      dword_1F6E4C = *(_DWORD *)(a1 + 4); /*0x17b923*/
    else
      *(_DWORD *)(v3 + 4) = v4; /*0x17b92c*/
    if ( v4 == &vm_page_queue_free ) /*0x17b934*/
      vm_page_queue_free = v3; /*0x17b936*/
    else
      *v4 = v3; /*0x17b940*/
    --vm_page_free_count; /*0x17b942*/
    *(_BYTE *)(a1 + 30) &= ~8u; /*0x17b948*/
  }
  if ( !*(_WORD *)(a1 + 28) ) /*0x17b94c*/
  {
    if ( (*(_BYTE *)(a1 + 30) & 2) != 0 ) /*0x17b957*/
      panic(aVmPageActivate); /*0x17b95e*/
    v5 = dword_1F6E44; /*0x17b963*/
    if ( (int *)dword_1F6E44 == &vm_page_queue_active ) /*0x17b96d*/
      vm_page_queue_active = a1; /*0x17b96f*/
    else
      *(_DWORD *)dword_1F6E44 = a1; /*0x17b978*/
    *(_DWORD *)(a1 + 4) = v5; /*0x17b97a*/
    *(_DWORD *)a1 = &vm_page_queue_active; /*0x17b97d*/
    dword_1F6E44 = a1; /*0x17b983*/
    *(_BYTE *)(a1 + 30) |= 2u; /*0x17b989*/
    ++vm_page_active_count; /*0x17b98d*/
  }
}
