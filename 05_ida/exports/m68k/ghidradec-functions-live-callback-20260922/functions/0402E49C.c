
void _ckuwakeup(uint *param_1)

{
  *param_1 = *param_1 | 1;
  _sbwakeup(param_1[5] + 0x22);
  return;
}

