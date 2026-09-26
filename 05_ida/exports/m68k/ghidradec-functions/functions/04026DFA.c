
void _exportfree(int param_1)

{
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0xc) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0xc) << 4);
  }
  if (((*(byte *)(param_1 + 3) & 2) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x18) << 4);
  }
  _kfree(*(word **)(param_1 + 0x28),**(word **)(param_1 + 0x28) + 2);
  _kfree(param_1,0x30);
  return;
}
