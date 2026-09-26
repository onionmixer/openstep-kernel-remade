
undefined4 _rtc_intr(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  while( true ) {
    if ((*_intrstat & 4) == 0) {
      return uVar2;
    }
    bVar1 = _rtc_read(0x30);
    if (-1 < (char)bVar1) break;
    if ((bVar1 & 0x10) != 0) {
      _rtc_set_clr(0x31,4,0xffffffff);
    }
    if ((bVar1 & 4) != 0) {
      _rtc_set_clr(0x31,2,0);
    }
    if ((bVar1 & 2) != 0) {
      _rtc_set_clr(0x31,8,0xffffffff);
    }
    if ((bVar1 & 1) != 0) {
      _rtc_set_clr(0x31,1,0xffffffff);
      uVar2 = 1;
    }
  }
  return 1;
}

