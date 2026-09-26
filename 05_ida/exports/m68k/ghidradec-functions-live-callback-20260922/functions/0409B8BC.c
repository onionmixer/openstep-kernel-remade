
void sone(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pone();
    return;
  }
  return;
}

