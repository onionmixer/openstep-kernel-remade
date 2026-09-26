
undefined4 _rlock_timeout(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  
  do {
    wVar1 = *(word *)(param_1 + 0x5e);
    if (((wVar1 & 1) == 0) || (*(int *)(param_1 + 0x66) == _active_threads)) {
      *(int *)(param_1 + 0x66) = _active_threads;
      *(sword *)(param_1 + 0x6a) = *(sword *)(param_1 + 0x6a) + 1;
      *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 1;
      return 0;
    }
    if ((wVar1 & 0x20) != 0) {
      _rlockretimeout = _rlockretimeout + 1;
      return 1;
    }
    *(word *)(param_1 + 0x5e) = wVar1 | 2;
    _timeout(sub_40296F8,param_1,_hz * param_2);
    _sleep(param_1,10);
    iVar2 = _untimeout(sub_40296F8,param_1);
  } while (iVar2 != 0);
  _rlocktimeout = _rlocktimeout + 1;
  *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 0x20;
  return 1;
}

