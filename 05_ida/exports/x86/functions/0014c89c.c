/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c89c. */
__int32 __cdecl ipc_port_clear_receiver(int a1)
{
  int v1; // ebx
  int v2; // eax
  volatile __int32 *v3; // edx
  volatile __int32 *v4; // edx

  v1 = *(_DWORD *)(a1 + 48); /*0x14c8a4*/
  if ( v1 ) /*0x14c8a9*/
  {
    do /*0x14c8be*/
    {
      while ( *(_DWORD *)v1 ) /*0x14c8ac*/
        ; /*0x14c8ae*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x14c8be*/
    ipc_pset_remove(v1, a1); /*0x14c8c2*/
    v2 = *(_DWORD *)(v1 + 4); /*0x14c8ca*/
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14c8cf*/
    if ( !v2 ) /*0x14c8d3*/
      zfree(ipc_object_zones[*(_WORD *)(v1 + 10) & 0x7FFF], v1); /*0x14c8e7*/
  }
  else
  {
    v3 = (volatile __int32 *)(a1 + 64); /*0x14c8f0*/
    do /*0x14c906*/
    {
      while ( *v3 ) /*0x14c8f4*/
        ; /*0x14c8f6*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14c906*/
    ipc_mqueue_changed(a1 + 64, 268451849); /*0x14c911*/
    _InterlockedExchange((volatile __int32 *)(a1 + 64), 0); /*0x14c918*/
  }
  *(_DWORD *)(a1 + 24) = 0; /*0x14c91b*/
  v4 = (volatile __int32 *)(a1 + 64); /*0x14c922*/
  do /*0x14c93a*/
  {
    while ( *v4 ) /*0x14c928*/
      ; /*0x14c92a*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14c93a*/
  *(_DWORD *)(a1 + 52) = 0; /*0x14c93c*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 64), 0); /*0x14c94b*/
}
