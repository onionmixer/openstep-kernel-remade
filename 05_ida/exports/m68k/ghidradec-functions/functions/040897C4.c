
int _vidioctl(undefined4 param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined auStack_a4 [128];
  undefined uStack_24;
  uint uStack_23;
  byte bStack_13;
  undefined auStack_12 [14];
  
  iVar2 = *(int *)(_active_threads + 0x24);
  if (param_2 == 0x20007603) {
    if (-1 < *(int *)(iVar2 + 0x54)) {
      return 6;
    }
    (*(&off_40B229C)[dword_40B2282 * 0xb])();
  }
  else if (param_2 < 0x20007604) {
    if (param_2 == -0x7fcf89f8) {
      _bcopy(param_3,unk_40B2310,0x30);
      sub_4089C56();
    }
    else {
      if (param_2 < -0x7fcf89f7) {
        if (param_2 == -0x7ff789f9) {
          iVar2 = _suser();
          if (iVar2 != 0) {
            iVar2 = _rtc_alarm(param_3,0);
            return iVar2;
          }
        }
        else {
          if (param_2 != -0x7fdf89fc) {
            return 0x19;
          }
          iVar2 = _suser();
          if (iVar2 != 0) {
            _nvram_check(&uStack_24);
            iVar2 = _strncmp(auStack_12,(int)param_3 + 0x12,0xc);
            if (iVar2 != 0) {
              _strcpy(&_boot_dev,(int)param_3 + 0x12);
              _boot_info = 0;
              _boot_file = 0;
            }
            if ((*(byte *)((int)param_3 + 0x11) & 0x40) != (bStack_13 & 0x40)) {
              _rtc_set_auto_poweron((*(byte *)((int)param_3 + 0x11) & 0x7f) >> 6);
            }
            _nvram_set(param_3);
            return 0;
          }
        }
loc_40899B4:
        return (int)*(char *)(dword_40B57D4 + 100);
      }
      if (param_2 == -0x3ffb8a00) {
        if (*param_3 == 0x87654321) {
          _vidSuspendAnimation();
        }
        else if (*param_3 == 0x12345678) {
          _vidResumeAnimation();
        }
        else {
          _vidStopAnimation();
        }
        if (*(int *)(iVar2 + 0x54) < 0) {
          return 0x10;
        }
        if (*param_3 != 0x12345678) {
          _vidStopAnimation();
        }
        uVar1 = (*(&off_40B2298)[dword_40B2282 * 0xb])();
        *param_3 = uVar1;
        if (uVar1 == 0) {
          return 6;
        }
      }
      else {
        if (param_2 != -0x3ffb89fe) {
          return 0x19;
        }
        _nvram_check(&uStack_24);
        uVar1 = _SetCurBrightness(*param_3);
        uStack_23 = uStack_23 & 0xf03fffff | (uVar1 & 0x3f) << 0x16;
        *param_3 = uVar1 & 0x3f;
        _nvram_set(&uStack_24);
      }
    }
  }
  else {
    if (param_2 != 0x20007609) {
      if (param_2 < 0x2000760a) {
        if (param_2 == 0x20007605) {
          iVar2 = sub_408B27A();
          return iVar2;
        }
        if (param_2 == 0x20007606) {
          uVar1 = *param_3;
          (**(code **)((int)&DAT_40b2290 + dword_40B2282 * 0x2c))(auStack_a4);
          iVar2 = _copyoutmsg(auStack_a4,uVar1,0x80);
          return iVar2;
        }
      }
      else {
        if (param_2 == 0x40207604) {
          iVar2 = _suser();
          if (iVar2 != 0) {
            _nvram_check(param_3);
            return 0;
          }
          goto loc_40899B4;
        }
        if (param_2 < 0x40207605) {
          if (param_2 == 0x40087607) {
            iVar2 = _rtc_alarm(0,param_3);
            return iVar2;
          }
        }
        else if (param_2 == 0x40307608) {
          _bcopy(unk_40B2310,param_3,0x30);
          return 0;
        }
      }
      return 0x19;
    }
    iVar2 = 0;
    puVar3 = unk_40AD8AC;
    do {
      unk_40B2310[iVar2] = *puVar3;
      unk_40B2320[iVar2] = *puVar3;
      unk_40B2330[iVar2] = *puVar3;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 0x10);
    sub_4089C56();
  }
  return 0;
}
