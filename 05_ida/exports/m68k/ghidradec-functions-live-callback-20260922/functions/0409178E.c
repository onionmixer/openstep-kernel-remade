
int _bcd_to_byte(byte param_1)

{
  return (param_1 & 0xf) + (uint)(param_1 >> 4) * 10;
}

