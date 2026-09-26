/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a39c. */
int host_priv_self()
{
  int v0; // ebx
  int v2; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  v0 = *(_DWORD *)(active_threads + 12); /*0x15a3a8*/
  if ( !suser() ) /*0x15a3ab*/
    return 0; /*0x15a3b4*/
  if ( !dword_1E97B4 ) /*0x15a3c0*/
    return 0; /*0x15a3e4*/
  v2 = ipc_port_copy_send(dword_1E97B4); /*0x15a3cb*/
  ipc_object_copyout(*(_DWORD *)(v0 + 136), v2, 17, 1, &v3); /*0x15a3db*/
  return v3; /*0x15a3ee*/
}
