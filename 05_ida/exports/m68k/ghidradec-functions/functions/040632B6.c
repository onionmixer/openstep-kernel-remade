
int _mach_swapon(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    return 0xd;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0;
  iStack_14 = 0;
  iVar1 = _pn_get(param_1,0,auStack_10);
  if (iVar1 != 0) {
    return 0x16;
  }
  iVar1 = iStack_8 + 1;
  iVar2 = _kalloc(iVar1);
  _strncpy(iVar2,uStack_c,iStack_8);
  *(undefined *)(iVar2 + -1 + iVar1) = 0;
  iVar3 = _lookuppn(auStack_10,1,0,&iStack_14);
  _pn_free(auStack_10);
  if (iVar3 == 0) {
    if (*(int *)(iStack_14 + 0x28) == 1) {
      piStack_18 = dword_40B4DF4;
      if ((int **)dword_40B4DF4 != &dword_40B4DF4) {
        do {
          if (iStack_14 == piStack_18[2]) break;
          piStack_18 = (int *)*piStack_18;
        } while ((int **)piStack_18 != &dword_40B4DF4);
        if ((int **)piStack_18 != &dword_40B4DF4) {
          iVar3 = 0x10;
          goto loc_40633C4;
        }
      }
      iVar3 = _vnode_pager_file_init(&piStack_18,iStack_14,param_3,param_4);
      if (iVar3 == 0) {
        piStack_18[0xb] = param_2 & 1;
        piStack_18[10] = iVar2;
        iVar2 = 0;
      }
    }
    else {
      iVar3 = 0x16;
    }
  }
loc_40633C4:
  if (iStack_14 != 0) {
    _vn_rele(iStack_14);
  }
  if (iVar2 != 0) {
    _kfree(iVar2,iVar1);
  }
  return iVar3;
}
