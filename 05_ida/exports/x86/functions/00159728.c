/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159728. */
__int32 __cdecl ipc_thread_disable(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // eax

  v1 = (volatile __int32 *)(a1 + 168); /*0x15972f*/
  do /*0x15974a*/
  {
    while ( *v1 ) /*0x159738*/
      ; /*0x15973a*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15974a*/
  v2 = *(_DWORD *)(a1 + 172); /*0x15974c*/
  if ( v2 ) /*0x159754*/
    ipc_kobject_set(v2, 0, 0); /*0x15975b*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x159768*/
}
