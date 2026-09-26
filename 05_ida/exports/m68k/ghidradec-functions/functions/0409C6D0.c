
void sub_409C6D0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) != 0) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x54);
    return;
  }
  *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x80;
  return;
}
