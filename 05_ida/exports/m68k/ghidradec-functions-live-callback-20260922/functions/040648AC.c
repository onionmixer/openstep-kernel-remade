
void _adb_keyboard_LED(uint param_1)

{
  undefined uStack_c;
  byte bStack_b;
  
  if (((byte_40B4F45 & 2) != 0) && (param_1 != (byte_40B4F47 & 0x7f) >> 6)) {
    bStack_b = bStack_b & 0xfd | (param_1 == 0) << 1 | 5;
    byte_40B4F47 = ((byte)param_1 & 1) << 6 | byte_40B4F47 & 0xbf;
    _adb_listen(2,2,&uStack_c,2);
  }
  return;
}

