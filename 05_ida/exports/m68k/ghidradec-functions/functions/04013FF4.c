
void _socantrcvmore(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x20;
  _sowakeup(param_1,param_1 + 0x22);
  return;
}
