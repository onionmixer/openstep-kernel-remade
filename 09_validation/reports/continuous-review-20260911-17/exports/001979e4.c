
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _VGASetGraphicsMode(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int local_10;
  
  out(0x3c4,1);
  LOCK();
  UNLOCK();
  out(0x3c5,0x21);
  LOCK();
  UNLOCK();
  in(0x3da);
  out(0x3c0,0);
  LOCK();
  UNLOCK();
  out(0x3c2,0xe3);
  LOCK();
  UNLOCK();
  out(0x3da,0);
  LOCK();
  _DAT_001e8648 = _DAT_001e8648 + 5;
  UNLOCK();
  uVar5 = 0;
  do {
    iVar4 = _DAT_001e8648;
    out(0x3c4,(char)uVar5);
    LOCK();
    UNLOCK();
    out(0x3c5,(&DAT_001d54de)[uVar5]);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 2;
    UNLOCK();
    uVar5 = uVar5 + 1;
  } while (uVar5 < 5);
  out(0x3c4,0);
  LOCK();
  UNLOCK();
  out(0x3c5,3);
  LOCK();
  UNLOCK();
  out(0x3d4,0x11);
  LOCK();
  UNLOCK();
  out(0x3d5,0);
  LOCK();
  _DAT_001e8648 = iVar4 + 6;
  UNLOCK();
  uVar5 = 0;
  do {
    out(0x3d4,(char)uVar5);
    LOCK();
    UNLOCK();
    out(0x3d5,(&DAT_001d54e3)[uVar5]);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 2;
    UNLOCK();
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x19);
  in(0x3da);
  uVar5 = 0;
  do {
    out(0x3c0,(char)uVar5);
    LOCK();
    UNLOCK();
    out(0x3c0,(&DAT_001d54fc)[uVar5]);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 2;
    UNLOCK();
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x15);
  uVar5 = 0;
  do {
    out(0x3ce,(char)uVar5);
    LOCK();
    UNLOCK();
    out(0x3cf,(&DAT_001d5511)[uVar5]);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 2;
    UNLOCK();
    uVar5 = uVar5 + 1;
  } while (uVar5 < 9);
  local_10 = 0;
  do {
    iVar4 = (local_10 % 4) * 3;
    uVar1 = (&DAT_001d551a)[iVar4];
    uVar2 = (&DAT_001d551b)[iVar4];
    uVar3 = (&DAT_001d551c)[iVar4];
    out(0x3c8,(undefined1)local_10);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 1;
    UNLOCK();
    _us_spin(10);
    out(0x3c9,uVar1);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 1;
    UNLOCK();
    _us_spin(10);
    out(0x3c9,uVar2);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 1;
    UNLOCK();
    _us_spin(10);
    out(0x3c9,uVar3);
    LOCK();
    _DAT_001e8648 = _DAT_001e8648 + 1;
    UNLOCK();
    _us_spin(10);
    local_10 = local_10 + 1;
  } while (local_10 < 0x10);
  _memset((void *)0xa0000,1,0x10000);
  in(0x3da);
  out(0x3c0,0x20);
  LOCK();
  UNLOCK();
  out(0x3c4,1);
  LOCK();
  UNLOCK();
  out(0x3c5,1);
  LOCK();
  _DAT_001e8648 = _DAT_001e8648 + 3;
  UNLOCK();
  return 0x3c500000000;
}

