
void _ResetKbd(void)

{
  int iVar1;
  undefined4 unaff_D3;
  
  if (_mapNotDefault == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(_curMapping + 0x2d8);
    unaff_D3 = _curMapLen;
  }
  _InitKbd(1);
  if (iVar1 != 0) {
    _kfree(iVar1,unaff_D3);
  }
  return;
}
