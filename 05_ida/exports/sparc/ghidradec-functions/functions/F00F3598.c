
uint __strhash(byte *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ *param_1;
    if (param_1[1] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)param_1[1] << 8;
    if (param_1[2] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)param_1[2] << 0x10;
    if (param_1[3] == 0) break;
    uVar1 = uVar1 ^ (uint)param_1[3] << 0x18;
    param_1 = param_1 + 4;
  }
  return uVar1;
}
