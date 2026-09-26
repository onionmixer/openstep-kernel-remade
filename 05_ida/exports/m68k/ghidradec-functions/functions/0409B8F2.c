
void sopr_inf(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pinf();
    return;
  }
  return;
}
