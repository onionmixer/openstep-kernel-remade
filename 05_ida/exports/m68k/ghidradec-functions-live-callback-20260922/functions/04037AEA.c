
void _iinactive(int param_1)

{
  undefined2 uVar1;
  word wVar2;
  
  if ((((*(word *)(param_1 + 0x42) & 0x101) == 0x100) && (*(int *)(param_1 + 0x5e) == 0)) &&
     (*(int *)(param_1 + 0x5a) == 0)) {
    if (*(char *)(*(int *)(param_1 + 0x4e) + 0xd2) == '\0') {
      while ((*(word *)(param_1 + 0x42) & 1) != 0) {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
        _sleep(param_1,10);
      }
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
      if (*(sword *)(param_1 + 100) < 1) {
        *(int *)(param_1 + 0xce) = *(int *)(param_1 + 0xce) + 1;
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x200;
        _itrunc(param_1,0);
        uVar1 = *(undefined2 *)(param_1 + 0x62);
        *(undefined2 *)(param_1 + 0x62) = 0;
        *(undefined4 *)(param_1 + 0x8a) = 0;
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
        _ifree(param_1,*(undefined4 *)(param_1 + 0x46),uVar1);
      }
      if ((*(word *)(param_1 + 0x42) & 0x4e) != 0) {
        _iupdat(param_1,0);
      }
      wVar2 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar2 & 0xfffe;
      if ((wVar2 & 0x10) != 0) {
        *(word *)(param_1 + 0x42) = wVar2 & 0xffee;
        _wakeup(param_1);
      }
    }
    *(undefined2 *)(param_1 + 0x42) = 0;
    if (_ifreeh == 0) {
      _ifreeh = param_1;
      *(int **)(param_1 + 0x5e) = &_ifreeh;
    }
    else {
      *_ifreet = param_1;
      *(int **)(param_1 + 0x5e) = _ifreet;
    }
    *(undefined4 *)(param_1 + 0x5a) = 0;
    _ifreet = (int *)(param_1 + 0x5a);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aIinactive);
}

