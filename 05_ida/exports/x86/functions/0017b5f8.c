/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b5f8. */
void __cdecl vm_page_addfree(int a1)
{
  int *v1; // edx
  int *v2; // eax
  int v3; // edx
  int *v4; // eax
  int v5; // edx
  int v6; // eax

  if ( (*(_BYTE *)(a1 + 30) & 2) != 0 ) /*0x17b603*/
  {
    v1 = *(int **)a1; /*0x17b605*/
    v2 = *(int **)(a1 + 4); /*0x17b607*/
    if ( *(int **)a1 == &vm_page_queue_active ) /*0x17b610*/
      dword_1F6E44 = *(_DWORD *)(a1 + 4); /*0x17b612*/
    else
      v1[1] = (int)v2; /*0x17b61c*/
    if ( v2 == &vm_page_queue_active ) /*0x17b624*/
      vm_page_queue_active = (int)v1; /*0x17b626*/
    else
      *v2 = (int)v1; /*0x17b630*/
    *(_BYTE *)(a1 + 30) &= ~2u; /*0x17b632*/
    --vm_page_active_count; /*0x17b636*/
  }
  if ( (*(_BYTE *)(a1 + 30) & 1) != 0 ) /*0x17b640*/
  {
    v3 = *(_DWORD *)a1; /*0x17b642*/
    v4 = *(int **)(a1 + 4); /*0x17b644*/
    if ( *(int **)a1 == &vm_page_queue_inactive ) /*0x17b64d*/
      dword_1F64E4 = *(_DWORD *)(a1 + 4); /*0x17b64f*/
    else
      *(_DWORD *)(v3 + 4) = v4; /*0x17b658*/
    if ( v4 == &vm_page_queue_inactive ) /*0x17b660*/
      vm_page_queue_inactive = v3; /*0x17b662*/
    else
      *v4 = v3; /*0x17b66c*/
    *(_BYTE *)(a1 + 30) &= ~1u; /*0x17b66e*/
    --vm_page_inactive_count; /*0x17b672*/
  }
  if ( (*(_BYTE *)(a1 + 32) & 8) == 0 ) /*0x17b67c*/
  {
    v5 = splimp(); /*0x17b683*/
    do /*0x17b6a1*/
    {
      while ( vm_page_queue_free_lock ) /*0x17b68f*/
        ; /*0x17b68d*/
    }
    while ( _InterlockedExchange(&vm_page_queue_free_lock, 1) == 1 ); /*0x17b6a1*/
    v6 = dword_1F6E4C; /*0x17b6a3*/
    if ( (int *)dword_1F6E4C == &vm_page_queue_free ) /*0x17b6ad*/
      vm_page_queue_free = a1; /*0x17b6af*/
    else
      *(_DWORD *)dword_1F6E4C = a1; /*0x17b6b8*/
    *(_DWORD *)(a1 + 4) = v6; /*0x17b6ba*/
    *(_DWORD *)a1 = &vm_page_queue_free; /*0x17b6bd*/
    dword_1F6E4C = a1; /*0x17b6c3*/
    *(_BYTE *)(a1 + 30) |= 8u; /*0x17b6c9*/
    ++vm_page_free_count; /*0x17b6cd*/
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x17b6d5*/
    splx(v5); /*0x17b6dc*/
  }
}
