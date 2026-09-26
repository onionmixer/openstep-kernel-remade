
undefined4 _itimerfix(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*param_1 < 0x5f5e101) && (uVar1 = param_1[1], uVar1 < 1000000)) {
    if ((*param_1 == 0) && ((uVar1 != 0 && ((int)uVar1 < (int)_tick)))) {
      param_1[1] = _tick;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}

