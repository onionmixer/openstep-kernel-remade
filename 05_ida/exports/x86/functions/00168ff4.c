/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168ff4. */
void __noreturn swapin_thread_continue()
{
  int v0; // esi
  int *v1; // edx
  int *v2; // ebx
  void *v3; // esp
  int v4; // esi
  volatile __int32 *v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  while ( 1 ) /*0x169001*/
  {
    v0 = splsched(v8, v9); /*0x169001*/
    do /*0x16901d*/
    {
      while ( swapper_lock_data ) /*0x16900b*/
        ; /*0x169009*/
    }
    while ( _InterlockedExchange(&swapper_lock_data, 1) == 1 ); /*0x16901d*/
    while ( 1 ) /*0x169020*/
    {
      v1 = (int *)swapin_queue; /*0x169020*/
      if ( (int *)swapin_queue == &swapin_queue ) /*0x16902c*/
        break; /*0x16902c*/
      *(_DWORD *)(*(_DWORD *)swapin_queue + 4) = &swapin_queue; /*0x169034*/
      swapin_queue = *v1; /*0x16903d*/
      v2 = v1; /*0x169043*/
      if ( !v1 ) /*0x169047*/
        break; /*0x169047*/
      _InterlockedExchange(&swapper_lock_data, 0); /*0x16904f*/
      v3 = alloca(splx(v0)); /*0x169064*/
      v4 = splsched(v2, thread_continue); /*0x16906e*/
      v5 = v2 + 8; /*0x169070*/
      do /*0x16908a*/
      {
        while ( *v5 ) /*0x169078*/
          ; /*0x16907a*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16908a*/
      v6 = v2[19]; /*0x16908c*/
      v7 = v6; /*0x16908f*/
      BYTE1(v7) = BYTE1(v6) & 0xFC; /*0x169091*/
      v2[19] = v7; /*0x169094*/
      if ( (v6 & 4) != 0 ) /*0x169099*/
        thread_setrun((char **)v2, 1); /*0x16909e*/
      _InterlockedExchange(v2 + 8, 0); /*0x1690a8*/
      splx(v4); /*0x1690ac*/
      v0 = splsched(v8, v9); /*0x1690b9*/
      do /*0x1690d5*/
      {
        while ( swapper_lock_data ) /*0x1690c3*/
          ; /*0x1690c1*/
      }
      while ( _InterlockedExchange(&swapper_lock_data, 1) == 1 ); /*0x1690d5*/
    }
    assert_wait((int)&swapin_queue, 0); /*0x1690e3*/
    _InterlockedExchange(&swapper_lock_data, 0); /*0x1690ed*/
    splx(v0); /*0x1690f4*/
    thread_block_with_continuation((int)swapin_thread_continue); /*0x1690fe*/
  }
}
