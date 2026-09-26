
undefined4 _rtc_tick(void)

{
  char cVar3;
  int iVar1;
  int iVar2;
  undefined4 uVar4;
  
  cVar3 = _rtc_read(0x30);
  uVar4 = 0x20;
  if (cVar3 < '\0') {
    uVar4 = 0x23;
  }
  iVar1 = _rtc_read(uVar4);
  while( true ) {
    iVar2 = _rtc_read(uVar4);
    if (iVar2 != iVar1) break;
    _delay(1000);
  }
  return 0;
}
