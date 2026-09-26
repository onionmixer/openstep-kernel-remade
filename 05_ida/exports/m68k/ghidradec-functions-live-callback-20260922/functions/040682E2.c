
void sub_40682E2(void)

{
  bool bVar1;
  int iVar2;
  undefined auStack_10 [2];
  undefined2 uStack_e;
  
  iVar2 = _rtc_intr();
  if (iVar2 != 0) {
    *_intrmask = *_intrmask & 0xfffffffb;
    _intr_mask = _intr_mask & 0xfffffffb;
    if (_force_power_down != 0) {
                    /* WARNING: Subroutine does not return */
      _rtc_power_down();
    }
    if (_autoDimmed != 0) {
      _UndoAutoDim();
    }
    if (_eventsOpen == 0) {
      _km_power_down();
    }
    else {
      if ((*(uint *)(_evg + 6) & 0x28) == 0x28) {
                    /* WARNING: Subroutine does not return */
        _rtc_power_down();
      }
      bVar1 = false;
      if ((_eventsOpen != 0) && (_evg[1] != *_evg)) {
        bVar1 = true;
      }
      uStack_e = 1;
      _LLEventPost(0xe,dword_40B124E,auStack_10);
      if (((!bVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
        _evnewevents();
      }
    }
  }
  return;
}

