
uint _mmmmap(char param_1,uint param_2)

{
  if (param_1 == '\x03') {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    param_2 = _slot_id_bmap + 0x2008000;
  }
  else if (param_1 != '\0') {
    return 0xffffffff;
  }
  return param_2 >> (_page_shift & 0x3f);
}

