
undefined8 _dsp_dev_reset_chip(void)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  bool bVar2;
  
  *_scr2 = *_scr2 & 0x7ffffff;
  if ((_machine_type != '\0') || (1 < _board_rev)) {
    if (_dma_chip == 0x139) {
      uVar1 = *_scr2 | 0x20;
    }
    else {
      uVar1 = *_scr2 & 0xffffffdf;
    }
    *_scr2 = uVar1;
  }
  *_scr2 = *_scr2 | 0x10000000;
  *_scr2 = *_scr2 | 0x80000000;
  uVar1 = *_scr2 & 0xefffffff;
  *_scr2 = uVar1;
  if ((_machine_type != '\0') || (bVar2 = _board_rev == 0, 1 < _board_rev)) {
    bVar2 = _dma_chip < 0x139;
    if (_dma_chip == 0x139) {
      uVar1 = *_scr2 & 0xffffffdf;
    }
    else {
      uVar1 = *_scr2 | 0x20;
    }
    *_scr2 = uVar1;
  }
  *(undefined *)(_slot_id_bmap + 0x2008000) = 0;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(bVar2 << 4 | 4)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}

