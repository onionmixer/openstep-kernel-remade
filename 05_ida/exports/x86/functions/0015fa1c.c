/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15fa1c. */
__int32 __cdecl vno_flush(__int32 *a1, int a2, int a3)
{
  __int32 result; // eax
  int v4; // esi
  volatile __int32 *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int v8; // eax
  char v9; // dl
  volatile __int32 *v10; // edx

  result = *a1; /*0x15fa28*/
  v4 = *(_DWORD *)(*a1 + 36); /*0x15fa2a*/
  if ( v4 ) /*0x15fa2f*/
  {
    do /*0x15fa51*/
    {
      while ( vm_page_queue_lock ) /*0x15fa3f*/
        ; /*0x15fa3d*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fa51*/
    v5 = (volatile __int32 *)(v4 + 16); /*0x15fa53*/
    do /*0x15fa6a*/
    {
      while ( *v5 ) /*0x15fa58*/
        ; /*0x15fa5a*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15fa6a*/
    v6 = ~page_mask & (page_mask + a2 + a3); /*0x15fa7c*/
    v7 = ~page_mask & a2; /*0x15fa7e*/
    while ( 1 ) /*0x15fa94*/
    {
      while ( 1 ) /*0x15fa80*/
      {
        if ( v7 >= v6 ) /*0x15fa82*/
        {
          _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x15fb12*/
          return _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fb17*/
        }
        v8 = vm_page_lookup(v4, v7); /*0x15fa8a*/
        if ( v8 ) /*0x15fa94*/
          break; /*0x15fa94*/
LABEL_19:
        v7 += page_size; /*0x15fb05*/
      }
      v9 = *(_BYTE *)(v8 + 32); /*0x15fa96*/
      if ( (v9 & 1) == 0 ) /*0x15fa9c*/
      {
        vm_page_free(v8); /*0x15fafd*/
        goto LABEL_19; /*0x15fafd*/
      }
      *(_BYTE *)(v8 + 32) = v9 | 2; /*0x15faa1*/
      assert_wait(v8, 0); /*0x15faa7*/
      _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x15fab1*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fab6*/
      thread_block(); /*0x15fabc*/
      do /*0x15fadd*/
      {
        while ( vm_page_queue_lock ) /*0x15facb*/
          ; /*0x15fac9*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fadd*/
      v10 = (volatile __int32 *)(v4 + 16); /*0x15fadf*/
      do /*0x15faf6*/
      {
        while ( *v10 ) /*0x15fae4*/
          ; /*0x15fae6*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x15faf6*/
    }
  }
  return result; /*0x15fb20*/
}
