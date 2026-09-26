/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1506b0. */
__int32 __cdecl ipc_space_reference(int a1)
{
  do /*0x1506ca*/
  {
    while ( *(_DWORD *)a1 ) /*0x1506b8*/
      ; /*0x1506ba*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1506ca*/
  ++*(_DWORD *)(a1 + 4); /*0x1506cc*/
  return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1506d5*/
}
