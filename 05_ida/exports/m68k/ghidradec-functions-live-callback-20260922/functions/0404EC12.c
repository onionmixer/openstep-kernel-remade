
undefined4 _kern_PMSetPowerState(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerState(param_2,param_3);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}

