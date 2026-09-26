
void _soisdisconnected(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff1 | 0x30;
  _wakeup(param_1 + 0x4e);
  _sowakeup(param_1,param_1 + 0x38);
  _sowakeup(param_1,param_1 + 0x22);
  return;
}
