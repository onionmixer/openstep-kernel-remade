
undefined4 _thread_priority(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar1 = 4;
  }
  else if (*(int *)(param_1 + 0x50) < (int)param_2) {
    uVar1 = 5;
  }
  else {
    if (*(int *)(param_1 + 0x60) < 0) {
      *(uint *)(param_1 + 0x4c) = param_2;
      _compute_priority(param_1,1);
    }
    else {
      *(uint *)(param_1 + 0x60) = param_2;
    }
    if (param_3 != 0) {
      *(uint *)(param_1 + 0x50) = param_2;
    }
  }
  return uVar1;
}
