/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130f38 */

undefined4 FUN_00130f38(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x128);
  _rflush(param_1);
  _rinval(param_1);
  if ((*(int *)(iVar1 + 0x18) == 1) && (*(short *)(*(int *)(iVar1 + 0x10) + 6) == 1)) {
    _rp_rmhash(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _rinactive(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _vn_rele(*(undefined4 *)(iVar1 + 0x10));
    _vfs_putnum(&DAT_001e59b8,*(undefined4 *)(iVar1 + 0x28));
    if (-1 < *(int *)(iVar1 + 0x58)) {
      _kfree(*(undefined4 *)(iVar1 + 0x54),*(int *)(iVar1 + 0x58));
    }
    _kfree(iVar1,0x70);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}

