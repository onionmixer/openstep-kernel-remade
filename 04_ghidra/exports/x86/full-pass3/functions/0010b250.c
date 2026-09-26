/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b250 */

void _realitexpire(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  _psignal(param_1,(char *)0xe);
  if ((*(int *)(param_1 + 0x54) == 0) && (*(int *)(param_1 + 0x58) == 0)) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  else {
    do {
      iVar1 = _mtime[1];
      iVar2 = _mtime[2];
    } while (*_mtime != iVar2);
    uVar3 = _splclock();
    if (*(int *)(param_1 + 0x5c) < iVar2 + -10) {
      *(int *)(param_1 + 0x5c) = iVar2;
      *(int *)(param_1 + 0x60) = iVar1;
    }
    else {
      _splx(uVar3);
      while( true ) {
        uVar3 = _splclock();
        _timevaladd(param_1 + 0x5c,param_1 + 0x54);
        if ((iVar2 < *(int *)(param_1 + 0x5c)) ||
           ((*(int *)(param_1 + 0x5c) == iVar2 && (iVar1 < *(int *)(param_1 + 0x60))))) break;
        _splx(uVar3);
      }
    }
    uVar4 = _hzto(param_1 + 0x5c);
    pcVar5 = _realitexpire;
    _timeout(0x10b250);
    _splx(uVar3,pcVar5,param_1,uVar4);
  }
  return;
}

