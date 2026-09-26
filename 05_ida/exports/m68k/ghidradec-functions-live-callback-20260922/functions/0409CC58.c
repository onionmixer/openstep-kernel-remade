
float10 src_nan(void)

{
  int unaff_A6;
  float10 in_FP0;
  
  if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
    *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
  }
  if ((*(byte *)(unaff_A6 + -200) & 0x40) != 0) {
    return (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
  }
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x40) != 0) {
    *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
    *(undefined *)(unaff_A6 + -0xe0) = *(undefined *)(unaff_A6 + -0xe0);
    *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x60;
    *(undefined *)(unaff_A6 + -0x4c) = 0xff;
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    return in_FP0;
  }
  *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
  return (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
}

