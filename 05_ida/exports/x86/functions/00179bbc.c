/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179bbc. */
void __cdecl vm_object_page_remove(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  _DWORD *v3; // ebx
  _DWORD *v4; // esi
  unsigned int v5; // eax

  if ( a1 ) /*0x179bc7*/
  {
    v3 = (_DWORD *)*a1; /*0x179bc9*/
    if ( a1 != (_DWORD *)*a1 ) /*0x179bcd*/
    {
      do /*0x179c1c*/
      {
        v4 = (_DWORD *)v3[2]; /*0x179bd0*/
        v5 = v3[6]; /*0x179bd3*/
        if ( a2 <= v5 && a3 > v5 ) /*0x179bde*/
        {
          pmap_remove_all(v3[9]); /*0x179be4*/
          do /*0x179c05*/
          {
            while ( vm_page_queue_lock ) /*0x179bf3*/
              ; /*0x179bf1*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179c05*/
          vm_page_free(v3); /*0x179c08*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x179c12*/
        }
        v3 = v4; /*0x179c18*/
      }
      while ( a1 != v4 ); /*0x179c1c*/
    }
  }
}
