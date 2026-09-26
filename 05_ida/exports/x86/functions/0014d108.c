/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d108. */
__int32 __cdecl ipc_port_release_sonce(int a1)
{
  int v1; // eax
  __int32 result; // eax

  do /*0x14d122*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d110*/
      ; /*0x14d112*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d122*/
  v1 = *(_DWORD *)(a1 + 4); /*0x14d124*/
  *(_DWORD *)(a1 + 4) = v1 - 1; /*0x14d12a*/
  if ( *(int *)(a1 + 8) < 0 ) /*0x14d131*/
  {
    --*(_DWORD *)(a1 + 32); /*0x14d158*/
    return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d15d*/
  }
  else
  {
    result = v1 - 1; /*0x14d133*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d136*/
    if ( !result ) /*0x14d13a*/
      return zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14d14e*/
  }
  return result; /*0x14d15f*/
}
