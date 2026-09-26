
void sub_409E564(void)

{
  uint uVar1;
  undefined4 *in_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x10c) = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x108) = in_A0[1];
  *(undefined4 *)(unaff_A6 + -0x104) = in_A0[2];
  uVar1 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
  *(uint *)(unaff_A6 + -0x10a) = uVar1;
  if (uVar1 != 0) {
    *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
  }
  *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x17;
  return;
}
