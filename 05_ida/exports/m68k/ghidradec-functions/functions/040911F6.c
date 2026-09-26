
undefined4 _rtc_alarm(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  undefined uStack_5;
  
  if (_new_clock_chip == 0) {
    uVar1 = 0x16;
  }
  else {
    if (param_2 != (uint *)0x0) {
      uVar2 = _rtc_read(0x31);
      *param_2 = uVar2 & 0x10;
      _rtc_blkread(0x24,&bStack_8,4);
      param_2[1] = CONCAT31((uint3)bStack_6 |
                            (uint3)(((uint)bStack_7 << 0x10) >> 8) |
                            (uint3)(((uint)bStack_8 << 0x18) >> 8),uStack_5);
    }
    if (param_1 != (int *)0x0) {
      uStack_5 = *(undefined *)((int)param_1 + 7);
      bStack_6 = (byte)((uint)param_1[1] >> 8);
      bStack_7 = *(undefined *)((int)param_1 + 5);
      bStack_8 = *(byte *)(param_1 + 1);
      _rtc_blkwrite(0x24,&bStack_8,4);
      uVar1 = 0;
      if (*param_1 != 0) {
        uVar1 = 0xffffffff;
      }
      _rtc_set_clr(0x31,0x10,uVar1);
    }
    uVar1 = 0;
  }
  return uVar1;
}
