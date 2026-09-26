
void spi_2(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_ppi2();
    return;
  }
  return;
}

