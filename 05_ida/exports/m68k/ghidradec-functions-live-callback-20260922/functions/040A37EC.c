
void stentox(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  sword sVar5;
  float10 *in_A0;
  int unaff_A6;
  float10 fVar6;
  
  fVar6 = *in_A0;
  uVar1 = *(undefined4 *)in_A0;
  uVar2 = *(undefined2 *)((int)in_A0 + 4);
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])fVar6;
  uVar3 = CONCAT22((sword)((uint)uVar1 >> 0x10),uVar2) & 0x7fffffff;
  if (uVar3 < 0x3fb98000) {
    func_0x040a378c();
    return;
  }
  if (0x400b9b07 < uVar3) {
    func_0x040a378c();
    return;
  }
  *(int *)(unaff_A6 + -0x54) = (int)(fVar6 * (float10)212.60339807279118);
  uVar3 = *(uint *)(unaff_A6 + -0x54);
  iVar4 = (uVar3 & 0x3f) * 0x10;
  sVar5 = (sword)((int)uVar3 >> 7);
  *(sword *)(unaff_A6 + -100) = ((sword)((int)uVar3 >> 6) - sVar5) + 0x3fff;
  *(undefined4 *)(unaff_A6 + -0x40) = *(undefined4 *)(&word_40A32AE + (uVar3 & 0x3f) * 8);
  *(undefined4 *)(unaff_A6 + -0x3c) = *(undefined4 *)(iVar4 + 0x40a32b2);
  *(undefined4 *)(unaff_A6 + -0x38) = *(undefined4 *)(iVar4 + 0x40a32b6);
  *(undefined2 *)(unaff_A6 + -0x30) = *(undefined2 *)(iVar4 + 0x40a32ba);
  *(undefined2 *)(unaff_A6 + -0x2e) = 0;
  *(undefined2 *)(unaff_A6 + -0x2c) = *(undefined2 *)(iVar4 + 0x40a32bc);
  *(undefined2 *)(unaff_A6 + -0x2a) = 0;
  *(undefined4 *)(unaff_A6 + -0x28) = 0;
  *(sword *)(unaff_A6 + -0x40) = sVar5 + *(sword *)(unaff_A6 + -0x40);
  *(sword *)(unaff_A6 + -0x30) = sVar5 + *(sword *)(unaff_A6 + -0x30);
  *(undefined2 *)(unaff_A6 + -0x62) = 0;
  *(undefined4 *)(unaff_A6 + -0x60) = 0x80000000;
  *(undefined4 *)(unaff_A6 + -0x5c) = 0;
  t_frcinx();
  return;
}

