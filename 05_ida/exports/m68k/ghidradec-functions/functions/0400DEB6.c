
void _ttyinput(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _ttynty(param_2);
  if ((*(byte *)(iVar2 + 0x12) & 8) != 0) {
    if ((*(byte *)((int)param_2 + 0x3a) & 0x20) != 0) {
      _ttypend(param_2);
    }
    _tk_nin = _tk_nin + 1;
    if (((param_1 & 0xff000000) == 0) && ((*(byte *)((int)param_2 + 0x3d) & 0x20) != 0)) {
      if (*param_2 < 0x401) {
        iVar3 = _putc(param_1,param_2);
        if (-1 < iVar3) {
          iVar3 = _ttcheckwakeup(iVar2);
          if (iVar3 != 0) {
            _ttwakeup(param_2);
          }
          _ttyecho(param_1,iVar2);
        }
      }
      else {
        _log(4,aTtyDRawInputOv,(int)*(sword *)(param_2 + 0xe));
        _ttwakeup(param_2);
      }
      uVar1 = *(uint *)((int)param_2 + 0x3a);
      *(uint *)((int)param_2 + 0x3a) = uVar1 & 0xff7fffff;
      if (((*(byte *)(iVar2 + 0x13) & 0x10) != 0) &&
         (((uVar1 & 0x40000000) == 0 ||
          ((*(char *)((int)param_2 + 0x51) != -1 &&
           (*(char *)((int)param_2 + 0x51) == *(char *)(param_2 + 0x14))))))) {
        *(word *)(param_2 + 0x10) = *(word *)(param_2 + 0x10) & 0xfeff;
      }
    }
    else {
      _ttcooked(param_1,iVar2);
    }
    if ((0x1ff < param_2[3] + *param_2) &&
       (((*(uint *)((int)param_2 + 0x3a) & 0x22) != 0 || (0 < param_2[3])))) {
      if (((*(uint *)((int)param_2 + 0x3a) & 1) != 0) && (*(char *)((int)param_2 + 0x51) != -1)) {
        iVar2 = _putc((int)*(char *)((int)param_2 + 0x51),param_2 + 6);
        if (iVar2 == 0) {
          *(word *)(param_2 + 0x10) = *(word *)(param_2 + 0x10) | 0x400;
          _ttstart(param_2);
        }
      }
      *(byte *)((int)param_2 + 0x3f) = *(byte *)((int)param_2 + 0x3f) | 0x80;
    }
    _ttstart(param_2);
  }
  return;
}
