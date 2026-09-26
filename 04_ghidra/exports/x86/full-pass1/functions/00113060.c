/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ndflush(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar4;
  int *piVar3;
  
  uVar1 = _spltty();
  if (0 < *param_1) {
    while (0 < param_2) {
      if (*param_1 == 0) goto LAB_00113135;
      piVar4 = (int *)(param_1[1] & 0xffffffc0);
      piVar3 = (int *)param_1[2];
      if (piVar4 != (int *)((int)piVar3 - 1U & 0xffffffc0)) {
        piVar3 = piVar4 + 0x10;
      }
      iVar2 = (int)piVar3 - param_1[1];
      if (param_2 < iVar2) {
        *param_1 = *param_1 - param_2;
        param_1[1] = param_1[1] + param_2;
        if (0 < *param_1) goto LAB_00113149;
        *piVar4 = (int)_cfreelist;
        __cfreecount = __cfreecount + 0x34;
        _cfreelist = piVar4;
        if (_cwaiting != '\0') {
          _wakeup(&_cwaiting);
          _cwaiting = '\0';
        }
        break;
      }
      param_2 = param_2 - iVar2;
      *param_1 = *param_1 - iVar2;
      param_1[1] = *piVar4 + 0xc;
      *piVar4 = (int)_cfreelist;
      __cfreecount = __cfreecount + 0x34;
      _cfreelist = piVar4;
      if (_cwaiting != '\0') {
        _wakeup(&_cwaiting);
        _cwaiting = '\0';
      }
    }
    if (*param_1 < 1) {
LAB_00113135:
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
    }
  }
LAB_00113149:
  _splx(uVar1);
  return;
}

