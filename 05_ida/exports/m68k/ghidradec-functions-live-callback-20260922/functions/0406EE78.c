
byte _vol_check_timeout(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = _vol_check_alive < '\0';
  cVar3 = _vol_check_alive == '\0';
  if (!(bool)cVar3) {
    _vol_check_event = 1;
    cVar2 = '\0';
    cVar3 = '\x01';
    cVar4 = '\0';
    bVar5 = 0;
    _thread_wakeup_prim(&_vol_check_event,0,0);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}

