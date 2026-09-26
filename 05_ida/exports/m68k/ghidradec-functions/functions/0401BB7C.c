
word _physstrat(int param_1,code *param_2,undefined4 param_3)

{
  byte bVar1;
  word wVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  wVar2 = (*param_2)(param_1);
  if ((*(byte *)(param_1 + 2) & 0x20) == 0) {
    cVar3 = '\0';
    cVar4 = '\0';
    cVar5 = '\0';
    bVar6 = 0;
    bVar1 = *(byte *)(param_1 + 3);
    while ((bVar1 & 2) == 0) {
      cVar4 = param_1 < 0;
      cVar5 = '\0';
      bVar6 = 0;
      _sleep(param_1,param_3);
      bVar1 = *(byte *)(param_1 + 3);
    }
    wVar2 = (word)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 1 | bVar6);
  }
  return wVar2;
}
