/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179084. */
__int32 __cdecl vm_object_deactivate_pages(_DWORD *a1)
{
  _DWORD *v1; // edx
  _DWORD *v2; // ebx
  __int32 result; // eax

  v1 = (_DWORD *)*a1; /*0x17908c*/
  if ( a1 != (_DWORD *)*a1 ) /*0x179090*/
  {
    do /*0x1790ce*/
    {
      v2 = (_DWORD *)v1[2]; /*0x179094*/
      do /*0x1790b1*/
      {
        while ( vm_page_queue_lock ) /*0x17909f*/
          ; /*0x17909d*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1790b1*/
      if ( (*((_BYTE *)v1 + 30) & 1) == 0 ) /*0x1790b7*/
        vm_page_deactivate(v1); /*0x1790ba*/
      result = _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1790c4*/
      v1 = v2; /*0x1790ca*/
    }
    while ( a1 != v2 ); /*0x1790ce*/
  }
  return result; /*0x1790d3*/
}
