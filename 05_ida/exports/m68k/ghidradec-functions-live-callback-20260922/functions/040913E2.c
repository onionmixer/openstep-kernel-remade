
int _tm_to_sec(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0x46;
  iVar2 = 0;
  iVar3 = iVar2;
  if (0x46 < param_1[5]) {
    do {
      iVar2 = iVar3 + 0x16d;
      if ((uVar1 & 3) == 0) {
        iVar2 = iVar3 + 0x16e;
      }
      uVar1 = uVar1 + 1;
      iVar3 = iVar2;
    } while ((int)uVar1 < param_1[5]);
  }
  iVar2 = param_1[3] + (int)(sword)(&unk_40B2890)[param_1[4]] + -1 + iVar2;
  if (((*(uint *)((int)param_1 + 0x17) & 0x3ffffff) >> 0x18 == 0) && (2 < param_1[4])) {
    iVar2 = iVar2 + 1;
  }
  return *param_1 + param_1[2] * 0xe10 + iVar2 * 0x15180 + param_1[1] * 0x3c;
}

