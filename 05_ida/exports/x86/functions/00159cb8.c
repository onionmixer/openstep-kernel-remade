/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159cb8. */
int thread_reply()
{
  int v0; // edi
  thread_act_t v1; // esi
  volatile __int32 *v2; // edx
  int v3; // ebx

  v0 = *(_DWORD *)(active_threads + 12); /*0x159cc3*/
  v1 = active_threads; /*0x159cc6*/
  v2 = (volatile __int32 *)(active_threads + 168); /*0x159cc8*/
  do /*0x159ce2*/
  {
    while ( *v2 ) /*0x159cd0*/
      ; /*0x159cd2*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159ce2*/
  if ( *(_DWORD *)(v1 + 172) ) /*0x159ce4*/
  {
    v3 = *(_DWORD *)(v1 + 184); /*0x159ced*/
    if ( v3 && v3 != -1 ) /*0x159cfa*/
      ipc_object_reference(*(_DWORD *)(v1 + 184)); /*0x159cfd*/
  }
  else
  {
    v3 = 0; /*0x159d08*/
  }
  _InterlockedExchange((volatile __int32 *)(v1 + 168), 0); /*0x159d0c*/
  return ipc_port_copyout_receiver(v3, *(_DWORD *)(v0 + 136)); /*0x159d22*/
}
