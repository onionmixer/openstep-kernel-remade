
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _us_spin_calibrate(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  out(0x43,0x30);
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 1;
  UNLOCK();
  uVar3 = _splusclock();
  out(0x40,0xff);
  LOCK();
  UNLOCK();
  out(0x40,0xff);
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 2;
  UNLOCK();
  _us_spin(1);
  out(0x43,0);
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 1;
  UNLOCK();
  uVar1 = in(0x40);
  uVar2 = in(0x40);
  _splx(uVar3);
  _us_spin_us_const =
       ((int)(0x1234cf / (longlong)(int)(0xffff - (uint)CONCAT11(uVar2,uVar1))) * _us_spin_us_const)
       / 1000000;
  return;
}

