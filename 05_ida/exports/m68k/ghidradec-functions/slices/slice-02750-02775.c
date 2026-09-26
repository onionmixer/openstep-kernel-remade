/* GHIDRADEC_FUNCTION index=2750 start=0x40a207e */

void ssin(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 0;
  func_0x040a2094();
  return;
}
/* GHIDRADEC_FUNCTION index=2751 start=0x40a208c */

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
/* GHIDRADEC_FUNCTION index=2752 start=0x40a242c */

void ssincosd(void)

{
  sto_cos();
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2753 start=0x40a2440 */

void ssincos(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar5;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 4;
  fVar5 = (float10)*in_A0;
  uVar1 = *(undefined4 *)*in_A0;
  uVar2 = *(undefined2 *)(*in_A0 + 4);
  *(undefined (*) [12])(unaff_A6 + -0x20) = (undefined  [12])fVar5;
  uVar3 = CONCAT22((sword)((uint)uVar1 >> 0x10),uVar2) & 0x7fffffff;
  if (uVar3 < 0x3fd78000) {
    *(undefined2 *)(unaff_A6 + -0x1e) = 0;
    sto_cos();
    t_frcinx();
    return;
  }
  if (0x4004bc7d < uVar3) {
    func_0x040a2288();
    return;
  }
  *(int *)(unaff_A6 + -0x50) = (int)(fVar5 * (float10)0.6366197723675814);
  fVar5 = (fVar5 - (float10)*(undefined (*) [12])(&word_40A2AB6 + *(int *)(unaff_A6 + -0x50) * 8)) -
          (float10)*(float *)(*(int *)(unaff_A6 + -0x50) * 0x10 + 0x40a2ac2);
  uVar3 = *(uint *)(unaff_A6 + -0x50);
  uVar4 = uVar3 >> 1;
  if ((uVar3 & 1) != 0) {
    *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])fVar5;
    *(uint *)(unaff_A6 + -0x74) = (uVar3 ^ uVar4) << 0x1f ^ *(uint *)(unaff_A6 + -0x74);
    *(undefined4 *)(unaff_A6 + -0x54) = 0x3f800000;
    *(uint *)(unaff_A6 + -0x54) = uVar4 << 0x1f ^ *(uint *)(unaff_A6 + -0x54);
    *(undefined (*) [12])(unaff_A6 + -100) = (undefined  [12])(fVar5 * fVar5);
    *(uint *)(unaff_A6 + -100) = uVar4 << 0x1f ^ *(uint *)(unaff_A6 + -100);
    sto_cos();
    t_frcinx();
    return;
  }
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])fVar5;
  *(undefined (*) [12])(unaff_A6 + -100) = (undefined  [12])(fVar5 * fVar5);
  uVar4 = uVar4 << 0x1f;
  *(uint *)(unaff_A6 + -0x74) = uVar4 ^ *(uint *)(unaff_A6 + -0x74);
  *(uint *)(unaff_A6 + -100) = uVar4 ^ *(uint *)(unaff_A6 + -100);
  *(uint *)(unaff_A6 + -0x54) = uVar4 | 0x3f800000;
  sto_cos();
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2754 start=0x40a2744 */

