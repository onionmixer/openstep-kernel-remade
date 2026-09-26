
word _biowait(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  word wVar6;
  
  cVar2 = '\0';
  cVar3 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  bVar1 = *(byte *)(param_1 + 3);
  while ((bVar1 & 2) == 0) {
    cVar3 = param_1 < 0;
    cVar4 = '\0';
    bVar5 = 0;
    _sleep(param_1,0x14);
    bVar1 = *(byte *)(param_1 + 3);
  }
  wVar6 = (word)(byte)(cVar2 << 4 | cVar3 << 3 | cVar4 << 1 | bVar5);
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    wVar6 = _geterror(param_1);
    *(char *)(dword_40B57D4 + 100) = (char)wVar6;
  }
  return wVar6;
}
