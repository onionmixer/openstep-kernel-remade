/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167184. */
void __cdecl thread_deallocate_interrupt(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v3; // esi

  if ( a1 ) /*0x16718e*/
  {
    v1 = splsched(); /*0x167199*/
    v2 = (volatile __int32 *)(a1 + 32); /*0x16719b*/
    do /*0x1671b2*/
    {
      while ( *v2 ) /*0x1671a0*/
        ; /*0x1671a2*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1671b2*/
    v3 = *(_DWORD *)(a1 + 36) - 1; /*0x1671b7*/
    *(_DWORD *)(a1 + 36) = v3; /*0x1671ba*/
    if ( v3 <= 0 ) /*0x1671c0*/
    {
      *(_DWORD *)(a1 + 36) = 1; /*0x1671d0*/
      do /*0x1671f1*/
      {
        while ( reaper_lock ) /*0x1671df*/
          ; /*0x1671dd*/
      }
      while ( _InterlockedExchange(&reaper_lock, 1) == 1 ); /*0x1671f1*/
      *(_DWORD *)a1 = &reaper_queue; /*0x1671f3*/
      *(_DWORD *)(a1 + 4) = dword_1E979C; /*0x1671ff*/
      **(_DWORD **)(a1 + 4) = a1; /*0x167205*/
      dword_1E979C = a1; /*0x167207*/
      _InterlockedExchange(&reaper_lock, 0); /*0x16720f*/
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167217*/
      splx(v1); /*0x16721b*/
      thread_wakeup_prim((int)&reaper_queue, 0, 0); /*0x167229*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1671c4*/
      splx(v1); /*0x1671c8*/
    }
  }
}
