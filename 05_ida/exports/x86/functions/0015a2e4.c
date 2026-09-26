/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a2e4. */
int __cdecl convert_task_to_port(int a1)
{
  volatile __int32 *v1; // edx
  int send; // ebx

  v1 = (volatile __int32 *)(a1 + 100); /*0x15a2ec*/
  do /*0x15a302*/
  {
    while ( *v1 ) /*0x15a2f0*/
      ; /*0x15a2f2*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15a302*/
  if ( *(_DWORD *)(a1 + 104) ) /*0x15a304*/
    send = ipc_port_make_send(*(_DWORD *)(a1 + 104)); /*0x15a311*/
  else
    send = 0; /*0x15a318*/
  _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x15a31c*/
  task_deallocate(a1); /*0x15a320*/
  return send; /*0x15a32a*/
}
