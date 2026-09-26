
void sub_409C6B0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) == 0) {
    *(word *)(unaff_A6 + -0x54) = *(word *)(unaff_A6 + -0x54) | 0x80;
    *(byte *)(unaff_A6 + -0x7a) = *(byte *)(unaff_A6 + -0x7a) | 8;
  }
  return;
}
