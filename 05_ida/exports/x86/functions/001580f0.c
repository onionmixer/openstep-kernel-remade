/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1580f0. */
int __cdecl convert_pset_to_port(int a1)
{
  volatile __int32 *v1; // edx
  int send; // ebx

  v1 = (volatile __int32 *)(a1 + 344); /*0x1580f8*/
  do /*0x158112*/
  {
    while ( *v1 ) /*0x158100*/
      ; /*0x158102*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x158112*/
  if ( *(_DWORD *)(a1 + 340) ) /*0x158114*/
    send = ipc_port_make_send(*(_DWORD *)(a1 + 348)); /*0x158129*/
  else
    send = 0; /*0x158130*/
  _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x158134*/
  pset_deallocate(a1); /*0x15813b*/
  return send; /*0x158145*/
}
