
undefined4 _vm_set_policy(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
    }
    if (param_2 == 0) {
      param_2 = *(int *)(param_1 + 0x10);
    }
    sub_4060C18(param_1,param_2,param_3 + param_2,param_4);
    uVar1 = 0;
  }
  return uVar1;
}
