
undefined4 sub_4068F24(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_104 [256];
  
  if (*param_1 == 1) {
    if (param_1[2] == 0) {
      param_1[2] = 0x40;
    }
    else {
      iVar1 = _adb_system_info(auStack_104,0x10);
      if (iVar1 == 0) {
        iVar1 = sub_4068ECC(auStack_104,0x10);
      }
      if ((uint)(iVar1 << 2) < (uint)param_1[2]) {
        param_1[2] = iVar1 << 2;
      }
      iVar1 = _copyoutmsg(auStack_104,param_1[1],param_1[2] << 2);
      if (iVar1 != 0) {
        return 0xe;
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}

