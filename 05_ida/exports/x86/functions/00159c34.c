/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159c34. */
int __cdecl thread_self()
{
  thread_act_t v0; // ebx
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // edx

  v0 = active_threads; /*0x159c39*/
  v1 = *(_DWORD *)(active_threads + 12); /*0x159c3f*/
  v2 = (volatile __int32 *)(active_threads + 168); /*0x159c42*/
  do /*0x159c5a*/
  {
    while ( *v2 ) /*0x159c48*/
      ; /*0x159c4a*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159c5a*/
  v3 = *(_DWORD *)(v0 + 176); /*0x159c5c*/
  if ( *(_DWORD *)(v0 + 172) == v3 ) /*0x159c68*/
  {
    do /*0x159c7e*/
    {
      while ( *(_DWORD *)v3 ) /*0x159c6c*/
        ; /*0x159c6e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x159c7e*/
    ++*(_DWORD *)(v3 + 4); /*0x159c80*/
    ++*(_DWORD *)(v3 + 28); /*0x159c83*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x159c88*/
  }
  else
  {
    v3 = ipc_port_copy_send(*(_DWORD *)(v0 + 176)); /*0x159c92*/
  }
  _InterlockedExchange((volatile __int32 *)(v0 + 168), 0); /*0x159c99*/
  return ipc_port_copyout_send_compat(v3, *(_DWORD *)(v1 + 136)); /*0x159caf*/
}
