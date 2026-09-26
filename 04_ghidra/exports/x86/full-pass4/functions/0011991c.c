/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011991c */

undefined4 _vfs_lock(int param_1)

{
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
    return 0;
  }
  return 0x10;
}

