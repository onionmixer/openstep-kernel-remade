
void _startrtclock(void)

{
  undefined4 uVar1;
  undefined auStack_24 [17];
  byte bStack_13;
  
  _nvram_check(auStack_24);
  _new_clock_chip = _rtc_read(0x30);
  _new_clock_chip = _new_clock_chip & 0x80;
  if (_new_clock_chip != 0) {
    uVar1 = 0;
    if ((bStack_13 & 0x40) != 0) {
      uVar1 = 0xffffffff;
    }
    _rtc_set_clr(0x31,0x20,uVar1);
    _rtc_set_clr(0x31,0x80,0xffffffff);
  }
  bStack_13 = bStack_13 & 0x7f | (_new_clock_chip != 0) << 7;
  _nvram_set(auStack_24);
  return;
}
