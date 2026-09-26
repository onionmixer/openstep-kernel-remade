
undefined4 sub_4039BDA(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x126);
  iVar4 = _iflush((int)*(sword *)(iVar1 + 4));
  if ((iVar4 < 0) && ((param_2 == 0 || (iVar4 < 0)))) {
    uVar5 = 0x10;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar1 + 10) + 0x20);
    iVar3 = -(int)-(*(char *)(iVar2 + 0xd2) == '\0');
    if ((iVar3 != 0) && (*(char *)(iVar2 + 0xd1) == '\x02')) {
      *(undefined *)(iVar2 + 0xd1) = 1;
      _sbupdate(iVar1);
    }
    _kfree(*(undefined4 *)(iVar2 + 0x2d8),*(undefined4 *)(iVar2 + 0x9c));
    _brelse(*(undefined4 *)(iVar1 + 10));
    *(undefined4 *)(iVar1 + 10) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
    if (iVar4 == 0) {
      (**(code **)(*(int *)(*(int *)(iVar1 + 6) + 0x1c) + 4))
                (*(int *)(iVar1 + 6),iVar3,1,*(undefined4 *)(_active_u + 0x1a));
      _binval(*(undefined4 *)(iVar1 + 6));
      _vn_rele(*(undefined4 *)(iVar1 + 6));
      *(undefined4 *)(iVar1 + 6) = 0;
      iVar4 = _mounttab;
      if (_mounttab == iVar1) {
        _mounttab = *(int *)(iVar1 + 0x1c);
      }
      else {
        for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
          if (iVar1 == *(int *)(iVar4 + 0x1c)) {
            *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
          }
        }
      }
      _kfree(iVar1,0x20);
    }
    uVar5 = 0;
  }
  return uVar5;
}

