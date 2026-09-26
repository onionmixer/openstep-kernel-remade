
int sub_404EAAE(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _PMGetPowerEvent(&uStack_8);
  if (iVar1 == 0) {
    switch(uStack_8) {
    case :
    case :
      dword_40B39C2 = 1;
      _PMSetPowerState(0x10000,1);
      break;
    case :
    case :
    case :
      dword_40B39C2 = 2;
      _PMSetPowerState(0x10000,2);
      dword_40B39C2 = 0;
      _PMSetPowerState(0x10000,0);
      break;
    case :
    case :
    case :
      if (dword_40B39C2 != 0) {
        dword_40B39C2 = 0;
        _PMSetPowerState(0x10000,0);
      }
    case :
      _PMUpdateClock();
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uStack_8;
    }
  }
  return iVar1;
}
