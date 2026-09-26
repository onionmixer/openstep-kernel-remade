
unkbyte10 t_operr(void)

{
  int unaff_A6;
  unkbyte10 in_FP0;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1002080;
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x20) == 0) {
    return tbyte_409C99A._0_10_;
  }
  *(undefined *)(unaff_A6 + -0x4c) = 0xff;
  return in_FP0;
}
