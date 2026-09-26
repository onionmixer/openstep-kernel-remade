
void ap_st_z(void)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  uint *in_A0;
  int unaff_A6;
  
  if (*(int *)(unaff_A6 + -0x54) < 0x1c) {
    return;
  }
  if ((*in_A0 & 0x40000000) != 0) {
    return;
  }
  iVar1 = 0;
  if ((*in_A0 & 0xf) == 0) {
    iVar1 = 1;
    uVar4 = in_A0[1];
    if (uVar4 == 0) {
      iVar1 = 9;
      uVar4 = in_A0[2];
    }
    iVar3 = 0;
    sVar2 = 7;
    do {
      if ((uVar4 << iVar3) >> 0x1c != 0) break;
      iVar3 = iVar3 + 4;
      iVar1 = iVar1 + 1;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  if (*(int *)(unaff_A6 + -0x54) < iVar1) {
    *in_A0 = *in_A0 | 0x40000000;
  }
  do {
    iVar1 = iVar1 >> 1;
  } while (iVar1 != 0);
  pwrten();
  return;
}

