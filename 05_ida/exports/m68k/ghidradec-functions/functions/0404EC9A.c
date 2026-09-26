
undefined4 _kern_PMRestoreDefaults(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMRestoreDefaults();
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
