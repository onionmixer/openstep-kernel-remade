
uint sub_408CE7E(byte param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((char)param_1 < '\0') {
    uVar1 = 0x20;
  }
  if (dword_40B51B8 == 1) {
    if ((param_1 & 0x20) != 0) {
      uVar1 = uVar1 | 0x10;
    }
  }
  else if (dword_40B51B8 < 2) {
    if (dword_40B51B8 != 0) {
      return uVar1;
    }
    if ((param_1 & 0x20) == 0) {
      uVar1 = uVar1 | 0x10;
    }
  }
  else {
    if (dword_40B51B8 != 2) {
      return uVar1;
    }
    if ((param_1 & 8) != 0) {
      uVar1 = uVar1 | 0x10;
    }
    if ((param_1 & 0x20) == 0) {
      return uVar1;
    }
  }
  return uVar1 | 8;
}
