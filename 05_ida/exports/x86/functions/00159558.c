/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159558. */
int __cdecl ipc_task_terminate(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int i; // ebx
  int v8; // eax

  v1 = (volatile __int32 *)(a1 + 100); /*0x159561*/
  do /*0x159576*/
  {
    while ( *v1 ) /*0x159564*/
      ; /*0x159566*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159576*/
  v2 = *(_DWORD *)(a1 + 104); /*0x159578*/
  if ( !v2 ) /*0x15957d*/
    return _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x159581*/
  *(_DWORD *)(a1 + 104) = 0; /*0x15958c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 100), 0); /*0x159595*/
  v4 = *(_DWORD *)(a1 + 108); /*0x159598*/
  if ( v4 && v4 != -1 ) /*0x1595a2*/
    ipc_port_release_send(*(_DWORD *)(a1 + 108)); /*0x1595a5*/
  v5 = *(_DWORD *)(a1 + 112); /*0x1595ad*/
  if ( v5 && v5 != -1 ) /*0x1595b7*/
    ipc_port_release_send(*(_DWORD *)(a1 + 112)); /*0x1595ba*/
  v6 = *(_DWORD *)(a1 + 116); /*0x1595c2*/
  if ( v6 && v6 != -1 ) /*0x1595cc*/
    ipc_port_release_send(*(_DWORD *)(a1 + 116)); /*0x1595cf*/
  for ( i = 0; i <= 3; ++i ) /*0x1595d7*/
  {
    v8 = *(_DWORD *)(a1 + 4 * i + 120); /*0x1595dc*/
    if ( v8 ) /*0x1595e2*/
    {
      if ( v8 != -1 ) /*0x1595e7*/
        ipc_port_release_send(*(_DWORD *)(a1 + 4 * i + 120)); /*0x1595ea*/
    }
  }
  ipc_space_destroy(*(_DWORD *)(a1 + 136)); /*0x1595ff*/
  return ipc_port_dealloc_special(v2); /*0x159614*/
}
