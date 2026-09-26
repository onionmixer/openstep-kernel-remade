/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107b38 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
  *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(*(int *)(_active_u + 0x1c) + 6);
  uVar1 = (uid_t)*(short *)(*(int *)(_active_u + 0x1c) + 2);
  *(uid_t *)(DAT_001e875c + 100) = uVar1;
  return uVar1;
}

