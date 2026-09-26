
void _km_autorepeat(void)

{
  int iVar1;
  
  if ((unk_40B6904 & 2) != 0) {
    iVar1 = _kybd_process(&dword_40B68D4);
    if (((bRam040b683d & 4) != 0) && (iVar1 < 0x100)) {
      _callout_dispatch(0,_km_input,iVar1);
    }
    _timeout(_km_autorepeat,0,_hz / 0x14);
  }
  return;
}

