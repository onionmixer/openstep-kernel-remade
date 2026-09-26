
void _panic(char *param_1,...)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  do {
  } while (_panic_lock != 0);
  LOCK();
  UNLOCK();
  if (_panicstr == (char *)0x0) {
    _panicstr = param_1;
    _paniccpu = 0;
  }
  else if (_paniccpu == 0) {
    uVar1 = 4;
  }
  else {
    LOCK();
    _panic_lock = 0;
    UNLOCK();
    _halt_cpu();
  }
  LOCK();
  _panic_lock = 0;
  UNLOCK();
  _printf(s_panic___Cpu__d___s_001dac34,_paniccpu,param_1);
  _printf(s_panic___s_001dac48,_version);
  _mini_mon(s_panic_001dac60,s_System_Panic_001dac53,_boothowto);
  _boot(0,uVar1,&DAT_001dac66);
  return;
}

