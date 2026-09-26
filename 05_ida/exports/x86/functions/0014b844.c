/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b844. */
__int32 __cdecl ipc_object_reference(int a1)
{
  do /*0x14b85e*/
  {
    while ( *(_DWORD *)a1 ) /*0x14b84c*/
      ; /*0x14b84e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14b85e*/
  ++*(_DWORD *)(a1 + 4); /*0x14b860*/
  return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14b869*/
}
