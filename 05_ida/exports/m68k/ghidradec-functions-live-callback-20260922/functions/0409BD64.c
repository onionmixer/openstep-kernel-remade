
float10 ld_mzero(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7C8;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xc000000;
  return fVar1;
}