void ssinhd(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2755 start=0x40a274a */

void ssinh(void)

{
  uint uVar1;
  undefined (*in_A0) [12];
  
  uVar1 = CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
          0x7fffffff;
  if (uVar1 < 0x400cb168) {
    *(float10 *)*in_A0 = ABS((float10)*in_A0);
    setoxm1();
    t_frcinx();
    return;
  }
  if (uVar1 < 0x400cb2b4) {
    *(float10 *)*in_A0 =
         (ABS((float10)*in_A0) - (float10)11354.443964752463) - (float10)8.971359657490228e-13;
    setox();
    t_frcinx();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2756 start=0x40a2cc6 */

void stand(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2757 start=0x40a2ccc */

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
/* GHIDRADEC_FUNCTION index=2758 start=0x40a2ff4 */

void stanhd(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2759 start=0x40a2ffa */

void stanh(void)

{
  uint uVar1;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar2;
  
  *(undefined (*) [12])(unaff_A6 + -0x20) = (undefined  [12])(float10)*in_A0;
  uVar1 = CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4));
  *(uint *)(unaff_A6 + -0x20) = uVar1;
  uVar1 = uVar1 & 0x7fffffff;
  if (iRam3fd78000 <= (int)uVar1 && (int)uVar1 <= iRam3fd78004) {
    *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x20);
    *(uint *)(unaff_A6 + -0x20) = (*(uint *)(unaff_A6 + -0x20) & 0x7fff0000) + 0x10000;
    *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0x80000000;
    *(float10 *)*in_A0 = (float10)*(undefined (*) [12])(unaff_A6 + -0x20);
    fVar2 = (float10)setoxm1();
    *(undefined (*) [12])(unaff_A6 + -0x10) = (undefined  [12])(fVar2 + (float10)2.0);
    *(uint *)(unaff_A6 + -0x10) = *(uint *)(unaff_A6 + -0x44) ^ *(uint *)(unaff_A6 + -0x10);
    t_frcinx();
    return;
  }
  if (0x3fff7fff < uVar1) {
    if (uVar1 < 0x40048aa2) {
      *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x20);
      *(uint *)(unaff_A6 + -0x20) = (*(uint *)(unaff_A6 + -0x20) & 0x7fff0000) + 0x10000;
      *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0x80000000;
      *(float10 *)*in_A0 = (float10)*(undefined (*) [12])(unaff_A6 + -0x20);
      setox();
      t_frcinx();
      return;
    }
    t_frcinx();
    return;
  }
  *(undefined2 *)(unaff_A6 + -0x1e) = 0;
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2760 start=0x40a314e */

uint sto_cos(void)

{
  uint uVar1;
  byte bVar2;
  int unaff_A6;
  unkbyte10 in_FP1;
  undefined4 uStack_c;
  
  uVar1 = (*(uint *)(unaff_A6 + -0xe4) & 0x7ffff) >> 0x10;
  bVar2 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 0xd) >> 0x1d);
  if (3 < bVar2) {
    uVar1 = 1 << (7 - uVar1 & 0x1f);
    uStack_c = (undefined4)((unkuint10)in_FP1 >> 0x30);
    fmovem(uStack_c,uVar1);
    return uVar1;
  }
  if (bVar2 == 0) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP1;
    return uVar1;
  }
  if (bVar2 == 1) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
    return uVar1;
  }
  if (bVar2 != 2) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = in_FP1;
    return uVar1;
  }
  *(unkbyte10 *)(unaff_A6 + -0x98) = in_FP1;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2761 start=0x40a31ae */

uint sto_res(void)

{
  uint uVar1;
  byte bVar2;
  int unaff_A6;
  unkbyte10 in_FP0;
  undefined4 uStack_c;
  
  uVar1 = (*(uint *)(unaff_A6 + -0xe4) & 0x3ffffff) >> 0x17;
  bVar2 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 6) >> 0x1d);
  if (3 < bVar2) {
    uVar1 = 1 << (7 - uVar1 & 0x1f);
    uStack_c = (undefined4)((unkuint10)in_FP0 >> 0x30);
    fmovem(uStack_c,uVar1);
    return uVar1;
  }
  if (bVar2 == 0) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
    return uVar1;
  }
  if (bVar2 == 1) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP0;
    return uVar1;
  }
  if (bVar2 != 2) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = in_FP0;
    return uVar1;
  }
  *(unkbyte10 *)(unaff_A6 + -0x98) = in_FP0;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2762 start=0x40a36ae */

void stwotoxd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2763 start=0x40a36cc */

void stwotox(void)

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
  if ((0x3fb97fff < uVar3) && (uVar3 < 0x400d80c1)) {
    *(int *)(unaff_A6 + -0x54) = (int)(fVar6 * (float10)64.0);
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
    func_0x040a38b6();
    return;
  }
  if (uVar3 < 0x3fff8001) {
    t_frcinx();
    return;
  }
  if (*(int *)(unaff_A6 + -0x74) < 0) {
    *(byte *)in_A0 = *(byte *)in_A0 & 0x7f;
    t_unfl();
    return;
  }
  *(byte *)in_A0 = *(byte *)in_A0 & 0x7f;
  t_ovfl();
  return;
}
/* GHIDRADEC_FUNCTION index=2764 start=0x40a37ce */

