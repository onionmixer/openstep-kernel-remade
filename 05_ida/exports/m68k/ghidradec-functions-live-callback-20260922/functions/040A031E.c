
void setox(void)

{
  int iVar1;
  undefined auVar2 [12];
  uint uVar3;
  sword sVar4;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  uVar3 = *(uint *)*in_A0 & 0x7fff0000;
  if (uVar3 < 0x3fbe0000) {
    t_frcinx();
    return;
  }
  uVar3 = CONCAT22((sword)(uVar3 >> 0x10),*(undefined2 *)(*in_A0 + 4));
  if (uVar3 < 0x400cb167) {
    auVar2 = *in_A0;
    *(undefined4 *)(unaff_A6 + -0x50) = 0;
    *(int *)(unaff_A6 + -0x54) = (int)((float)auVar2 * 92.33248);
    sVar4 = (sword)(*(int *)(unaff_A6 + -0x54) >> 6);
    *(undefined2 *)(unaff_A6 + -0x54) = 0x3fdc;
  }
  else {
    if (0x400cb27c < uVar3) {
      iVar1 = *(int *)*in_A0;
      (*in_A0)[0] = (*in_A0)[0] & 0x7f;
      if (-1 < iVar1) {
        t_ovfl();
        return;
      }
      return;
    }
    auVar2 = *in_A0;
    *(undefined4 *)(unaff_A6 + -0x50) = 1;
    *(int *)(unaff_A6 + -0x54) = (int)((float)auVar2 * 92.33248);
    iVar1 = *(int *)(unaff_A6 + -0x54);
    *(int *)(unaff_A6 + -0x54) = iVar1 >> 6;
    iVar1 = iVar1 >> 7;
    *(int *)(unaff_A6 + -0x54) = *(int *)(unaff_A6 + -0x54) - iVar1;
    *(sword *)(unaff_A6 + -100) = (sword)iVar1 + 0x3fff;
    *(undefined2 *)(unaff_A6 + -0x62) = 0;
    *(undefined4 *)(unaff_A6 + -0x60) = 0x80000000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    sVar4 = (sword)*(undefined4 *)(unaff_A6 + -0x54);
  }
  *(sword *)(unaff_A6 + -0x74) = sVar4 + 0x3fff;
  *(undefined2 *)(unaff_A6 + -0x72) = 0;
  *(undefined4 *)(unaff_A6 + -0x70) = 0x80000000;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  t_frcinx();
  return;
}

