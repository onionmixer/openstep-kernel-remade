
void t_frcinx(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
  if ((*(byte *)(unaff_A6 + -0x7a) & 8) != 0) {
    *(byte *)(unaff_A6 + -0x79) = *(byte *)(unaff_A6 + -0x79) | 0x20;
  }
  return;
}
