/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157cd8. */
mach_port_t mach_host_self(void)
{
  int send; // eax

  send = ipc_port_make_send(realhost); /*0x157ce2*/
  return ipc_port_copyout_send(send, *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136)); /*0x157d00*/
}
