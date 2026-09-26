
void ssincosnan(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  *(byte *)(unaff_A6 + -0x70) = *(byte *)(unaff_A6 + -0x70) | 0x40;
  sto_cos();
  src_nan();
  return;
}

