/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a330. */
int __cdecl convert_thread_to_port(int a1)
{
  volatile __int32 *v1; // edx
  int send; // ebx

  v1 = (volatile __int32 *)(a1 + 168); /*0x15a338*/
  do /*0x15a352*/
  {
    while ( *v1 ) /*0x15a340*/
      ; /*0x15a342*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15a352*/
  if ( *(_DWORD *)(a1 + 172) ) /*0x15a354*/
    send = ipc_port_make_send(*(_DWORD *)(a1 + 172)); /*0x15a364*/
  else
    send = 0; /*0x15a36c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x15a370*/
  thread_deallocate(a1); /*0x15a377*/
  return send; /*0x15a381*/
}
