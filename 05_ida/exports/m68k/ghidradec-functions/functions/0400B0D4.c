
int _logread(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4)) {
    do {
      if ((_logsoftc & 2) != 0) {
        return 0x23;
      }
      _logsoftc = _logsoftc | 8;
      _sleep(_pmsgbuf,0x1a);
    } while (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4));
  }
  _logsoftc = _logsoftc & 0xfffffff7;
  while( true ) {
    if (*(int *)(param_2 + 0x12) < 1) {
      return 0;
    }
    iVar1 = *(int *)(_pmsgbuf + 8);
    iVar4 = *(int *)(_pmsgbuf + 4) - iVar1;
    if (iVar4 < 0) {
      iVar4 = 0xff4 - iVar1;
    }
    if (*(int *)(param_2 + 0x12) < iVar4) {
      iVar4 = *(int *)(param_2 + 0x12);
    }
    if (iVar4 == 0) break;
    iVar3 = _uiomove(_pmsgbuf + 0xc + iVar1,iVar4,0,param_2);
    iVar1 = _pmsgbuf;
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar2 = iVar4 + *(int *)(_pmsgbuf + 8);
    *(uint *)(_pmsgbuf + 8) = uVar2;
    if (((int)uVar2 < 0) || (0xff3 < uVar2)) {
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  return 0;
}
