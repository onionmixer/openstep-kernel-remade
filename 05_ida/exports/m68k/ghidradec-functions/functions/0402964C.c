
void _rlock(int param_1)

{
  while (((*(word *)(param_1 + 0x5e) & 1) != 0 && (*(int *)(param_1 + 0x66) != _active_threads))) {
    *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 2;
    _sleep(param_1,10);
  }
  *(int *)(param_1 + 0x66) = _active_threads;
  *(sword *)(param_1 + 0x6a) = *(sword *)(param_1 + 0x6a) + 1;
  *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 1;
  return;
}
