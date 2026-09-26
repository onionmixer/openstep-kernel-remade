
void _socantsendmore(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x10;
  _sowakeup(param_1,param_1 + 0x38);
  return;
}
