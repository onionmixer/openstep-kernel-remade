
float10 ld_minf(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7E0;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa000000;
  return fVar1;
}
