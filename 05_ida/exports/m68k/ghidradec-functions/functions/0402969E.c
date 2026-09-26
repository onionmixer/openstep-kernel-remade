
word _runlock(int param_1)

{
  sword sVar1;
  word wVar2;
  
  sVar1 = *(sword *)(param_1 + 0x6a);
  *(sword *)(param_1 + 0x6a) = sVar1 + -1;
  wVar2 = sVar1 - 1;
  if ((sword)wVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRunlock);
  }
  if (*(sword *)(param_1 + 0x6a) == 0) {
    wVar2 = *(word *)(param_1 + 0x5e);
    *(word *)(param_1 + 0x5e) = wVar2 & 0xffde;
    if ((wVar2 & 2) != 0) {
      *(word *)(param_1 + 0x5e) = wVar2 & 0xffdc;
      wVar2 = _wakeup(param_1);
    }
  }
  return wVar2;
}
