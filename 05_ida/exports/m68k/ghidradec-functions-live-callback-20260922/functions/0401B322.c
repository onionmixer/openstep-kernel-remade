
int _vn_create(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
              int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_14 = 0;
  *param_6 = 0;
  iVar2 = _pn_get(param_1,param_2,auStack_10);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((param_4 == 1) && (*param_3 != 2)) {
    uVar3 = 0;
    piVar4 = (int *)0x0;
  }
  else {
    uVar3 = 1;
    piVar4 = param_6;
  }
  iVar2 = _lookuppn(auStack_10,uVar3,&iStack_14,piVar4);
  if (iVar2 != 0) {
    _pn_free(auStack_10);
    return iVar2;
  }
  if ((*param_6 != 0) && (*(int *)(*param_6 + 0x28) == 6)) {
    return 0x2d;
  }
  if ((*(byte *)(*(int *)(iStack_14 + 0x24) + 0xf) & 1) == 0) {
loc_401B3EC:
    iVar2 = 0;
    if ((param_4 == 0) && (iVar1 = *param_6, iVar1 != 0)) {
      if (((char)param_5 < '\0') &&
         (((*(byte *)(iVar1 + 5) & 2) != 0 &&
          (_vnode_uncache(iVar1), (*(byte *)(*param_6 + 5) & 2) != 0)))) {
        iVar2 = 0x1a;
      }
      _vn_rele(*param_6);
    }
    if (iVar2 == 0) {
      if (*param_3 == 2) {
        if (*param_6 == 0) {
          iVar2 = (**(code **)(*(int *)(iStack_14 + 0x1c) + 0x34))
                            (iStack_14,uStack_c,param_3,param_6,*(undefined4 *)(_active_u + 0x1a));
        }
        else {
          _vn_rele(*param_6);
          iVar2 = 0x11;
        }
      }
      else {
        iVar2 = (**(code **)(*(int *)(iStack_14 + 0x1c) + 0x24))
                          (iStack_14,uStack_c,param_3,param_4,param_5,param_6,
                           *(undefined4 *)(_active_u + 0x1a));
      }
    }
  }
  else {
    iVar2 = *param_6;
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x28) - 3U < 2) goto loc_401B3EC;
      _vn_rele(iVar2);
    }
    iVar2 = 0x1e;
  }
  _pn_free(auStack_10);
  _vn_rele(iStack_14);
  return iVar2;
}

