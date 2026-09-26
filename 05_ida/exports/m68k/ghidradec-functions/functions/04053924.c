
undefined4 _thread_max_priority(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (0x1f < param_3)) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x50) = param_3;
    if ((int)param_3 < *(int *)(param_1 + 0x4c)) {
      *(uint *)(param_1 + 0x4c) = param_3;
      _compute_priority(param_1,1);
    }
    else if ((-1 < *(int *)(param_1 + 0x60)) && ((int)param_3 < *(int *)(param_1 + 0x60))) {
      *(uint *)(param_1 + 0x60) = param_3;
    }
    uVar1 = 0;
  }
  return uVar1;
}
