/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b7bc. */
__int16 __cdecl vm_page_unwire(int a1)
{
  int v1; // eax

  LOWORD(v1) = *(_WORD *)(a1 + 28); /*0x17b7c2*/
  *(_WORD *)(a1 + 28) = v1 - 1; /*0x17b7ca*/
  if ( (_WORD)v1 == 1 ) /*0x17b7d2*/
  {
    v1 = dword_1F6E44; /*0x17b7d4*/
    if ( (int *)dword_1F6E44 == &vm_page_queue_active ) /*0x17b7de*/
      vm_page_queue_active = a1; /*0x17b7e0*/
    else
      *(_DWORD *)dword_1F6E44 = a1; /*0x17b7e8*/
    *(_DWORD *)(a1 + 4) = v1; /*0x17b7ea*/
    *(_DWORD *)a1 = &vm_page_queue_active; /*0x17b7ed*/
    dword_1F6E44 = a1; /*0x17b7f3*/
    ++vm_page_active_count; /*0x17b7f9*/
    *(_BYTE *)(a1 + 30) |= 2u; /*0x17b7ff*/
    --vm_page_wire_count; /*0x17b803*/
  }
  return v1; /*0x17b80b*/
}
