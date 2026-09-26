
uint sub_408D284(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x10) != 0) {
    uVar1 = 0x40;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1;
}

