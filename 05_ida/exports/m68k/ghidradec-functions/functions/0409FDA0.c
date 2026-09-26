
void scosh(void)

{
  uint uVar1;
  undefined (*in_A0) [12];
  
  uVar1 = CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
          0x7fffffff;
  if (uVar1 < 0x400cb168) {
    *(float10 *)*in_A0 = ABS((float10)*in_A0);
    setox();
    t_frcinx();
    return;
  }
  if (uVar1 < 0x400cb2b4) {
    *(float10 *)*in_A0 =
         (ABS((float10)*in_A0) - (float10)11354.443964752463) - (float10)8.971359657490228e-13;
    setox();
    t_frcinx();
    return;
  }
  (*in_A0)[0] = (*in_A0)[0] & 0x7f;
  t_ovfl();
  return;
}
