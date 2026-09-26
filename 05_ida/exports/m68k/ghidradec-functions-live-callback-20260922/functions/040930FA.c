
undefined8 __lshldi3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    uVar1 = 0x20 - param_4;
    if ((int)uVar1 < 1) {
      param_1 = param_2 << (-uVar1 & 0x3f);
      param_2 = 0;
    }
    else {
      uVar1 = param_2 >> (uVar1 & 0x3f);
      param_2 = param_2 << (param_4 & 0x3f);
      param_1 = uVar1 | param_1 << (param_4 & 0x3f);
    }
  }
  return CONCAT44(param_1,param_2);
}

