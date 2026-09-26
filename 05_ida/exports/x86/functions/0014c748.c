/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c748. */
int __cdecl ipc_port_lock_mqueue(int a1)
{
  int v1; // ebx
  volatile __int32 *v2; // edx
  int v4; // eax
  volatile __int32 *v5; // edx

  if ( *(_DWORD *)(a1 + 48) ) /*0x14c750*/
  {
    v1 = *(_DWORD *)(a1 + 48); /*0x14c757*/
    do /*0x14c76e*/
    {
      while ( *(_DWORD *)v1 ) /*0x14c75c*/
        ; /*0x14c75e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x14c76e*/
    if ( *(int *)(v1 + 8) < 0 ) /*0x14c774*/
    {
      v2 = (volatile __int32 *)(v1 + 16); /*0x14c776*/
      do /*0x14c78e*/
      {
        while ( *v2 ) /*0x14c77c*/
          ; /*0x14c77e*/
      }
      while ( _InterlockedExchange(v2, 1) == 1 ); /*0x14c78e*/
      _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14c792*/
      return v1 + 16; /*0x14c797*/
    }
    ipc_pset_remove(v1, a1); /*0x14c79e*/
    v4 = *(_DWORD *)(v1 + 4); /*0x14c7a6*/
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14c7ab*/
    if ( !v4 ) /*0x14c7af*/
      zfree(ipc_object_zones[*(_WORD *)(v1 + 10) & 0x7FFF], v1); /*0x14c7c3*/
  }
  v5 = (volatile __int32 *)(a1 + 64); /*0x14c7c8*/
  do /*0x14c7de*/
  {
    while ( *v5 ) /*0x14c7cc*/
      ; /*0x14c7ce*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14c7de*/
  return a1 + 64; /*0x14c7e6*/
}
