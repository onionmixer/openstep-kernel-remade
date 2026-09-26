
bool _kern_timestamp(undefined4 param_1)

{
  int iVar1;
  uint uStack_c;
  undefined4 uStack_8;
  
  uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
             0xfffff;
  if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  uStack_8 = *_event_high;
  uStack_c = *_event_middle | uStack_c;
  iVar1 = _copyoutmsg(&uStack_c,param_1,8);
  return iVar1 != 0;
}

