
void _miniMonLoop(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  _miniMonState = param_3;
  if (param_2 != 0) {
    _safe_prf(aSystemPanic_0);
    _safe_prf(&aS,_panicstr);
    _safe_prf(aTypeRToRebootO);
    do {
      while( true ) {
        iVar1 = _miniMonTryGetchar();
        if (iVar1 != 0x72) break;
        _safe_prf(aRebooting);
        _miniMonReboot(&unk_40A62E7);
      }
    } while (iVar1 != 0x6d);
    _safe_prf(&asc_40A6049);
  }
  _safe_prf(aNextstepMiniMo);
  do {
    _safe_prf(&aS_0,param_1);
    sub_404E0D2(unk_40B393A,0x80);
    iVar1 = sub_404E046(unk_40B393A);
  } while (iVar1 != 0);
  return;
}
