
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _panic(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _mon_global;
  uVar2 = 0;
  if (_panicstr == 0) {
    _panicstr = param_1;
    _paniccpu = 0;
  }
  else {
    if (_paniccpu != 0) {
                    /* WARNING: Subroutine does not return */
      _halt_cpu();
    }
    uVar2 = 4;
  }
  _printf(aPanicCpuDS,_paniccpu,param_1);
  _printf(aNextRomMonitor,(int)*(sword *)(iVar1 + 0x312),(int)*(sword *)(iVar1 + 0x30a),
          (int)*(sword *)(iVar1 + 0x30c));
  _printf(aPanicS,_version);
  _mini_mon(&aPanic,aSystemPanic,__boothowto);
  _boot(0,uVar2,&unk_40A62E7);
  return;
}
