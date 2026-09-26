
int _kmgetc(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar1 = _slot_id;
  puVar3 = (uint *)(_slot_id + 0x200e000);
loc_40704B4:
  do {
    iVar2 = _adb_check_keyboard(&_km);
    if (iVar2 == 0) {
      if ((*puVar3 & 0x400000) == 0) goto loc_40704B4;
      _km = *(undefined4 *)(iVar1 + 0x200e008);
    }
    iVar2 = _kybd_process(&_km);
    if (iVar2 < 0x100) {
      if (iVar2 == 0xd) {
        iVar2 = 10;
      }
      _cnputc(iVar2);
      return iVar2;
    }
  } while( true );
}
