
void _eninit(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined uVar4;
  undefined4 uVar3;
  
  iVar2 = _if_unit(param_1);
  puVar1 = *(undefined **)((&_eninfo)[iVar2] + 0x12);
  if ((*(uint *)(&DAT_40c9136 + iVar2 * 0x14b) & 1) == 0) {
    *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) = *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) | 1;
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x41;
    puVar1[6] = 0x80;
    if (_dma_chip != 0x139) {
      puVar1[6] = 0;
    }
    if (((&byte_40C9139)[iVar2 * 0x52c] & 4) != 0) {
      _bytecopy((int)&unk_40C8F38 + iVar2 * 0x52c,puVar1 + 8,6);
      *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) = *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) & 0xfffffffb
      ;
    }
    if (_dma_chip == 0x139) {
      puVar1[4] = 0;
    }
    else {
      puVar1[4] = 4;
      _delay(500000);
    }
    *puVar1 = 0xff;
    uVar4 = 4;
    if (_dma_chip != 0x139) {
      uVar4 = 0x8e;
    }
    puVar1[1] = uVar4;
    sub_408DBD2(puVar1 + 2,0xff);
    uVar3 = 0;
    if (_dma_chip != 0x139) {
      uVar3 = 0x41;
    }
    sub_408DBD2(puVar1 + 3,uVar3);
    uVar3 = 0;
    if (_dma_chip != 0x139) {
      uVar3 = 0x80;
    }
    sub_408DBD2(puVar1 + 5,uVar3);
    if (_dma_chip == 0x139) {
      puVar1[6] = 0;
    }
    if ((_dma_chip == 0x139) && (puVar1[4] = 2, _dma_chip == 0x139)) {
      puVar1[5] = 1;
    }
    else {
      sub_408DBD2(puVar1 + 5,0xa2);
    }
  }
  return;
}
