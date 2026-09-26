
void _udp_notify(int param_1)

{
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x22);
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x38);
  return;
}

