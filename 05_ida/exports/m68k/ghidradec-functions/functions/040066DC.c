
void _utask_zero(int param_1)

{
  _bzero(*(undefined4 *)(param_1 + 0x30),0x28a);
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}
