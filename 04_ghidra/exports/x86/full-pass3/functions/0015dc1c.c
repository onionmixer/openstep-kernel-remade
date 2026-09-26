/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015dc1c */

void _netipc_msg_release(undefined4 param_1)

{
  _zfree(_mach_net_kmsg_zone,param_1);
  return;
}

