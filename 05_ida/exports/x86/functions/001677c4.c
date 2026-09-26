/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1677c4. */
int thread_halt_self_with_continuation()
{
  int v0; // ebx
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v4; // ecx
  volatile __int32 *v5; // edx
  int v6; // [esp-14h] [ebp-1Ch]

  v0 = active_threads; /*0x1677c9*/
  if ( (*(_BYTE *)(active_threads + 380) & 2) != 0 ) /*0x1677d6*/
  {
    ipc_thread_terminate(active_threads); /*0x1677dd*/
    thread_hold(v0); /*0x1677e3*/
    v1 = splsched(); /*0x1677ed*/
    do /*0x16780d*/
    {
      while ( reaper_lock ) /*0x1677fb*/
        ; /*0x1677f9*/
    }
    while ( _InterlockedExchange(&reaper_lock, 1) == 1 ); /*0x16780d*/
    *(_DWORD *)v0 = &reaper_queue; /*0x16780f*/
    *(_DWORD *)(v0 + 4) = dword_1E979C; /*0x16781b*/
    **(_DWORD **)(v0 + 4) = v0; /*0x167821*/
    dword_1E979C = v0; /*0x167823*/
    _InterlockedExchange(&reaper_lock, 0); /*0x16782b*/
    v2 = (volatile __int32 *)(v0 + 32); /*0x167831*/
    do /*0x167846*/
    {
      while ( *v2 ) /*0x167834*/
        ; /*0x167836*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x167846*/
    *(_BYTE *)(v0 + 76) |= 0x10u; /*0x167848*/
    _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x16784e*/
    splx(v1); /*0x167852*/
    thread_wakeup_prim((int)&reaper_queue, 0, 0); /*0x167860*/
    return thread_block_with_continuation((int)walking_zombie); /*0x16786a*/
  }
  else
  {
    v4 = splsched(); /*0x167871*/
    v5 = (volatile __int32 *)(v0 + 32); /*0x167873*/
    do /*0x16788a*/
    {
      while ( *v5 ) /*0x167878*/
        ; /*0x16787a*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16788a*/
    *(_BYTE *)(v0 + 76) |= 0x10u; /*0x16788c*/
    *(_DWORD *)(v0 + 380) &= ~1u; /*0x167890*/
    _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x167899*/
    splx(v4); /*0x16789d*/
    return thread_block_with_continuation(v6); /*0x1678a6*/
  }
}
