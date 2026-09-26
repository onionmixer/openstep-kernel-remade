
void _soisconnecting(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff5 | 4;
  _wakeup(param_1 + 0x4e);
  return;
}

