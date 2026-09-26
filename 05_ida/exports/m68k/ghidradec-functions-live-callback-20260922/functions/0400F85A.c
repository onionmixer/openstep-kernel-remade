
void _ttwakeup(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    _selwakeup(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x3e) & 0x800);
    _selthreadclear(param_1 + 0x28);
    *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xf7ff;
  }
  if ((*(byte *)(param_1 + 0x40) & 0x40) != 0) {
    _gsignal((int)*(sword *)(param_1 + 0x42),0x17);
  }
  _wakeup(param_1);
  return;
}

