
void _in_rtchange(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    _rtfree(*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

