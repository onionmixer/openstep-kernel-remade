
float10 sslog2(void)

{
  byte *in_A0;
  float10 in_FP0;
  
  if ((*in_A0 & 0x80) != 0) {
    return in_FP0;
  }
  if (((*(sword *)in_A0 == 0x3fff) && (*(int *)(in_A0 + 4) == -0x80000000)) &&
     (*(int *)(in_A0 + 8) == 0)) {
    return (float10)tbyte_409B7BC;
  }
  return in_FP0;
}

