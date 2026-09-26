/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159518. */
__int32 __cdecl ipc_task_disable(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // eax

  v1 = (volatile __int32 *)(a1 + 100); /*0x15951f*/
  do /*0x159536*/
  {
    while ( *v1 ) /*0x159524*/
      ; /*0x159526*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159536*/
  v2 = *(_DWORD *)(a1 + 104); /*0x159538*/
  if ( v2 ) /*0x15953d*/
    ipc_kobject_set(v2, 0, 0); /*0x159544*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x15954e*/
}
