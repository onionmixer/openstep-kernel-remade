
undefined4 _if_init(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x2e) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x2e))(param_1);
  }
  return uVar1;
}
