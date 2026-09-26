
void _sbwait(int param_1)

{
  *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 4;
  _sleep(param_1,0x1a);
  return;
}

