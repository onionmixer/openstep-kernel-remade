
undefined4 _thread_policy(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (3 < param_2 - 1)) {
    uVar1 = 4;
  }
  else if (param_2 == *(uint *)(param_1 + 0x5c)) {
    if (param_2 == 2) {
      param_3 = param_3 * 1000;
      if (param_3 % _tick != 0) {
        param_3 = _tick + param_3;
      }
      *(int *)(param_1 + 0x58) = param_3 / _tick;
    }
  }
  else if ((param_2 & *(uint *)(*(int *)(param_1 + 0x178) + 0x158)) == 0) {
    uVar1 = 5;
  }
  else {
    *(uint *)(param_1 + 0x5c) = param_2;
    if (param_2 == 2) {
      param_3 = param_3 * 1000;
      if (param_3 % _tick != 0) {
        param_3 = _tick + param_3;
      }
      *(int *)(param_1 + 0x58) = param_3 / _tick;
    }
    _compute_priority(param_1,1);
  }
  return uVar1;
}
