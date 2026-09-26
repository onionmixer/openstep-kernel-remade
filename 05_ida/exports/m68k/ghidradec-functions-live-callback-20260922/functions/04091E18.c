
uint sub_4091E18(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *_event_middle;
  if (((uVar2 ^ (uint)*_eventc_h << 0x10) & 0x80000) != 0) {
    *_event_middle = *_event_middle + 0x80000;
    puVar1 = _event_high;
    uVar2 = *_event_middle & 0xfff80000;
    if (uVar2 == 0) {
      *_event_high = *_event_high + 1;
      uVar2 = *puVar1;
    }
  }
  if (dword_40B55BC != (code *)0x0) {
    uVar2 = (*dword_40B55BC)(param_1,param_2,param_3);
  }
  return uVar2;
}

