
void _bawrite(int param_1)

{
  *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 0x100;
  _bwrite(param_1);
  return;
}
