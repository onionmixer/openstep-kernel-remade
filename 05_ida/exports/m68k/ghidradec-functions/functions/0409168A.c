
sqword _rtc_get(void)

{
  uint uVar1;
  uint uVar2;
  byte bStack_34;
  undefined uStack_33;
  undefined uStack_32;
  undefined uStack_30;
  undefined uStack_2f;
  undefined uStack_2e;
  byte bStack_2c;
  byte bStack_2b;
  byte bStack_2a;
  undefined uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = _rtc_read(0x30);
  if ((uVar1 & 0x10) == 0) {
    if (_new_clock_chip == 0) {
      do {
        _rtc_blkread(0x20,&bStack_34,8);
        uVar2 = (uint)bStack_34;
        uVar1 = _rtc_read(0x20);
      } while (uVar1 != uVar2);
      uStack_28 = _bcd_to_byte(bStack_34);
      uStack_24 = _bcd_to_byte(uStack_33);
      uStack_20 = _bcd_to_byte(uStack_32);
      uStack_1c = _bcd_to_byte(uStack_30);
      uStack_18 = _bcd_to_byte(uStack_2f);
      uStack_14 = _bcd_to_byte(uStack_2e);
      uVar1 = _tm_to_sec(&uStack_28);
    }
    else {
      _rtc_blkread(0x20,&bStack_2c,4);
      uVar1 = CONCAT31((uint3)bStack_2a |
                       (uint3)(((uint)bStack_2b << 0x10) >> 8) |
                       (uint3)(((uint)bStack_2c << 0x18) >> 8),uStack_29);
    }
  }
  else {
    uVar1 = 0;
  }
  return (qword)uVar1 << 0x20;
}
