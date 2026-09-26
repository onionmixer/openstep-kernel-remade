
void _ip_enq(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(int *)(*(int *)(param_2 + 0xc) + 0x10) = param_1;
  *(int *)(param_2 + 0xc) = param_1;
  return;
}

