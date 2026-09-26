
void _lock_init(undefined4 *param_1,uint param_2)

{
  _bzero(param_1,8);
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0x3f;
  *(undefined2 *)(param_1 + 1) = 0;
  *(uint *)((int)param_1 + 6) = *(uint *)((int)param_1 + 6) & 0xefffffff | (param_2 & 1) << 0x1c;
  *param_1 = 0xffffffff;
  *(word *)((int)param_1 + 6) = *(word *)((int)param_1 + 6) & 0xf000;
  return;
}

