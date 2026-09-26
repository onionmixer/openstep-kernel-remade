
undefined4 sub_40826E6(int param_1)

{
  word wVar1;
  uint in_D0;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  
  wVar1 = _dma_chip;
  uVar2 = in_D0 & 0xffff0000;
  if (param_1 == 0) {
    if (_dma_chip == 0x139) {
      uVar2 = *_scr2 | 0x40;
      *_scr2 = uVar2;
    }
    bVar4 = _bmap_chip < 0;
    bVar5 = true;
    if (_bmap_chip == 0) goto loc_4082756;
    uVar2 = CONCAT31((int3)(uVar2 >> 8),*(undefined *)(_bmap_chip + 0xc)) | 0x20;
  }
  else {
    if (_dma_chip == 0x139) {
      uVar2 = *_scr2 & 0xffffffbf;
      *_scr2 = uVar2;
    }
    bVar4 = _bmap_chip < 0;
    bVar5 = true;
    if (_bmap_chip == 0) goto loc_4082756;
    uVar2 = CONCAT31((int3)(uVar2 >> 8),*(undefined *)(_bmap_chip + 0xc)) & 0xffffffdf;
  }
  cVar3 = (char)uVar2;
  *(char *)(_bmap_chip + 0xc) = cVar3;
  bVar4 = cVar3 < '\0';
  bVar5 = cVar3 == '\0';
loc_4082756:
  return CONCAT22((sword)(uVar2 >> 0x10),
                  (word)(byte)((wVar1 < 0x139) << 4 | bVar4 << 3 | bVar5 << 2));
}

