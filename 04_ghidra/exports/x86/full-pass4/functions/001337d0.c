/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001337d0 */

void _sync_vp(int param_1)

{
  _mfs_fsync(param_1);
  if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x60) & 0x10) != 0) {
    FUN_00133824(param_1);
  }
  return;
}

