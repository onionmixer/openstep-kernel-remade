/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1594dc. */
__int32 __cdecl ipc_task_enable(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // eax

  v1 = (volatile __int32 *)(a1 + 100); /*0x1594e3*/
  do /*0x1594fa*/
  {
    while ( *v1 ) /*0x1594e8*/
      ; /*0x1594ea*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1594fa*/
  v2 = *(_DWORD *)(a1 + 104); /*0x1594fc*/
  if ( v2 ) /*0x159501*/
    ipc_kobject_set(v2, a1, 2); /*0x159507*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x159511*/
}
