
void t_dz2(void)

{
  int unaff_A6;
  
  *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
  if ((*(byte *)(unaff_A6 + -0x7e) & 4) == 0) {
    func_0x0409c9f2();
    return;
  }
  return;
}
