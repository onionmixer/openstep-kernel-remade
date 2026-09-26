/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159b58. */
int __cdecl task_self()
{
  int v0; // ebx
  volatile __int32 *v1; // edx
  int v2; // edx

  v0 = *(_DWORD *)(active_threads + 12); /*0x159b61*/
  v1 = (volatile __int32 *)(v0 + 100); /*0x159b64*/
  do /*0x159b7a*/
  {
    while ( *v1 ) /*0x159b68*/
      ; /*0x159b6a*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159b7a*/
  v2 = *(_DWORD *)(v0 + 108); /*0x159b7c*/
  if ( *(_DWORD *)(v0 + 104) == v2 ) /*0x159b82*/
  {
    do /*0x159b96*/
    {
      while ( *(_DWORD *)v2 ) /*0x159b84*/
        ; /*0x159b86*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x159b96*/
    ++*(_DWORD *)(v2 + 4); /*0x159b98*/
    ++*(_DWORD *)(v2 + 28); /*0x159b9b*/
    _InterlockedExchange((volatile __int32 *)v2, 0); /*0x159ba0*/
  }
  else
  {
    v2 = ipc_port_copy_send(*(_DWORD *)(v0 + 108)); /*0x159baa*/
  }
  _InterlockedExchange((volatile __int32 *)(v0 + 100), 0); /*0x159bb1*/
  return ipc_port_copyout_send_compat(v2, *(_DWORD *)(v0 + 136)); /*0x159bc1*/
}
