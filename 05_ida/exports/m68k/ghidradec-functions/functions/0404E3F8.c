
byte _ns_timer_init(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = '\0';
  cVar3 = '\x01';
  cVar4 = '\0';
  bVar5 = 0;
  __set_timer_expire_func(0,sub_404E458);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
