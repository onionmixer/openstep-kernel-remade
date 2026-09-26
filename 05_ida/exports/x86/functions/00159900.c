/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159900. */
int __cdecl retrieve_thread_self_fast(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edx

  v1 = (volatile __int32 *)(a1 + 168); /*0x159907*/
  do /*0x159922*/
  {
    while ( *v1 ) /*0x159910*/
      ; /*0x159912*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159922*/
  v2 = *(_DWORD *)(a1 + 176); /*0x159924*/
  if ( *(_DWORD *)(a1 + 172) == v2 ) /*0x159930*/
  {
    do /*0x159946*/
    {
      while ( *(_DWORD *)v2 ) /*0x159934*/
        ; /*0x159936*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x159946*/
    ++*(_DWORD *)(v2 + 4); /*0x159948*/
    ++*(_DWORD *)(v2 + 28); /*0x15994b*/
    _InterlockedExchange((volatile __int32 *)v2, 0); /*0x159950*/
  }
  else
  {
    v2 = ipc_port_copy_send(*(_DWORD *)(a1 + 176)); /*0x15995a*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x15995e*/
  return v2; /*0x159966*/
}
