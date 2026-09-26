
int _vn_link(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_18 = 0;
  iStack_14 = 0;
  iVar1 = _pn_get(param_2,param_3,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _lookupname(param_1,param_3,1,0,&iStack_14);
    if ((iVar1 == 0) && (iVar1 = _lookuppn(auStack_10,1,&iStack_18,0), iVar1 == 0)) {
      if (*(int *)(iStack_14 + 0x24) == *(int *)(iStack_18 + 0x24)) {
        if ((*(byte *)(*(int *)(iStack_14 + 0x24) + 0xf) & 1) == 0) {
          iVar1 = (**(code **)(*(int *)(iStack_18 + 0x1c) + 0x2c))
                            (iStack_14,iStack_18,uStack_c,*(undefined4 *)(_active_u + 0x1a));
        }
        else {
          iVar1 = 0x1e;
        }
      }
      else {
        iVar1 = 0x12;
      }
    }
    _pn_free(auStack_10);
    if (iStack_14 != 0) {
      _vn_rele(iStack_14);
    }
    if (iStack_18 != 0) {
      _vn_rele(iStack_18);
    }
  }
  return iVar1;
}

