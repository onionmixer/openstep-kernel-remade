
void satanh(void)

{
  undefined (*in_A0) [12];
  float10 fVar1;
  
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    fVar1 = ABS((float10)*in_A0);
    *(float10 *)*in_A0 = (fVar1 + fVar1) / (-fVar1 + (float10)1.0);
    slognp1();
    t_frcinx();
    return;
  }
  if (ABS((float10)*in_A0) - (float10)1.0 != FLOAT_UNKNOWN &&
      FLOAT_UNKNOWN <= ABS((float10)*in_A0) - (float10)1.0) {
    t_operr();
    return;
  }
  t_dz();
  return;
}
