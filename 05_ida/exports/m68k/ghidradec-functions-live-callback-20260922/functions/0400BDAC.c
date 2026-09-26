
void sub_400BDAC(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((((param_2 & 2) != 0) && (param_3 != (int *)0x0)) &&
     ((*(uint *)((int)param_3 + 0x3e) & 0x14) == 0x14)) {
    if (param_1 == 10) {
      _ttyoutput(0xd,param_3);
    }
    _ttyoutput(param_1,param_3);
    _ttstart(param_3);
  }
  piVar1 = _pmsgbuf;
  if ((((param_2 & 4) != 0) && (param_1 != 0)) && ((param_1 != 0xd && (param_1 != 0x7f)))) {
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar2 = 0;
      do {
        *(undefined *)((int)_pmsgbuf + uVar2 + 0xc) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0xff4);
    }
    piVar1 = _pmsgbuf;
    *(char *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc) = (char)param_1;
    piVar1[1] = piVar1[1] + 1;
    if ((_pmsgbuf[1] < 0) || (0xff3 < (uint)_pmsgbuf[1])) {
      _pmsgbuf[1] = 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_1 != 0)) {
    _cnputc(param_1);
  }
  if ((param_2 & 8) != 0) {
    *(char *)*param_3 = (char)param_1;
    *param_3 = *param_3 + 1;
  }
  return;
}

