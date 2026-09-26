
void _rtc_set_auto_poweron(int param_1)

{
  undefined4 uVar1;
  
  if (_new_clock_chip != 0) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = 0xffffffff;
    }
    _rtc_set_clr(0x31,0x20,uVar1);
  }
  return;
}

