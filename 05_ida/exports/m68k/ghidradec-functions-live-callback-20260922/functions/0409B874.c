
void snzrinx(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pzero();
    t_inx2();
    return;
  }
  ld_mzero();
  t_inx2();
  return;
}

