
uint g_opcls(void)

{
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    return 0;
  }
  return *(uint *)(unaff_A6 + -0xe4) >> 0x1d;
}
