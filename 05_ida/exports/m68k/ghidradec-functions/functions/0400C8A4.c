
void _selwakeup(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (param_2 != 0) {
    _nselcoll = _nselcoll + 1;
    _wakeup(&_selwait);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x170) != 0)) {
    if (*(undefined4 **)(param_1 + 0x38) == &_selwait) {
      _clear_wait(param_1,0,1);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x34);
    if (iVar1 != 0) {
      pbVar2 = (byte *)(iVar1 + 0x29);
      *pbVar2 = *pbVar2 & 0xbf;
    }
  }
  return;
}
