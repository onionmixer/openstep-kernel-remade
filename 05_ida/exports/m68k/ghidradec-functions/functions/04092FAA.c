
char _msb(uint param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = '\0';
  if (param_1 != 0) {
    cVar2 = '\x18';
    uVar3 = param_1 >> 0x18;
    if ((char)(param_1 >> 0x18) == '\0') {
      cVar2 = '\x10';
      uVar3 = (param_1 & 0xffffff) >> 0x10;
      if ((char)((param_1 & 0xffffff) >> 0x10) == '\0') {
        cVar2 = '\b';
        uVar1 = param_1 << 8 & 0xffffff;
        uVar3 = uVar1 >> 0x10;
        if ((char)(uVar1 >> 0x10) == '\0') {
          cVar2 = '\0';
          uVar3 = (param_1 << 8 & 0xffff) >> 8;
        }
      }
    }
    if (0xf < (word)uVar3) {
      cVar2 = cVar2 + '\x04';
      uVar3 = uVar3 >> 4;
    }
    cVar2 = *(char *)((int)&word_4092FF6 + (uVar3 & 0xf)) + cVar2;
  }
  return cVar2;
}
