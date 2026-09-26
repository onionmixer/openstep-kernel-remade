
undefined8 _dma_abort(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_A2;
  char in_XF;
  bool bVar4;
  
  puVar1 = *(uint **)(param_1 + 0x1c);
  bVar4 = false;
  if ((*(uint *)(param_1 + 0x2c) & 0x1000) != 0) {
    bVar4 = _dma_chip < 0x139;
    if (_dma_chip == 0x139) {
      do {
      } while (*puVar1 == 0);
      uVar2 = *puVar1 & 0xb000000;
    }
    else {
      uVar2 = *puVar1 & 0x1b000000;
    }
    *(uint *)(param_1 + 0x24) = uVar2;
    *(uint *)(param_1 + 0x28) = puVar1[0x1000];
    if (*(int *)(param_1 + 8) != 0) {
      bVar4 = _dma_chip < 0x139;
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar1 == 0);
        uVar2 = *puVar1 & 0xb000000;
      }
      else {
        uVar2 = *puVar1 & 0x1b000000;
      }
      *(uint *)(*(int *)(param_1 + 8) + 0x10) = uVar2;
      *(uint *)(*(int *)(param_1 + 8) + 0x14) = puVar1[0x1000];
    }
  }
  *puVar1 = 0x100000;
  uVar2 = *(uint *)(param_1 + 0x2c);
  uVar3 = uVar2 & 0xffffcfff;
  *(uint *)(param_1 + 0x2c) = uVar3;
  return CONCAT44(CONCAT22((sword)(uVar2 >> 0x10),
                           (word)(byte)(bVar4 << 4 | ((int)uVar3 < 0) << 3 | (uVar3 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 | (unaff_A2 == 0) << 2))
  ;
}
