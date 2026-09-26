
undefined4 _thread_userstack(undefined4 param_1,int param_2,int param_3,uint param_4,int *param_5)

{
  int iVar1;
  
  if (*param_5 == 0) {
    *param_5 = 0x4000000;
  }
  if (param_2 == 1) {
    if (param_4 < 0x12) {
      return 4;
    }
    iVar1 = 0x4000000;
    if (*(int *)(param_3 + 0x3c) != 0) {
      iVar1 = *(int *)(param_3 + 0x3c);
    }
    *param_5 = iVar1;
  }
  return 0;
}

