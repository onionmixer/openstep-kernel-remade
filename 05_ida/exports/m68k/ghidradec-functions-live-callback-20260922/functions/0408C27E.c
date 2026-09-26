
uint _zs_tc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int aiStack_14 [2];
  word wStack_a;
  word wStack_6;
  
  if ((param_1 == 0x86) && (param_2 == 0x10)) {
    uVar1 = 0x356;
    if (_dma_chip == 0x139) {
      uVar1 = 0x20356;
    }
  }
  else {
    iVar4 = 0;
    do {
      if (iVar4 == 0) {
        iVar3 = 10000000;
        if (_dma_chip == 0x139) {
          iVar3 = 0x3836a0;
        }
      }
      else {
        iVar3 = 0x3836a0;
        if (_dma_chip == 0x139) {
          iVar3 = 4000000;
        }
      }
      iVar2 = (param_2 * param_1 + iVar3) / (param_2 * 2 * param_1);
      *(int *)(&stack0xfffffff4 + iVar4 * 4) = iVar2 + -2;
      iVar3 = (iVar3 << 7) / (param_2 * 2 * iVar2) + param_1 * -0x80;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      aiStack_14[iVar4] = iVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    if (aiStack_14[0] < aiStack_14[1]) {
      uVar1 = wStack_a | 0x20000;
    }
    else {
      uVar1 = (uint)wStack_6;
    }
  }
  return uVar1;
}

