/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15839c. */
__int32 __cdecl ipc_kobject_set(int a1, int a2, int a3)
{
  do /*0x1583b6*/
  {
    while ( *(_DWORD *)a1 ) /*0x1583a4*/
      ; /*0x1583a6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1583b6*/
  *(_DWORD *)(a1 + 8) = a3 | *(_DWORD *)(a1 + 8) & 0xFFFF0000; /*0x1583c3*/
  *(_DWORD *)(a1 + 20) = a2; /*0x1583c9*/
  return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1583d2*/
}
