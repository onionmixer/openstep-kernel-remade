/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010be44 */

int _logread(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = _splhigh();
  while (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4)) {
    if ((_logsoftc & 2) != 0) {
      _splx(uVar2);
      return 0x23;
    }
    _logsoftc = _logsoftc | 8;
    _sleep(_pmsgbuf);
  }
  _splx(uVar2);
  _logsoftc = _logsoftc & 0xfffffff7;
  while( true ) {
    if (*(int *)(param_2 + 0x14) < 1) {
      return 0;
    }
    iVar3 = *(int *)(_pmsgbuf + 8);
    iVar5 = *(int *)(_pmsgbuf + 4) - iVar3;
    if (iVar5 < 0) {
      iVar5 = 0xff4 - iVar3;
    }
    if (*(int *)(param_2 + 0x14) < iVar5) {
      iVar5 = *(int *)(param_2 + 0x14);
    }
    if (iVar5 == 0) break;
    iVar3 = _uiomove(_pmsgbuf + 0xc + iVar3,iVar5,0,param_2);
    uVar1 = _pmsgbuf;
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar4 = *(int *)(_pmsgbuf + 8) + iVar5;
    *(uint *)(_pmsgbuf + 8) = uVar4;
    if (((int)uVar4 < 0) || (0xff3 < uVar4)) {
      *(undefined4 *)(uVar1 + 8) = 0;
    }
  }
  return 0;
}

