
void _ttyblkin(undefined *param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  word wVar4;
  sword sVar5;
  undefined *puVar6;
  
  iVar2 = _ttynty(param_3);
  if ((*(byte *)(iVar2 + 0x12) & 8) != 0) {
    if ((*(byte *)((int)param_3 + 0x3a) & 0x20) != 0) {
      _ttypend(param_3);
    }
    _tk_nin = param_2 + _tk_nin;
    if ((*(byte *)((int)param_3 + 0x3d) & 0x20) == 0) {
      param_2 = param_2 + -1;
      if (-1 < param_2) {
        do {
          do {
            puVar6 = param_1 + 1;
            _ttcooked(*param_1,iVar2);
            wVar4 = (word)((uint)param_2 >> 0x10);
            sVar5 = (sword)param_2 + -1;
            param_2 = CONCAT22(wVar4,sVar5);
            param_1 = puVar6;
          } while (sVar5 != -1);
          param_2 = (uint)wVar4 * 0x10000 + -1;
        } while (wVar4 != 0);
      }
    }
    else {
      if (0x400 < param_2 + *param_3) {
        param_2 = 0x400 - *param_3;
        if (param_2 < 0) {
          param_2 = 0;
        }
        _log(4,aTtyDRawInputOv,(int)*(sword *)(param_3 + 0xe));
      }
      iVar3 = _b_to_q(param_1,param_2,param_3);
      if ((param_2 != iVar3 && -1 < param_2 - iVar3) && (iVar3 = _ttcheckwakeup(iVar2), iVar3 != 0))
      {
        _ttwakeup(param_3);
      }
      uVar1 = *(uint *)((int)param_3 + 0x3a);
      *(uint *)((int)param_3 + 0x3a) = uVar1 & 0xff7fffff;
      if ((uVar1 & 8) != 0) {
        iVar3 = _b_to_q(param_1,param_2,param_3 + 6);
        _tk_nout = iVar3 + _tk_nout;
      }
      if (((*(byte *)(iVar2 + 0x13) & 0x10) != 0) &&
         (((*(byte *)((int)param_3 + 0x3a) & 0x40) == 0 ||
          ((*(char *)((int)param_3 + 0x51) != -1 &&
           (*(char *)((int)param_3 + 0x51) == *(char *)(param_3 + 0x14))))))) {
        *(word *)(param_3 + 0x10) = *(word *)(param_3 + 0x10) & 0xfeff;
      }
    }
    if ((0x1ff < param_3[3] + *param_3) &&
       (((*(uint *)((int)param_3 + 0x3a) & 0x22) != 0 || (0 < param_3[3])))) {
      if (((*(uint *)((int)param_3 + 0x3a) & 1) != 0) &&
         ((*(char *)((int)param_3 + 0x51) != -1 &&
          (iVar2 = _putc((int)*(char *)((int)param_3 + 0x51),param_3 + 6), iVar2 == 0)))) {
        *(word *)(param_3 + 0x10) = *(word *)(param_3 + 0x10) | 0x400;
        _ttstart(param_3);
      }
      *(byte *)((int)param_3 + 0x3f) = *(byte *)((int)param_3 + 0x3f) | 0x80;
    }
    _ttstart(param_3);
  }
  return;
}

