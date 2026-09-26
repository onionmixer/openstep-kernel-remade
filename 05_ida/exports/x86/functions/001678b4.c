/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1678b4. */
int thread_halt_self()
{
  int v0; // ebx
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v4; // ecx
  volatile __int32 *v5; // edx
  int v6; // [esp-14h] [ebp-1Ch]

  v0 = active_threads; /*0x1678b9*/
  if ( (*(_BYTE *)(active_threads + 380) & 2) != 0 ) /*0x1678c6*/
  {
    ipc_thread_terminate(active_threads); /*0x1678cd*/
    thread_hold(v0); /*0x1678d3*/
    v1 = splsched(); /*0x1678dd*/
    do /*0x1678fd*/
    {
      while ( reaper_lock ) /*0x1678eb*/
        ; /*0x1678e9*/
    }
    while ( _InterlockedExchange(&reaper_lock, 1) == 1 ); /*0x1678fd*/
    *(_DWORD *)v0 = &reaper_queue; /*0x1678ff*/
    *(_DWORD *)(v0 + 4) = dword_1E979C; /*0x16790b*/
    **(_DWORD **)(v0 + 4) = v0; /*0x167911*/
    dword_1E979C = v0; /*0x167913*/
    _InterlockedExchange(&reaper_lock, 0); /*0x16791b*/
    v2 = (volatile __int32 *)(v0 + 32); /*0x167921*/
    do /*0x167936*/
    {
      while ( *v2 ) /*0x167924*/
        ; /*0x167926*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x167936*/
    *(_BYTE *)(v0 + 76) |= 0x10u; /*0x167938*/
    _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x16793e*/
    splx(v1); /*0x167942*/
    thread_wakeup_prim((int)&reaper_queue, 0, 0); /*0x167950*/
    return thread_block_with_continuation((int)walking_zombie); /*0x16795a*/
  }
  else
  {
    v4 = splsched(); /*0x167961*/
    v5 = (volatile __int32 *)(v0 + 32); /*0x167963*/
    do /*0x16797a*/
    {
      while ( *v5 ) /*0x167968*/
        ; /*0x16796a*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16797a*/
    *(_BYTE *)(v0 + 76) |= 0x10u; /*0x16797c*/
    *(_DWORD *)(v0 + 380) &= ~1u; /*0x167980*/
    _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x167989*/
    splx(v4); /*0x16798d*/
    return thread_block_with_continuation(v6); /*0x167997*/
  }
}
