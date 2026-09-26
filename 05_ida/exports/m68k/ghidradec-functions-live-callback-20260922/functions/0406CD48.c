
void sub_406CD48(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((char)param_1[6] < '\0') {
    if ((param_1[6] & 0x4000U) != 0) {
      iVar2 = 0;
      if (_dma_chip == 0x139) goto loc_406CD8E;
      while (iVar2 < 1) {
loc_406CD8E:
        while( true ) {
          **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 4;
          _delay(5);
          **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xfb;
          _delay(5);
          iVar2 = iVar2 + 1;
          if (_dma_chip != 0x139) break;
          if (7 < iVar2) goto loc_406CDC4;
        }
      }
loc_406CDC4:
      **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xef;
    }
    iVar2 = 0;
    do {
      if (*(char *)(iVar1 + 4) < '\0') break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 400);
    if (iVar2 != 400) {
      if ((*(byte *)(iVar1 + 4) & 0x40) == 0) {
        iVar1 = _fc_send_byte(param_1,8);
        if (iVar1 != 0) goto loc_406CE4C;
      }
      else {
        *(undefined *)(param_1[8] + 0x26) = *(undefined *)(iVar1 + 5);
        *(int *)(param_1[8] + 0x4a) = *(int *)(param_1[8] + 0x4a) + 1;
      }
      param_1[6] = param_1[6] | 0x40;
      if (_fd_polling_mode != 0) {
        return;
      }
      _thread_wakeup_prim(param_1 + 6,0,0);
      return;
    }
  }
  else {
    _printf(aFcDSpuriousFlo,(int)(param_1 + -0x1030ddb) * -0x3fca482f >> 1);
  }
loc_406CE4C:
  _fc_flags_bset(param_1,0x400);
  _uninstall_scanned_intr(0x736);
  _fc_flags_bclr(param_1,0x2000);
  return;
}

