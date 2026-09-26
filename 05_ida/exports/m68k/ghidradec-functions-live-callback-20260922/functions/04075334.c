
undefined4 _odread(word param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (param_1 & 0xff) >> 3;
  if (uVar1 < 0x1f) {
    uVar2 = _physio(_odstrategy,DAT_40c3eee + uVar1 * 0xda,(int)(sword)param_1,1,_odminphys,param_2,
                    0x400);
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}

