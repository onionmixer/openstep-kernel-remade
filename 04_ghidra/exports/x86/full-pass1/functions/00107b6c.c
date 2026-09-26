/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107b6c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

gid_t _getgid(void)

{
  gid_t gVar1;
  
  *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(*(int *)(_active_u + 0x1c) + 8);
  gVar1 = (gid_t)*(short *)(*(int *)(_active_u + 0x1c) + 4);
  *(gid_t *)(DAT_001e875c + 100) = gVar1;
  return gVar1;
}

