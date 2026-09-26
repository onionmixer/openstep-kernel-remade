
void _rtc_power_down(void)

{
  char cVar1;
  undefined4 uVar2;
  
  if (_new_clock_chip != 0) {
    _rtc_tick();
    _delay(850000);
  }
  cVar1 = _rtc_read(0x30);
  uVar2 = 0x32;
  if (cVar1 < '\0') {
    uVar2 = 0x31;
  }
  _rtc_set_clr(uVar2,0x40,0xffffffff);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
