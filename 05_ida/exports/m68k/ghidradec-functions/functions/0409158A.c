
void _rtc_set(undefined4 *param_1)

{
  undefined uStack_34;
  undefined uStack_33;
  undefined uStack_32;
  undefined uStack_31;
  undefined uStack_30;
  undefined uStack_2f;
  undefined uStack_2e;
  undefined uStack_2c;
  undefined uStack_2b;
  undefined uStack_2a;
  undefined uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (_new_clock_chip == 0) {
    _sec_to_tm(*param_1,&uStack_28);
    _bzero(&uStack_34,8);
    uStack_34 = _byte_to_bcd(uStack_28);
    uStack_33 = _byte_to_bcd(uStack_24);
    uStack_32 = _byte_to_bcd(uStack_20);
    uStack_31 = 1;
    uStack_30 = _byte_to_bcd(uStack_1c);
    uStack_2f = _byte_to_bcd(uStack_18);
    uStack_2e = _byte_to_bcd(uStack_14);
    _rtc_write(0x31,0x30);
    _rtc_blkwrite(0x20,&uStack_34,8);
    _rtc_write(0x31,0xb0);
  }
  else {
    uStack_29 = *(undefined *)((int)param_1 + 3);
    uStack_2a = (undefined)((uint)*param_1 >> 8);
    uStack_2b = *(undefined *)((int)param_1 + 1);
    uStack_2c = *(undefined *)param_1;
    _rtc_set_clr(0x31,0x80,0);
    _rtc_blkwrite(0x20,&uStack_2c,4);
    _rtc_set_clr(0x31,0x80,0xffffffff);
  }
  return;
}
