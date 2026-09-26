
undefined4 _nbic_bus_enable(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(_slot_id + 0x200d000);
  puVar2 = (uint *)(_slot_id + 0x2200010);
  if (_machine_type == 2) {
loc_407261C:
    if (_dma_chip == 0x139) {
      *puVar3 = *puVar3 | 0x80;
    }
    else {
      *puVar3 = *puVar3 & 0xffffff7f;
      *puVar2 = *puVar2 & 0xfffffcff;
      *(undefined *)(_slot_id + 0x2012000) = 0x88;
    }
    if (_bmap_chip != 0) {
      *(byte *)(_bmap_chip + 4) = *(byte *)(_bmap_chip + 4) & 0xbf;
    }
    uVar1 = 1;
  }
  else {
    if (_machine_type < 3) {
      if (_machine_type == 0) goto loc_407261C;
    }
    else if ((_machine_type < 10) && (7 < _machine_type)) goto loc_407261C;
    uVar1 = 0;
  }
  return uVar1;
}

