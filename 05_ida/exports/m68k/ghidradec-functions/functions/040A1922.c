
void slognp1(void)

{
  int iVar1;
  undefined auVar2 [12];
  undefined (*in_A0) [12];
  int unaff_A6;
  
  if (ABS((float10)*in_A0) - (float10)tbyte_40A0EB2 == FLOAT_UNKNOWN ||
      ABS((float10)*in_A0) - (float10)tbyte_40A0EB2 < FLOAT_UNKNOWN) {
    t_frcinx();
    return;
  }
  auVar2 = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])((float)auVar2 + 1.0);
  *(undefined2 *)(unaff_A6 + -0x72) = *(undefined2 *)(unaff_A6 + -0x70);
  iVar1 = *(int *)(unaff_A6 + -0x74);
  if (iVar1 < 1) {
    if (-1 < iVar1) {
      t_dz();
      return;
    }
    t_operr();
    return;
  }
  if (iVar1 < iRam3ffe8000 || iRam3ffe8004 < iVar1) {
    return;
  }
  if (iRam3ffef07d <= iVar1 && iVar1 <= iRam3ffef081) {
    func_0x040a189c();
    return;
  }
  *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -0x70);
  *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) & 0xfe000000;
  *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) | 0x1000000;
  if (iVar1 < 0x3fff8000) {
    *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    func_0x040a17f8();
    return;
  }
  *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
  *(undefined4 *)(unaff_A6 + -0x5c) = 0;
  func_0x040a17f8();
  return;
}
