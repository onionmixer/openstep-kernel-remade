
undefined4 _spec_fid(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
  if (iVar1 == 0) {
    uVar2 = 0x16;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 100))(iVar1,param_2);
  }
  return uVar2;
}
