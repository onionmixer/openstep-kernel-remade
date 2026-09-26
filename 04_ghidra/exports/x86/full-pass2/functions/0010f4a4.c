/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f4a4 */

void _ttyblkin(undefined1 *param_1,int param_2,int *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uchar *local_10;
  int local_c;
  int local_8;
  
  iVar3 = _ttynty(param_3);
  if ((*(byte *)(iVar3 + 0x11) & 8) != 0) {
    if ((param_3[0xf] & 0x20000000U) != 0) {
      param_3[0xf] = param_3[0xf] & 0xdfffffff;
      param_3[0x10] = param_3[0x10] | 0x100000;
      local_10 = (uchar *)*param_3;
      local_c = param_3[1];
      local_8 = param_3[2];
      *param_3 = 0;
      param_3[2] = 0;
      param_3[1] = 0;
      while (iVar4 = _getc((FILE *)&local_10), -1 < iVar4) {
        _ttyinput(iVar4,param_3);
      }
      param_3[0x10] = param_3[0x10] & 0xffefffff;
    }
    _tk_nin = _tk_nin + param_2;
    if ((*(byte *)(param_3 + 0xf) & 0x20) == 0) {
      while (param_2 = param_2 + -1, -1 < param_2) {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        _ttcooked(uVar1,iVar3);
      }
    }
    else {
      if (0x400 < param_2 + *param_3) {
        param_2 = 0x400 - *param_3;
        if (param_2 < 0) {
          param_2 = 0;
        }
        _log(4,s_tty_d__raw_input_overrun_001daf5c,(int)(short)param_3[0xe]);
      }
      iVar4 = _b_to_q(param_1,param_2,param_3);
      if ((param_2 != iVar4 && -1 < param_2 - iVar4) && (iVar4 = _ttcheckwakeup(iVar3), iVar4 != 0))
      {
        _ttwakeup(param_3);
      }
      uVar2 = param_3[0xf];
      param_3[0xf] = uVar2 & 0xff7fffff;
      if ((uVar2 & 8) != 0) {
        iVar4 = _b_to_q(param_1,param_2,param_3 + 6);
        _tk_nout = _tk_nout + iVar4;
      }
      if (((*(byte *)(iVar3 + 0x10) & 0x10) != 0) &&
         (((*(byte *)((int)param_3 + 0x3f) & 0x40) == 0 ||
          ((*(char *)((int)param_3 + 0x52) != -1 &&
           (*(char *)((int)param_3 + 0x51) == *(char *)((int)param_3 + 0x52))))))) {
        param_3[0x10] = param_3[0x10] & 0xfffffeff;
      }
    }
    if ((0x1ff < *param_3 + param_3[3]) && (((param_3[0xf] & 0x22U) != 0 || (0 < param_3[3])))) {
      if (((param_3[0xf] & 1U) != 0) &&
         ((*(char *)((int)param_3 + 0x52) != -1 &&
          (iVar3 = _putc((int)*(char *)((int)param_3 + 0x52),(FILE *)(param_3 + 6)), iVar3 == 0))))
      {
        param_3[0x10] = param_3[0x10] | 0x400;
        uVar5 = _spltty();
        if (((param_3[0x10] & 0x4000121U) == 0) && ((code *)param_3[9] != (code *)0x0)) {
          (*(code *)param_3[9])(param_3);
        }
        _splx(uVar5);
      }
      param_3[0x10] = param_3[0x10] | 0x800000;
    }
    uVar5 = _spltty();
    if (((param_3[0x10] & 0x4000121U) == 0) && ((code *)param_3[9] != (code *)0x0)) {
      (*(code *)param_3[9])(param_3);
    }
    _splx(uVar5);
  }
  return;
}

