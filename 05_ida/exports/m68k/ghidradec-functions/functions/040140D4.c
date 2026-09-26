
void _sowakeup(int param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  
  _sbwakeup(param_2);
  if ((*(byte *)(param_1 + 6) & 2) != 0) {
    sVar1 = *(sword *)(param_1 + 0x54);
    if (sVar1 < 0) {
      _gsignal(-(int)sVar1,0x17);
    }
    else if (0 < sVar1) {
      iVar2 = _pfind((int)sVar1);
      if (iVar2 != 0) {
        _psignal(iVar2,0x17);
      }
    }
  }
  return;
}
