
void _in_pcbdisconnect(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x18) + 7) & 1) != 0) {
    _in_pcbdetach(param_1);
  }
  return;
}
