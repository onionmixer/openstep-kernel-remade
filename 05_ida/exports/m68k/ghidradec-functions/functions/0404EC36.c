
undefined4 _kern_PMGetPowerEvent(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = sub_404EAAE(param_2);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
