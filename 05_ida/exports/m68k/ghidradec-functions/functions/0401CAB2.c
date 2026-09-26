
undefined4 _if_output(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x32) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x32))(param_1,param_2,param_3);
  }
  return uVar1;
}
