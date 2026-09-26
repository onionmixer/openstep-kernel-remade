/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f42c */

int _setdirgid(int param_1)

{
  if (((*(byte *)(*(int *)(param_1 + 0x24) + 0xc) & 0x10) == 0) &&
     ((*(byte *)(*(int *)(param_1 + 0x30) + 0x85) & 4) == 0)) {
    return (int)*(short *)(*(int *)(_active_u + 0x1c) + 4);
  }
  return (int)*(short *)(*(int *)(param_1 + 0x30) + 0x88);
}

