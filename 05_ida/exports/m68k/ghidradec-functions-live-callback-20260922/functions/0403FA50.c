
void _ipc_notify_init_send_once(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x18;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x47;
  return;
}

