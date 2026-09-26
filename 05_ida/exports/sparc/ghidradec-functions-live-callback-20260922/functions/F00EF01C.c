
uint __mapStrHash(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    while (bVar1 != 0) {
      uVar2 = bVar1 ^ uVar2;
      if (param_2[1] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[1] << 8;
      if (param_2[2] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[2] << 0x10;
      pbVar3 = param_2 + 3;
      if (*pbVar3 == 0) {
        return uVar2;
      }
      param_2 = param_2 + 4;
      uVar2 = uVar2 ^ (uint)*pbVar3 << 0x18;
      bVar1 = *param_2;
    }
  }
  return uVar2;
}

