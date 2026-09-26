/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157d04. */
int host_self()
{
  int send; // eax

  send = ipc_port_make_send(realhost); /*0x157d0e*/
  return ipc_port_copyout_send_compat(send, *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136)); /*0x157d2c*/
}
