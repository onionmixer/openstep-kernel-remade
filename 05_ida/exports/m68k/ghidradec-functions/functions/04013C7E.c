
void _sohasoutofband(int param_1)

{
  sword sVar1;
  int iVar2;
  
  sVar1 = *(sword *)(param_1 + 0x54);
  if (sVar1 < 0) {
    _gsignal(-(int)sVar1,0x10);
  }
  else if ((0 < sVar1) && (iVar2 = _pfind((int)sVar1), iVar2 != 0)) {
    _psignal(iVar2,0x10);
  }
  if (*(int *)(param_1 + 0x32) != 0) {
    _selwakeup(*(int *)(param_1 + 0x32),*(byte *)(param_1 + 0x37) & 0x10);
    _selthreadclear(param_1 + 0x32);
    *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) & 0xffef;
  }
  return;
}
