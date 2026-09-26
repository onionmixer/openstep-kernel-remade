
void _unp_mark(int param_1)

{
  if ((*(byte *)(param_1 + 0xb) & 0x10) == 0) {
    _unp_defer = _unp_defer + 1;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x30;
  }
  return;
}

