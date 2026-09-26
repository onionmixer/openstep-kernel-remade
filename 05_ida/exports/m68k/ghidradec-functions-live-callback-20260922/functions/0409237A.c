
void _delay(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *_event_middle;
  uVar1 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if (((uVar1 ^ uVar3) & 0x80000) != 0) {
    uVar3 = uVar3 + 0x80000;
  }
  do {
    uVar4 = *_event_middle;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if (((uVar2 ^ uVar4) & 0x80000) != 0) {
      uVar4 = uVar4 + 0x80000;
    }
  } while ((uVar2 | uVar4) - (uVar1 | uVar3) < param_1 + 1U);
  return;
}

