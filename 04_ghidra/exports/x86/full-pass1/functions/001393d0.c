/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001393d0 */

undefined4 FUN_001393d0(vnop_fsync_args *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  _sunsave(iVar1);
  _spec_fsync(param_1);
  if (*(int *)(iVar1 + 0x38) != 0) {
    _vn_rele(*(int *)(iVar1 + 0x38));
    *(undefined4 *)(iVar1 + 0x38) = 0;
  }
  _kfree(*(undefined4 *)(param_1 + 0x30),0x8c);
  return 0;
}

