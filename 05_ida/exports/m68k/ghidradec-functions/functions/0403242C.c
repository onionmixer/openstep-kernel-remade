
undefined4 _spec_link(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_2 + 0x1c) + 0x2c))(iVar1,param_2,param_3,param_4);
  }
  return uVar2;
}
