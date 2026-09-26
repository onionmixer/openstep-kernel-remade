
undefined4 _sodisconnect(int param_1)

{
  undefined4 uVar1;
  
  if ((*(word *)(param_1 + 6) & 2) == 0) {
    uVar1 = 0x39;
  }
  else if ((*(word *)(param_1 + 6) & 8) == 0) {
    uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,6,0,0,0);
  }
  else {
    uVar1 = 0x25;
  }
  return uVar1;
}

