
uint sub_408D24A(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x40) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}
