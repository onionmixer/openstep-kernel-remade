
byte _thread_set_timeout(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar3 = (*(byte *)(_active_threads + 0x4b) & 1) == 0;
  if (!(bool)cVar3) {
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar5 = 0;
    _set_timeout(_active_threads + 0x110,param_1);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}

