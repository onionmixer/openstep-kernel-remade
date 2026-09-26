
void _raw_connaddr(int param_1,int param_2)

{
  _bcopy(*(int *)(param_2 + 4) + param_2,param_1 + 0xc,0x10);
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) | 2;
  return;
}

