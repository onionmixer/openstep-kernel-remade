
undefined4 _syread(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(DAT_40b0ac8 + (uint)(*(word *)(_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}
