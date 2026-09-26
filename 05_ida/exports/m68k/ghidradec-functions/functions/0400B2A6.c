
undefined4 _logioctl(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == -0x7ffb8b8a) {
    dword_40B67EC = *param_2;
  }
  else if (param_1 < -0x7ffb8b89) {
    if (param_1 == -0x7ffb9983) {
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffb;
      }
      else {
        _logsoftc = _logsoftc | 4;
      }
    }
    else {
      if (param_1 != -0x7ffb9982) {
        return 0xffffffff;
      }
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffd;
      }
      else {
        _logsoftc = _logsoftc | 2;
      }
    }
  }
  else if (param_1 == 0x4004667f) {
    iVar1 = *(int *)(_pmsgbuf + 4) - *(int *)(_pmsgbuf + 8);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xff4;
    }
    *param_2 = iVar1;
  }
  else {
    if (param_1 != 0x40047477) {
      return 0xffffffff;
    }
    *param_2 = dword_40B67EC;
  }
  return 0;
}
