
byte sub_40818B4(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(_slot_id_bmap + 0x2008002);
  if ((char)bVar2 < '\0') {
    if (((_snd_var == 0) && (dword_40C6E76 == 0)) || (dword_40C6E76 == 7)) {
      bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
    }
    else {
      if (((*(byte *)(_slot_id_bmap + 0x2008000) & 2) != 0) &&
         (*(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfd,
         (dword_40C6E84 & 0x2000) != 0)) {
        _softint_run(3);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008000) & 1) != 0) {
        if (((dword_40C6E84 & 0x2c00) == 0) && ((dword_40C6E84 & 0x100) != 0)) {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
        }
        else {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
        }
        *(byte *)(_slot_id_bmap + 0x2008000) = bVar2;
      }
      if (dword_40C6E76 == 3) {
        _dsp_dev_reset_chip();
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 0x18) == 0x18) && ((dword_40C6E84 & 0x200) != 0))
      {
        dword_40C6E76 = 7;
        _printf(aDspAborted);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 0x40) != 0) {
        sub_40826E6(1);
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 3) == 0) && (iVar1 = _dspq_check(), iVar1 == 0))
      {
        return 0;
      }
      bVar2 = _dsp_dev_loop();
    }
  }
  return bVar2;
}
