
undefined8 _clock_value(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar1 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if ((((uVar1 ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  uVar1 = uVar1 | *_event_middle;
  uVar3 = uVar1 * 1000;
  iVar2 = ((((*_event_high << 5 | (uint)*_event_middle >> 0x1b) * 4 +
             (uint)(uVar1 * 0x20 < uVar1) * -4 + *_event_high * -3 +
             (uint)CARRY4(uVar1 * 0x1f,uVar1 * 0x1f) * 2 + (uint)CARRY4(uVar1 * 0x3e,uVar1 * 0x3e))
            * 2 + (uint)CARRY4(uVar1,uVar1 * 0x7c) * 2 + (uint)CARRY4(uVar1 * 0x7d,uVar1 * 0x7d)) *
           2 + (uint)CARRY4(uVar1 * 0xfa,uVar1 * 0xfa)) * 2 + (uint)CARRY4(uVar1 * 500,uVar1 * 500);
  if (param_1 == 0) {
    bVar4 = CARRY4(dword_40B55B0,uVar3);
    uVar3 = dword_40B55B0 + uVar3;
    iVar2 = dword_40B55AC + iVar2 + (uint)bVar4;
  }
  else if (param_1 != 1) {
    iVar2 = 0;
    uVar3 = 0;
  }
  return CONCAT44(iVar2,uVar3);
}
