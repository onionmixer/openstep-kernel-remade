
float10 bindec(void)

{
  sword sVar1;
  int in_D0;
  word wVar3;
  uint uVar2;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar7;
  float10 fVar8;
  
  *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)*in_A0;
  *(undefined *)(unaff_A6 + -0x4b) = 0;
  if ((*(word *)(unaff_A6 + -0xe8) & 0xe000) != 0) {
    wVar3 = *(word *)*in_A0 & 0x7fff;
    uVar2 = *(uint *)(*in_A0 + 4);
    iVar4 = *(int *)(*in_A0 + 8);
    do {
      wVar3 = wVar3 - 1;
      bVar6 = iVar4 < 0;
      iVar4 = iVar4 << 1;
      uVar2 = uVar2 << 1 | (uint)bVar6;
    } while (-1 < (int)uVar2);
    if ((sword)wVar3 < 1) {
      *(undefined *)(unaff_A6 + -0x4b) = 0xff;
    }
    *(word *)*in_A0 = wVar3 & 0x7fff;
    *(uint *)(*in_A0 + 4) = uVar2;
    *(int *)(*in_A0 + 8) = iVar4;
  }
  *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)*in_A0;
  *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(*in_A0 + 4);
  *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(*in_A0 + 8);
  *(uint *)(unaff_A6 + -100) = *(uint *)(unaff_A6 + -100) & 0x7fffffff;
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    sVar1 = *(sword *)(unaff_A6 + -100);
    *(undefined2 *)(unaff_A6 + -100) = 0x3fff;
    fVar8 = (float10)*(undefined (*) [12])(unaff_A6 + -100);
    fVar7 = (fVar8 + (float10)(sVar1 + -0x3fff)) - (float10)1.0;
    if (fVar8 == FLOAT_UNKNOWN || FLOAT_UNKNOWN <= fVar8) {
      iVar4 = (int)(fVar7 * (float10)tbyte_409AB9C);
    }
    else {
      iVar4 = (int)(fVar7 * (float10)tbyte_409ABAC);
    }
  }
  else {
    iVar4 = -0x1345;
  }
  iVar5 = in_D0;
  if (in_D0 < 1) {
    iVar5 = (iVar4 - in_D0) + 1;
  }
  if (iVar5 < 1) {
    iVar5 = 1;
  }
  else if ((0x11 < iVar5) && (iVar5 = 0x11, 0 < in_D0)) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2080;
  }
  if ((in_D0 < 1) && (iVar4 <= in_D0)) {
    iVar4 = in_D0;
  }
  uVar2 = (iVar4 + 1) - iVar5;
  bVar6 = false;
  if ((int)uVar2 < 0) {
    bVar6 = true;
    if ((int)uVar2 < -0x132b) {
      uVar2 = uVar2 + 0x18;
    }
    uVar2 = -uVar2;
  }
  do {
    uVar2 = uVar2 >> 1;
  } while (uVar2 != 0);
  if (bVar6) {
    return ABS((float10)*in_A0);
  }
  fVar8 = (float10)func_0x0409ae78();
  return fVar8;
}

