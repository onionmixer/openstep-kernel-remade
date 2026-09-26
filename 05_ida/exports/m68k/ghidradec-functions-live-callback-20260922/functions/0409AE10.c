
/* WARNING: Removing unreachable block (ram,0x0409af82) */

unkbyte10 sc_mul(void)

{
  undefined (*pauVar1) [12];
  uint uVar2;
  float fVar3;
  undefined4 *puVar4;
  uint uVar5;
  word wVar6;
  undefined4 in_D1;
  sword unaff_D2w;
  sword sVar8;
  int iVar7;
  uint unaff_D4;
  undefined4 unaff_D5;
  int unaff_D6;
  int unaff_D7;
  undefined4 *in_A0;
  int in_A1;
  int iVar9;
  int extraout_A1;
  int unaff_A6;
  uint in_FPSR;
  float10 in_FP0;
  float10 fVar10;
  unkbyte10 Var11;
  unkint10 Var12;
  float10 in_FP1;
  float10 fVar13;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    if (unaff_D2w != 0) {
      in_FP0 = in_FP0 * (float10)*(undefined (*) [12])(in_A1 + 0x24) *
               (float10)*(undefined (*) [12])(in_A1 + 0x30);
    }
    fVar10 = in_FP0 * in_FP1;
  }
  else {
    uStack_10 = in_A0[2];
    uStack_14 = in_A0[1];
    uStack_18 = *in_A0;
    sVar8 = 0x12;
    puVar4 = &uStack_18;
    do {
      register0x0000003c = (BADSPACEBASE *)puVar4;
      *(undefined4 *)((int)register0x0000003c + -4) = 0;
      sVar8 = sVar8 + -1;
      puVar4 = (undefined4 *)((int)register0x0000003c + -4);
    } while (sVar8 != -1);
    *(undefined *)((int)register0x0000003c + -4) = *(undefined *)(unaff_A6 + -0x45);
    *(undefined *)((int)register0x0000003c + -3) = 0x60;
    *(undefined *)((int)register0x0000003c + 0x40) = 0x10;
    *(undefined2 *)((int)register0x0000003c + 0x3c) = 0x23;
    *(undefined *)((int)register0x0000003c + 4) = 0xfe;
    restoreFPUStateFrame(*(undefined4 *)((int)register0x0000003c + -4));
    fVar10 = in_FP0 * (float10)*(undefined (*) [12])(in_A1 + 0x24) *
             (float10)*(undefined (*) [12])(in_A1 + 0x30);
  }
  *(undefined (*) [12])(unaff_A6 + -100) = (undefined  [12])fVar10;
  if ((in_FPSR & 0x200) != 0) {
    *(uint *)(unaff_A6 + -0x5c) = *(uint *)(unaff_A6 + -0x5c) | 1;
    fVar10 = (float10)*(undefined (*) [12])(unaff_A6 + -100);
  }
  *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0x80);
  *(uint *)(unaff_A6 + -0x80) = *(uint *)(unaff_A6 + -0x80) & 0x30;
  *(int *)((int)register0x0000003c + -4) = in_A1;
  *(undefined4 **)((int)register0x0000003c + -8) = in_A0;
  *(undefined4 *)((int)register0x0000003c + -0xc) = in_D1;
  *(uint *)((int)register0x0000003c + -0x10) = in_FPSR;
  *(undefined4 *)((int)register0x0000003c + -0x14) = *(undefined4 *)(unaff_A6 + -0x54);
  *(undefined4 *)((int)register0x0000003c + -0x18) = *(undefined4 *)(unaff_A6 + -0x50);
  pauVar1 = (undefined (*) [12])(unaff_A6 + -100);
  *pauVar1 = (undefined  [12])fVar10;
  if (*(int *)(unaff_A6 + -0x50) < 0) {
    *(uint *)*pauVar1 = *(uint *)*pauVar1 | 0x80000000;
  }
  *(undefined4 *)((int)register0x0000003c + -0x1c) = *(undefined4 *)(unaff_A6 + -0x7c);
  *(undefined4 *)((int)register0x0000003c + -0x20) = 0x409aeda;
  fVar10 = (float10)sintdo();
  *(undefined *)(unaff_A6 + -0x7c) = *(undefined *)((int)register0x0000003c + -0x1c);
  *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)((int)register0x0000003c + -0x18);
  *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)((int)register0x0000003c + -0x14);
  iVar9 = *(int *)((int)register0x0000003c + -4);
  *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(unaff_A6 + -0x50);
  *(undefined4 *)(unaff_A6 + -0x80) = *(undefined4 *)(unaff_A6 + -0x54);
  if ((sword)((uint)unaff_D5 >> 0x10) == 0) {
    fVar13 = (float10)1.0;
    uVar5 = unaff_D4 - 1;
    iVar7 = 0;
    do {
      uVar2 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar2 != 0) {
        fVar13 = fVar13 * (float10)*(undefined (*) [12])(iVar9 + iVar7);
      }
      iVar7 = iVar7 + 0xc;
    } while (uVar5 != 0);
    if ((*(char *)(unaff_A6 + -0x4b) == '\0') &&
       (ABS(fVar10) - fVar13 != FLOAT_UNKNOWN && ABS(fVar10) - fVar13 < FLOAT_UNKNOWN)) {
      Var11 = func_0x0409ace6();
      return Var11;
    }
    fVar10 = ABS(fVar10);
    fVar13 = fVar13 * (float10)10.0;
    if (FLOAT_UNKNOWN <= fVar10 - fVar13 || fVar10 - fVar13 == FLOAT_UNKNOWN) {
      Var11 = func_0x0409ace6();
      return Var11;
    }
  }
  else {
    fVar13 = (float10)1.0;
    iVar7 = 0;
    do {
      uVar5 = unaff_D4 & 1;
      unaff_D4 = unaff_D4 >> 1;
      if (uVar5 != 0) {
        fVar13 = fVar13 * (float10)*(undefined (*) [12])(iVar9 + iVar7);
      }
      iVar7 = iVar7 + 0xc;
    } while (unaff_D4 != 0);
    fVar10 = ABS(fVar10);
    if (fVar10 - fVar13 == FLOAT_UNKNOWN) {
      fVar10 = fVar10 / (float10)10.0;
      unaff_D6 = unaff_D6 + 1;
      fVar13 = fVar13 * (float10)10.0;
    }
  }
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(fVar10 / fVar13);
  *(undefined4 *)(unaff_A6 + -0x70) = 0;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  uVar5 = *(uint *)*(undefined (*) [12])(unaff_A6 + -0x74);
  uVar5 = uVar5 << 0x10 | uVar5 >> 0x10;
  if ((uVar5 != 0) && (iVar9 = uVar5 - 0x3ffd, iVar9 < 1)) {
    uVar5 = -iVar9;
    do {
      wVar6 = (sword)uVar5 - 1;
      uVar5 = (uint)wVar6;
    } while (wVar6 != 0xffff);
  }
  *(undefined4 *)((int)register0x0000003c + -4) = 0x409b060;
  Var12 = binstr();
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    if (Var12 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = ABS((float)unaff_D6);
    }
  }
  else if (Var12 == 0) {
    if (unaff_D7 < 0) {
      fVar3 = ABS((float)unaff_D6);
    }
    else {
      fVar3 = 4933.0;
    }
  }
  else {
    fVar3 = ABS((float)unaff_D6);
  }
  *(undefined (*) [12])(unaff_A6 + -100) =
       (undefined  [12])(fVar3 / (float)*(undefined (*) [12])(extraout_A1 + 0x18));
  if (*(sword *)(unaff_A6 + -100) != 0) {
    sVar8 = -(*(sword *)(unaff_A6 + -100) + -0x3ffd);
    do {
      sVar8 = sVar8 + -1;
    } while (sVar8 != -1);
  }
  *(undefined4 *)((int)register0x0000003c + -4) = 0x409b10c;
  binstr();
  uVar5 = *(uint *)(unaff_A6 + -0x54);
  *(uint *)(unaff_A6 + -0x74) =
       *(uint *)(unaff_A6 + -0x74) & 0xf000ffff | (uVar5 >> 0xc & 0xfff) << 0x10;
  *(uint *)(unaff_A6 + -0x74) =
       *(uint *)(unaff_A6 + -0x74) & 0xffff0fff | (uVar5 >> 0x18 & 0xf) << 0xc;
  if ((char)(uVar5 >> 0x18) != '\0') {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2080;
  }
  iVar9 = 0;
  *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) & 0xf;
  if (*(int *)(unaff_A6 + -0x50) < 0) {
    iVar9 = 2;
  }
  if (unaff_D6 < 0) {
    iVar9 = iVar9 + 1;
  }
  *(uint *)(unaff_A6 + -0x74) = *(uint *)(unaff_A6 + -0x74) & 0x3fffffff | iVar9 << 0x1e;
  return *(unkbyte10 *)register0x0000003c;
}

