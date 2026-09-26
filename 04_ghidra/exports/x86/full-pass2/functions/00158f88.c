/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158f88 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

mach_port_t _mig_get_reply_port(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _active_threads;
  if (*(int *)(_active_threads + 0xbc) == 0) {
    uVar2 = _mach_reply_port();
    *(undefined4 *)(iVar1 + 0xbc) = uVar2;
  }
  return *(mach_port_t *)(iVar1 + 0xbc);
}

