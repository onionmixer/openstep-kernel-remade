
undefined4 _np_setstate_rdyerr(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _np_getgpi(param_1,(byte *)(param_1 + 0x11b));
  if (iVar1 == 0) {
    _np_power_off(param_1);
    uVar2 = 5;
  }
  else {
    if ((*(byte *)(param_1 + 0x11b) & 8) == 0) {
      uVar2 = 6;
    }
    else {
      uVar2 = 2;
    }
    _np_setstate(param_1,uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

