
int _namesetattr(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,param_2,0,&iStack_8);
  if (iVar1 == 0) {
    if ((*(byte *)(*(int *)(iStack_8 + 0x24) + 0xf) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x18))
                        (iStack_8,param_3,*(undefined4 *)(_active_u + 0x1a));
    }
    else {
      iVar1 = 0x1e;
    }
    _vn_rele(iStack_8);
  }
  return iVar1;
}
