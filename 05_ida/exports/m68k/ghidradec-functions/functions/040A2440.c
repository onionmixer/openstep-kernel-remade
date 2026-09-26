
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
