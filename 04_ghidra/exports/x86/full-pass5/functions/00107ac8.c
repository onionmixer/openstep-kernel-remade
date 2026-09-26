/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107ac8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t _getpid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(_active_threads + 0x84);
  iVar2 = *_active_u;
  *(int *)(iVar1 + 0x60) = (int)*(short *)(iVar2 + 0x30);
  iVar2 = (int)*(short *)(iVar2 + 0x32);
  *(int *)(iVar1 + 100) = iVar2;
  return iVar2;
}

