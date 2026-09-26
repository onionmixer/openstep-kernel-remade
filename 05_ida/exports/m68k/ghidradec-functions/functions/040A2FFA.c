
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
