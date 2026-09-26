/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173ebc. */
int __cdecl sub_173EBC(int a1, int a2, int a3, int a4)
{
  int v5; // esi
  int v6; // ebx
  volatile __int32 *v8; // edx
  volatile __int32 *v9; // [esp+Ch] [ebp-4h]

  v5 = a3; /*0x173ec8*/
  if ( a3 ) /*0x173ecd*/
  {
    v9 = (volatile __int32 *)(a1 + 16); /*0x173ed9*/
    do /*0x173fa4*/
    {
      do /*0x173ef4*/
      {
        while ( *v9 ) /*0x173edf*/
          ; /*0x173ee1*/
      }
      while ( _InterlockedExchange(v9, 1) == 1 ); /*0x173ef4*/
      while ( 1 ) /*0x173f04*/
      {
        v6 = vm_page_alloc_sequential(a1, a2, 1); /*0x173f04*/
        if ( v6 ) /*0x173f0b*/
          break; /*0x173f0b*/
        _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x173f12*/
        if ( !a4 ) /*0x173f19*/
          return 0; /*0x173f1d*/
        do /*0x173f3d*/
        {
          while ( vm_pages_needed_lock ) /*0x173f2b*/
            ; /*0x173f29*/
        }
        while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x173f3d*/
        thread_wakeup_prim(&vm_pages_needed, 0, 0); /*0x173f48*/
        thread_sleep(&vm_page_free_count, &vm_pages_needed_lock, 0); /*0x173f59*/
        v8 = (volatile __int32 *)(a1 + 16); /*0x173f61*/
        do /*0x173f7a*/
        {
          while ( *v8 ) /*0x173f68*/
            ; /*0x173f6a*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x173f7a*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x173f89*/
      vm_page_zero_fill(v6); /*0x173f8d*/
      *(_BYTE *)(v6 + 32) &= ~1u; /*0x173f92*/
      v5 -= page_size; /*0x173f9b*/
      a2 += page_size; /*0x173f9d*/
    }
    while ( v5 ); /*0x173fa4*/
  }
  return 1; /*0x173fb2*/
}
