
void _km_power_down(void)

{
  uint uVar1;
  int iVar2;
  
  if ((unk_40B6904 & 8) != 0) {
    _printf(aReallyPowerOff);
    do {
      iVar2 = _kmtrygetc();
    } while (iVar2 == -1);
    if (iVar2 != 0x79) {
      uVar1 = *_intrstat;
      while ((uVar1 & 4) != 0) {
        _rtc_intr();
        uVar1 = *_intrstat;
      }
      *_intrmask = *_intrmask | 4;
      _intr_mask = _intr_mask | 4;
      return;
    }
    _printf(aShutDownInProg);
  }
  _force_power_down = 1;
  _vidStopAnimation();
  _vidSuspendAnimation();
  _reboot_mach(0x90000);
  return;
}

