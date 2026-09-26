/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1598a0. */
int __cdecl retrieve_task_self_fast(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edx

  v1 = (volatile __int32 *)(a1 + 100); /*0x1598a7*/
  do /*0x1598be*/
  {
    while ( *v1 ) /*0x1598ac*/
      ; /*0x1598ae*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1598be*/
  v2 = *(_DWORD *)(a1 + 108); /*0x1598c0*/
  if ( *(_DWORD *)(a1 + 104) == v2 ) /*0x1598c6*/
  {
    do /*0x1598da*/
    {
      while ( *(_DWORD *)v2 ) /*0x1598c8*/
        ; /*0x1598ca*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x1598da*/
    ++*(_DWORD *)(v2 + 4); /*0x1598dc*/
    ++*(_DWORD *)(v2 + 28); /*0x1598df*/
    _InterlockedExchange((volatile __int32 *)v2, 0); /*0x1598e4*/
  }
  else
  {
    v2 = ipc_port_copy_send(*(_DWORD *)(a1 + 108)); /*0x1598ee*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x1598f2*/
  return v2; /*0x1598f7*/
}
