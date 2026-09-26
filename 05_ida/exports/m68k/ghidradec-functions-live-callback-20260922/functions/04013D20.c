
void _soisconnected(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = _soqremque(param_1,0);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aSoisconnected);
    }
    _soqinsque(iVar1,param_1,1);
    _sowakeup(iVar1,iVar1 + 0x22);
    _wakeup(iVar1 + 0x4e);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff3 | 2;
  _wakeup(param_1 + 0x4e);
  _sowakeup(param_1,param_1 + 0x22);
  _sowakeup(param_1,param_1 + 0x38);
  return;
}

