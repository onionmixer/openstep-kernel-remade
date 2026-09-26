
void _rinactive(int param_1)

{
  if (*(int *)(param_1 + 0x6c) != 0) {
    _crfree(*(int *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return;
}
