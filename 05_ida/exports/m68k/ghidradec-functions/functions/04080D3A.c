
undefined8 _snd_dspcmd_def_high_water(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == 1) {
    uVar1 = 0xc0000;
  }
  else {
    uVar2 = 2;
    uVar1 = 0x10000;
  }
  return CONCAT44(uVar1,uVar2);
}