void stentoxd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2765 start=0x40a37ec */

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
/* GHIDRADEC_FUNCTION index=2766 start=0x40a40b8 */

void ovf_r_k(void)

{
  byte bVar1;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + -0xcc);
  *(byte *)(unaff_A6 + -0xcc) = bVar1 & 0x7f;
  *(char *)(unaff_A6 + -0xca) = -((bVar1 & 0x80) != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2767 start=0x40a40c6 */

void ovf_r_x2(void)

{
  word wVar1;
  undefined4 in_D0;
  uint uVar2;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x44;
    if (wVar1 == 0x40) goto loc_40A416C;
    if (wVar1 == 0x44) goto loc_40A4174;
    wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x7f;
    if ((wVar1 == 0x27) || (wVar1 == 0x24)) goto loc_40A4164;
  }
  else {
    uVar2 = CONCAT22((sword)((uint)in_D0 >> 0x10),*(undefined2 *)(unaff_A6 + -0xf0)) & 0xffff0060;
    if (uVar2 == 0x40) {
loc_40A416C:
      ovf_res();
      return;
    }
    if (uVar2 == 0x60) {
loc_40A4174:
      ovf_res();
      return;
    }
    wVar1 = *(word *)(unaff_A6 + -0xf0) & 0x7f;
    if ((wVar1 == 0x33) || (wVar1 == 0x30)) {
loc_40A4164:
      ovf_res();
      return;
    }
  }
  ovf_res();
  return;
}
/* GHIDRADEC_FUNCTION index=2768 start=0x40a4188 */

void ovf_r_x3(void)

{
  g_dfmtou();
  return;
}
/* GHIDRADEC_FUNCTION index=2769 start=0x40a418e */

void ovf_res(void)

{
  int in_D0;
  int unaff_A6;
  
                    /* WARNING: Could not recover jumptable at 0x040a41a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&loc_40A4078 + ((*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c | in_D0 << 2) * 4)
  )();
  return;
}
/* GHIDRADEC_FUNCTION index=2770 start=0x40a432c */

undefined4 get_fline(void)

{
  mem_read();
  return 0;
}
/* GHIDRADEC_FUNCTION index=2771 start=0x40a4346 */

uint g_rndpr(void)

{
  word wVar1;
  sword sVar3;
  uint uVar2;
  int unaff_A6;
  
  sVar3 = g_opcls();
  if (sVar3 == 3) {
    uVar2 = g_dfmtou();
    return uVar2;
  }
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    uVar2 = *(uint *)(unaff_A6 + -0xe4) & 0x440000;
    if (uVar2 == 0x400000) {
      return 1;
    }
    if (uVar2 == 0x440000) {
      return 2;
    }
    uVar2 = *(uint *)(unaff_A6 + -0xe4) & 0x7f0000;
    if (uVar2 == 0x270000) {
      return 0;
    }
    if (uVar2 == 0x240000) {
      return 0;
    }
  }
  else {
    uVar2 = (*(uint *)(unaff_A6 + -0xf0) & 0x7fffff) >> 0x15;
    if (uVar2 == 2) {
      return 1;
    }
    if (uVar2 == 3) {
      return 2;
    }
    wVar1 = *(word *)(unaff_A6 + -0xf0) & 0x7f;
    if ((wVar1 == 0x33) || (wVar1 == 0x30)) {
      return 0;
    }
  }
  return (*(uint *)(unaff_A6 + -0x80) & 0xff) >> 6;
}
/* GHIDRADEC_FUNCTION index=2772 start=0x40a4412 */

uint g_opcls(void)

{
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    return 0;
  }
  return *(uint *)(unaff_A6 + -0xe4) >> 0x1d;
}
/* GHIDRADEC_FUNCTION index=2773 start=0x40a442c */

undefined4 g_dfmtou(void)

{
  byte bVar1;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    return 0;
  }
  bVar1 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d);
  if (bVar1 == 1) {
    return 1;
  }
  if (bVar1 == 5) {
    return 2;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2774 start=0x40a4504 */

void unf_sub(void)

{
  int in_D0;
  int unaff_A6;
  
                    /* WARNING: Could not recover jumptable at 0x040a4518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(((*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c | in_D0 << 2) * 4 + 0x40a44c4))()
  ;
  return;
}

