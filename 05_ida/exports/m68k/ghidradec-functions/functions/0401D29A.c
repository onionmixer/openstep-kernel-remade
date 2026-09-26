
void _raw_disconnect(int param_1)

{
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) & 0xfffd;
  if ((*(byte *)(*(int *)(param_1 + 8) + 7) & 1) != 0) {
    _raw_detach(param_1);
  }
  return;
}
