
void sub_4083CCA(int param_1)

{
  _object_copyin(dword_40C6EB8,*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),6,0,
                 *(int *)(param_1 + 4) + 0x10);
  _msg_send_from_kernel(*(undefined4 *)(param_1 + 4),0,0);
  _port_release(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10));
  _dspq_free_msg(param_1);
  return;
}

