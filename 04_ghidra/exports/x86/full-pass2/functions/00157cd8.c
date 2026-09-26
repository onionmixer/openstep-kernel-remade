/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157cd8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

mach_port_t _mach_host_self(void)

{
  undefined4 uVar1;
  mach_port_t mVar2;
  
  uVar1 = _ipc_port_make_send(_realhost);
  mVar2 = _ipc_port_copyout_send(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88));
  return mVar2;
}

