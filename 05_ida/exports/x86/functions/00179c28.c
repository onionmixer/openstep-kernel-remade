/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179c28. */
int __cdecl vm_object_coalesce(int a1, int a2, int a3, int a4, int a5, int a6)
{
  volatile __int32 *v7; // edx
  _DWORD *v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // eax
  _DWORD *v11; // [esp+Ch] [ebp-8h]

  if ( a2 ) /*0x179c38*/
    return 0; /*0x179c3c*/
  if ( a1 ) /*0x179c46*/
  {
    v7 = (volatile __int32 *)(a1 + 16); /*0x179c4c*/
    do /*0x179c62*/
    {
      while ( *v7 ) /*0x179c50*/
        ; /*0x179c52*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x179c62*/
    vm_object_collapse(a1); /*0x179c65*/
    if ( *(__int16 *)(a1 + 24) > 1 || *(_DWORD *)(a1 + 40) || *(_DWORD *)(a1 + 32) || *(_DWORD *)(a1 + 28) ) /*0x179c80*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179c88*/
      return 0; /*0x179c8d*/
    }
    v8 = *(_DWORD **)a1; /*0x179ca4*/
    if ( a1 != *(_DWORD *)a1 ) /*0x179ca8*/
    {
      do /*0x179cfd*/
      {
        v11 = (_DWORD *)v8[2]; /*0x179caf*/
        v9 = v8[6]; /*0x179cb2*/
        if ( a5 + a3 <= v9 && v9 < a6 + a5 + a3 ) /*0x179cbc*/
        {
          pmap_remove_all(v8[9]); /*0x179cc2*/
          do /*0x179ce5*/
          {
            while ( vm_page_queue_lock ) /*0x179cd3*/
              ; /*0x179cd1*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179ce5*/
          vm_page_free(v8); /*0x179ce8*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x179cf2*/
        }
        v8 = v11; /*0x179cf8*/
      }
      while ( (_DWORD *)a1 != v11 ); /*0x179cfd*/
    }
    v10 = a6 + a5 + a3; /*0x179d05*/
    if ( *(_DWORD *)(a1 + 20) < v10 ) /*0x179d0b*/
      *(_DWORD *)(a1 + 20) = v10; /*0x179d0d*/
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179d12*/
  }
  return 1; /*0x179d1d*/
}
