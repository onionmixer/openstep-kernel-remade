
int sub_402B07A(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 param_6,
               undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_88;
  undefined auStack_84 [68];
  int iStack_40;
  int iStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  while( true ) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x1a);
    if (param_4 < iVar3) {
      iVar3 = param_4;
    }
    iVar1 = *(int *)(param_1 + 0x2e);
    uStack_30 = *(undefined4 *)(iVar1 + 0x3e);
    uStack_2c = *(undefined4 *)(iVar1 + 0x42);
    uStack_28 = *(undefined4 *)(iVar1 + 0x46);
    uStack_24 = *(undefined4 *)(iVar1 + 0x4a);
    uStack_20 = *(undefined4 *)(iVar1 + 0x4e);
    uStack_1c = *(undefined4 *)(iVar1 + 0x52);
    uStack_18 = *(undefined4 *)(iVar1 + 0x56);
    uStack_14 = *(undefined4 *)(iVar1 + 0x5a);
    iStack_3c = param_2;
    iStack_10 = param_3;
    iStack_c = iVar3;
    iStack_8 = iVar3;
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),6,_xdr_readargs,&uStack_30,
                     _xdr_rdresult,&iStack_88,param_6);
    iVar1 = iStack_88;
    if (iVar2 != 0) break;
    if (iStack_88 == 0x46) {
      _printf(aNfsReadErrorEs,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
      sub_402B03A(*(int *)(param_1 + 0x2e) + 0x3e);
      _printf(&asc_40A6049);
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    iVar2 = iVar1;
    if (iVar1 != 0) break;
    param_4 = param_4 - iStack_40;
    param_2 = iStack_40 + param_2;
    param_3 = iStack_40 + param_3;
    if ((param_4 == 0) || (iVar3 != iStack_40)) break;
  }
  *param_5 = param_4;
  if (iVar2 == 0) {
    _nattr_to_vattr(param_1,auStack_84,param_7);
  }
  return iVar2;
}
