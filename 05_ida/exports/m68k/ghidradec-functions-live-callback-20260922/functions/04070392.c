
void _kmintr_process(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((unk_40B6904 & 2) != 0) {
    unk_40B6904 = unk_40B6904 & 0xfffd;
    _untimeout(_km_autorepeat,0);
  }
  iVar1 = _kybd_process(param_1);
  if (iVar1 != 0x100) {
    if (-1 < *(char *)((int)param_1 + 3)) {
      if ((unk_40B6904 & 0x100) != 0) {
        _alert_key = iVar1;
        return;
      }
      dword_40B68D4 = *param_1;
      unk_40B6904 = unk_40B6904 | 2;
      iVar2 = _hz;
      if (_hz < 0) {
        iVar2 = _hz + 1;
      }
      _timeout(_km_autorepeat,0,iVar2 >> 1);
    }
    if (((bRam040b683d & 4) != 0) && (iVar1 < 0x100)) {
      _callout_dispatch(0,_km_input,iVar1);
    }
  }
  return;
}

