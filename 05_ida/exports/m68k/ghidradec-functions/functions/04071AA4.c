
void _km_select_console(void)

{
  int iVar1;
  
  iVar1 = _mon_global;
  if (_slot_id == 0) {
    _nbic_bus_enable();
  }
  if (0x2b < *(sword *)(iVar1 + 0x30c)) {
    if ((*(char *)(iVar1 + 0x34c) != _slot_id) &&
       (iVar1 = _km_try_slot((int)*(char *)(iVar1 + 0x34c),(int)*(char *)(iVar1 + 0x34d)),
       iVar1 == 1)) {
      return;
    }
  }
  _bzero(&_km_coni,0x80);
  iVar1 = _vidProbeForFB();
  if (iVar1 != -1) {
    byte_40B6964 = (undefined)_slot_id;
    byte_40B6965 = (undefined)iVar1;
    _vidGetConsoleInfo(&_km_coni);
  }
  return;
}

