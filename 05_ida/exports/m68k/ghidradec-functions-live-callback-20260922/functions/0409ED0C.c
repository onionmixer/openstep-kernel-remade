
void sasin(void)

{
  float10 fVar1;
  undefined (*in_A0) [12];
  
  fVar1 = (float10)*in_A0;
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    *(float10 *)*in_A0 = fVar1 / SQRT(((float10)1.0 - fVar1) * ((float10)1.0 + fVar1));
    satan();
    t_frcinx();
    return;
  }
  if (ABS(fVar1) - (float10)1.0 != FLOAT_UNKNOWN && FLOAT_UNKNOWN <= ABS(fVar1) - (float10)1.0) {
    t_operr();
    return;
  }
  t_frcinx();
  return;
}

