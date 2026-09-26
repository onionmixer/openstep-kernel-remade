/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d0dc. */
int __cdecl ipc_port_make_sonce(int a1)
{
  do /*0x14d0f6*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d0e4*/
      ; /*0x14d0e6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d0f6*/
  ++*(_DWORD *)(a1 + 32); /*0x14d0f8*/
  ++*(_DWORD *)(a1 + 4); /*0x14d0fb*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d100*/
  return a1; /*0x14d106*/
}
