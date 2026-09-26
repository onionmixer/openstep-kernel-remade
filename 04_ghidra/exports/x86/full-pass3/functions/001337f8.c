/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001337f8 */

void _sync_vp_invalidate(int param_1,undefined4 param_2)

{
  _mfs_fsync_invalidate(param_1,param_2);
  if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x60) & 0x10) != 0) {
    FUN_00133824(param_1);
  }
  return;
}

