
void _odminphys(int param_1)

{
  int iVar1;
  
  iVar1 = 0x10000;
  if (_dma_chip == 0x139) {
    iVar1 = 0x2000;
  }
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return;
}

