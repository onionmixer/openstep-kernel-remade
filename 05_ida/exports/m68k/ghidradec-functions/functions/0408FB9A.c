
undefined4 _en_xmit(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  sword sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  char *pcVar14;
  
  iVar7 = _slot_id_bmap;
  iVar6 = _slot_id;
  pcVar14 = (char *)(_slot_id_bmap + 0x2006000);
  puVar13 = (uint *)(_slot_id + 0x2000110);
  uVar11 = 0;
  if (param_2 < 0x3c) {
    param_2 = 0x3c;
  }
  do {
    if (_dma_chip == 0x139) {
      cVar1 = *pcVar14;
      while (-1 < cVar1) {
        cVar1 = *pcVar14;
      }
    }
    else {
      *pcVar14 = -1;
    }
    _cache_flush(param_1,param_1 + 0x242,0);
    sVar5 = _dma_chip;
    uVar8 = 0x900000;
    if (_dma_chip == 0x139) {
      uVar8 = 0x300000;
    }
    *puVar13 = uVar8;
    *(int *)(iVar6 + 0x2004110) = param_1;
    if (sVar5 == 0x139) {
      *(int *)(iVar6 + 0x2004100) = param_1;
    }
    else {
      *(int *)(iVar6 + 0x2004118) = param_1;
    }
    sVar5 = _dma_chip;
    iVar12 = param_1 + param_2;
    if (_dma_chip == 0x139) {
      iVar12 = iVar12 + -0x7ffffff1;
    }
    *(int *)(iVar6 + 0x2004114) = iVar12;
    if (sVar5 == 0x139) {
      *(int *)(iVar6 + 0x2004104) = iVar12;
    }
    *puVar13 = 0x10000;
    if (_dma_chip != 0x139) {
      *(byte *)(iVar7 + 0x2006004) = *(byte *)(iVar7 + 0x2006004) | 0x80;
    }
    uVar8 = *_event_middle;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if (((uVar2 ^ uVar8) & 0x80000) != 0) {
      uVar8 = uVar8 + 0x80000;
    }
    bVar4 = false;
    do {
      if (_dma_chip == 0x139) {
        if ((*puVar13 & 0x8000000) != 0) goto loc_408FD62;
      }
      else if (*pcVar14 < '\0') goto loc_408FD62;
      _delay(1);
      uVar10 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar10) & 0x80000) != 0) {
        uVar10 = uVar10 + 0x80000;
      }
    } while ((uVar3 | uVar10) - (uVar2 | uVar8) < 0x2711);
    uVar11 = uVar11 + 1;
    _printf(aEnXmitTimeout);
    bVar4 = true;
loc_408FD62:
    if ((!bVar4) || (3 < uVar11)) {
      *puVar13 = 0x100000;
      if (_dma_chip != 0x139) {
        *(byte *)(iVar7 + 0x2006004) = *(byte *)(iVar7 + 0x2006004) & 0x7f;
      }
      uVar9 = 1;
      if (3 < uVar11) {
        uVar9 = 0xffffffff;
      }
      return uVar9;
    }
  } while( true );
}
