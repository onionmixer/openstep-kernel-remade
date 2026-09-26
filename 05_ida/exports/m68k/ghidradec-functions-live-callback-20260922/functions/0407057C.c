
int _kmtrygetc(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = _slot_id;
  puVar3 = (uint *)(_slot_id + 0x200e000);
  iVar1 = _adb_check_keyboard(&_km);
  if (iVar1 == 0) {
    if ((*puVar3 & 0x400000) == 0) {
      return -1;
    }
    _km = *(undefined4 *)(iVar2 + 0x200e008);
  }
  iVar1 = _kybd_process(&_km);
  iVar2 = -1;
  if (iVar1 < 0x100) {
    iVar2 = iVar1;
  }
  return iVar2;
}

