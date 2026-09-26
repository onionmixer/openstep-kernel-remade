
uint norm(void)

{
  int unaff_A6;
  uint in_FPSR;
  
  if ((in_FPSR & 0x200) != 0) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x108;
  }
  return in_FPSR & 0xfffffdff;
}
