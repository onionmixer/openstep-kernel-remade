
undefined4 _en_jam(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x1fe);
  *(undefined4 *)(param_1 + 0x206) = 0;
  if (_bmap_chip == 0) {
loc_408EAE2:
    if (_dma_chip != 0x139) {
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 4;
      _delay(500000);
      if ((*(byte *)(iVar1 + 6) & 0x40) != 0) {
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xfb;
        _delay(500000);
        iVar5 = sub_408DC16(iVar1 + 2);
        if (iVar5 != 0) {
          iVar1 = *(int *)(param_1 + 0x20a);
          *(int *)(param_1 + 0x20a) = iVar1 + 1;
          if (iVar1 + 1 < 4) {
            return 1;
          }
          goto loc_408EBB4;
        }
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 4;
        _delay(500000);
      }
      iVar1 = *(int *)(param_1 + 0x20a);
      *(int *)(param_1 + 0x20a) = iVar1 + 1;
      if (iVar1 + 1 < 6) goto loc_408E99C;
    }
loc_408EBB4:
    if ((*(byte *)(param_1 + 0x205) & 0x10) == 0) {
      _printf(aTheNetworkIsDi);
      *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 0x10;
    }
    *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 8;
    _en_down((param_1 + -0x40c8f34) * -0x40317f9d >> 2);
    _timeout(_en_antijam,param_1,_hz * 10);
    uVar4 = 2;
  }
  else {
    if (*(int *)(_bmap_chip + 0x34) < 0) {
      uVar6 = *_event_middle;
      uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar2 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      uVar2 = uVar2 | uVar6;
      do {
        uVar6 = *_event_middle;
        uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                0xfffff;
        if (((uVar3 ^ uVar6) & 0x80000) != 0) {
          uVar6 = uVar6 + 0x80000;
        }
      } while (((uVar3 | uVar6) - uVar2 < 150000) &&
              ((*(uint *)(_bmap_chip + 0x34) & 0x20000000) != 0));
      uVar6 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      if (149999 < (uVar3 | uVar6) - uVar2) {
        *(uint *)(_bmap_chip + 0x34) = *(uint *)(_bmap_chip + 0x34) & 0x6fffffff;
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 2;
        return 1;
      }
    }
    else {
      uVar6 = *_event_middle;
      uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar2 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      uVar2 = uVar2 | uVar6;
      do {
        uVar6 = *_event_middle;
        uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                0xfffff;
        if (((uVar3 ^ uVar6) & 0x80000) != 0) {
          uVar6 = uVar6 + 0x80000;
        }
      } while (((uVar3 | uVar6) - uVar2 < 150000) &&
              ((*(uint *)(_bmap_chip + 0x34) & 0x20000000) != 0));
      uVar6 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      if (149999 < (uVar3 | uVar6) - uVar2) goto loc_408EAE2;
      *(uint *)(_bmap_chip + 0x34) = *(uint *)(_bmap_chip + 0x34) | 0x90000000;
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xfd;
    }
loc_408E99C:
    uVar4 = 0;
  }
  return uVar4;
}

