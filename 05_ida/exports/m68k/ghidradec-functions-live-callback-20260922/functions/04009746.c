
void _stop(int param_1)

{
  _task_suspend_nowait(*(undefined4 *)(param_1 + 0x66));
  *(undefined *)(param_1 + 0x13) = 6;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;
  _wakeup(*(undefined4 *)(param_1 + 0x42));
  return;
}

