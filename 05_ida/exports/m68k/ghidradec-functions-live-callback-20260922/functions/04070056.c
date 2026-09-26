
int _kmioctl(undefined4 param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if (param_2 == 0x20006b02) {
    if (((word_40B6938 != 0) && ((param_4 & 0xa0000000) != 0)) &&
       (sVar2 = word_40B6938 + -1, bVar5 = word_40B6938 == 1, word_40B6938 = sVar2, bVar5)) {
      _kmrestore();
      _alert_lock_screen(0);
    }
  }
  else if (param_2 < 0x20006b03) {
    if (param_2 == -0x7ff78b99) {
      return 0x16;
    }
    if (-0x7ff78b99 < param_2) {
      if (param_2 == -0x7ff394fb) {
        iVar3 = _km_drawrect(param_3);
        return iVar3;
      }
      if (param_2 == -0x7ff394fa) {
        iVar3 = _km_eraserect(param_3);
        return iVar3;
      }
loc_4070260:
      iVar3 = (**(code **)(DAT_40ae4bc + byte_40B6841 * 0x30))(_cons,param_2,param_3,param_4);
      if (-1 < iVar3) {
        return iVar3;
      }
      iVar3 = _ttioctl(_cons,param_2,param_3,param_4);
      if (iVar3 < 0) {
        return 0x19;
      }
      return iVar3;
    }
    if (param_2 == -0x7ffb94f9) {
      _km_send(0xc5,*param_3 << 0x10);
    }
    else {
      if (param_2 != -0x7ffb94f7) goto loc_4070260;
      uVar1 = *param_3;
      if (uVar1 == 1) {
        _vidSuspendAnimation();
      }
      else if ((int)uVar1 < 2) {
        if (uVar1 != 0) {
          return 0x16;
        }
        _vidStopAnimation();
      }
      else {
        if (uVar1 != 2) {
          return 0x16;
        }
        _vidResumeAnimation();
      }
    }
  }
  else if (param_2 == 0x40046b04) {
    iVar3 = _suser();
    if (iVar3 == 0) {
      return 0xd;
    }
    *param_3 = (int)(sword)unk_40B6904;
  }
  else if (param_2 < 0x40046b05) {
    if (param_2 == 0x20006b03) {
      if (*_pmsgbuf == 0x63061) {
        piVar4 = (int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc);
        do {
          if (*(char *)piVar4 != '\0') {
            if (*(char *)piVar4 == '\n') {
              _kmpaint(0xd);
            }
            _kmpaint((int)*(char *)piVar4);
          }
          piVar4 = (int *)((int)piVar4 + 1);
          if (_pmsgbuf + 0x400 <= piVar4) {
            piVar4 = _pmsgbuf + 3;
          }
        } while ((int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc) != piVar4);
      }
    }
    else {
      if (param_2 != 0x20006b08) goto loc_4070260;
      unk_40B6904 = unk_40B6904 & 0xfff7;
    }
  }
  else if (param_2 == 0x40046b0a) {
    iVar3 = _suser();
    if (iVar3 == 0) {
      return 0xd;
    }
    *param_3 = (uint)((unk_40B6904 & 8) != 0);
  }
  else {
    if (param_2 != 0x40086b0b) goto loc_4070260;
    *(undefined2 *)((int)param_3 + 2) = word_40B68E0;
    *(undefined2 *)param_3 = word_40B68E4;
    *(undefined2 *)(param_3 + 1) = uRam040b6946;
    *(undefined2 *)((int)param_3 + 6) = word_40B694E;
  }
  return 0;
}

