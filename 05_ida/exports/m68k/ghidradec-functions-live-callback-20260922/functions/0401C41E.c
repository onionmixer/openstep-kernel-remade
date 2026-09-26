
undefined4 sub_401C41E(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined uStack_a;
  undefined uStack_9;
  undefined uStack_8;
  byte bStack_7;
  undefined uStack_6;
  undefined uStack_5;
  
  iVar1 = _if_private(param_1);
  uVar2 = *(undefined4 *)(iVar1 + 10);
  iVar1 = _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      uVar2 = _if_private(param_1);
      uVar2 = _in_bootp(param_1,param_3,uVar2);
      return uVar2;
    }
  }
  else {
    iVar1 = _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar1 != 0) {
      iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
      if ((iVar1 == 0) || (iVar1 = _strcmp(param_2,_IFCONTROL_RMVMULTICAST), iVar1 == 0)) {
        if (param_3[8] != 2) {
          return 0x2f;
        }
        uStack_a = 1;
        uStack_9 = 0;
        uStack_8 = 0x5e;
        bStack_7 = *(byte *)((int)param_3 + 0x15) & 0x7f;
        uStack_6 = *(undefined *)(param_3 + 0xb);
        uStack_5 = *(undefined *)((int)param_3 + 0x17);
        param_3 = (sword *)&uStack_a;
      }
      uVar2 = _if_control(uVar2,param_2,param_3);
      return uVar2;
    }
    if (*param_3 == 2) {
      uVar3 = _if_flags(param_1);
      _if_flags_set(param_1,uVar3 | 0x41);
      _if_init(uVar2);
      param_3 = param_3 + 2;
      _if_control(uVar2,_IFCONTROL_SETIPADDRESS,param_3);
      iVar1 = _if_private(param_1);
      *(undefined4 *)(iVar1 + 6) = *(undefined4 *)param_3;
      uVar3 = _if_flags(param_1);
      if ((uVar3 & 0x4000) == 0) {
        iVar1 = _if_private(param_1,param_3);
        uVar2 = _if_private(param_1,*(undefined4 *)(iVar1 + 6));
        _arpwhohas(param_1,uVar2);
      }
      return 0;
    }
  }
  return 0x2f;
}

