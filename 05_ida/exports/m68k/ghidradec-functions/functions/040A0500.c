
void setoxm1(void)

{
  uint uVar1;
  int iVar2;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  uVar1 = *(uint *)*in_A0 & 0x7fff0000;
  if (0x3ffcffff < uVar1) {
    if (CONCAT22((sword)(uVar1 >> 0x10),*(undefined2 *)(*in_A0 + 4)) < 0x4004c216) {
      *(int *)(unaff_A6 + -0x54) = (int)((float)*in_A0 * 92.33248);
      iVar2 = *(int *)(unaff_A6 + -0x54) >> 6;
      *(int *)(unaff_A6 + -0x54) = iVar2;
      *(sword *)(unaff_A6 + -0x40) = (sword)iVar2 + 0x3fff;
      *(undefined2 *)(unaff_A6 + -0x3e) = 0;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      *(word *)(unaff_A6 + -0x30) = 0x3fffU - (sword)*(undefined4 *)(unaff_A6 + -0x54) | 0x8000;
      *(undefined2 *)(unaff_A6 + -0x2e) = 0;
      *(undefined4 *)(unaff_A6 + -0x2c) = 0x80000000;
      *(undefined4 *)(unaff_A6 + -0x28) = 0;
      t_frcinx();
      return;
    }
    if (0 < *(int *)*in_A0) {
      return;
    }
    t_frcinx();
    return;
  }
  if (0x3fbdffff < uVar1) {
    t_frcinx();
    return;
  }
  if (uVar1 < 0x330000) {
    *(undefined4 *)(unaff_A6 + -0x40) = 0x80010000;
    *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
    *(undefined4 *)(unaff_A6 + -0x38) = 0;
    t_frcinx();
    return;
  }
  *(undefined4 *)(unaff_A6 + -0x40) = 0x80010000;
  *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
  *(undefined4 *)(unaff_A6 + -0x38) = 0;
  t_frcinx();
  return;
}
