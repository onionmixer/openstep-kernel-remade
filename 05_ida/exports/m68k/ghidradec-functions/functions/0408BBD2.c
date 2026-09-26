
undefined4 _zsstop(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  
  iVar2 = (sword)(*(word *)(param_1 + 0x38) & 0x1f) * 0x164;
  uVar3 = 0;
  cVar4 = '\0';
  bVar5 = false;
  bVar6 = (*(byte *)(param_1 + 0x41) & 0x20) == 0;
  if (!bVar6) {
    if ((unk_40B52E0[iVar2 + 0x123] & 1) == 0) {
      *(undefined4 *)(unk_40B52E0 + iVar2 + 0x28) = *(undefined4 *)(unk_40B52E0 + iVar2 + 0x100);
    }
    else {
      _dma_abort(unk_40B52E0 + iVar2);
    }
    uVar3 = *(uint *)(param_1 + 0x3e);
    bVar5 = (int)uVar3 < 0;
    bVar6 = false;
    if ((uVar3 & 0x100) == 0) {
      uVar1 = uVar3 | 8;
      *(uint *)(param_1 + 0x3e) = uVar1;
      bVar5 = (int)uVar1 < 0;
      bVar6 = uVar1 == 0;
    }
  }
  return CONCAT22((sword)(uVar3 >> 0x10),(word)(byte)(cVar4 << 4 | bVar5 << 3 | bVar6 << 2));
}
