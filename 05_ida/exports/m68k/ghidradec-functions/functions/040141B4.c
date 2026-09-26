
byte _sbrelease(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  _sbflush(param_1);
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = *(int *)(param_1 + 0x10) < 0;
  cVar3 = *(int *)(param_1 + 0x10) == 0;
  if (!(bool)cVar3) {
    _selthreadclear(param_1 + 0x10);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
