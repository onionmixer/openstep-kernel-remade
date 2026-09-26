
void _iput(int param_1)

{
  word wVar1;
  
  if ((*(byte *)(param_1 + 0x43) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIput);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return;
}

