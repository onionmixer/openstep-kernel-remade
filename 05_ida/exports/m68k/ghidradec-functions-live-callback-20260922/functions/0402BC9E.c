
int sub_402BC9E(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iStack_50;
  undefined auStack_4c [36];
  undefined auStack_28 [36];
  
  iVar1 = _strcmp(param_2,&asc_40A6047);
  if ((((iVar1 == 0) || (iVar1 = _strcmp(param_2,&asc_40A6712), iVar1 == 0)) ||
      (iVar1 = _strcmp(param_4,&asc_40A6047), iVar1 == 0)) ||
     (iVar1 = _strcmp(param_4,&asc_40A6712), iVar1 == 0)) {
    return 0x16;
  }
  _rlock(*(undefined4 *)(param_1 + 0x2e));
  _dnlc_remove(param_1,param_2);
  _dnlc_remove(param_3,param_4);
  if (param_1 != param_3) {
    _rlock(*(undefined4 *)(param_3 + 0x2e));
  }
  _setdiropargs(auStack_4c,param_2,param_1);
  _setdiropargs(auStack_28,param_4,param_3);
  iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),0xb,_xdr_rnmargs,auStack_4c,
                   _xdr_enum,&iStack_50,param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  *(undefined4 *)(*(int *)(param_3 + 0x2e) + 0xb6) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x2e));
  if (param_1 != param_3) {
    _runlock(*(undefined4 *)(param_3 + 0x2e));
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  if (iStack_50 != 0x46) {
    return iStack_50;
  }
  _btrash(param_1);
  _nfs_invalidate_caches(param_1);
  _btrash(param_3);
  _nfs_invalidate_caches(param_3);
  return 0x46;
}

