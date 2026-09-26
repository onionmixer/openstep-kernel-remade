
void scos(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  sword sVar5;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 1;
  fVar7 = (float10)*in_A0;
  uVar1 = *(undefined4 *)*in_A0;
  uVar2 = *(undefined2 *)(*in_A0 + 4);
  *(undefined (*) [12])(unaff_A6 + -0x20) = (undefined  [12])fVar7;
  uVar3 = CONCAT22((sword)((uint)uVar1 >> 0x10),uVar2) & 0x7fffffff;
  if (uVar3 < 0x3fd78000) {
    if (*(int *)(unaff_A6 + -0x44) < 1) {
      *(undefined2 *)(unaff_A6 + -0x1e) = 0;
      t_frcinx();
      return;
    }
    t_frcinx();
    return;
  }
  if (uVar3 < 0x4004bc7e) {
    *(int *)(unaff_A6 + -0x50) = (int)(fVar7 * (float10)0.6366197723675814);
    fVar7 = (fVar7 - (float10)*(undefined (*) [12])(&word_40A2AB6 + *(int *)(unaff_A6 + -0x50) * 8))
            - (float10)*(float *)(*(int *)(unaff_A6 + -0x50) * 0x10 + 0x40a2ac2);
  }
  else {
    fVar6 = (float10)0.0;
    if (uVar3 == 0x7ffeffff) {
      *(undefined4 *)(unaff_A6 + -100) = 0x7ffe0000;
      *(undefined4 *)(unaff_A6 + -0x60) = 0xc90fdaa2;
      *(undefined4 *)(unaff_A6 + -0x5c) = 0;
      *(undefined4 *)(unaff_A6 + -0x40) = 0x7fdc0000;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x85a308d3;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      if (FLOAT_UNKNOWN <= fVar7 || fVar7 == FLOAT_UNKNOWN) {
        *(word *)(unaff_A6 + -100) = *(word *)(unaff_A6 + -100) | 0x8000;
        *(word *)(unaff_A6 + -0x40) = *(word *)(unaff_A6 + -0x40) | 0x8000;
      }
      fVar6 = fVar7 + (float10)*(undefined (*) [12])(unaff_A6 + -100);
      fVar7 = fVar6 + (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
      fVar6 = (fVar6 - fVar7) + (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
    }
    while( true ) {
      *(undefined (*) [12])(unaff_A6 + -0x30) = (undefined  [12])fVar7;
      uVar3 = *(word *)(unaff_A6 + -0x30) & 0x7fff;
      if ((int)(uVar3 - 0x3fff) < 0x1d) {
        sVar5 = 0;
        *(undefined4 *)(unaff_A6 + -0x50) = 1;
      }
      else {
        sVar5 = (sword)uVar3 + -0x401a;
        *(undefined4 *)(unaff_A6 + -0x50) = 0;
      }
      *(undefined4 *)(unaff_A6 + -0x70) = 0xa2f9836e;
      *(undefined4 *)(unaff_A6 + -0x6c) = 0x4e44152a;
      *(sword *)(unaff_A6 + -0x74) = 0x3ffe - sVar5;
      *(uint *)(unaff_A6 + -0x54) = (*(word *)(unaff_A6 + -0x30) & 0x8000) << 0x10 | 0x5f000000;
      *(sword *)(unaff_A6 + -100) = sVar5 + 0x3fff;
      *(undefined2 *)(unaff_A6 + -0x62) = 0;
      *(undefined4 *)(unaff_A6 + -0x60) = 0xc90fdaa2;
      *(undefined4 *)(unaff_A6 + -0x5c) = 0;
      fVar9 = (fVar7 * (float10)*(undefined (*) [12])(unaff_A6 + -0x74) +
              (float10)*(float *)(unaff_A6 + -0x54)) - (float10)*(float *)(unaff_A6 + -0x54);
      *(sword *)(unaff_A6 + -0x40) = sVar5 + 0x3fdd;
      *(undefined2 *)(unaff_A6 + -0x3e) = 0;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x85a308d3;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      fVar11 = fVar9 * (float10)*(undefined (*) [12])(unaff_A6 + -100);
      fVar12 = fVar9 * (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
      fVar10 = fVar11 + fVar12;
      fVar8 = fVar7 - fVar10;
      fVar6 = fVar6 - ((fVar11 - fVar10) + fVar12);
      fVar7 = fVar8 + fVar6;
      if (0 < *(int *)(unaff_A6 + -0x50)) break;
      fVar6 = fVar6 + (fVar8 - fVar7);
    }
    *(int *)(unaff_A6 + -0x50) = (int)fVar9;
    if (3 < *(int *)(unaff_A6 + -0x44)) {
      func_0x040a24aa();
      return;
    }
  }
  uVar3 = *(int *)(unaff_A6 + -0x44) + *(int *)(unaff_A6 + -0x50);
  uVar4 = uVar3 >> 1;
  if ((uVar3 & 1) == 0) {
    *(undefined (*) [12])(unaff_A6 + -0x20) = (undefined  [12])fVar7;
    *(uint *)(unaff_A6 + -0x20) = uVar4 << 0x1f ^ *(uint *)(unaff_A6 + -0x20);
    t_frcinx();
    return;
  }
  *(undefined (*) [12])(unaff_A6 + -0x20) = (undefined  [12])(fVar7 * fVar7);
  uVar4 = uVar4 << 0x1f;
  *(uint *)(unaff_A6 + -0x20) = uVar4 ^ *(uint *)(unaff_A6 + -0x20);
  *(uint *)(unaff_A6 + -0x54) = uVar4 | 0x3f800000;
  t_frcinx();
  return;
}

