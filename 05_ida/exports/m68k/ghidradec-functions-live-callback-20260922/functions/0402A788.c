
undefined4 sub_402A788(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x126);
  _rflush(param_1);
  _rinval(param_1);
  if ((*(int *)(iVar1 + 0x16) == 1) && (*(sword *)(*(int *)(iVar1 + 0x10) + 6) == 1)) {
    _rp_rmhash(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x2e));
    _rinactive(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x2e));
    _vn_rele(*(undefined4 *)(iVar1 + 0x10));
    _vfs_putnum(unk_40B3534,*(undefined4 *)(iVar1 + 0x26));
    if (-1 < *(int *)(iVar1 + 0x56)) {
      _kfree(*(undefined4 *)(iVar1 + 0x52),*(int *)(iVar1 + 0x56));
    }
    _kfree(iVar1,0x6e);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}

