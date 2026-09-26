/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c2f8 */

void _nfs_attrcache(int param_1,undefined4 param_2)

{
  if (((*(byte *)(param_1 + 4) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x10) == 0)) {
    _nattr_to_vattr(param_1,param_2,*(int *)(param_1 + 0x30) + 0x80);
    FUN_0012c380(param_1);
  }
  return;
}

