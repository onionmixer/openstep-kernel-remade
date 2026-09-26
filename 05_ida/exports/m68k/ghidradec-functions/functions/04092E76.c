
char _ffs(uint param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  if (param_1 != 0) {
    if ((sword)param_1 == 0) {
      param_1 = param_1 >> 0x10;
      cVar1 = '\x10';
    }
    if ((char)param_1 == '\0') {
      param_1 = param_1 >> 8;
      cVar1 = cVar1 + '\b';
    }
    cVar1 = *(char *)((int)&word_4092EAA + (param_1 & 0xff)) + cVar1;
  }
  return cVar1;
}
