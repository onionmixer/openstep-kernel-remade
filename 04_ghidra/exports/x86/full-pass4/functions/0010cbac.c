/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010cbac */

void FUN_0010cbac(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  
  if ((param_2 & 2) != 0) {
    uVar2 = _spltty();
    if ((param_3 != (int *)0x0) && ((param_3[0x10] & 0x14U) == 0x14)) {
      if (param_1 == 10) {
        _ttyoutput(0xd,param_3);
      }
      _ttyoutput(param_1,param_3);
      _ttstart(param_3);
    }
    _splx(uVar2);
  }
  piVar1 = _pmsgbuf;
  cVar3 = (char)param_1;
  if (((((param_2 & 4) != 0) && (param_1 != 0)) && (param_1 != 0xd)) && (param_1 != 0x7f)) {
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar4 = 0;
      do {
        *(undefined1 *)(uVar4 + 0xc + (int)_pmsgbuf) = 0;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0xff4);
    }
    piVar1 = _pmsgbuf;
    *(char *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc) = cVar3;
    piVar1[1] = piVar1[1] + 1;
    if ((_pmsgbuf[1] < 0) || (0xff3 < (uint)_pmsgbuf[1])) {
      _pmsgbuf[1] = 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_1 != 0)) {
    _cnputc(cVar3);
  }
  if ((param_2 & 8) != 0) {
    *(char *)*param_3 = cVar3;
    *param_3 = *param_3 + 1;
  }
  return;
}

