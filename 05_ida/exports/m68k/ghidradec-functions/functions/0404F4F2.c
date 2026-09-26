
undefined4 _processor_set_policy_enable(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (3 < param_2 - 1)) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x158) = param_2 | *(uint *)(param_1 + 0x158);
    uVar1 = 0;
  }
  return uVar1;
}
