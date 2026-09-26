/* GHIDRADEC_FUNCTION index=2750 start=0x40a2068 */

void scosd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2751 start=0x40a207e */

void ssin(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 0;
  func_0x040a2094();
  return;
}
/* GHIDRADEC_FUNCTION index=2752 start=0x40a208c */

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
/* GHIDRADEC_FUNCTION index=2753 start=0x40a242c */

void ssincosd(void)

{
  sto_cos();
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2754 start=0x40a2440 */

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
/* GHIDRADEC_FUNCTION index=2755 start=0x40a2744 */

void ssinhd(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2756 start=0x40a274a */

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
/* GHIDRADEC_FUNCTION index=2757 start=0x40a2cc6 */

void stand(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2758 start=0x40a2ccc */

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
/* GHIDRADEC_FUNCTION index=2759 start=0x40a2ff4 */

void stanhd(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2760 start=0x40a2ffa */

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
/* GHIDRADEC_FUNCTION index=2761 start=0x40a314e */

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
/* GHIDRADEC_FUNCTION index=2762 start=0x40a31ae */

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
/* GHIDRADEC_FUNCTION index=2763 start=0x40a36ae */

void stwotoxd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2764 start=0x40a36cc */

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
/* GHIDRADEC_FUNCTION index=2765 start=0x40a37ce */

void stentoxd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2766 start=0x40a37ec */

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
/* GHIDRADEC_FUNCTION index=2767 start=0x40a40b8 */

void ovf_r_k(void)

{
  byte bVar1;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + -0xcc);
  *(byte *)(unaff_A6 + -0xcc) = bVar1 & 0x7f;
  *(char *)(unaff_A6 + -0xca) = -((bVar1 & 0x80) != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2768 start=0x40a40c6 */

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
/* GHIDRADEC_FUNCTION index=2769 start=0x40a4188 */

void ovf_r_x3(void)

{
  g_dfmtou();
  return;
}
/* GHIDRADEC_FUNCTION index=2770 start=0x40a418e */

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
/* GHIDRADEC_FUNCTION index=2771 start=0x40a432c */

undefined4 get_fline(void)

{
  mem_read();
  return 0;
}
/* GHIDRADEC_FUNCTION index=2772 start=0x40a4346 */

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
/* GHIDRADEC_FUNCTION index=2773 start=0x40a4412 */

uint g_opcls(void)

{
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    return 0;
  }
  return *(uint *)(unaff_A6 + -0xe4) >> 0x1d;
}
/* GHIDRADEC_FUNCTION index=2774 start=0x40a442c */

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
/* GHIDRADEC_FUNCTION index=2775 start=0x40a4504 */

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
/* GHIDRADEC_FUNCTION index=2776 start=0x40a4712 */

void reg_dest(void)

{
  int in_D1;
  
                    /* WARNING: Could not recover jumptable at 0x040a471c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&loc_40A46B2 + in_D1 * 4))();
  return;
}
/* GHIDRADEC_FUNCTION index=2777 start=0x40a47ba */

void fpsp_bsun(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  restoreFPUStateFrame(uStack_c8);
  real_bsun();
  return;
}
/* GHIDRADEC_FUNCTION index=2778 start=0x40a47f4 */

//Decompiler native message:  Low-level Error: Overlapping input varnodes
//Decompiling function: fpsp_fline @ 0x40a47f4
/* GHIDRADEC_FUNCTION index=2779 start=0x40a48d2 */

void fpsp_operr(void)

{
  byte bVar2;
  int iVar1;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  byte bStack_ec;
  int iStack_e8;
  uint uStack_e0;
  word wStack_dc;
  int iStack_d8;
  uint uStack_d4;
  undefined4 uStack_c8;
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(uStack_c8);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  if ((uStack_e0 & 0x100000) == 0) {
loc_40A491C:
    restoreFPUStateFrame(uStack_c8);
    real_operr();
    return;
  }
  bVar2 = (byte)((uint)(iStack_e8 << 3) >> 0x1d);
  if (bVar2 != 0) {
    if (bVar2 == 4) {
      if ((bStack_ec & 0xe0) == 0x60) goto loc_40A4AD2;
      if ((uStack_d4 == 0xffff8000) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
      if ((wStack_dc & 0x7fff) == 0x3ffe) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
    }
    else {
      if (bVar2 != 6) goto loc_40A491C;
      if ((bStack_ec & 0xe0) == 0x60) goto loc_40A4AD2;
      if ((uStack_d4 == 0xffffff80) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
      if ((wStack_dc & 0x7fff) == 0x3ffe) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
    }
    goto loc_40A4AEA;
  }
  if ((bStack_ec & 0xe0) == 0x60) {
loc_40A4AD2:
    sub_40A4B34();
loc_40A4BC4:
    if (((uint)uStack_84 & 0x2000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      real_operr();
      return;
    }
  }
  else {
    if ((uStack_d4 == 0x80000000) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
      sub_40A4B34();
      goto loc_40A4BEC;
    }
    if ((wStack_dc & 0x7fff) != 0x3ffe) {
      if ((0x4000 < (wStack_dc & 0x7fff)) || ((wStack_dc & 0x7fff) == 0x4000)) goto loc_40A4AEA;
      if ((uStack_d4 & 0x7fff0000) != 0x7fff0000) {
        if ((int)uStack_d4 < 0) {
          if (iStack_d8 != -1) {
loc_40A4AEA:
            bStack_7e = bStack_7e & 0xfd;
            if ((sword)wStack_dc < 0) {
              sub_40A4B34();
            }
            else {
              sub_40A4B34();
            }
            goto loc_40A4BC4;
          }
        }
        else if (iStack_d8 != 0) goto loc_40A4AEA;
      }
    }
    sub_40A4B34();
  }
loc_40A4BEC:
  if ((bStack_7e & uStack_84._2_1_ & 3) == 0) {
    fpsp_done();
    return;
  }
  restoreFPUStateFrame(uStack_c8);
  real_inex();
  return;
}
/* GHIDRADEC_FUNCTION index=2780 start=0x40a4c48 */

void fpsp_ovfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  sub_40A4D76();
  if (((uint)puStack_84 & 0x1000) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_ovfl();
    return;
  }
  if (((uint)puStack_84 & 0x200) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_inex();
    return;
  }
  if ((uStack_e0 & 0x2000000) != 0) {
    b1238_fix();
    restoreFPUStateFrame(uStack_c8);
    fpsp_done();
    return;
  }
  fpsp_done();
  return;
}
/* GHIDRADEC_FUNCTION index=2781 start=0x40a4dce */

void fpsp_snan(void)

{
  char cVar1;
  undefined4 *puVar2;
  sword sVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  byte bStack_e8;
  char acStack_cc [4];
  undefined4 auStack_c8 [11];
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(auStack_c8[0]);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  if (((uint)uStack_84 & 0x4000) != 0) {
    if ((bStack_e8 & 0x20) != 0) {
      sub_40A4EEC();
    }
    cVar1 = auStack_c8[0]._0_1_;
    if (auStack_c8[0]._0_1_ == '@') {
      sVar3 = 0xd;
    }
    else {
      sVar3 = 0xb;
    }
    auStack_c8[0] = 0;
    puVar2 = auStack_c8;
    do {
      puVar4 = (undefined *)puVar2;
      *(undefined4 *)(puVar4 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar4 + -4);
    } while (sVar3 != -1);
    puVar4[-4] = cVar1;
    puVar4[-3] = 0x60;
    restoreFPUStateFrame(*(undefined4 *)(puVar4 + -4));
    real_snan();
    return;
  }
  sub_40A4EEC();
  if ((bStack_7e & uStack_84._2_1_ & 3) == 0) {
    cVar1 = auStack_c8[0]._0_1_;
    if (auStack_c8[0]._0_1_ == '@') {
      sVar3 = 0xd;
    }
    else {
      sVar3 = 0xb;
    }
    auStack_c8[0] = 0;
    puVar2 = auStack_c8;
    do {
      puVar5 = (undefined *)puVar2;
      *(undefined4 *)(puVar5 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar5 + -4);
    } while (sVar3 != -1);
    puVar5[-4] = cVar1;
    puVar5[-3] = 0x60;
    restoreFPUStateFrame(*(undefined4 *)(puVar5 + -4));
    fpsp_done();
    return;
  }
  restoreFPUStateFrame(auStack_c8[0]);
  real_inex();
  return;
}
/* GHIDRADEC_FUNCTION index=2782 start=0x40a5024 */

void store(void)

{
  word wVar1;
  byte bVar2;
  char cVar4;
  int iVar3;
  byte *in_A0;
  byte *extraout_A0;
  int unaff_A6;
  unkbyte10 in_FP0;
  unkbyte10 extraout_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    cVar4 = g_opcls();
    if (cVar4 == '\x03') {
      iVar3 = g_dfmtou();
      if (iVar3 == 0) {
        return;
      }
      if (iVar3 != 1) {
        return;
      }
      return;
    }
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xe4) >> 0x10);
    in_A0 = extraout_A0;
    in_FP0 = extraout_FP0;
  }
  else {
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xf0) >> 0x10);
  }
  bVar2 = *(byte *)((int)&dword_40A501C + (int)(sword)((wVar1 & 0x3ff) >> 7));
  if (in_A0[2] != 0) {
    *in_A0 = *in_A0 | 0x80;
  }
  fmovem(*(undefined4 *)in_A0,(uint)bVar2);
  if (bVar2 == 0x80) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
    return;
  }
  if (bVar2 == 0x40) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
    return;
  }
  if (bVar2 == 0x20) {
    *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
    return;
  }
  if (bVar2 == 0x10) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2783 start=0x40a50e2 */

void dest_dbl(void)

{
  uint uVar1;
  uint *in_A1;
  
  if (*(sword *)in_A1 == 0x7fff) {
    uVar1 = 0x7ff00000;
    in_A1[1] = 0;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = 0xfff00000;
    }
    *in_A1 = uVar1;
  }
  else {
    uVar1 = (uint)(word)(*(sword *)in_A1 + 0xc400) << 0x14;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    *in_A1 = (in_A1[1] & 0x7fffffff) >> 0xb | uVar1;
    in_A1[1] = in_A1[1] << 0x15;
    in_A1[1] = in_A1[2] >> 0xb | in_A1[1];
  }
  mem_write();
  return;
}
/* GHIDRADEC_FUNCTION index=2784 start=0x40a5166 */

