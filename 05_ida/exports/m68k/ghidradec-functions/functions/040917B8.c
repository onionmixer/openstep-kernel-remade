
byte _byte_to_bcd(byte param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  for (; 9 < param_1; param_1 = param_1 - 10) {
    bVar1 = bVar1 + 0x10;
  }
  return param_1 | bVar1;
}
