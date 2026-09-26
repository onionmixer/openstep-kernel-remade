/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c010 */

undefined4 _logioctl(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == -0x7ffb8b8a) {
    DAT_001e97c8 = *param_2;
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
    uVar1 = _splhigh();
    iVar2 = *(int *)(_pmsgbuf + 4) - *(int *)(_pmsgbuf + 8);
    _splx(uVar1);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xff4;
    }
    *param_2 = iVar2;
  }
  else {
    if (param_1 != 0x40047477) {
      return 0xffffffff;
    }
    *param_2 = DAT_001e97c8;
  }
  return 0;
}

