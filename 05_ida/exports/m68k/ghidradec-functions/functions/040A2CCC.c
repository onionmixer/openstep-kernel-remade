
void stan(void)

{
  sword sVar2;
  uint uVar1;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  fVar4 = (float10)*in_A0;
  uVar1 = CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
          0x7fffffff;
  if (uVar1 < 0x3fd78000) {
    t_frcinx();
    return;
  }
  if (uVar1 < 0x4004bc7e) {
    uVar1 = (int)(fVar4 * (float10)0.6366197723675814) << 0x1f;
  }
  else {
    fVar3 = (float10)0.0;
    if (uVar1 == 0x7ffeffff) {
      *(undefined4 *)(unaff_A6 + -100) = 0x7ffe0000;
      *(undefined4 *)(unaff_A6 + -0x60) = 0xc90fdaa2;
      *(undefined4 *)(unaff_A6 + -0x5c) = 0;
      *(undefined4 *)(unaff_A6 + -0x40) = 0x7fdc0000;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x85a308d3;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      if (FLOAT_UNKNOWN <= fVar4 || fVar4 == FLOAT_UNKNOWN) {
        *(word *)(unaff_A6 + -100) = *(word *)(unaff_A6 + -100) | 0x8000;
        *(word *)(unaff_A6 + -0x40) = *(word *)(unaff_A6 + -0x40) | 0x8000;
      }
      fVar3 = fVar4 + (float10)*(undefined (*) [12])(unaff_A6 + -100);
      fVar4 = fVar3 + (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
      fVar3 = (fVar3 - fVar4) + (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
    }
    while( true ) {
      *(undefined (*) [12])(unaff_A6 + -0x30) = (undefined  [12])fVar4;
      uVar1 = *(word *)(unaff_A6 + -0x30) & 0x7fff;
      if ((int)(uVar1 - 0x3fff) < 0x1d) {
        sVar2 = 0;
        *(undefined4 *)(unaff_A6 + -0x50) = 1;
      }
      else {
        sVar2 = (sword)uVar1 + -0x401a;
        *(undefined4 *)(unaff_A6 + -0x50) = 0;
      }
      *(undefined4 *)(unaff_A6 + -0x70) = 0xa2f9836e;
      *(undefined4 *)(unaff_A6 + -0x6c) = 0x4e44152a;
      *(sword *)(unaff_A6 + -0x74) = 0x3ffe - sVar2;
      *(uint *)(unaff_A6 + -0x54) = (*(word *)(unaff_A6 + -0x30) & 0x8000) << 0x10 | 0x5f000000;
      *(sword *)(unaff_A6 + -100) = sVar2 + 0x3fff;
      *(undefined2 *)(unaff_A6 + -0x62) = 0;
      *(undefined4 *)(unaff_A6 + -0x60) = 0xc90fdaa2;
      *(undefined4 *)(unaff_A6 + -0x5c) = 0;
      fVar6 = (fVar4 * (float10)*(undefined (*) [12])(unaff_A6 + -0x74) +
              (float10)*(float *)(unaff_A6 + -0x54)) - (float10)*(float *)(unaff_A6 + -0x54);
      *(sword *)(unaff_A6 + -0x40) = sVar2 + 0x3fdd;
      *(undefined2 *)(unaff_A6 + -0x3e) = 0;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x85a308d3;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      fVar8 = fVar6 * (float10)*(undefined (*) [12])(unaff_A6 + -100);
      fVar9 = fVar6 * (float10)*(undefined (*) [12])(unaff_A6 + -0x40);
      fVar7 = fVar8 + fVar9;
      fVar5 = fVar4 - fVar7;
      fVar3 = fVar3 - ((fVar8 - fVar7) + fVar9);
      fVar4 = fVar5 + fVar3;
      if (0 < *(int *)(unaff_A6 + -0x50)) break;
      fVar3 = fVar3 + (fVar5 - fVar4);
    }
    *(int *)(unaff_A6 + -0x44) = (int)fVar6;
    uVar1 = *(uint *)(unaff_A6 + -0x44) << 0x1f | *(uint *)(unaff_A6 + -0x44) >> 1;
  }
  if (-1 < (int)uVar1) {
    t_frcinx();
    return;
  }
  t_frcinx();
  return;
}