void dest_sgl(void)

{
  uint uVar1;
  int in_A0;
  sword *in_A1;
  int unaff_A6;
  
  if (*in_A1 == 0x7fff) {
    uVar1 = 0x7f800000;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = 0xff800000;
    }
  }
  else {
    uVar1 = (uint)(word)(*in_A1 + 0xc080) << 0x17;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    uVar1 = (*(uint *)(in_A1 + 2) & 0x7fffffff) >> 8 | uVar1;
  }
  *(uint *)(unaff_A6 + -0x54) = uVar1;
  if (in_A0 != 0) {
    mem_write();
    return;
  }
  get_fline();
  reg_dest();
  return;
}
/* GHIDRADEC_FUNCTION index=2785 start=0x40a51ee */

void dest_ext(void)

{
  byte *in_A1;
  
  if (in_A1[2] != 0) {
    *in_A1 = *in_A1 | 0x80;
  }
  in_A1[2] = 0;
  mem_write();
  return;
}
/* GHIDRADEC_FUNCTION index=2786 start=0x40a520e */

void fpsp_unfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(uStack_c8);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  sub_40A533C();
  if (((uint)uStack_84 & 0x800) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_unfl();
    return;
  }
  if ((bStack_7e & uStack_84._2_1_ & 3) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_inex();
    return;
  }
  if ((uStack_e0 & 0x2000000) != 0) {
    b1238_fix();
    restoreFPUStateFrame(uStack_c8);
    fpsp_done();
    return;
  }
  fpsp_done();
  return;
}
/* GHIDRADEC_FUNCTION index=2787 start=0x40a5420 */

