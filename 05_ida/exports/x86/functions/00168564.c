/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168564. */
void __noreturn reaper_thread_continue()
{
  int v0; // esi
  int *v1; // edx
  int v2; // ebx
  int v3; // edi
  volatile __int32 *v4; // edx
  volatile __int32 *v5; // esi
  int v6; // [esp+Ch] [ebp-4h]

  while ( 1 ) /*0x168575*/
  {
    v0 = splsched(); /*0x168575*/
    do /*0x168591*/
    {
      while ( reaper_lock ) /*0x16857f*/
        ; /*0x16857d*/
    }
    while ( _InterlockedExchange(&reaper_lock, 1) == 1 ); /*0x168591*/
    while ( 1 ) /*0x168594*/
    {
      v1 = (int *)reaper_queue; /*0x168594*/
      if ( (int *)reaper_queue == &reaper_queue ) /*0x1685a0*/
        break; /*0x1685a0*/
      *(_DWORD *)(*(_DWORD *)reaper_queue + 4) = &reaper_queue; /*0x1685a8*/
      reaper_queue = *v1; /*0x1685b1*/
      v2 = (int)v1; /*0x1685b7*/
      if ( !v1 ) /*0x1685bb*/
        break; /*0x1685bb*/
      _InterlockedExchange(&reaper_lock, 0); /*0x1685c3*/
      splx(v0); /*0x1685ca*/
      if ( active_threads == v2 ) /*0x1685d8*/
        panic(aThreadDowait); /*0x1685df*/
      v3 = 0; /*0x1685e7*/
      v6 = splsched(); /*0x1685ee*/
      v4 = (volatile __int32 *)(v2 + 32); /*0x1685f1*/
      do /*0x168606*/
      {
        while ( *v4 ) /*0x1685f4*/
          ; /*0x1685f6*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x168606*/
      v5 = (volatile __int32 *)(v2 + 32); /*0x168608*/
      while ( 2 ) /*0x16861e*/
      {
        switch ( *(_DWORD *)(v2 + 76) & 0xF ) /*0x16861e*/
        {
          case 6: /*0x16861e*/
            if ( !rem_runq((_DWORD *)v2) ) /*0x168661*/
              goto LABEL_14; /*0x16866b*/
            *(_DWORD *)(v2 + 76) &= ~4u; /*0x168700*/
            v3 = *(_DWORD *)(v2 + 72); /*0x168704*/
            *(_DWORD *)(v2 + 72) = 0; /*0x168707*/
            goto LABEL_18; /*0x16870e*/
          case 7: /*0x16861e*/
          case 0xB: /*0x16861e*/
          case 0xE: /*0x16861e*/
          case 0xF: /*0x16861e*/
LABEL_14:
            *(_DWORD *)(v2 + 72) = 1; /*0x168671*/
            thread_sleep(v2 + 72, (volatile __int32 *)(v2 + 32), 1); /*0x16867f*/
            do /*0x16869e*/
            {
              while ( *v5 ) /*0x16868c*/
                ; /*0x16868e*/
            }
            while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16869e*/
            continue; /*0x16869e*/
          default:
LABEL_18:
            _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x1686a8*/
            splx(v6); /*0x1686b1*/
            if ( v3 ) /*0x1686bb*/
              thread_wakeup_prim(v2 + 72, 0, 0); /*0x1686c5*/
            thread_deallocate(v2); /*0x1686ce*/
            v0 = splsched(); /*0x1686d8*/
            do /*0x1686f9*/
            {
              while ( reaper_lock ) /*0x1686e7*/
                ; /*0x1686e5*/
            }
            while ( _InterlockedExchange(&reaper_lock, 1) == 1 ); /*0x1686f9*/
            break; /*0x1686f9*/
        }
        break;
      }
    }
    assert_wait((int)&reaper_queue, 0); /*0x168717*/
    _InterlockedExchange(&reaper_lock, 0); /*0x168721*/
    splx(v0); /*0x168728*/
    thread_block_with_continuation((int)reaper_thread_continue); /*0x168732*/
  }
}
