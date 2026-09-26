/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15814c. */
int __cdecl convert_pset_name_to_port(int a1)
{
  volatile __int32 *v1; // edx
  int send; // ebx

  v1 = (volatile __int32 *)(a1 + 344); /*0x158154*/
  do /*0x15816e*/
  {
    while ( *v1 ) /*0x15815c*/
      ; /*0x15815e*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15816e*/
  if ( *(_DWORD *)(a1 + 340) ) /*0x158170*/
    send = ipc_port_make_send(*(_DWORD *)(a1 + 352)); /*0x158185*/
  else
    send = 0; /*0x15818c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x158190*/
  pset_deallocate(a1); /*0x158197*/
  return send; /*0x1581a1*/
}
