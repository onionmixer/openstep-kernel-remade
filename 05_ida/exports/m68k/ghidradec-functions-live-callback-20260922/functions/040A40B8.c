
void ovf_r_k(void)

{
  byte bVar1;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + -0xcc);
  *(byte *)(unaff_A6 + -0xcc) = bVar1 & 0x7f;
  *(char *)(unaff_A6 + -0xca) = -((bVar1 & 0x80) != 0);
  return;
}

