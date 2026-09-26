
void _raw_init(void)

{
  dword_40B6DEC = &_rawcb;
  _rawcb = &_rawcb;
  dword_40B5A70 = 0x32;
  return;
}

