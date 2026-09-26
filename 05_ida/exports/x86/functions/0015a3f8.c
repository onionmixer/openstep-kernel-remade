/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a3f8. */
int device_master_self()
{
  int v0; // ebx
  int v1; // edx
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v0 = *(_DWORD *)(active_threads + 12); /*0x15a404*/
  if ( suser() ) /*0x15a407*/
    v1 = dword_1E97B4; /*0x15a418*/
  else
    v1 = realhost; /*0x15a410*/
  if ( !v1 ) /*0x15a420*/
    return 0; /*0x15a444*/
  v2 = ipc_port_copy_send(v1); /*0x15a42b*/
  ipc_object_copyout(*(_DWORD *)(v0 + 136), v2, 17, 1, &v4); /*0x15a43b*/
  return v4; /*0x15a44e*/
}
