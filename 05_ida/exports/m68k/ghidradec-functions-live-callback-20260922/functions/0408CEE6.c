
uint sub_408CEE6(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 4) != 0) {
    uVar1 = 0x80;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((-1 < dword_40B51B8) &&
     ((dword_40B51B8 < 2 || ((dword_40B51B8 == 2 && ((param_1 & 1) != 0)))))) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}

