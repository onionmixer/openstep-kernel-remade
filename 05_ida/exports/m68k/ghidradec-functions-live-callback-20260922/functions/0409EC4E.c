
float10 sacos(void)

{
  undefined (*in_A0) [12];
  float10 fVar1;
  
  fVar1 = (float10)*in_A0;
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    *(float10 *)*in_A0 = SQRT((-fVar1 + (float10)1.0) / ((float10)1.0 + fVar1));
    satan();
    fVar1 = (float10)t_frcinx();
    return fVar1;
  }
  if (ABS(fVar1) - (float10)1.0 != FLOAT_UNKNOWN && FLOAT_UNKNOWN <= ABS(fVar1) - (float10)1.0) {
    fVar1 = (float10)t_operr();
    return fVar1;
  }
  if (CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) < 1) {
    fVar1 = (float10)t_frcinx();
    return fVar1;
  }
  return (float10)0.0;
}

