/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1599e0. */
mach_port_t mach_thread_self(void)
{
  thread_act_t v0; // ebx
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // edx

  v0 = active_threads; /*0x1599e5*/
  v1 = *(_DWORD *)(active_threads + 12); /*0x1599eb*/
  v2 = (volatile __int32 *)(active_threads + 168); /*0x1599ee*/
  do /*0x159a06*/
  {
    while ( *v2 ) /*0x1599f4*/
      ; /*0x1599f6*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159a06*/
  v3 = *(_DWORD *)(v0 + 176); /*0x159a08*/
  if ( *(_DWORD *)(v0 + 172) == v3 ) /*0x159a14*/
  {
    do /*0x159a2a*/
    {
      while ( *(_DWORD *)v3 ) /*0x159a18*/
        ; /*0x159a1a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x159a2a*/
    ++*(_DWORD *)(v3 + 4); /*0x159a2c*/
    ++*(_DWORD *)(v3 + 28); /*0x159a2f*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x159a34*/
  }
  else
  {
    v3 = ipc_port_copy_send(*(_DWORD *)(v0 + 176)); /*0x159a3e*/
  }
  _InterlockedExchange((volatile __int32 *)(v0 + 168), 0); /*0x159a45*/
  return ipc_port_copyout_send(v3, *(_DWORD *)(v1 + 136)); /*0x159a5b*/
}
