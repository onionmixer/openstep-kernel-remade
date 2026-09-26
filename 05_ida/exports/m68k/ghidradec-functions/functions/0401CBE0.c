
undefined4 _if_getbuf(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x3e) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x3e))(param_1);
  }
  return uVar1;
}
