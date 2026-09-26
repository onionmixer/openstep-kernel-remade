
void _inittodr(uint param_1)

{
  uint uVar1;
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((param_1 < 0x1ff46b80) || ((int)param_1 < 0)) {
    _printf(aWarningPrepost);
  }
  else {
    _microtime(&uStack_c);
    _boottime = uStack_c;
    dword_40B67D4 = 0;
    uVar1 = uStack_c - param_1;
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
    }
    if ((uVar1 < 0x2a300) && ((int)param_1 < (int)uStack_c)) {
      dword_40B67D4 = 0;
      return;
    }
    if (uStack_c < 0x1e13380) {
      _printf(aWarningClockNo);
      uStack_c = param_1;
      uStack_8 = 0;
      _setthetime(&uStack_c);
      _boottime = uStack_c;
      dword_40B67D4 = uStack_8;
    }
    else if (uVar1 < 0x76a701) {
      _printf(aWarningClockLo,uVar1 / 0x15180);
    }
    else {
      _printf(aWarningPrepost_0);
      uStack_c = param_1;
      uStack_8 = 0;
      _setthetime(&uStack_c);
      _boottime = uStack_c;
      dword_40B67D4 = uStack_8;
    }
  }
  _printf(aCheckAndResetT);
  return;
}
