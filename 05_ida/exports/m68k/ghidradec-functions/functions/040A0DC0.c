
void slog2(void)

{
  int *in_A0;
  
  if (*in_A0 < 0) {
    t_operr();
    return;
  }
  if ((in_A0[2] == 0) && ((in_A0[1] & 0x7fffffffU) == 0)) {
    t_frcinx();
    return;
  }
  slogn();
  t_frcinx();
  return;
}
