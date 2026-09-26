
uint sub_40327F0(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    do {
      if (*(char *)(uVar4 + *(int *)(param_1 + 0x14)) == -1) {
        *param_3 = uVar4;
        pbVar5 = (byte *)(*(int *)(param_1 + 0x14) + uVar4);
        bVar3 = *pbVar5;
        if (bVar3 == 0) {
          return 0xffffffff;
        }
        uVar2 = (1 << (param_2 & 0x3f)) - 1;
        uVar4 = 0;
        if (-param_2 == -9) {
          return 0xffffffff;
        }
        do {
          uVar1 = uVar2 & bVar3;
          if (uVar2 == uVar1) {
            *pbVar5 = ~(byte)(uVar1 << (uVar4 & 0x3f)) & *pbVar5;
            return uVar4;
          }
          bVar3 = bVar3 >> 1;
          uVar4 = uVar4 + 1;
        } while (uVar4 < -param_2 + 9);
        return 0xffffffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x1c));
  }
  return 0xffffffff;
}

