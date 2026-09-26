/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d5b0. */
int __cdecl ipc_port_copyout_receiver(int a1, int a2)
{
  int v3; // ebx
  int v4; // esi

  if ( !a1 || a1 == -1 ) /*0x14d5c2*/
    return 0; /*0x14d5c4*/
  do /*0x14d5da*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d5c8*/
      ; /*0x14d5ca*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d5da*/
  v3 = 0; /*0x14d5dc*/
  if ( *(_DWORD *)(a1 + 12) == a2 ) /*0x14d5e1*/
    v3 = *(_DWORD *)(a1 + 16); /*0x14d5e3*/
  v4 = *(_DWORD *)(a1 + 4) - 1; /*0x14d5e9*/
  *(_DWORD *)(a1 + 4) = v4; /*0x14d5ec*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d5f2*/
  if ( !v4 ) /*0x14d5f6*/
    zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14d60a*/
  return v3; /*0x14d614*/
}
