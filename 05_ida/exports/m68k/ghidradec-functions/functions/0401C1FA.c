
undefined4 _locontrol(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = _strcmp(param_2,&_IFCONTROL_SETADDR);
  if (iVar1 == 0) {
    uVar2 = _if_flags(param_1);
    _if_flags_set(param_1,uVar2 | 0x41);
  }
  else {
    iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
    if ((iVar1 != 0) && (iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST), iVar1 != 0)) {
      return 0x16;
    }
    if (*(sword *)(param_3 + 0x10) != 2) {
      uVar3 = 0x2f;
    }
  }
  return uVar3;
}
