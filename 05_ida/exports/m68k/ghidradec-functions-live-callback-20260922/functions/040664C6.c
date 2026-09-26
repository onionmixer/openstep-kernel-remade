
void _dma_close(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    _kfree(*(int *)(param_1 + 0x38),0x110);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return;
}

