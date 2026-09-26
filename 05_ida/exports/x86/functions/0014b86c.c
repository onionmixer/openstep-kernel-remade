/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b86c. */
int __cdecl ipc_object_release(int a1)
{
  int v1; // ebx
  int result; // eax

  do /*0x14b886*/
  {
    while ( *(_DWORD *)a1 ) /*0x14b874*/
      ; /*0x14b876*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14b886*/
  v1 = *(_DWORD *)(a1 + 4) - 1; /*0x14b88b*/
  *(_DWORD *)(a1 + 4) = v1; /*0x14b88e*/
  result = v1; /*0x14b891*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14b894*/
  if ( !v1 ) /*0x14b898*/
    return zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14b8ac*/
  return result; /*0x14b8b1*/
}
