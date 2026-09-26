
int _chdirec(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 0x28) == 2) {
      iVar1 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x1c))
                        (iStack_8,0x40,*(undefined4 *)(_active_u + 0x1a));
      if (iVar1 == 0) {
        *param_2 = iStack_8;
        return 0;
      }
    }
    else {
      iVar1 = 0x14;
    }
    _vn_rele(iStack_8);
  }
  return iVar1;
}
