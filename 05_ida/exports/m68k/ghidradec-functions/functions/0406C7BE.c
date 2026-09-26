
void _fc_slave(int param_1)

{
  _fd_slave((int)&_fd_controller + *(sword *)(*(int *)(param_1 + 0x22) + 4) * 0x262,param_1);
  return;
}
