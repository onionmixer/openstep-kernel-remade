
void sintd(void)

{
  byte *in_A0;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0x7d) & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(unaff_A6 + -0x7d) & 0x10) != 0) {
    if ((*in_A0 & 0x80) == 0) {
      ld_pone();
      t_inx2();
      return;
    }
    ld_mzero();
    t_inx2();
    return;
  }
  if ((*in_A0 & 0x80) != 0) {
    ld_mone();
    t_inx2();
    return;
  }
  ld_pzero();
  t_inx2();
  return;
}

