
undefined4 _in_canforward(uint param_1)

{
  undefined4 uVar1;
  
  if (((param_1 & 0xe0000000) == 0xe0000000) ||
     ((-1 < (int)param_1 && (((param_1 & 0xff000000) == 0 || ((param_1 & 0xff000000) == 0x7f)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

