
float10 sgetexp(void)

{
  word *in_A0;
  
  return (float10)(sword)((*in_A0 & 0x7fff) + 0xc001);
}

