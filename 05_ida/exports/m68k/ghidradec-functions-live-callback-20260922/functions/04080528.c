
undefined4 _snd_device_def_high_water(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10000;
  if (param_1 == 0) {
    uVar1 = 0xc0000;
  }
  return uVar1;
}

