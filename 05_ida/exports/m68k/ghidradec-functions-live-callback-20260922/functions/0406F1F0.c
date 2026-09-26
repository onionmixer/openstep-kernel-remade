
undefined4 _kmopen(sword param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 & 0xa0000000) == 0) {
loc_406F2A4:
    if ((unk_40B6904 & 1) == 0) {
      _kminit();
    }
    if (1 < (byte)param_1) {
      return 6;
    }
    dword_40B6830 = 0;
    dword_40B6820 = _kmstart;
    byte_40B6841 = '\x02';
    if ((dword_40B683A & 4) == 0) {
      _ttychars(_cons);
      dword_40B6836 = 0x140700d8;
      byte_40B6848 = 0x7f;
      byte_40B6844 = 0xd;
      byte_40B6843 = 0xd;
      dword_40B683A = dword_40B683A | 0x10;
    }
    else if (((char)dword_40B683A < '\0') && (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0))
    goto loc_406F306;
    uVar2 = (*(code *)(&_linesw)[byte_40B6841 * 0xc])((int)param_1,_cons);
    DAT_40b6858._0_2_ = word_40B68E0;
    DAT_40b6856._0_2_ = word_40B68E4;
    DAT_40b6858._2_2_ = uRam040b6946;
    DAT_40b6858._4_2_ = word_40B694E;
  }
  else {
    if ((unk_40B6904 & 8) != 0) {
      if (word_40B6938 != 0) {
        word_40B6938 = word_40B6938 + 1;
      }
      goto loc_406F2A4;
    }
    if ((int)param_2 < 0) {
      _kmpopup(_mach_title,0,0,0,0);
      _kmioctl(0,0x20006b03,0,0);
loc_406F28E:
      word_40B6938 = word_40B6938 + 1;
      goto loc_406F2A4;
    }
    iVar1 = _suser();
    if (iVar1 == 0) {
      return 0xd;
    }
    if (_eventsOpen == 0) {
      _alert_lock_screen(1);
      _kmpopup(_mach_title,1,0x3c,8,1);
      goto loc_406F28E;
    }
loc_406F306:
    uVar2 = 0x10;
  }
  return uVar2;
}

