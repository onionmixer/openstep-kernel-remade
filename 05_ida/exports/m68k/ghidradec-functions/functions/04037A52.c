
void _idrop(int param_1)

{
  word wVar1;
  sword sVar2;
  
  if ((*(byte *)(param_1 + 0x43) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIdrop);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  sVar2 = *(sword *)(param_1 + 0x12);
  *(sword *)(param_1 + 0x12) = sVar2 + -1;
  if (sVar2 == 1) {
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
  }
  return;
}
