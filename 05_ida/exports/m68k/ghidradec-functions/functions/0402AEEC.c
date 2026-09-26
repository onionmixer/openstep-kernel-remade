
int _nfswrite(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iStack_84;
  undefined auStack_80 [68];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  do {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x1e);
    if (param_4 < iVar2) {
      iVar2 = param_4;
    }
    iVar1 = *(int *)(param_1 + 0x2e);
    uStack_3c = *(undefined4 *)(iVar1 + 0x3e);
    uStack_38 = *(undefined4 *)(iVar1 + 0x42);
    uStack_34 = *(undefined4 *)(iVar1 + 0x46);
    uStack_30 = *(undefined4 *)(iVar1 + 0x4a);
    uStack_2c = *(undefined4 *)(iVar1 + 0x4e);
    uStack_28 = *(undefined4 *)(iVar1 + 0x52);
    uStack_24 = *(undefined4 *)(iVar1 + 0x56);
    uStack_20 = *(undefined4 *)(iVar1 + 0x5a);
    iStack_1c = param_3;
    iStack_18 = param_3;
    iStack_14 = iVar2;
    iStack_10 = iVar2;
    iStack_c = param_2;
    iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),8,_xdr_writeargs,&uStack_3c,
                     _xdr_attrstat,&iStack_84,param_5);
    if ((iVar1 == 0) && (iVar1 = iStack_84, iStack_84 == 0x46)) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    param_4 = param_4 - iVar2;
    param_2 = iVar2 + param_2;
    param_3 = iVar2 + param_3;
    if (iVar1 != 0) goto loc_402AFCC;
  } while (param_4 != 0);
  _nfs_attrcache(param_1,auStack_80);
loc_402AFCC:
  if (iVar1 == 0x1c) {
    _printf(aNfsWriteErrorO,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else if (iVar1 == 0x45) {
      return 0x45;
    }
    _printf(aNfsWriteErrorD,iVar1,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
    sub_402B03A(*(int *)(param_1 + 0x2e) + 0x3e);
    _printf(&asc_40A6049);
  }
  return iVar1;
}
