/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159970. */
int mach_task_self()
{
  int v0; // ebx
  volatile __int32 *v1; // edx
  int v2; // edx

  v0 = *(_DWORD *)(active_threads + 12); /*0x159979*/
  v1 = (volatile __int32 *)(v0 + 100); /*0x15997c*/
  do /*0x159992*/
  {
    while ( *v1 ) /*0x159980*/
      ; /*0x159982*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159992*/
  v2 = *(_DWORD *)(v0 + 108); /*0x159994*/
  if ( *(_DWORD *)(v0 + 104) == v2 ) /*0x15999a*/
  {
    do /*0x1599ae*/
    {
      while ( *(_DWORD *)v2 ) /*0x15999c*/
        ; /*0x15999e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x1599ae*/
    ++*(_DWORD *)(v2 + 4); /*0x1599b0*/
    ++*(_DWORD *)(v2 + 28); /*0x1599b3*/
    _InterlockedExchange((volatile __int32 *)v2, 0); /*0x1599b8*/
  }
  else
  {
    v2 = ipc_port_copy_send(*(_DWORD *)(v0 + 108)); /*0x1599c2*/
  }
  _InterlockedExchange((volatile __int32 *)(v0 + 100), 0); /*0x1599c9*/
  return ipc_port_copyout_send(v2, *(_DWORD *)(v0 + 136)); /*0x1599d9*/
}
