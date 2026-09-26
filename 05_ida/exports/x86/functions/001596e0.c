/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1596e0. */
__int32 __cdecl ipc_thread_enable(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // eax

  v1 = (volatile __int32 *)(a1 + 168); /*0x1596e7*/
  do /*0x159702*/
  {
    while ( *v1 ) /*0x1596f0*/
      ; /*0x1596f2*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159702*/
  v2 = *(_DWORD *)(a1 + 172); /*0x159704*/
  if ( v2 ) /*0x15970c*/
    ipc_kobject_set(v2, a1, 1); /*0x159712*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x15971f*/
}
