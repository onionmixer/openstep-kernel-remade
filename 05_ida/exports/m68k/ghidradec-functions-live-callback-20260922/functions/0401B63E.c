
int _vn_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined auStack_1c [4];
  undefined4 uStack_18;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_24 = 0;
  iStack_28 = 0;
  iStack_20 = 0;
  iVar1 = _pn_get(param_1,param_3,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _pn_get(param_2,param_3,auStack_1c);
    if (iVar1 == 0) {
      iVar1 = _lookuppn(auStack_10,0,&iStack_20,&iStack_24);
      if (iVar1 == 0) {
        if (iStack_24 == 0) {
          iVar1 = 2;
        }
        else {
          iVar1 = _lookuppn(auStack_1c,0,&iStack_28,0);
          if (iVar1 == 0) {
            if (*(int *)(iStack_24 + 0x24) == *(int *)(iStack_28 + 0x24)) {
              if ((*(byte *)(*(int *)(iStack_24 + 0x24) + 0xf) & 1) == 0) {
                _vnode_uncache(iStack_28);
                iVar1 = (**(code **)(*(int *)(iStack_20 + 0x1c) + 0x30))
                                  (iStack_20,uStack_c,iStack_28,uStack_18,
                                   *(undefined4 *)(_active_u + 0x1a));
              }
              else {
                iVar1 = 0x1e;
              }
            }
            else {
              iVar1 = 0x12;
            }
          }
        }
      }
      _pn_free(auStack_10);
      _pn_free(auStack_1c);
      if (iStack_24 != 0) {
        _vn_rele(iStack_24);
      }
      if (iStack_20 != 0) {
        _vn_rele(iStack_20);
      }
      if (iStack_28 != 0) {
        _vn_rele(iStack_28);
      }
    }
    else {
      _pn_free(auStack_10);
    }
  }
  return iVar1;
}

