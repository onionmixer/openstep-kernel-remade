
float10 ap_st_n(void)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  uint *in_A0;
  int unaff_A6;
  float10 in_FP0;
  float10 fVar5;
  
  uVar1 = 0;
  uVar4 = in_A0[2];
  if (uVar4 == 0) {
    uVar1 = 8;
    uVar4 = in_A0[1];
  }
  iVar3 = 0x1c;
  sVar2 = 7;
  do {
    if ((uVar4 << iVar3) >> 0x1c != 0) break;
    iVar3 = iVar3 + -4;
    uVar1 = uVar1 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  if (*(int *)(unaff_A6 + -0x54) <= (int)uVar1) {
    *in_A0 = *in_A0 & 0xbfffffff;
  }
  iVar3 = 0;
  fVar5 = (float10)1.0;
  do {
    uVar4 = uVar1 & 1;
    uVar1 = (int)uVar1 >> 1;
    if (uVar4 != 0) {
      fVar5 = fVar5 * (float10)*(undefined (*) [12])(ptenrn + iVar3);
    }
    iVar3 = iVar3 + 0xc;
  } while (uVar1 != 0);
  return in_FP0 / fVar5;
}

