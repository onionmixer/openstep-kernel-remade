
void _panic(char *param_1,...)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = _panic_lock;
    do {
    } while (iVar1 != 0);
    LOCK();
    iVar1 = _panic_lock;
    _panic_lock = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (_panicstr == (char *)0x0) {
    _panicstr = param_1;
    _paniccpu = 0;
  }
  else if (_paniccpu == 0) {
    uVar3 = 4;
  }
  else {
    LOCK();
    uVar2 = _panic_lock;
    _panic_lock = 0;
    UNLOCK();
    _halt_cpu();
  }
  LOCK();
  uVar2 = _panic_lock;
  _panic_lock = 0;
  UNLOCK();
  _printf(s_panic___Cpu__d___s_001dac34,_paniccpu,param_1);
  _printf(s_panic___s_001dac48,_version);
  _mini_mon(s_panic_001dac60,s_System_Panic_001dac53,_boothowto);
  _boot(0,uVar3,&DAT_001dac66);
  return;
}