void fpsp_unimp(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  return;
}
/* GHIDRADEC_FUNCTION index=2788 start=0x40a5426 */

void uni_2(void)

{
  undefined4 *puVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 in_A0;
  undefined4 in_A1;
  int unaff_A6;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  byte in_stack_00000000;
  undefined4 uVar2;
  
  *(undefined4 *)(unaff_A6 + -0xc0) = in_D0;
  *(undefined4 *)(unaff_A6 + -0xbc) = in_D1;
  *(undefined4 *)(unaff_A6 + -0xb8) = in_A0;
  *(undefined4 *)(unaff_A6 + -0xb4) = in_A1;
  *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
  *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
  *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
  *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
  puVar1 = *(undefined4 **)(unaff_A6 + -0x80);
  *puVar1 = in_FPCR;
  puVar1[3] = in_FPSR;
  puVar1[6] = in_FPIAR;
  if ((in_stack_00000000 & 0xf0) == 0x40) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) & 0xff;
    *(undefined *)(unaff_A6 + -0x47) = 0;
    get_op();
    *(undefined *)(unaff_A6 + -0x4c) = 0;
    uVar2 = 0x40a547a;
    do_func();
    saveFPUStateFrame(uVar2);
    if (*(char *)(unaff_A6 + -0x4c) == '\0') {
      sto_res(uVar2);
    }
    gen_except();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2789 start=0x40a5492 */

