
int _diraddentry(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30) == *(int *)(param_5 + 0x30)) {
    if (((*(word *)(param_5 + 0x62) & 0xf000) == 0x4000) &&
       (iVar1 = sub_4035F40(param_5,param_6,param_1), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = sub_403627C(param_1,param_4);
    if (iVar1 == 0) {
      *(sword *)(*(int *)(param_4 + 0x10) + 6) = (sword)param_3;
      _strncpy(*(int *)(param_4 + 0x10) + 8,param_2,param_3 + 4U & 0xfffffffc);
      **(undefined4 **)(param_4 + 0x10) = *(undefined4 *)(param_5 + 0x46);
      _dnlc_enter(param_1 + 0xc,param_2,param_5 + 0xc,0);
      _bwrite(*(undefined4 *)(param_4 + 0xc));
      *(undefined4 *)(param_4 + 0xc) = 0;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
        *(undefined4 *)(param_1 + 0x4a) = 0;
        iVar1 = 0;
      }
      else {
        iVar1 = (int)*(char *)(dword_40B57D4 + 100);
      }
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}

