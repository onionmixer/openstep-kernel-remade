
int _vn_remove(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iVar1 = _pn_get(param_1,param_2,auStack_10);
  if (iVar1 != 0) {
    return iVar1;
  }
  iStack_18 = 0;
  iVar1 = _lookuppn(auStack_10,0,&iStack_14,&iStack_18);
  if (iVar1 != 0) {
    _pn_free(auStack_10);
    return iVar1;
  }
  if (iStack_18 == 0) {
    iVar1 = 2;
  }
  else if ((*(byte *)(*(int *)(iStack_18 + 0x24) + 0xf) & 1) == 0) {
    if ((*(byte *)(iStack_18 + 5) & 1) == 0) {
      _vnode_uncache(iStack_18);
      if (*(int *)(iStack_18 + 0x28) == 2) {
        if (param_3 != 1) {
          iVar1 = 1;
          goto loc_401B892;
        }
        if (*(int *)(iStack_18 + 0x10) != 0) {
          iVar1 = 0x42;
          goto loc_401B892;
        }
        _vn_rele(iStack_18);
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        pcVar2 = *(code **)(*(int *)(iStack_14 + 0x1c) + 0x38);
      }
      else {
        if (param_3 != 0) {
          iVar1 = 0x14;
          goto loc_401B892;
        }
        _vn_rele(iStack_18);
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        pcVar2 = *(code **)(*(int *)(iStack_14 + 0x1c) + 0x28);
      }
      iStack_18 = 0;
      iVar1 = (*pcVar2)(iStack_14,uStack_c,uVar3);
    }
    else {
      iVar1 = 0x10;
    }
  }
  else {
    iVar1 = 0x1e;
  }
loc_401B892:
  _pn_free(auStack_10);
  if (iStack_18 != 0) {
    _vn_rele(iStack_18);
  }
  _vn_rele(iStack_14);
  return iVar1;
}

