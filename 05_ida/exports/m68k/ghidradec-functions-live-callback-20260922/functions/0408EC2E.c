
void _en_tx_guard(int param_1)

{
  *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 0x40;
  _callout_dispatch(1,_en_tx_dmaintr,(param_1 + -0x40c8f34) * -0x40317f9d >> 2);
  return;
}

