
unkbyte10 t_dz(void)

{
  unkbyte10 Var1;
  int unaff_A6;
  unkbyte10 in_FP0;
  unkbyte10 Var2;
  
  Var1 = tbyte_409C982._0_10_;
  if ((*(byte *)(unaff_A6 + -0x7e) & 4) != 0) {
    if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    }
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000410;
    *(undefined *)(unaff_A6 + -0x4c) = 0xff;
    return in_FP0;
  }
  Var2 = tbyte_409C98E._0_10_;
  if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
    *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    Var2 = Var1;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000410;
  return Var2;
}
