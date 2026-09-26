/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159bc8. */
int task_notify()
{
  int v0; // edi
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // ebx

  v0 = *(_DWORD *)(active_threads + 12); /*0x159bd3*/
  v1 = *(_DWORD *)(v0 + 136); /*0x159bd6*/
  v2 = (volatile __int32 *)(v1 + 8); /*0x159bdc*/
  do /*0x159bf2*/
  {
    while ( *v2 ) /*0x159be0*/
      ; /*0x159be2*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159bf2*/
  if ( *(_DWORD *)(v1 + 12) ) /*0x159bf4*/
  {
    v3 = *(_DWORD *)(v1 + 68); /*0x159bfa*/
    if ( v3 && v3 != -1 ) /*0x159c04*/
      ipc_object_reference(*(_DWORD *)(v1 + 68)); /*0x159c07*/
  }
  else
  {
    v3 = 0; /*0x159c14*/
  }
  _InterlockedExchange((volatile __int32 *)(v1 + 8), 0); /*0x159c18*/
  return ipc_port_copyout_receiver(v3, *(_DWORD *)(v0 + 136)); /*0x159c2b*/
}
