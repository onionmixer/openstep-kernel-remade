
undefined4 _soconnect(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 3) & 2) == 0) {
    if (((*(word *)(param_1 + 6) & 6) == 0) ||
       (((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 4) == 0 &&
        (iVar2 = _sodisconnect(param_1), iVar2 == 0)))) {
      uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,4,0,param_2,0);
    }
    else {
      uVar1 = 0x38;
    }
  }
  else {
    uVar1 = 0x2d;
  }
  return uVar1;
}
