
int sub_402B5F2(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iStack_48;
  undefined auStack_28 [36];
  
  iStack_48 = 0;
  iVar2 = _nfs_validate_caches(param_1,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  iStack_48 = *(int *)(param_1 + 0x2e);
  _rlock();
  iVar2 = _dnlc_lookup(param_1,param_2,param_4);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    iStack_48 = 0x68;
    piVar3 = (int *)_kalloc();
    _bzero(piVar3,0x68);
    _setdiropargs(auStack_28,param_2,param_1);
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),4,_xdr_diropargs,auStack_28,
                     _xdr_diropres,piVar3,param_4);
    if (iVar2 == 0) {
      iVar2 = *piVar3;
      if (iVar2 == 0x46) {
        iStack_48 = param_1;
        _btrash();
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 != 0) goto loc_402B712;
      iStack_48 = *(int *)(param_1 + 0x24);
      iVar4 = _makenfsnode(piVar3 + 1,piVar3 + 9);
      *param_3 = iVar4;
      if (_nfs_dnlc != 0) {
        iStack_48 = param_4;
        _dnlc_enter(param_1,param_2,iVar4);
      }
    }
    else {
loc_402B712:
      *param_3 = 0;
    }
    piVar5 = (int *)&stack0xffffffbc;
    iStack_48 = 0x68;
    _kfree(piVar3);
    if (iVar2 != 0) goto loc_402B75C;
  }
  else {
    *(sword *)(iVar2 + 6) = *(sword *)(iVar2 + 6) + 1;
    iStack_48 = param_4;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40);
    if (iVar2 != 0) {
      iStack_48 = *param_3;
      _vn_rele();
      piVar5 = &iStack_48;
      goto loc_402B75C;
    }
  }
  iVar4 = *param_3;
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 - 3U < 2) || (piVar5 = (int *)&stack0xffffffbc, iVar1 == 8)) {
    iStack_48 = iVar1;
    iVar4 = _specvp(iVar4,(int)*(sword *)(iVar4 + 0x2c));
    _vn_rele(*param_3);
    *param_3 = iVar4;
    piVar5 = (int *)&stack0xffffffbc;
  }
loc_402B75C:
  *(undefined4 *)((int)piVar5 + -4) = *(undefined4 *)(param_1 + 0x2e);
  *(undefined4 *)((int)piVar5 + -8) = 0x402b766;
  _runlock();
  return iVar2;
}
