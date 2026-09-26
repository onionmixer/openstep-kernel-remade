
void _ipc_notify_init_no_senders(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x46;
  *(undefined *)(param_1 + 6) = 2;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}