void fpsp_unsupp(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  if ((uStack_c8._0_1_ & 0xf0) == 0x40) {
    get_op();
    res_func();
    gen_except();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2790 start=0x40a5510 */

int _port_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  cStack_29 = '\x01';
  iStack_28 = 0x18;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x81c;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x880) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\x01')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x2200018) {
          *param_2 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2791 start=0x40a55ea */

int _port_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined auStack_24 [3];
  char cStack_21;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0x2200018;
  iStack_8 = param_2;
  cStack_21 = '\x01';
  iStack_20 = 0x20;
  uStack_1c = 0x100;
  uStack_14 = param_1;
  uStack_18 = _mig_get_reply_port();
  iStack_10 = 0x81d;
  iVar1 = _msg_rpc(auStack_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_10 == 0x881) {
      if (((iStack_20 == 0x20) && (cStack_21 == '\x01')) && (iStack_c == 0x2200018)) {
        iVar1 = iStack_8;
        if (iStack_8 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2792 start=0x40a56ae */

int _port_set_add_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x2200018;
  uStack_8 = param_3;
  cStack_29 = '\x01';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x822;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x886) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2793 start=0x40a5780 */

int _port_set_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  cStack_29 = '\x01';
  iStack_28 = 0x18;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x820;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x884) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\x01')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x2200018) {
          *param_2 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2794 start=0x40a585a */

int _port_set_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined auStack_24 [3];
  char cStack_21;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0x2200018;
  iStack_8 = param_2;
  cStack_21 = '\x01';
  iStack_20 = 0x20;
  uStack_1c = 0x100;
  uStack_14 = param_1;
  uStack_18 = _mig_get_reply_port();
  iStack_10 = 0x821;
  iVar1 = _msg_rpc(auStack_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_10 == 0x885) {
      if (((iStack_20 == 0x20) && (cStack_21 == '\x01')) && (iStack_c == 0x2200018)) {
        iVar1 = iStack_8;
        if (iStack_8 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2795 start=0x40a591e */

int _task_set_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x6200018;
  uStack_8 = param_3;
  cStack_29 = '\0';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x80b;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x86f) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2796 start=0x40a59ee */

int _thread_get_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  cStack_29 = '\x01';
  iStack_28 = 0x20;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x813;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x877) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\0')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x6200018) {
          *param_3 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2797 start=0x40a5ad4 */

int _thread_set_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x6200018;
  uStack_8 = param_3;
  cStack_29 = '\0';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x814;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x878) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2798 start=0x40a5ba4 */

int _vm_deallocate_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x2200018;
  uStack_8 = param_3;
  cStack_29 = '\x01';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x7e7;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x84b) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2799 start=0x40a5c76 */

int _vm_read_EXTERNAL(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,
                     undefined4 *param_5)

{
  int iVar1;
  undefined auStack_34 [3];
  char cStack_31;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_1c = 0x2200018;
  iStack_18 = param_2;
  uStack_14 = 0x2200018;
  iStack_10 = param_3;
  cStack_31 = '\x01';
  iStack_30 = 0x28;
  uStack_2c = 0x100;
  uStack_24 = param_1;
  uStack_28 = _mig_get_reply_port();
  iStack_20 = 0x7ea;
  iVar1 = _msg_rpc(auStack_34,0,0x30,0,0);
  if (iVar1 == 0) {
    if (iStack_20 == 0x84e) {
      if ((((iStack_30 == 0x30) && (cStack_31 == '\0')) ||
          ((iStack_30 == 0x20 && ((cStack_31 == '\x01' && (iStack_18 != 0)))))) &&
         (iStack_1c == 0x2200018)) {
        if (iStack_18 != 0) {
          return iStack_18;
        }
        if ((((byte)uStack_14 & 0xc) == 4) && (iStack_10 == 0x90008)) {
          *param_4 = uStack_8;
          *param_5 = uStack_c;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}

