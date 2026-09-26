/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1506d8. */
int __cdecl ipc_space_release(int a1)
{
  int v1; // ebx
  int result; // eax

  do /*0x1506f2*/
  {
    while ( *(_DWORD *)a1 ) /*0x1506e0*/
      ; /*0x1506e2*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1506f2*/
  v1 = *(_DWORD *)(a1 + 4) - 1; /*0x1506f7*/
  *(_DWORD *)(a1 + 4) = v1; /*0x1506fa*/
  result = v1; /*0x1506fd*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x150700*/
  if ( !v1 ) /*0x150704*/
    return zfree(ipc_space_zone, a1); /*0x15070e*/
  return result; /*0x150713*/
}
